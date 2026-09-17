#!/usr/bin/env python3
"""objdiff_report.py — write this repository's progress as an objdiff report (v2 JSON,
the format decomp.dev consumes) from the committed ledger. Standard library only, so
CI and contributors run it without the toolchain or the disc.

    python3 tools/objdiff_report.py [--repo DIR] [--out build/report.json]

Reads  ledger/functions.jsonl (one record per function: name, addr, size, segment,
       kind, status, score, linked), ledger/segments.json (kind per segment) and
       config/target.json (boot file, title).
Writes the report: one unit per segment (name = segment; source_path = src/<segment>/
       when C exists), one function item per ledger record. A function's match percent
       is 100 when its status is `matched` (a ledger record exists only after
       ledger.py mark compiled the C with the pinned compiler and found the .text
       byte-identical), its best recorded objdiff score when `wip`, 0 otherwise.
       matched_code counts matched functions; complete_code counts matched functions
       that are linked into the rebuilt ELF (the byte-identical image, build/check.json).
       Categories: game (segments of kind game), sdk (kind sdk / libc). Data is not
       tracked by the ledger before S7 data-migrate and is reported as 0.
Exit 0 written (prints the totals); 2 missing inputs.
"""
import argparse
import json
import sys
from pathlib import Path

REPORT_VERSION = 2


def read_jsonl(p):
    out = []
    if p.is_file():
        for line in p.read_text(encoding="utf-8").splitlines():
            line = line.strip()
            if line:
                out.append(json.loads(line))
    return out


def pct(part, whole):
    return round(100.0 * part / whole, 4) if whole else 0.0


def measures(items, linked_sizes):
    total_code = sum(i["size"] for i in items)
    matched_code = sum(i["size"] for i in items if i["fuzzy_match_percent"] >= 100.0)
    fuzzy = sum(i["size"] * i["fuzzy_match_percent"] / 100.0 for i in items)
    n = len(items)
    m = sum(1 for i in items if i["fuzzy_match_percent"] >= 100.0)
    return {
        "fuzzy_match_percent": pct(fuzzy, total_code),
        "total_code": total_code, "matched_code": matched_code,
        "matched_code_percent": pct(matched_code, total_code),
        "total_data": 0, "matched_data": 0, "matched_data_percent": 0.0,
        "total_functions": n, "matched_functions": m, "matched_functions_percent": pct(m, n),
        "complete_code": linked_sizes, "complete_code_percent": pct(linked_sizes, total_code),
        "complete_data": 0, "complete_data_percent": 0.0,
    }


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--repo", default=".")
    ap.add_argument("--out", default="build/report.json")
    a = ap.parse_args()
    repo = Path(a.repo).resolve()
    funcs = read_jsonl(repo / "ledger" / "functions.jsonl")
    if not funcs:
        print("ledger/functions.jsonl missing or empty (segment-map has not run): no report", file=sys.stderr)
        return 2
    segs = (json.loads((repo / "ledger" / "segments.json").read_text(encoding="utf-8")) if (repo / "ledger" / "segments.json").is_file() else {}).get("segments", [])
    seg_kind = {s["name"]: s.get("kind", "game") for s in segs}
    target = json.loads((repo / "config" / "target.json").read_text(encoding="utf-8")) if (repo / "config" / "target.json").is_file() else {}

    by_seg = {}
    for f in funcs:
        if f.get("status") == "skipped-data":
            continue
        by_seg.setdefault(f.get("segment") or "unassigned", []).append(f)

    units, cat_items, cat_linked = [], {"game": [], "sdk": []}, {"game": 0, "sdk": 0}
    all_items, all_linked, complete_units = [], 0, 0
    for seg, fs in sorted(by_seg.items(), key=lambda kv: min(int(f["addr"], 16) for f in kv[1])):
        kind = seg_kind.get(seg, "game")
        cat = "sdk" if kind in ("sdk", "libc") else "game"
        items, linked = [], 0
        for f in sorted(fs, key=lambda f: int(f["addr"], 16)):
            st = f.get("status")
            if st == "matched":
                p = 100.0
            elif st == "wip" and isinstance(f.get("score"), (int, float)):
                p = float(min(f["score"], 99.99))
            else:
                p = 0.0
            item = {"name": f["name"], "size": int(f.get("size") or 0), "fuzzy_match_percent": p,
                    "metadata": {"virtual_address": int(f["addr"], 16)}}
            items.append(item)
            if st == "matched" and f.get("linked"):
                linked += item["size"]
        m = measures(items, linked)
        src_dir = repo / "src" / seg
        complete = bool(items) and all(i["fuzzy_match_percent"] >= 100.0 for i in items) and linked == m["total_code"]
        complete_units += int(complete)
        meta = {"complete": complete, "progress_categories": [cat], "auto_generated": False}
        if src_dir.is_dir():
            meta["source_path"] = f"src/{seg}/"
        units.append({"name": seg, "measures": m, "sections": [], "functions": items, "metadata": meta})
        cat_items[cat].extend(items); cat_linked[cat] += linked
        all_items.extend(items); all_linked += linked

    overall = measures(all_items, all_linked)
    overall["total_units"] = len(units); overall["complete_units"] = complete_units
    categories = []
    for cid, name in (("game", "Game code"), ("sdk", "SDK and libc")):
        if cat_items[cid]:
            categories.append({"id": cid, "name": name, "measures": measures(cat_items[cid], cat_linked[cid])})
    report = {"measures": overall, "units": units, "version": REPORT_VERSION, "categories": categories}
    out = repo / a.out
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(report, indent=1) + "\n", encoding="utf-8")
    print(f"{out.relative_to(repo)}: {target.get('boot_file', '?')} — {overall['matched_functions']}/{overall['total_functions']} functions matched, "
          f"{overall['matched_code']}/{overall['total_code']} bytes ({overall['matched_code_percent']}%), linked {overall['complete_code_percent']}%, "
          f"{len(units)} units, {len(categories)} categories")
    return 0


if __name__ == "__main__":
    sys.exit(main())
