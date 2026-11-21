/* MSL floating-point limits, exposed through int-array representation objects
 * by strtold.c, ansi_fp.c and math/fdlibm.h. Words are in target byte order. */
int __float_nan[1] = {0x7FFFFFFF};
int __float_huge[1] = {0x7F800000};
int __double_min[2] = {0x00100000, 0};
int __double_max[2] = {0x7FEFFFFF, -1};
int __double_huge[2] = {0x7FF00000, 0};
int __long_double_min[2] = {0x00100000, 0};
int __long_double_max[2] = {0x7FEFFFFF, -1};
