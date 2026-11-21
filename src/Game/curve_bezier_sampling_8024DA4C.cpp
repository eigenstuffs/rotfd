// Curve sampling unit (fn_8024DA4C..fn_8024DEF8) with its own literal pool
// 0x8037B460..0x8037B46C (1e-6, 3.0, 6.0); full source from
// scratch/claude_match/auto_03_8024DA4C_text/final.cpp.
/* Curve sampling (fn_8024DA4C..fn_8024DEF8): world position of a curve
 * parameter through an owner matrix, linear extrapolation past the curve
 * ends, arc-length position on a cubic Bezier segment, and the segment's
 * cubic coefficients.
 *
 * Matching notes:
 * - All four functions use compiler-generated Vec3 copy members, which makes
 *   CodeWarrior defer their generation and emit them in reverse definition
 *   order; the source is therefore written in reverse address order.
 * - 1e-6f, 3.0f and 6.0f are this unit's own pooled literals; the object's
 *   .sdata2 (12 bytes, 8-aligned) is exactly lbl_8037B460 (1e-6),
 *   lbl_8037B464 (3.0) and lbl_8037B468 (6.0) in that order. No other code
 *   references them. Extern labels for 3.0/6.0 change the register
 *   allocation of fn_8024DEF8 (best extern variant ~82%).
 * - The shared 1.0/0.0/0.125 constants (lbl_8037B448/4C/50) are extern with
 *   distinct read forms where the original reloaded the literal. */
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

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

extern "C" const float lbl_8037B448; /* 1.0f */
extern "C" const float lbl_8037B44C; /* 0.0f */
extern "C" const float lbl_8037B450; /* 0.125f */

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3& operator+=(const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_8037B44C;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

inline float absf(float x) { return __fabs(x); }

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
    float fn_8024DD38(Curve*, float, Vec3*);
    void fn_8024DEF8(Curve*, int, Vec3*, Vec3*, Vec3*, Vec3*);
    void fn_801AFFBC(Vec3*, const Vec3*, float);
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

extern "C" float fn_8024DD38(Curve* self, float t, Vec3* out)
{
    float scale = self->scale;
    float u = scale * t;
    while (u < lbl_8037B44C) u += scale;
    while (u > scale) u -= scale;
    float sum = *(const float*)&lbl_8037B44C;
    int i;
    for (i = 0; i < self->count; ++i) {
        if (sum > u) break;
        sum += self->entries[i].length;
    }
    float s = *(const float*)(unsigned long)&lbl_8037B44C;
    float r = s;
    CurveEntry* e = &self->entries[i - 1];
    sum -= e->length;
    u -= sum;
    CurveSub* sub = e->sub;
    for (int k = 0; k < 8; ++k, ++sub) {
        float len = sub->length;
        if (s + len > u) {
            r += lbl_8037B450 * ((u - s) / len);
            break;
        }
        r += *(const float*)&lbl_8037B450;
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
    if (len < 1e-6f) return *(const float*)&lbl_8037B44C;
    Vec3 dir = diff * (lbl_8037B448 / len);
    if (dist > len) *out += diff;
    else *out += dir * len;
    return dist;
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

