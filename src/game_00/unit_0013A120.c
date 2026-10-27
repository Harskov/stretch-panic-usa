#include "common.h"

extern s32 D_006A6D00;

extern void *__nw__FUi(u32 size);

void func_00135C70();

extern s32 D_0069C5D0;

void func_001355E0();

void __dl__FPv(void *);

extern s32 D_0069C5B0;

void func_00135570();

typedef struct Obj_0013AC50 {
    s32 *unk_0;
    u8 unk_4[0x20];
    s32 unk_24;
} Obj_0013AC50;

typedef struct Obj_0013A880 {
    s32 *unk_0;
    u8 unk_4[0x2C];
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
} Obj_0013A880;

void func_00136CA0(void *, s32, s32, f32, f32);

typedef struct Elem_0013AC90 {
    /* 0x00 */ struct Sub_0013AFE0 {
        /* 0x00 */ f32 unk_0;
        /* 0x04 */ f32 unk_4;
        /* 0x08 */ f32 unk_8;
        /* 0x0C */ f32 unk_C;
        /* 0x10 */ f32 unk_10;
        /* 0x14 */ f32 unk_14;
        /* 0x18 */ f32 unk_18;
        /* 0x1C */ f32 unk_1C;
        /* 0x20 */ f32 unk_20;
        /* 0x24 */ f32 unk_24;
    } unk_0;
    /* 0x28 */ struct Elem_0013AC90 *next;
} Elem_0013AC90;

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013A120);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013A2E0);

Obj_0013A880 *func_0013A880(Obj_0013A880 *self)
{
    func_00135570(self);
    self->unk_0 = &D_0069C5D0;
    self->unk_30 = 1.0f;
    self->unk_34 = 1.0f;
    self->unk_38 = 1.0f;
    self->unk_3C = 0.5f;
    self->unk_40 = 0.0f;
    self->unk_44 = 60.0f;
    self->unk_48 = 0.0f;
    self->unk_4C = 1.0f;
    return self;
}

s32 **func_0013A8E0(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069C5D0;
        func_001355E0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013A940);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013AA50);

Obj_0013AC50 *func_0013AC50(Obj_0013AC50 *self)
{
    func_00135570(self);
    self->unk_0 = &D_0069C5B0;
    self->unk_24 = 0;
    return self;
}

// the destructor of the type func_0013AC50 constructs: frees the chain held at +0x24,
// runs the base teardown, then frees the object itself when the flag asks for it
Obj_0013AC50 *func_0013AC90(Obj_0013AC50 *self, s16 flags)
{
    Elem_0013AC90 *node;
    Elem_0013AC90 *next;

    if (self != 0) {
        self->unk_0 = &D_0069C5B0;
        node = (Elem_0013AC90 *)self->unk_24;
        self->unk_24 = 0;
        while (node != 0) {
            next = node->next;
            __dl__FPv(node);
            node = next;
        }
        func_001355E0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

s32 func_0013AD30(void)
{
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013AD40);

/* Pushes a new 0x2C-byte node on the list headed at +0x24: the node takes a copy of
   the ten floats at src and links to the previous head. The unit declares the head
   as an s32, hence the casts. */
void func_0013AFE0(Obj_0013AC50 *self, struct Sub_0013AFE0 *src)
{
    s32 prev;

    prev = self->unk_24;
    self->unk_24 = (s32)__nw__FUi(0x2C);
    ((Elem_0013AC90 *)self->unk_24)->unk_0 = *src;
    ((Elem_0013AC90 *)self->unk_24)->next = (Elem_0013AC90 *)prev;
}

void *func_0013B080(void)
{
    void *obj;

    if ((obj = __nw__FUi(0x50)) != 0) {
        func_00135C70(obj, D_006A6D00 + 0x100, D_006A6D00 + 0x10C);
    }
    return obj;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013B0D0);

void *func_0013B100(void)
{
    void *obj;

    if ((obj = __nw__FUi(0x78)) != 0) {
        func_00136CA0(obj, D_006A6D00 + 0x100, D_006A6D00 + 0x11C, -240.0f, -144.0f);
    }
    return obj;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013B160);

void *func_0013B190(void)
{
    void *obj;

    if ((obj = __nw__FUi(0x78)) != 0) {
        func_00136CA0(obj, D_006A6D00 + 0x100, D_006A6D00 + 0x11C, 240.0f, 144.0f);
    }
    return obj;
}
