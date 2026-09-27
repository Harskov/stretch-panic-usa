#include "common.h"

extern void func_00100630(void *p);

void *func_0015D600(void *p, s16 flags)
{
    if (p != 0) {
        if (flags > 0) {
            func_00100630(p);
        }
    }
    return p;
}
