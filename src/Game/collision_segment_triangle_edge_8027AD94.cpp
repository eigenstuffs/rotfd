// Partial text split: fn_8027AD94 (segment vs triangle) and fn_8027B140
// (sphere vs segment edge). fn_8027A410 (99.3%) and fn_8027AA38 (95.8%)
// before them remain original code; full draft:
// scratch/claude_match/auto_03_80279558_text/retry2/final_8027A410.cpp.
/* auto_03_80279558_text (0x80279558..0x8027B2E4): collision primitive
   queries of one engine translation unit -- segment vs grid quad
   (fn_80279558), capsule vs triangle with a precomputed plane (fn_80279D64),
   sphere vs triangle with a precomputed plane (fn_8027A180), capsule vs
   triangle (fn_8027A410), sphere vs triangle (fn_8027AA38), segment vs
   triangle (fn_8027AD94) and sphere vs segment edge (fn_8027B140).
   This file holds: fn_8027AD94, fn_8027B140.
   GC/1.3.2, -O4,p, fp_contract on, C++ without exceptions (no extab); the
   unit owns no data.  The float literals are the pooled labels
   lbl_8037B740..lbl_8037B754 owned by Game/render_transform_constants.c.
   Each function keeps its own private struct views in a namespace (the
   functions are extern "C", so the namespaces do not change symbol names);
   fn_8027B140 is declared once with the nsB140 types and callers cast.
   The K* spellings are distinct read forms of one extern label
   (pooled-literal emulation, scratch/claude_match/GUIDE.md). */
namespace nsB140 { struct Sphere; struct Vertex; struct Hit; }
extern "C" signed char fn_8027B140(const nsB140::Sphere* sphere, const nsB140::Vertex* a, const nsB140::Vertex* b, nsB140::Hit* out);

