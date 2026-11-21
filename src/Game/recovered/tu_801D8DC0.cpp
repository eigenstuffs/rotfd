/* Merged translation unit for .text 0x801D8DC0-0x801D9ED0 and
 * .sdata2 0x8037A4C0-0x8037A4D8: part_801D8DC0 (fn_801D8DC0, fn_801D8FD0),
 * Game/bicubic_grid_sample_801D9304.cpp, part_801D9964 (fn_801D9964,
 * fn_801D9C20).  Replaces Game/scalar_constant_8037A4C0.c, 8037A4C8.c,
 * 8037A4D0.c and the 0x8037A4D4 word of original/float_remaining_fragment_8037A4D4.s.
 *
 * .sdata2 layout: -1.0f is a NAMED constant defined at the top of the TU
 * (it is emitted ahead of the pool; the Bezier helpers read it by name, which
 * keeps their codegen identical).  1, 3, 6, -3, 2 are compiler-pooled
 * literals in first-use order (1.0f first used by fn_801D8FD0).
 * A literal -1.0f cannot be first in the pool: fn_801D8FD0 creates 1.0f
 * before any -1.0f use.
 *
 * Emission order: mwcc holds a function back until the next type or object
 * declaration, so each function is followed by an incomplete struct
 * declaration (struct FlushDummy;) to keep address order. */
