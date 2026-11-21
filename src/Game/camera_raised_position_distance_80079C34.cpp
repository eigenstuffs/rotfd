/* Distance from the camera point at 0xF4 to the context position
   (fn_80076D98) raised by the height at 0xDC (fn_80079C34). The engine
   square root is the bare reciprocal of a reciprocal-square-root estimate
   (frsqrte into f4, then fres, with no frsp), which no compiler built-in
   produces; it is written as a minimal inline asm statement in the math
   helper. */
extern "C" const float lbl_8037899C;

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
    Vec3 operator+(const Vec3& o) const { Vec3 r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
    float distance(const Vec3& o) const
    {
        float dz = z - o.z;
        float dy = y - o.y;
        float dx = x - o.x;
        float sq = dx * dx + dy * dy + dz * dz;
        float r = lbl_8037899C;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

struct Camera {
    char unknown00[0xDC];
    float height;
    char unknownE0[0x14];
    Vec3 current;
};

extern "C" void fn_80076D98(Camera*, Vec3*);

extern "C" float fn_80079C34(Camera* self)
{
    Vec3 position;
    fn_80076D98(self, &position);
    return self->current.distance(position + Vec3(lbl_8037899C, self->height, lbl_8037899C));
}
