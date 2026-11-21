/* fn_80099A00: transforms a bounding sphere by a 4x4 matrix (row-vector
   convention, translation in row 3). The radius is the length of the
   rotated vector (0, 0, radius) (engine square root: frsqrte into f4, then
   fres, as in record_object_space_transform_801DC5E8.cpp); the centre is
   transformed through the full matrix. Returns the sphere through the
   hidden result pointer (r3); r4 = matrix, r5 = source sphere.

   Matching notes: lbl_80378D10 is the pooled 0.0f shared with the rest of
   the original TU; the two zero components of the rotated vector use the
   distinct read forms of the label so they behave like separate pooled
   literals (the backend merges them into the single load). The rotated
   and transformed vectors are built member-wise in named Vec3 locals, and
   the centre's y component is read into a float local before the
   transform; these reproduce the original FPR colouring, including the four
   saved FPRs (f28-f31) recorded in the exception table. */
extern "C" const float lbl_80378D10; /* 0.0f */

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
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_80378D10;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

struct Matrix {
    float m[4][4];
};

struct Sphere {
    Vec3 center;
    float radius;
    Sphere() {}
};

extern "C" Sphere fn_80099A00(const Matrix& m, const Sphere& s)
{
    float cy;
    Sphere result;
    Vec3 v(*(const float*)&lbl_80378D10, *(const float*)(unsigned long)&lbl_80378D10, s.radius);
    Vec3 o;
    o.x = m.m[0][0] * v.x + m.m[1][0] * v.y + m.m[2][0] * v.z;
    o.y = m.m[0][1] * v.x + m.m[1][1] * v.y + m.m[2][1] * v.z;
    o.z = m.m[0][2] * v.x + m.m[1][2] * v.y + m.m[2][2] * v.z;
    result.radius = o.length();
    const Vec3& c = s.center;
    cy = c.y;
    Vec3 t;
    t.x = m.m[3][0] + (m.m[0][0] * c.x + m.m[1][0] * cy + m.m[2][0] * c.z);
    t.y = m.m[3][1] + (m.m[0][1] * c.x + m.m[1][1] * cy + m.m[2][1] * c.z);
    t.z = m.m[3][2] + (m.m[0][2] * c.x + m.m[1][2] * cy + m.m[2][2] * c.z);
    result.center = t;
    return result;
}
