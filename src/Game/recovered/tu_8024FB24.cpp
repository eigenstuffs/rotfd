/* fn_8024FB24 (sphere vs mesh), its own original TU (pool 0x8037B4C8..E0:
 * 1.0f, 3.0f, 6.0f, pad, int->float bias at 0x8037B4D8).
 * GC/1.3.2, -O4,p, -fp_contract on.  probe: --opt p --flags "-fp_contract on"
 * -> EXACT-MOD-POOL (only the 6 pool loads differ: literal @800/@801/@802 and
 * the bias @806 must become lbl_8037B4C8/CC/D0/D8).  Emits the weak
 * __dt__21FixedArray<5Entry,16>Fv (EXACT-WEAK).
 * Load-bearing for the grid-patch colouring: C-style declarations at function
 * top in the order boxes, patches, p, i, k, m (named vregs are numbered in
 * reverse declaration order); one short `i` shared by the grid branch (i = *p)
 * and the list branch, so the frontend splits the list-branch web into a temp
 * whose `li 0` CSEs with the extra&MASK(2) compare zero; grid count in its own
 * `int k`.  Other notes: FixedArray with raw storage and resize() storing count
 * once at the end; overlapXZ declares dz,dx,r but assigns r,dx,dz; nodeAt()
 * accessor; maskOf(const Handle&) with index/manager/tag resolve; named Horner
 * steps q,r,p; float literals (extern labels get CSE'd). */
typedef unsigned long Word;
typedef unsigned long long Mask;
#define MASK(x) ((Mask)(x) << 32)

inline void* operator new(unsigned long, void* p) { return p; }

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
    float lengthSquared() const { return x * x + y * y + z * z; }
    Vec3 cross(const Vec3& v) const { return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }
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

struct Handle { signed long tag : 8, index : 24; };
inline void* resolve(const Handle& h)
{
    int index = h.index;
    HandleManager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].tag;
    return tag == h.tag ? m->entries[index].object : 0;
}

