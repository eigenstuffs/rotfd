/* fn_80230740: resolve a contact against a body record (velocity reflect /
   damp along the contact normal); returns whether the record came to rest. */
/* Own original TU: .text 0x80230740-0x80230958, .sdata2 0x8037B1B8-0x8037B1D0.
   lbl_8037B1B8 (1e-6f) is a named constant defined first (same head constant as
   lbl_8037B188 in tu_8022D618); 0.0f, 2.0f, pad, (double)0.707 are pooled literals. */
namespace pool_head {
extern "C" {
extern const float lbl_8037B1B8 = 9.999999974752427e-07f;
}
}
extern "C" {
extern const float lbl_8037B1B8; /* 1e-6f */
double __fabs(double);
}
inline float fastSqrt(register float x){register float r;asm{frsqrte f4,x
 fres r,f4}return r;}
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator*(float a) const { return Vec3(x * a, y * a, z * a); }
    Vec3& operator-=(const Vec3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
    Vec3& operator*=(float a) { x *= a; y *= a; z *= a; return *this; }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    float lengthSquared() const { return x * x + y * y + z * z; }
    float length() const { float sq = lengthSquared(); float r = 0.0f; if (sq != r) r = fastSqrt(sq); return r; }
};
extern "C" const Vec3 game_vec3_zero;
struct BodyRecord {
    Vec3 velocity;
    Vec3 previous;
    char unknown18[0xC];
    float bounce;
    char unknown28[4];
    float damping;
    float restSpeed;
    char unknown34[4];
    unsigned long long flags;
    char unknown40[0xA8 - 0x40];
};
struct BodyOwner { char unknown000[0x188]; BodyRecord* records; };
struct Contact {
    char unknown00[0x10];
    Vec3 normal;
    char unknown1C[0xC];
    unsigned long long flags;
    int surface;
};
extern "C" void fn_8021FD9C(BodyOwner*, void*, int, int);

extern "C" signed char fn_80230740(BodyOwner* self, Contact* contact, int, int, int index)
{
    BodyRecord* record = &self->records[index];
    float a;
    float x = record->velocity.x;
    float y = record->velocity.y;
    float z = record->velocity.z;
    float length = Vec3(x, y, z).length();
    signed char rest = 0;
    float dot = x * contact->normal.x + y * contact->normal.y + z * contact->normal.z;
    if (dot < lbl_8037B1B8) {
        Vec3 d = contact->normal * (2.0f * dot);
        Vec3 v(x, y, z); v -= d; x = v.x; y = v.y; z = v.z;
    }
    if (contact->normal.y < 0.707 || (contact->flags & 0x80000000000ULL)) {
        if (length < record->restSpeed) { x *= record->damping; y *= record->damping; z *= record->damping; }
        if ((float)__fabs(record->damping) <= lbl_8037B1B8) rest = 1;
        else rest = 0;
    } else {
        if (length < record->restSpeed || (a = __fabs(record->bounce), a <= lbl_8037B1B8)) rest = 1;
        else { float b = record->bounce; x *= b; y *= b; z *= b; }
    }
    if (rest) {
        if (!(contact->flags & 0x80000000000ULL))
            fn_8021FD9C(self, (char*)record + 0x40, contact->surface, 0);
        record->flags &= ~0x400ULL;
        record->flags |= 0x80;
        record->velocity = game_vec3_zero;
        record->previous = record->velocity;
    } else {
        record->velocity.x = x;
        record->velocity.y = y;
        record->velocity.z = z;
    }
    return rest;
}
