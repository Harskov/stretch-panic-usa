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
    u8 pad0[0x94];
    s32 x94;
    u8 pad98[0x28];
    s32 xC0;
    u8 padC4[0x4];
    s32 xC8;
} Obj;

s32 func_00176BB0(Obj *arg0) {
    s32 v1;
    s32 v0;

    v1 = arg0->xC0;
    if (v1 == 0) {
        v0 = arg0->xC8;
        if (v0 == arg0->x94) {
            return 1;
        }
        arg0->xC8 = v0 + 1;
        return 1;
    }
    v0 = arg0->xC8;
    if (v0 != 0) {
        arg0->xC8 = v0 - 1;
        return 1;
    }
    if (v1 == -1) {
        return 0;
    }
    return 1;
}
