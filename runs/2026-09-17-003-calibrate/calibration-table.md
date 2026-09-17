# Calibration table — every (compiler, flags) x function cell, every score (2026-09-17T03:28:12Z)

Cell = objdiff match % (B = .text bytes identical to the target; err = compile error). Judgment is a separate paragraph in the run report, never a filter on this table.

| compiler | flags | func_00103628 | func_001185E8 | func_00120340 | func_00131740 | func_00145A10 | func_00157650 | func_00164E80 | func_00172A40 | byte-identical | score 100 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| mwcps2-2.3.3-000906 | `-O3,p` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O3,p -enum min` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O3,p -fp single -sdatathreshold 0` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O3,p -inline auto` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O3,p -inline auto -sdatathreshold 0` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O3,p -sdatathreshold 0` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O3,p -str readonly -inline deferred` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O4,p` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O4,p -fp single` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O4,p -inline auto` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O4,p -sdatathreshold 0` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-sdatathreshold 0 -O3,p` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O3,p` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O3,p -enum min` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O3,p -fp single -sdatathreshold 0` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O3,p -inline auto` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O3,p -inline auto -sdatathreshold 0` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O3,p -sdatathreshold 0` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O3,p -str readonly -inline deferred` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O4,p` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O4,p -fp single` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O4,p -inline auto` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O4,p -sdatathreshold 0` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-sdatathreshold 0 -O3,p` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O3,s` | 27.5 | 9.9 | 83.5 | 46.3 | 100.0 B | 78.3 | 55.9 | 62.7 | 1/8 | 1/8 |
| mwcps2-2.3.3-000906 | `-O4,s` | 27.5 | 9.9 | 83.5 | 46.3 | 100.0 B | 78.3 | 55.9 | 62.7 | 1/8 | 1/8 |
| mwcps2-2.4-001213 | `-O3,s` | 27.5 | 10.5 | 71.0 | 46.3 | 100.0 B | 78.3 | 55.9 | 62.7 | 1/8 | 1/8 |
| mwcps2-2.4-001213 | `-O4,s` | 27.5 | 10.5 | 71.0 | 46.3 | 100.0 B | 78.3 | 55.9 | 62.7 | 1/8 | 1/8 |
| mwcps2-3.0-011126 | `-O3,p` | 53.7 | 13.3 | 68.1 | 78.3 | 65.2 | 86.2 | 73.0 | 8.0 | 0/8 | 0/8 |
| mwcps2-3.0-011126 | `-O4,p` | 53.7 | 13.3 | 68.1 | 78.3 | 65.2 | 86.2 | 73.0 | 8.0 | 0/8 | 0/8 |
| mwcps2-2.3.3-000906 | `-O2,p` | 50.6 | 11.7 | 54.9 | 76.0 | 71.6 | 62.2 | 45.9 | 0.0 | 0/8 | 0/8 |
| mwcps2-2.3.3-000906 | `-O2,p -sdatathreshold 0` | 50.6 | 11.7 | 54.9 | 76.0 | 71.6 | 62.2 | 45.9 | 0.0 | 0/8 | 0/8 |
| mwcps2-2.3.3-000906 | `-O1,p` | 50.6 | 11.7 | 54.9 | 67.2 | 71.6 | 62.2 | 51.1 | 0.0 | 0/8 | 0/8 |
| mwcps2-2.4-001213 | `-O2,p` | 58.3 | 11.7 | 43.1 | 76.0 | 71.6 | 62.2 | 45.9 | 0.0 | 0/8 | 0/8 |
| mwcps2-2.4-001213 | `-O2,p -sdatathreshold 0` | 58.3 | 11.7 | 43.1 | 76.0 | 71.6 | 62.2 | 45.9 | 0.0 | 0/8 | 0/8 |
| mwcps2-2.4-001213 | `-O1,p` | 58.3 | 11.7 | 43.1 | 67.2 | 71.6 | 62.2 | 51.1 | 0.0 | 0/8 | 0/8 |
| mwcps2-3.0-011126 | `-O2,p` | 58.3 | 11.7 | 38.7 | 73.7 | 71.6 | 57.6 | 38.0 | 7.7 | 0/8 | 0/8 |
| mwcps2-3.0-011126 | `-O1,p` | 58.3 | 11.7 | 38.7 | 64.7 | 71.6 | 57.6 | 45.9 | 1.0 | 0/8 | 0/8 |
| mwcps2-3.0-011126 | `-O3,s` | 27.5 | 13.3 | 65.2 | 44.0 | 65.2 | 65.3 | 43.6 | 8.0 | 0/8 | 0/8 |
| mwcps2-3.0-011126 | `-O4,s` | 27.5 | 13.3 | 65.2 | 44.0 | 65.2 | 65.3 | 43.6 | 8.0 | 0/8 | 0/8 |
| mwcps2-2.4-001213 | `-O0,p` | 0.0 | 0.0 | 0.0 | 43.5 | 5.7 | 0.0 | 10.5 | 0.0 | 0/8 | 0/8 |
| mwcps2-2.4-001213 | `-O0,p -char unsigned -str readonly` | 0.0 | 0.0 | 0.0 | 43.5 | 5.7 | 0.0 | 10.5 | 0.0 | 0/8 | 0/8 |
| mwcps2-2.3.3-000906 | `-O0,p` | 0.0 | 0.0 | 0.0 | 43.5 | 5.6 | 0.0 | 10.5 | 0.0 | 0/8 | 0/8 |
| mwcps2-2.3.3-000906 | `-O0,p -char unsigned -str readonly` | 0.0 | 0.0 | 0.0 | 43.5 | 5.6 | 0.0 | 10.5 | 0.0 | 0/8 | 0/8 |
| mwcps2-3.0-011126 | `-O0,p` | 0.0 | 0.0 | 0.0 | 41.2 | 5.7 | 0.0 | 5.0 | 0.0 | 0/8 | 0/8 |
| mwcps2-2.3.3-000906 | `-O0,p -sdatathreshold 128 -str readonly -fl divbyzerocheck` | err | err | err | err | err | err | err | err | 0/8 | 0/8 |
| mwcps2-2.3.3-000906 | `-O2,p -sdatathreshold 0 -str readonly -enum min` | err | err | err | err | err | err | err | err | 0/8 | 0/8 |
| mwcps2-2.3.3-000906 | `-O4,p -inline auto,deferred -enum min -strings readonly,reuse` | err | err | err | err | err | err | err | err | 0/8 | 0/8 |
| mwcps2-2.3.3-000906 | `-O4,p -inline auto,deferred,bottomup -sdatathreshold 0` | err | err | err | err | err | err | err | err | 0/8 | 0/8 |
| mwcps2-2.3.3-000906 | `-sdatathreshold 8 -O4,p min -fl divbyzerocheck` | err | err | err | err | err | err | err | err | 0/8 | 0/8 |
| mwcps2-2.4-001213 | `-O0,p -sdatathreshold 128 -str readonly -fl divbyzerocheck` | err | err | err | err | err | err | err | err | 0/8 | 0/8 |
| mwcps2-2.4-001213 | `-O2,p -sdatathreshold 0 -str readonly -enum min` | err | err | err | err | err | err | err | err | 0/8 | 0/8 |
| mwcps2-2.4-001213 | `-O4,p -inline auto,deferred -enum min -strings readonly,reuse` | err | err | err | err | err | err | err | err | 0/8 | 0/8 |
| mwcps2-2.4-001213 | `-O4,p -inline auto,deferred,bottomup -sdatathreshold 0` | err | err | err | err | err | err | err | err | 0/8 | 0/8 |
| mwcps2-2.4-001213 | `-sdatathreshold 8 -O4,p min -fl divbyzerocheck` | err | err | err | err | err | err | err | err | 0/8 | 0/8 |
