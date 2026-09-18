typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;
typedef unsigned __int128 u128;

typedef struct {
    unsigned char unk_00[0x28];
    f32 f28;
    f32 f2C;
    s32 i30;
} Obj;

int func_00160940(Obj *a0) {
    f32 f1;
    if (a0->i30 != 0) {
        f1 = a0->f2C;
    } else {
        f32 f2 = a0->f28;
        a0->f28 = f2 + 0.083333336f * (0.5f - f2);
        a0->f2C = a0->f2C + -0.0125f;
        f1 = a0->f2C;
    }
    if (f1 > 0.0f) {
        return 1;
    }
    return 0;
}
