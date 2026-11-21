/* Horizontal (XZ) distance between the matrix positions of the objects two
   resources' owner handles resolve to (fn_8005ED34); the planar sibling of
   handle_owner_position_distance_8005EC4C.cpp.
   The engine square root is the bare reciprocal of a reciprocal-square-root
   estimate (frsqrte into f4, then fres, with no frsp), which no compiler
   built-in produces; it is written as a minimal inline asm statement in the
   math helper. The flattened Y term is the shared 0.0f constant, and the two
   handle resolutions read the manager through two views so the entries
   pointer is reloaded for the second one, as in the original. */
extern "C" const float lbl_80378654;

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
        float dz = z - o.z;
        float dx = x - o.x;
        float sq = dx * dx + lbl_80378654 + dz * dz;
        float r = lbl_80378654;
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

struct Handle { union { unsigned long value; struct { signed int tag : 8; signed int index : 24; } bits; }; };
struct Entry { Owner* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct Manager { int count, capacity; Entry* entries; };
struct TypedManager { int count, capacity; Entry* entries; };
extern "C" struct Context { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;

inline Owner* resolve(const Handle& h)
{
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    return e->tag == h.bits.tag ? e->object : 0;
}

inline Owner* resolveTyped(const Handle& h)
{
    Entry* e = &((TypedManager*)lbl_801E9D24.manager)->entries[h.bits.index];
    return e->tag == h.bits.tag ? e->object : 0;
}

struct Resource {
    char unknown00[0x58];
    Handle owner;
};

extern "C" float fn_8005ED34(Resource* a, Resource* b)
{
    return resolve(b->owner)->getPos().planarDistance(resolveTyped(a->owner)->getPos());
}
