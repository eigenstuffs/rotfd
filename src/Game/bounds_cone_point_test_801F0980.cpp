// Partial text split: fn_801F0980 (point-in-cone test). Uses the engine's
// fixed-f4 frsqrte inline helper pattern (scaledRsqrt, like fastSqrt).
// fn_801F0A20 (94.1%) remains original; full draft in
// scratch/claude_match/auto_03_801F0980_text/final.cpp.
/* Engine bounding-volume helpers (one original TU with fn_801F0E60's
 * box-axes startup; shares its 1.0f/0.0f pool labels):
 *   fn_801F0980  point-in-cone test (origin, min distance, axis, cosine)
 *   fn_801F0A20  smallest sphere enclosing two spheres (returned by value)
 *   fn_801F0C68  bounding sphere of a point array (AABB centre, max distance)
 * fn_801F0980 and fn_801F0C68 match exactly; fn_801F0A20 is PARTIAL (94.1%,
 * FPR assignment in the main block only).
 *
 * Notes: the cone test's raw rsqrt estimate times 1.0f keeps a fixed f4
 * (frsqrte f4,x; fmuls r,f4,s) like the engine fastSqrt helper.  The 0.5f
 * centre scale is a pooled literal in the original; Vec3::half() spells its
 * three reads differently so each is loaded at its use (pooled-literal
 * emulation).  The max corner of the AABB is kept in memory through a pointer.
 */
extern "C" {
extern const float lbl_8037A6C8; /* 10001.0f */
extern const float lbl_8037A6CC; /* 1.0f */
extern const float lbl_8037A6D0; /* 0.0f */
extern const float lbl_8037A6D8; /* 0.5f */
extern const float lbl_8037A6DC; /* 0.000001f */
float fn_800AA52C(float, float); /* max */
float fn_800AA53C(float, float); /* min */
}

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
inline float scaledRsqrt(register float x, register float s)
{
    register float r;
    asm { frsqrte f4, x
          fmuls r, f4, s }
    return r;
}
inline float sqrtOrZero(float sq, float zero)
{
    float r = zero;
    if (sq != r) r = fastSqrt(sq);
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}

    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    float dot() const { return x * x + y * y + z * z; }
    float length(float zero) const { return sqrtOrZero(dot(), zero); }
    Vec3 half() const { return Vec3(x * lbl_8037A6D8, y * *(const float*)&lbl_8037A6D8, z * *(const float*)(unsigned long)&lbl_8037A6D8); }
};

struct Sphere {
    Vec3 center;
    float radius;
    Sphere() {}
    Sphere(const Vec3& c, float r) : center(c), radius(r) {}
    Sphere(const Sphere& o) : center(o.center), radius(o.radius) {}
    Sphere& operator=(const Sphere& o) { center = o.center; radius = o.radius; return *this; }
};

struct Cone {
    Vec3 origin;
    float minimum;
    Vec3 axis;
    float cosine;
};

extern "C" int fn_801F0980(const Cone* cone, const Vec3* point)
{
    if (lbl_8037A6C8 == cone->minimum) return 0;
    Vec3 d = *point - cone->origin;
    float projection = d.dot(cone->axis);
    if (projection < cone->minimum) return 0;
    return projection * scaledRsqrt(d.dot(), lbl_8037A6CC) >= cone->cosine ? 1 : 0;
}




