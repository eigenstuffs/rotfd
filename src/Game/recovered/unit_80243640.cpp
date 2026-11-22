/* fn_80243640: point-in-wedge test (cone/sector volume). */
typedef unsigned int u32;
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
inline float squareRoot(float x)
{
    float r = 0.0f;
    if (x != r) r = fastSqrt(x);
    return r;
}
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};
struct Quat {
    float w, x, y, z;
    Quat() {}
};
extern "C" {
float fn_8028506C(float);
float fn_80284FA8(float);
Vec3 fn_801F1B1C(const Quat* q, const Vec3* v);
}
inline void makeQuat(Quat& q, const Vec3& axis, float angle)
{
    q.w = fn_8028506C(angle);
    float s = fn_80284FA8(angle);
    q.x = axis.x * s;
    q.y = axis.y * s;
    q.z = axis.z * s;
}
struct Scalar { float v; };
struct Plane {
    float x, y, z, d;
    Plane() {}
    Plane(float a, float b, float c, const Vec3& p)
    {
        x = a; y = b; z = c;
        d = -(a * p.x + b * p.y + c * p.z);
    }
    Plane(const Vec3& a, const Vec3& b, const Vec3& c)
    {
        x = a.y * (b.z - c.z) + b.y * (c.z - a.z) + c.y * (a.z - b.z);
        y = a.z * (b.x - c.x) + b.z * (c.x - a.x) + c.z * (a.x - b.x);
        z = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
        d = x * a.x + y * a.y + z * a.z;
        d = -d;
    }
    void set(const Vec3& a, const Vec3& b, const Vec3& c)
    {
        x = a.y * (b.z - c.z) + b.y * (c.z - a.z) + c.y * (a.z - b.z);
        y = a.z * (b.x - c.x) + b.z * (c.x - a.x) + c.z * (a.x - b.x);
        z = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
        d = x * a.x + y * a.y + z * a.z;
        d = -d;
    }
    float dist(const Vec3& p) const { return d + x * p.x + y * p.y + z * p.z; }
};
struct Matrix {
    float a[16];
};
struct MatrixCache {
    Matrix* arrays[6];
    unsigned char active;
};
struct Globals {
    char unknown[0x134];
    MatrixCache* cache;
};
extern "C" Globals lbl_801E9D24;
extern "C" void fn_801F230C(const Matrix*, Matrix*);
struct Object {
    char unknown[0x120];
    u32 flags;
    Matrix *matrix, *cached;
    char unknown12C[2];
    short index;
    Matrix* getMatrix()
    {
        if (flags & 0x20) {
            cached = lbl_801E9D24.cache->arrays[lbl_801E9D24.cache->active] + index;
            fn_801F230C(matrix, cached);
            flags &= ~0x20;
        }
        return cached;
    }
};
struct Volume {
    char unknown00[0x74];
    float width;
    float height;
    float radius;
    float angle;
    Vec3 edge(float a) const
    {
        Quat q;
        makeQuat(q, Vec3(0.0f, 1.0f, 0.0f), a * 0.5f);
        Vec3 v(0.0f, -(height * 0.5f), radius);
        v = fn_801F1B1C(&q, &v);
        return v;
    }
};
struct Result {
    char unknown00[0xC];
    float ratio;
};
inline bool inRange(const Volume* self, const Vec3& p)
{
    if (squareRoot(p.x * p.x + p.z * p.z) <= self->radius) {
        float h = self->height / 2.0f;
        if (p.y >= -h && p.y <= h)
            return true;
    }
    return false;
}
/* w21: MISMATCH 29 -> EXACT-MOD-POOL.  Pure vreg-numbering fixes found with the
   GC/1.3.2 debugger dump + simplify/colour simulator (/home/claude/work/f21a/rsim*.py):
   - Plane p1 declared early and filled by set(); dead p1.x, p1.y, c2.y, p1.z
     initialisers (in that order, after p0) put c2.y between p1.y and p1.z;
   - the q1 angle is the member of a one-member struct (SRA) pre-numbered by a
     dead initialiser right after p1.z;
   - phase-1 corner members are pre-numbered by dead initialisers at the top and
     really assigned after p0 (moves the -width fneg after p0's 0.0 load);
   - phase-2 statement order b2.y, b2.x, a2, c2.x, c2.y (pre-RA schedule). */
