/* fn_802507E4 + fn_80251208 (GC/1.3.2, -O4,p, -fp_contract on): one original
 * TU (pool 0x8037B4E0..0x8037B500), split from auto_03_8024FB24_text.cpp.
 * Both functions EXACT-MOD-POOL (the TU owns .sdata2 0x8037B4E0..0x8037B500:
 * 3.0, 6.0, 1.0, 0.0, 1e-6, 0.1, int->float bias; our .sdata2 has exactly
 * that layout).
 * Load-bearing for fn_80251208:
 * - C-style locals at the top in the order boxes, patches, index, skip, mask,
 *   p, i, count, k, n, found, axisAligned, m (named vregs are numbered in
 *   reverse declaration order); `Mask skip = extra & MASK(2)` is a named
 *   local declared after index (both halves and index are spilled; spill
 *   slots follow vreg order);
 * - `long index` with the shared `short i`: `index = i` in the list loop is
 *   then a short->long conversion, which the frontend does not CSE with the
 *   short->int one of `i < count`; the grid branch writes
 *   `index = (short)i` so it does not join the subscripts' long conversion;
 * - FixedArray stack declared before QSphere bounds;
 * - FixedArray::resize goes through construct(i, n) / destroy(i, n) helpers
 *   and destroy starts with `--i`: no frontend CSE of count - 1, the helper
 *   locals are numbered below resize's n, so n takes r3 and count r4.
 * Load-bearing for fn_802507E4 (w41b; found with the pre-RA/post-RA scheduler
 * and three-pass FPR/GPR colouring simulators, see results/w41_b.json):
 * - Vec3 has no user copy constructor (B16/B17 block cut) and non-const
 *   Capsule* / Sphere* parameters; transform2 builds a named Vec3 r;
 * - only mtx, sub, c, i, found, j are C-style locals; there is no `hit`
 *   local (hits[c].x everywhere: the frontend CSE temp gives r23), and mtx /
 *   sub are assigned from inline getters (object->getMatrix(), gridSub()):
 *   the coalesced copies take the getters' temp numbers, which gives the
 *   target GPR colouring mtx r26, sub r25, (long)i r24, hits[c] r23, i*24 r22;
 * - the flag test goes through MeshSegment::flag() (lhzx base/index order);
 * - `Vec3 prev = p0;` before `float step = ...` (named step);
 * - dir is built component by component and normalised component by
 *   component (no SRA copy nodes for dir), `along` uses sqrtOrZeroDirect
 *   (fres straight into the result: one coalesced copy fewer next to step),
 *   dist uses sqrtOrZero(lengthSquared()) so its copy group is numbered above
 *   P; the frac product goes through the named `along`;
 * - statement order d, bb, e, inv (backend temp numbering of that block).
 * Other notes carried over: FixedArray with raw storage; nodeAt() accessor;
 * maskOf(const Handle&) with the index/manager/tag resolve; named Horner
 * steps q, r, p; `float zero` for the ray axis tests; 8-byte aligned
 * RayResult; best.position transformed in place. */
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

inline void* operator new(unsigned long, void* p) { return p; }

extern "C" const float lbl_8037B4C8; /* 1.0f */
extern "C" const float lbl_8037B4CC; /* 3.0f */
extern "C" const float lbl_8037B4D0; /* 6.0f */

