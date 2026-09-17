# Friction Report — 2026-09-17-006-segment-map

**Job folder:** `2026-09-17-006-segment-map`  
**Log:** `friction-log.jsonl` (3 entries; opened 2026-09-17T06:50:05Z, exported 2026-09-17T07:02:05Z)  
**Skills build:** 2026-09-17-006  
**Severity counts:** minor 2, papercut 1  

## How to consume this report (for the remediating model)

You are reading an operator's friction log from one run (one step) of the
Decompilation Assistant (PS2) project. Before you implement anything,
internalize the rules the sibling projects' remediation rounds paid for:

1. **Reproduce every claim from its artifacts before implementing its fix.**
   Each entry separates OBSERVED (facts the operator saw, with artifact paths)
   from HYPOTHESIS (the operator's guess at the cause — explicitly unverified).
   A sibling project's report once proposed a remedy that verification showed
   would have turned 8 false positives into 31 false negatives. Reproduce first.
2. **Right symptom, wrong layer is the common failure.** Three diagnoses in
   one sibling remediation round were correct about the symptom and wrong
   about which layer owned the defect (instructions / knowledge / skill script
   / template), and each proposed fix would have passed its own test while
   leaving the defect in place. Trace the defect to the layer that owns it.
3. **A fix without a discriminating check is not a fix.** Every fix ships with
   a check that fails on the pre-fix version: a script test, a build-evidence
   transcript, or a `check.json` / ledger record that the old build could not
   have produced. A check that passes when the fix is absent tests nothing.
4. **Measure thresholds before shipping them.** Every cutoff you change in
   config/policy.json (batch size, attempt cap, permuter timeout) should cite
   the ledger or friction evidence that justifies it, in the commit message.
5. **Structural truncation check on every revised file:** no definitions lost,
   and growth accounted for. Never let a revised file ship truncated.
6. **Entries are review sites, not verdicts.** An operator can misread a tool
   (see any entry whose category is `operator-drift` or `evidence-gap`).
   Rejecting an entry with a reasoned refutation is a legitimate resolution —
   record it.

**Severity vocabulary:** **blocker** = stopped the pipeline or forced a forbidden action (e.g. a hand-edit); **major** = wrong output, missed detection, or substantial rework; **minor** = friction worked around within the sanctioned toolset; **papercut** = annoyance; no rework, but worth fixing.

**Category vocabulary:** **tool-bug** = a toolkit script or third-party tool (wibo, mwccps2, objdiff, splat, m2c, permuter) produced wrong output or crashed on sanctioned input; **tool-gap** = a needed capability is missing from the toolkit or the pinned toolchain; **toolchain-drift** = compiler, assembler, linker or objdiff behaviour differs from tools/manifest.json or from the doctrine in K1/K2 (a version that differs from the manifest, a preset that does not exist for the compiler); **doc-gap** = K1-K8, a SKILL.md or PROJECT-INSTRUCTIONS.md is silent or wrong where the run needed guidance; **doctrine-gap** = a step procedure in dps2-step is unclear or contradicts observed behaviour (a segment boundary found wrong, an entry state next_step.py misjudged); **evidence-gap** = a status, name, type or address could not be grounded in an artifact (no cited evidence for a name; objdiff could not read a compile that succeeded under wibo); **environment** = the VM bit: the ~3-minute device_bash cap, memory, network, the no-delete mount, host binutils without R5900; **operator-drift** = the operator caught itself outside the step: wanting to start a second step, a report over its length target, an unplanned subagent, instructed-looking re-checking of its own work; **false-signal** = a check false-positived or false-negatived (objdiff 100 but check.json red; check.json green with a wrong segment).

## Stage attestation

Silence is not evidence of frictionlessness: a stage is either attested (`clear-stage` recorded, with or without entries) or UNATTESTED (never examined — the operator never said). Entries without a `clear-stage` mean friction was seen and the review was not finished. UNATTESTED stages are holes in this report's coverage, not clean bills of health.

| Stage | Status |
|---|---|
| Stage R RESUME | attested clear |
| Stage S SELECT | attested clear |
| Stage E EXECUTE | 2 entries + attested complete |
| Stage V SHIP | attested clear |
| Cross-cutting / environment | 1 entry + attested complete |

## Entries (most severe first)

### F-1 — [minor / doctrine-gap] MW-runtime/SDK boundary is 8-mod-16; moved one function

- **Stage:** Stage E EXECUTE | **Tool:** `gen_splat_yaml.py` | **Logged:** 2026-09-17T07:01:24Z
- **Observed (fact):** The first ee-gcc (daddu-move) function is func_00102628 (vram 0x00102628, 8-mod-16). gen_splat_yaml.py requires 16-aligned starts, so mw_runtime/sdk_libgraph was set at func_001024C0 (0x001024C0); one MW function (90 insns) now sits in sdk_libgraph. Recorded in segments.json evidence.
- **Expected:** A boundary at the evidence's address
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** subalign 16 is a YAML constant; gcc objects are 8-aligned so any MW/gcc boundary can land on 8-mod-16 — a per-subsegment subalign (or accepting 8-aligned starts for asm subsegments) would remove the move

### F-2 — [minor / tool-gap] stale asm/ files from the previous split survive a resplit

- **Stage:** Stage E EXECUTE | **Tool:** `configure.py` | **Logged:** 2026-09-17T07:01:24Z
- **Observed (fact):** After configure.py --build with the 18-subsegment YAML, asm/ still held main.s (8.1 MB, S3 split), main_1.s (4.9 MB, the A6 link probe split) and asm/data/main_data.data.s beside the new per-segment files; ls asm/ asm/data/. Moved them to _delete/stretch-panic-usa-asm-stale/ by hand.
- **Expected:** configure.py clears (or moves aside) asm/ files that the current YAML does not name
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** splat only writes; nothing removes files from older YAMLs, and xrefs.py --index reads asm/*.s so every function would be indexed twice
- **Repro:** `ls targets/stretch-panic-usa/asm/ after a resplit with a different subsegment list`

### F-3 — [papercut / environment] device bridge dropped once mid-EXECUTE

- **Stage:** Cross-cutting / environment | **Logged:** 2026-09-17T07:01:24Z
- **Observed (fact):** The remote-devices server disconnected after a python3 read-only call (string map from disc/SLUS_201.82) and reconnected within a minute; /tmp/fns.json and the shell home survived, no work lost.
- **Expected:** no drop
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** transient link drop between the desktop app and the session

## Suggested remediation order

Blockers and majors first, then whichever minor/papercut fixes share a root cause with them (fixing one layer often clears several entries — and mis-locating the layer often "fixes" none; see rule 2 of the consumption contract).

## Evidence accounting

Cited artifacts: 0 — 0 present, 0 inside a checkpoint archive, 0 on another filesystem, 0 ephemeral (declared or retired), 0 unexplained. Archives searched: no checkpoint archives in the job folder.

## Machine-readable summary

```json
{
  "job": "2026-09-17-006-segment-map",
  "exported": "2026-09-17T07:02:05Z",
  "build": "2026-09-17-006",
  "entry_count": 3,
  "severity_counts": {
    "minor": 2,
    "papercut": 1
  },
  "stages": {
    "R": "attested clear",
    "S": "attested clear",
    "E": "2 entries + attested complete",
    "V": "attested clear",
    "X": "1 entry + attested complete"
  },
  "artifact_accounting": {
    "total": 0,
    "present": 0,
    "archived": 0,
    "other_fs": 0,
    "ephemeral": 0,
    "missing": 0
  },
  "retired_artifacts": [],
  "entries": [
    {
      "id": "F-1",
      "stage": "E",
      "severity": "minor",
      "category": "doctrine-gap",
      "title": "MW-runtime/SDK boundary is 8-mod-16; moved one function",
      "tool": "gen_splat_yaml.py"
    },
    {
      "id": "F-2",
      "stage": "E",
      "severity": "minor",
      "category": "tool-gap",
      "title": "stale asm/ files from the previous split survive a resplit",
      "tool": "configure.py"
    },
    {
      "id": "F-3",
      "stage": "X",
      "severity": "papercut",
      "category": "environment",
      "title": "device bridge dropped once mid-EXECUTE"
    }
  ]
}
```
