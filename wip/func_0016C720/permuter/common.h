#ifndef COMMON_H
#define COMMON_H
/* shared declarations grow here in consolidate steps */
#include "types.h"

/* The 16-byte vector the VU0 macro-mode blocks load and store whole (lqc2/sqc2):
   four floats, of which vadd.xyz touches the first three. */
typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec;
#endif