inline float sqrtOrZero(float sq)
{
    float r = 0.0f;
    if (sq != r) r = fastSqrt(sq);
    return r;
}
inline float sqrtOrZeroDirect(register float sq)
{
    register float r = 0.0f;
    if (sq != r) {
        asm { frsqrte f4, sq
              fres r, f4 }
    }
    return r;
}
inline float rsqrt(register float x)
{
    register float r;
    asm { frsqrte r, x }
    return r;
}
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    float lengthSquared() const { return x * x + y * y + z * z; }
    float length() const { return sqrtOrZero(lengthSquared()); }
    Vec3& normalize() { *this = *this * rsqrt(lengthSquared()); return *this; }
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
    Vec3 transform2(const Vec3& v) const
    {
        Vec3 r;
        r.x = m[12] + (m[0] * v.x + m[4] * v.y + m[8] * v.z);
        r.y = m[13] + (m[1] * v.x + m[5] * v.y + m[9] * v.z);
        r.z = m[14] + (m[2] * v.x + m[6] * v.y + m[10] * v.z);
        return r;
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
    Matrix* getMatrix() { return matrix; }
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
    void destroy(int i, int n) { for (--i; i >= n; --i) data()[i].~T(); }
    void construct(int i, int n) { for (; i < n; ++i) new (&data()[i]) T; }
    void resize(int n)
    {
        if (n > count) construct(count, n);
        else if (n < count) destroy(count, n);
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
struct MeshSegment { unsigned short unknown0; unsigned short edge; int flag() const { return unknown0 & 1; } char pad[4]; Sphere sphere;
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

extern "C" const float lbl_8037B4E0; /* 3.0f */
extern "C" const float lbl_8037B4E4; /* 6.0f */
extern "C" const float lbl_8037B4E8; /* 1.0f */
extern "C" const float lbl_8037B4EC; /* 0.0f */
extern "C" const float lbl_8037B4F0; /* 1e-6f */
extern "C" const float lbl_8037B4F4; /* 0.1f */

struct Capsule { Vec3 start; float length; Vec3 dir; float radius; };
struct TubeHit {
    Vec3 position; float distance; Vec3 normal; float t;
    Object* object; Mesh* mesh; long index; signed char valid;
};
extern "C" {
signed char fn_801BA38C(const void*, const Sphere&);
float fn_800A8E8C(float, float, float);
}

inline int gridSub() { return lbl_801E9D24.grid->subdivision; }
extern "C" signed char fn_802507E4(Mesh* self, Object* object, const Info* info, Capsule* capsules, Sphere* bound, unsigned count, TubeHit* hits)
{
    const Matrix* mtx;
    int sub;
    unsigned short c;
    unsigned short i;
    signed char found;
    int j;
    found = 0;
    fn_80099A00(object->getInverse(), bound);
    Sphere meshSphere = fn_80099A00(object->matrix, &self->sphere);
    if (!overlap(*bound, meshSphere)) return 0;
    for (c = 0; c < count; c++) {
        Capsule cap;
        cap = capsules[c];
        if (fn_801BA38C(&cap, meshSphere)) {
            mtx = object->getMatrix();
            for (i = 0; i < self->tubes.count; i++) {
                if (fn_801BA38C(&cap, fn_80099A00(mtx, &self->tubes[i].getSphere()))) {
                    Vec3 p0 = mtx->transform2(self->verts[self->edgeOf(self->tubes[i]).vert[0]]);
                    Vec3 p1 = mtx->transform2(self->verts[self->edgeOf(self->tubes[i]).ctrl[0]]);
                    Vec3 p2 = mtx->transform2(self->verts[self->edgeOf(self->tubes[i]).ctrl[1]]);
                    Vec3 p3 = mtx->transform2(self->verts[self->edgeOf(self->tubes[i]).vert[1]]);
                    Vec3 a = -p0 + p1 * 3.0f - p2 * 3.0f + p3;
                    Vec3 b = p0 * 3.0f - p1 * 6.0f + p2 * 3.0f;
                    Vec3 cc = -p0 * 3.0f + p1 * 3.0f;
                    sub = gridSub();
                    Vec3 prev = p0;
                    float step = 1.0f / (float)sub;
                    for (j = 1; j < sub + 1; j++) {
                        float t = step * (float)j;
                        Vec3 q = b + fn_801AFFBC(a, t);
                        Vec3 r = cc + q * t;
                        Vec3 p = p0 + r * t;
                        Vec3 dir;
                        dir.x = p.x - prev.x;
                        dir.y = p.y - prev.y;
                        dir.z = p.z - prev.z;
                        float len = dir.length();
                        if (len > 1e-6f) { float k = 1.0f / len; dir.x *= k; dir.y *= k; dir.z *= k; }
                        float d = (cap.start - prev).dot(dir);
                        float bb = dir.dot(cap.dir);
                        float e = (cap.start - prev).dot(cap.dir);
                        float inv = 1.0f / (1.0f - bb * bb);
                        float s = inv * (d - bb * e);
                        float u = inv * (bb * d + -e);
                        s = fn_800A8E8C(s, 0.0f, len);
                        u = fn_800A8E8C(u, 0.0f, cap.length);
                        Vec3 P = prev + dir * s;
                        Vec3 Q = cap.start + cap.dir * u;
                        float dist = sqrtOrZero((Q - P).lengthSquared());
                        if (dist < 0.1f) {
                            if (!hits[c].valid || dist < hits[c].distance) {
                                hits[c].distance = dist;
                                hits[c].position = P;
                                if (self->tubes[i].flag()) {
                                    hits[c].normal = Vec3(0.0f, 1.0f, 0.0f).cross(dir).normalize();
                                } else {
                                    hits[c].normal = dir.cross(Vec3(0.0f, 1.0f, 0.0f)).normalize();
                                }
                                hits[c].valid = 1;
                                hits[c].object = object;
                                hits[c].mesh = self;
                                hits[c].index = i;
                                hits[c].t = step * (float)(j - 1);
                                float along = sqrtOrZeroDirect((P - prev).lengthSquared()) / len;
                                float frac = along * (1.0f / (float)(sub + 1));
                                hits[c].t += frac;
                                found = 1;
                            }
                        }
                        prev = p;
                    }
                }
            }
        }
    }
    return found;
}

extern "C" const Vec3 game_vec4_zero;
struct QSphere {
    Vec3 center;
    float r;
    QSphere() : center(game_vec4_zero), r(1.0f) {}
    QSphere& operator=(const Sphere& s) { center = s.center; r = s.r; return *this; }
};
struct Ray { Vec3 origin; float length; Vec3 dir; float pad; };
struct ObjectX {
    char unknown00[0x30];
    Matrix3 rotation;
    char unknown54[0x84];
    Vec3 scale;
    char unknownE4[0x3c];
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
struct QueryHit {
    Vec3 position; float distance; Vec3 normal; int index; float u, v;
    Mask mask; ObjectX* object; Mesh* mesh; const Info* info; signed char valid;
};
struct RayResult { Vec3 position; float distance; Vec3 normal; float u, v; float pad; Mask pad2; };
extern "C" {
Ray fn_80245250(const Matrix*, const Ray*);
signed char fn_801B98A4(const QSphere*, const Ray*);
signed char fn_801B6430(const Ray*, const Vec3*, const Vec3*, RayResult*);
signed char fn_80264CCC(SpatialGrid*, const Ray*);
void fn_802659A4(SpatialGrid*, const Ray*);
signed char fn_801B602C(const Ray*, const void*);
signed char fn_801DF498(const Ray*, Vertex*, RayResult*, int);
signed char fn_801DF604(const Ray*, Vertex*, RayResult*, int);
}

extern "C" signed char fn_80251208(Mesh* self, ObjectX* object, const Info* info, const Ray* ray, QueryHit* out, Mask flags, Mask extra)
{
    PatchBox* boxes;
    Patch* patches;
    long index;
    Mask skip;
    Mask mask;
    short* p;
    short i;
    int count;
    int k;
    int n;
    signed char found;
    signed char axisAligned;
    Mask m;
    skip = extra & MASK(2);
    if (skip && (extra & MASK(4))) return 0;
    if (info->flags & 1) return 0;
    if (!(object->flags & 0x40000)) return 0;
    FixedArray<Entry, 16> stack;
    QSphere bounds;
    found = 0;
    axisAligned = 0;
    n = lbl_801E9D24.grid->subdivision + 1;
    if (0.0f == object->scale.x + object->scale.y + object->scale.z) return 0;
    Ray local = fn_80245250(object->getInverse(), ray);
    float zero = 0.0f;
    if ((zero == local.dir.x && zero == local.dir.z && local.dir.y != zero)
        || (local.dir.x != zero && zero == local.dir.y && zero == local.dir.z)
        || (zero == local.dir.x && zero == local.dir.y && local.dir.z != zero))
        axisAligned = 1;
    RayResult hit;
    RayResult best;
    if ((flags & MASK(4)) && (int)self->segments.count != 0) {
        stack.resize(0);
        stack.push(Entry(0));
        for (;;) {
            short seg = -1;
            while (stack.count != 0) {
                Entry& top = stack.back();
                Node& node = self->nodeAt(top.node);
                bounds = node.sphere;
                if (fn_801B98A4(&bounds, &local)) {
                    if (top.state == 0) {
                        top.state++;
                        if (node.flags & 1) {
                            bounds = self->segments[node.child[0]].sphere;
                            if (fn_801B98A4(&bounds, &local)) {
                                seg = node.child[0];
                                break;
                            }
                        } else if (!(node.flags & 4)) {
                            stack.push(Entry(node.child[0]));
                        }
                    } else if (top.state == 1) {
                        top.state++;
                        if (node.flags & 2) {
                            bounds = self->segments[node.child[1]].sphere;
                            if (fn_801B98A4(&bounds, &local)) {
                                seg = node.child[1];
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
            if (seg == -1) break;
            Vec3 p0 = self->verts[self->edgeOf(self->segments[seg]).vert[0]];
            Vec3 p1 = self->verts[self->edgeOf(self->segments[seg]).ctrl[0]];
            Vec3 p2 = self->verts[self->edgeOf(self->segments[seg]).ctrl[1]];
            Vec3 p3 = self->verts[self->edgeOf(self->segments[seg]).vert[1]];
            Vec3 a = -p0 + p1 * 3.0f - p2 * 3.0f + p3;
            Vec3 b = p0 * 3.0f - p1 * 6.0f + p2 * 3.0f;
            Vec3 c = -p0 * 3.0f + p1 * 3.0f;
            float step = 1.0f / (float)n;
            Vec3 prev = p0;
            for (int j = 1; j <= n; j++) {
                float t = step * (float)j;
                Vec3 q = b + fn_801AFFBC(a, t);
                Vec3 r = c + q * t;
                Vec3 cur = p0 + r * t;
                if (fn_801B6430(&local, &prev, &cur, &hit)) {
                    if (!found || hit.distance < best.distance) {
                        best.distance = hit.distance;
                        mask = MASK(4);
                        found = 1;
                        best.position = hit.position;
                        best.normal = hit.normal;
                        local.length = best.distance;
                        out->index = seg;
                    }
                }
                prev = cur;
            }
        }
    }
    i = 0;
    count = self->patches.count;
    if (!skip) {
        if (self->grid) {
            if (fn_80264CCC(self->grid, &local) && fn_801BA38C(&local, self->sphere)) {
                fn_802659A4(self->grid, &local);
                short buf[32];
                boxes = self->boxes;
                patches = self->patches.items;
                while ((k = fn_802654E8(self->grid, buf, 32)) != 0) {
                    p = &buf[k];
                    while (p--, k-- != 0) {
                        i = *p;
                        m = maskOf(patches[i].handle);
                        if ((flags & m) && !(extra & m)) {
                            if (fn_801B602C(&local, boxes[i].box)) {
                                if (axisAligned) {
                                    if (fn_801DF498(&local, fn_801D6BA8(self, i, info), &hit, n)) {
                                        if (!found || hit.distance < best.distance) {
                                            best.distance = hit.distance;
                                            mask = m;
                                            index = (short)i;
                                            found = 1;
                                            best.normal = hit.normal;
                                            local.length = best.distance;
                                            best.position = hit.position;
                                        }
                                    }
                                } else {
                                    if (fn_801DF604(&local, fn_801D6BA8(self, i, info), &hit, n)) {
                                        if (!found || hit.distance < best.distance) {
                                            best.distance = hit.distance;
                                            mask = m;
                                            index = (short)i;
                                            found = 1;
                                            best.normal = hit.normal;
                                            local.length = best.distance;
                                            best.position = hit.position;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            PatchBox* box = info->boxes;
            Patch* patch = self->patches.items;
            for (; i < count; i++, box++, patch++) {
                int m = maskOf(patch->handle);
                if ((flags & m) && !(extra & m)) {
                    if (fn_801BA38C(&local, box->sphere)) {
                        if (axisAligned) {
                            if (fn_801DF498(&local, fn_801D6BA8(self, i, info), &hit, n)) {
                                if (!found || hit.distance < best.distance) {
                                    best.distance = hit.distance;
                                    mask = m;
                                    index = i;
                                    found = 1;
                                    best.normal = hit.normal;
                                    local.length = best.distance;
                                    best.position = hit.position;
                                }
                            }
                        } else {
                            if (fn_801DF604(&local, fn_801D6BA8(self, i, info), &hit, n)) {
                                if (!found || hit.distance < best.distance) {
                                    best.distance = hit.distance;
                                    mask = m;
                                    index = i;
                                    found = 1;
                                    best.normal = hit.normal;
                                    local.length = best.distance;
                                    best.position = hit.position;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (found) {
        best.position = object->matrix->transform(best.position);
        float d = ray->dir.dot(best.position - ray->origin);
        if (!out->valid || d < out->distance) {
            out->distance = d;
            out->position = best.position;
            out->normal = object->rotation.transform(best.normal);
            out->mask = mask;
            out->u = best.u;
            out->v = best.v;
            out->index = index;
            out->object = object;
            out->mesh = self;
            out->info = info;
            out->valid = 1;
        }
    }
    return found;
}
