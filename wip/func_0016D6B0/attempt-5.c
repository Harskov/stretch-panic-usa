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

typedef struct {
    unsigned char pad[0x134];
    int field134;
    f32 field138;
    int field13C;
    u128 field140;
    u128 field150;
} Obj;

void func_0016D6B0(Obj *arg0) {
    arg0->field134 = 0;
    arg0->field138 = 1.0f;
    arg0->field13C = 0;
    arg0->field140 = *(u128 *)0x70000BE0;
    arg0->field150 = *(u128 *)0x70000BA0;
}
