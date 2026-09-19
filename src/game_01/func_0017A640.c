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
    u8 pad0[0x178];
    s32 i178;
    u8 pad17C[0x180 - 0x17C];
    s32 i180;
    u8 pad184[0x2B0 - 0x184];
    s32 i2B0;
    s32 i2B4;
    s32 i2B8;
    s32 i2BC;
} Ent;

void func_0016E760();

void func_0017A640(Ent *arg0)
{
    arg0->i2B0 = 6;
    arg0->i178 = 7;
    arg0->i180 = 0x3F800000;
    arg0->i2BC = 0;
    arg0->i2B8 = 0;
    arg0->i2B4 = 0;
    func_0016E760();
}
