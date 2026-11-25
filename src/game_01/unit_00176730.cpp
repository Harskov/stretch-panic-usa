#include "common.h"
#include "types.h"

typedef union Obj_00176730 {
    /* 0x00 */ u128 unk_0;
    /* 0x00 */ Vec vec0;
    /* 0x00 */ s32 i0[4];
} Obj_00176730;

class Sub_00176730 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
};

typedef struct Ent {
    void *unk_0;          /* 0x00 */
    u8 pad04[0x4C];      /* 0x04 */
    Sub_00176730 *unk_50; /* 0x50 */
    s32 unk_54;           /* 0x54 */
    f32 unk_58;           /* 0x58 */
    f32 unk_5C;           /* 0x5C */
    Obj_00176730 unk_60;         /* 0x60 */
    u8 pad70[0x40];      /* 0x70 */
    Quad unk_B0;          /* 0xB0 */
    f32 unk_C0;           /* 0xC0 */
    f32 unk_C4;           /* 0xC4 */
} Ent;

extern "C" void func_00121B10(s32, f32);

extern "C" s32 func_00176730(Ent *e);

// steps the float at 0x5C by the one at 0x60 after the two calls; 1 while the sum stays above zero
s32 func_00176730(Ent *e) {
    s32 ret;

    e->unk_50->m2();
    func_00121B10(e->unk_54, e->unk_58);
    ret = 1;
    e->unk_5C += e->unk_60.vec0.x;
    if (e->unk_5C <= 0.0f) {
        ret = 0;
    }
    return ret;
}
