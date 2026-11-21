/* Original TU: fn_8024E62C alone, .text 0x8024E62C-0x8024EB80, .sdata2 0x8037B488-0x8037B4A0
 * (pooled 3.0f, 6.0f, 1.0f, pad, int->float bias). GC/1.3.2 -O4,p -fp_contract on. */
typedef unsigned long Word;
typedef unsigned long long Mask;
#define MASK(x) ((Mask)(x) << 32)

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
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
};

struct Vec4 : Vec3 {
    float w;
    Vec4() {}
    Vec4(const Vec3& v) : Vec3(v), w(1.0f) {}
    Vec4(const Vec4& v) : Vec3(v), w(v.w) {}
    Vec4& operator=(const Vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }
};

struct Matrix {
    float m[16];
    Vec3 transform(const Vec3& v) const
    {
        float Z;
        float Y;
        float X;
        X = m[12] + (m[0] * v.x + m[4] * v.y + m[8] * v.z);
        Y = m[13] + (m[1] * v.x + m[5] * v.y + m[9] * v.z);
        Z = m[14] + (m[2] * v.x + m[6] * v.y + m[10] * v.z);
        return Vec3(X, Y, Z);
    }
};
struct Matrix3 {
    float m[9];
    Vec3 transform(const Vec3& v) const
    {
        float Z;
        float Y;
        float X;
        X = m[0] * v.x + m[3] * v.y + m[6] * v.z;
        Y = m[1] * v.x + m[4] * v.y + m[7] * v.z;
        Z = m[2] * v.x + m[5] * v.y + m[8] * v.z;
        return Vec3(X, Y, Z);
    }
};
struct MatrixPool { Matrix* pages[6]; unsigned char active; };
struct Grid { int subdivision; };
struct HandleEntry { void* object; char pad4[8]; signed char tag; char padD[3]; };
struct HandleManager { char pad[8]; HandleEntry* entries; };
struct Context { char pad[0x118]; HandleManager* manager; char pad11C[0xc]; Grid* grid; char pad12C[8]; MatrixPool* pool; };
extern "C" Context lbl_801E9D24;
extern "C" void fn_801F230C(const Matrix*, Matrix*);
extern "C" void fn_801F2124(const Matrix3*, Matrix3*);

struct Handle { signed long tag : 8, index : 24; };
inline void* resolve(const Handle& h)
{
    int index = h.index;
    HandleManager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].tag;
    return tag == h.tag ? m->entries[index].object : 0;
}

struct Object {
    char unknown00[0x30];
    Matrix3 rotation;
    Matrix3 inverseRotation;
    char unknown78[0xa8];
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
    const Matrix3& getInverseRotation()
    {
        if (flags & 0x40) {
            fn_801F2124(&rotation, &inverseRotation);
            flags &= ~0x40;
        }
        return inverseRotation;
    }
};

struct Sphere {
    float x, y, z, r;
    Sphere() {}
    Sphere(const Vec3& c, float radius) : x(c.x), y(c.y), z(c.z), r(radius) {}
    const Vec3& center() const { return *(const Vec3*)this; }
    Vec3& center() { return *(Vec3*)this; }
};
struct Segment { Vec3 start; float length; Vec3 direction; float radius; };
struct Line {
    Vec3 origin;
    float weight;
    Vec3 dir;
    float pad;
    Line() {}
    Line(const Segment& s) : origin(s.start), dir(s.direction) { weight = s.length; }
    Line(const Vec3& o, const Vec3& d) : origin(o), dir(d) { weight = 1.0f; }
    Line(const Vec3& d) : dir(d) { weight = 1.0f; }
};
struct Plane {
    float x, y, z, w, dx, dy, dz, pad;
    Plane(const Vec3& o, const Vec3& d) : x(o.x), y(o.y), z(o.z), dx(d.x), dy(d.y), dz(d.z) { w = 1.0f; }
};
inline Plane makePlane(const Vec3& o, const Vec3& d) { return Plane(o, d); }
struct PatchBox { char pad[0x10]; char box[0x58]; };
struct Info { char unknown00[0xC]; Word flags; char pad10[0x1c]; PatchBox* boxes; };
struct Hit { Vec3 position; float distance; Vec3 normal; float u, v; char pad[12]; };
struct QueryHit {
    Vec3 position; float distance; Vec3 normal; int index; float u, v;
    Mask mask; struct Object* object; struct Mesh* mesh; const Info* info; signed char valid;
};
template <class T, int N> struct FixedArray {
    char storage[N * sizeof(T)];
    int count;
    FixedArray() : count(0) {}
    ~FixedArray() { for (int i = 0; i < count; i++) ((T*)storage)[i].~T(); }
};
struct Slot { int a; ~Slot() {} };

