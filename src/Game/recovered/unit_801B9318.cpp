/* auto_03_801B9318_text: 2D/3D sphere/capsule/cylinder overlap tests.
   GC/1.3.2, -O4,p, -fp_contract on.
   EXACT: fn_801B9318, fn_801B9458, fn_801B9620, fn_801B98A4, fn_801B99DC,
   fn_801BA38C and fn_801B9D1C (all seven).
   fn_801B9620: the frsqrte/fres helper writes straight into the result
   variable (`fres r, f4` inside sqrtOrZero).  A separate fastSqrt() helper
   returns through a temporary that is coalesced into the result; coalesced
   copies stay in the interference graph and raise the degree of every value
   live across them, which changed the simplify order of the CSE'd
   differences.
   Register colouring follows the creation order of locals: a component kept
   in a small local array (float d[3]) is coloured after named scalars, which
   is what fixed fn_801B9458.  An element's colouring rank is set by its
   FIRST assignment, while the order of the arithmetic sets the rank of the
   operands it reads; pre-assigning d[k] = component (then d[k] -= o.k)
   decouples the two, which fixed fn_801BA38C.
   Each function keeps its own operator spellings (namespaces) because the
   spelling of the inline operators drives register colouring. */
extern "C" { extern const float lbl_8037A250; extern const float lbl_8037A258; extern const float lbl_8037A264; }
/* Read forms of one pooled constant that the compiler keeps apart (the
   original reloads its literals per block; same idiom as
   segment_sphere_quad_queries_801B74D8.cpp). */
