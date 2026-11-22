typedef unsigned short U16;

#define T1 3
#define R 1
#define F 0
#define H 0
#define LT U16
#define GT U16
#define IT U16
#define G 1
struct LinkNode {
    unsigned int owner;
    U16 record;
    U16 pad;
    U16 next, prev;
};

struct Vec3Slot { float v[3]; };
namespace patch6104 {
struct Vec3 {
    float x, y, z;
    Vec3() {}
    /* w35b: user copy ctor -> the last operator of 'Vec3 a = ...'/'Vec3 b = ...' is built in a temp
       (x,y,z order) and copied, instead of R-to-L scalar args (z,y,x); fixes the pre-RA schedule */
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    /* w41a: copy-then-+= add (loop-1 c): the result lives in the SRA members of the inline local r
       (numbered after all inline-argument temps), not in operator+'s argument temps */
    Vec3 AddC(const Vec3& o) const { Vec3 r(*this); r += o; return r; }
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3& operator+=(const Vec3& o) { x += o.x; y += o.y; z += o.z; return *this; }
    void Set(const Vec3& v, float s) { x = v.x * s; y = v.y * s; z = v.z * s; }
    Vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    Vec3 Cross(const Vec3& o) const { return Vec3(y * o.z - z * o.y, z * o.x - x * o.z, x * o.y - y * o.x); }
    float LengthSq() const { return x * x + y * y + z * z; }
};
struct Vec4 : Vec3 {
    float w;
    Vec4() {}
    Vec4(float a, float b, float c, float d) : Vec3(a, b, c), w(d) {}
    Vec4 operator-(const Vec4& o) const { return Vec4(x - o.x, y - o.y, z - o.z, w - o.w); }
    Vec3 Cross(const Vec4& o) const { return Vec3(y * o.z - z * o.y, z * o.x - x * o.z, x * o.y - y * o.x); }
};
inline float FastSqrt(register float sq) {
    register float r = 0.0f;
    if (sq != r) {
        asm { frsqrte f4, sq
              fres r, f4 }
    }
    return r;
}
/* w41a: member-assign constructors for loop 1 (p0 is a const ref): the p0 loads and their fneg/fmuls
   are backend vregs created x,y,z after the K3 load (target key order -p0.z > p0.z > -p0.y > ... > K3) */
struct Neg3 : Vec3 { Neg3(const Vec3& v) { x = -v.x; y = -v.y; z = -v.z; } };
struct Mul3 : Vec3 { Mul3(const Vec3& v, float s) { x = v.x * s; y = v.y * s; z = v.z * s; } };
inline void Normal(Vec4* out, const Vec4& a, const Vec4& b, const Vec4& c) {
    Vec3 n = (c - a).Cross(b - a);
    float len = FastSqrt(n.LengthSq());
    if (len <= 0.000001f) {
        len = 0.0f;
    } else {
        n *= 1.0f / len;
    }
    out->x = n.x;
    out->y = n.y;
    out->z = n.z;
    out->w = len;
}
}
typedef patch6104::Vec4 Vec4Slot;

