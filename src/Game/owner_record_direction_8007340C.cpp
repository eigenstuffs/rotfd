/* Aims an owner at a record (fn_8007340C): stores the direction from the
   resolved node's matrix position to the record position at 0x9C, its length
   at 0xA8, then normalizes the direction in place.
   The engine square root is the bare reciprocal of a reciprocal-square-root
   estimate (frsqrte into f4, then fres, no frsp) and the fast normalize uses a
   raw frsqrte estimate (no frsp); no compiler built-in emits either, so both
   math helpers are minimal inline asm statements (as in
   owner_position_distance_80066DA4.cpp and early_direction_target_setup_8007F990.cpp).
   The node position reads each component through the matrix pointer; the
   reused matrix load is folded into the first-evaluated (z) operand, which
   reproduces the native z-component register order. */
typedef unsigned long Word;
extern "C" const float lbl_80378928;

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

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
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    float lengthSquared() const { return x * x + y * y + z * z; }
    float length() const
    {
        float sq = lengthSquared();
        float r = lbl_80378928;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    void normalize()
    {
        float inv = reciprocalSqrt(lengthSquared());
        x *= inv;
        y *= inv;
        z *= inv;
    }
};

struct Matrix { float m[16]; };
struct Node {
    char unknown00[0x124];
    Matrix* matrix;
    Vec3 getPos() const { return Vec3(matrix->m[12], matrix->m[13], matrix->m[14]); }
};
struct Handle { union { Word word; struct { signed int tag : 8, index : 24; } bits; }; };
struct Entry { Node* object; char unknown04[8]; signed char tag; char pad[3];
    signed char getTag() const { return tag; } };
struct Manager { char unknown00[8]; Entry* entries; };
extern "C" struct Global { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;
inline Node* resolve(const Handle& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}

/* Twenty-byte owner record: identifier, actor pointer, position. */
struct Record { short id; void* actor; Vec3 pos; };
struct Owner {
    char unknown00[0x58];
    Handle handle;
    char unknown5C[0x9C - 0x5C];
    Vec3 direction;
    float distance;
};

extern "C" void fn_8007340C(Owner* self, Record* record)
{
    self->direction = record->pos - resolve(self->handle)->getPos();
    self->distance = self->direction.length();
    self->direction.normalize();
}
