/* GSQE78 retained math_ppc.c wrapper, following the tanf body in
 * reference/mkdd-msl/math_api.h. See docs/notes/msl-math.md.
 */
extern double tan(double);
float tanf(float x) { return tan((double)x); }