template <class T, class Base> struct LinkCache : Base {
    int count;
    int capacity;
    char* entries;
    int stride;
    T* data;

#if T1==1
    LinkNode& at(int i) { return ((LinkNode*)entries)[i]; }
    void touch(int n) {
        at(at(n).next).prev = at(n).prev;
        at(at(n).prev).next = at(n).next;
        at(n).prev = at(0).prev;
        at(n).next = 0;
        at(at(0).prev).next = n;
        at(0).prev = n;
    }
#elif T1==2
    LinkNode& at(int i) { return ((LinkNode*)entries)[i]; }
    void touch(int n) {
        LinkNode* e = (LinkNode*)entries;
        e[at(n).next].prev = at(n).prev;
        e[at(n).prev].next = at(n).next;
        at(n).prev = at(0).prev;
        at(n).next = 0;
        e[at(0).prev].next = n;
        at(0).prev = n;
    }
#elif T1==3
    LinkNode& at(int i) { return ((LinkNode*)entries)[i]; }
    void touch(int n) {
        ((LinkNode*)entries)[at(n).next].prev = at(n).prev;
        ((LinkNode*)entries)[at(n).prev].next = at(n).next;
        at(n).prev = at(0).prev;
        at(n).next = 0;
        ((LinkNode*)entries)[at(0).prev].next = n;
        at(0).prev = n;
    }
#elif T1==4
    LinkNode& at(int i) { return ((LinkNode*)entries)[i]; }
    U16& prev(int i) { return at(i).prev; }
    U16& next(int i) { return at(i).next; }
    void touch(int n) {
        prev(next(n)) = prev(n);
        next(prev(n)) = next(n);
        prev(n) = prev(0);
        next(n) = 0;
        next(prev(0)) = n;
        prev(0) = n;
    }
#elif T1==5
    LinkNode& at(int i) { return ((LinkNode*)entries)[i]; }
    void unlink(int n) {
        at(at(n).next).prev = at(n).prev;
        at(at(n).prev).next = at(n).next;
    }
    void link(int n) {
        at(n).prev = at(0).prev;
        at(n).next = 0;
        at(at(0).prev).next = n;
        at(0).prev = n;
    }
    void touch(int n) { unlink(n); link(n); }
#else
    LinkNode* at(int i) { return (LinkNode*)(entries + i * 12); }
    void touch(int n) {
        at(at(n)->next)->prev = at(n)->prev;
        at(at(n)->prev)->next = at(n)->next;
        at(n)->prev = at(0)->prev;
        at(n)->next = 0;
        at(at(0)->prev)->next = n;
        at(0)->prev = n;
    }
#endif
#if G==1
    typedef T Elem;
#define AT(i) (((LinkNode*)entries)[i])
    T* get6(U16 index) {
        int n = index + 1;
        AT(AT(n).next).prev = AT(n).prev;
        AT(AT(n).prev).next = AT(n).next;
        AT(n).prev = AT(0).prev;
        AT(n).next = 0;
        AT(AT(0).prev).next = n;
        AT(0).prev = n;
        return &data[index * stride];
    }
    void touchIndex(U16 index) { int n = index + 1; touch(n); }
    T* item(U16 index) { return &data[index * stride]; }
    T* get2(U16 index) { touchIndex(index); return item(index); }
    T* get3(U16 index) { U16 i = index; int n = i + 1; touch(n); return &data[i * stride]; }
    T* get(GT index) {
        int n = index;
        n++;
        touch(n);
        return &data[index * stride];
    }
#elif G==2
    T* get(int index) {
        touch(index + 1);
        return &data[index * stride];
    }
#elif G==3
    void touch2(int index) {
        int n = index + 1;
        ((LinkNode*)entries)[at(n).next].prev = at(n).prev;
        ((LinkNode*)entries)[at(n).prev].next = at(n).next;
        at(n).prev = at(0).prev;
        at(n).next = 0;
        ((LinkNode*)entries)[at(0).prev].next = n;
        at(0).prev = n;
    }
    T* get(U16 index) {
        touch2(index);
        return &data[index * stride];
    }
#elif G==4
    T* get(U16 index) {
        U16 n = index + 1;
        ((LinkNode*)entries)[at(n).next].prev = at(n).prev;
        ((LinkNode*)entries)[at(n).prev].next = at(n).next;
        at(n).prev = at(0).prev;
        at(n).next = 0;
        ((LinkNode*)entries)[at(0).prev].next = n;
        at(0).prev = n;
        return &data[index * stride];
    }
#else
    T* get(U16 index) {
        touch(index + 1);
        return &data[index * stride];
    }
#endif
};
#if F==1
template <class C> inline typename C::Elem* cget(C* c, U16 index) { int n = index + 1; c->touch(n); return &c->data[index * c->stride]; }
#define GET(c, i) cget(c, i)
#elif F==2
template <class C> inline typename C::Elem* cget(U16 index, C* c) { int n = index + 1; c->touch(n); return &c->data[index * c->stride]; }
#define GET(c, i) cget(i, c)
#elif F==6
#define GET(c, i) (c)->get6(i)
#elif F==3
#define GET(c, i) ((c)->touchIndex(i), (c)->item(i))
#elif F==4
#define GET(c, i) (c)->get2(i)
#elif F==5
#define GET(c, i) (c)->get3(i)
#else
#define GET(c, i) (c)->get(i)
#endif
struct NoBase {};
struct PadBase { int pad; };
typedef LinkCache<Vec3Slot, NoBase> Cache12;
typedef LinkCache<Vec4Slot, PadBase> Cache16;

