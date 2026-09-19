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

typedef struct {
    u8 pad[0x50];
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    f32 unk64;
    f32 unk68;
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    f32 unk78;
    f32 unk7C;
    f32 unk80;
    u8 pad2[0x8];
    f32 unk8C;
    u8 pad3[0xC];
    f32 unk9C;
} S;

s32 func_001733C0(S *arg0) {
    register f32 *v;
    register f32 *p;
    s32 r;

    arg0->unk70 = arg0->unk70 * arg0->unk74;
    arg0->unk74 = arg0->unk74 * arg0->unk78;
    arg0->unk7C = arg0->unk7C * arg0->unk80;
    arg0->unk9C = arg0->unk9C + arg0->unk8C;
    v = &arg0->unk50;
    p = &arg0->unk60;
    asm {
        lqc2 vf1, 0(v)
        lqc2 vf2, 0(p)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(v)
    }
    r = 1;
    if (arg0->unk9C <= 0.0f) {
        r = 0;
    }
    return r;
}
