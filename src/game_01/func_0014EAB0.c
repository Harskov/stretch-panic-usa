#include "common.h"
#include "game_01/node90.h"

void func_0014EAB0(ListNode *arg0, u128 *arg1) {
    ListNode *p = D_006AF4C8;
    while (p != 0) {
        *arg1 = p->unk_310;
        p = p->next;
        arg1++;
    }
}
