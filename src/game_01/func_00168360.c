#include "common.h"

typedef struct Obj {
    u8 unk_00[0xC0];
    s32 unk_C0;
} Obj;

extern void func_001683F0(void *arg0, Obj *arg1);

void func_00168360(void *arg0, Obj *arg1)
{
    switch (arg1->unk_C0) {
    case 2:
        func_001683F0(arg0, arg1);
        break;
    }
}
