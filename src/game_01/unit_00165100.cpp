#include "common.h"

typedef struct Obj_00165090 {
    /* 0x00 */ s32 *unk_0;
    unsigned char unk_04[0xC];
    /* 0x10 */ Vec unk_10;
    unsigned char unk_20[0x30];
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ f32 unk_54;
    unsigned char unk_58[0x28];
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ void *unk_84;
} Obj_00165090;

typedef struct Obj32 {
    /* 0x00 */ Vec unk_0;
    /* 0x10 */ Vec unk_10;
} Obj32;

class Obj_006A6B80 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual Vec *m11(Vec *v);
};

extern "C" {
extern Obj_006A6B80 *D_006A6B80;
void func_0012E9A0(Vec *out, Vec *a, Vec *b, f32 s);
void func_0012E9E0(Vec *out, Vec *a, Vec *b, f32 s);
s32 func_00165100(Obj_00165090 *self);
}

/* Steps every element's second vector through the two helpers and adds it into the
   first (xyz only), then counts the object's counter down; nonzero while it stays positive. */
s32 func_00165100(Obj_00165090 *self)
{
    s32 i;
    register Obj32 *e;

    e = (Obj32 *)self->unk_84;
    for (i = 0; i < self->unk_80; i++) {
        Vec *v = D_006A6B80->m11(&self->unk_10);

        func_0012E9A0(&e->unk_10, v, &e->unk_10, self->unk_54);
        func_0012E9E0(&e->unk_10, &e->unk_10, &e->unk_10, 0.03125f);
        {
            register Vec *src = &e->unk_10;

            asm {
                lqc2 vf1, 0(e)
                lqc2 vf2, 0(src)
                vadd.xyz vf1, vf1, vf2
                sqc2 vf1, 0(e)
            }
        }
        e++;
    }
    self->unk_50--;
    return self->unk_50 > 0;
}
