/* GSQE78 retained MSL unit; provenance: docs/notes/msl-math.md. */
#include "fdlibm.h"

double pow(double x, double y) {
    return __ieee754_pow(x, y);
}
