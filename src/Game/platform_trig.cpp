#include "Game/platform_trig_internal.h"
#include "Game/platform_trig_tables_internal.h"

extern "C" {
extern const double lbl_8037B850;
extern const float lbl_8037B860;
extern const float lbl_8037B870;
double __fabs(double);

inline float phaseInterpolation(float angle)
{
    float x = __fabs(lbl_8037B870 * float(angle - lbl_8037B850));
    int index = x;
    x -= float(index);
    float fraction = x;
    float weight = lbl_8037B860 - fraction;
    int sample = index & 31;
    float result;

    if (index & 32) {
        sample = 32 - sample;
        result = weight * lbl_8035D4A0[sample] +
                 fraction * lbl_8035D4A0[sample - 1];
    } else {
        result = weight * lbl_8035D4A0[sample] +
                 fraction * lbl_8035D4A0[sample + 1];
    }
    if ((index ^ (index >> 1)) & 32) {
        result = -result;
    }
    return result;
}

inline float directInterpolation(float angle)
{
    float x = __fabs(lbl_8037B870 * angle);
    int index = x;
    float fraction = x - float(index);
    float weight = lbl_8037B860 - fraction;
    int sample = index & 31;
    float result;

    if (index & 32) {
        sample = 32 - sample;
        result = weight * lbl_8035D4A0[sample] +
                 fraction * lbl_8035D4A0[sample - 1];
    } else {
        result = weight * lbl_8035D4A0[sample] +
                 fraction * lbl_8035D4A0[sample + 1];
    }
    if ((index ^ (index >> 1)) & 32) {
        result = -result;
    }
    return result;
}
float fn_80284E34(float angle)
{
    return phaseInterpolation(angle) / directInterpolation(angle);
}
float fn_80284FA8(float angle) { return phaseInterpolation(angle); }
float fn_8028506C(float angle)
{
    float x = __fabs(lbl_8037B870 * angle);
    int index = x;
    float fraction = x - float(index);
    float weight = lbl_8037B860 - fraction;
    int sample = index & 31;
    float result;

    if (index & 32) {
        sample = 32 - sample;
        result = weight * lbl_8035D4A0[sample] +
                 fraction * lbl_8035D4A0[sample - 1];
    } else {
        result = weight * lbl_8035D4A0[sample] +
                 fraction * lbl_8035D4A0[sample + 1];
    }
    if ((index ^ (index >> 1)) & 32) {
        result = -result;
    }
    return result;
}
extern const float lbl_8037B838;
extern const double lbl_8037B848, lbl_8037B858, lbl_8037B880, lbl_8037B888;
double atan(double);
double cos(double);
double acos(double);
inline float absoluteFloat(float value) { return value < lbl_8037B838 ? -value : value; }

#pragma opt_common_subs off
float fn_80285124(float y, float x)
{
    if (lbl_8037B838 == x && lbl_8037B838 == y) return lbl_8037B838;
    double ax; double ay;
    ay = absoluteFloat(y);
    ax = absoluteFloat(x);
    
    if (ay == ay - ax) {
        return y < lbl_8037B838 ? lbl_8037B848 : lbl_8037B850;
    }
    double angle;
    if (ax == ax - ay) angle = lbl_8037B858;
    else angle = atan(y / x);
    if (x > lbl_8037B838) return angle;
    if (y < lbl_8037B838) return angle - lbl_8037B880;
    return lbl_8037B880 + angle;
}
#pragma opt_common_subs on
void fn_80285234()
{
    int i;
    for (i = 0; i <= 32; ++i) {
        lbl_8035D4A0[i] = cos(float(lbl_8037B888 * i));
    }
    for (i = 0; i < 64; ++i) {
        union { unsigned long bits; float value; } exponent;
        exponent.bits = 0x38000000 | (i << 21);
        lbl_8035D3A0[i] = acos(lbl_8037B860 - exponent.value);
    }
}
}
