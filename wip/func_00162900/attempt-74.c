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

typedef struct Sub {
    unsigned char unk_00[0x80];
    u128 v80;
    u128 v90;
    u128 vA0;
} Sub;

typedef struct Obj {
    unsigned char unk_00[0x28C];
    u8 unk_28C;
    unsigned char unk_28D[0x310 - 0x28D];
    u128 unk_310;
    u128 unk_320;
    u128 unk_330;
} Obj;

void func_00162900(Obj *arg0, Sub *arg1) {
    arg0->unk_28C = 1;
    arg0->unk_310 = arg1->v80;
    arg0->unk_320 = arg1->v90;
    arg0->unk_330 = arg1->vA0;
}
