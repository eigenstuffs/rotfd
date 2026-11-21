/* fn_8024F9D8: distance between two lines (origin + direction); falls back to
 * the point-to-line distance when the directions are parallel.
 *
 * Original translation unit: fn_8024EB80 + fn_8024F9D8 with the .sdata2 pool
 * 0x8037B4A0..0x8037B4C8 (0.5, 0.0, 1.0, 3.0, 6.0, pad, int->float bias,
 * (double)1e-6f).  fn_8024EB80 is not matched, so this source references the
 * three constants it uses as the original extern labels (lbl_8037B4A4 and
 * lbl_8037B4A8 are shared with fn_8024EB80); it owns no data and is suitable
 * for a text-only split 0x8024F9D8..0x8024FB24.
 *
 * Matching notes: the user-written Vec3 copy constructor fixes the colouring
 * of the cross product, and the reciprocal must come from an inline helper
 * with a named local (`float r = 1 / x; return r;`) so that it is coloured
 * between the cross product and the difference vector.  The parallel branch
 * needs the 4-float vector temporary (w = 0) for its stack layout. */
extern "C" const float lbl_8037B4A4;  /* 0.0f */
extern "C" const float lbl_8037B4A8;  /* 1.0f */
extern "C" const double lbl_8037B4C0; /* (double)1e-6f */

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    Vec3 cross(const Vec3& v) const { return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_8037B4A4;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float a, float b, float c) : x(a), y(b), z(c), w(lbl_8037B4A4) {}
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_8037B4A4;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

inline float reciprocal(float x)
{
    float r = lbl_8037B4A8 / x;
    return r;
}

struct Line {
    Vec3 origin;
    float weight;
    Vec3 dir;
    float pad;
};

extern "C" float fn_8024F9D8(const Line* a, const Line* b)
{
    Vec3 c = b->dir.cross(a->dir);
    float len = c.length();
    if (__fabs(len) < lbl_8037B4C0) {
        Vec3 d = b->origin - a->origin;
        Vec3 p = d - a->dir * d.dot(a->dir);
        return Vec4(p.x, p.y, p.z).length();
    }
    Vec3 n = c * reciprocal(len);
    return (b->origin - a->origin).dot(n);
}
