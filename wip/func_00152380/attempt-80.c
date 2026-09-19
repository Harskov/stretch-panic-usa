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

void func_00152380(char *arg0, char *arg1) {
    f32 f02;
    f32 f03;
    f32 f01;
    f32 f00;

    *(u8 *)(arg0 + 0x414) = 0;
    f03 = *(f32 *)(arg0 + 0x470);
    f02 = *(f32 *)(arg0 + 0x474);
    f01 = *(f32 *)(arg0 + 0x478);
    f00 = *(f32 *)(arg0 + 0x47C);
    *(f32 *)(arg1 + 0x50) = f03;
    *(f32 *)(arg1 + 0x54) = f02;
    *(f32 *)(arg1 + 0x58) = f01;
    *(f32 *)(arg1 + 0x5C) = f00;
    *(s32 *)(arg1 + 0x60) = *(s32 *)(arg0 + 0x480);
    *(u128 *)(arg1 + 0x30) = *(u128 *)(arg0 + 0x140);
    *(u128 *)(arg1 + 0x00) = *(u128 *)(arg0 + 0x250);
    *(u128 *)(arg1 + 0x10) = *(u128 *)(arg0 + 0x260);
    *(u128 *)(arg1 + 0x20) = *(u128 *)(arg0 + 0x270);
    *(f32 *)(arg1 + 0x20) = -*(f32 *)(arg1 + 0x20);
    *(f32 *)(arg1 + 0x24) = -*(f32 *)(arg1 + 0x24);
    *(f32 *)(arg1 + 0x28) = -*(f32 *)(arg1 + 0x28);
}
