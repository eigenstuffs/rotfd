/* GSQE78 retained MSL unit; provenance: docs/notes/msl-math.md. */
#include "fdlibm.h"

double fmod(double x, double y) {
    return __ieee754_fmod(x, y);
}
