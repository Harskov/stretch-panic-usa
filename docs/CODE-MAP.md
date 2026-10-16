# Code map — Stretch Panic

Generated at the map step from ledger/segments.json, the ledger and ledger/units.json; the consolidate and docs steps extend it.

| Segment | Kind | Range | Functions | Units |
|---|---|---|---|---|
| crt0 | game | 0x00100000-0x001000F0 | 4 | 3 |
| mw_runtime | libc | 0x001000F0-0x001024C0 | 39 | 0 |
| sdk_libgraph | sdk | 0x001024C0-0x00103628 | 14 | 0 |
| sdk_libdma | sdk | 0x00103628-0x00104150 | 19 | 0 |
| sdk_libkernel | sdk | 0x00104150-0x0010CCA0 | 339 | 0 |
| sdk_libpad | sdk | 0x0010CCA0-0x0010E070 | 31 | 0 |
| sdk_libcdvd | sdk | 0x0010E070-0x00110FC0 | 51 | 0 |
| sdk_libmc | sdk | 0x00110FC0-0x00112660 | 26 | 0 |
| sdk_libm | sdk | 0x00112660-0x00115900 | 30 | 0 |
| sdk_libc | libc | 0x00115900-0x0011F5E0 | 123 | 0 |
| game_00 | game | 0x0011F5E0-0x00145A90 | 572 | 31 |
| game_memcard | game | 0x00145A90-0x00147F60 | 76 | 4 |
| game_01 | game | 0x00147F60-0x0017EF00 | 738 | 49 |
| data_vu | data | 0x0017EF00-0x00196080 | 0 | 0 |
| data_sdk | data | 0x00196080-0x00197250 | 0 | 0 |
| data_game | data | 0x00197250-0x00699800 | 0 | 0 |
| rodata_00 | rodata | 0x00699800-0x0069F800 | 0 | 0 |
| main_bss | bss | 0x0069F800-0x006B3900 | 0 | 0 |

The Functions column counts ledger records: in the game segments it includes the one-`nop` alignment pads before unit starts, which the ledger records as `skipped-data`, not as functions.