struct Record {
    char pad[0x60];
    U16 link;
    char tail[6];
};
template <class T> struct PArr {
    int count;
    int capacity;
    T* data;
    T& operator[](IT i) { return data[i]; }
};
struct Source {
    char pad[0x20];
    U16 link;
    char pad22[2];
    PArr<Record> records;
};
struct Sample { char data[0x90]; };
struct Self {
    char pad[0x6e];
    U16 flags;
    char pad70[0xac - 0x70];
    Sample* samples;
    char padb0[0xc8 - 0xb0];
    PArr<Record> records;
};

extern "C" {
extern struct Globals {
    char pad[0x128];
    Cache16* list;
    Cache16* list2;
    Cache12* list3;
} lbl_801E9D24;
U16 fn_801D7B5C(Cache16*, Source*, U16);
U16 fn_801D7C28(Cache16*, Self*, U16);

void fn_801D6104(Self*, Vec4Slot*, Sample*, Vec3Slot*);
}

/* ---- fn_801D5DF8: sample the cached control grid at (u,v) -------------
 * STATUS: same size (780), ~85 diffs = FP register allocation / load order in
 * the two triangle branches and the shared tail.  Structure, constants, frame
 * and all integer code match. */
extern "C" {
float fn_800AA52C(float, float); /* max */
float fn_800AA53C(float, float); /* min */
double floor(double);
Vec4Slot* fn_801D6BA8(Self* self, U16 record, void* source);
}
struct SVec2 {
    float x, y;
    SVec2() {}
    SVec2(float a, float b) : x(a), y(b) {}
    SVec2 operator-(const SVec2& o) const { return SVec2(x - o.x, y - o.y); }
    SVec2 Min(float m) const { float a = fn_800AA53C(x, m); float b = fn_800AA53C(y, m); return SVec2(a, b); }
    SVec2 Max(float m) const { float a = fn_800AA52C(x, m); float b = fn_800AA52C(y, m); return SVec2(a, b); }
};
struct SVec3 {
    float x, y, z;
    SVec3() {}
    SVec3(float a, float b, float c) : x(a), y(b), z(c) {}
    void Sub(const SVec3& a, const SVec3& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; }
};
struct SVec4 : SVec3 {
    float w;
    SVec4() {}
    SVec4(float a, float b, float c, float d) : SVec3(a, b, c), w(d) {}
    void Sub(const SVec4& a, const SVec4& b) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; w = a.w - b.w; }
    /* constructor form: the frontend CSE numbers its temps by the order of the 2nd occurrence;
       args are evaluated right to left, so w..x -> base group colours x<y<z<w as in the target */
    void SubC(const SVec4& a, const SVec4& b) { *this = SVec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
};
inline SVec3 operator+(const SVec3& a, const SVec3& o) { return SVec3(a.x + o.x, a.y + o.y, a.z + o.z); }
inline SVec3 operator*(const SVec3& a, float s) { return SVec3(a.x * s, a.y * s, a.z * s); }
inline SVec4 operator+(const SVec4& a, const SVec4& o) { return SVec4(a.x + o.x, a.y + o.y, a.z + o.z, a.w + o.w); }
inline SVec4 operator*(const SVec4& a, float s) { return SVec4(a.x * s, a.y * s, a.z * s, a.w * s); }
/* fn_801D5DF8. Levers: re-reading grid[k] in the Subs (frontend CSE temps -> fmr copies coalesced at RA ->
 * post-RA reschedule of both triangle blocks as in the target); SubC in the else branch (CSE temp order);
 * 'float m' for the Min argument.
 * merge42: every float constant of the TU is a plain literal. The compiler pools them for the whole unit:
 * frontend literals of fn_801D5DF8 first (0.0001, 0.0, 0.999999, 1.0), then its int->float bias, then the new
 * literals of fn_801D6104 (3.0, 6.0, 2.0, 1e-6; its 1.0 and 0.0 reuse the entries above). That is exactly
 * .sdata2 0x8037A478..0x8037A4A0 (lbl_8037A478..lbl_8037A49C). */
