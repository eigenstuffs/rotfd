/* auto_03_801DCCE8_text: fn_801DCCE8, capsule (segment + radius) against a
   capped cylinder: projected-segment side test against the infinite
   cylinder, the two end-cap discs, the side wall, then both rounded rims
   through the torus solver fn_801DE350 in the cylinder's frame.
   GC/1.3.2 -O4,p -fp_contract on.  Status: EXACT (w30).
   The FPR colouring depends on vreg numbering; the forms below set it:
   - b->base after fn_801DDB3C is read plain, distanceSq computes dz,dy,dx
     (CSE temps are created at the second occurrence, so z is numbered first);
     the bottom-cap base read is plain too, the side test plain.
   - a->radius: rsum plain, both cap dist reads cast (CSE temp created at the
     bottom-cap axis*radius read, i.e. after the a->direction temps).
   - bottom cap: hit is an assigned (SRA) Vec3 with z in a named local hz,
     out->point stored per component; top cap: hx/hy/hz named, computed z,y,x.
   - side hit through addv() (x-first, no fmadds); t's dot reads
     proj.direction plain; rim radius scaling through Vec3::scale(float).
   - d1's y difference is a named local (dy); m.m[14] stored after inv.
   - rim frame: lbl_8037A4E0 goes through pinned(), u is built in perpOf()
     and its length through lengthOr() whose fres writes r directly, so the
     zero/length value chain is numbered above the u components. */
extern "C" {
extern const float lbl_8037A4E0;
extern const float lbl_8037A4E4;
extern const float lbl_8037A4E8;
extern const double lbl_8037A4F0;
}
typedef unsigned long long Mask;

extern "C" {
void* memset(void*, int, unsigned long);
extern const float lbl_8037A4E0;
extern const float lbl_8037A4E4;
extern const float lbl_8037A4E8;
extern const double lbl_8037A4F0;
}

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float reciprocalSqrt(register float x)
{
    register float r;
    asm { frsqrte r, x }
    return r;
}

