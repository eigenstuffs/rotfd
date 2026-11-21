#pragma inline_max_size(100000)
// fn_801E059C: sphere vs capped cylinder (segment start/length/dir + radius) contact generation:
// before the start cap, beyond the end cap (closest point clamped to the cap disc), or along the side.
// Contacts are appended to a 256-entry Hits list (placement-new Hit at +0x2800 count).
// The whole body lives in the inline sphereCylinder() called by a thin wrapper (inline arguments then get
// real parameter temps instead of substituted expressions).
// The two cap branches share the inline capClosest helper (projection clamped to the cap disc);
// operator* is member-assignment style so the normal is computed x,y,z as in the target.
// w18 (EXACT): (1) capClosest computes v from proj AFTER 'closest = proj': the three copies survive to
// register allocation, are coalesced and deleted there, and a block that loses instructions at RA is
// scheduled a second time with physical-register dependencies (that is the target's far-cap order);
// (2) length() writes the fres result straight into r (no fastSqrt return temp): the coalesced alias of
// each sqrt result otherwise stays in every neighbour list and pushed dir.z out of the first simplify pass.
// w20: the constants are the shared named .sdata2 constants lbl_8037A4E0/E4/E8 (0.0f / 1.0f / 0.000001f,
// owned by grid_triangle_sweep_constants.c / scalar_constant_8037A4E8.c), not literals of this unit. To get
// the literal-style per-use reloads, capClosest reads 0.0f and 0.000001f through '*(const float*)&' (a
// spelling the frontend CSE does not identify with the plain reads in sphereCylinder; the backend still
// merges identical loads as it does for literals).
extern "C" {
extern const float lbl_8037A4E0;
extern const float lbl_8037A4E4;
extern const float lbl_8037A4E8;
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
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator*(float s) const { Vec3 r; r.x = x * s; r.y = y * s; r.z = z * s; return r; }
    Vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    float lengthSq() const { return x * x + y * y + z * z; }
    float length(float zero) const
    {
        register float sq = lengthSq();
        register float r = zero;
        if (sq != r) { asm { frsqrte f4, sq
            fres r, f4 } }
        return r;
    }
};
struct Sphere { Vec3 center; float radius; };
struct Cylinder { Vec3 start; float length; Vec3 dir; float unknown1C; float radius; };
struct Hit {Vec3 point;float distance;Vec3 normal;void*object;unsigned long long token;Hit(){object=0;}};
inline void*operator new(unsigned long,void*p){return p;}
struct Hits {Hit records[256];int count;int append(){if(count>=256){new(&records[255])Hit;return 255;}new(&records[count++])Hit;return count-1;}};

inline void capClosest(const Cylinder* c, const Vec3& cap, const Vec3& proj, Vec3& closest)
{
    closest = proj;
    Vec3 v = proj - cap;
    float l = v.length(*(const float*)&lbl_8037A4E0);
    if (!(l < *(const float*)&lbl_8037A4E8)) {
        Vec3 n = v * (lbl_8037A4E4 / l);
        if (l > c->radius) { n *= c->radius; closest = cap + n; }
    }
}
inline int sphereCylinder(const Sphere* s, const Cylinder* c, Hits* out, unsigned long long token)
{
    float t = c->dir.dot(s->center - c->start);
    if (t < lbl_8037A4E8) {
        Vec3 closest;
        capClosest(c, c->start, s->center - c->dir * t, closest);
        Vec3 d = s->center - closest;
        float dist = d.length(lbl_8037A4E0);
        if (dist < s->radius) {
            Vec3 n = d * (lbl_8037A4E4 / dist);
            Hit& hit = out->records[out->append()];
            hit.point = closest;
            hit.normal = n;
            hit.distance = dist;
            hit.token = token;
            return 1;
        }
    } else if (t > c->length) {
        Vec3 closest;
        capClosest(c, c->start + c->dir * c->length, s->center + c->dir * (c->length - t), closest);
        Vec3 d = s->center - closest;
        float dist = d.length(lbl_8037A4E0);
        if (dist < s->radius) {
            Vec3 n = d * (lbl_8037A4E4 / dist);
            Hit& hit = out->records[out->append()];
            hit.point = closest;
            hit.normal = n;
            hit.distance = dist;
            hit.token = token;
            return 1;
        }
    } else {
        Vec3 p = c->start + c->dir * t;
        Vec3 d = s->center - p;
        float dist = d.length(lbl_8037A4E0);
        if (dist < s->radius + c->radius) {
            Vec3 n = d * (lbl_8037A4E4 / dist);
            Hit& hit = out->records[out->append()];
            hit.point = p + n * c->radius;
            hit.normal = n;
            hit.distance = dist - c->radius;
            hit.token = token;
            return 1;
        }
    }
    return 0;
}
extern "C" int fn_801E059C(const Sphere* s, const Cylinder* c, Hits* out, void*, unsigned long long token)
{
    return sphereCylinder(s, c, out, token);
}
