/* Places the camera point (0xF4) at a distance along the fast-normalized
   view direction (fn_800784A8) from the raised context position, with the
   vertical part taken from the sine of the pitch at 0x144, and copies it to
   the desired point at 0x118 (fn_800792A0). The fast normalize uses a
   minimal inline asm frsqrte (no Newton step, no frsp), which no compiler
   built-in emits. */
extern "C" const float lbl_8037899C;
extern "C" const float lbl_803789E8;

inline float reciprocalSqrt(register float value)
{
    register float result;
    asm { frsqrte result, value }
    return result;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    float lengthSquared() const { return x * x + y * y + z * z; }
    Vec3& normalize() { float inv = reciprocalSqrt(lengthSquared()); x *= inv; y *= inv; z *= inv; return *this; }
};

struct Camera {
    char unknown00[0xDC];
    float height;
    char unknownE0[0x14];
    Vec3 current;
    char unknown100[0x18];
    Vec3 desired;
    char unknown124[0x20];
    float pitch;
};

extern "C" void fn_80076D98(Camera*, Vec3*);
extern "C" void fn_800784A8(Camera*, Vec3*);
extern "C" float fn_80284FA8(float);

extern "C" void fn_800792A0(Camera* self, float distance)
{
    Vec3 position;
    fn_80076D98(self, &position);
    Vec3 direction;
    fn_800784A8(self, &direction);
    direction.normalize();
    float dx = direction.x;
    float dz = direction.z;
    float s = fn_80284FA8(lbl_803789E8 * self->pitch);
    float h = self->height;
    self->current = position + Vec3(lbl_8037899C, h, lbl_8037899C) + Vec3(dx * distance, s * distance, dz * distance);
    self->desired = self->current;
}
