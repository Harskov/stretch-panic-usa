typedef struct Obj {
    unsigned char unk_00[0x54];
    int count;
} Obj;

int func_00158670(Obj *o) {
    return o->count-- > 0;
}