namespace nsAD94 {
extern "C" {
extern const float lbl_8037B740; /* -1.0f */
extern const float lbl_8037B744; /* 0.0f */
extern const float lbl_8037B748; /* 0.999f */
extern const float lbl_8037B74C; /* 1.0f */
extern const float lbl_8037B750; /* 1.0e-6f */
extern const float lbl_8037B754; /* -1.0e-4f */
}

#define K0(l) (l)
#define K1(l) (*(const float*)&(l))
#define K2(l) (*(const float*)(unsigned long)&(l))
#define K3(l) (*(const float*)(long)&(l))
#define K4(l) (*(const float*)(unsigned int)&(l))
#define K5(l) (*(const float*)(int)&(l))

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float sqrtOrZero(float sq) { float r = K2(lbl_8037B744); if (sq != r) r = fastSqrt(sq); return r; }
inline float clampf2(float v, float lo, float hi) { if (v < lo) v = lo; else if (v > hi) v = hi; return v; }
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 operator+(const Vec3& r) const { return Vec3(x + r.x, y + r.y, z + r.z); }
    Vec3 operator-(const Vec3& r) const { return Vec3(x - r.x, y - r.y, z - r.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 operator/(float s) const { float inv = lbl_8037B74C / s; return Vec3(x * inv, y * inv, z * inv); }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    /* normal passed as scalars, last component first: sets the order of the
       normal CSE temps (FPR colouring) */
    float dot3r(float Z, float Y, float X) const { return x * X + y * Y + z * Z; }
    float lengthSq() const { float xx = x * x; float yy = y * y; float zz = z * z; return xx + yy + zz; }
    float magnitude() const { float sq = x * x + y * y + z * z; float r = lbl_8037B744; if (sq != r) r = fastSqrt(sq); return r; }
    float length() const { float sq = lengthSq(); float r = K2(lbl_8037B744); if (sq != r) r = fastSqrt(sq); return r; }
};

struct Vertex : Vec3 {
    float w;
    Vertex() {}
    Vertex(float X, float Y, float Z, float W) : Vec3(X, Y, Z), w(W) {}
};
inline Vertex cross(const Vec3& a, const Vec3& b) { return Vertex(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, lbl_8037B74C); }
struct Query {
    Vec3 position;
    float distance;
    Vec3 direction;
    float unknown1C;
};

struct Sphere {
    Vec3 center;
    float radius;
};

struct Hit {
    Vec3 point;
    float distance;
    Vec3 normal;
    unsigned long unknown1C;
    float unknown20, unknown24;
    unsigned long long unknown28;
};

extern "C" signed char fn_8027AD94(const Query* self, const Vertex* a, const Vertex* b, const Vertex* c, Hit* out)
{
    out->normal.x = a->y * (b->z - c->z) + b->y * (c->z - a->z) + c->y * (a->z - b->z);
    out->normal.y = a->z * (b->x - c->x) + b->z * (c->x - a->x) + c->z * (a->x - b->x);
    out->normal.z = a->x * (b->y - c->y) + b->x * (c->y - a->y) + c->x * (a->y - b->y);
    float length = out->normal.length();
    if (length <= lbl_8037B750) return 0;
    float inverse = lbl_8037B74C / length;
    out->normal.x *= inverse;
    out->normal.y *= inverse;
    out->normal.z *= inverse;
    float plane = -out->normal.dot(*a);
    float side = plane + out->normal.dot(self->position);
    if (side <= lbl_8037B744) return 0;
    out->distance = -(side / out->normal.dot(self->direction));
    if (out->distance < lbl_8037B744 || out->distance > self->distance) return 0;
    out->point = self->direction * out->distance + self->position;
    Vec3 av = *a - out->point;
    Vec3 bv = *b - out->point;
    if (cross(av, bv).dot(out->normal) < lbl_8037B754) return 0;
    Vec3 cv = *c - out->point;
    if (cross(bv, cv).dot3r(out->normal.z, out->normal.y, out->normal.x) < K1(lbl_8037B754)) return 0;
    if (cross(cv, av).dot(out->normal) < K2(lbl_8037B754)) return 0;
    return 1;
}

} /* namespace nsAD94 */
#undef K0
#undef K1
#undef K2
#undef K3
#undef K4
#undef K5

namespace nsB140 {
extern "C" {
extern const float lbl_8037B740; /* -1.0f */
extern const float lbl_8037B744; /* 0.0f */
extern const float lbl_8037B748; /* 0.999f */
extern const float lbl_8037B74C; /* 1.0f */
extern const float lbl_8037B750; /* 1.0e-6f */
extern const float lbl_8037B754; /* -1.0e-4f */
}

#define K0(l) (l)
#define K1(l) (*(const float*)&(l))
#define K2(l) (*(const float*)(unsigned long)&(l))
#define K3(l) (*(const float*)(long)&(l))
#define K4(l) (*(const float*)(unsigned int)&(l))
#define K5(l) (*(const float*)(int)&(l))

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float sqrtOrZero(float sq) { float r = K2(lbl_8037B744); if (sq != r) r = fastSqrt(sq); return r; }
/* clamp to [0, hi]; the zero bound is read through two distinct label forms */
inline float clampLH(float v, float hi) { if (v < K1(lbl_8037B744)) v = K2(lbl_8037B744); else if (v > hi) v = hi; return v; }
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 operator+(const Vec3& r) const { return Vec3(x + r.x, y + r.y, z + r.z); }
    Vec3 operator-(const Vec3& r) const { return Vec3(x - r.x, y - r.y, z - r.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 operator/(float s) const { float inv = lbl_8037B74C / s; return Vec3(x * inv, y * inv, z * inv); }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    float lengthSq() const { float xx = x * x; float yy = y * y; float zz = z * z; return xx + yy + zz; }
    Vec3& operator/=(float s) { float inv = lbl_8037B74C / s; x *= inv; y *= inv; z *= inv; return *this; }
    float magnitude() const { float sq = x * x + y * y + z * z; float r = lbl_8037B744; if (sq != r) r = fastSqrt(sq); return r; }
    float length() const { float sq = lengthSq(); float r = K2(lbl_8037B744); if (sq != r) r = fastSqrt(sq); return r; }
};

struct Vertex : Vec3 {
    float w;
};

struct Sphere {
    Vec3 center;
    float radius;
};

struct Hit {
    Vec3 point;
    float distance;
    Vec3 normal;
    unsigned long unknown1C;
    float unknown20, unknown24;
    unsigned long long unknown28;
};

extern "C" signed char fn_8027B140(const Sphere* sphere, const Vertex* a, const Vertex* b, Hit* out)
{
    Vec3 d = *b - *a;
    float len = d.magnitude();
    Vec3 v = sphere->center - *a;
    d /= len;
    float t = v.dot(d);
    t = clampLH(t, len);
    Vec3 p = *a + d * t;
    float dist = sqrtOrZero((p - sphere->center).lengthSq());
    Vec3 n = (sphere->center - p) * (K1(lbl_8037B74C) / dist);
    if (dist < sphere->radius) {
        Hit hit;
        hit.distance = dist;
        hit.point = p;
        hit.normal = n;
        *out = hit;
        return 1;
    }
    return 0;
}

} /* namespace nsB140 */
#undef K0
#undef K1
#undef K2
#undef K3
#undef K4
#undef K5
