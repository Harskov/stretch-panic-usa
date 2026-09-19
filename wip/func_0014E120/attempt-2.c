typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;

typedef struct Node {
    u8 pad[0x60];
    s32 flags;
    u8 pad2[0xB8 - 0x64];
    f32 unk_B8;
    u8 unk_BC;
    u8 pad3[0x364 - 0xBD];
    s32 unk_364;
} Node;

void func_0014E120(Node *arg0) {
    if (arg0->flags & 0x40) {
        if (arg0->unk_B8 >= 100.0f) {
            arg0->unk_364 = 0x14;
        } else if (arg0->unk_BC != 0) {
            arg0->unk_364 = 0x16;
        } else {
            arg0->unk_364 = 0x17;
        }
    }
}
