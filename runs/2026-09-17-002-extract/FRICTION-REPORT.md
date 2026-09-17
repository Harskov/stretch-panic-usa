# Friction Report — 2026-09-17-002-extract

**Job folder:** `2026-09-17-002-extract`  
**Log:** `friction-log.jsonl` (3 entries; opened 2026-09-17T02:36:02Z, exported 2026-09-17T02:38:20Z)  
**Skills build:** extract S1 (no build at S1)  
**Severity counts:** major 1, minor 1, papercut 1  

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
| Stage R RESUME | 1 entry + attested complete |
| Stage S SELECT | attested clear |
| Stage E EXECUTE | 1 entry + attested complete |
| Stage V SHIP | attested clear |
| Cross-cutting / environment | 1 entry + attested complete |

## Entries (most severe first)

### F-2 — [major / tool-gap] extract_elf.py could not read the disc: Stretch Panic ships as a raw 2352-byte-sector .bin+.cue, not a 2048-byte .iso

- **Stage:** Stage E EXECUTE | **Tool:** `extract_elf.py` | **Logged:** 2026-09-17T02:37:21Z
- **Observed (fact):** Stretch Panic (USA).cue: 'TRACK 01 MODE2/2352'; Stretch Panic (USA).bin is 221452560 bytes (94156 x 2352). extract_elf.py had SECTOR=2048 and Iso.sector() seeking lba*2048; at 16*2048 the bytes [1:6] are 00 00 00 00 00, not CD001, so pvd() would die('no ISO 9660 primary volume descriptor at sector 16..31'). At 16*2352+24 the bytes are 01 'CD001' (MODE2/2352 form 1: 12 sync + 4 header + 8 subheader + 2048 data).
- **Expected:** S1 extract works on any PS2 disc image at the project root; the first target's disc was an .iso, this one is a CD rip, and the step procedure names no conversion.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** The toolkit was written against the single .iso of target 1; CD-based PS2 discs (Stretch Panic is CD, SLUS_201.82) are commonly ripped as .bin+.cue, so every CD target would have hit this. Fixed in the layer that owns it: Iso now detects the sector mode at LBA 16 (2048 / 2352 mode 2 / 2352 mode 1), translates sector() and read() to the data area, and records iso.sector_mode in config/target.json. Pre-fix check: the 2048 reader at LBA 16 returns no CD001 on this file (reproduced above); post-fix the extract exits 0 with sha1 0a330e76424b7254e4096d8809b2a927603d3581.
- **Repro:** `python3 skills/dps2-toolkit/scripts/extract_elf.py --repo targets/stretch-panic-usa --iso 'Stretch Panic (USA).bin'`

### F-3 — [minor / doctrine-gap] a toolkit fix made during a run has no commit record: the project root is not a git repository

- **Stage:** Cross-cutting / environment | **Tool:** `extract_elf.py` | **Logged:** 2026-09-17T02:38:08Z
- **Observed (fact):** ls -d .git at the project root: absent; only targets/<slug>/ are repos. The extract_elf.py fix of F-2 lives in skills/dps2-toolkit/scripts/ on the mount and is in no commit; the run commit (git_mount.sh targets/stretch-panic-usa) covers the target repo only. Pre-fix copy saved to _backup/extract_elf.py.pre-raw-2352.20260917.
- **Expected:** Every change a run makes to disk is recorded somewhere a later run can read, as the deliverables section requires for the tree changes.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** The layer map assumes toolkit changes happen in remediation rounds, which record themselves in build-evidence/; a step-run fix of a blocking tool defect has no such home. Shared scripts also change under the other target with no record in its history.

### F-1 — [papercut / tool-gap] targets.py resolve does not match the game name for stretch-panic-usa

- **Stage:** Stage R RESUME | **Tool:** `targets.py` | **Logged:** 2026-09-17T02:36:02Z
- **Observed (fact):** python3 skills/dps2-toolkit/scripts/targets.py resolve 'Stretch Panic' -> exit 1, 'no target matches Stretch Panic; targets: fate-unlimited-codes-jp, stretch-panic-usa'. targets.py list shows the target's title as 'stretch-panic-usa' (no game title), while fate's title is 'Fate/Unlimited Codes (Japan) SLPM_551.08'.
- **Expected:** A request naming the game ('Stretch Panic') resolves to slug stretch-panic-usa.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** S0 bootstrap was run without --title for this target, so config has no title for resolve to match against; resolve matches slug tokens only and 'Stretch Panic' with a space does not tokenise to 'stretch-panic-usa'.
- **Repro:** `python3 skills/dps2-toolkit/scripts/targets.py resolve 'Stretch Panic'`

## Suggested remediation order

Blockers and majors first, then whichever minor/papercut fixes share a root cause with them (fixing one layer often clears several entries — and mis-locating the layer often "fixes" none; see rule 2 of the consumption contract).

## Evidence accounting

Cited artifacts: 0 — 0 present, 0 inside a checkpoint archive, 0 on another filesystem, 0 ephemeral (declared or retired), 0 unexplained. Archives searched: no checkpoint archives in the job folder.

## Machine-readable summary

```json
{
  "job": "2026-09-17-002-extract",
  "exported": "2026-09-17T02:38:20Z",
  "build": "extract S1 (no build at S1)",
  "entry_count": 3,
  "severity_counts": {
    "major": 1,
    "minor": 1,
    "papercut": 1
  },
  "stages": {
    "R": "1 entry + attested complete",
    "S": "attested clear",
    "E": "1 entry + attested complete",
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
      "id": "F-2",
      "stage": "E",
      "severity": "major",
      "category": "tool-gap",
      "title": "extract_elf.py could not read the disc: Stretch Panic ships as a raw 2352-byte-sector .bin+.cue, not a 2048-byte .iso",
      "tool": "extract_elf.py"
    },
    {
      "id": "F-3",
      "stage": "X",
      "severity": "minor",
      "category": "doctrine-gap",
      "title": "a toolkit fix made during a run has no commit record: the project root is not a git repository",
      "tool": "extract_elf.py"
    },
    {
      "id": "F-1",
      "stage": "R",
      "severity": "papercut",
      "category": "tool-gap",
      "title": "targets.py resolve does not match the game name for stretch-panic-usa",
      "tool": "targets.py"
    }
  ]
}
```
