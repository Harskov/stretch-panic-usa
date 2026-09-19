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

typedef struct Node Node;
struct Node {
    u8 pad[0x378];
    u32 index;
    u8 pad2[0x500 - 0x37C];
    Node *arr[1];
};

typedef struct Dst {
    u8 pad[0x230];
    u128 v0;
    u128 v1;
    u128 v2;
    u128 v3;
    u128 v4;
    u128 v5;
    u128 v6;
    u128 v7;
} Dst;

extern Node *D_006A6730;

void func_001502A0(Dst *arg0, s32 arg1) {
    Node *base;
    Node *t0;

    if (arg1 != 3) {
        return;
    }
    base = D_006A6730;
    t0 = base->arr[base->index];
    arg0->v0 = *(u128 *)((u8 *)t0 + 0x0);
    arg0->v1 = *(u128 *)((u8 *)t0 + 0x10);
    arg0->v2 = *(u128 *)((u8 *)t0 + 0x20);
    arg0->v3 = *(u128 *)((u8 *)t0 + 0x30);
    arg0->v4 = *(u128 *)((u8 *)t0 + 0x40);
    base = D_006A6730;
    t0 = base->arr[base->index];
    arg0->v5 = *(u128 *)((u8 *)t0 + 0x0);
    arg0->v6 = *(u128 *)((u8 *)t0 + 0x10);
    arg0->v7 = *(u128 *)((u8 *)t0 + 0x20);
}
