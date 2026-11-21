/* Distance between the matrix positions of two owners (fn_80066DA4).
   The engine square root is the bare reciprocal of a reciprocal-square-root
   estimate (frsqrte into f4, then fres, with no frsp), which no compiler
   built-in produces; it is written as a minimal inline asm statement in the
   math helper. */
extern "C" const float lbl_80378778;

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
    float distance(const Vec3& o) const
    {
        float dz = z - o.z;
        float dy = y - o.y;
        float dx = x - o.x;
        float sq = dx * dx + dy * dy + dz * dz;
        float r = lbl_80378778;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

struct Matrix {
    float m[16];
    Vec3 getPos() const { return Vec3(m[12], m[13], m[14]); }
};

struct Owner {
    char unknown00[0x124];
    Matrix* matrix;
    Vec3 getPos() const { return matrix->getPos(); }
};

extern "C" float fn_80066DA4(void* self, Owner* a, Owner* b)
{
    return b->getPos().distance(a->getPos());
}
