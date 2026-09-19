# Friction Report — 2026-09-19-010-ghidra-hints

**Job folder:** `2026-09-19-010-ghidra-hints`  
**Log:** `friction-log.jsonl` (2 entries; opened 2026-09-19T04:42:41Z, exported 2026-09-19T04:47:01Z)  
**Skills build:** Ghidra 12.1.3 PUBLIC / ee-reloaded v2.1.37 / JDK 21.0.10 (cloud sandbox)  
**Severity counts:** minor 1, papercut 1  

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
| Cross-cutting / environment | attested clear |

## Entries (most severe first)

### F-2 — [minor / evidence-gap] Ghidra's auto-analysis misses the tiny leaf functions S6 matches first: only 25 of 77 matched functions got a hint

- **Stage:** Stage E EXECUTE | **Logged:** 2026-09-19T04:46:02Z
- **Observed (fact):** runs/2026-09-19-010-ghidra-hints/hints-table.md: 1660 of 2027 ledger entries are Ghidra function starts, but only 25 of the 77 matched ones are. The 52 uncovered matched functions are all in game_01 (50) and game_00 (2), 0x00131740-0x00176F50, and none of them falls inside a Ghidra function body - Ghidra created no function there at all. 37 of the 52 are 8 bytes long. On fate-unlimited-codes-jp the same export covered 93 of 94 matched functions.
- **Expected:** a hint for every function the ledger knows, since the ledger's starts come from splat and are the project's
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** Ghidra's auto-analyzer only creates a function where it finds a call or an entry reference, so 8-byte leaf stubs reached only through a jump table or a data pointer stay undefined code. A pre-script that calls createFunction at every address in config/symbol_addrs.txt before the export would close the gap; the ledger's boundaries are authoritative either way (K3 §8).
- **Artifact:** `hints-table.md` (exists)

### F-1 — [papercut / tool-bug] git checkout -- .gitignore through git_mount.sh did not restore the file

- **Stage:** Stage R RESUME | **Tool:** `git_mount.sh` | **Logged:** 2026-09-19T04:42:41Z
- **Observed (fact):** During the fate run the S5 ignore rule was appended to this target's .gitignore too, then reverted with 'git_mount.sh targets/stretch-panic-usa checkout -- .gitignore'; the command printed nothing and exited, but at this RESUME 'git status --short' still showed ' M .gitignore' with the five added lines, and git_sync.sh pull refused with exit 2 (dirty tree).
- **Expected:** either the checkout restores the file or it reports that it cannot
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** K6's known mount limitation - git cannot replace a tracked file on the mount ('unable to unlink old') - applies to checkout as well as revert, and git_mount.sh swallows the failure instead of surfacing it. Worked around by committing the rule as its own commit (407e404), which this target's own S5 needed anyway.
- **Repro:** `bash skills/dps2-toolkit/scripts/git_mount.sh targets/<slug> checkout -- .gitignore`

## Suggested remediation order

Blockers and majors first, then whichever minor/papercut fixes share a root cause with them (fixing one layer often clears several entries — and mis-locating the layer often "fixes" none; see rule 2 of the consumption contract).

## Evidence accounting

Cited artifacts: 1 — 1 present, 0 inside a checkpoint archive, 0 on another filesystem, 0 ephemeral (declared or retired), 0 unexplained. Archives searched: no checkpoint archives in the job folder.

## Machine-readable summary

```json
{
  "job": "2026-09-19-010-ghidra-hints",
  "exported": "2026-09-19T04:47:01Z",
  "build": "Ghidra 12.1.3 PUBLIC / ee-reloaded v2.1.37 / JDK 21.0.10 (cloud sandbox)",
  "entry_count": 2,
  "severity_counts": {
    "minor": 1,
    "papercut": 1
  },
  "stages": {
    "R": "1 entry + attested complete",
    "S": "attested clear",
    "E": "1 entry + attested complete",
    "V": "attested clear",
    "X": "attested clear"
  },
  "artifact_accounting": {
    "total": 1,
    "present": 1,
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
      "severity": "minor",
      "category": "evidence-gap",
      "title": "Ghidra's auto-analysis misses the tiny leaf functions S6 matches first: only 25 of 77 matched functions got a hint"
    },
    {
      "id": "F-1",
      "stage": "R",
      "severity": "papercut",
      "category": "tool-bug",
      "title": "git checkout -- .gitignore through git_mount.sh did not restore the file",
      "tool": "git_mount.sh"
    }
  ]
}
```
