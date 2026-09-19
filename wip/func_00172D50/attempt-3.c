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

extern s32 D_006A6D18;
void func_0013BFB0();

void func_00172D50(s32 *arg0, s32 arg1, f32 f12, f32 f13, f32 f14) {
    s32 temp_v1;
    f32 temp_f0;
    f32 temp_f1;
    s32 *p;

    temp_v1 = arg1 << 5;
    temp_f1 = f12 * f12;
    temp_f0 = 12.566371f * temp_f1;
    p = (s32 *)(temp_v1 + arg0[0x18]);
    *(f32 *)(p + 4) = temp_f0;
    *(f32 *)(p + 5) = f13;
    *(f32 *)(p + 6) = f14;
    func_0013BFB0(arg0);
}
