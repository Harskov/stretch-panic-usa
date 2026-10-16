#ifndef COMMON_H
#define COMMON_H
/* declarations shared across the units */
#include "types.h"

/* A translation unit names each function not yet written in C with an INCLUDE_ASM line;
   the build puts the function's assembly in its place before the compiler reads the
   file, and these empty definitions keep the file readable to everything else. */
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME)
#endif
#ifndef INCLUDE_RODATA
#define INCLUDE_RODATA(FOLDER, NAME)
#endif

/* The 16-byte vector the VU0 macro-mode blocks load and store whole (lqc2/sqc2):
   four floats, of which vadd.xyz touches the first three. */
typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec;

/* A quadword reached both whole (lq/sq: copied, or loaded from the scratchpad) and
   lane by lane as a Vec. */
typedef union Quad {
    /* 0x00 */ u128 unk_0;
    /* 0x00 */ Vec vec0;
} Quad;
#endif
