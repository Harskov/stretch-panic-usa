typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;

extern void func_0014E460();

void func_0014E460(char *arg0) {
    s32 i;

    i = 0;
    do {
        *(s32 *)(arg0 + i * 4 + 0x530) = 0;
        *(u8 *)(arg0 + i + 0x538) = 0;
        i += 1;
    } while (i < 2);
}
