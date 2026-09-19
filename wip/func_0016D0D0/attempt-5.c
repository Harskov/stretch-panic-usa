typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;
typedef unsigned __int128 u128;

void func_0016E4D0();

typedef struct {
    unsigned char pad[0xD4];
    int unkD4;
    unsigned char pad2[0x4];
    int unkDC;
    unsigned char pad3[0xB0];
} Obj;

void func_0016D0D0(Obj *arg0) {
    func_0016E4D0((char *)arg0 + 0x190, arg0->unkDC, arg0->unkD4, 0);
}
