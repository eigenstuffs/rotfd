/* fn_80247E40: collision-mesh node swept-segment query (vtable slot 0x48 of
 * lbl_802EA388). Transforms the query segment into object space, tests the
 * node bounds, then collects hits from cylinders/boxes/spheres (mask bits
 * 0x20/0x40/0x80) or, when the node has none, from its masked triangle strips;
 * the nearest hit is transformed back to world space into *out.
 * EXACT: one loop index shared by all four loops (so the Hit zero stores reuse
 * its register) and the counts read through an inline Array::size() getter (so
 * they are coloured before the index). Flags: -O4,p -Cpp_exceptions off. */
typedef unsigned long long Mask;
#define MASK(x) ((Mask)(x) << 32)

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

extern "C" const float lbl_8037B3F8;

inline float vectorLength(float x, float y, float z)
{
    float sq = x * x + y * y + z * z;
    float r = lbl_8037B3F8;
    if (sq != r) r = fastSqrt(sq);
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3& operator=(const Vec3& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
};

struct Matrix {
    float m[16];
    float scale() const { return vectorLength(m[0], m[4], m[8]); }
    Vec3 transform(const Vec3& v) const
    {
        Vec3 r;
        r.x = m[12] + (m[0] * v.x + m[4] * v.y + m[8] * v.z);
        r.y = m[13] + (m[1] * v.x + m[5] * v.y + m[9] * v.z);
        r.z = m[14] + (m[2] * v.x + m[6] * v.y + m[10] * v.z);
        return r;
    }
};

struct Basis {
    float m[9];
    Vec3 transform(const Vec3& v) const
    {
        Vec3 r;
        r.x = m[0] * v.x + m[3] * v.y + m[6] * v.z;
        r.y = m[1] * v.x + m[4] * v.y + m[7] * v.z;
        r.z = m[2] * v.x + m[5] * v.y + m[8] * v.z;
        return r;
    }
};

struct MatrixPool {
    Matrix* pages[6];
    unsigned char active;
};

struct Node {
    char unknown00[0x64];
    int mask;
};

struct Handle {
    union {
        int word;
        struct {
            signed int tag : 8, index : 24;
        } bits;
    };
    signed char getTag() const { return *(const signed char*)this; }
};
struct Entry {
    Node* object;
    char unknown04[8];
    signed char tag;
    char pad0D[3];
    signed char getTag() const { return tag; }
};
struct Manager {
    char unknown00[8];
    Entry* entries;
};

extern "C" struct Global {
    char unknown00[0x118];
    Manager* manager;
    char unknown11C[0x18];
    MatrixPool* pool;
} lbl_801E9D24;

inline Node* resolve(const Handle& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.getTag() ? m->entries[index].object : 0;
}

extern "C" void fn_801F230C(const Matrix*, Matrix*);

struct WorldObject {
    char unknown00[0x30];
    Basis basis;
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

struct Segment {
    Vec3 start;
    float length;
    Vec3 direction;
    float radius;
    Segment() {}
    Segment(const Segment& s) : start(s.start), length(s.length), direction(s.direction), radius(s.radius) {}
};

struct Sphere {
    Vec3 center;
    float radius;
};

struct Info {
    char unknown00[0xC];
    unsigned long flags;
};

struct Hit {
    Vec3 point;
    float t;
    Vec3 normal;
    int unknown1C;
    float unknown20, unknown24;
    Mask mask;
    void* object;
    void* owner;
    const Info* info;
    signed char valid;
    int unknown40;
    Hit() { valid = 0; object = 0; owner = 0; info = 0; mask = 0; }
};

template <class T> struct Array {
    int count, capacity;
    T* data;
    int size() const { return count; }
};

struct Strip {
    Array<short> indices;
    int handle;
    unsigned long flags;
};

struct Cylinder { char unknown00[0x24]; };
struct Box { char unknown00[0x50]; };
struct Ball { char unknown00[0x10]; };

struct Geometry {
    char unknown00[0xC];
    Sphere bounds;
    char unknown1C[0x6E - 0x1C];
    unsigned short flags;
    char unknown70[0x7C - 0x70];
    Vec3* points;
    char unknown80[0xA4 - 0x80];
    Array<Strip> strips;
    char unknownB0[0xBC - 0xB0];
    Array<Handle> handles;
    Array<Ball> balls;
    Array<Box> boxes;
    Array<Cylinder> cylinders;
};

extern "C" {
Segment fn_801DD9E0(const Matrix& matrix, const Segment& segment);
signed char fn_801B9458(const Sphere&, const Segment*);
void fn_801DCCE8(const Segment*, const Cylinder*, Hit*, Mask);
void fn_801DDBFC(const Segment*, const Box*, Hit*, Mask);
void fn_801DE080(const Segment*, const Ball*, Hit*, Mask);
void fn_801DC8B4(const Segment*, const Vec3*, short*, int, int, Hit*, Mask);
}

extern "C" signed char fn_80247E40(Geometry* self, WorldObject* object, const Info* info,
                                   const Segment* query, Hit* out, Mask flags, Mask flags2)
{
    if ((flags2 & MASK(0x100)) || (self->flags & 4) || (info->flags & 1))
        return 0;
    if (!(flags & MASK(0x100)))
        return 0;
    Segment segment = fn_801DD9E0(*object->getInverse(), *query);
    if (!fn_801B9458(self->bounds, &segment))
        return 0;
    int i;
    int balls = self->balls.size();
    int boxes = self->boxes.size();
    int cylinders = self->cylinders.size();
    Hit hit;
    if (balls || boxes || cylinders) {
        if (flags & MASK(0x20))
            for (i = 0; i < cylinders; i++)
                fn_801DCCE8(&segment, &self->cylinders.data[i], &hit, MASK(0x120));
        if (flags & MASK(0x40))
            for (i = 0; i < boxes; i++)
                fn_801DDBFC(&segment, &self->boxes.data[i], &hit, MASK(0x140));
        if (flags & MASK(0x80))
            for (i = 0; i < balls; i++)
                fn_801DE080(&segment, &self->balls.data[i], &hit, MASK(0x180));
    } else {
        Vec3* points = self->points;
        Strip* strip = self->strips.data;
        int count = self->strips.count;
        for (i = 0; i < count; i++, strip++) {
            Mask mask = resolve(self->handles.data[strip->handle])->mask;
            if ((flags & mask) && !(flags2 & mask))
                fn_801DC8B4(&segment, points, strip->indices.data, strip->indices.count - 2,
                            (strip->flags >> 1 & 1) ^ 1, &hit, mask);
        }
    }
    if (hit.valid) {
        Matrix* m = object->matrix;
        if (!out->valid || out->t > hit.t * m->scale()) {
            out->valid = 1;
            out->object = object;
            out->owner = self;
            out->info = info;
            out->t = hit.t * m->scale();
            out->point = m->transform(hit.point);
            out->normal = object->basis.transform(hit.normal);
            out->mask = hit.mask;
            return 1;
        }
    }
    return 0;
}