inline int FloorI(float x) { return x < 0.0f ? (int)(x - 0.999999f) : (int)x; }
extern "C" SVec3 fn_801D5DF8(Self* self, void* source, int record, SVec2* uv) {
    int n = lbl_801E9D24.list->pad + 1;
    SVec4* grid = (SVec4*)fn_801D6BA8(self, record, source);
    uv->x *= (float)n;
    uv->y *= (float)n;
    float m = (float)n - 0.0001f;
    *uv = uv->Min(m);
    *uv = uv->Max(0.0f);
    int ix = FloorI(uv->x);
    int iy = FloorI(uv->y);
    int idx = ix + (n + 1) * iy;
    uv->x -= (float)floor(uv->x);
    uv->y -= (float)floor(uv->y);
    SVec4 base, d1;
    SVec3 d2;
    if (uv->x + uv->y < 1.0f) {
        base = grid[idx];
        d1.Sub(grid[idx + 1], grid[idx]);
        d2.Sub(grid[idx + n + 1], grid[idx]);
    } else {
        base = grid[idx + n + 2];
        d1.SubC(grid[idx + n + 1], grid[idx + n + 2]);
        d2.Sub(grid[idx + 1], grid[idx + n + 2]);
        *uv = SVec2(1.0f, 1.0f) - *uv;
    }
    SVec3 r = base + d1 * uv->x + d2 * uv->y;
    return r;
}

/* source arrives as an untyped/base pointer: the cast keeps a separate copy
 * (mr r28,r5 inside the branch) instead of a callee-save move at entry. */
