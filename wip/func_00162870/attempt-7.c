typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;
typedef unsigned __int128 u128;

typedef struct Sub {
    unsigned char unk_00[0x58];
    s32 unk_58;
    unsigned char unk_5C[0x4];
    s32 unk_60;
    unsigned char unk_64[0x4];
    s32 unk_68;
} Sub;

typedef struct Arg1 {
    unsigned char unk_00[0x80];
    u128 unk_80;
    unsigned char unk_90[0x10];
    f32 unk_A0;
    f32 unk_A4;
    f32 unk_A8;
    f32 unk_AC;
    unsigned char unk_B0[0x18];
    Sub *unk_C8;
} Arg1;

typedef struct Arg0 {
    unsigned char unk_00[0x60];
    s32 unk_60;
    unsigned char unk_64[0x224];
    s32 unk_288;
    unsigned char unk_28C[0x54];
    f32 unk_2E0;
    f32 unk_2E4;
    f32 unk_2E8;
    f32 unk_2EC;
    s32 unk_2F0;
    s32 unk_2F4;
    unsigned char unk_2F8[0x18];
    u128 unk_310;
    unsigned char unk_320[0x10];
    u128 unk_330;
} Arg0;

void func_00162870(Arg0 *arg0, Arg1 *arg1) {
    Sub *temp_a2;
    Sub *temp_a3;

    temp_a2 = arg1->unk_C8;
    if ((temp_a2->unk_68 & 0x10) && !(temp_a2->unk_60 & 0x20000)) {
        temp_a3 = temp_a2;
        arg0->unk_288 = temp_a3->unk_60;
        arg0->unk_2F0 = temp_a2->unk_58;
        arg0->unk_2E0 = arg1->unk_A0;
        arg0->unk_2E4 = arg1->unk_A4;
        arg0->unk_2E8 = arg1->unk_A8;
        arg0->unk_2EC = arg1->unk_AC;
        arg0->unk_2F4 = 0;
        arg0->unk_310 = arg1->unk_80;
        arg0->unk_330 = arg1->unk_80;
        arg0->unk_60 = arg0->unk_60 | 2;
    }
}
