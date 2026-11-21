/* Actor velocity integration (fn_80099CB4): adds a planar drag of -0.1 times
   the current velocity (0x15C) to the accumulated force (0x358; the y term is
   the pooled 0.0f), lets the virtual slot 0x18C contribute unless flag bit
   0x8000000000 is set, then integrates velocity + force / mass (0x354) *
   delta, clamps its length to the maximum speed (0x370) and stores the
   result at 0x144.

   Matching notes: the original TU used pooled literals (lbl_80378D10 = 0.0f,
   lbl_80378D14 = 0.1f, lbl_80378D1C = 1.0f); the literal source is
   `Vec3 d = -velocity * 0.1f; d.y = 0.0f; force += d;` (see literal.cpp,
   EXACT-DATA). With the shared labels the literal loads are emulated:
   - the drag scale is read at each live multiply (x, z) with distinct read
     forms inside a member of the negated temporary (dragScaled), and the
     0.0f is read at the y add;
   - the two 1.0f reciprocals (force / mass, clamp) use distinct read forms
     (operator/ and divide) so the second is reloaded inside the clamp.
   The dead stack stores (negated velocity at 0x20, force / mass at 0x14,
   v * maxSpeed at 0x8) come from temporaries used as the object of inline
   members (dragScaled, operator* and divide with their locals). The engine
   square root is the established frsqrte/fres inline helper. */
extern "C" const float lbl_80378D10; /* 0.0f */
extern "C" const float lbl_80378D14; /* 0.1f */
extern "C" const float lbl_80378D1C; /* 1.0f */

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
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    Vec3 operator*(float s) const { float t = s; return Vec3(x * t, y * t, z * t); }
    Vec3 operator/(float s) const { float inv = lbl_80378D1C / s; return Vec3(x * inv, y * inv, z * inv); }
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 divide(float s) const { float inv = *(const float*)&lbl_80378D1C / s; return Vec3(x * inv, y * inv, z * inv); }
    Vec3 dragScaled() const
    {
        return Vec3(x * lbl_80378D14, y * *(const float*)&lbl_80378D14,
                    z * *(const float*)(unsigned long)&lbl_80378D14);
    }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_80378D10;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

struct Prefix { char unknown00[8]; };
struct Node : Prefix {
    virtual void slot8();
    virtual void slotC();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual void slotAC();
    virtual void slotB0();
    virtual void slotB4();
    virtual void slotB8();
    virtual void slotBC();
    virtual void slotC0();
    virtual void slotC4();
    virtual void slotC8();
    virtual void slotCC();
    virtual void slotD0();
    virtual void slotD4();
    virtual void slotD8();
    virtual void slotDC();
    virtual void slotE0();
    virtual void slotE4();
    virtual void slotE8();
    virtual void slotEC();
    virtual void slotF0();
    virtual void slotF4();
    virtual void slotF8();
    virtual void slotFC();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10C();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11C();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12C();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13C();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14C();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15C();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16C();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17C();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void applyForces();
    char unknown0C[0x30 - 0xC];
    unsigned long long flags;
    char unknown38[0x144 - 0x38];
    Vec3 position;
    char unknown150[0x15C - 0x150];
    Vec3 velocity;
    char unknown168[0x354 - 0x168];
    float mass;
    Vec3 force;
    char unknown364[0x370 - 0x364];
    float maxSpeed;
};

extern "C" void fn_80099CB4(Node* self, float delta)
{
    Vec3 drag = (-self->velocity).dragScaled();
    self->force.x += drag.x;
    self->force.y += lbl_80378D10;
    self->force.z += drag.z;
    if (!(self->flags & 0x8000000000ULL)) self->applyForces();
    Vec3 v = self->velocity + self->force / self->mass * delta;
    float len = v.length();
    if (len > self->maxSpeed) v = (v * self->maxSpeed).divide(len);
    self->position = v;
}
