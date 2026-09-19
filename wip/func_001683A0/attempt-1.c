#include "common.h"

typedef struct Obj {
    u8 unk_00[0xC0];
    s32 unk_C0;
} Obj;

extern void func_00168470(void);

/* The first parameter is not read. */
s32 func_001683A0(void *arg0, Obj *o)
{
    if (o->unk_C0 == 6) {
        func_00168470();
    }
    return 0;
}
