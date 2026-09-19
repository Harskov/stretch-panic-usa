# Exemplars for func_0016DC40 — the 3 matched functions nearest by address

## func_0016DC30 @ 0x0016DC30 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef struct {
    unsigned char pad[0x134];
    int field134;
} Obj;

void func_0016DC40(Obj *arg0, int arg1);

void func_0016DC30(Obj *arg0) {
    func_0016DC40(arg0, arg0->field134);
}

```

## func_0016DC80 @ 0x0016DC80 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
#include "game_01/obj168.h"

s32 func_0016DC80(Obj168 *arg0) {
    s32 v = arg0->unk_168;
    if (v != 0) {
        arg0->unk_168 = v - 1;
        if (arg0->unk_168 == 0) {
            arg0->flags &= 0xFBFFFFFF;
            arg0->unk_164 = 0;
        }
        return 1;
    }
    return 0;
}

```

## func_0016DCD0 @ 0x0016DCD0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
#include "game_01/obj168.h"

void func_0016DCD0(Obj168 *arg0, Obj168 *arg1) {
    arg0->unk_164 = arg1->unk_164;
    arg0->unk_168 = arg1->unk_168;
}

```
