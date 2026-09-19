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
    Vec q[9];
} Dst;

extern Node *D_006A6730;

void func_001502A0(Dst *arg0, s32 arg1) {
    Node *base;
    u128 *src;

    if (arg1 != 3) {
        return;
    }
    base = D_006A6730;
    src = (u128 *)base->arr[base->index];
    arg0->q[0] = *((Vec *)src + 0);
    arg0->q[1] = *((Vec *)src + 1);
    arg0->q[2] = *((Vec *)src + 2);
    arg0->q[3] = *((Vec *)src + 3);
    arg0->q[4] = *((Vec *)src + 4);
    base = D_006A6730;
    src = (u128 *)base->arr[base->index];
    arg0->q[5] = *((Vec *)src + 0);
    arg0->q[6] = *((Vec *)src + 1);
    arg0->q[7] = *((Vec *)src + 2);
    arg0->q[8] = *((Vec *)src + 3);
}
