typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;

typedef struct Arr {
    u8 pad0[0x530];
    s32 unk_530;
    u8 pad534[0x538 - 0x534];
    u8 unk_538[2];
} Arr;

void func_0014E460(Arr *a) {
    s32 i;
    Arr *p;

    i = 0;
    p = a;
    do {
        p->unk_530 = 0;
        a[i].unk_538[0] = 0;
        i += 1;
        p = (Arr *)((u8 *)p + 4);
    } while (i < 2);
}
