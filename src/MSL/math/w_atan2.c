/* GSQE78 retained MSL unit; provenance: docs/notes/msl-math.md. */
#include "fdlibm.h"

double atan2(double x, double y) {
    return __ieee754_atan2(x, y);
}
