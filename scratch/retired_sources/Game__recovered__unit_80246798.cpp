/* fn_80246798: composite node bounds refresh -- merges every attached
 * primitive (spheres, capsules, matrix shapes) into the node bounds.
 *
 * The capsule -> bounding sphere conversion is register- and stack-layout
 * sensitive; what matters is the inline nesting depth of each piece (the
 * compiler creates inline temporaries breadth-first, and colours them in
 * creation order):
 *   - "edge" (pos + (0,0,radius)) and the difference are built by operators
 *     called directly from the Sphere constructor;
 *   - the fast square root (with its zero-initialised result) is also called
 *     directly from the constructor, not through Vec3::length();
 *   - the centre goes through one wrapper (Capsule::mid -> addScaled);
 *   - the axis goes through two (Capsule::axis -> scaledDir -> operator*),
 *     while its temporary still belongs to the constructor (const Vec3& half).
 *
 * 0.0f / 0.5f are pooled literals of the original translation unit
 * (lbl_8037B3E0 / lbl_8037B3E4). Define BOUNDS_POOLED_LITERALS to build with
 * real literals (EXACT-MOD-POOL, 8 pool refs); the default references the
 * existing labels, with the casts keeping the three zero uses separate loads
 * for the front end exactly as literals are (EXACT). */
#pragma inline_max_size(1024)

#ifdef BOUNDS_POOLED_LITERALS
#define BOUNDS_ZERO_A 0.0f
#define BOUNDS_ZERO_B 0.0f
#define BOUNDS_ZERO_C 0.0f
#define BOUNDS_HALF 0.5f
#else
extern "C" const float lbl_8037B3E0; /* 0.0f */
extern "C" const float lbl_8037B3E4; /* 0.5f */
#define BOUNDS_ZERO_A lbl_8037B3E0
#define BOUNDS_ZERO_B (*(const float*)&lbl_8037B3E0)
#define BOUNDS_ZERO_C (*(const float*)(unsigned long)&lbl_8037B3E0)
#define BOUNDS_HALF lbl_8037B3E4
#endif

inline float fastSqrt(register float x)
{
    register float r = BOUNDS_ZERO_C;
    if (x != r) {
        asm { frsqrte f4, x
              fres r, f4 }
    }
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 addScaled(const Vec3& v, float s) const { return Vec3(x + v.x * s, y + v.y * s, z + v.z * s); }
    float lengthSquared() const { return x * x + y * y + z * z; }
};

struct Capsule {
    Vec3 pos;
    float length;
    Vec3 dir;
    float unknown1C;
    float radius;
    Vec3 scaledDir(float s) const { return dir * s; }
    Vec3 axis() const { return scaledDir(length); }
    Vec3 mid(const Vec3& half) const { return pos.addScaled(half, BOUNDS_HALF); }
};

struct Sphere {
    Vec3 center;
    float r;
    Sphere() {}
    Sphere(const Capsule& c)
    {
        const Vec3& half = c.axis();
        center = c.mid(half);
        const Vec3& d = (c.pos + Vec3(BOUNDS_ZERO_A, BOUNDS_ZERO_B, c.radius)) - center;
        r = fastSqrt(d.lengthSquared());
    }
    Sphere& operator=(const Sphere& o)
    {
        center.x = o.center.x;
        center.y = o.center.y;
        center.z = o.center.z;
        r = o.r;
        return *this;
    }
};

struct Node {
    char unknown00[0xC];
    Sphere bounds;
    char unknown1C[0x70 - 0x1C];
    Sphere* extra70;
    Sphere* a0;
    Sphere* a1;
    Capsule* a2;
    void* a3;
    Sphere* b0;
    Capsule* b1;
    void* b2;
    Sphere* c0;
    Capsule* c1;
    void* c2;
    Sphere* d0;
    Capsule* d1;
    void* d2;
    Sphere* extraA8;
    Sphere* sphere() { return &bounds; }
};

extern "C" {
Sphere fn_801F0A20(const Sphere&, const Sphere&);
Sphere fn_80246E14(const Sphere&, const void*);
}

inline Sphere merge(const Sphere& a, const Capsule& c)
{
    return fn_801F0A20(a, Sphere(c));
}

extern "C" void fn_80246798(Node* self)
{
    Sphere* bounds = self->sphere();
    if (self->a0) *bounds = fn_801F0A20(*bounds, *self->a0);
    if (self->a1) *bounds = fn_801F0A20(*bounds, *self->a1);
    if (self->a2) *bounds = merge(*bounds, *self->a2);
    if (self->a3) *bounds = fn_80246E14(*bounds, self->a3);
    if (self->c0) *bounds = fn_801F0A20(*bounds, *self->c0);
    if (self->c1) *bounds = merge(*bounds, *self->c1);
    if (self->c2) *bounds = fn_80246E14(*bounds, self->c2);
    if (self->b0) *bounds = fn_801F0A20(*bounds, *self->b0);
    if (self->b1) *bounds = merge(*bounds, *self->b1);
    if (self->b2) *bounds = fn_80246E14(*bounds, self->b2);
    if (self->d0) *bounds = fn_801F0A20(*bounds, *self->d0);
    if (self->d1) *bounds = merge(*bounds, *self->d1);
    if (self->d2) *bounds = fn_80246E14(*bounds, self->d2);
    if (self->extraA8) *bounds = fn_801F0A20(*bounds, *self->extraA8);
    if (self->extra70) *bounds = fn_801F0A20(*bounds, *self->extra70);
}
