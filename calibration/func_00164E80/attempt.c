typedef struct Ent {
    unsigned char used;
    unsigned char unk_01[0x2F];
} Ent;

typedef struct Obj {
    unsigned char unk_00[0x50];
    int count;
    unsigned char unk_54[0x14];
    Ent *arr;
} Obj;

Ent *func_00164E80(Obj *o) {
    int i;

    for (i = 0; i < o->count; i++) {
        if (o->arr[i].used == 0) {
            return &o->arr[i];
        }
    }
    return 0;
}
