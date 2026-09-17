# Friction Report — 2026-09-17-001-bootstrap

**Job folder:** `2026-09-17-001-bootstrap`  
**Log:** `friction-log.jsonl` (2 entries; opened 2026-09-17T01:53:03Z, exported 2026-09-17T01:56:04Z)  
**Skills build:** S0 bootstrap: splat 0.50.0 / objdiff 3.7.3 / wibo 1.2.0 / binutils-deb 2.35.2; 11/11 smoke ok  
**Severity counts:** blocker 1, major 1  

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

### F-1 — [blocker / environment] device VM session disk 100% full; $HOME unusable for scratch

- **Stage:** Stage R RESUME | **Logged:** 2026-09-17T01:53:03Z
- **Observed (fact):** df -h $HOME: /dev/sdc 9.8G size, 9.3G used, 0 Avail, 100% on /sessions. 'mkdir $HOME/tmp/spacetest' -> 'No space left on device'. du -sh /sessions/* sums to 1.9G (the passthrough mount), so the used space is other sessions' directories, unreadable and not freeable from here. The project folder itself is a passthrough with 245G free (df -h . -> /proc/self/fd/3 932G, 245G Avail). /tmp is on / (9.6G, 4.1G Avail) and writable: dd 100MiB ok.
- **Expected:** a writable $HOME on the VM, since bootstrap.sh clones into $HOME before copying to the mount
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** the /sessions disk is shared across desktop sessions on this device and was filled by other sessions; it is not this project's data
- **Repro:** `df -h $HOME; mkdir $HOME/tmp/spacetest`

### F-2 — [major / tool-gap] bootstrap.sh hardcodes $HOME for the clone scratch with no override

- **Stage:** Stage E EXECUTE | **Tool:** `bootstrap.sh` | **Logged:** 2026-09-17T01:53:12Z
- **Observed (fact):** bootstrap.sh line 150: local tmp="$HOME/dps2-clone-$$-$name" is the only $HOME use in the script (grep -n 'HOME|TMPDIR|/tmp' returns one hit). With $HOME full, stage clones cannot run. Workaround used in this run: prefix every bootstrap.sh call with HOME=/tmp/dps2-home (the script uses $HOME for nothing else; pip's cache and venv temp also follow HOME/TMPDIR).
- **Expected:** a --scratch/$TMPDIR-honouring scratch location, or a fallback when $HOME has no space
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** the v1 build wrote the clone into $HOME to dodge the mount's unlink problem (comment at line 148) and no fallback was needed because the VM disk was empty then
- **Repro:** `HOME=/tmp/dps2-home bash skills/dps2-toolkit/scripts/bootstrap.sh --repo targets/stretch-panic-usa --stage clones`

## Suggested remediation order

Blockers and majors first, then whichever minor/papercut fixes share a root cause with them (fixing one layer often clears several entries — and mis-locating the layer often "fixes" none; see rule 2 of the consumption contract).

## Evidence accounting

Cited artifacts: 0 — 0 present, 0 inside a checkpoint archive, 0 on another filesystem, 0 ephemeral (declared or retired), 0 unexplained. Archives searched: no checkpoint archives in the job folder.

## Machine-readable summary

```json
{
  "job": "2026-09-17-001-bootstrap",
  "exported": "2026-09-17T01:56:04Z",
  "build": "S0 bootstrap: splat 0.50.0 / objdiff 3.7.3 / wibo 1.2.0 / binutils-deb 2.35.2; 11/11 smoke ok",
  "entry_count": 2,
  "severity_counts": {
    "blocker": 1,
    "major": 1
  },
  "stages": {
    "R": "1 entry + attested complete",
    "S": "attested clear",
    "E": "1 entry + attested complete",
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
      "stage": "R",
      "severity": "blocker",
      "category": "environment",
      "title": "device VM session disk 100% full; $HOME unusable for scratch"
    },
    {
      "id": "F-2",
      "stage": "E",
      "severity": "major",
      "category": "tool-gap",
      "title": "bootstrap.sh hardcodes $HOME for the clone scratch with no override",
      "tool": "bootstrap.sh"
    }
  ]
}
```
