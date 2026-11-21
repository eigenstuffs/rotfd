/* GSQE78 retained MSL unit; provenance: docs/notes/msl-math.md. */
#include "fdlibm.h"

double exp(double x) {
    return __ieee754_exp(x);
}