extern "C" int fn_80243640(Volume* self, Object* object, const Vec3* a, const Vec3* unused, Result* result)
{
    Vec3 c, b, c2, b2;
    Plane p1;
    Scalar ang;
    b2.z = 0.0f;
    Matrix m = *object->getMatrix();
    c.z = 0.0f;
    b.x = 0.0f;
    c.x = 0.0f;
    b.z = 0.0f;
    c.y = 0.0f;
    b.y = 0.0f;
    b2.y = 0.0f;
    Vec3 p;
    p.x = m.a[12] + (m.a[0] * a->x + m.a[4] * a->y + m.a[8] * a->z);
    p.y = m.a[13] + (m.a[1] * a->x + m.a[5] * a->y + m.a[9] * a->z);
    p.z = m.a[14] + (m.a[2] * a->x + m.a[6] * a->y + m.a[10] * a->z);
    Plane p0(0.0f, 0.0f, 1.0f, Vec3(0.0f, 0.0f, 0.0f));
    b.x = -self->width / 2.0f;
    c.x = -self->width / 2.0f;
    c.y = -self->height / 2.0f;
    b.y = self->height / 2.0f;
    p1.x = 0.0f;
    p1.y = 0.0f;
    c2.y = 0.0f;
    p1.z = 0.0f;
    ang.v = 0.0f;
    Vec3 v;
    ang.v = -self->angle / 2.0f / 2.0f;
    Quat q1;
    makeQuat(q1, Vec3(0.0f, 1.0f, 0.0f), ang.v);
    c2.x = 0.0f;
    v = Vec3(0.0f, -(self->height / 2.0f), self->radius);
    v = fn_801F1B1C(&q1, &v);
    p1.set(c, b, v);
    c2.z = 0.0f;
    b2.z = 0.0f;
    b2.y = -self->height / 2.0f;
    b2.x = self->width / 2.0f;
    float a2 = self->angle / 2.0f / 2.0f;
    c2.x = self->width / 2.0f;
    c2.y = self->height / 2.0f;
    Quat q2;
    makeQuat(q2, Vec3(0.0f, 1.0f, 0.0f), a2);
    v = Vec3(0.0f, -(self->height / 2.0f), self->radius);
    v = fn_801F1B1C(&q2, &v);
    Plane p2(c2, b2, v);
    result->ratio = squareRoot(p.x * p.x + p.z * p.z) / self->radius;
    const float zero = 0.0f;
    if (self->angle > 3.1415927f) {
        if (!self->width) {
            float d1 = p1.dist(p);
            float d2 = p2.dist(p);
            if (d1 >= 0.0f || d2 >= 0.0f) {
                if (squareRoot(p.x * p.x + p.z * p.z) <= self->radius) {
                    float h = self->height / 2.0f;
                    if (p.y >= -h && p.y <= h)
                        return 1;
                }
            }
            return 0;
        } else {
            float d0 = p0.dist(p);
            float d1 = p1.dist(p);
            float d2 = p2.dist(p);
            if (d0 >= 0.0f || d1 >= 0.0f || d2 >= 0.0f) {
                if (squareRoot(p.x * p.x + p.z * p.z) <= self->radius) {
                    float h = self->height / 2.0f;
                    if (p.y >= -h && p.y <= h)
                        return 1;
                }
            }
            return 0;
        }
    } else {
        if (!self->width) {
            float d1 = p1.dist(p);
            float d2 = p2.dist(p);
            if (d1 >= 0.0f && d2 >= 0.0f) {
                if (squareRoot(p.x * p.x + p.z * p.z) <= self->radius) {
                    float h = self->height / 2.0f;
                    if (p.y >= -h && p.y <= h)
                        return 1;
                }
            }
            return 0;
        } else {
            float d0 = p0.dist(p);
            float d1 = p1.dist(p);
            float d2 = p2.dist(p);
            if (d0 >= 0.0f && d1 >= 0.0f && d2 >= 0.0f) {
                if (squareRoot(p.x * p.x + p.z * p.z) <= self->radius) {
                    float h = self->height / 2.0f;
                    if (p.y >= -h && p.y <= h)
                        return 1;
                }
            }
            return 0;
        }
    }
}
