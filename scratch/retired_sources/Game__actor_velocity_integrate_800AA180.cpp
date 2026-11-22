/* Actor velocity integration step (fn_800AA180).
 * Skipped while the resolved resource (virtual slot 0x9C) has property bit
 * 0x10000. Without the grounded flag (bit 0x8000000000) calls the gravity
 * virtual (slot 0x18C); otherwise clamps a downward base velocity (+0x15C)
 * to zero and applies contact friction (fn_8009B674). With the bounce flag
 * (bit 0x20000000000) reflects the base velocity about the contact normal
 * (+0x3A4) and scales it by the restitution (+0x3A0). Finally
 * velocity(+0x144) = base + (force(+0x358) / mass(+0x354)) * delta, clamped
 * to the maximum speed (+0x370).
 *
 * Matching notes: hasFlag must use the if/return form (the first flag test
 * materialises a signed char); the reflection copies the base vector through
 * value parameters in y, x, z order and computes 2*dot as its own statement
 * (FPR colouring); the clamp's 1.0f uses a second read form of the pooled
 * label so it is reloaded instead of CSE'd with the mass reciprocal. */
extern "C" {
extern const float lbl_80379000, lbl_80379004, lbl_80379024;
}

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
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator*(float f) const { return Vec3(x * f, y * f, z * f); }
    Vec3 operator/(float f) const { float inverse = lbl_80379004 / f; return Vec3(x * inverse, y * inverse, z * inverse); }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    float lengthSquared() const { return x * x + y * y + z * z; }
    float length() const { float sq = lengthSquared(); float r = lbl_80379000; if (sq != r) r = fastSqrt(sq); return r; }
};

inline Vec3 vec3FromYXZ(float y, float x, float z) { return Vec3(x, y, z); }

struct Handle { signed int tag : 8; signed int index : 24; };
struct Resource { char unknown00[0x120]; unsigned long property; };
struct Entry { Resource* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { char unknown00[8]; Entry* entries; };
struct Context { char unknown00[0x118]; Manager* manager; };
extern "C" Context lbl_801E9D24;
inline Resource* resolveResource(const Handle& h)
{
    int index = h.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.tag ? m->entries[index].object : 0;
}

struct Prefix { char unknown00[8]; };
struct Agent : Prefix {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36();
    virtual const Handle* slot37(int);
    virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
    virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47();
    virtual void slot48(); virtual void slot49(); virtual void slot50(); virtual void slot51();
    virtual void slot52(); virtual void slot53(); virtual void slot54(); virtual void slot55();
    virtual void slot56(); virtual void slot57(); virtual void slot58(); virtual void slot59();
    virtual void slot60(); virtual void slot61(); virtual void slot62(); virtual void slot63();
    virtual void slot64(); virtual void slot65(); virtual void slot66(); virtual void slot67();
    virtual void slot68(); virtual void slot69(); virtual void slot70(); virtual void slot71();
    virtual void slot72(); virtual void slot73(); virtual void slot74(); virtual void slot75();
    virtual void slot76(); virtual void slot77(); virtual void slot78(); virtual void slot79();
    virtual void slot80(); virtual void slot81(); virtual void slot82(); virtual void slot83();
    virtual void slot84(); virtual void slot85(); virtual void slot86(); virtual void slot87();
    virtual void slot88(); virtual void slot89(); virtual void slot90(); virtual void slot91();
    virtual void slot92(); virtual void slot93(); virtual void slot94(); virtual void slot95();
    virtual void slot96();
    virtual void applyGravity();
    char unknown0C[0x24];
    unsigned long long flags;
    char unknown38[0x10C];
    Vec3 velocity;
    char unknown150[0xC];
    Vec3 base;
    char unknown168[0x1EC];
    float mass;
    Vec3 force;
    char unknown364[0xC];
    float maxSpeed;
    char unknown374[0x2C];
    float restitution;
    Vec3 normal;
    signed char hasFlag(unsigned long long mask) const { if (flags & mask) return 1; return 0; }
};

extern "C" void fn_8009B674(Agent*);

extern "C" void fn_800AA180(Agent* self, float delta)
{
    if (!(resolveResource(*self->slot37(0))->property & 0x10000)) {
        if (!self->hasFlag(0x8000000000ULL)) {
            self->applyGravity();
        } else if ((self->flags & 0x8000000000ULL) && self->base.y < lbl_80379000) {
            self->base.y = lbl_80379000;
            fn_8009B674(self);
        } else if (self->flags & 0x8000000000ULL) {
            fn_8009B674(self);
        }
        if (self->flags & 0x20000000000ULL) {
            Vec3 b = vec3FromYXZ(self->base.y, self->base.x, self->base.z);
            float k = b.dot(self->normal);
            k = lbl_80379024 * k;
            Vec3 d = b - self->normal * k;
            self->base = d * self->restitution;
        }
        Vec3 next = self->base + (self->force / self->mass) * delta;
        float len = next.length();
        if (len > self->maxSpeed)
            next = (next * self->maxSpeed) * (*(const float*)&lbl_80379004 / len);
        self->velocity = next;
    }
}
