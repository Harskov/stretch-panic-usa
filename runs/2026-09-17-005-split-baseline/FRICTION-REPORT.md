# Friction Report — 2026-09-17-005-split-baseline

**Job folder:** `2026-09-17-005-split-baseline`  
**Log:** `friction-log.jsonl` (2 entries; opened 2026-09-17T05:54:59Z, exported 2026-09-17T06:01:43Z)  
**Skills build:** 2026-09-17-005-split-baseline  
**Severity counts:** major 1, papercut 1  

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
| Cross-cutting / environment | attested clear |

## Entries (most severe first)

### F-1 — [major / tool-gap] gen_splat_yaml.py --initial cannot express a data subsegment, so the S3 restore-the-baseline step would drop the split that makes this target assemble

- **Stage:** Stage E EXECUTE | **Tool:** `gen_splat_yaml.py` | **Logged:** 2026-09-17T06:01:15Z
- **Observed (fact):** S3 baseline needed [0x0007F280, data, main_data] (code ends at vram 0x0017EF00; fingerprint.json classes 0x180000-0x69F800 as data; run 004 F-2: 656 lld/sdc1 errors from filler). --initial has no option for it; the doc's 'gen_splat_yaml.py --initial --force' after the A6 probe would regenerate the one-asm YAML. Worked around by saving config/SLUS_201.82.yaml to runs/2026-09-17-005-split-baseline/baseline.yaml before the probe and copying it back.
- **Expected:** --initial reads an optional list of pre-S4 data ranges (e.g. config/splat-yaml.json initial_data_ranges) or the S3 procedure says to hand-restore the saved YAML
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** the initial-YAML shape was designed on Fate, whose whole image assembles as code; a code+assets image was not anticipated
- **Repro:** `python3 skills/dps2-toolkit/scripts/gen_splat_yaml.py --repo targets/stretch-panic-usa --initial --force && grep main_data targets/stretch-panic-usa/config/SLUS_201.82.yaml`

### F-2 — [papercut / tool-gap] string_encoding SHIFT-JIS hardcoded for a US target with language_hint C

- **Stage:** Stage E EXECUTE | **Tool:** `gen_splat_yaml.py` | **Logged:** 2026-09-17T06:01:15Z
- **Observed (fact):** gen_splat_yaml.py lines 152-153 write string_encoding/data_string_encoding: SHIFT-JIS unconditionally; config/target.json language_hint is "C". Affects only splat's string comments, not bytes; check.json green.
- **Expected:** encoding chosen per target from target.json
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** copied from the Fate (JP) template

## Suggested remediation order

Blockers and majors first, then whichever minor/papercut fixes share a root cause with them (fixing one layer often clears several entries — and mis-locating the layer often "fixes" none; see rule 2 of the consumption contract).

## Evidence accounting

Cited artifacts: 0 — 0 present, 0 inside a checkpoint archive, 0 on another filesystem, 0 ephemeral (declared or retired), 0 unexplained. Archives searched: no checkpoint archives in the job folder.

## Machine-readable summary

```json
{
  "job": "2026-09-17-005-split-baseline",
  "exported": "2026-09-17T06:01:43Z",
  "build": "2026-09-17-005-split-baseline",
  "entry_count": 2,
  "severity_counts": {
    "major": 1,
    "papercut": 1
  },
  "stages": {
    "R": "attested clear",
    "S": "attested clear",
    "E": "2 entries + attested complete",
    "V": "attested clear",
    "X": "attested clear"
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
      "severity": "major",
      "category": "tool-gap",
      "title": "gen_splat_yaml.py --initial cannot express a data subsegment, so the S3 restore-the-baseline step would drop the split that makes this target assemble",
      "tool": "gen_splat_yaml.py"
    },
    {
      "id": "F-2",
      "stage": "E",
      "severity": "papercut",
      "category": "tool-gap",
      "title": "string_encoding SHIFT-JIS hardcoded for a US target with language_hint C",
      "tool": "gen_splat_yaml.py"
    }
  ]
}
```
