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

typedef struct Node Node;
struct Node {
    u8 pad[0x378];
    u32 index;
    u8 pad2[0x500 - 0x37C];
    Node *arr[1];
};

typedef struct Dst {
    u8 pad[0x230];
    u128 q[8];
} Dst;

extern Node D_006A6730[];

void func_001502A0(Dst *arg0, s32 arg1) {
    Node *base;
    Node *t0;
    u128 *src;

    if (arg1 != 3) {
        return;
    }
    base = &D_006A6730[0];
    t0 = base->arr[base->index];
    src = (u128 *)t0;
    arg0->q[0] = src[0];
    arg0->q[1] = src[1];
    arg0->q[2] = src[2];
    arg0->q[3] = src[3];
    arg0->q[4] = src[4];
    base = &D_006A6730[0];
    t0 = base->arr[base->index];
    src = (u128 *)t0;
    arg0->q[5] = src[0];
    arg0->q[6] = src[1];
    arg0->q[7] = src[2];
}
