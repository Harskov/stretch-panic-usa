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

typedef struct Obj {
    void **vtable;
    f32 unk4;
    f32 unk8;
} Obj;

s32 func_00172C00(Obj *arg0, s32 arg1, f32 fparg0) {
    s32 s0 = 0;
    if (!((fparg0 + arg0->unk4) < arg0->unk8)) {
        if (arg1 != 0) {
            s0 = 1;
            ((void (*)(Obj *, s32))arg0->vtable[7])(arg0, 0);
        }
    }
    return s0;
}
