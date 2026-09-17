# Run 2026-09-17-006-segment-map — segment-map

- Target: stretch-panic-usa
- Step: segment-map (S4) — proposed by next_step.py
- Started: 2026-09-17T06:50:05Z · Finished: 2026-09-17T07:02:04Z
- Commit: the commit whose message starts `run 2026-09-17-006-segment-map:` (git log --grep)

## What changed

- Ledger: functions 8 → 2027 (+2019), wip 4 → 2 (-2), asm 0 → 1349 (+1349), library 0 → 672 (+672).
- The map rests on two per-instruction idioms, not the 64 KB windows: paddub-move (CodeWarrior) versus daddu-move (ee-gcc). They partition the text cleanly — 13 MW functions after crt0 (the MW C++ runtime, std::exception strings), 378 gcc functions 0x00102628-0x0011F5E0 (the SDK, libraries ordered libgraph, libdma, libkernel, libpad, libcdvd, libmc, libm, libc by their own strings at 0x00699A88-0x0069B148), then 1351 MW functions with no gcc move at all. The memory-card save code is a call-graph island (0x00145A90-0x00147F60) whose only outside callees are libmc and libc, so it is its own game segment. The data region is .data (VU microcode packets, then SDK vtables/data from 0x00196080, then game data/assets) followed by one .rodata tail from 0x00699800 ('std::exception', SDK strings, libm/libc tables, game strings, jump tables, type_info records) — typed rodata and the split build stayed green. Boundaries without a string on the boundary function itself are marked approximate in the table; the MW-runtime/SDK boundary had to move from 0x00102628 to 0x001024C0 for 16-alignment (F-1). The stale asm/main.s from the S3 split was moved to _delete/ (F-2).

## Build check

`check.json`: ok = **True**, checked 2026-09-17T07:00:59Z, regime `full`; image 0x00100000–0x0069F800, rebuilt 5896192 of 5896192 bytes; first diff None, 0 differing byte(s). Segments: crt0 ok; mw_runtime ok; sdk_libgraph ok; sdk_libdma ok; sdk_libkernel ok; sdk_libpad ok; sdk_libcdvd ok; sdk_libmc ok.

## Step table

# Segment table — run 2026-09-17-006-segment-map (Stretch Panic (USA) SLUS_201.82)

Every start is a 16-byte-aligned function start (code) or 16-aligned address (data); segments are contiguous 0x00100000-0x006B3900. Function counts and statuses from ledger/functions.jsonl after import-functions + relink; referencing functions of data/rodata segments from %hi/%lo/%gp_rel operands in asm/. Build: split YAML of 18 segment subsegments, 26 after relink (4 c subsegments each splitting an asm one) — check.json ok: true.