extern "C" const float lbl_8037A4C0 = -1.0f;
/* ---- part_801D8DC0 ---- */
namespace part_801D8DC0 {
/* Patch scroll/tangent helpers (fn_801D8DC0, fn_801D8FD0).
 * Flags: -O4,p -fp_contract on (GC/1.3.2). Both functions EXACT
 * (fn_801D8FD0 EXACT-MOD-POOL: only the 1.0f literal pool ref).
 * Notes: 1.0f must be an inline literal used twice per expression (the unit
 * owns lbl_8037A4C4 through the TU-wide pool shared with 801D9304/801D9964). */
typedef unsigned int u32;
struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
    Vec2(const Vec2& o) : x(o.x), y(o.y) {}
    Vec2& operator=(const Vec2& o) { x = o.x; y = o.y; return *this; }
    Vec2 operator-() const { return Vec2(-x, -y); }
    Vec2 operator+(const Vec2& o) const { return Vec2(x + o.x, y + o.y); }
    Vec2 operator*(float s) const { return Vec2(x * s, y * s); }
    Vec2& operator-=(const Vec2& o) { x -= o.x; y -= o.y; return *this; }
    Vec2 operator-(const Vec2& o) const { return Vec2(x - o.x, y - o.y); }
};
#pragma fp_contract off
inline float InvSqrt(register float x) {
    register float r;
    asm { frsqrte r, x }
    return r;
}
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3& operator-=(const Vec3& o) { x -= o.x; y -= o.y; z -= o.z; return *this; }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    float LengthSq() const { return x * x + y * y + z * z; }
    Vec3& Normalize() { *this *= InvSqrt(LengthSq()); return *this; }
};
#pragma fp_contract on
struct Entry {
    void* object;
    u32 unknown[2];
    signed char generation;
    char padD[3];
    signed char getGeneration() const { return generation; }
};
struct Manager {
    int count, capacity;
    Entry* entries;
};
struct Globals {
    char unknown[0x118];
    Manager* manager;
};
extern "C" Globals lbl_801E9D24;
struct Handle {
    signed int generation : 8;
    signed int index : 24;
    template <class T> T* get() const {
        int i = index;
        Manager* m = lbl_801E9D24.manager;
        int gen = m->entries[i].getGeneration();
        return gen == generation ? (T*)m->entries[i].object : 0;
    }
};
struct Curve {
    int unknown0;
    int count;
};
extern "C" void fn_801B0620(Curve* curve, Vec2* out, float t);
struct UVTransform {
    char unknown00[0x2C];
    float m[3][3];
    Vec2 Apply(const Vec2& p) const {
        /* Result held in a small local array: array elements are coloured
         * after the named scalars, which gives the target FPR assignment
         * (t0'.x in f25, 1-uv.x in f13). Named float x/y locals give 18 diffs. */
        float d[2];
        d[0] = m[2][0] + (m[0][0] * p.x + m[1][0] * p.y);
        d[1] = m[2][1] + (m[0][1] * p.x + m[1][1] * p.y);
        return Vec2(d[0], d[1]);
    }
};
struct Material {
    char unknown00[0x20];
    Curve curve;
    char unknown28[0x88];
    float time;
    char unknownB4[4];
    Handle child;
    char Scroll(Vec2& out) {
        if (curve.count == 0) return 0;
        fn_801B0620(&curve, &out, time);
        return 1;
    }
};
struct Edge {
    unsigned short ends[2];
    unsigned short ctrl[2];
    unsigned short End(bool s) const { return ends[s]; }
};
template <class T> struct Arr {
    int count, capacity;
    T* items;
    T& operator[](int i) { return items[i]; }
};
struct Face {
    Vec2 uv[4];
    char unknown20[0x38];
    unsigned short edges[4];
    unsigned long flags;
    char unknown64[0x24];
    Handle material;
    int unknown8C;
    /* Mask-then-test form matters: it changes the pre-peephole instruction
     * count and hence the first scheduling pass (fixes the +0x1a8 swap). */
    bool Side(int i) const { return (flags & (1 << (i + 1))) != 0; }
    int Vertex(Arr<Edge>& e, int i) { return e[edges[i]].End((flags >> (i + 1)) & 1); }
};
struct Owner {
    char unknown00[0x74];
    Arr<Vec3> vertices;
    char unknown80[0x24];
    Arr<Face> faces;
    Arr<Edge> edges;
    Vec3& Vertex(Face& f, int i) { return vertices[edges[f.edges[i]].End((f.flags >> (i + 1)) & 1)]; }
};
extern "C" int fn_801D8DC0(Owner* self, int index, const Vec2& uv, Vec3* out) {
    Face& face = self->faces[index];
    Vec2 v;
    if (!face.material.get<Material>()->Scroll(v)) return 0;
    v = -v;
    Vec2 uv0 = face.uv[0];
    Vec2 e1 = face.uv[1];
    Vec2 e2 = face.uv[2];
    e1 -= uv0;
    e2 -= uv0;
    float a = -(-e2.y * v.x + v.y * e2.x) / (e1.x * e2.y - e2.x * e1.y);
    float b = (e1.x * v.y - v.x * e1.y) / (e1.x * e2.y - e2.x * e1.y);
    Vec3 p0 = self->vertices[self->edges[face.edges[0]].End(face.Side(0))];
    Vec3 p1 = self->vertices[self->edges[face.edges[1]].End(face.Side(1))];
    Vec3 p2 = self->vertices[self->edges[face.edges[2]].End(face.Side(2))];
    p1 -= p0;
    p2 -= p0;
    *out = p1 * a + p2 * b;
    return 1;
}
struct FlushDummy;
extern "C" Vec3 fn_801D9304(Owner* self, int index, const Vec2& uv, Vec3* du, Vec3* dv);
extern "C" Vec3 fn_801D8FD0(Owner* self, int index, const Vec2& dir, const Vec2& uv) {
    Vec3 du, dv;
    Vec3 pos = fn_801D9304(self, index, uv, &du, &dv);
    Face& face = self->faces[index];
    Vec2 t0 = face.uv[0];
    Vec2 t1 = face.uv[1];
    Vec2 t2 = face.uv[2];
    Vec2 t3 = face.uv[3];
    UVTransform* xf = face.material.get<Material>()->child.get<UVTransform>();
    t0 = xf->Apply(t0);
    t1 = xf->Apply(t1);
    t2 = xf->Apply(t2);
    t3 = xf->Apply(t3);
    Vec2 e1 = (t1 - t0) * (1.0f - uv.x) + (t2 - t3) * (1.0f - uv.x);
    Vec2 e2 = (t3 - t0) * (1.0f - uv.y) + (t2 - t1) * (1.0f - uv.y);
    float a = -(-e2.y * dir.x + dir.y * e2.x) / (e1.x * e2.y - e2.x * e1.y);
    float b = (e1.x * dir.y - dir.x * e1.y) / (e1.x * e2.y - e2.x * e1.y);
    return (du * a + dv * b).Normalize();
}
struct FlushDummy;

}

