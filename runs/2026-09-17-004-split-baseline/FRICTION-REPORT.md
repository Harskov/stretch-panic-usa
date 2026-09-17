# Friction Report — 2026-09-17-004-split-baseline

**Job folder:** `2026-09-17-004-split-baseline`  
**Log:** `friction-log.jsonl` (2 entries; opened 2026-09-17T05:42:31Z, exported 2026-09-17T05:51:31Z)  
**Skills build:** v7-remediation-7  
**Severity counts:** blocker 2  

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

### F-1 — [blocker / tool-bug] splat 0.50.0 emits the .main_bss ld entry but writes no asm/data/main_bss.bss.s, so the first link cannot start

- **Stage:** Stage E EXECUTE | **Tool:** `configure.py` | **Logged:** 2026-09-17T05:48:24Z
- **Observed (fact):** configure.py --repo targets/stretch-panic-usa --build: splat rc=0 in 63.9s, 'Split 5 MB (99.96%) ... asm: 5 MB 1 split', then 'ninja: error: asm/data/main_bss.bss.s, needed by build/asm/data/main_bss.bss.s.o, missing and no known rule to make it'. build/SLUS_201.82.ld line 32 has build/asm/data/main_bss.bss.s.o(.bss) inside .main_bss (NOLOAD). A second, direct splat run (tools/venv/bin/python -m splat split config/SLUS_201.82.yaml, rc=0) left asm/ holding only main.s; asm/data/ does not exist. YAML: subsegments [0x00000380, asm, main] and [0x0059FB80, bss, main_bss], segment bss_size 0x00014100, end marker [0x0059FB80] - the same shape as targets/fate-unlimited-codes-jp, whose asm/data/main_bss.bss.s (29 bytes, '.section .bss' + '.space 0x2D180', mtime 2026-09-05 19:52) predates its own S3 run folder (friction log opened 2026-09-05T20:23:11Z) and was therefore never observed being generated.
- **Expected:** splat writes the .s file for every subsegment it references from the linker script, so the asm-only baseline links on the first configure.py --build
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** splat 0.50.0 / spimdisasm 1.42.4 emit no file for a bss subsegment (nothing to disassemble: the region is NOLOAD and has no file bytes) while the ld template lists the object unconditionally; the Fate target only builds because an equivalent stub was created by hand before its S3 run and has survived since, so the defect was invisible on the only previous S3. UNVERIFIED.
- **Artifact:** `../../build/SLUS_201.82.ld` (exists)
- **Repro:** `python3 skills/dps2-toolkit/scripts/gen_splat_yaml.py --repo targets/stretch-panic-usa --initial --force && python3 skills/dps2-toolkit/scripts/configure.py --repo targets/stretch-panic-usa --build`

### F-2 — [blocker / doctrine-gap] S3's one-asm-subsegment baseline does not assemble for this target: 656 R5900-invalid opcodes from data decoded as code, and the step procedure has no minimal data-typing move

- **Stage:** Stage E EXECUTE | **Tool:** `gen_splat_yaml.py` | **Logged:** 2026-09-17T05:50:57Z
- **Observed (fact):** mipsel-linux-gnu-as -EL -march=r5900 -mabi=eabi -no-pad-sections -G0 on asm/main.s: 656 errors, 'opcode not supported on this processor: r5900 (mips3)' — 654 lld, 2 sdc1 — plus 1 'Warning: divide by zero' at line 1140964. The error lines fall in 8 runs between asm/main.s:1143889 and :1149096, i.e. VRAM 0x0054A8EC to 0x0054F29C. The bytes there are filler, not code: 0x0054E868-0x0054F29C is 0xCBD3CBD3 repeated (decoded as 'lld $t3, -0x2C35($fp) /* handwritten instruction */'), the two sdc1 sites sit in 0x9A9A9AFF / 0xFDFBA3F6 runs, and asm/main.s:1148405 just above the big run is already emitted as '.word 0xD3CBD3CB'. splat typed the whole image as one asm subsegment because dps2-step S3 says to: 'one asm subsegment + bss'. Fate/Unlimited Codes' S3 assembled on that shape, so the procedure has never met an image whose data decodes to opcodes the pinned R5900 assembler refuses.
- **Expected:** the S3 initial YAML assembles to an asm-only ELF for any PS2 target, or the S3 procedure says how much data typing is allowed before the segment map (S4)
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** spimdisasm decodes every word in an asm subsegment as an instruction and only falls back to .word for a few patterns, so a filler blob at 0x0054A8E0-0x0054F2A0 becomes lld/sdc1, which exist in MIPS III but not on the R5900 (no ll/sc/lld/scd, single-precision FPU only); the fix is a narrow 'data' subsegment over that range in the S3 YAML, with the real boundaries left to S4. The region's true start and end were not yet established when the run was cut short. UNVERIFIED.
- **Artifact:** `../../asm/main.s` (exists)
- **Repro:** `cd targets/stretch-panic-usa && LD_LIBRARY_PATH=tools/binutils-deb/usr/lib/x86_64-linux-gnu tools/binutils-deb/usr/bin/mipsel-linux-gnu-as -EL -march=r5900 -mabi=eabi -no-pad-sections -G0 -I include -o /tmp/main.o asm/main.s`

## Suggested remediation order

Blockers and majors first, then whichever minor/papercut fixes share a root cause with them (fixing one layer often clears several entries — and mis-locating the layer often "fixes" none; see rule 2 of the consumption contract).

## Evidence accounting

Cited artifacts: 2 — 2 present, 0 inside a checkpoint archive, 0 on another filesystem, 0 ephemeral (declared or retired), 0 unexplained. Archives searched: no checkpoint archives in the job folder.

## Machine-readable summary

```json
{
  "job": "2026-09-17-004-split-baseline",
  "exported": "2026-09-17T05:51:31Z",
  "build": "v7-remediation-7",
  "entry_count": 2,
  "severity_counts": {
    "blocker": 2
  },
  "stages": {
    "R": "attested clear",
    "S": "attested clear",
    "E": "2 entries + attested complete",
    "V": "attested clear",
    "X": "attested clear"
  },
  "artifact_accounting": {
    "total": 2,
    "present": 2,
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
      "severity": "blocker",
      "category": "tool-bug",
      "title": "splat 0.50.0 emits the .main_bss ld entry but writes no asm/data/main_bss.bss.s, so the first link cannot start",
      "tool": "configure.py"
    },
    {
      "id": "F-2",
      "stage": "E",
      "severity": "blocker",
      "category": "doctrine-gap",
      "title": "S3's one-asm-subsegment baseline does not assemble for this target: 656 R5900-invalid opcodes from data decoded as code, and the step procedure has no minimal data-typing move",
      "tool": "gen_splat_yaml.py"
    }
  ]
}
```
