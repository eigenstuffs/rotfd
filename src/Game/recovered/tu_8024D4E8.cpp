/* Curve translation unit, .text 0x8024D4E8..0x8024E200, .sdata2 0x8037B448..0x8037B46C.
 * .sdata2 order: 1.0f (lbl_8037B448, named, defined first), then the pooled literals in
 * first-use order: 0.0f, 0.125f, 0.999999f, the int->float bias double, 1e-6f, 3.0f, 6.0f.
 * 1.0f precedes every pooled literal although the first function does not use it, so it is a
 * named definition: it is defined inside a namespace (emitted at the definition point) and the
 * code refers to the global extern declaration of the same C symbol, which keeps the compiler
 * from folding the value into a second pooled copy. */
namespace curve_pool { extern "C" { extern const float lbl_8037B448 = 1.0f; } }
extern "C" const float lbl_8037B448;
#ifndef W3_5_CURVE_H
#define W3_5_CURVE_H
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
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3& operator+=(const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
    float lengthRef() const
    {
        const Vec3& v = *this;
        float sq = v.x * v.x + v.y * v.y + v.z * v.z;
        float r = 0.0f;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = 0.0f;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};
inline float lengthRef(const Vec3& v)
{
    float sq = v.x * v.x + v.y * v.y + v.z * v.z;
    float r = 0.0f;
    if (sq != r) r = fastSqrt(sq);
    return r;
}
struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
    Vec2 operator+(float s) const { return Vec2(x + s, y + s); }
    Vec2 operator*(const Vec2& v) const { return Vec2(x * v.x, y * v.y); }
};
struct Color { float r, g, b, a; Color() {} Color(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {} };

struct CurveSub { char unknown00[0x18]; float length; };
struct CurveEntry { int point[4]; char unknown10[4]; float length; CurveSub sub[8]; };
struct Curve {
    char unknown00[0x7C];
    Vec3* points;
    int count, capacity;
    CurveEntry* entries;
    char unknown8C[0x10];
    float scale;
};

extern "C" {
    void fn_8024DEF8(Curve*, int, Vec3*, Vec3*, Vec3*, Vec3*);
    void fn_801AFFBC(Vec3*, const Vec3*, float);
    void fn_80238180(void*, const Vec2*, const Vec2*, const Color*);
}
#endif

struct Params { float x, y, z, offset; };

extern "C" float fn_8024D4E8(const Vec3* a, const Vec3* b, const Vec3* c, const Vec3* d, float u)
{
    float length = 0.0f;
    Vec3 prev = *d;
    for (int i = 1; i <= 8; ++i) {
        float t = 0.125f * (float)i;
        Vec3 cubic;
        fn_801AFFBC(&cubic, a, t);
        Vec3 p = *b + cubic;
        p = p * t;
        p = *c + p;
        p = p * t;
        p = *d + p;
        float len = (p - prev).lengthRef();
        if (u < 0.999999f && t > u) {
            length += len * (u + (0.125f - t)) / 0.125f;
            break;
        }
        prev = p;
        length += len;
    }
    return length;
}

struct CurveX : Curve {
    int getCount() const { return count; }
};
inline Vec2 projectXZ(const Vec3& v, float offset)
{
    float Y = v.z; float X = v.x; Y += offset; X += offset; return Vec2(X, Y);
}
inline Vec3 diff(const Vec3& a, const Vec3& b) { return a.operator-(b); }
inline Vec3 diff2(const Vec3& a, const Vec3& b) { return diff(a, b); }
extern "C" void fn_8024D6F4(Curve* self_, void* raster, const Params* params, const Vec2* scale)
{
    CurveX* self = (CurveX*)self_;
    int n = self->getCount();
    float offset = params->offset;
    for (int i = 0; i < n; ++i) {
        const Vec3& p0 = diff2(self->points[self->entries[i].point[0]], *(const Vec3*)params);
        const Vec3& p1 = diff2(self->points[self->entries[i].point[1]], *(const Vec3*)params);
        const Vec2& q0 = projectXZ(p0, offset);
        Vec2 s0 = q0 * *scale;
        const Vec2& q1 = projectXZ(p1, offset);
        Vec2 s1 = q1 * *scale;
        Color color(0.0f, 0.0f, 0.0f, lbl_8037B448);
        fn_80238180(raster, &s0, &s1, &color);
    }
}


struct CurveCursor { int index; float distance; };

extern "C" void fn_8024D868(Curve* self, int* index, float* acc, Vec3* out, float t)
{
    if (*index < 0) {
        *index = 0;
        *acc = 0.0f;
    }
    CurveEntry* e = &self->entries[*index];
    while (*index < self->count) {
        if (*acc + e->length > t) break;
        *acc += e->length;
        ++e;
        ++*index;
    }
    float s; float r; float sum; float u; sum = *acc; r = 0.0f; u = t - sum; s = r;
    CurveSub* sub = e->sub;
    for (int k = 0; k < 8; ++k, ++sub) {
        sum = sub->length;
        if (s + sum > u) {
            r += 0.125f * ((u - s) / sum);
            break;
        }
        r += 0.125f;
        s += sum;
    }
    Vec3 a, b, c, d;
    fn_8024DEF8(self, *(int*)(unsigned long)index, &a, &b, &c, &d);
    Vec3 cubic;
    fn_801AFFBC(&cubic, &a, r);
    Vec3 p = b + cubic;
    p = p * r;
    p = c + p;
    p = p * r;
    *out = d + p;
}


#ifndef GAME_ENGINE_OWNER_SMALL_LOOPS_H
#define GAME_ENGINE_OWNER_SMALL_LOOPS_H

struct CurveSegmentFindEntry {
    char unknown00[0x14];
    float length;
    char unknown18[0xE0];
};
struct CurveSegmentFindOwner {
    char unknown00[0x80];
    int count, capacity;
    CurveSegmentFindEntry* entries;
    char unknown8C[0x10];
    float scale;
};
struct OwnerEmptyScanOwner {
    char unknown00[0x64];
    int count;
};
typedef char CurveSegmentFindEntrySize[sizeof(CurveSegmentFindEntry)==248?1:-1];
extern "C" {
    int fn_8024D9FC(CurveSegmentFindOwner*, float);
    signed char fn_8024A040(OwnerEmptyScanOwner*);
}
#endif

extern "C" int fn_8024D9FC(CurveSegmentFindOwner* self, float value) {
    float target = self->scale * value;
    float sum = 0.0f;
    int i;
    for (i = 0; i < self->count; ++i) {
        if (sum > target) break;
        sum += self->entries[i].length;
    }
    return i - 1;
}

/* Curve sampling (fn_8024DA4C..fn_8024DEF8): world position of a curve parameter through an
 * owner matrix, linear extrapolation past the curve ends, arc-length position on a cubic Bezier
 * segment, and the segment's cubic coefficients. */
typedef unsigned long Word;
struct Handle { union { Word word; struct { signed int tag : 8, index : 24; } bits; }; };
struct Node { char unknown00[0x124]; float* matrix; };
struct Entry { Node* object; char unknown04[8]; signed char tag; char pad[3];
    signed char getTag() const { return tag; } };
struct Manager { char unknown00[8]; Entry* entries; };
extern "C" struct Global { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;
inline Node* resolve(const Handle& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}

inline float absf(float x) { return __fabs(x); }

extern "C" {
    float fn_8024DD38(Curve*, float, Vec3*);
}

extern "C" float fn_8024DA4C(Curve* self, const Handle* handle, Vec3* v, float t)
{
    float r = fn_8024DD38(self, t, v);
    float* m = resolve(*handle)->matrix;
    float X = m[0] * v->x + m[4] * v->y + m[8] * v->z + m[12];
    float Y = m[1] * v->x + m[5] * v->y + m[9] * v->z + m[13];
    float Z = m[2] * v->x + m[6] * v->y + m[10] * v->z + m[14];
    *v = Vec3(X, Y, Z);
    return r * Vec3(m[0], m[4], m[8]).length();
}


extern "C" float fn_8024DB7C(Curve* self, float t, Vec3* out)
{
    float d;
    Vec3 diff;
    if (t < 1e-6f) {
        d = absf(t);
        *out = self->points[self->entries[0].point[0]];
        diff = *out - self->points[self->entries[0].point[2]];
    } else {
        d = t - lbl_8037B448;
        int n = self->count - 1;
        int k = 3;
        *out = self->points[self->entries[n].point[1]];
        diff = *out - self->points[self->entries[n].point[k]];
    }
    float dist = __fabs(self->scale * d);
    float len = diff.length();
    if (len < 1e-6f) return 0.0f;
    Vec3 dir = diff * (lbl_8037B448 / len);
    if (dist > len) *out += diff;
    else *out += dir * len;
    return dist;
}

extern "C" float fn_8024DD38(Curve* self, float t, Vec3* out)
{
    float scale = self->scale;
    float u = scale * t;
    while (u < 0.0f) u += scale;
    while (u > scale) u -= scale;
    float sum = 0.0f;
    int i;
    for (i = 0; i < self->count; ++i) {
        if (sum > u) break;
        sum += self->entries[i].length;
    }
    float s = 0.0f;
    float r = s;
    CurveEntry* e = &self->entries[i - 1];
    sum -= e->length;
    u -= sum;
    CurveSub* sub = e->sub;
    for (int k = 0; k < 8; ++k, ++sub) {
        float len = sub->length;
        if (s + len > u) {
            r += 0.125f * ((u - s) / len);
            break;
        }
        r += 0.125f;
        s += len;
    }
    Vec3 a, b, c, d;
    fn_8024DEF8(self, i - 1, &a, &b, &c, &d);
    Vec3 cubic;
    fn_801AFFBC(&cubic, &a, r);
    Vec3 p = b + cubic;
    p = p * r;
    p = c + p;
    p = p * r;
    *out = d + p;
    return u;
}

extern "C" void fn_8024DEF8(Curve* self, int seg, Vec3* a, Vec3* b, Vec3* c, Vec3* d)
{
    CurveEntry& e = self->entries[seg];
    Vec3* pts = self->points;
    Vec3 p0 = pts[e.point[0]];
    Vec3 p1 = pts[e.point[2]];
    Vec3 p2 = pts[e.point[3]];
    Vec3 p3 = pts[e.point[1]];
    *a = -p0 + p1 * 3.0f - p2 * 3.0f + p3;
    *b = p0 * 3.0f - p1 * 6.0f + p2 * 3.0f;
    *c = -p0 * 3.0f + p1 * 3.0f;
    *d = p0;
}

/* Observed resource initializer; tables and scalar constants keep their
 * existing owners. The named flag value preserves the native update order. */
typedef unsigned short u16;
typedef unsigned long u32;
struct Record_8024E18C {
    char gap00[8];
    void* table;
    char gap0C[0x60];
    u16 kind;
    u16 flags;
    char gap70[4];
    u32 handles[6];
    char gap8C[0x10];
    float value;
};
extern "C" void fn_80243F28(Record_8024E18C*);
extern "C" char lbl_802EA558[0x58];
extern "C" Record_8024E18C* fn_8024E18C(Record_8024E18C* self) {
    fn_80243F28(self);
    self->table = lbl_802EA558;
    float initialValue = 0.0f;
    self->handles[0] = 0;
    self->handles[1] = 0;
    self->handles[2] = 0;
    self->handles[3] = 0;
    self->handles[4] = 0;
    self->handles[5] = 0;
    self->kind = 2;
    unsigned short enabledFlags = self->flags;
    enabledFlags |= 0x20;
    self->flags = enabledFlags;
    self->value = initialValue;
    return self;
}
typedef char CheckRecord_8024E18CSize[sizeof(Record_8024E18C)==0xA0?1:-1];