/* ---- Game/bicubic_grid_sample_801D9304.cpp ---- */
namespace bicubic_grid_sample_801D9304 {
/* Bicubic grid value and tangent reconstruction; see docs/notes/game-bicubic-grid-sample.md. */
struct Vec3 {
    float x, y, z;
};
}
struct Vector3_801D5330 : bicubic_grid_sample_801D9304::Vec3 {
    Vector3_801D5330();
};
namespace bicubic_grid_sample_801D9304 {
struct Vector2 {
    float x, y;
};
struct GridRecord {
    char bytes[0x90];
};
struct Surface {
    char prefix[0x7C];
    int stride;
    char prefix80[0x2C];
    GridRecord* records;
};
extern "C" {
    void fn_801D8458(Surface*, GridRecord*, Vector3_801D5330*, int);
    void fn_801D9C20(Vec3*, Vec3, Vec3, Vec3, Vec3, float);
    void fn_801D9964(Vec3*, Vec3, Vec3, Vec3, Vec3, float);
}
extern "C"    void fn_801D9304(Vec3* result, Surface* self, int index,
                           const Vector2& uv, Vec3* du, Vec3* dv) {
    Vector3_801D5330 grid[16];
    fn_801D8458(self, &self->records[index], grid, self->stride);
    Vec3 a, b, c, d, point;
    // Evaluate the four columns, then the horizontal tangent.
    fn_801D9C20(&a, grid[0], grid[4], grid[8], grid[12], uv.y);
    fn_801D9C20(&b, grid[1], grid[5], grid[9], grid[13], uv.y);
    fn_801D9C20(&c, grid[2], grid[6], grid[10], grid[14], uv.y);
    fn_801D9C20(&d, grid[3], grid[7], grid[11], grid[15], uv.y);
    fn_801D9C20(&point, a, b, c, d, uv.x);
    fn_801D9964(du, a, b, c, d, uv.x);

    // Evaluate the four rows, then the vertical tangent.
    fn_801D9C20(&a, grid[0], grid[1], grid[2], grid[3], uv.x);
    fn_801D9C20(&b, grid[4], grid[5], grid[6], grid[7], uv.x);
    fn_801D9C20(&c, grid[8], grid[9], grid[10], grid[11], uv.x);
    fn_801D9C20(&d, grid[12], grid[13], grid[14], grid[15], uv.x);
    fn_801D9C20(&point, a, b, c, d, uv.y);
    fn_801D9964(dv, a, b, c, d, uv.y);
    result->x = point.x;
    result->y = point.y;
    result->z = point.z;
}
struct FlushDummy;

}

/* ---- part_801D9964 ---- */
namespace part_801D9964 {
/* Cubic Bezier tangent (fn_801D9964) and value (fn_801D9C20).
 *
 * 3, 6, -3, 2 and 1 are literals (extern references to those defeat the
 * constant CSE the original shows).  -1.0f is the TU's named constant
 * lbl_8037A4C0 (defined at the top of the file), read by name; that keeps the
 * code identical and puts -1 ahead of the pooled 1,3,6,-3,2. */
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
};
extern "C" const float lbl_8037A4C0;
extern "C" Vec3 fn_801D9964(Vec3 a, Vec3 b, Vec3 c, Vec3 d, float t) {
    float t2 = t * t;
    Vec3 c3 = a * lbl_8037A4C0 + b * 3.0f - c * 3.0f + d * 1.0f;
    Vec3 c2 = a * 3.0f - b * 6.0f + c * 3.0f;
    Vec3 c1 = a * -3.0f + b * 3.0f;
    return c3 * t2 * 3.0f + c2 * t * 2.0f + c1;
}
struct FlushDummy;
extern "C" Vec3 fn_801D9C20(Vec3 a, Vec3 b, Vec3 c, Vec3 d, float t) {
    float t2 = t * t;
    float t3 = t2 * t;
    Vec3 c3 = a * lbl_8037A4C0 + b * 3.0f - c * 3.0f + d * 1.0f;
    Vec3 c2 = a * 3.0f - b * 6.0f + c * 3.0f;
    Vec3 c1 = a * -3.0f + b * 3.0f;
    return c3 * t3 + c2 * t2 + c1 * t + a * 1.0f;
}

}