struct Edge { unsigned short vert[2]; unsigned short ctrl[2]; };
struct MeshSegment { unsigned short unknown0; unsigned short edge; char pad[4]; Sphere sphere;
    const Sphere& getSphere() const { return sphere; }
    const unsigned short& getEdge() const { return edge; } };
template <class T> struct Array { unsigned count, capacity; T* items; T& operator[](long i) { return items[i]; } };
struct MaterialB { char pad[0x64]; Word mask; };
struct MaterialA { char pad[0xb8]; Handle material; };
struct Patch { char pad[0x88]; Handle handle; char pad8C[4]; };
inline Word maskOf(const Handle& handle)
{
    return ((MaterialB*)resolve(((MaterialA*)resolve(handle))->material))->mask;
}
struct SpatialGrid;
struct Vertex;
struct Mesh {
    char pad[0xc];
    Sphere sphere;
    char pad1C[0x60];
    Vec3* verts;
    char pad80[0xc];
    Array<MeshSegment> segments;
    char pad98[0xc];
    Array<Patch> patches;
    char padB0[8];
    Edge* edges;
    char padBC[0x14];
    PatchBox* boxes;
    char padD4[0x24];
    SpatialGrid* grid;
    Edge& edgeOf(const MeshSegment& s) { return edges[s.edge]; }
};

extern "C" {
Segment fn_801DD9E0(const Matrix*, const Segment*);
Sphere fn_80099A00(const Matrix*, const Sphere*);
signed char fn_801B9318(const Sphere&, const Segment*);
Vec3 fn_801AFFBC(const Vec3&, float);
float fn_8024F9D8(const Line*, const Line*);
signed char fn_801B80B0(const Segment*, Plane, Hit*);
signed char fn_801B679C(const Segment*, const Vec4*, const Vec4*, const Vec4*, Hit*);
signed char fn_801B9458(const void*, const Segment*);
signed char fn_801B6338(const Sphere*, const void*);
void fn_80265028(SpatialGrid*, const Sphere*, float);
short fn_802654E8(SpatialGrid*, short*, short);
Vertex* fn_801D6BA8(Mesh*, unsigned short, const Info*);
signed char fn_801DEF20(const Segment*, const Vertex*, Hit*, int);
}

extern "C" int fn_8024E62C(Mesh* self, Object* object, const Info* info, const Segment* segment, void* context, Mask flags, Mask extra)
{
    if (info->flags & 1) return 0;
    Segment local = fn_801DD9E0(object->getInverse(), segment);
    const Matrix* mtx = object->matrix;
    if (flags & MASK(4)) {
        if (!fn_801B9318(fn_80099A00(mtx, &self->sphere), segment)) return 0;
        for (unsigned i = 0; i < self->segments.count; i++) {
            if (fn_801B9318(fn_80099A00(mtx, &self->segments[i].getSphere()), segment)) {
                Vec3 p0 = mtx->transform(self->verts[self->edgeOf(self->segments[i]).vert[0]]);
                Vec3 p1 = mtx->transform(self->verts[self->edgeOf(self->segments[i]).ctrl[0]]);
                Vec3 p2 = mtx->transform(self->verts[self->edgeOf(self->segments[i]).ctrl[1]]);
                Vec3 p3 = mtx->transform(self->verts[self->edgeOf(self->segments[i]).vert[1]]);
                Vec3 a = -p0 + p1 * 3.0f - p2 * 3.0f + p3;
                Vec3 b = p0 * 3.0f - p1 * 6.0f + p2 * 3.0f;
                Vec3 c = -p0 * 3.0f + p1 * 3.0f;
                float step = 1.0f / (float)(lbl_801E9D24.grid->subdivision + 1);
                for (int j = 1; j < lbl_801E9D24.grid->subdivision + 2; j++) {
                    float t = step * (float)j;
                    fn_801AFFBC(a, t);
                }
            }
        }
    }
    return 0;
}
