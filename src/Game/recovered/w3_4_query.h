#ifndef W3_4_QUERY_H
#define W3_4_QUERY_H
/* Shared declarations for the composite-geometry node queries
 * (fn_802474F8 / fn_80247890). */
typedef unsigned long long u64;
#define MASK(x) ((u64)(x) << 32)

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3& p) : x(p.x), y(p.y), z(p.z) {}
    Vec3 operator-(const Vec3& p) const { return Vec3(x - p.x, y - p.y, z - p.z); }
    float lengthSquared() const { return x * x + y * y + z * z; }
};
struct Sphere {
    Vec3 center;
    float radius;
    Sphere(const Sphere& s) : center(s.center), radius(s.radius) {}
};
struct Matrix { float m[4][4]; };
struct MatrixPool { Matrix* pages[6]; unsigned char active; };
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
extern "C" struct Global {
    char unknown00[0x118];
    Manager* manager;
    char unknown11C[0x18];
    MatrixPool* pool;
} lbl_801E9D24;
extern "C" void fn_801F230C(const Matrix*, Matrix*);

struct Object {
    char unknown00[0x120];
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
struct Info { char unknown00[0xC]; unsigned long flags; };
struct Material { char unknown00[0x64]; int mask; };

inline Material* resolveMaterial(const Handle& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.getTag() ? (Material*)m->entries[index].object : 0;
}

struct Strip {
    int count;
    int unknown04;
    short* indices;
    int material;
    unsigned long flags;
};
struct BoxShape { char data[0x24]; };
struct MatrixShape { char data[0x50]; };
struct SphereShape { char data[0x10]; };
template <class T> struct Array {
    int count, capacity;
    T* data;
};
struct Node {
    char unknown00[0xC];
    Sphere bounds;
    char unknown1C[0x6E - 0x1C];
    unsigned short flags;
    char unknown70[0x7C - 0x70];
    void* points;
    char unknown80[0xA4 - 0x80];
    Array<Strip> strips;
    char unknownB0[0xBC - 0xB0];
    Array<Handle> materials;
    Array<SphereShape> spheres;
    Array<MatrixShape> matrices;
    Array<BoxShape> boxes;
};
struct Collector { char unknown00[0x2800]; void* record; };
#endif
