// fn_801DE350: ray vs. torus with elliptic cross-section (radius R, tube r, height scale h).
// Builds the monic quartic in t and solves it with fn_801DE498 (same original TU as
// swept_sphere_sphere_hit_801DE080.cpp / polynomial_root_solvers_801DE498.cpp).
// The declaration order of the float locals reproduces the original FPR colouring.
extern "C" {
extern const float lbl_8037A4E4; /* 1.0f */
extern const float lbl_8037A4F8; /* 2.0f */
extern const float lbl_8037A4FC; /* 4.0f */
extern const double lbl_8037A500; /* 1.0 */
int fn_801DE498(const double*, double*);
}
struct Vec3 { float x, y, z; };
extern "C" bool fn_801DE350(float R, float r, float h, const Vec3* o, const Vec3* d, int* num, double* roots)
{
    double c[5];
    float c3, k2, b, ox, oy, od, dy, dx, oz, n;
    float r2 = r * r;
    *num = 0;
    float R4 = lbl_8037A4FC * R;
    dx = d->x;
    float k = r2 / (h * h);
    ox = o->x;
    float dz = d->z;
    k2 = lbl_8037A4F8 * k;
    oy = o->y;
    oz = o->z;
    dy = d->y;
    od = ox * dx + oz * dz;
    n = lbl_8037A4E4 - dy * dy;
    float m = lbl_8037A4F8 * od;
    float oo = ox * ox + oz * oz;
    float k2dy = k2 * dy;
    float cc = (R * R - r2) + (oy * (k * oy) + oo);
    b = oy * k2dy + m;
    float a = dy * (k * dy) + n;
    float E = (R4 * R) / (a * a);
    float B = b / a;
    float C = cc / a;
    c3 = lbl_8037A4F8 * B;
    c[4] = lbl_8037A500;
    c[3] = c3;
    c[2] = lbl_8037A4F8 * C + B * B - E * n;
    c[1] = c3 * C - E * m;
    c[0] = C * C - E * oo;
    *num = fn_801DE498(c, roots);
    float t0 = roots[1];
    float t1 = roots[0];
    roots[0] = t0;
    roots[1] = t1;
    t0 = roots[3];
    t1 = roots[2];
    roots[2] = t0;
    roots[3] = t1;
    return *num != 0;
}
