/* fn_8024222C: blend up to four edge contact records into one result
 * (inverse-distance weights, averaged heading).
 * w13 shape notes: temps that are `this` of a member call made directly inside
 * an inline body stay on the stack ((a - b).isNull() in operator==, the
 * axis*sin product in the Quat(axis, angle) ctor via self()); the count read
 * inside loop 2 goes through the Head base so it is reloaded. */
typedef unsigned long Word;
extern "C" {
double __fabs(double);
float fn_8028506C(float);
float fn_80284FA8(float);
float fn_80285124(float, float);
}
inline float rsqrt(register float x)
{
    register float r;
    asm { frsqrte r, x }
    return r;
}
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
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    const Vec3& self() const { return *this; }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    signed char isNull() const;
    void dot3(const Vec3& v, float& r) const { r = x * v.x + y * v.y + z * v.z; }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = 0.0f;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    float lengthSq() const
    {
        Vec3 sq(x * x, y * y, z * z);
        return sq.x + sq.y + sq.z;
    }
    float lengthSqF() const { float xx = x * x; float yy = y * y; float zz = z * z; return xx + yy + zz; }
    float lengthU() const
    {
        float sq = lengthSq();
        float r = 0.0f;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    void normalize()
    {
        float s = rsqrt(lengthSqF());
        x *= s; y *= s; z *= s;
    }
    void normalizeFast()
    {
        float s = rsqrt(x * x + y * y + z * z);
        x *= s; y *= s; z *= s;
    }
};
inline float root(float sq) { float r = 0.0f; if (sq != r) r = fastSqrt(sq); return r; }
extern "C" const Vec3 game_vec3_zero;
inline double absd(double v) { return __fabs(v); }
inline signed char Vec3::isNull() const { int xy; signed char r; r = 0; xy = 0; if ((float)absd(x) < 0.000001f) if ((float)absd(y) < 0.000001f) xy = 1; if (xy != 0) if ((float)absd(z) < 0.000001f) r = 1; return r; }
inline signed char isZero(const Vec3& v) { int xy = 0; signed char r = 0; if ((float)__fabs(v.x) < 0.000001f) if ((float)__fabs(v.y) < 0.000001f) xy = 1; if (xy != 0) if ((float)__fabs(v.z) < 0.000001f) r = 1; return r; }
inline Vec3 subr(const Vec3& a, const Vec3& b) { float dz = a.z - b.z; float dy = a.y - b.y; return Vec3(a.x - b.x, dy, dz); }
inline signed char operator==(const Vec3& a, const Vec3& b) { return subr(a, b).isNull(); }
struct Quat {
    float w;
    Vec3 v;
    Quat() {}
    Quat(float aw, const Vec3& av) : w(aw), v(av) {}
    Quat(const Vec3& axis, float angle);
};
inline Vec3 scale(const Vec3& v, float s) { return Vec3(v.x * s, v.y * s, v.z * s); }
inline Quat::Quat(const Vec3& axis, float angle) { w = fn_8028506C(angle); v = scale(axis, fn_80284FA8(angle)).self(); }
inline void setAxisAngle(Quat& q, const Vec3& axis, float angle)
{
    float c = fn_8028506C(angle);
    float s = fn_80284FA8(angle);
    q.w = c;
    q.v.x = axis.x * s;
    q.v.y = axis.y * s;
    q.v.z = axis.z * s;
}
inline void setAxisAngleT(Quat& q, const Vec3& axis, float angle)
{
    q.w = fn_8028506C(angle);
    q.v = scale(axis, fn_80284FA8(angle)).self();
}
extern "C" Vec3 fn_801F1B1C(const Quat* q, const Vec3* v);
inline Vec3 rotate(const Quat& q, const Vec3& v) { return fn_801F1B1C(&q, &v); }
struct Color {
    float r, g, b, a;
    Color() {}
    Color(float ar, float ag, float ab) : r(ar), g(ag), b(ab), a(1.0f) {}
    Color(float ar, float ag, float ab, float aa) : r(ar), g(ag), b(ab), a(aa) {}
    Color operator*(float s) const { return Color(r * s, g * s, b * s); }
    void operator+=(const Color& c) { r += c.r; g += c.g; b += c.b; a += c.a; }
};
struct Edge {
    int first, second;
    char unknown08[0xF0];
};
struct Mesh {
    char unknown00[0x7C];
    Vec3* vertices;
    char unknown80[8];
    Edge* edges;
};
struct Record {
    float angle;
    float radius;
    float deltaY;
    float distance;
    float unknown10;
    float value14;
    float value18;
    Color color;
    unsigned short flags;
    unsigned short edge;
    unsigned short vertex;
    unsigned short unknown32;
    float length;
    Vec3 dir;
};
struct Head { int index; Word handle; int count; };
struct Readback : Head {
    int indices[4];
    Record records[4];
};
struct Result {
    unsigned char active;
    Vec3 first;
    Vec3 second;
    float radius;
    float value20;
    float value24;
    Color color;
    float deltaY;
    float distance;
};
extern "C" int fn_8024222C(Mesh* self, const Vec3* pos, const Vec3* from, const Readback* faces, Result* out)
{
    float weights[4];
    int i;
    out->active = 1;
    out->first = *from;
    float sum = 0.0f;
    float sumInv = 0.0f;
    Vec3 p = *pos; p.y = 0.0f;
    for (i = 0; i < faces->count; i++) {
        const Record& rec = faces->records[i];
        Vec3 v0(self->vertices[self->edges[rec.edge].first].x, 0.0f, self->vertices[self->edges[rec.edge].first].z);
        const Vec3& s = self->vertices[self->edges[rec.edge].second];
        Vec3 v1(s.x, 0.0f, 0.0f); v1.z = s.z;
        Vec3 dir(rec.dir.x, rec.dir.y, rec.dir.z);
        float t; (p - v0).dot3(dir, t);
        Vec3 c = v0;
        if (t > rec.length)
            c = v1;
        else if (t > 0.000001f)
            c = dir * t + v0;
        Vec3 diff = c - p;
        float dist = 0.0f;
        if (!(diff == game_vec3_zero)) {
            dist = diff.length();
            sumInv += 1.0f / dist;
        }
        sum += dist;
        weights[i] = dist;
    }
    float deltaY = 0.0f;
    float distance = 0.0f;
    float radius = 0.0f;
    float value14 = 0.0f;
    float value18 = 0.0f;
    Vec3 heading = game_vec3_zero;
    Color color(0.0f, 0.0f, 0.0f, 1.0f);
    for (i = 0; i < faces->count; i++) {
        float w = 1.0f;
        if (((const Head*)faces)->count > 2)
            w = 1.0f / weights[i] / sumInv;
        else if (((const Head*)faces)->count != 1)
            w = (sum - weights[i]) / sum;
        const Record& rec = faces->records[i];
        Vec3 v = self->vertices[rec.vertex];
        float dy = rec.deltaY;
        float dist = rec.distance;
        Vec3 d;
        if ((rec.flags & 0x4004) == 4) {
            d = v - *from;
            d.y = 0.0f;
            d.normalize();
            d = rotate(Quat(Vec3(0.0f, 1.0f, 0.0f), 0.7853982f), d);
            Vec3 f = *pos - v; f.y = 0.0f;
            dy = v.y - pos->y;
            dist = f.length();
        } else if ((rec.flags & 0x8002) == 2) {
            d = *pos - v;
            d.y = 0.0f;
            root(Vec3(pos->x - v.x, 0.0f, pos->z - v.z).lengthSqF());
            d.normalize();
            d = rotate(Quat(Vec3(0.0f, 1.0f, 0.0f), 0.7853982f), d);
        } else {
            Quat q;
            setAxisAngle(q, Vec3(0.0f, 1.0f, 0.0f), rec.angle / 2.0f);
            d = fn_801F1B1C(&q, &rec.dir);
        }
        deltaY += dy * w;
        distance += dist * w;
        radius += rec.radius * w;
        value14 += rec.value14 * w;
        color += rec.color * w;
        value18 += rec.value18 * w;
        heading.x += d.x * w;
        heading.z += d.z * w;
    }
    heading.normalizeFast();
    Quat q;
    setAxisAngle(q, Vec3(0.0f, 1.0f, 0.0f), fn_80285124(-heading.z, heading.x) / 2.0f);
    Vec3 offset(0.0f, 0.0f, distance);
    offset = fn_801F1B1C(&q, &offset);
    out->second = *pos + offset;
    out->deltaY = deltaY;
    out->distance = distance;
    out->second.y += deltaY + (from->y - pos->y);
    float k = 0.08726646f; out->radius = radius + k;
    out->value20 = value14;
    out->color = color;
    out->value24 = value18;
    { float z = 0.0f; out->first.y += z; }
    return 1;
}

