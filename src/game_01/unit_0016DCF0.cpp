#include "common.h"
#include "types.h"

class Sub_0016DCF0 {
public:
    virtual void m0();
    virtual void m1(u8 *p);
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(int a, f32 b);
};

struct Obj_0016DCF0 {
    u8 unk_00[0xD4];
    Sub_0016DCF0 *unk_D4;
    u8 unk_D8[0x9C];
    u8 *unk_174;
    s32 unk_178;
    s32 unk_17C;
    f32 unk_180;
};

extern "C" void func_0016DCF0(Obj_0016DCF0 *o);

class Sub_0016DD60 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2(u8 *p);
    virtual void m3();
    virtual void m4();
    virtual void m5(s32 a, f32 b);
};

typedef struct Obj184 {
    u8 unk_00[0xD4];
    Sub_0016DD60 *unk_D4;
    u8 unk_D8[0x9C];
    u8 *unk_174;
    s32 unk_178;
    s32 unk_17C;
    f32 unk_180;
} Obj184;

extern "C" void func_0016DD60(Obj184 *o);

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
    virtual Quad *m11(Quad *);
};

typedef struct Obj2E0 {
    u8 unk_00[0x10];
    Quad unk_10;
    u8 unk_20[0x10];
    Quad unk_30;
    u8 unk_40[0x290];
    Quad unk_2D0;
} Obj2E0;

extern Obj_006A6B80 *D_006A6B80;

extern "C" void func_0012E9A0(Vec *a, Vec *b, Vec *out, f32 t);

extern "C" void func_0016DDD0(Obj2E0 *o, f32 t);

void func_0016DCF0(Obj_0016DCF0 *o)
{
    s32 idx = o->unk_178;
    if (idx != o->unk_17C) {
        o->unk_17C = idx;
        o->unk_D4->m1(o->unk_174 + o->unk_178 * 8);
    }
    o->unk_D4->m5(0, o->unk_180);
}

void func_0016DD60(Obj184 *o) {
    if (o->unk_178 != o->unk_17C) {
        o->unk_17C = o->unk_178;
        o->unk_D4->m2(o->unk_174 + o->unk_178 * 8);
    }
    o->unk_D4->m5(0, o->unk_180);
}

void func_0016DDD0(Obj2E0 *o, f32 t) {
    o->unk_2D0 = *D_006A6B80->m11(&o->unk_10);
    func_0012E9A0(&o->unk_30.vec0, &o->unk_2D0.vec0, &o->unk_30.vec0, t);
}
