#ifndef COMMON_H
#define COMMON_H
/* shared declarations grow here in consolidate steps */
#include "types.h"

/* A translation unit names each function not yet matched with an INCLUDE_ASM line; mwccgap
   puts the function's assembly in its place before the compiler reads the file, and
   these empty definitions keep the file readable to everything else that reads it. */
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
#endif
