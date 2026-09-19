# Exemplars for func_00152630 — the 3 matched functions nearest by address

## func_00156E20 @ 0x00156E20 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_00156E20(void) {
}

```

## func_00156E30 @ 0x00156E30 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_00156E30(void) {
}

```

## func_00157650 @ 0x00157650 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
#include "game_01/pool70.h"

int func_00157650(Pool70 *p) {
    int i;

    for (i = 0; i < 8; i++) {
        if (p->slots[i].active == 0) {
            return i;
        }
    }
    return -1;
}

```
