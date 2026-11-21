/* Planar (X/Z) distance between the matrix positions of two owners
   (fn_80066E08). The flattened Y term survives as an explicit zero addend.
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
    float planarDistance(const Vec3& o) const
    {
        float zero = lbl_80378778;
        float dz = z - o.z;
        float dx = x - o.x;
        float sq = dx * dx + zero + dz * dz;
        float r = zero;
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

extern "C" float fn_80066E08(void* self, Owner* a, Owner* b)
{
    return b->getPos().planarDistance(a->getPos());
}
