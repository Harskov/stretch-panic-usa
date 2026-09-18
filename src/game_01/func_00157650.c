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
