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
    u8 pad78[0x90 - 0x78];
    u8 unk90;
    u8 pad91[0x350 - 0x91];
    u32 unk350;
    u32 unk360;
} Ctx;

void func_00170980(void)
{
    Ctx *c;
    u32 a0;
    u32 a4;
    u64 t;

    c = (Ctx *)D_006A6730;
    a0 = c->unk360;
    c->unk90 = 1;
    t = c->unk70;
    a0 |= 0x400;
    t &= ~1;
    t |= (u64)((a0 & 0x1000) >> 12);
    c->unk70 = t;
    c->unk90 = 1;
    t = c->unk70;
    t &= ~0x4000;
    t |= (u64)(((a0 & 0x2000) >> 13) << 14);
    c->unk70 = t;
    c->unk350 |= ((a0 ^ c->unk360) & 0xF) << 4;
    c->unk360 = a0;

    c = (Ctx *)D_006A6730;
    a4 = c->unk360 & ~0x110;
    c->unk90 = 1;
    t = c->unk70;
    t &= ~1;
    t |= (u64)((a4 & 0x1000) >> 12);
    c->unk70 = t;
    c->unk90 = 1;
    t = c->unk70;
    t &= ~0x4000;
    t |= (u64)(((a4 & 0x2000) >> 13) << 14);
    c->unk70 = t;
    c->unk350 |= ((a4 ^ c->unk360) & 0xF) << 4;
    c->unk360 = a4;

    func_00127840(D_006A6730, 0, 2, 0, 0);
}
