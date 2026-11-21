/* TU for 0x801D6FB4..0x801D7B5C: cubic Bezier edge through a 4x4 matrix,
 * fn_801D6FB4 = arc length up to parameter u (optionally the point at u),
 * fn_801D75C0 = parameter/point at arc distance dist.  The TU's private
 * .sdata2 is lbl_8037A4A0 (3.0f), lbl_8037A4A4 (6.0f), lbl_8037A4A8 (1.0f),
 * lbl_8037A4AC (0.0f), lbl_8037A4B0 (signed int-to-float bias), 24 bytes,
 * 8-aligned.  fn_801AFFBC is the engine's out-of-line Vec3 * float, returning
 * the vector through the hidden result pointer.
 * Matching notes:
 * - Both functions use compiler-generated Vec3 copy members, so CodeWarrior
 *   defers them and emits them in reverse definition order: the source is in
 *   reverse address order.
 * - length() binds *this to a reference; this keeps the squared terms as
 *   separate fmuls/fadds and materialises the difference temporaries.
 * - fn_801D6FB4: `length` is declared before `remaining` (FPR f16/f17 order).
 * - fn_801D75C0: the loop evaluates the cubic through a working vector w
 *   (copy-form steps, the c step written member-wise z,y,x, the last scale
 *   in place) and then p = w; p.add(d).  These spellings fix the FPR
 *   colouring of the chain (x/y/z = f1/f2/f3) and of p (f7/f8/f9). */
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
    void add(const Vec3& v) { x = v.x + x; y = v.y + y; z = v.z + z; }
    void scale(float s) { x = x * s; y = y * s; z = z * s; }
    float length() const
    {
        const Vec3& v = *this;
        float sq = v.x * v.x + v.y * v.y + v.z * v.z;
        float r = 0.0f;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

struct Matrix {
    float m[16];
    Vec3 transform(const Vec3& v) const
    {
        Vec3 r;
        r.x = m[12] + (m[0] * v.x + m[4] * v.y + m[8] * v.z);
        r.y = m[13] + (m[1] * v.x + m[5] * v.y + m[9] * v.z);
        r.z = m[14] + (m[2] * v.x + m[6] * v.y + m[10] * v.z);
        return r;
    }
};

struct Edge { unsigned short vert[2]; unsigned short ctrl[2]; };
struct Segment { unsigned short unknown0; unsigned short edge; char pad[0x14]; };
struct Mesh {
    char pad[0x7c];
    Vec3* verts;
    char pad80[0x20];
    Segment* segments;
    char padA4[0x14];
    Edge* edges;
};
struct Grid { int subdivision; };
struct Context { char pad[0x128]; Grid* grid; };
extern "C" {
extern Context lbl_801E9D24;
Vec3 fn_801AFFBC(const Vec3&, float);
}

extern "C" float fn_801D75C0(Mesh* mesh, const Matrix& mtx, int index, Vec3* out, float dist)
{
    Edge& e = mesh->edges[mesh->segments[index].edge];
    Vec3 p0 = mtx.transform(mesh->verts[e.vert[0]]);
    Vec3 p1 = mtx.transform(mesh->verts[e.ctrl[0]]);
    Vec3 p2 = mtx.transform(mesh->verts[e.ctrl[1]]);
    Vec3 p3 = mtx.transform(mesh->verts[e.vert[1]]);
    Vec3 a = -p0 + p1 * 3.0f - p2 * 3.0f + p3;
    Vec3 b = p0 * 3.0f - p1 * 6.0f + p2 * 3.0f;
    Vec3 c = -p0 * 3.0f + p1 * 3.0f;
    Vec3 d = p0;
    float step = 1.0f / (float)(lbl_801E9D24.grid->subdivision + 1);
    Vec3 prev = d;
    for (int i = 1; i < lbl_801E9D24.grid->subdivision + 2; i++) {
        float t = step * (float)i;
        Vec3 w = fn_801AFFBC(a, t);
        w = b + w;
        w = w * t;
        w.z = c.z + w.z;
        w.y = c.y + w.y;
        w.x = c.x + w.x;
        w.scale(t);
        Vec3 p = w;
        p.add(d);
        float len = (p - prev).length();
        if (len > dist) {
            float s = t - step + dist * step / len;
            Vec3 q = b + fn_801AFFBC(a, s);
            q = q * s;
            q = c + q;
            q = q * s;
            *out = d + q;
            return s;
        }
        prev = p;
        dist -= len;
    }
    *out = p3;
    return 1.0f;
}

extern "C" float fn_801D6FB4(Mesh* mesh, const Matrix& mtx, int index, Vec3* out, float u)
{
    Edge& e = mesh->edges[mesh->segments[index].edge];
    Vec3 p0 = mtx.transform(mesh->verts[e.vert[0]]);
    Vec3 p1 = mtx.transform(mesh->verts[e.ctrl[0]]);
    Vec3 p2 = mtx.transform(mesh->verts[e.ctrl[1]]);
    Vec3 p3 = mtx.transform(mesh->verts[e.vert[1]]);
    Vec3 a = -p0 + p1 * 3.0f - p2 * 3.0f + p3;
    Vec3 b = p0 * 3.0f - p1 * 6.0f + p2 * 3.0f;
    Vec3 c = -p0 * 3.0f + p1 * 3.0f;
    Vec3 d = p0;
    float step = 1.0f / (float)(lbl_801E9D24.grid->subdivision + 1);
    float length = 0.0f;
    float remaining = u;
    Vec3 prev = d;
    for (int i = 1; i < lbl_801E9D24.grid->subdivision + 2; i++) {
        float t = step * (float)i;
        Vec3 p = b + fn_801AFFBC(a, t);
        p = p * t;
        p = c + p;
        p = p * t;
        p = d + p;
        if (step > remaining) {
            length += remaining * (p - prev).length() / step;
            if (out) {
                Vec3 q = b + fn_801AFFBC(a, u);
                q = q * u;
                q = c + q;
                q = q * u;
                *out = d + q;
            }
            return length;
        }
        length += (p - prev).length();
        prev = p;
        remaining -= step;
    }
    if (out) *out = p3;
    return length;
}
