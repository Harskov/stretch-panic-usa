#include "common.h"
#include "game_01/objC0.h"

extern void func_00168470(void);

/* The first parameter is not read. */
s32 func_001683A0(void *arg0, ObjC0 *o)
{
    switch (o->unk_C0) {
    case 6:
        func_00168470();
        break;
    }
    return 0;
}
