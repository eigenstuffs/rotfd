extern "C" const float lbl_8037B3C0;
extern "C" const float lbl_8037B3C4;
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
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_8037B3C0;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    Vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    Vec3& operator/=(float s) { float i = lbl_8037B3C4 / s; x *= i; y *= i; z *= i; return *this; }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
};
struct Matrix {
    float m[4][4];
    Vec3 transform(const Vec3& p, const float& m11) const
    {
        float z, x, y;
        x = m[3][0] + (m[0][0] * p.x + m[1][0] * p.y + m[2][0] * p.z);
        y = m[3][1] + (m[0][1] * p.x + m11 * p.y + m[2][1] * p.z);
        z = m[3][2] + (m[0][2] * p.x + m[1][2] * p.y + m[2][2] * p.z);
        return Vec3(x, y, z);
    }
    Vec3 rotateI(const Vec3& p, const float& m11, const float& dy) const
    {
        float x = m[0][0] * p.x + m[1][0] * dy + m[2][0] * p.z;
        float y = m[0][1] * p.x + m11 * dy + m[2][1] * p.z;
        float z = m[0][2] * p.x + m[1][2] * dy + m[2][2] * p.z;
        return Vec3(x, y, z);
    }
    Vec3 rotate(const Vec3& p, const float& m11, const float& dy) const { return rotateI(p,m11,dy); }
};
struct Ray {
    Vec3 origin;
    float maxT;
    Vec3 dir;
    float length;
    Ray() {}
    Ray(const Ray& r) : origin(r.origin), maxT(r.maxT), dir(r.dir), length(r.length) {}
};
extern "C" Ray fn_80245250(const Matrix* mat, const Ray* src)
{
    Ray out;
    /* m[1][1] and dir.y are named locals (lowest virtual registers, m11 declared first):
       this is what the FPR colouring of the original needs. */
    float m11 = mat->m[1][1];
    float dy = src->dir.y;
    out.origin = mat->transform(src->origin, m11);
    out.dir = mat->rotate(src->dir, m11, dy);
    float len = out.dir.length();
    out.maxT = len * src->maxT;
    out.dir /= len;
    return out;
}