// ---- fn_80242A24 (was Game/collision_contact_blend_tail_80242A24.cpp) ----
namespace blend_tail {
typedef unsigned long Word;
extern "C" {
}
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
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    float length() const
    {
        const float& a = x;
        const float& b = y;
        const float& c = z;
        float sq = a * a + b * b + c * c;
        float r = 0.0f;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};
struct Edge {
    int first, second;
    char unknown08[0xF0];
};
inline const int& secondVertex(const Edge& e) { return e.second; }
struct Polygon {
    int kind;
    Word unknown04;
    unsigned short* edges;
    char unknown0C[12];
    int edgeAt(int n) const { return edges[n]; }
    unsigned short flags;
    char unknown1A[6];
};
struct Mesh {
    char unknown00[0x7C];
    Vec3* vertices;
    char unknown80[8];
    Edge* edges;
    char unknown8C[0x14];
    int count, capacity;
    Polygon* polygons;
};
struct Record {
    float angle;
    float radius;
    float deltaY;
    float distance;
    float unknown10;
    float value14;
    float value18;
    float color[4];
    unsigned short flags;
    unsigned short edge;
    unsigned short vertex;
    unsigned short unknown32;
    float length;
    Vec3 dir;
};
struct Readback {
    int index;
    Word handle;
    int count;
    int indices[4];
    Record records[4];
};
struct Result {
    unsigned char active;
    Vec3 first;
    Vec3 second;
    float radius;
    float value20;
    float value24;
    float color[4];
    float deltaY;
    float distance;
};
extern "C" int fn_80242A24(Mesh* self, const Vec3* pos, const Readback* faces, Result* out)
{
    out->active = 0;
    int i;
    for (i = 0; i < self->count; i++)
        if (self->polygons[i].kind == 3)
            break;
    if (self->count != 2)
        return 0;
    if (i == self->count)
        return 0;
    const Record& rec = faces->records[0];
    int k;
    for (k = 0; k < 3; k++)
        if (rec.edge == self->polygons[i].edgeAt(k))
            break;
    int next = (k + 1) % 3;
    const Polygon& poly = self->polygons[i];
    unsigned short mask = 1 << next;
    unsigned short edge = poly.edges[next];
    if (mask & poly.flags)
        out->second = self->vertices[secondVertex(self->edges[edge])];
    else
        out->second = self->vertices[self->edges[edge].first];
    float pad = 0.08726646f; out->radius = rec.radius + pad;
    out->value20 = rec.value14;
    out->first = self->vertices[rec.vertex];
    out->deltaY = out->second.y - out->first.y;
    out->distance = (out->second - out->first).length();
    return 1;
}

}