inline float sqrtOrZero(float sq)
{
    float r = (*(const float*)&lbl_8037A4E0);
    if (sq != r) r = fastSqrt(sq);
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3& operator=(const Vec3& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    Vec3 cross(float vx, float vy, float vz) const
    {
        return Vec3(y * vz - z * vy, z * vx - x * vz, x * vy - y * vx);
    }
    Vec3 cross(const Vec3& v) const
    {
        return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }
    float lengthSq() const { return x * x + y * y + z * z; }
    float lengthOr(register float r) const
    {
        register float sq = lengthSq();
        if (sq != r) {
            asm { frsqrte f4, sq
                  fres r, f4 }
        }
        return r;
    }
    float length() const
    {
        float sq = lengthSq();
        float r = lbl_8037A4E0;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    float distanceSq(const Vec3& v) const
    {
        float dz = z - v.z;
        float dy = y - v.y;
        float dx = x - v.x;
        return dx * dx + dy * dy + dz * dz;
    }
    void scale(float s)
    {
        x *= s;
        y *= s;
        z *= s;
    }
    Vec3& normalize()
    {
        float s = reciprocalSqrt(lengthSq());
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
};

struct Matrix {
    float m[16];
    void identity()
    {
        memset(this, 0, sizeof(*this));
        m[0] = (*(const float*)&lbl_8037A4E4);
        m[5] = lbl_8037A4E4;
        m[10] = lbl_8037A4E4;
        m[15] = lbl_8037A4E4;
    }
    Vec3 rotate(const Vec3& v) const
    {
        Vec3 r;
        r.x = m[0] * v.x + m[4] * v.y + m[8] * v.z;
        r.y = m[1] * v.x + m[5] * v.y + m[9] * v.z;
        r.z = m[2] * v.x + m[6] * v.y + m[10] * v.z;
        return r;
    }
};

struct Segment {
    Vec3 start;
    float length;
    Vec3 direction;
    float radius;
    Segment() {}
    Segment(const Segment& s) : start(s.start), length(s.length), direction(s.direction), radius(s.radius) {}
    Segment& operator=(const Segment& s)
    {
        start = s.start;
        length = s.length;
        direction = s.direction;
        radius = s.radius;
        return *this;
    }
};

struct Cylinder {
    Vec3 base;
    float height;
    Vec3 axis;
    float unknown1C;
    float radius;
};

struct Result {
    Vec3 point;
    float distance;
    Vec3 normal;
    char unknown1C[12];
    Mask flags;
    char unknown30[12];
    signed char valid;
};

extern "C" {
extern const float lbl_8037A4E0;
extern const float lbl_8037A4E4;
extern const float lbl_8037A4E8;
extern const double lbl_8037A4F0;
Segment fn_801DD9E0(const Matrix& matrix, const Segment& segment);
void fn_801DDB3C(Segment* segment, const Vec3& start, const Vec3& end);
void fn_801F230C(const Matrix* matrix, Matrix* inverse);
int fn_801DE350(Vec3 start, Vec3 direction, int* count, double* roots,
                float radius, float a, float b);
}

inline Vec3 project(const Vec3& p, const Vec3& base, const Vec3& axis)
{
    return p - axis * (p - base).dot(axis);
}

inline float ratio(float n, float d) { return n / d; }
inline Vec3 perpOf(const Vec3& axis, const float& zero)
{
    return Vec3(axis.y * lbl_8037A4E4 - axis.z * zero,
                axis.z * zero - axis.x * lbl_8037A4E4,
                axis.x * zero - axis.y * zero);
}
inline float pinned(float v)
{
    v = v;
    return v;
}
inline Vec3 addv(const Vec3& p, const Vec3& q)
{
    Vec3 r;
    r.x = p.x + q.x;
    r.y = p.y + q.y;
    r.z = p.z + q.z;
    return r;
}

extern "C" int fn_801DCCE8(const Segment* a, const Cylinder* b, Result* out, Mask flags)
{
    Vec3 top = b->base + b->axis * b->height;
    Vec3 end = a->start + a->direction * a->length;
    float dBottom = -b->axis.dot(b->base);
    float dTop = -b->axis.dot(top);
    Segment proj;
    float d0 = (a->start - b->base).dot(b->axis);
    Vec3 p0 = a->start - b->axis * d0;
    float dy = end.y - b->base.y;
    float d1 = Vec3(end.x - b->base.x, dy, end.z - b->base.z).dot(b->axis);
    Vec3 p1 = end - b->axis * d1;
    fn_801DDB3C(&proj, p0, p1);

    float t = (b->base - proj.start).dot(proj.direction);
    float distSq = (proj.direction * t + proj.start).distanceSq(b->base);
    float rsum = b->radius + a->radius;
    if (distSq > rsum * rsum) return 0;

    if (a->direction.dot(b->axis) > (*(const float*)(unsigned long)&(*(const float*)&lbl_8037A4E8))) {
        float dist = (*(const float*)&a->radius) + (dBottom + b->axis.dot(a->start));
        if (dist < (*(const float*)(unsigned long)&lbl_8037A4E8)) {
            float tc = -(dist / b->axis.dot(a->direction));
            if (tc > (*(const float*)(unsigned long)&lbl_8037A4E8) && tc < a->length) {
                const Vec3& dt = a->direction * tc;
                float hz = dt.z + a->start.z;
                Vec3 hit;
                hit = Vec3(dt.x + a->start.x, dt.y + a->start.y, hz);
                if ((hit - (b->base - b->axis * a->radius)).lengthSq() < b->radius * b->radius) {
                    if (!out->valid || tc < out->distance) {
                        out->valid = 1;
                        out->flags = flags;
                        out->distance = tc;
                        out->point.x = hit.x;
                        out->point.y = hit.y;
                        out->point.z = hz;
                        out->normal = -b->axis;
                        return 1;
                    }
                }
            }
        }
    } else {
        float dist = (dTop + b->axis.dot(a->start)) - (*(const float*)&a->radius);
        if (dist > (*(const float*)(unsigned long)&lbl_8037A4E8)) {
            float tc = -(dist / b->axis.dot(a->direction));
            if (tc > (*(const float*)(unsigned long)&lbl_8037A4E8) && tc < a->length) {
                const Vec3& dt = a->direction * tc;
                float hx, hy;
                float hz = dt.z + a->start.z;
                hy = dt.y + a->start.y;
                hx = dt.x + a->start.x;
                Vec3 hit(hx, hy, hz);
                if ((hit - (top + b->axis * a->radius)).lengthSq() < b->radius * b->radius) {
                    if (!out->valid || tc < out->distance) {
                        out->valid = 1;
                        out->flags = flags;
                        out->distance = tc;
                        out->point = hit;
                        out->normal = b->axis;
                        return 1;
                    }
                }
            }
        }
    }

    {
        float h = sqrtOrZero(rsum * rsum - distSq);
        float th = t - h;
        float s = ratio(th * a->length, proj.length);
        if (s > (*(const float*)&(*(const float*)(unsigned long)&lbl_8037A4E8)) && s < a->length) {
            Vec3 hit = addv(a->start, a->direction * s);
            float hh = (hit - b->base).dot(b->axis);
            if (hh > (*(const float*)&lbl_8037A4E8) && hh < b->height) {
                if (!out->valid || s < out->distance) {
                    out->valid = 1;
                    out->flags = flags;
                    out->distance = s;
                    out->point = hit;
                    out->normal = ((proj.start + proj.direction * (t - h)) - b->base).normalize();
                    return 1;
                }
            }
        }
    }

    Vec3 axis = b->axis;
    float zero = pinned(lbl_8037A4E0);
    Vec3 u = perpOf(axis, zero);
    float len = u.lengthOr(zero);
    Vec3 w;
    if (len < lbl_8037A4E8) {
        u = Vec3(axis.y * zero - axis.z * zero,
                 axis.z * (*(const float*)&lbl_8037A4E4) - axis.x * zero,
                 axis.x * zero - axis.y * lbl_8037A4E4);
        u.normalize();
        w = u.cross(axis);
    } else {
        u = u * ((*(const float*)(unsigned long)&lbl_8037A4E4) / len);
        w = u.cross(axis);
    }

    Matrix m;
    m.identity();
    m.m[0] = u.x;
    m.m[1] = u.y;
    m.m[2] = u.z;
    m.m[4] = axis.x;
    m.m[5] = axis.y;
    m.m[6] = axis.z;
    m.m[8] = w.x;
    m.m[9] = w.y;
    m.m[10] = w.z;
    m.m[12] = b->base.x;
    m.m[13] = b->base.y;
    m.m[14] = b->base.z;
    Matrix inv;
    fn_801F230C(&m, &inv);

    int result = 0;
    int count;
    double roots[4];
    Segment local = fn_801DD9E0(inv, *a);
    if (fn_801DE350(local.start, local.direction, &count, roots, b->radius, a->radius, a->radius)
        && roots[0] > lbl_8037A4F0 && roots[0] < a->length) {
        float tr = roots[0];
        if (!out->valid || tr < out->distance) {
            Vec3 p = local.direction * tr + local.start;
            float rs = reciprocalSqrt(p.lengthSq());
            Vec3 c(p.x * rs, lbl_8037A4E0, p.z * rs);
            c.scale(b->radius);
            out->valid = 1;
            result = 1;
            out->flags = flags;
            out->distance = tr;
            out->point = a->direction * tr + a->start;
            out->normal = m.rotate((p - c).normalize());
        }
    }

    m.m[12] = top.x;
    m.m[13] = top.y;
    inv.m[12] = -top.x;
    inv.m[13] = -top.y;
    inv.m[14] = -top.z;
    m.m[14] = top.z;
    local = fn_801DD9E0(inv, *a);
    if (fn_801DE350(local.start, local.direction, &count, roots, b->radius, a->radius, a->radius)
        && roots[0] > lbl_8037A4F0 && roots[0] < a->length) {
        float tr = roots[0];
        if (!out->valid || tr < out->distance) {
            Vec3 p = local.direction * tr + local.start;
            float rs = reciprocalSqrt(p.lengthSq());
            Vec3 c(p.x * rs, lbl_8037A4E0, p.z * rs);
            c.scale(b->radius);
            out->valid = 1;
            out->flags = flags;
            out->distance = tr;
            out->point = a->direction * tr + a->start;
            out->normal = m.rotate((p - c).normalize());
            return 1;
        }
    }
    return result;
}
