typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;
typedef unsigned __int128 u128;

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec;

typedef struct Ent {
    u8 pad0[0x64];
    s32 i64;
    s32 i68;
    u8 pad6C[0x178 - 0x6C];
    s32 i178;
    u8 pad17C[0x180 - 0x17C];
    s32 i180;
    u8 pad184[0x2B0 - 0x184];
    s32 i2B0;
    s32 i2B4;
    s32 i2B8;
    s32 i2BC;
    u8 pad2C0[0x2F0 - 0x2C0];
    s32 i2F0;
} Ent;

void func_00179DF0(Ent *arg0)
{
    arg0->i2B0 = 0;
    arg0->i178 = 0xA;
    arg0->i180 = 0;
    arg0->i2BC = 0;
    arg0->i2B8 = 0;
    arg0->i2B4 = 0;
    arg0->i64 = 0;
    arg0->i68 = 0x40;
    arg0->i2F0 = 0;
}
