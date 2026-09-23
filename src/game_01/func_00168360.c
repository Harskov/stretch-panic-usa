#include "common.h"
#include "game_01/objC0.h"

extern void func_001683F0(void *arg0, ObjC0 *arg1);

void func_00168360(void *arg0, ObjC0 *arg1)
{
    switch (arg1->unk_C0) {
    case 2:
        func_001683F0(arg0, arg1);
        break;
    }
}
