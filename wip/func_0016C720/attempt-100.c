#include "common.h"

typedef struct Node Node;

typedef struct Vtbl {
    u8 unk_00[0x18];
    void (*unk_18)(Node *, void *);
} Vtbl;

struct Node {
    Vtbl *vtbl;
    u8 unk_04[0x44];
    Node *next;
};

extern Node *D_006B3880;

/* The first parameter is not read: the second is forwarded to every node's
   virtual +0x18. */
s32 func_0016C720(void *arg0, void *arg1)
{
    Node *p;

    for (p = D_006B3880; p != 0; p = p->next) {
        p->vtbl->unk_18(p, arg1);
    }
    return 0;
}
