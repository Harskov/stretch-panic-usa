typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct Obj {
    unsigned char unk_00[0xF4];
    s32 state;
    f32 unk_F8;
    f32 unk_FC;
} Obj;

void func_001668D0(Obj *o) {
    switch (o->state) {
    case 0:
        o->unk_FC = 0.0f;
        o->unk_F8 = 0.0f;
        o->state = o->state + 1;
        /* fallthrough */
    case 1:
        o->unk_FC = o->unk_FC + 0.041666668f * (2.0f - o->unk_FC);
        if (o->unk_FC < 1.75f) {
            return;
        }
        o->state = o->state + 1;
        return;
    case 2:
        o->unk_FC = o->unk_FC + 0.03125f * (1.0f - o->unk_FC);
        return;
    }
}
