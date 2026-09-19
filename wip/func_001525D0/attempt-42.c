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

void func_001525D0(char *arg0, char *arg1) {
    *(u8 *)(arg0 + 0x314) = 1;
    *(unsigned __int128 *)(arg0 + 0x3A0) = *(unsigned __int128 *)(arg1 + 0x80);
    *(unsigned __int128 *)(arg0 + 0x3B0) = *(unsigned __int128 *)(arg1 + 0x90);
    *(unsigned __int128 *)(arg0 + 0x3C0) = *(unsigned __int128 *)(arg1 + 0xA0);
}
