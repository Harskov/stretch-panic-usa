#ifndef GAME_00_OBJ_006A6730_H
#define GAME_00_OBJ_006A6730_H
#include "common.h"
/* One of the object's two buffers of doublewords: unk_0 is its start and unk_4 the
   place the next one is written (func_00123520 sends unk_0..unk_4 over DMA). */
typedef struct Sub_00123520 {
    /* 0x00 */ u64 *unk_0;
    /* 0x04 */ u64 *unk_4;
} Sub_00123520;

/* The five-quadword block the object's stacks hold: func_001243D0 copies the top
   block of each stack one slot up, func_0016E4D0 and func_0017BBA0 push one. */
typedef struct Blk_001243D0 {
    /* 0x00 */ u128 unk_0;
    /* 0x10 */ u128 unk_10;
    /* 0x20 */ u128 unk_20;
    /* 0x30 */ u128 unk_30;
    /* 0x40 */ u128 unk_40;
} Blk_001243D0;

/* The object D_006A6730 points at; func_00127FD0 returns it at start-up. unit_00123520
   holds its functions, and every unit that draws reaches it through the global.
   unk_C is the pair of DMA buffers and unk_8 the current one; unk_368[unk_364] is the
   base of the frame buffer being displayed (func_00124080); cursor[] are the tops of
   its stacks of five-quadword blocks, unk_378 selects one, and bit 0x100 << n of
   unk_350 marks stack n changed. */
typedef struct Obj_006A6730 {
    /* 0x0000 */ void *unk_0;
    /* 0x0004 */ s32 unk_4;
    /* 0x0008 */ Sub_00123520 *unk_8;
    /* 0x000C */ Sub_00123520 unk_C[2];
    /* 0x001C */ u8 pad_1C[0x14];
    /* 0x0030 */ u64 unk_30;
    /* 0x0038 */ u8 pad_38[0x58];
    /* 0x0090 */ u8 unk_90;
    /* 0x0091 */ u8 pad_91[0x2BF];
    /* 0x0350 */ s32 unk_350;
    /* 0x0354 */ u8 pad_354[8];
    /* 0x035C */ u32 flags;
    /* 0x0360 */ u8 pad_360[4];
    /* 0x0364 */ s32 unk_364;
    /* 0x0368 */ u64 unk_368[2];
    /* 0x0378 */ s32 unk_378;
    /* 0x037C */ u8 pad_37C[4];
    /* 0x0380 */ f32 unk_380;
    /* 0x0384 */ f32 unk_384;
    /* 0x0388 */ f32 unk_388;
    /* 0x038C */ u8 pad_38C[4];
    /* 0x0390 */ f32 unk_390;
    /* 0x0394 */ f32 unk_394;
    /* 0x0398 */ f32 unk_398;
    /* 0x039C */ u8 pad_39C[0x164];
    /* 0x0500 */ Blk_001243D0 *cursor[8];
    /* 0x0520 */ u8 pad_520[0x1180];
    /* 0x16A0 */ Vec unk_16A0;
    /* 0x16B0 */ f32 unk_16B0;
    /* 0x16B4 */ f32 unk_16B4;
    /* 0x16B8 */ u8 pad_16B8[0x9A8];
    /* 0x2060 */ u32 unk_2060;
    /* 0x2064 */ u8 pad_2064[0xC];
    /* 0x2070 */ u8 unk_2070;
} Obj_006A6730;

#ifdef __cplusplus
extern "C" {
#endif
extern Obj_006A6730 *D_006A6730;

/* unit_00123520.c */
void func_00123520(Obj_006A6730 *o);
void func_00124080(Obj_006A6730 *arg0);
void func_00124110(Obj_006A6730 *o);
void func_00125260(Obj_006A6730 *arg0);
#ifdef __cplusplus
}
#endif
#endif
