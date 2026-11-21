/* Merged translation unit: Game/grid_clip_constants.c, part_80264CCC, Game/index_selection_collect.cpp, part_80265594, Game/grid_x_clip.cpp. */
/* ---- Game/grid_clip_constants.c ---- */
#pragma push
#pragma RTTI on
#pragma fp_contract off
namespace grid_clip_constants {
extern "C" {
/* Grid clipping endpoints, tolerance, intersection scale and signed integer conversion bias. */
const float lbl_8037B5F8 = 0.5f;
const float lbl_8037B5FC = -10000000000.0f;
const float lbl_8037B600 = 10000000000.0f;
const float lbl_8037B604 = 9.999999974752427e-07f;
const float lbl_8037B608 = 0.0f;
const float lbl_8037B60C = 1.0f;
const float lbl_8037B610 = 0.9999989867210388f;
const double lbl_8037B618 = 4503601774854144.0;

}

}

#pragma pop
/* ---- part_80264CCC ---- */
namespace part_80264CCC {
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};
inline Vec3 operator-(const Vec3& a, const Vec3& b) { Vec3 r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
struct Mat3 { float m[3][3]; };
inline Vec3 xform(const Mat3& m, const Vec3& v) {
    float z;
    float y;
    float x;
    x = v.x * m.m[0][0] + v.y * m.m[0][1] + v.z * m.m[0][2];
    y = v.x * m.m[1][0] + v.y * m.m[1][1] + v.z * m.m[1][2];
    z = v.x * m.m[2][0] + v.y * m.m[2][1] + v.z * m.m[2][2];
    return Vec3(x, y, z);
}
inline Vec3 scaleC(const Vec3& a, float s) { return Vec3(a.x * s, a.y * s, a.z * s); }
inline Vec3 scale(const Vec3& a, float s) { Vec3 r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
struct Box { char unknown00[0x3C]; Vec3 center; Mat3 axes; char unknown6C[0xC]; Vec3 size; };
struct Ray { Vec3 origin; float pad; Vec3 dir; };
inline float absf(float x) { return __fabs(x); }
extern "C" bool fn_80264CCC(Box* box, const Ray* ray)
{
    float tmin;
    Vec3 p;
    float tmax;
    float t1;
    Vec3 d;
    Vec3 dir;
    float tmp;
    Vec3 h;
    float inv;
    float t2;
    d = ray->origin - box->center;
    p = xform(box->axes, d);
    dir = xform(box->axes, ray->dir);
    h = scale(box->size, 0.5f);
    tmin = -1e10f;
    tmax = 1e10f;
    if (absf(dir.x) <= 0.000001f && (p.x < -h.x || p.x > h.x)) return false;
    if (absf(dir.y) <= 0.000001f && (p.y < -h.y || p.y > h.y)) return false;
    if (absf(dir.z) <= 0.0f && 0.0f != h.z && (p.z < -h.z || p.z > h.z)) return false;
    inv = 1.0f / dir.x;
    t1 = inv * (-h.x - p.x);
    t2 = inv * (h.x - p.x);
    if (t1 > t2) { tmp = t1; t1 = t2; t2 = tmp; }
    if (t1 > -1e10f) tmin = t1;
    if (t2 < 1e10f) tmax = t2;
    if (tmin > tmax) return false;
    if (tmax < 0.000001f) return false;
    {
    float u1;
    float u2;
    float inv2;
    float tmp2;
    inv2 = 1.0f / dir.z;
    u1 = inv2 * (-h.z - p.z);
    u2 = inv2 * (h.z - p.z);
    if (u1 > u2) { tmp2 = u1; u1 = u2; u2 = tmp2; }
    if (u1 > tmin) tmin = u1;
    if (u2 < tmax) tmax = u2;
    }
    if (tmin > tmax) return false;
    if (tmax < 0.000001f) return false;
    if (absf(h.y) <= 0.000001f) return true;
    inv = 1.0f / dir.y;
    t1 = inv * (-h.y - p.y);
    t2 = inv * (h.y - p.y);
    if (t1 > t2) { tmp = t1; t1 = t2; t2 = tmp; }
    if (t1 > tmin) tmin = t1;
    if (t2 < tmax) tmax = t2;
    if (tmin > tmax) return false;
    return !(tmax < 0.000001f);
}


extern "C" void* memset(void*, int, unsigned long);
struct IVec3 { int x, y, z; int& operator[](int i) { return (&x)[i]; } };
struct Cell { short first; short count; short stamp; };
struct BitArr {
    int count, capacity;
    volatile unsigned int* data;
    int bits;
    void clear() { if (bits != 0 && count != 0) memset((void*)data, 0, count * 4); }
};
struct Grid {
    char pad0[8];
    Cell* cells;        /* 0x08 */
    char padC[8];
    short* indices;     /* 0x14 */
    int cursor;         /* 0x18 */
    BitArr bits;        /* 0x1C */
    char pad2C[0x10];
    Vec3 center;        /* 0x3C */
    Mat3 axes;          /* 0x48 */
    int nx, ny, nz;     /* 0x6C */
    Vec3 size;          /* 0x78 */
    unsigned int stamp; /* 0x84 */
};
inline int roundDown(float v)
{
    if (v < 0.0f) return (int)(v - 0.999999f);
    return (int)v;
}
inline int roundUp(float v)
{
    if (v > 0.0f) return (int)(0.999999f + v);
    return (int)v;
}
inline Vec3 operator+(const Vec3& a, const Vec3& b) { Vec3 r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec3 operator*(const Vec3& a, const Vec3& b) { Vec3 r; r.x = a.x * b.x; r.y = a.y * b.y; r.z = a.z * b.z; return r; }
inline Vec3 operator/(const Vec3& a, const Vec3& b) { Vec3 r; r.x = a.x / b.x; r.y = a.y / b.y; r.z = a.z / b.z; return r; }
inline void operator+=(Vec3& a, const Vec3& b) { a.x += b.x; a.y += b.y; a.z += b.z; }
inline void operator/=(Vec3& a, const Vec3& b) { a.x /= b.x; a.y /= b.y; a.z /= b.z; }
inline void operator*=(Vec3& a, const Vec3& b) { a.x *= b.x; a.y *= b.y; a.z *= b.z; }
struct Sphere { Vec3 pos; };
extern "C" void fn_80265028(Grid* self, const Sphere* s, float r)
{
    IVec3 lo;
    IVec3 hi;
    self->stamp++;
    self->bits.clear();
    self->cursor = 0;
    Vec3 p = xform(self->axes, s->pos - self->center);
    Vec3 a = p - Vec3(r, r, r);
    Vec3 b = p + Vec3(r, r, r);
    Vec3 hs = scaleC(self->size, 0.5f);
    Vec3 hn(0.5f * self->nx, 0.5f * self->ny, 0.5f * self->nz);
    Vec3 fl = a * hn; Vec3 fh = b * hn; fl /= hs; fh /= hs; fl += hn; fh += hn;
    lo[0] = roundDown(fl.x);
    hi[0] = roundUp(fh.x);
    if (hi[0] < 0 || !(lo[0] < self->nx)) return;
    lo[1] = roundDown(fl.y);
    hi[1] = roundUp(fh.y);
    if (hi[1] < 0 || !(lo[1] < self->ny)) return;
    lo[2] = roundDown(fl.z);
    hi[2] = roundUp(fh.z);
    if (hi[2] < 0 || !(lo[2] < self->nz)) return;
    if (lo[0] < 0) lo[0] = 0;
    if (hi[0] > self->nx) hi[0] = self->nx;
    if (lo[1] < 0) lo[1] = 0;
    if (hi[1] > self->ny) hi[1] = self->ny;
    if (lo[2] < 0) lo[2] = 0;
    if (hi[2] > self->nz) hi[2] = self->nz;
    int* q = &lo.x; int* q2 = &hi.x;
    Cell* cells; int z0, y0, y1, z1; int x;
    y0 = lo[1]; y1 = hi[1]; cells = self->cells; x = lo[0]; z0 = lo[2]; z1 = hi[2];
    for (; x < hi[0]; x++) {
        for (int z = z0; z < z1; z++) {
            for (int y = y0; y < y1; y++) {
                Cell* c = &cells[x + self->nx * z + y * (self->nx * self->nz)];
                if (c->stamp != self->stamp) {
                    c->stamp = self->stamp;
                    int j = c->first;
                    for (short k = 0; k < c->count; k++, j++) {
                        int id = self->indices[j];
                        volatile unsigned int* wp = &self->bits.data[id >> 5]; unsigned int m = 1 << (id & 31);
                        signed char b = (m & *wp) != 0;
                        if (!b) *wp |= m;
                    }
                }
            }
        }
    }
}

}

/* ---- Game/index_selection_collect.cpp ---- */
#pragma push
#pragma fp_contract off
#include "Game/bitset_internal.h"
struct IndexSelectionView {
    char unknown0[0x18];
    int cursor;
    BitSet_80207EE8 bits;
};
extern "C" int fn_80207B94(BitSet_80207EE8*,signed char,int);
extern "C" int fn_802654E8(IndexSelectionView*self,short*output,short limit){
    if(self->cursor<0)return 0;
    int count=0;
    while((short)count!=limit){
        self->cursor=fn_80207B94(&self->bits,1,self->cursor);
        if(self->cursor<0)break;
        output[(short)count++]=self->cursor++;
    }
    return count;
}

#pragma pop
/* ---- part_80265594 ---- */
namespace part_80265594 {

inline float fastRecip(register float x)
{
    register float r;
    asm { fres r, x }
    return r;
}

extern "C" void* memset(void*, int, unsigned long);
struct IVec3 { int x, y, z; int& operator[](int i) { return (&x)[i]; } };
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 add(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 sub(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 mul(float s) const { return Vec3(x * s, y * s, z * s); }
    float& operator[](int i) { return (&x)[i]; }
    const float& operator[](int i) const { return (&x)[i]; }
};
inline Vec3 operator-(const Vec3& a, const Vec3& b) { Vec3 r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec3 operator+(const Vec3& a, const Vec3& b) { Vec3 r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec3 operator*(const Vec3& a, float s) { Vec3 r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
struct Mat3 { float m[3][3]; };
inline Vec3 xform(const Mat3& m, const Vec3& v) {
    Vec3 r;
    r.x = v.z * m.m[0][2] + (v.x * m.m[0][0] + v.y * m.m[0][1]);
    r.y = v.z * m.m[1][2] + (v.x * m.m[1][0] + v.y * m.m[1][1]);
    r.z = v.z * m.m[2][2] + (v.x * m.m[2][0] + v.y * m.m[2][1]);
    return r;
}
struct BitArr {
    int count, capacity;
    volatile unsigned int* data;
    int bits;
    void clear() { if (bits != 0 && count != 0) memset((void*)data, 0, count * 4); }
};

struct Cell {
    short first;
    short count;
    short stamp;
};

struct Grid {
    char pad0[8];
    Cell* cells;        /* 0x08 */
    char padC[8];
    short* indices;     /* 0x14 */
    int cursor;         /* 0x18 */
    BitArr bits;        /* 0x1C */
    char pad2C[4];
    Vec3 cell;          /* 0x30 */
    Vec3 center;        /* 0x3C */
    Mat3 axes;          /* 0x48 */
    int nx;             /* 0x6C */
    int ny;             /* 0x70 */
    int nz;             /* 0x74 */
    Vec3 size;          /* 0x78 */
    unsigned int stamp; /* 0x84 */

    Cell* getCell(int x, int y, int z) {
        if (x >= nx || y >= ny || z >= nz) return 0;
        int i = x + nx * z + y * (nx * nz);
        if (i < 0) return 0;
        return &cells[i];
    }
};

/* Promoted struct-member locals are coloured ahead of plain locals and LICM temps:
   keeping x and the index table in a small local struct gives them r0/r4 ahead of
   the hoisted step.x (r5). */
struct Cursor { int x; short* indices; };

extern "C" void fn_80265594(Grid* self, const IVec3* start, const Vec3* frac, const IVec3* deltaIn, const Vec3* dir)
{
    int n;
    IVec3 step;
    IVec3 delta = *deltaIn;
    Cursor cur;
    int y;
    int z;
    float inv[3];
    float fx;
    float fy;
    float fz;
    float t2;
    float t1;
    float t0;
    n = 0;
    int* q = &step.x; q[1] = q[1]; q[2] = q[2];
    cur.x = start->x;
    y = start->y;
    z = start->z;
    if (delta[0] != 0) {
        if (delta[0] > 0) { n += delta[0]; step[0] = 1; }
        else { n -= delta[0]; step[0] = -1; }
        inv[0] = fastRecip(dir->x);
    } else {
        step[0] = 0;
        inv[0] = 0.0f;
    }
    if (delta[1] != 0) {
        if (delta[1] > 0) { n += delta[1]; step[1] = 1; }
        else { n -= delta[1]; step[1] = -1; }
        inv[1] = fastRecip(dir->y);
    } else {
        step[1] = 0;
        inv[1] = 0.0f;
    }
    if (delta[2] != 0) {
        if (delta[2] > 0) { n += delta[2]; step[2] = 1; }
        else { n -= delta[2]; step[2] = -1; }
        inv[2] = fastRecip(dir->z);
    } else {
        step[2] = 0;
        inv[2] = 0.0f;
    }
    fx = frac->x;
    fy = frac->y;
    fz = frac->z;
    cur.indices = self->indices;
    for (; n != 0; n--) {
        Cell* c = self->getCell(cur.x, y, z);
        if (c != 0 && c->stamp != self->stamp) {
            c->stamp = self->stamp;
            unsigned int cnt;
            if ((cnt = c->count) != 0) {
                int k = c->first;
                do {
                    int id = cur.indices[k++];
                    self->bits.data[id >> 5] |= 1 << (id & 31);
                } while (--cnt != 0);
            }
        }
        t0 = t1 = t2 = 0.0f;
        if (step[0] > 0) t0 = (1.0f - fx) * inv[0];
        else if (step[0] < 0) t0 = -fx * inv[0];
        if (step[1] > 0) t1 = (1.0f - fy) * inv[1];
        else if (step[1] < 0) t1 = -fy * inv[1];
        if (step[2] > 0) t2 = (1.0f - fz) * inv[2];
        else if (step[2] < 0) t2 = -fz * inv[2];
        if (step[0] != 0 && (step[1] == 0 || t0 < t1) && (step[2] == 0 || t0 < t2)) {
            cur.x += step[0];
            fy += t0 * dir->y;
            fz += t0 * dir->z;
            if (step[0] > 0) fx = 0.0f; else fx = 1.0f;
        }
        if (step[1] != 0 && (step[0] == 0 || t1 < t0) && (step[2] == 0 || t1 < t2)) {
            y += step[1];
            fx += t1 * dir->x;
            fz += t1 * dir->z;
            if (step[1] > 0) fy = 0.0f; else fy = 1.0f;
        }
        if (step[2] != 0 && (step[0] == 0 || t2 < t0) && (step[1] == 0 || t2 < t1)) {
            z += step[2];
            fx += t2 * dir->x;
            fy += t2 * dir->y;
            if (step[2] > 0) fz = 0.0f; else fz = 1.0f;
        }
    }
    Cell* c = self->getCell(cur.x, y, z);
    if (c != 0 && c->stamp != self->stamp) {
        unsigned int cnt;
        if ((cnt = c->count) != 0) {
                int k = c->first;
            do {
                int id = cur.indices[k++];
                self->bits.data[id >> 5] |= 1 << (id & 31);
            } while (--cnt != 0);
        }
    }
}

extern "C" signed char fn_80265F10(Grid* self, Vec3* a, Vec3* b);
struct Ray { Vec3 origin; float length; Vec3 dir; };
extern "C" const float lbl_8037B620;
inline float rsqrt(register float x)
{
    register float r;
    asm { frsqrte r, x }
    return r;
}
inline Vec3 scaleC(const Vec3& a, float s) { return Vec3(a.x * s, a.y * s, a.z * s); }
inline void operator+=(Vec3& a, const Vec3& b) { a.x += b.x; a.y += b.y; a.z += b.z; }
inline float lengthSq(const Vec3& v)
{
    float xx = v.x * v.x;
    float yy = v.y * v.y;
    float zz = v.z * v.z;
    return zz + (xx + yy);
}
inline Vec3 addC(const Vec3& a, const Vec3& b) { return Vec3(a.x + b.x, a.y + b.y, a.z + b.z); }
inline Vec3 subC(const Vec3& a, const Vec3& b) { return Vec3(a.x - b.x, a.y - b.y, a.z - b.z); }
inline Vec3 mulC(const Vec3& a, float s) { return Vec3(a.x * s, a.y * s, a.z * s); }
inline Vec3 toLocal(const Mat3& m, const Vec3& c, const Vec3& p)
{
    Vec3 r;
    float dx = p.x - c.x;
    float dy = p.y - c.y;
    float dz = p.z - c.z;
    r.x = dz * m.m[0][2] + (dx * m.m[0][0] + dy * m.m[0][1]);
    r.y = dz * m.m[1][2] + (dx * m.m[1][0] + dy * m.m[1][1]);
    r.z = dz * m.m[2][2] + (dx * m.m[2][0] + dy * m.m[2][1]);
    return r;
}
inline float rsqrtScaled(register float x, register float len)
{
    register float r;
    asm { frsqrte f4, x
          fmuls r, f4, len }
    return r;
}
struct Dir : Vec3 {
    Dir(float a, float b, float c) : Vec3(a, b, c) {}
    Dir& normalize()
    {
        float s = rsqrt(lengthSq(*this));
        x *= s; y *= s; z *= s;
        return *this;
    }
};
inline Dir subD(const Vec3& a, const Vec3& b) { return Dir(a.x - b.x, a.y - b.y, a.z - b.z); }
inline void setLength(Vec3& v, float len)
{
    float l2 = lengthSq(v);
    if (l2 > lbl_8037B620) {
        float s = rsqrtScaled(l2, len);
        v.x *= s; v.y *= s; v.z *= s;
    }
}
inline Vec3 divC(const Vec3& a, const Vec3& b) { return Vec3(a.x / b.x, a.y / b.y, a.z / b.z); }
extern "C" int fn_802659A4(Grid* self, const Ray* ray)
{
    self->stamp++;
    self->bits.clear();
    self->cursor = 0;
    Vec3 a;
    Vec3 b;
    IVec3 start;
    IVec3 iend;
    Vec3 frac;
    Vec3 dn;
    Vec3 d0 = subC(ray->origin, self->center);
    Vec3 d1 = ray->origin.add(ray->dir.mul(ray->length)).sub(self->center);
    Vec3 half = scaleC(self->size, 0.5f);
    a = Vec3(half.x, half.y, half.z);
    b = a;
    a.x += d0.x * self->axes.m[0][0] + d0.y * self->axes.m[0][1] + d0.z * self->axes.m[0][2];
    a.y += d0.x * self->axes.m[1][0] + d0.y * self->axes.m[1][1] + d0.z * self->axes.m[1][2];
    a.z += d0.x * self->axes.m[2][0] + d0.y * self->axes.m[2][1] + d0.z * self->axes.m[2][2];
    b.x += d1.x * self->axes.m[0][0] + d1.y * self->axes.m[0][1] + d1.z * self->axes.m[0][2];
    b.y += d1.x * self->axes.m[1][0] + d1.y * self->axes.m[1][1] + d1.z * self->axes.m[1][2];
    b.z += d1.x * self->axes.m[2][0] + d1.y * self->axes.m[2][1] + d1.z * self->axes.m[2][2];
    if (!fn_80265F10(self, &a, &b)) return 0;
    dn = subD(b, a).normalize();
    float zero = 0.0f;
    if (self->cell.x != zero) dn.x = dn.x / self->cell.x; else dn.x = zero;
    if (self->cell.y != zero) dn.y = dn.y / self->cell.y; else dn.y = zero;
    if (self->cell.z != zero) dn.z = dn.z / self->cell.z; else dn.z = zero;
    setLength(dn, 1.0f);
    start.x = (int)(a.x / self->cell.x);
    start.y = (int)(a.y / self->cell.y);
    start.z = (int)(a.z / self->cell.z);
    frac.x = a.x - start.x * self->cell.x;
    frac.y = a.y - start.y * self->cell.y;
    frac.z = a.z - start.z * self->cell.z;
    frac = divC(frac, self->cell);
    Vec3 eb = divC(b, self->cell);
    iend.x = (int)eb.x;
    iend.y = (int)eb.y;
    iend.z = (int)eb.z;
    if (iend.x < 0) iend.x = 0; else if (iend.x >= self->nx) iend.x = self->nx - 1;
    if (iend.y < 0) iend.y = 0; else if (iend.y >= self->ny) iend.y = self->ny - 1;
    if (iend.z < 0) iend.z = 0; else if (iend.z >= self->nz) iend.z = self->nz - 1;
    iend.x -= start.x;
    iend.y -= start.y;
    iend.z -= start.z;
    fn_80265594(self, &start, &frac, &iend, &dn);
    return 1;
}

extern "C" { extern const float lbl_8037B604; extern const float lbl_8037B608; }
extern "C" void fn_802665F4(Grid* self, Vec3* start, const Vec3* end, unsigned long* flags);
inline void outcode(Grid* self, const Vec3* start, unsigned long* flags)
{
    *flags = 0;
    if (start->x < 0.000001f) *flags |= 1;
    if (start->x > self->size.x) *flags |= 2;
    if (start->y < 0.000001f) *flags |= 4;
    if (start->y > self->size.y) *flags |= 8;
    if (start->z < 0.000001f) *flags |= 16;
    if (start->z > self->size.z) *flags |= 32;
}
inline void clipY(Grid* self, Vec3* start, const Vec3* end, unsigned long* flags)
{
    if (*flags & 4) {
        Vec3 delta(end->x - start->x, end->y - start->y, end->z - start->z);
        float fraction = -start->y / delta.y;
        start->y = 0.0f;
        start->x += fraction * delta.x;
        start->z += fraction * delta.z;
    } else if (*flags & 8) {
        Vec3 delta(end->x - start->x, end->y - start->y, end->z - start->z);
        float fraction = (start->y - self->size.y) / delta.y;
        start->y = self->size.y;
        start->x -= fraction * delta.x;
        start->z -= fraction * delta.z;
    }
    outcode(self, start, flags);
}
inline void clipZ(Grid* self, Vec3* start, const Vec3* end, unsigned long* flags)
{
    if (*flags & 16) {
        Vec3 delta(end->x - start->x, end->y - start->y, end->z - start->z);
        float fraction = -start->z / delta.z;
        start->z = 0.0f;
        start->x += fraction * delta.x;
        start->y += fraction * delta.y;
    } else if (*flags & 32) {
        Vec3 delta(end->x - start->x, end->y - start->y, end->z - start->z);
        float fraction = (start->z - self->size.z) / delta.z;
        start->z = self->size.z;
        start->x -= fraction * delta.x;
        start->y -= fraction * delta.x;
    }
    outcode(self, start, flags);
}
extern "C" signed char fn_80265F10(Grid* self, Vec3* a, Vec3* b)
{
    unsigned long fa = 0;
    unsigned long fb = 0;
    outcode(self, a, &fa);
    outcode(self, b, &fb);
    if (fa & fb) return 0;
    if (!(fa | fb)) return 1;
    if (fa & 3) fn_802665F4(self, a, b, &fa);
    if (fa & 12) clipY(self, a, b, &fa);
    if (fa & 48) clipZ(self, a, b, &fa);
    if (fb & 3) fn_802665F4(self, b, a, &fb);
    if (fb & 12) clipY(self, b, a, &fb);
    if (fb & 48) clipZ(self, b, a, &fb);
    return 1;
}

}

/* ---- Game/grid_x_clip.cpp ---- */
#pragma push
#pragma fp_contract off
namespace grid_x_clip {
#pragma fp_contract on
struct GridXClipPoint {float x,y,z;GridXClipPoint(float a,float b,float c):x(a),y(b),z(c){}};
struct GridXClipSelf {char unknown00[0x78];GridXClipPoint extent;};

extern "C" void fn_802665F4(GridXClipSelf* self,GridXClipPoint* start,const GridXClipPoint* end,unsigned long* flags) {
 if(*flags&1){
  GridXClipPoint delta(end->x-start->x,end->y-start->y,end->z-start->z);
  float fraction=-start->x/delta.x;
  start->x=0.0f;
  start->y+=fraction*delta.y;
  start->z+=fraction*delta.z;
 }else if(*flags&2){
  GridXClipPoint delta(end->x-start->x,end->y-start->y,end->z-start->z);
  float fraction=(start->x-self->extent.x)/delta.x;
  start->x=self->extent.x;
  start->y-=fraction*delta.y;
  start->z-=fraction*delta.z;
 }
 *flags=0;
 if(start->x<9.999999974752427e-07f)*flags|=1;
 if(start->x>self->extent.x)*flags|=2;
 if(start->y<9.999999974752427e-07f)*flags|=4;
 if(start->y>self->extent.y)*flags|=8;
 if(start->z<9.999999974752427e-07f)*flags|=16;
 if(start->z>self->extent.z)*flags|=32;
}

}

#pragma pop
