typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct Obj {
    unsigned char unk_00[0xA8];
    float unk_A8;
    float unk_AC;
    unsigned char unk_B0[0x30];
    float vel_x;
    float vel_y;
    float accel_y;
    int count;
} Obj;

int func_00166D90(Obj *o) {
    int old;

    o->vel_x += o->unk_A8;
    o->vel_y += o->accel_y;
    if (o->vel_y < 0.0f) {
        o->vel_y = 0.0f;
    }
    old = o->count;
    o->count = old + 1;
    return old < o->unk_AC;
}
