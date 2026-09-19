typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;

extern s32 D_006A6730;
void func_00127840();

typedef struct {
    u8 pad0[0x70];
    u64 unk70;
    u8 pad78[0x18];
    u8 unk90;
    u8 pad91[0x2BF];
    u32 unk350;
    u32 unk360;
} State;

void func_00170AB0(void)
{
    State *s = (State *)D_006A6730;
    u32 a0;
    u32 a0b;

    a0 = s->unk360 | 0x400;
    s->unk90 = 1;
    s->unk70 = (s->unk70 & ~1LL) | (u64)((a0 & 0x1000) >> 12);
    s->unk90 = 1;
    s->unk70 = (s->unk70 & ~0x4000LL) | (u64)(((a0 & 0x2000) >> 13) << 14);
    s->unk350 |= ((a0 ^ s->unk360) & 0xF) << 4;
    s->unk360 = a0;

    s = (State *)D_006A6730;
    a0b = s->unk360 & ~0x110;
    s->unk90 = 1;
    s->unk70 = (s->unk70 & ~1LL) | (u64)((a0b & 0x1000) >> 12);
    s->unk90 = 1;
    s->unk70 = (s->unk70 & ~0x4000LL) | (u64)(((a0b & 0x2000) >> 13) << 14);
    s->unk350 |= ((a0b ^ s->unk360) & 0xF) << 4;
    s->unk360 = a0b;

    func_00127840(D_006A6730, 0, 1, 0, 0);
}