#define K0(l) (l)
#define K1(l) (*(const float*)&(l))
#define K2(l) (*(const float*)(unsigned long)&(l))
#define K3(l) (*(const float*)(long)&(l))
#define K4(l) (*(const float*)(unsigned int)&(l))
namespace w3_2_9318 {
struct Vec3 { float x, y, z; };
struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
    Vec2(float a, float b, float) { y = b; x = a; }
    Vec2(const Vec3& v) { y = v.x; x = v.z; }
    Vec2 operator-(const Vec2& o) const { return Vec2(x - o.x, y - o.y); }
    Vec2 sub1(const Vec2& o) const { return Vec2(x - o.x, y - o.y, 0.0f); }
    Vec2 operator+(const Vec2& o) const { return Vec2(x + o.x, y + o.y); }
    Vec2 operator*(float s) const { return Vec2(x * s, y * s); }
    Vec2 mul1(float s) const { return Vec2(x * s, y * s, 0.0f); }
    Vec2 add1(const Vec2& o) const { return Vec2(x + o.x, y + o.y, 0.0f); }
    float dot(const Vec2& o) const { return x * o.x + y * o.y; }
    float distSq(const Vec2& o) const { float b = y - o.y; float a = x - o.x; return a * a + b * b; }
    float lenSq() const { float a = x * x; float b = y * y; return a + b; }
};
inline Vec2 to2(const Vec3& v) { return Vec2(v.z, v.x); }
struct Sphere { Vec3 c; float r; };
struct Capsule { Vec3 p; float len; Vec3 d; float r; };
extern "C" signed char fn_801B9318(const Sphere* s, const Capsule* c) {
    Vec2 cd = to2(c->d); Vec2 sc = to2(s->c); Vec2 cp = to2(c->p);
    float t = sc.sub1(cp).dot(cd);
    float rr = (s->r + c->r) * (s->r + c->r);
    if ((cd.mul1(t) + cp).distSq(sc) > rr) return 0;
    if (t < lbl_8037A250) return (to2(c->p) - to2(s->c)).lenSq() < rr;
    if (t > c->len) return (to2(c->p) + to2(c->d) * c->len - to2(s->c)).lenSq() < rr;
    return 1;
}
}
namespace w3_2_9458 {
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator+(const Vec3& o) const { float rz = z + o.z; float ry = y + o.y; float rx = x + o.x; return Vec3(rx, ry, rz); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    float distSq(const Vec3& o) const { float d[3]; d[2] = z - o.z; float b = y - o.y; float a = x - o.x; float r = a * a + b * b + d[2] * d[2]; return r; }
    float lenSq() const { float a = x * x; float b = y * y; float c = z * z; return a + b + c; }
};
struct Sphere { Vec3 c; float r; };
struct Capsule { Vec3 p; float len; Vec3 d; float r; };
extern "C" signed char fn_801B9458(const Sphere* s, const Capsule* c) {
    float t = (s->c - c->p).dot(c->d);
    float sum = s->r + c->r;
    float rr = sum * sum;
    if ((c->d * t + c->p).distSq(s->c) > rr) return 0;
    if (t < lbl_8037A250) return (c->p - s->c).lenSq() < rr;
    if (t > c->len) return (c->p + c->d * c->len - s->c).lenSq() < rr;
    return 1;
}
}
namespace w7_9620 {
/* Returning the difference from an inline call (rather than a named local)
   makes the inliner's return temporaries number the distSq components after
   the dot-product temporary t, which colours t/add/distSq as in the target. */
inline float dif(float a, float b) { return a - b; }
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 sub1(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 sub2(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 sub4(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 sub5(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 add1(const Vec3& o) const { float rz = z + o.z; float ry = y + o.y; float rx = x + o.x; return Vec3(rx, ry, rz); }
    Vec3 add4(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 mul1(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 mul4(float s) const { return Vec3(x * s, y * s, z * s); }
    float dot1(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    float dot4(const Vec3& o) const { float d = x * o.x + y * o.y + z * o.z; return d; }
    float distSq(const Vec3& o) const { float d[3]; d[0] = x; d[1] = y; d[2] = z; d[2] -= o.z; d[1] -= o.y; d[0] -= o.x; float a = d[0]; return a * a + d[1] * d[1] + d[2] * d[2]; }
    float lenSq2() const { float rx = x * x; float ry = y * y; float rz = z * z; return rx + ry + rz; }
    float lenSq5() const { float a = x * x; float b = y * y; float c = z * z; return a + b + c; }
};
inline float sqrtOrZero(register float sq) { register float r = lbl_8037A250; if (sq != r) { asm { frsqrte f4, sq
    fres r, f4 } } return r; }
struct Sphere { Vec3 c; float r; };
struct Segment { Vec3 p; float len; Vec3 d; float r; };
struct Hit { Vec3 pos; float dist; Vec3 n; };
extern "C" signed char fn_801B9620(const Sphere* s, const Segment* c, Hit* out) {
    float r = s->r;
    float t = s->c.sub1(c->p).dot1(c->d);
    float rr = r * r;
    if (c->d.mul1(t).add1(c->p).distSq(s->c) > rr) return 0;
    if (t < lbl_8037A250) {
        if (c->p.sub2(s->c).lenSq2() < rr) {
            out->pos = c->p;
            out->dist = sqrtOrZero(c->p.sub5(s->c).lenSq5());
            return 1;
        }
        return 0;
    }
    out->pos = c->d.mul4(c->d.dot4(s->c.sub4(c->p))).add4(c->p);
    out->dist = sqrtOrZero(out->pos.sub5(s->c).lenSq5());
    return 1;
}
}
namespace w3_2_98A4 {
struct Vec3 { float x, y, z; };
struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
    Vec2(float a, float b, float) { y = b; x = a; }
    Vec2(const Vec3& v) { y = v.x; x = v.z; }
    Vec2 operator-(const Vec2& o) const { return Vec2(x - o.x, y - o.y); }
    Vec2 sub1(const Vec2& o) const { return Vec2(x - o.x, y - o.y, 0.0f); }
    Vec2 operator+(const Vec2& o) const { return Vec2(x + o.x, y + o.y); }
    Vec2 operator*(float s) const { return Vec2(x * s, y * s); }
    float dot(const Vec2& o) const { return x * o.x + y * o.y; }
    float distSq(const Vec2& o) const { float b = y - o.y; float a = x - o.x; return a * a + b * b; }
    float lenSq() const { float a = x * x; float b = y * y; return a + b; }
};
inline Vec2 to2(const Vec3& v) { return Vec2(v.z, v.x); }
struct Sphere { Vec3 c; float r; };
struct Capsule { Vec3 p; float len; Vec3 d; float r; };
extern "C" signed char fn_801B98A4(const Sphere* s, const Capsule* c) {
    Vec2 sc = to2(s->c); Vec2 cp = to2(c->p); Vec2 cd = to2(c->d);
    float t = sc.sub1(cp).dot(cd);
    float rr = s->r * s->r;
    if ((cd * t + cp).distSq(sc) > rr) return 0;
    if (t < lbl_8037A250) return (to2(c->p) - to2(s->c)).lenSq() < rr;
    if (t > c->len) return (to2(c->p) + to2(c->d) * c->len - sc).lenSq() < rr;
    return 1;
}
}
namespace w17_99DC {
/* Constants are re-read at every use (volatile read idiom); the frsqrte/fres
   pair writes straight into the result variable; q is declared before e in
   the far-cap branch; the cap normal is scaled in place (n *= r) and the hit
   normal is w /= dist. */
#define ZERO (*(const volatile float*)&lbl_8037A250)
#define ONE (*(const volatile float*)&lbl_8037A258)
#define EPS (*(const volatile float*)&lbl_8037A264)
inline float sqrtOrZero(register float sq) { register float r = ZERO; if (sq != r) { asm { frsqrte f4, sq
    fres r, f4 } } return r; }
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    void operator*=(float s) { x *= s; y *= s; z *= s; }
    Vec3 operator/(float s) const { Vec3 r; float inv = ONE / s; r.x = x * inv; r.y = y * inv; r.z = z * inv; return r; }
    void operator/=(float s) { float inv = ONE / s; x *= inv; y *= inv; z *= inv; }
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    float lenSq() const { return x * x + y * y + z * z; }
    float length() const { return sqrtOrZero(lenSq()); }
};
struct Sphere { Vec3 c; float r; };
struct Cyl { Vec3 p; float len; Vec3 d; float pad; float r; };
struct Hit { Vec3 pos; float dist; Vec3 n; };
extern "C" signed char fn_801B99DC(const Sphere* s, const Cyl* c, Hit* out) {
    float t = c->d.dot(s->c - c->p);
    if (t < EPS) {
        Vec3 q = s->c - c->d * t;
        Vec3 v = q - c->p;
        float l = v.length();
        if (!(l < EPS)) {
            Vec3 n = v / l;
            if (l > c->r) { n *= c->r; q = c->p + n; }
        }
        Vec3 w = s->c - q;
        float dist = w.length();
        if (dist < s->r) {
            out->pos = q;
            w /= dist; out->n = w;
            out->dist = dist;
            return 1;
        }
    } else if (t > c->len) {
        Vec3 q = s->c + c->d * (c->len - t);
        Vec3 e = c->p + c->d * c->len;
        Vec3 v = q - e;
        float l = v.length();
        if (!(l < EPS)) {
            Vec3 n = v / l;
            if (l > c->r) { n *= c->r; q = e + n; }
        }
        Vec3 w = s->c - q;
        float dist = w.length();
        if (dist < s->r) {
            out->pos = q;
            w /= dist; out->n = w;
            out->dist = dist;
            return 1;
        }
    } else {
        Vec3 q = c->p + c->d * t;
        Vec3 w = s->c - q;
        float dist = w.length();
        if (dist < s->r + c->r) {
            Vec3 n = w / dist;
            out->pos = q + n * c->r;
            out->n = n;
            out->dist = dist - c->r;
            return 1;
        }
    }
    return 0;
}
#undef ZERO
#undef ONE
#undef EPS
}
namespace w6_9D1C {
/* fn_801B9D1C (segment sweep against a capped cylinder).  What the match needed (GC/1.3.2 debugger dumps):
   - statement order f, e, planeA, tA, tB, pa, pb, planeB: the frontend numbers its CSE temporaries at the SECOND
     occurrence of a load, so c->p / c->d get theirs interleaved per component (y, x, z) in the planeA dot, before
     s->p (pa) and s->d; computing f before e gives the pre-RA schedule of the first block.
   - dir is first cleared in x, z, y member order (dead stores, no code) and then assigned pb - pa: field
     temporaries are numbered by FIRST assignment, so dir.y gets the lowest virtual register of the three, is
     scanned first and stays (31 neighbours) in the high-degree set with the loads, while the subtraction still
     evaluates pb's products in x, y, z order.
   - L comes from length() through one more inline level (len()): the sqrt result is then numbered below f / pa.
   - 0.000001 is read through a different expression at every use so that the frontend makes no CSE temporary
     (the backend merges the identical loads).  The plain literal 0.000001f at all eight uses gives the same
     code as EXACT-MOD-POOL (3 pool refs to lbl_8037A264) and is presumably the original spelling.
   - uh = u - h is a named local. */
#define EPS0 (*(const float*)&lbl_8037A264)
#define EPS1 (*(const float*)(unsigned long)&lbl_8037A264)
#define EPS2 (*(const float*)(long)&lbl_8037A264)
#define EPS3 (*(const float*)(unsigned int)&lbl_8037A264)
#define EPS4 (*(const float*)(int)&lbl_8037A264)
#define EPS5 (*(const float*)(const void*)&lbl_8037A264)
#define EPS6 (*(const float*)(const char*)&lbl_8037A264)
#define EPS7 (lbl_8037A264)
inline float rsqrt(register float x) { register float r; asm { frsqrte r, x } return r; }
inline float sqrtOrZero(register float sq) { register float r = lbl_8037A250; if (sq != r) { asm { frsqrte f4, sq
    fres r, f4 } } return r; }
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    void clear() { x = 0.0f; z = 0.0f; y = 0.0f; }
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    float distSq(const Vec3& o) const { float d[3]; d[0] = x; d[1] = y; d[2] = z; d[2] -= o.z; d[1] -= o.y; d[0] -= o.x; float a = d[0]; return a * a + d[1] * d[1] + d[2] * d[2]; }
    float lenSq() const { float a = x * x; float b = y * y; float c = z * z; return a + b + c; }
    float length() const { return sqrtOrZero(x * x + y * y + z * z); }
    float len() const { return length(); }
    Vec3& normalize() { float s = rsqrt(lenSq()); x *= s; y *= s; z *= s; return *this; }
};
struct Seg { Vec3 p; float len; Vec3 d; float pad; };
struct Cyl { Vec3 p; float len; Vec3 d; float pad; float r; };
struct Hit { Vec3 pos; float dist; Vec3 n; };
extern "C" signed char fn_801B9D1C(const Seg* s, const Cyl* c, Hit* out) {
    Vec3 f = c->p + c->d * c->len;
    Vec3 e = s->p + s->d * s->len;
    float planeA = -c->d.dot(c->p);
    float tA = (s->p - c->p).dot(c->d);
    float tB = (e - c->p).dot(c->d);
    Vec3 pa = s->p - c->d * tA;
    Vec3 pb = e - c->d * tB;
    float planeB = -c->d.dot(f);
    Vec3 dir;
    dir.clear();
    dir = pb - pa;
    float L = dir.len();
    if (L > EPS0) {
        float inv = lbl_8037A258 / L;
        dir.x *= inv; dir.y *= inv; dir.z *= inv;
    }
    float rr = c->r * c->r;
    float u = (c->p - pa).dot(dir);
    float d2 = (dir * u + pa).distSq(c->p);
    if (d2 > rr) return 0;
    if (s->d.dot(c->d) > EPS1) {
        float dA = planeA + c->d.dot(s->p);
        if (dA < EPS2) {
            out->dist = -(dA / c->d.dot(s->d));
            if (out->dist > EPS3 && out->dist < s->len) {
                out->pos = s->d * out->dist + s->p;
                if ((out->pos - c->p).lenSq() < rr) { out->n = -c->d; return 1; }
            }
        }
    } else {
        float dB = planeB + c->d.dot(s->p);
        if (dB > EPS4) {
            out->dist = -(dB / c->d.dot(s->d));
            if (out->dist > EPS5 && out->dist < s->len) {
                out->pos = s->d * out->dist + s->p;
                if ((out->pos - f).lenSq() < rr) { out->n = c->d; return 1; }
            }
        }
    }
    float h = sqrtOrZero(rr - d2);
    float uh = u - h;
    out->dist = uh * s->len / L;
    if (out->dist > EPS6 && out->dist < s->len) {
        out->pos = s->p + s->d * out->dist;
        float v = (out->pos - c->p).dot(c->d);
        if (v < EPS7 || v > c->len) return 0;
        out->n = (pa + dir * uh - c->p).normalize();
        return 1;
    }
    return 0;
}
#undef EPS0
#undef EPS1
#undef EPS2
#undef EPS3
#undef EPS4
#undef EPS5
#undef EPS6
#undef EPS7
}
namespace w3_2_A38C {
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator+(const Vec3& o) const { float rz = z + o.z; float ry = y + o.y; float rx = x + o.x; return Vec3(rx, ry, rz); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
    float distSq(const Vec3& o) const { float d[3]; d[0] = x; d[1] = y; d[2] = z; d[2] -= o.z; d[1] -= o.y; d[0] -= o.x; float a = d[0]; return a * a + d[1] * d[1] + d[2] * d[2]; }
    float lenSq() const { float a = x * x; float b = y * y; float c = z * z; return a + b + c; }
};
struct Sphere { Vec3 c; float r; };
struct Capsule { Vec3 p; float len; Vec3 d; float r; };
extern "C" signed char fn_801BA38C(const Capsule* r, const Sphere* s) {
    float rr = s->r * s->r;
    float t = (s->c - r->p).dot(r->d);
    if ((r->d * t + r->p).distSq(s->c) > rr) return 0;
    if (t < lbl_8037A264) return (r->p - s->c).lenSq() < rr;
    if (t > r->len) return (r->p + r->d * r->len - s->c).lenSq() < rr;
    return 1;
}
}
