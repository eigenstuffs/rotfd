/* auto_03_801DC784_text: collision-geometry helpers between
   fn_801DC5E8 (record_object_space_transform) and fn_801DDBFC
   (box_collision_nearest_hit); same original TU and flags as the latter
   (-O4,p, -Cpp_exceptions off, GC/1.3.2).

   fn_801DC784  sphere/direction records (0x48 stride) into object space;
                twin of fn_801DC5E8.                                 EXACT
   fn_801DC8B4  mesh-strip collision: count+2 vertices, two edges per
                strip position, then signed-short indexed triangles with
                alternating winding.  The index pointers must be plain
                `short*`: with `const short*` CodeWarrior lets the next
                index load move above the previous vertex's stores and the
                triangle vertex copies interleave.                   EXACT
   fn_801DCCE8  capsule (segment+radius) against capped cylinder: end-cap
                planes, side, then the two rounded rims through the
                quartic solver fn_801DE350 in the cylinder's frame.
                Partial: code shape, stack frame and every load/store
                match; floating-point register allocation differs and one
                extra non-volatile FPR (f16) is saved.
   fn_801DD9E0  transform a segment by a matrix and renormalise.
                Partial (register allocation only).
   fn_801DDB3C  segment from two points.                              EXACT

   The original pooled its float literals; the shared labels are read in
   the three distinct forms (plain, *(const float*)&, and
   *(const float*)(unsigned long)&) so each region reloads them where the
   original did.  Segment has user-declared special members: an implicit
   (non-trivial) Segment assignment/copy makes CodeWarrior emit
   fn_801DD9E0/fn_801DDB3C ahead of fn_801DCCE8. */
typedef unsigned long long Mask;

extern "C" {
void* memset(void*, int, unsigned long);
extern const float lbl_8037A4E0;
extern const float lbl_8037A4E4;
extern const float lbl_8037A4E8;
extern const double lbl_8037A4F0;
}

#define ZERO_Q (*(const float*)&lbl_8037A4E0)
#define ONE_Q (*(const float*)&lbl_8037A4E4)
#define EPS_Q (*(const float*)&lbl_8037A4E8)
#define EPS_R (*(const float*)(unsigned long)&lbl_8037A4E8)

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
    float r = lbl_8037A4E0;
    if (sq != r) r = fastSqrt(sq);
    return r;
}

namespace RecordTransform801DC784 {

inline float vectorLength(float x, float y, float z)
{
    float sq = x * x + y * y + z * z;
    float r = lbl_8037A4E0;
    if (sq != r) r = fastSqrt(sq);
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
};

struct Matrix {
    float m[16];
    float scale() const { return vectorLength(m[0], m[4], m[8]); }
    Vec3 transform(const Vec3& v) const
    {
        Vec3 r;
        r.x = m[12] + (m[0] * v.x + m[4] * v.y + m[8] * v.z);
        r.y = m[13] + (m[1] * v.x + m[5] * v.y + m[9] * v.z);
        r.z = m[14] + (m[2] * v.x + m[6] * v.y + m[10] * v.z);
        return r;
    }
};

struct Basis {
    float m[9];
    Vec3 transform(const Vec3& v) const
    {
        Vec3 r;
        r.x = m[0] * v.x + m[3] * v.y + m[6] * v.z;
        r.y = m[1] * v.x + m[4] * v.y + m[7] * v.z;
        r.z = m[2] * v.x + m[5] * v.y + m[8] * v.z;
        return r;
    }
};

struct Object {
    char unknown00[0x30];
    Basis basis;
    char unknown54[0x124 - 0x54];
    Matrix* matrix;
};

struct Record {
    Vec3 point;
    float radius;
    Vec3 direction;
    char unknown1C[0x30 - 0x1C];
    Object* object;
    char unknown34[0x48 - 0x34];
};

typedef char RecordSize[sizeof(Record) == 0x48 ? 1 : -1];
typedef char ObjectSize[sizeof(Object) == 0x128 ? 1 : -1];

} // namespace RecordTransform801DC784


