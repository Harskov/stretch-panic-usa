typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;

typedef struct Obj {
    u8 pad_00[0x70];
    s64 unk70;
    u8 pad_78[0x18];
    u8 unk90;
} Obj;

void func_001278A0(Obj *arg0, s32 arg1, s32 arg2, f32 fparg0) {
    arg0->unk90 = 1;
    arg0->unk70 = (s64)((arg2 << 0xC) | ((arg1 * 2) | ((s32)(128.0f * fparg0) * 0x10))) | (arg0->unk70 & ~0x3FFE);
}
