/* Engine bounding-volume helpers and the box-axes startup tables: one original TU
 * (.text 0x801F0980-0x801F0EFC, .sdata2 0x8037A6C8-0x8037A6E0, .ctors 0x80299950, .bss 0x80340AC0-0x80340B44).
 *   fn_801F0980  point-in-cone test (origin, min distance, axis, cosine)
 *   fn_801F0A20  smallest sphere enclosing two spheres (returned by value)
 *   fn_801F0C68  bounding sphere of a point array (AABB centre, max distance)
 *   __sinit      box corner / axis tables
 * .sdata2 (address order): 10001.0f, 1.0f, 0.0f, -1.0f are named constants defined at the top (pool_head);
 * 0.5f is the pooled literal of fn_801F0A20 ('* 0.5f' / '/ 2.0f'), shared by fn_801F0C68's half();
 * 0.000001f is a named constant defined after fn_801F0A20 (pool_tail), which reads it by name.
 * fn_801F0A20 reads 0.0f through three spellings (sqrtOrZero0/1/2) so each length() reloads it as a
 * literal would.  The tables' __sinit needs common-subexpression elimination off (was -opt nocse). */
namespace pool_head {
extern "C" {
extern const float lbl_8037A6C8 = 10001.0f;
extern const float lbl_8037A6CC = 1.0f;
extern const float lbl_8037A6D0 = 0.0f;
extern const float lbl_8037A6D4 = -1.0f;
}
}

extern "C" {
extern const float lbl_8037A6C8; /* 10001.0f */
extern const float lbl_8037A6CC; /* 1.0f */
extern const float lbl_8037A6D0; /* 0.0f */
extern const float lbl_8037A6D4; /* -1.0f */
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
    Vec3 half() const { return Vec3(x / 2.0f, y / 2.0f, z / 2.0f); }
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

namespace p0A20 {
inline float sqrtOrZero0(register float sq)
{
    register float r = lbl_8037A6D0;
    if (sq != r) {
        asm { frsqrte f4, sq
              fres r, f4 }
    }
    return r;
}
inline float sqrtOrZero1(register float sq)
{
    register float r = *(const float*)&lbl_8037A6D0;
    if (sq != r) {
        asm { frsqrte f4, sq
              fres r, f4 }
    }
    return r;
}
inline float sqrtOrZero2(register float sq)
{
    register float r = *(const float*)(unsigned long)&lbl_8037A6D0;
    if (sq != r) {
        asm { frsqrte f4, sq
              fres r, f4 }
    }
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator*(float s) const { Vec3 r; r.x = x * s; r.y = y * s; r.z = z * s; return r; }
    Vec3 operator/(float s) const { float inv = lbl_8037A6CC / s; Vec3 r; r.x = x * inv; r.y = y * inv; r.z = z * inv; return r; }
    float dot() const { return x * x + y * y + z * z; }
    float length0() const { return sqrtOrZero0(dot()); }
    float length1() const { return sqrtOrZero1(dot()); }
    float length2() const { return sqrtOrZero2(dot()); }
};

struct Sphere {
    Vec3 center;
    float radius;
    Sphere() {}
    Sphere(const Vec3& c, float r) : center(c), radius(r) {}
    Sphere(const Sphere& o) : center(o.center), radius(o.radius) {}
    Sphere& operator=(const Sphere& o) { center = o.center; radius = o.radius; return *this; }
};

extern "C" Sphere fn_801F0A20(const Sphere& a, const Sphere& b)
{
    Sphere result;
    Vec3 d = b.center - a.center;
    float dist = d.length0();
    if (dist > lbl_8037A6DC) {
        Vec3 dir = d / dist;
        Vec3 farB = b.center + dir * b.radius;
        Vec3 farA = a.center - dir * a.radius;
        if ((farB - a.center).length1() < a.radius) {
            result = a;
        } else if ((farA - b.center).length2() < b.radius) {
            result = b;
        } else {
            float reach = dist;
            reach += b.radius;
            result = Sphere((farB + farA) * 0.5f, (a.radius + reach) / 2.0f);
        }
    } else {
        result = Sphere(a.center, fn_800AA52C(b.radius, a.radius));
    }
    return result;
}
}

namespace pool_tail {
extern "C" {
extern const float lbl_8037A6DC = 0.000001f;
}
}

extern "C" void fn_801F0C68(Sphere* out, const Vec3* points, int count)
{
    Vec3 high = points[0];
    Vec3 low = points[0];
    Vec3* hp = &high;
    int i;
    for (i = 1; i < count; i++) {
        low.x = fn_800AA53C(low.x, points[i].x);
        low.y = fn_800AA53C(low.y, points[i].y);
        low.z = fn_800AA53C(low.z, points[i].z);
        hp->x = fn_800AA52C(hp->x, points[i].x);
        hp->y = fn_800AA52C(hp->y, points[i].y);
        hp->z = fn_800AA52C(hp->z, points[i].z);
    }
    out->center = (high + low).half();
    float best = (out->center - points[0]).dot();
    for (i = 1; i < count; i++) {
        best = fn_800AA52C(best, (out->center - points[i]).dot());
    }
    out->radius = sqrtOrZero(best, lbl_8037A6D0);
}

#pragma opt_common_subs off
struct EngineCubePoint3 {
    float x, y, z;
    EngineCubePoint3(float a, float b, float c) : x(a), y(b), z(c) {}
};

EngineCubePoint3 lbl_80340AC0[8] = {
    EngineCubePoint3(lbl_8037A6CC, lbl_8037A6CC, lbl_8037A6CC),
    EngineCubePoint3(lbl_8037A6CC, lbl_8037A6CC, lbl_8037A6D4),
    EngineCubePoint3(lbl_8037A6D4, lbl_8037A6CC, lbl_8037A6D4),
    EngineCubePoint3(lbl_8037A6D4, lbl_8037A6CC, lbl_8037A6CC),
    EngineCubePoint3(lbl_8037A6CC, lbl_8037A6D0, lbl_8037A6CC),
    EngineCubePoint3(lbl_8037A6CC, lbl_8037A6D0, lbl_8037A6D4),
    EngineCubePoint3(lbl_8037A6D4, lbl_8037A6D0, lbl_8037A6D4),
    EngineCubePoint3(lbl_8037A6D4, lbl_8037A6D0, lbl_8037A6CC)
};

EngineCubePoint3 lbl_80340B20[3] = {
    EngineCubePoint3(lbl_8037A6D0, lbl_8037A6CC, lbl_8037A6D0),
    EngineCubePoint3(lbl_8037A6CC, lbl_8037A6D0, lbl_8037A6D0),
    EngineCubePoint3(lbl_8037A6D0, lbl_8037A6D0, lbl_8037A6CC)
};
