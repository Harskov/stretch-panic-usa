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
    u8 pad_00[0xF0];
    s64 unkF0;
    u8 pad_F8[0x18];
    u8 unk110;
} Obj;

void func_00125C90(Obj *arg0, s32 arg1, s32 arg2, f32 fparg0) {
    arg0->unk110 = 1;
    arg0->unkF0 = (s64)((arg2 << 0xC) | ((arg1 * 2) | ((s32)(128.0f * fparg0) * 0x10))) | (arg0->unkF0 & ~0x3FFE);
}
