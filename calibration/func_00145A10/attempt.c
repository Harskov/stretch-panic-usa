typedef struct M128 {
    __int128 q[8];
} M128;

typedef struct Obj {
    unsigned char unk_00[0x90];
    M128 m;
    unsigned char unk_110[0x3C];
    unsigned char flag;
} Obj;

void func_00145A10(Obj *o, M128 *dst) {
    *dst = o->m;
    o->flag = 0;
}
