typedef int s32;
typedef unsigned __int128 u128;

typedef struct Entry {
    u128 a;
    u128 b;
} Entry;

typedef struct Obj {
    unsigned char unk_00[0x94];
    s32 count;
    unsigned char unk_98[4];
    Entry *buf;
    unsigned char unk_A0[0xC4 - 0xA0];
    s32 idx;
} Obj;

void func_00176C10(Obj *p, u128 *s1, u128 *s2)
{
    p->idx = (p->idx - 1) & (p->count - 1);
    p->buf[p->idx].a = *s1;
    p->buf[p->idx].b = *s2;
}