struct Object {
    char unknown00[0x120];
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

struct Sphere {
    Vec3 center;
    float r;
};
struct Info { char unknown00[0xC]; Word flags; char pad10[0x1c]; struct PatchBox* boxes; };
struct Result { Vec3 position; float distance; Vec3 normal; char pad[0x14]; };
struct Hit {
    Vec3 position; float distance; Vec3 normal; void* object; Mask token;
    Hit() { object = 0; }
};
struct Hits {
    Hit records[256];
    int count;
    int append()
    {
        if (count >= 256) {
            new (&records[255]) Hit;
            return 255;
        }
        new (&records[count++]) Hit;
        return count - 1;
    }
};
inline void store(Hits* out, const Result& result, Mask token)
{
    Hit& hit = out->records[out->append()];
    hit.position = result.position;
    hit.normal = result.normal;
    hit.distance = result.distance;
    hit.token = token;
}

template <class T, int N> struct FixedArray {
    char storage[N * sizeof(T)];
    int count;
    T* data() { return (T*)storage; }
    T& back() { return data()[count - 1]; }
    T& operator[](int i) { return data()[i]; }
    FixedArray() : count(0) {}
    ~FixedArray() { for (int i = 0; i < count; i++) data()[i].~T(); }
    void push(const T& v)
    {
        if (count >= N) {
            new (&data()[N - 1]) T(v);
        } else {
            new (&data()[count++]) T(v);
        }
    }
    void resize(int n)
    {
        if (n > count) {
            for (int i = count; i < n; ++i) new (&data()[i]) T;
        } else if (n < count) {
            for (int i = count - 1; i >= n; --i) data()[i].~T();
        }
        count = n;
    }
};
struct Entry {
    unsigned short node;
    unsigned short state;
    Entry() {}
    Entry(unsigned short n) : node(n), state(0) {}
};

struct Node { Sphere sphere; Word flags; short child[2]; };
struct Edge { unsigned short vert[2]; unsigned short ctrl[2]; };
struct MeshSegment { unsigned short unknown0; unsigned short edge; char pad[4]; Sphere sphere;
    const Sphere& getSphere() const { return sphere; } };
template <class T> struct Array { unsigned count, capacity; T* items; T& operator[](int i) { return items[i]; } };
struct MaterialB { char pad[0x64]; Word mask; };
struct MaterialA { char pad[0xb8]; Handle material; };
struct Patch { char pad[0x88]; Handle handle; char pad8C[4]; };
struct PatchBox { Sphere sphere; char box[0x58]; };
struct SpatialGrid;
struct Vertex;
struct Mesh {
    char pad[0xc];
    Sphere sphere;
    char pad1C[0x60];
    Vec3* verts;
    char pad80[0xc];
    Array<MeshSegment> segments;
    Array<MeshSegment> tubes;
    Array<Patch> patches;
    char padB0[8];
    Edge* edges;
    char padBC[0x14];
    PatchBox* boxes;
    char padD4[0x20];
    Node* nodes;
    SpatialGrid* grid;
    Edge& edgeOf(const MeshSegment& s) { return edges[s.edge]; }
    Node& nodeAt(int i) { return nodes[i]; }
    Node& nodeOf(const Entry& e) { return nodes[e.node]; }
};

inline bool overlapXZ(const Sphere& s, const Sphere& n)
{
    float dz;
    float dx;
    float r;
    r = s.r + n.r;
    dx = n.center.x - s.center.x;
    dz = n.center.z - s.center.z;
    return dx * dx + dz * dz < r * r;
}
inline bool overlapXZ(const Sphere& s, const MeshSegment& n)
{
    float dz;
    float dx;
    float r;
    r = s.r + n.sphere.r;
    dx = n.sphere.center.x - s.center.x;
    dz = n.sphere.center.z - s.center.z;
    return dx * dx + dz * dz < r * r;
}
inline bool overlap(const Sphere& a, const Sphere& b)
{
    float r = a.r + b.r;
    const Vec3& d = a.center - b.center;
    return d.lengthSquared() < r * r;
}
inline Word maskOf(const Handle& handle)
{
    return ((MaterialB*)resolve(((MaterialA*)resolve(handle))->material))->mask;
}

extern "C" {
Sphere fn_80099A00(const Matrix*, const Sphere*);
Vec3 fn_801AFFBC(const Vec3&, float);
signed char fn_801B8B20(const Sphere*, const Vec4*, const Vec4*, Result*);
signed char fn_801B6338(const Sphere*, const void*);
void fn_80265028(SpatialGrid*, const Sphere*, float);
short fn_802654E8(SpatialGrid*, short*, short);
Vertex* fn_801D6BA8(Mesh*, unsigned short, const Info*);
void fn_801DF770(const Sphere*, Vertex*, Hits*, int, Mask);
int fn_801DC718(Hits*, int, Object*);
}

extern "C" int fn_8024FB24(Mesh* self, Object* object, const Info* info, const Sphere* sphere, Hits* out, Mask flags, Mask extra)
{
    if ((extra & MASK(2)) && (extra & MASK(4))) return 0;
    if (info->flags & 1) return 0;
    Sphere local = fn_80099A00(object->getInverse(), sphere);
    FixedArray<Entry, 16> stack;
    PatchBox* boxes;
    Patch* patches;
    short* p;
    short i;
    int k;
    Mask m;
    int n = lbl_801E9D24.grid->subdivision + 1;
    int start = out->count;
    if ((flags & MASK(4)) && (int)self->segments.count != 0) {
        float step = 1.0f / (float)n;
        stack.resize(0);
        stack.push(Entry(0));
        for (;;) {
            short found = -1;
            while (stack.count != 0) {
                Entry& top = stack.back();
                Node& node = self->nodeAt(top.node);
                if (overlapXZ(local, node.sphere)) {
                    if (top.state == 0) {
                        top.state++;
                        if (node.flags & 1) {
                            short s = node.child[0];
                            if (overlapXZ(local, self->segments[s])) {
                                found = s;
                                break;
                            }
                        } else if (!(node.flags & 4)) {
                            stack.push(Entry(node.child[0]));
                        }
                    } else if (top.state == 1) {
                        top.state++;
                        if (node.flags & 2) {
                            short s = node.child[1];
                            if (overlapXZ(local, self->segments[s])) {
                                found = s;
                                break;
                            }
                        } else if (!(node.flags & 8)) {
                            stack.push(Entry(node.child[1]));
                        }
                    } else {
                        stack.resize(stack.count - 1);
                    }
                } else {
                    stack.resize(stack.count - 1);
                }
            }
            if (found == -1) break;
            Vec3 p0 = self->verts[self->edgeOf(self->segments[found]).vert[0]];
            Vec3 p1 = self->verts[self->edgeOf(self->segments[found]).ctrl[0]];
            Vec3 p2 = self->verts[self->edgeOf(self->segments[found]).ctrl[1]];
            Vec3 p3 = self->verts[self->edgeOf(self->segments[found]).vert[1]];
            Vec3 a = -p0 + p1 * 3.0f - p2 * 3.0f + p3;
            Vec3 b = p0 * 3.0f - p1 * 6.0f + p2 * 3.0f;
            Vec3 c = -p0 * 3.0f + p1 * 3.0f;
            Vec4 prev(p0);
            for (int j = 1; j <= n; j++) {
                float t = step * (float)j;
                Vec3 q = b + fn_801AFFBC(a, t);
                Vec3 r = c + q * t;
                Vec3 p = p0 + r * t;
                Vec4 cur(p);
                Result hit;
                if (fn_801B8B20(&local, &prev, &cur, &hit)) store(out, hit, MASK(4));
                prev = Vec4(p);
            }
        }
    }
    i = 0;
    int count = self->patches.count;
    if (!(extra & MASK(2))) {
        if (self->grid) {
            fn_80265028(self->grid, &local, local.r);
            short buf[32];
            boxes = self->boxes;
            patches = self->patches.items;
            while ((k = fn_802654E8(self->grid, buf, 32)) != 0) {
                p = &buf[k];
                while (p--, k-- != 0) {
                    i = *p;
                    m = maskOf(patches[i].handle);
                    if ((flags & m) && !(extra & m)) {
                        if (fn_801B6338(&local, boxes[i].box))
                            fn_801DF770(&local, fn_801D6BA8(self, i, info), out, n, m);
                    }
                }
            }
        } else {
            PatchBox* box = info->boxes;
            Patch* patch = self->patches.items;
            for (; i < count; i++, box++, patch++) {
                int m = maskOf(patch->handle);
                if ((flags & m) && !(extra & m)) {
                    if (overlap(box->sphere, local)) {
                        int m2 = maskOf(self->patches.items[i].handle);
                        if ((flags & m2) && !(extra & m2))
                            fn_801DF770(&local, fn_801D6BA8(self, i, info), out, n, m2);
                    }
                }
            }
        }
    }
    return fn_801DC718(out, start, object);
}
