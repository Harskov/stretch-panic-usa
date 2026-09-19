#include "types.h"

/* A vtable accessor: six function-pointer tables (D_0069CE00, D_0069D0E0, D_0069D1B0,
   D_0069D2B0, D_0069D320, D_0069D4B0) hold its address, and it returns the address of
   whatever sits at +0xA0 in the object it is called on. No matched function reaches
   that member, so only its existence is asserted here. */
typedef struct ObjA0 {
    unsigned char unk_00[0xA0];
    u8 unk_A0;
} ObjA0;

void *func_0016D240(ObjA0 *o) {
    return &o->unk_A0;
}
