#include "Game/platform_math_internal.h"

extern "C" {
extern const float lbl_8037B860, lbl_8037B864;
extern const double lbl_8037B840, lbl_8037B868;
double log(double);
double acos(double);
void fn_80284DB0(void*, void*) {}
float fn_80284DB4(float value) { return log(value); }
float fn_80284DD8(float value)
{
    if (value > lbl_8037B860) return acos(lbl_8037B840);
    if (value < lbl_8037B864) return acos(lbl_8037B868);
    return acos(value);
}
}
