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

extern s32 D_006A6D18;
void func_0013BFB0();

typedef struct {
    u8 pad[0x60];
    u8 *unk60;
} Obj;

void func_00172CC0(Obj *arg0, s32 arg1, f32 fparg0) {
    u8 *p = arg0->unk60 + (arg1 << 5);
    *(s32 *)(p + 0x10) = 0x459D1463;
    *(s32 *)(p + 0x14) = 0x40A00000;
    *(f32 *)(p + 0x18) = fparg0;
    func_0013BFB0(D_006A6D18);
}