namespace MeshScan329 {
typedef unsigned long long Mask;
struct Point {
    float x,y,z;
    Point& operator=(const Point& p) {x=p.x;y=p.y;z=p.z;return *this;}
};
extern "C" const float lbl_8037A4E4;
struct Vertex {
    float x,y,z,w;
    Vertex() {}
    Vertex(const Point& p) {x=p.x;y=p.y;z=p.z;w=lbl_8037A4E4;}
    Vertex& operator=(const Point& p) {x=p.x;y=p.y;z=p.z;w=lbl_8037A4E4;return *this;}
};
struct Geometry;
struct Hit {Point point;float distance;Point normal;unsigned int unknown1C;float unknown20,unknown24;unsigned int unknown28,unknown2C;};
struct Result {
    Point point;float distance;Point normal;char unknown1C[12];Mask flags;
    unsigned int unknown30,unknown34,unknown38;signed char valid;
};
extern "C" signed char fn_801B6DD4(Geometry*,const Vertex&,Hit*);
extern "C" signed char fn_801B85B0(Geometry*,const Vertex&,const Vertex&,Hit*);
extern "C" signed char fn_8027A410(Geometry*,const Vertex&,const Vertex&,const Vertex&,Hit*);
inline void setResult(Result* result,const Hit& hit,Mask flags) {
    result->valid=1;result->flags=flags;result->normal=hit.normal;
    result->point=hit.point;result->distance=hit.distance;
}
}

namespace MeshScan329 {
typedef char PointSize[sizeof(Point)==12?1:-1];
typedef char VertexSize[sizeof(Vertex)==16?1:-1];
typedef char HitSize[sizeof(Hit)==48?1:-1];
typedef char ResultSize[sizeof(Result)==64?1:-1];
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
    Vec3 cross(const Vec3& v) const
    {
        return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }
    float lengthSq() const { return x * x + y * y + z * z; }
    float length() const
    {
        float sq = lengthSq();
        float r = ZERO_Q;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    float distanceSq(const Vec3& v) const
    {
        float dx = x - v.x;
        float dy = y - v.y;
        float dz = z - v.z;
        return dx * dx + dy * dy + dz * dz;
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
        m[0] = lbl_8037A4E4;
        m[5] = lbl_8037A4E4;
        m[10] = lbl_8037A4E4;
        m[15] = lbl_8037A4E4;
    }
    Vec3 transform(const Vec3& v) const
    {
        Vec3 r;
        r.x = m[12] + (m[0] * v.x + m[4] * v.y + m[8] * v.z);
        r.y = m[13] + (m[1] * v.x + m[5] * v.y + m[9] * v.z);
        r.z = m[14] + (m[2] * v.x + m[6] * v.y + m[10] * v.z);
        return r;
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

extern "C" int fn_801DCCE8(const Segment* a, const Cylinder* b, Result* out, Mask flags);

extern "C" {
Segment fn_801DD9E0(const Matrix& matrix, const Segment& segment);
void fn_801DDB3C(Segment* segment, const Vec3& start, const Vec3& end);
void fn_801F230C(const Matrix* matrix, Matrix* inverse);
int fn_801DE350(Vec3 start, Vec3 direction, int* count, double* roots,
                float radius, float a, float b);
}

/* @@FN_801DDB3C@@ */
extern "C" void fn_801DDB3C(Segment* segment, const Vec3& start, const Vec3& end)
{
    segment->start = start;
    segment->direction = end - start;
    segment->length = segment->direction.length();
    if (segment->length > lbl_8037A4E8) {
        float inv = lbl_8037A4E4 / segment->length;
        segment->direction.x *= inv;
        segment->direction.y *= inv;
        segment->direction.z *= inv;
    }
}
/* @@END@@ */
