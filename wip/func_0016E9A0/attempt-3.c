typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
typedef unsigned __int128 u128;

typedef struct {
    unsigned char pad[0xE8];
    s32 count;      /* 0xE8 */
    u8 *unkEC;      /* 0xEC */
    unsigned char pad2[0xC];
    u8 *unkFC;      /* 0xFC */
    u8 *unk100;     /* 0x100 */
    u8 *unk104;     /* 0x104 */
} Obj;

void func_0016E9A0(Obj *arg0)
{
    s32 i;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    u8 *p4;
    register u8 *v;
    register u8 *p;
    register u8 *d;

    i = 0;
    goto test;
loop:
    p1 = arg0->unkEC + i * 0x30;
    p2 = arg0->unkFC + i * 0x10;
    v = p2;
    p = p1;
    d = p1 + 0x10;
    asm {
        lqc2 vf1, 0(v)
        lqc2 vf2, 0(p)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(d)
    }
    *(u128 *)p1 = *(u128 *)p2;
    p3 = arg0->unk100 + i * 0x10;
    *(u128 *)p3 = *(u128 *)p2;
    p4 = arg0->unk104 + i * 0x10;
    *(u128 *)p4 = *(u128 *)(p1 + 0x10);
    i++;
test:
    if (i != arg0->count)
        goto loop;
}
