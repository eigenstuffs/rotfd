/* fn_801DD9E0 alone (tail of auto_03_801DCCE8_text, 0x801DD9E0..0x801DDB3C):
   transform a segment by a matrix (start with translation, direction by the
   3x3 part), renormalise the direction and scale length and radius by the
   direction's length.  EXACT with GC/1.3.2 -O4,p -Cpp_exceptions off (flags
   of collision_capsule_query_801DDB3C.cpp).  For a partial split; fn_801DCCE8
   (0x801DCCE8..0x801DD9E0) stays original code.
   Load-bearing details: `float dx;` declared at the top but assigned just
   before the direction transform; normalising through Vec3::operator/=,
   which holds `inv` as its own local, scales y/z in place and rebuilds x
   through a Vec3 temporary. */
typedef unsigned long long Mask;

extern "C" {
void* memset(void*, int, unsigned long);
extern const float lbl_8037A4E0;
extern const float lbl_8037A4E4;
extern const float lbl_8037A4E8;
extern const double lbl_8037A4F0;
}

#define ZERO_Q (*(const float*)&lbl_8037A4E0)
#define ONE_Q (*(const float*)&lbl_8037A4E4)
#define EPS_Q (*(const float*)&lbl_8037A4E8)
#define EPS_R (*(const float*)(unsigned long)&lbl_8037A4E8)

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
    Vec3& operator/=(float s) { float inv = lbl_8037A4E4 / s; y *= inv; z *= inv; x = Vec3(x * inv, y, z).x; return *this; }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    Vec3 cross(const Vec3& v) const
    {
        return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }
    float lengthSq() const { return x * x + y * y + z * z; }
    float length() const
    {
        float sq = lengthSq();
        float r = ZERO_Q;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    float distanceSq(const Vec3& v) const
    {
        float dx = x - v.x;
        float dy = y - v.y;
        float dz = z - v.z;
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

struct Matrix {
    float m[16];
    void identity()
    {
        memset(this, 0, sizeof(*this));
        m[0] = lbl_8037A4E4;
        m[5] = lbl_8037A4E4;
        m[10] = lbl_8037A4E4;
        m[15] = lbl_8037A4E4;
    }
    Vec3 transform(const Vec3& v) const
    {
        Vec3 r;
        r.x = m[12] + (m[0] * v.x + m[4] * v.y + m[8] * v.z);
        r.y = m[13] + (m[1] * v.x + m[5] * v.y + m[9] * v.z);
        r.z = m[14] + (m[2] * v.x + m[6] * v.y + m[10] * v.z);
        return r;
    }
    Vec3 rotate(const Vec3& v) const
    {
        Vec3 r;
        r.x = m[0] * v.x + m[4] * v.y + m[8] * v.z;
        r.y = m[1] * v.x + m[5] * v.y + m[9] * v.z;
        r.z = m[2] * v.x + m[6] * v.y + m[10] * v.z;
        return r;
    }
};

struct Segment {
    Vec3 start;
    float length;
    Vec3 direction;
    float radius;
    Segment() {}
    Segment(const Segment& s) : start(s.start), length(s.length), direction(s.direction), radius(s.radius) {}
    Segment& operator=(const Segment& s)
    {
        start = s.start;
        length = s.length;
        direction = s.direction;
        radius = s.radius;
        return *this;
    }
};

/* @@FN_801DD9E0@@ */
extern "C" Segment fn_801DD9E0(const Matrix& matrix, const Segment& in)
{
    Segment out;
    Vec3 r;
    Vec3 d;
    float dx;
    float m6 = matrix.m[6];
    r.x = matrix.m[12] + (matrix.m[0] * in.start.x + matrix.m[4] * in.start.y + matrix.m[8] * in.start.z);
    r.y = matrix.m[13] + (matrix.m[1] * in.start.x + matrix.m[5] * in.start.y + matrix.m[9] * in.start.z);
    r.z = matrix.m[14] + (matrix.m[2] * in.start.x + m6 * in.start.y + matrix.m[10] * in.start.z);
    out.start = r;
    dx = in.direction.x;
    d.x = matrix.m[0] * dx + matrix.m[4] * in.direction.y + matrix.m[8] * in.direction.z;
    d.y = matrix.m[1] * dx + matrix.m[5] * in.direction.y + matrix.m[9] * in.direction.z;
    d.z = matrix.m[2] * dx + m6 * in.direction.y + matrix.m[10] * in.direction.z;
    float length = d.length();
    out.length = length * in.length;
    d /= length;
    out.direction = d;
    out.radius = in.radius * length;
    return out;
}
/* @@END@@ */