| # | Segment | Kind | Start | End | Size | Functions (status) | Refs | Evidence |
|---|---|---|---|---|---|---|---|---|
| 1 | crt0 | game | 0x00100000 | 0x001000F0 | 0xF0 | 4 (asm 4) | — | entry 0x00100008 (config/target.json elf_header.entry); func_00100008 zeroes bss 0x0069F800.. with sq and sets $gp=0x006A77F0 (asm/main.s 'Handwritten function'); 5 functions func_00100000-func_001000C0, no compiler idiom |
| 2 | mw_runtime | libc | 0x001000F0 | 0x001024C0 | 0x23D0 | 39 (library 39) | — | CodeWarrior runtime (MSL/C++ support): paddub move idiom in func_001000F0/170/210/260, 0x1008D0, 0x100F70, 0x101250 (fingerprint mw_move; zero gcc daddu moves); strings 'exception' func_001006E0, '!std::exception!!std::bad_alloc!!' func_00100710/func_00100810, 'bad_alloc' func_00100800, '!std::bad_exception!!' func_00101250, 'bad_exception' func_001022A0 (rodata 0x00699800-0x00699A78) / boundary note: the gcc block starts at func_00102628 (8-mod-16); moved to the nearest 16-aligned function start func_001024C0, so func_001024C0 (MW, 90 insns) sits in sdk_libgraph — both library kind |
| 3 | sdk_libgraph | sdk | 0x001024C0 | 0x001039B0 | 0x14F0 | 21 (library 21) | — | first daddu-move (ee-gcc) function func_00102628; 'sceGsDefDispEnv:Not support' referenced by func_001027B0, 'sceGsPutDrawEnv' (0x00699AC0) by func_00102E98, 'sceGsSyncPath' x5 (0x00699AF0-0x00699C58) and 'D1_TADR=%08x:'/'D2_MADR=%08x:' dump strings by func_00103310 |
| 4 | sdk_libdma | sdk | 0x001039B0 | 0x00104150 | 0x7A0 | 12 (library 12) | — | 'libdma: sync timeout' (0x00699C80) referenced by the 8 consecutive functions func_001039B0-func_00103FC8 (sceDmaSync per channel); func_00104098-func_00104108 are 8-18-insn accessors with no strings, kept here; boundary at the next 16-aligned start func_00104150 |
| 5 | sdk_libkernel | sdk | 0x00104150 | 0x0010CCA0 | 0x8B50 | 339 (library 339) | — | 138 syscall stubs func_00104E40-func_001056D0 (<=6 insns each); '## internel error in libkernl.' (0x00699C98) func_00105FE8; 'TTY: receive error'/'TTY: send err %d' func_001065D0; kernel printf float formatting '0.%d'/'e+%d' func_00106BF8; sif rpc block func_00109270-func_0010BE10 (10-18 calls each); 'rom0:UDNL ' + 'too long parameter' (sceSifRebootIop) func_0010CB10 |
| 6 | sdk_libpad | sdk | 0x0010CCA0 | 0x0010E1D0 | 0x1530 | 34 (library 34) | — | 'libpad: sceSifSetDma faild' func_0010CCA0; 'libpad: Module version mismatch ' + '[libpad.a = %d.%d, padman.irx' func_0010CDD0; 'libpad: buffer addr is not 64 byte align'/'pad port is already open' func_0010D030 (0x00699F40-0x0069A008) |
| 7 | sdk_libcdvd | sdk | 0x0010E1D0 | 0x00110FC0 | 0x2DF0 | 48 (library 48) | — | 'sceCdCbfunc= %d sceCdCbfunc_num' func_0010E1D0; 'Libcdvd bind err ...' func_0010E6F8/func_0010E880/func_0010EB80/func_0010FA28/func_0010FB98/func_0010FE78; 'sceCdStRead'/'sceCdStPause call'/'sceCdStResume call'/'sceCdStStat call' func_00110BE8-func_00110E18 (0x0069A098-0x0069A498) |
| 8 | sdk_libmc | sdk | 0x00110FC0 | 0x00112660 | 0x16A0 | 26 (library 26) | — | 'bind error libmc '/'libmc: too old release of mcserv.irx'/'mcman.irx' (0x0069A4B0-0x0069A4F0) func_00110FC0; func_00110FC0-func_00111FE8 are the only SDK callees of the game's memory-card cluster game_memcard (func_00145A90-func_00147F50) |
| 9 | sdk_libm | sdk | 0x00112660 | 0x00115900 | 0x32A0 | 30 (library 30) | — | entry points naming themselves for errno/matherr: 'acosf' func_00114FB8, 'asinf' func_001150B8, 'atan2f' func_001151B8, 'expf' func_001152E0, 'logf' func_00115458 (0x0069AA30-0x0069AA60), all sharing the table at 0x0069A9D0; call-free table functions func_00112660-func_001133E8 reference the constant block 0x0069A530-0x0069A8D0 |
| 10 | sdk_libc | libc | 0x00115900 | 0x0011F5E0 | 0x9CE0 | 123 (library 123) | — | 'Infinity'/'NaN' (strtod) func_00115900 (1118 insns); vfprintf: '0123456789abcdef', '(null)', 'bug in vfprintf: bad base' func_0011A9B8 (0x0069AC60-0x0069ACA8); last daddu-move function func_0011F5A0; ends at the first paddub (MW) function func_0011F5E0 |
| 11 | game_00 | game | 0x0011F5E0 | 0x00145A90 | 0x264B0 | 563 (asm 560, matched 2, wip 1) | — | MW game code (paddub moves, sq/lq saves, zero daddu moves from here to 0x0017EF00); IOP module loader 'cdrom0:\MODULES\IOPRP222.IMG;1', SIO2MAN/PADMAN/MCMAN/MCSERV paths (0x0069B250-0x0069B300) func_0011FA50; 'ERROR: scePadRead' func_00120A70; '%12.8f' func_00123F70; sound module paths 'cdrom0:\MODULES\LIBSD.IRX;1'/'SMSPS2.IRX' func_0013DBF0 |
| 12 | game_memcard | game | 0x00145A90 | 0x00147F60 | 0x24D0 | 74 (asm 74) | — | memory-card save cluster: '/BASLUS-20182SPANIC' func_00146060/func_00146FD0/func_00147260/func_001472F0/func_00147380/func_00147C90/func_00147DC0, 'icon.sys'+'PS2D' func_00147080, 's_panic.ico' func_00147120; call-graph island func_00145A90-func_00147F50 whose only outside callees are sdk_libmc (func_00110FC0-func_00111FE8) and sdk_libc (func_00119A40, func_0011A1F0); func_00147F60-func_00149B50 have no calls in or out |
| 13 | game_01 | game | 0x00147F60 | 0x0017EF00 | 0x36FA0 | 714 (asm 711, matched 2, wip 1) | — | MW game code after the memory-card cluster; '33s?fff?' func_00177D00; last function func_0017ED50 + nop pad to 0x0017EF00 (S3 run 005 boundary; fingerprint.json classes 0x180000-0x69F800 data) |
| 14 | data_vu | data | 0x0017EF00 | 0x00196080 | 0x17180 | 0 () | 0 | first data after the text: VIF MPG packet 0x4AA00000 at 0x0017EF0C followed by VU instruction pairs with the 0x000002FF NOP upper word through 0x00196038, zero pad to 0x00196080; no %hi/%lo reference from any function |
| 15 | data_sdk | data | 0x00196080 | 0x00197250 | 0x11D0 | 0 () | 158 | first mw_runtime reference 0x00196080 (vtable of code pointers func_00100710/0x00100BD0/0x00100BA0); 68 distinct addresses 0x00196080-0x00197228 referenced only by mw_runtime and SDK functions; first game reference 0x00197250 |
| 16 | data_game | data | 0x00197250 | 0x00699800 | 0x5025B0 | 0 () | 132 | game references from 0x00197250 (float constants 1.0f/256.0f) to 0x006997B0; asset region: fingerprint windows 0x001A0000-0x00690000 class data, 0-71% zero words; zero pad 0x006997C0-0x006997FF |
| 17 | rodata_00 | rodata | 0x00699800 | 0x0069F800 | 0x6000 | 0 () | 305 | 'std::exception' at 0x00699800 (MW runtime type names, referenced 0x00699818-0x00699A78 by mw_runtime); SDK strings 0x00699A88-0x0069A4F0 (sceGs*, libdma, libkernl, TTY, libpad, Libcdvd, libmc); libm/libc tables 0x0069A530-0x0069B148; game strings 0x0069B250-0x0069BED8 (module paths, '/BASLUS-20182SPANIC'); code-address tables (jump tables into 0x0015ECD4.., 0x0017BD74..) at 0x0069C100; type_info/vtable records at 0x0069C180 (pointer to 0x00699810 + func_00100670); pointer-dense (40-62%) to 0x0069F800, last non-zero before the file end |
| 18 | main_bss | bss | 0x0069F800 | 0x006B3900 | 0x14100 | 0 () | — | LOAD segment memsz 0x005B3900 - filesz 0x0059F800 = 0x00014100 (config/target.json program_headers[0]); crt0 zeroes from 0x0069F800; $gp 0x006A77F0 inside it |


(first 25 lines; every row is in `segment-table.md`)

## Proposed next step

S6 match-batch — 1351 game function(s) still asm/wip; batch size 12

## Friction filed

3 entries (minor 2, papercut 1); stages attested: E, R, S, V, X; export: FRICTION-REPORT.md
- F-1 [minor/doctrine-gap] MW-runtime/SDK boundary is 8-mod-16; moved one function
- F-2 [minor/tool-gap] stale asm/ files from the previous split survive a resplit
- F-3 [papercut/environment] device bridge dropped once mid-EXECUTE
