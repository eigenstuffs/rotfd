/* Apply the stored motion delta to an actor's position, keeping the height (y) unchanged.
 * Matching notes: the sum is accumulated in a copy of the zero vector and assigned back as a whole
 * Vec3 with y taken from the current position; MWCC removes the redundant y load/store pair late,
 * but the three-store chain is what gives the x chain scheduling priority over the z loads. */
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3& operator+=(const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
};

struct PlanarMotionActor {
    char unknown00[0x144];
    Vec3 pos;
    char unknown150[0x208];
    Vec3 delta;
};

extern "C" Vec3 game_vec3_zero;

extern "C" void fn_8009237C(PlanarMotionActor* self) {
    Vec3 sum = game_vec3_zero;
    sum += self->delta + self->pos;
    sum.y = self->pos.y;
    self->pos = sum;
}
