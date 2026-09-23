#include "common.h"
#include "game_01/node90.h"

void func_0014EA70(s32 arg0, u128 *arg1) {
    ListNode *p;
    p = D_006AF4C8;
    while (p != 0) {
        p->unk_A0 = *arg1;
        p->unk_98 = 1;
        p = p->next;
    }
}
