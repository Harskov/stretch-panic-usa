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
    float x;
    float y;
    float z;
    float w;
} Vec;

typedef struct Obj {
    unsigned char unk_00[0x190];
    Vec m190;
    Vec m1A0;
    Vec m1B0;
    unsigned char unk_1C0[0xB4];
    s32 unk_274;
    unsigned char unk_278[0x14];
    u8 unk_28C;
    unsigned char unk_28D[0x53];
    float unk_2E0;
    float unk_2E4;
    float unk_2E8;
    float unk_2EC;
    s32 unk_2F0;
    float unk_2F4;
} Obj;

typedef struct Out {
    Vec m00;
    Vec m10;
    Vec m20;
    unsigned char unk_30[0x20];
    float unk_50;
    float unk_54;
    float unk_58;
    float unk_5C;
    s32 unk_60;
    float unk_64;
    s32 unk_68;
    s32 unk_6C;
    s32 unk_70;
} Out;

void func_001627B0(Obj *a, Out *b)
{
    float f0;
    float f1;
    float f2;
    float f3;

    a->unk_28C = 0;
    f3 = a->unk_2E0;
    f2 = a->unk_2E4;
    f1 = a->unk_2E8;
    f0 = a->unk_2EC;
    b->unk_50 = f3;
    b->unk_54 = f2;
    b->unk_58 = f1;
    b->unk_5C = f0;
    b->m00 = a->m190;
    b->m10 = a->m1A0;
    b->m20 = a->m1B0;
    f0 = b->m20.x;
    b->m20.x = -f0;
    f0 = b->m20.y;
    b->m20.y = -f0;
    f0 = b->m20.z;
    b->m20.z = -f0;
    b->unk_60 = a->unk_2F0;
    b->unk_64 = a->unk_2F4;
    if (a->unk_274 & 4) {
        b->unk_68 = 2;
        b->unk_6C = 4;
        b->unk_70 = 0x3F800000;
        a->unk_274 &= ~4;
        return;
    }
    b->unk_68 = 0;
    b->unk_6C = 0;
    b->unk_70 = 0;
}
