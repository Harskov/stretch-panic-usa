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
    u8 *sa = (u8 *)arg0;
    u8 *sb = (u8 *)arg1;
    u128 v0;
    u128 v1;
    u128 v2;
    sa[0x314] = 1;
    v0 = *(u128 *)(sb + 0x80);
    v1 = *(u128 *)(sb + 0x90);
    v2 = *(u128 *)(sb + 0xA0);
    *(u128 *)(sa + 0x3A0) = v0;
    *(u128 *)(sa + 0x3B0) = v1;
    *(u128 *)(sa + 0x3C0) = v2;
}
