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

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec;

typedef struct Src {
    u8 pad414[0x414];
    u8 flag;
    u8 pad415[0x470 - 0x415];
    Vec rot;
    u8 pad480[0x480 - 0x480];
    s32 unk480;
} Src;

typedef struct Dst {
    u8 pad0[0x50];
    Vec rot;
    u8 pad60[0x60 - 0x60];
    s32 unk60;
} Dst;

void func_00152380(Src *arg0, Dst *arg1) {
    arg0->flag = 0;
    arg1->rot.x = arg0->rot.x;
    arg1->rot.y = arg0->rot.y;
    arg1->rot.z = arg0->rot.z;
    arg1->rot.w = arg0->rot.w;
    arg1->unk60 = arg0->unk480;
    *(Vec *)((char *)arg1 + 0x30) = *(Vec *)((char *)arg0 + 0x140);
    *(u128 *)((char *)arg1 + 0x0) = *(u128 *)((char *)arg0 + 0x250);
    *(u128 *)((char *)arg1 + 0x10) = *(u128 *)((char *)arg0 + 0x260);
    *(u128 *)((char *)arg1 + 0x20) = *(u128 *)((char *)arg0 + 0x270);
    *(f32 *)((char *)arg1 + 0x20) = -*(f32 *)((char *)arg1 + 0x20);
    *(f32 *)((char *)arg1 + 0x24) = -*(f32 *)((char *)arg1 + 0x24);
    *(f32 *)((char *)arg1 + 0x28) = -*(f32 *)((char *)arg1 + 0x28);
}
