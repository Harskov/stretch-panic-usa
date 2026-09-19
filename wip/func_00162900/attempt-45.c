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
    u128 unk_80;
    u128 unk_90;
    u128 unk_A0;
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
    u128 a;
    u128 b;
    u128 c;

    arg0->unk_28C = 1;
    a = arg1->unk_80;
    b = arg1->unk_90;
    c = arg1->unk_A0;
    arg0->unk_310 = a;
    arg0->unk_320 = b;
    arg0->unk_330 = c;
    arg0->unk_28C = arg0->unk_28C + 0;
}
