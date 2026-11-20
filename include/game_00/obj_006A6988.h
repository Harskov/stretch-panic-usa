#ifndef GAME_00_OBJ_006A6988_H
#define GAME_00_OBJ_006A6988_H
#include "common.h"
/* The object D_006A6988 points at: a C++ object with nine virtual functions, six of
   which the main loop in unit_0011F5E0 calls each frame, and a word after its vtable
   pointer whose address func_00159520 and func_0015BA80 pass to func_0012AA10. */
#ifdef __cplusplus
struct Obj_006A6988 {
    virtual void m0(void);
    virtual void m1(void);
    virtual void m2(void);
    virtual void m3(void);
    virtual void m4(void);
    virtual void m5(void);
    virtual void m6(void);
    virtual void m7(void);
    virtual void m8(void);
    /* 0x04 */ s32 unk_4;
};

extern "C" {
#else
/* A C unit cannot declare the class; it sees the vtable pointer as a plain member. */
typedef struct Obj_006A6988 {
    /* 0x00 */ void *vtable;
    /* 0x04 */ s32 unk_4;
} Obj_006A6988;
#endif

extern Obj_006A6988 *D_006A6988;

#ifdef __cplusplus
}
#endif
#endif