/* ---- fn_801D6104: tessellate a bicubic Bezier patch by forward differencing ---- */
struct Vector3_801D5330 : patch6104::Vec3 {
    Vector3_801D5330();
};
extern "C" {
void fn_801D8068(Self*, Sample*, Vector3_801D5330*, Vec3Slot*);
void fn_801D8494(Self*, Sample*, Vector3_801D5330*);
void fn_801D8458(Self*, Sample*, Vector3_801D5330*, Vec3Slot*);
void fn_801D84B8(Self*, Sample*, Vector3_801D5330*);
}
namespace patch6104 {
struct FBox { float v; };
inline void NormalB(Vec4* out, const Vec4& a, const Vec4& b, const Vec4& c) {
    Vec3 n = (c - a).Cross(b - a);
    FBox t;
    t.v = 0.0f;
    FBox len = t;
    len.v = FastSqrt(n.LengthSq());
    if (len.v <= 0.000001f) {
        len.v = 0.0f;
    } else {
        n *= 1.0f / len.v;
    }
    out->x = n.x;
    out->y = n.y;
    out->z = n.z;
    out->w = len.v;
}
}
using patch6104::Vec3;
using patch6104::Vec4;
namespace patch6104 {
/* w42a: tri2 writes through 'Vec4* out = dst++' after the normalisation (copy + increment in the join block,
   as in the target). The addi is kept in front of the stores by Peephole.c adjustforward(): its scan stops,
   without moving the addi, at a store whose args[0] register number equals destReg, and that test ignores the
   register class. So dst's GPR virtual register number must equal the FPR vreg of one of tri2's stored values.
   Here dst is r40 (4 named GPRs a,c,b,d declared after it) and tri2's len.v is f40 (8 named floats). */
inline void NormalR(Vec4*& dst, const Vec4& a, const Vec4& b, const Vec4& c) {
    Vec3 n = (c - a).Cross(b - a);
    FBox t;
    t.v = 0.0f;
    FBox len = t;
    len.v = FastSqrt(n.LengthSq());
    if (len.v <= 0.000001f) {
        len.v = 0.0f;
    } else {
        n *= 1.0f / len.v;
    }
    Vec4* out = dst++;
    out->x = n.x;
    out->y = n.y;
    out->z = n.z;
    out->w = len.v;
}
}
extern "C" void fn_801D6104(Self* self, Vec4* out, Sample* face, Vec3Slot* extra) {
    int n = lbl_801E9D24.list->pad + 1;
    Vector3_801D5330 ctrl[4][4];
    if (self->flags & 4) {
        if (extra) fn_801D8068(self, face, ctrl[0], extra);
        else fn_801D8494(self, face, ctrl[0]);
    } else {
        if (extra) fn_801D8458(self, face, ctrl[0], extra);
        else fn_801D84B8(self, face, ctrl[0]);
    }
    Vec3 p[4], d1[4], d2[4], d3[4];
    /* w42a: the copy chains add one named float vreg each (8 named floats instead of 6), which shifts every FPR
       temporary up by 2 and puts tri2's len at f40 (= dst's GPR vreg). The relative order is unchanged, so the colouring is too. */
    float rcpu = 1.0f / n;
    float stepu = rcpu;
    float du = stepu;
    float du2 = du * du;
    float du3 = du2 * du;
    float rcpv = 1.0f;
    rcpv /= n;
    float stepv = rcpv;
    float dv = stepv;
    float dv2 = dv * dv;
    float dv3 = dv2 * dv;
    int i, j;
    Vec4* dst = out;
    for (i = 0; i < 4; i++) {
        /* w42a: only p0 is a named reference; ctrl[1..3][i] are written out so that dst has exactly four named
           GPR locals (a, c, b, d) declared after it -> dst = r40 (the code is identical to the p1..p3 reference form) */
        const Vec3& p0 = ctrl[0][i];
        Vec3 a = patch6104::Neg3(p0) + ctrl[1][i] * 3.0f - ctrl[2][i] * 3.0f + ctrl[3][i];
        Vec3 b = patch6104::Mul3(p0, 3.0f) - ctrl[1][i] * 6.0f + ctrl[2][i] * 3.0f;
        Vec3 c = (patch6104::Neg3(p0) * 3.0f).AddC(ctrl[1][i] * 3.0f);
        p[i] = p0;
        d1[i] = a * dv3 + b * dv2 + c * dv;
        d2[i] = a * 6.0f * dv3 + b * 2.0f * dv2;
        d3[i] = a * 6.0f * dv3;
    }
    for (j = 0; j < n + 1; j++) {
        /* w41a: dead initialisers set the SRA numbering of loop 2: e0 above a, a6 (a*6) above b */
        Vec3 e0;
        e0.x = 0.0f;
        e0.y = 0.0f;
        e0.z = 0.0f;
        Vec3 a = -p[0] + p[1] * 3.0f - p[2] * 3.0f + p[3];
        Vec3 a6;
        a6.x = 0.0f;
        a6.y = 0.0f;
        a6.z = 0.0f;
        Vec3 b = p[0] * 3.0f - p[1] * 6.0f + p[2] * 3.0f;
        Vec3 c = -p[0] * 3.0f + p[1] * 3.0f;
        e0 = p[0];
        Vec3 e1 = a * du3 + b * du2 + c * du;
        /* a*6 as SRA members of a6 (instead of a frontend-CSE temp numbered below b); the two
           Vec3(a6) copies keep the two stored a*6 stack temporaries of the target */
        a6.Set(a, 6.0f);
        Vec3 e2 = Vec3(a6) * du3 + b * 2.0f * du2;
        Vec3 e3 = Vec3(a6) * du3;
        for (i = 0; i < n + 1; i++) {
            dst->x = e0.x;
            dst->y = e0.y;
            dst->z = e0.z;
            dst++;
            e0 += e1;
            e1 += e2;
            e2 += e3;
        }
        for (i = 0; i < 4; i++) {
            p[i] += d1[i];
            d1[i] += d2[i];
            d2[i] += d3[i];
        }
    }
    Vec4* a = out;
    Vec4* c = out + n + 1;
    Vec4* b = out + 1;
    Vec4* d = c + 1;
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            patch6104::NormalB(dst, *a, *b, *c);
            dst++;
            patch6104::NormalR(dst, *b, *d, *c);
            a++;
            c++;
            b++;
            d++;
        }
        a++;
        c++;
        b++;
        d++;
    }
}
/* merge42: forward declaration flushes fn_801D6104 before fn_801D6BA8 (target order 5DF8, 6104, 6BA8) */
struct FlushN;
extern "C" Vec4Slot* fn_801D6BA8(Self* self, U16 record, void* source) {
    Vec4Slot* result;
    if (self->flags & 4) {
#if R==1
        Source* src = (Source*)source;
#else
#define src source
#endif
        Record* first = &src->records[record];
        if (first->link == 0xffff) {
            Vec3Slot* extra = GET(lbl_801E9D24.list3, src->link);
            Record* rec = &src->records[record];
            rec->link = fn_801D7B5C(lbl_801E9D24.list2, src, record);
            result = GET(lbl_801E9D24.list2, src->records[record].link);
            fn_801D6104(self, result, &self->samples[record], extra);
        } else {
            result = GET(lbl_801E9D24.list2, src->records[record].link);
        }
    } else {
        Record* rec = &self->records[record];
        if (self->records[record].link == 0xffff) {
            rec->link = fn_801D7C28(lbl_801E9D24.list, self, record);
            result = GET(lbl_801E9D24.list, self->records[record].link);
            fn_801D6104(self, result, &self->samples[record], 0);
        } else {
            result = GET(lbl_801E9D24.list, rec->link);
        }
    }
    return result;
}
