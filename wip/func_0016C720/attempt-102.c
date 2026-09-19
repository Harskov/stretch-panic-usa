#include "common.h"

typedef struct Node Node;
typedef void (*Method)(Node *, void *);

typedef struct Vtbl {
    u8 unk_00[0x18];
    Method unk_18;
} Vtbl;

struct Node {
    Vtbl *vtbl;
    u8 unk_04[0x44];
    Node *next;
};

extern Node *D_006B3880;

s32 func_0016C720(void *arg0, void *arg1)
{
    Node *p;
    Vtbl *v;

    for (p = D_006B3880; p != 0; p = p->next) {
        v = p->vtbl;
        v->unk_18(p, arg1);
    }
    return 0;
}
