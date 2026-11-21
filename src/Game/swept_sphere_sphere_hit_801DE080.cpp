// Partial text split: fn_801DE080 (swept sphere vs sphere). The following
// ray/torus quartic setup fn_801DE350 (90.8%) remains original code; full
// draft: scratch/claude_match/auto_03_801DE080_text/final.cpp.
typedef unsigned long long Mask;

extern "C" {
extern const float lbl_8037A4E0;
extern const float lbl_8037A4E4;
extern const float lbl_8037A4E8;
extern const float lbl_8037A4F8;
extern const float lbl_8037A4FC;
extern const double lbl_8037A500;
int fn_801DE498(const double*, double*);
}

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float reciprocalSqrt(register float x)
{
    register float r;
    asm { frsqrte r, x }
    return r;
}

inline float sqrtOrZero(float sq)
{
    float r = lbl_8037A4E0;
    if (sq != r) r = fastSqrt(sq);
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3& operator=(const Vec3& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    float lengthSq() const { return x * x + y * y + z * z; }
    float distanceSq(const Vec3& v) const
    {
        float dz = z - v.z;
        float dy = y - v.y;
        float dx = x - v.x;
        return dx * dx + dy * dy + dz * dz;
    }
    Vec3& normalize()
    {
        float s = reciprocalSqrt(lengthSq());
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
};

struct Segment {
    Vec3 start;
    float length;
    Vec3 direction;
    float radius;
};

struct Sphere {
    Vec3 center;
    float radius;
};

struct Result {
    Vec3 point;
    float distance;
    Vec3 normal;
    char unknown1C[12];
    Mask flags;
    char unknown30[12];
    signed char valid;
};

extern "C" int fn_801DE080(const Segment* seg, const Sphere* sphere, Result* out, Mask flags)
{
    Vec3 d(sphere->center.x - seg->start.x, sphere->center.y - seg->start.y, sphere->center.z - seg->start.z);
    float t = d.dot(seg->direction);
    if (t < lbl_8037A4E8)
        return 0;
    float distSq = (seg->direction * t + seg->start).distanceSq(sphere->center);
    float rSq = sphere->radius + seg->radius;
    rSq *= rSq;
    if (distSq > rSq)
        return 0;
    float dSq = d.lengthSq();
    if (dSq < rSq) {
        out->valid = 1;
        out->flags = flags;
        out->point = seg->start;
        float zero = lbl_8037A4E0;
        out->distance = zero;
        if (dSq != zero) {
            out->normal = (-d).normalize();
        } else {
            out->normal = Vec3(lbl_8037A4E0, lbl_8037A4E4, lbl_8037A4E0);
        }
        return 1;
    }
    float hitDist = t - sqrtOrZero(rSq - distSq);
    if (hitDist < seg->length && (!out->valid || hitDist < out->distance)) {
        out->valid = 1;
        out->flags = flags;
        out->point = seg->direction * hitDist + seg->start;
        out->distance = hitDist;
        out->normal = (out->point - sphere->center).normalize();
        return 1;
    }
    return 0;
}

