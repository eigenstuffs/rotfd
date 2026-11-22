/* Partial split candidate: fn_802453B4 only (0x802453B4..0x802457B8).
 * auto_03_80244C00_text: masked ray/sphere queries of the spatial binding node
 * (vtable lbl_802EC210 / lbl_802ED1C4 slots 0x3C and 0x50) plus the ray
 * transform helper.
 *
 * fn_80244C00  slot 0x3C ray query: rejects masks without a collision category
 *              and disabled records, transforms the ray into object space
 *              (fn_80245250), tests it against the node bounds (fn_801BA38C),
 *              picks one geometry representation per category (0x2000, 0x4000,
 *              0x8000) or forwards to the first child node's slot 0x3C, and
 *              keeps the nearest hit (point/normal back in world space).
 * fn_80245250  ray (origin, maxT, unit direction, unused word) by matrix:
 *              transforms origin and direction, renormalizes the direction and
 *              scales maxT by the direction length.  The fourth word is never
 *              written in the source; the original stores whatever f1 holds.
 * fn_802453B4  slot 0x50 sphere query against the 0x4000 category geometry,
 *              same nearest-hit update (no +0x40 copy).
 *
 * Flags: GC/1.3.2 -O4,p -inline auto -Cpp_exceptions off -fp_contract on.
 * fn_802453B4 uses lbl_8037B3C8 for 0.0f where the first two use lbl_8037B3C0,
 * so it came from a different original TU.  Templates are avoided on purpose:
 * a function that instantiates a template is emitted at the end of the TU,
 * which breaks the original function order. */
typedef unsigned long long u64;

extern "C" const float lbl_8037B3C0;
extern "C" const float lbl_8037B3C4;
extern "C" const float lbl_8037B3C8;

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
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_8037B3C0;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    float length2() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_8037B3C8;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    Vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
};

struct Matrix {
    float m[4][4];
    Vec3 transform(const Vec3& p) const
    {
        float x = m[3][0] + (m[0][0] * p.x + m[1][0] * p.y + m[2][0] * p.z);
        float y = m[3][1] + (m[0][1] * p.x + m[1][1] * p.y + m[2][1] * p.z);
        float z = m[3][2] + (m[0][2] * p.x + m[1][2] * p.y + m[2][2] * p.z);
        return Vec3(x, y, z);
    }
    Vec3 rotate(const Vec3& p) const
    {
        return Vec3(m[0][0] * p.x + m[1][0] * p.y + m[2][0] * p.z,
                    m[0][1] * p.x + m[1][1] * p.y + m[2][1] * p.z,
                    m[0][2] * p.x + m[1][2] * p.y + m[2][2] * p.z);
    }
    float scale() const { return Vec3(m[0][0], m[1][0], m[2][0]).length(); }
    float scale2() const { return Vec3(m[0][0], m[1][0], m[2][0]).length2(); }
};

struct Rotation {
    Vec3 row[3];
    Vec3 rotate(const Vec3& p) const
    {
        float x = row[0].x * p.x + row[1].x * p.y + row[2].x * p.z;
        float y = row[0].y * p.x + row[1].y * p.y + row[2].y * p.z;
        float z = row[0].z * p.x + row[1].z * p.y + row[2].z * p.z;
        return Vec3(x, y, z);
    }
};

struct Ray {
    Vec3 origin;
    float maxT;
    Vec3 dir;
    float length;
    Ray() {}
    Ray(const Ray& r) : origin(r.origin), maxT(r.maxT), dir(r.dir), length(r.length) {}
};

struct Sphere {
    Vec3 center;
    float radius;
    Sphere() {}
    Sphere(const Sphere& s) : center(s.center), radius(s.radius) {}
};

struct Handle {
    union { int word; struct { signed int tag : 8, index : 24; } bits; };
    signed char getTag() const { return *(const signed char*)this; }
};
struct Entry {
    void* object;
    char unknown04[8];
    signed char tag;
    char pad0D[3];
    signed char getTag() const { return tag; }
};
struct Manager { char unknown00[8]; Entry* entries; };
struct MatrixPool { Matrix* pages[6]; unsigned char active; };
extern "C" struct Global {
    char unknown00[0x118];
    Manager* manager;
    char unknown11C[0x18];
    MatrixPool* pool;
} lbl_801E9D24;

