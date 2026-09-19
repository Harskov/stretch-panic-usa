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

void func_00152380(char *a0, char *a1) {
    *(u8 *)(a0 + 0x414) = 0;
    *(f32 *)(a1 + 0x50) = *(f32 *)(a0 + 0x470);
    *(f32 *)(a1 + 0x54) = *(f32 *)(a0 + 0x474);
    *(f32 *)(a1 + 0x58) = *(f32 *)(a0 + 0x478);
    *(f32 *)(a1 + 0x5C) = *(f32 *)(a0 + 0x47C);
    *(s32 *)(a1 + 0x60) = *(s32 *)(a0 + 0x480);
    *(u128 *)(a1 + 0x30) = *(u128 *)(a0 + 0x140);
    *(u128 *)(a1 + 0x00) = *(u128 *)(a0 + 0x250);
    *(u128 *)(a1 + 0x10) = *(u128 *)(a0 + 0x260);
    *(u128 *)(a1 + 0x20) = *(u128 *)(a0 + 0x270);
    *(f32 *)(a1 + 0x20) = -*(f32 *)(a1 + 0x20);
    *(f32 *)(a1 + 0x24) = -*(f32 *)(a1 + 0x24);
    *(f32 *)(a1 + 0x28) = -*(f32 *)(a1 + 0x28);
}
