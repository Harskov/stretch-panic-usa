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
    Vtbl *unk114;
} Obj;

void func_0015D4E0(Obj *arg0) {
    Vtbl *vt;

    vt = arg0->unk114;
    if (vt != 0) {
        vt = *(Vtbl **)vt;
        vt->fn(arg0->unk114, 1);
    }
}
