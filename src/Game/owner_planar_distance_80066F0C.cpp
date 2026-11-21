/* Horizontal (XZ) distance from a resolved owner to another owner. The
   square root is the engine's reciprocal estimate pair (frsqrte then fres,
   fixed scratch f4, no frsp), written as a minimal inline asm statement in
   the vector helper; the zero literal is the unit's pooled 0.0f. */
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}

    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    float length() const
    {
        register float sq = x * x + y * y + z * z;
        register float result = 0.0f;
        if (sq != result) {
            asm { frsqrte f4, sq }
            asm { fres result, f4 }
        }
        return result;
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

struct Handle { union { unsigned long value; struct { signed int tag : 8; signed int index : 24; } bits; }; };
struct Entry { Owner* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct Manager { int count, capacity; Entry* entries; };
struct Context { char unknown00[0x118]; Manager* manager; };
extern "C" Context lbl_801E9D24;
struct Resource { char unknown00[0x58]; Handle owner; };
inline Owner* resolve(const Handle& h)
{
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    if (e->tag == h.bits.tag) return e->object;
    return 0;
}

extern "C" float fn_80066F0C(void* self, Resource* resource, Owner* other)
{
    Vec3 otherPos = other->getPos();
    Vec3 delta = resolve(resource->owner)->getPos() - otherPos;
    delta.y = 0.0f;
    return delta.length();
}
