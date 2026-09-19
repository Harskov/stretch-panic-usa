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
    u8 pad[8];
    void (*unk8)(void *, int);
} Vtbl;

typedef struct Obj {
    u8 pad[0xB0];
    Vtbl **unk_B0;
} Obj;

typedef void (*Fn)(Vtbl **, int);

void func_00159EE0(Obj *arg0) {
    Vtbl **temp_a0;
    Fn fn;

    temp_a0 = arg0->unk_B0;
    if (temp_a0 != 0) {
        fn = (Fn)(*temp_a0)->unk8;
        fn(temp_a0, 1);
    }
}
