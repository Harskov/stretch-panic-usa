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

extern s32 D_0069CE70;
extern s32 D_006B3700;
extern s32 D_006B3880;
extern s32 D_006B3888;

typedef struct Node {
    s32 unk0;
    u128 unk10;
    u128 unk20;
    s32 unk30;
    s32 unk34;
    struct Node *unk38;
    struct Node *unk3C;
    u8 unk40;
    struct Node *unk44;
    struct Node *unk48;
} Node;

void func_00172DA0(Node *arg0, s32 arg1, u8 arg2) {
    Node *temp_v0;
    Node *temp_v0_2;

    arg0->unk0 = (s32)&D_0069CE70;
    arg0->unk10 = *(u128 *)0x70000BE0;
    arg0->unk20 = *(u128 *)0x70000BE0;
    arg0->unk30 = arg1;
    arg0->unk34 = D_006B3888;
    D_006B3888 = D_006B3888 + 1;
    arg0->unk3C = (Node *)(&D_006B3700)[arg0->unk30];
    arg0->unk38 = 0;
    (&D_006B3700)[arg0->unk30] = (s32)arg0;
    temp_v0 = arg0->unk3C;
    if (temp_v0 != 0) {
        temp_v0->unk38 = arg0;
    }
    arg0->unk40 = arg2;
    if (arg0->unk40 != 0) {
        arg0->unk48 = (Node *)D_006B3880;
        arg0->unk44 = 0;
        D_006B3880 = (s32)arg0;
        temp_v0_2 = arg0->unk48;
        if (temp_v0_2 != 0) {
            temp_v0_2->unk44 = arg0;
        }
    }
}
