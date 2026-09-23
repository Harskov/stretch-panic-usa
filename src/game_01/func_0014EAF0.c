#include "common.h"
#include "game_01/node90.h"

void func_0014EAF0(void) {
    ListNode *p = D_006AF4C8;
    while (p != 0) {
        p->flags |= 4;
        p = p->next;
    }
}
