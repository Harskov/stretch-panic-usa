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

void func_0015D550(u8 *arg0) {
    u128 *p;
    u128 *q;
    u128 *r;
    u128 *s;
    u128 v;

    p = (u128 *)0x70000BE0;
    q = (u128 *)0x70000B80;
    r = (u128 *)0x70000BA0;
    s = (u128 *)0x70000BC0;

    v = *p;
    *(u128 *)(arg0 + 0x0) = v;
    v = *p;
    *(u128 *)(arg0 + 0x10) = v;
    v = *q;
    *(u128 *)(arg0 + 0x20) = v;
    v = *r;
    *(u128 *)(arg0 + 0x30) = v;
    v = *s;
    *(u128 *)(arg0 + 0x40) = v;
    *(u32 *)(arg0 + 0x50) = 0;
    *(u32 *)(arg0 + 0x54) = 0xBF800000;
    *(u32 *)(arg0 + 0x58) = 0x3F800000;
    *(u32 *)(arg0 + 0x5C) = 0x3F000000;
    *(u32 *)(arg0 + 0x60) = 0x3E800000;
    *(u32 *)(arg0 + 0x64) = 0;
    *(u32 *)(arg0 + 0x68) = 0x3E800000;
    *(u32 *)(arg0 + 0x6C) = 0x3F400000;
    v = *p;
    *(u128 *)(arg0 + 0x70) = v;
    v = *p;
    *(u128 *)(arg0 + 0x80) = v;
    *(u32 *)(arg0 + 0x90) = 0;
    v = *r;
    *(u128 *)(arg0 + 0xA0) = v;
    v = *p;
    *(u128 *)(arg0 + 0xB0) = v;
    v = *p;
    *(u128 *)(arg0 + 0xC0) = v;
}
