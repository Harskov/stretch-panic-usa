/* types.h */
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
/* common.h */
/* shared declarations grow here in consolidate steps */

/* The 16-byte vector the VU0 macro-mode blocks load and store whole (lqc2/sqc2):
   four floats, of which vadd.xyz touches the first three. */
typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec;
/* externs referenced by the target asm (systematic names; rename in consolidate with evidence) */
extern s32 D_006AF0A0;
extern s32 D_006AF0A4;
extern s32 D_006AF4A0;
void func_00151820();
