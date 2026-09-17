typedef struct E64 {
    __int128 q[4];
} E64;

typedef struct Src {
    unsigned char unk_00[4];
    E64 *arr;
} Src;

typedef struct Ctx {
    unsigned char unk_00[8];
    Src *src;
    int count;
    E64 *dst;
} Ctx;

void func_00131740(Ctx *c) {
    int i;

    for (i = 0; i < c->count; i++) {
        c->dst[i] = c->src->arr[i];
    }
}
