/* Early actor motion step: unless control state 5 or 6 is active, integrate
 * the velocity at +0x15C with force/mass (+0x358 / +0x354) over the frame
 * delta, clamp the result's length to the speed limit at +0x374 and store it
 * at +0x144 (other views call that field the position); in states 5 and 6 the
 * field is zeroed.
 *
 * Matching notes: the Vec3 needs a user-declared member-wise copy constructor
 * (it decides the x/z register assignment of the integration). The scaled
 * force temporary and the clamp's `v * maxSpeed` temporary are left as dead
 * stack stores because inline operators are called on them. The original
 * divided by a pooled 1.0f literal that is reloaded for each division; the
 * volatile read of the shared label keeps the second load (see
 * facing_angle_query_80058350.cpp for the same idiom). */
extern "C" const float lbl_80378C8C; /* 0.0f */
extern "C" const float lbl_80378C90; /* 1.0f */

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
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator/(float divisor) const
    {
        float reciprocal = *(const volatile float*)&lbl_80378C90 / divisor;
        return Vec3(x * reciprocal, y * reciprocal, z * reciprocal);
    }
    Vec3 operator*(float scale) const { return Vec3(x * scale, y * scale, z * scale); }
    Vec3 operator+(const Vec3& other) const { return Vec3(x + other.x, y + other.y, z + other.z); }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_80378C8C;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

struct Actor {
    char unknown00[0x144];
    Vec3 motion;
    char unknown150[0xC];
    Vec3 velocity;
    char unknown168[0x318 - 0x168];
    char control;
    char unknown319[0x354 - 0x319];
    float mass;
    Vec3 force;
    char unknown364[0x374 - 0x364];
    float maxSpeed;
};

extern "C" signed char fn_8007D604(void*, int);

extern "C" void fn_80096FC8(Actor* self, float delta)
{
    if (fn_8007D604(&self->control, 5) || fn_8007D604(&self->control, 6)) {
        self->motion = Vec3(lbl_80378C8C, lbl_80378C8C, lbl_80378C8C);
    } else {
        Vec3 v = self->velocity + self->force / self->mass * delta;
        float len = v.length();
        if (len > self->maxSpeed) v = v * self->maxSpeed / len;
        self->motion = v;
    }
}
