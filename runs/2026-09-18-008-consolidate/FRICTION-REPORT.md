# Friction Report — 2026-09-18-008-consolidate

**Job folder:** `2026-09-18-008-consolidate`  
**Log:** `friction-log.jsonl` (2 entries; opened 2026-09-18T20:51:42Z, exported 2026-09-18T21:00:35Z)  
**Skills build:** dps2 2026-09-18 / mwcps2-2.3.3-000906  
**Severity counts:** major 1, minor 1  

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

### F-1 — [major / tool-gap] xrefs.py cannot report a matched, linked function — the evidence S8 needs disappears at the moment a function is matched

- **Stage:** Stage E EXECUTE | **Tool:** `xrefs.py` | **Logged:** 2026-09-18T20:57:37Z
- **Observed (fact):** xrefs.py --repo targets/stretch-panic-usa <fn> answered 'no glabel block in asm/ (a data symbol, or the asm predates the split)' for func_00131740, func_00145A10, func_00157650 and func_00164E80 — 4 of the 33 matched functions. Those four wip/<fn>/ folders hold only relink.o and relink.o.text.bin: no target.s. The other 29 answered because their wip/<fn>/target.s still exists from match.py prepare. xrefs.py --index reported '2052 functions, 12536 data symbols' from asm/ + wip/*/target.s; splat stops emitting asm for a function once it is linked.
- **Expected:** A matched function's callers, callees and referenced data are readable at S8, which is the step whose whole job is naming matched functions from exactly that evidence.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** The index is built from asm/ and wip/*/target.s only. A linked function has no asm/ block, and ledger.py relink replaces its wip/ contents with relink.o, so its target.s is gone. The index could instead read the function's own src/<seg>/<fn>.c, or keep target.s across relink, or read the original ELF.
- **Repro:** `python3 skills/dps2-toolkit/scripts/xrefs.py --repo targets/stretch-panic-usa func_00131740`

### F-2 — [minor / evidence-gap] no admitted naming evidence exists anywhere in this target yet

- **Stage:** Stage E EXECUTE | **Logged:** 2026-09-18T20:57:37Z
- **Observed (fact):** config/symbol_addrs.txt holds 0 non-systematic names; ledger/functions.jsonl holds 0 named library functions; xrefs.py reported 'references (0): none' for every matched function and for all 8 of their callers except func_00167ED0 (D_006A6B80, which has no dlabel in asm/ and decodes to no string); reference/ghidra/ does not exist (S5 never run on this target). 33 matched functions, 0 renameable.
- **Expected:** At least one of the five admitted sources — a referenced string, an SDK call pattern, an xref from a named caller, a TCRF fact, a Ghidra hint — reaches some matched function.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** game_01 is a leaf-heavy region of small virtual methods that touch neither strings nor the SDK. The one source that could be opened without S5: asm/sdk_libkernel.s at 0x00104E40 onward is the PS2 kernel syscall stub table (addiu $v1, $zero, N; syscall; jr $ra, N running 0,1,2,... in 0x10 steps), whose numbers are public; naming those 339 library stubs from a cited table would give named callees to every game function that calls one.

## Suggested remediation order

Blockers and majors first, then whichever minor/papercut fixes share a root cause with them (fixing one layer often clears several entries — and mis-locating the layer often "fixes" none; see rule 2 of the consumption contract).

## Evidence accounting

Cited artifacts: 0 — 0 present, 0 inside a checkpoint archive, 0 on another filesystem, 0 ephemeral (declared or retired), 0 unexplained. Archives searched: no checkpoint archives in the job folder.

## Machine-readable summary

```json
{
  "job": "2026-09-18-008-consolidate",
  "exported": "2026-09-18T21:00:35Z",
  "build": "dps2 2026-09-18 / mwcps2-2.3.3-000906",
  "entry_count": 2,
  "severity_counts": {
    "major": 1,
    "minor": 1
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
      "title": "xrefs.py cannot report a matched, linked function — the evidence S8 needs disappears at the moment a function is matched",
      "tool": "xrefs.py"
    },
    {
      "id": "F-2",
      "stage": "E",
      "severity": "minor",
      "category": "evidence-gap",
      "title": "no admitted naming evidence exists anywhere in this target yet"
    }
  ]
}
```
