/* fn_8023B508: audio source audibility test (EXACT, retry3).
 * Returns 1 when no viewport camera (lbl_801E9D24+0x114, 7 records of 0x4C,
 * handle at +0x14, count at +0x214) in the source's group (+0x134) is inside
 * the attenuation range: center = source position (+ owner position when an
 * owner is given), radii = 0x8037B320 * scaleX * sqrt(+0xE8/+0xEC), volume =
 * 1 - (d - inner) / (outer - inner).
 * Literal-pool emulation: each zero/scale read uses a distinct form; the
 * distance zero is the pointer form (not hoisted out of the loop) and the
 * compare zero volatile so the two loads stay separate.
 * Vec3::distance uses register locals (dz, dy, dx, result, sq; the
 * engine's frsqrte/fres pair written in place as in
 * src/Game/owner_planar_distance_80066F0C.cpp); dz first holds o.z and is
 * then replaced by z - dz, which reproduces the original FPR colouring of the
 * camera-position loads. */
typedef unsigned long u32;
extern "C" const float lbl_8037B308;
extern "C" const float lbl_8037B318;
extern "C" const float lbl_8037B31C;
extern "C" const float lbl_8037B320;
extern "C" const float lbl_8037B324;

#define ZERO_A lbl_8037B318
#define ZERO_B (*(const float*)&lbl_8037B318)
#define ZERO_C (*(const float*)(unsigned long)&lbl_8037B318)
#define ZERO_V (*(const volatile float*)&lbl_8037B318)

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

#define SAFE_SQRT(NAME, ZERO) inline float NAME(float sq) { float r = ZERO; if (sq != r) r = fastSqrt(sq); return r; }
SAFE_SQRT(safeSqrtA, ZERO_A)
SAFE_SQRT(safeSqrtB, ZERO_B)
SAFE_SQRT(safeSqrtC, ZERO_C)

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    float lengthSq() const { return x * x + y * y + z * z; }
    float length() const { return safeSqrtB(x * x + y * y + z * z); }
    float distance(const Vec3& o) const
    {
        register float dz = o.z;
        register float dy = y - o.y;
        register float dx = x - o.x;
        register float result = ZERO_B;
        dz = z - dz;
        register float sq = dx * dx + dy * dy + dz * dz;
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
    float getScaleSq() const { float x = m[0], y = m[4], z = m[8]; return x * x + y * y + z * z; }
    float getScaleX() const { float x = m[0], y = m[4], z = m[8]; return safeSqrtA(x * x + y * y + z * z); }
};

struct Object {
    char unknown00[0xE8];
    float innerRange;
    float outerRange;
    char unknownF0[0x124 - 0xF0];
    Matrix* matrix;
    char unknown128[0x134 - 0x128];
    int group;
};

struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct Entry {
    Object* object;
    u32 unknown[2];
    signed char generation;
    char pad[3];
    signed char getGeneration() const { return generation; }
};
struct Manager { int count, capacity; Entry* entries; };
struct Slot { char unknown00[0x14]; Handle handle; char unknown18[0x4C - 0x18]; };
struct SlotTable { Slot slots[7]; signed char count; };
struct Globals {
    char unknown0[0x114];
    SlotTable* table;
    Manager* manager;
};
extern "C" Globals lbl_801E9D24;

inline Object* resolve(Manager* m, const Handle& h)
{
    int index = h.bits.index;
    int actual = m->entries[index].getGeneration();
    int expected = h.bits.generation;
    if (actual == expected) return m->entries[index].object;
    return 0;
}

inline signed char allOutside(const Vec3& center, float inner, float outer, const Object* first)
{
    Manager* manager = lbl_801E9D24.manager;
    int group = first->group;
    signed char outside = 1;
    for (int i = 0; i < lbl_801E9D24.table->count; ++i) {
        Object* o = resolve(manager, lbl_801E9D24.table->slots[i].handle);
        if (o && group == o->group) {
            float d = center.distance(o->matrix->getPos());
            if (*(const float*)&lbl_8037B308 - (d - inner) / (outer - inner) < ZERO_V) {
                outside = 1;
            } else {
                outside = 0;
                break;
            }
        }
    }
    return outside;
}

extern "C" signed char fn_8023B508(void* self, Object* first, Object* second)
{
    Vec3 center;
    float scale;
    if (second) {
        Matrix* m = second->matrix;
        float sq = m->getScaleSq();
        center = m->getPos() + first->matrix->getPos();
        scale = safeSqrtA(sq);
    } else {
        Matrix* m = first->matrix;
        center.z = m->m[14]; center.x = m->m[12]; center.y = m->m[13];
        scale = m->getScaleX();
    }
    float inner;
    float outer;
    if (first->innerRange < lbl_8037B31C && first->outerRange < lbl_8037B31C) {
        inner = lbl_8037B320;
        outer = lbl_8037B324;
    } else {
        inner = *(const float*)&lbl_8037B320 * (scale * safeSqrtB(first->innerRange));
        outer = *(const float*)(unsigned long)&lbl_8037B320 * (scale * safeSqrtC(first->outerRange));
    }
    return allOutside(center, inner, outer, first);
}
