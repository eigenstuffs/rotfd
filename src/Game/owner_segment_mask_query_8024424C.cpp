// fn_8024424C: masked segment (ray) query against an owner's geometry.
// Segment twin of fn_80244710 (engine_sphere_mask_dispatch.cpp): category
// masks select the owner's geometry (or forward to the owner's resolved
// shape through vtable slot 0x48), the segment is moved into object space,
// and the nearest hit is transformed back and kept in the caller's record.
// Flags: GC/1.3.2 -O4,p, exceptions off, RTTI off, -fp_contract on.
// Matching notes: the first handle resolve keeps its zero result preset
// (shares the r8 zero with the mask test); the second resolve's ?: must
// sit inside the call's argument list (an inline helper is hoisted before
// the argument setup); the point/normal transforms are written in the body.
typedef unsigned long Word;
typedef unsigned long long Mask;
#define MASK(x) (Mask(x) << 32)

extern "C" const float lbl_8037B3B8;

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
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
};
inline float lengthScale(float x, float y, float z)
{
    float sq = x * x + y * y + z * z;
    float r = lbl_8037B3B8;
    if (sq != r) r = fastSqrt(sq);
    return r;
}

struct Segment {
    Vec3 start;
    float length;
    Vec3 direction;
    float radius;
    Segment(const Segment& s) : start(s.start), length(s.length), direction(s.direction), radius(s.radius) {}
};

struct Matrix {
    float a[16];
};
struct Basis {
    float a[9];
};
struct MatrixPool { Matrix* pages[6]; unsigned char active; };

struct Handle { union { Word word; struct { signed int tag : 8, index : 24; } bits; }; };
struct Prefix { char unknown00[8]; };
struct Entry { void* object; char unknown04[8]; signed char tag; char pad[3];
    signed char getTag() const { return tag; } };
struct Manager { char unknown00[8]; Entry* entries; };
struct Global { char unknown00[0x118]; Manager* manager; char unknown11C[0x134 - 0x11C]; MatrixPool* pool; };
extern "C" Global lbl_801E9D24;

inline void* resolveOrZero(const Handle& h)
{
    void* p = 0;
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    if (tag == h.bits.tag) p = m->entries[index].object;
    return p;
}

extern "C" void fn_801F230C(const Matrix*, Matrix*);

struct Object {
    char unknown00[0x30];
    Basis rotation;
    char unknown54[0x120 - 0x54];
    Word flags;
    Matrix* matrix;
    Matrix* inverse;
    short unknown12C, index;
    Matrix* getInverse()
    {
        if (flags & 0x20) {
            inverse = lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active] + index;
            fn_801F230C(matrix, inverse);
            flags &= ~0x20;
        }
        return inverse;
    }
};

struct Info {
    char unknown00[0xC];
    Word flags;
    char unknown10[0x10];
    int enabled;
    char unknown24[4];
    Handle* handle;
};

struct Owner;

struct Hit {
    Vec3 point;
    float distance;
    Vec3 normal;
    char unknown1C[12];
    Mask flags;
    Object* object;
    Owner* owner;
    const Info* info;
    signed char valid;
    Hit() { valid = 0; object = 0; owner = 0; info = 0; flags = 0; }
};

struct Shape : Prefix {
    virtual void slot08();
    virtual void slot0C();
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
    virtual int query(Object*, void*, const Segment*, Hit*, Mask, Mask);
};

struct Owner {
    char unknown00[0x74];
    void *a0, *a1, *a2, *a3;
    char unknown84[0xBC - 0x84];
    unsigned short flagsBC;
    char unknownBE[2];
    int enabledC0;
    char unknownC4[4];
    Handle* handle;
};

extern "C" {
Segment fn_801DD9E0(const Matrix*, const Segment*);
int fn_801DCCE8(const Segment*, void*, Hit*, Mask);
int fn_801DDBFC(const Segment*, void*, Hit*, Mask);
int fn_801DE080(const Segment*, void*, Hit*, Mask);
}

extern "C" int fn_8024424C(Owner* self, Object* object, const Info* info, const Segment* segment, Hit* result, Mask flags, Mask extra)
{
    if (!(flags & MASK(0xF000))) return 0;
    if (info->flags & 1) return 0;
    void* a2 = 0;
    void* a3 = 0;
    void* a0 = 0;
    void* a1 = 0;
    if (flags & MASK(0x8000)) {
        if ((flags & MASK(0x200)) && self->a2)
            a2 = self->a2;
        else if ((flags & MASK(0x400)) && self->a3)
            a3 = self->a3;
        else if ((flags & MASK(0x800)) && self->a0) {
            a0 = self->a0;
            a1 = self->a1;
        }
    } else if (!(self->flagsBC & 0x80) && self->enabledC0 && info->enabled) {
        Shape* shape = (Shape*)resolveOrZero(*self->handle);
        const Handle& h = *info->handle;
        Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
        int tag = e->getTag();
        return shape->query(object, tag == h.bits.tag ? e->object : 0, segment, result, flags, extra);
    }
    Segment local = fn_801DD9E0(object->getInverse(), segment);
    Hit hit;
    if (a2)
        fn_801DCCE8(&local, a2, &hit, MASK(0x8200));
    else if (a3)
        fn_801DDBFC(&local, a3, &hit, MASK(0x8400));
    else if (a0)
        fn_801DE080(&local, a0, &hit, MASK(0x8800));
    if (a1)
        fn_801DE080(&local, a1, &hit, MASK(0x8800));
    if (hit.valid) {
        const Matrix* m = object->matrix;
        float distance = hit.distance * lengthScale(m->a[0], m->a[4], m->a[8]);
        if (!result->valid || result->distance > distance) {
            result->valid = 1;
            result->object = object;
            result->owner = self;
            result->info = info;
            result->distance = distance;
            const Vec3& v = hit.point;
            float X = m->a[0] * v.x + m->a[4] * v.y + m->a[8] * v.z + m->a[12];
            float Y = m->a[1] * v.x + m->a[5] * v.y + m->a[9] * v.z + m->a[13];
            float Z = m->a[2] * v.x + m->a[6] * v.y + m->a[10] * v.z + m->a[14];
            result->point = Vec3(X, Y, Z);
            const Vec3& n = hit.normal;
            const float* r = object->rotation.a;
            float NX = r[0] * n.x + r[3] * n.y + r[6] * n.z;
            float NY = r[1] * n.x + r[4] * n.y + r[7] * n.z;
            float NZ = r[2] * n.x + r[5] * n.y + r[8] * n.z;
            result->normal = Vec3(NX, NY, NZ);
            result->flags = hit.flags;
            return 1;
        }
    }
    return 0;
}
