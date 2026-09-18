#include "game_01/pool70.h"

void func_001580D0(Pool70 *p, int i) {
    p->slots[i].pos_x += p->slots[i].vel_x;
    p->slots[i].pos_y += p->slots[i].vel_y;
    p->slots[i].pos_z += p->slots[i].vel_z;
    if (p->slots[i].pos_z < 0.0f) {
        p->slots[i].active = 0;
    }
}
