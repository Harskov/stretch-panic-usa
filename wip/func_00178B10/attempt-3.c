typedef struct Vtbl {
    unsigned char unk_00[0x10];
    int (*f10)(void *);
} Vtbl;

typedef struct Inner {
    Vtbl *vt;
} Inner;

typedef struct Obj {
    unsigned char unk_00[0x50];
    Inner *field_50;
} Obj;

int func_00178B10(Obj *p)
{
    Inner *q = p->field_50;

    return q->vt->f10(q);
}