inline void* resolveAny(const Handle& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.getTag() ? m->entries[index].object : 0;
}

struct Child;
inline Child* resolveChild(const Handle& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.getTag() ? (Child*)m->entries[index].object : 0;
}
inline void* lookupAny(const Handle& h)
{
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    if (e->getTag() == h.getTag())
        return e->object;
    return 0;
}

struct HandleArray {
    int count, capacity;
    Handle* data;
    Handle& operator[](int i) { return data[i]; }
    const Handle& operator[](int i) const { return data[i]; }
};

extern "C" void fn_801F230C(const Matrix*, Matrix*);

struct Info;
struct Object {
    char unknown00[0x20];
    Handle info;
    char unknown24[0x30 - 0x24];
    Rotation rotation;
    char unknown54[0x120 - 0x54];
    unsigned long flags;
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
    unsigned long flags;
    char unknown10[0x10];
    HandleArray handles;
};

struct Hit {
    Vec3 point;
    float t;
    Vec3 normal;
    int unknown1C;
    float unknown20, unknown24;
    u64 mask;
    void* object;
    void* owner;
    void* info;
    signed char valid;
    int unknown40;
    Hit() { valid = 0; object = 0; owner = 0; info = 0; mask = 0; }
};

struct ChildBase { char unknown00[8]; };
struct Child : ChildBase {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38();
    virtual signed char raycast(Object*, Info*, const Ray*, Hit*, u64, u64);
};

struct Owner {
    char unknown00[0xC];
    Sphere bounds;
    char unknown1C[0x74 - 0x1C];
    void *a0, *a1, *a2, *a3;
    void *b0, *b1, *b2;
    void *c0, *c1, *c2;
    void *d0, *d1, *d2;
    char unknownA8[0xBC - 0xA8];
    unsigned short flags;
    char unknownBE[2];
    HandleArray handles;
};

extern "C" {
Ray fn_80245250(const Matrix*, const Ray*);
signed char fn_801BA38C(const Ray*, const Sphere*);
void fn_801E09E8(const Ray*, void*, Hit*, u64);
void fn_801E0188(const Ray*, void*, Hit*, u64);
void fn_801E0CD4(const Ray*, void*, Hit*, u64);
Sphere fn_80099A00(const Matrix*, const Sphere*);
void fn_801E04DC(const Sphere*, void*, Hit*, u64);
void fn_801DFBC4(const Sphere*, void*, Hit*, u64);
void fn_801E0AA8(const Sphere*, void*, Hit*, u64);
}

#define MASK(x) ((u64)(x) << 32)

extern "C" signed char fn_802453B4(Owner* self, Object* object, const Sphere* sphere, void* context, Hit* out,
                                   u64 flags)
{
    if (!(flags & MASK(0x4000)))
        return 0;
    Info* info = (Info*)resolveAny(object->info);
    if (info->flags & 1)
        return 0;
    void* a = 0;
    void* b = 0;
    void* c = 0;
    if ((flags & MASK(0x200)) && self->b1)
        a = self->b1;
    else if ((flags & MASK(0x400)) && self->b2)
        b = self->b2;
    else if ((flags & MASK(0x800)) && self->b0)
        c = self->b0;
    else
        return 0;
    Sphere local(fn_80099A00(object->getInverse(), sphere));
    Hit hit;
    if (a)
        fn_801E04DC(&local, a, &hit, MASK(0x4200));
    else if (b)
        fn_801DFBC4(&local, b, &hit, MASK(0x4800));
    else if (c)
        fn_801E0AA8(&local, c, &hit, MASK(0x4800));
    if (hit.valid) {
        Matrix* m = object->matrix;
        if (!out->valid || out->t > hit.t * m->scale2()) {
            out->valid = 1;
            out->object = object;
            out->owner = self;
            out->info = info;
            out->t = hit.t * m->scale2();
            out->point = m->transform(hit.point);
            out->normal = object->rotation.rotate(hit.normal);
            out->mask = hit.mask;
            return 1;
        }
    }
    return 0;
}
