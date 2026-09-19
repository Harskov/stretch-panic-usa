typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;

typedef struct Vtbl {
    unsigned char pad[8];
    void (*fn)(void *, int);
} Vtbl;

typedef struct Obj {
    unsigned char pad[0x114];
    Vtbl **unk114;
} Obj;

void func_0015D4E0(Obj *arg0) {
    register Vtbl **a0 asm("a0") = arg0->unk114;
    register Vtbl *t9;

    if (a0 != 0) {
        t9 = *a0;
        t9 = *(Vtbl **)((unsigned char *)t9 + 8);
        ((void (*)(void *, int))t9)(a0, 1);
    }
}
