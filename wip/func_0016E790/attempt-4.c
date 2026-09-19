typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;
typedef unsigned __int128 u128;

extern s32 D_0069C300;
extern s32 D_0069C480;
void *func_00100810();

typedef struct Sub24 {
    u8 pad0[0x24];
    void *p24;
    u8 b28;
    u8 pad29[3];
} Sub24;

typedef struct Sub10 {
    s32 f0;
    s32 f4;
    f32 f8;
    s32 fC;
} Sub10;

typedef struct Obj {
    u8 pad0[0x50];
    f32 unk50;
    u8 pad54[0x94];
    s32 unkE8;
    Sub24 *unkEC;
    Sub10 *unkF0;
    s32 *unkF4;
    s32 *unkF8;
    u8 *unkFC;
    u8 *unk100;
    u8 *unk104;
} Obj;

typedef struct Arg1 {
    f32 f0;
    s32 f4;
} Arg1;

void func_0016E790(Obj *arg0, Arg1 *arg1) {
    s32 i;
    s32 offTbl;
    s32 offVec;
    Sub24 *p24;
    Sub10 *p10;
    u128 *src;
    u128 val;
    void *res;

    i = 0;
    offTbl = 0;
    offVec = 0;
    src = (u128 *)0x70000BE0;
    for (i = 0; i < arg0->unkE8; i++) {
        val = *src;
        *(u128 *)(arg0->unkFC + offVec) = val;
        val = *src;
        *(u128 *)(arg0->unk100 + offVec) = val;
        val = *src;
        *(u128 *)(arg0->unk104 + offVec) = val;
        *(f32 *)((u8 *)arg0->unkEC + offTbl + 0x20) = arg0->unk50 * arg1->f0;
        res = func_00100810(0x40, src, 0);
        p24 = (Sub24 *)((u8 *)arg0->unkEC + offTbl);
        p24->p24 = res;
        if (res != 0) {
            *(s32 *)((u8 *)res + 0x0) = (s32)&D_0069C300;
            *(s32 *)((u8 *)res + 0x0) = (s32)&D_0069C480;
            *(s32 *)((u8 *)res + 0x30) = arg1->f4;
            *(s32 *)((u8 *)res + 0x4) = 0;
            p10 = (Sub10 *)*(s32 *)((u8 *)res + 0x30);
            *(u128 *)((u8 *)res + 0x10) = *(u128 *)p10;
            *(u128 *)((u8 *)res + 0x20) = *(u128 *)((u8 *)p10 + 0x10);
        }
        p24->b28 = 1;
        arg1 = (Arg1 *)((u8 *)arg1 + 8);
        p10 = (Sub10 *)((u8 *)arg0->unkF0 + offVec);
        p10->f0 = 0;
        p10->f4 = 1;
        p10->f8 = 1.0f;
        p10->fC = 2;
        offVec += 0x10;
        offTbl += 0x30;
    }
    arg0->unkF8[0] = arg0->unkE8;
    arg0->unkF8[1] = (s32)arg0->unkEC;
    arg0->unkF8[2] = (s32)arg0->unkF0;
    arg0->unkF8[3] = (s32)arg0->unkF4;
}
