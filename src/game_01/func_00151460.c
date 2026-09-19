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

void func_00151460(char *arg0, s32 arg1, f32 fparg0) {
    *(u32 *)(arg0 + 0x60) |= 0x04000000;
    *(s32 *)(arg0 + 0x410) = arg1;
    *(f32 *)(arg0 + 0x414) = fparg0;
    *(u8 *)(arg0 + 0x418) = 0;
    *(s32 *)(arg0 + 0x420) = 0;
    *(s32 *)(arg0 + 0x424) = 0;
    *(s32 *)(arg0 + 0x428) = 0;
    *(f32 *)(arg0 + 0x42C) = 1.0f;
}
