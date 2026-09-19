typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;

typedef struct {
    unsigned char pad[0x60];
    u32 flags;
    unsigned char pad2[0x100];
    s32 unk_164;
    s32 unk_168;
} Obj168;

s32 func_00172A80(s32 arg0);

void func_0016DC40(Obj168 *arg0, s32 arg1) {
    arg0->unk_164 = arg1;
    arg0->unk_168 = func_00172A80(arg1);
    arg0->flags |= 0x04000000;
}
