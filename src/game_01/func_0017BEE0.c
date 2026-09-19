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
    u8 pad0[0x16C];
    s32 i16C;
} Ent;

void func_0017AFC0();

void func_0017BEE0(Ent *arg0)
{
    arg0->i16C = 0;
    func_0017AFC0();
}
