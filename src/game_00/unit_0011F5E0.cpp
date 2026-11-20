#include "common.h"
#include "globals.h"
#include "game_00/obj_006A6730.h"
#include "game_00/obj_001211E0.h"
#include "game_00/obj_006A6988.h"

extern "C" {

s32 sceGsSyncV(s32 mode);
s32 sceGsSyncPath(s32 mode, u16 timeout);
void smsBufferPush(void);
void smsBufferPop(void);
void func_001000C0(void);
void func_0011FA00(void);
void func_0011FA50(void);
void func_00121640(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_001214F0(void *arg0);

void func_00128B90(void);
void func_00128C00(void);
void func_00128C40(void);
void func_00128CB0(void);
void func_00129010(void);
s32 func_00129060(void);
void func_0013C1C0(Obj_006A6D18 *arg0);
void func_0013C2E0(void);
s32 func_0013C510(s32 arg0, char *arg1);
void func_0013C7A0(s32 arg0);
void func_0013DEA0(s32 arg0);
void func_0013E160(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_0013E1A0(s32 arg0);
void func_00145FC0(void);

void func_0011F5E0(void);
}

/* The top-level loop after the boot set-up: forever, prepare a pass, wait 30 vsyncs, run the
   per-frame virtual calls on D_006A6988 while D_006A69B8 is set, tear down, wait 30 vsyncs. */
void func_0011F5E0(void)
{
    s32 p1, p2, p3, p4, p5, p6;

    func_0011FA00();
    func_001000C0();
    func_0011FA50();
    func_00128B90();
    func_00128C00();

    for (;;) {
        func_00128C40();
        smsBufferPush();
        D_006A6D10[1] = func_0013C510(1, D_00546440[func_00129060()].unk_0);
        D_006A6D10[2] = func_0013C510(2, D_00546440[func_00129060()].unk_4);
        for (D_006A66F0 = 0; D_006A66F0 < 30; D_006A66F0++) {
            func_001214F0(D_006A66E8);
            func_0013C2E0();
            sceGsSyncV(0);
        }

        func_0013E1A0(1);
        p6 = D_005464F0[func_00129060()].unk_1C;
        p5 = D_005464F0[func_00129060()].unk_18;
        p4 = D_005464F0[func_00129060()].unk_14;
        p3 = D_005464F0[func_00129060()].unk_10;
        p2 = D_005464F0[func_00129060()].unk_C;
        p1 = D_005464F0[func_00129060()].unk_8;
        func_0013E160(D_005464F0[func_00129060()].unk_4, p1, p2, p3, p4, p5, p6);
        for (D_006A66F0 = 0; D_006A66F0 < 30; D_006A66F0++) {
            func_001214F0(D_006A66E8);
            func_0013C2E0();
            sceGsSyncV(0);
        }

        func_00121640(D_006A66F8, 0, 1, 1);
        func_00128CB0();
        do {
            func_001214F0(D_006A66E8);
            D_006A6988->m7();
            if (D_006A69C0) {
                D_006A6988->m4();
                D_006A6988->m2();
            } else {
                D_006A6988->m1();
                D_006A6988->m3();
                D_006A6988->m2();
            }
            D_006A6988->m8();
            D_006A69F8++;
            func_0013C1C0(D_006A6D18);
            func_0013C2E0();
            sceGsSyncPath(0, 0);
            sceGsSyncV(0);
            func_00145FC0();
            func_00124080(D_006A6730);
            func_00124110(D_006A6730);
        } while (D_006A69B8);

        sceGsSyncV(0);
        sceGsSyncPath(0, 0);
        func_00129010();
        func_0013DEA0(0);
        func_0013C7A0(D_006A6D20);
        smsBufferPop();
        for (D_006A66F0 = 0; D_006A66F0 < 30; D_006A66F0++) {
            func_001214F0(D_006A66E8);
            func_0013C2E0();
            sceGsSyncV(0);
        }
    }
}
