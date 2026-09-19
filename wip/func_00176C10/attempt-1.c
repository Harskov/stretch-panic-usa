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
    u8 pad98[0x4];
    u8 *x9C;
    u8 padA0[0x24];
    s32 xC4;
} Obj;

void func_00176C10(Obj *arg0, u128 *arg1, u128 *arg2) {
    arg0->xC4 = (arg0->xC4 - 1) & (arg0->x94 - 1);
    *(u128 *)(arg0->x9C + (arg0->xC4 << 5)) = *arg1;
    *(u128 *)(arg0->x9C + (arg0->xC4 << 5) + 0x10) = *arg2;
}
