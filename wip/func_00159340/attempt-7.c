typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;

void func_00159820();

void func_00159340(char *a0, char *a1) {
    u32 v1;

    v1 = *(u32 *)(a1 + 0xC0);
    if (v1 == 0) {
        func_00159820(a0, a1);
    }
}
