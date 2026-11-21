/* GSQE78 retained MSL unit; provenance: docs/notes/msl-math.md. */
#include "fdlibm.h"

double asin(double x) {
    return __ieee754_asin(x);
}
