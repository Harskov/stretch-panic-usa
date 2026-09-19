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

typedef struct Obj {
    unsigned char pad0[0x314];
    u8 unk314;
    unsigned char pad1[0x8B];
    u128 v0;
    u128 v1;
    u128 v2;
} Obj;

typedef struct Src {
    unsigned char pad0[0x80];
    u128 v0;
    u128 v1;
    u128 v2;
} Src;

void func_001525D0(Obj *arg0, Src *arg1) {
    u128 a;
    u128 b;
    u128 c;

    a = arg1->v0;
    b = arg1->v1;
    c = arg1->v2;
    arg0->v0 = a;
    arg0->v1 = b;
    arg0->v2 = c;
    arg0->unk314 = 1;
}
