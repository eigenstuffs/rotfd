// Partial text split: fn_801BBB74 only. fn_801BBDC8 after it (94.8%) remains
// original code; full draft: scratch/claude_match/auto_03_801BBB74_text/final.cpp.
typedef unsigned int u32;

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float reciprocalSqrt(register float value)
{
    register float result;
    asm { frsqrte result, value }
    return result;
}

extern "C" {
    extern const float lbl_8037A2A0;
    extern const float lbl_8037A2A4;
    extern const float lbl_8037A2A8;
    extern const float lbl_8037A2AC;
    extern const float lbl_8037A2B0;
    extern const float lbl_8037A2B4;
    extern const float lbl_8037A2B8;
    extern const float lbl_8037A2BC;
    extern const float lbl_8037A2C0;
    extern const float lbl_8037A2C4;
    extern const float lbl_8037A2C8;
    extern const float lbl_8037A2CC;
    double acos(double);
    double cos(double);
    double sin(double);
}

inline float safeSqrt_801BBB74(float sq)
{
    float r = lbl_8037A2A4;
    if (sq != r) r = fastSqrt(sq);
    return r;
}

struct Vec3_801BBB74 {
    float x, y, z;
    Vec3_801BBB74() {}
    Vec3_801BBB74(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3_801BBB74 operator*(float s) const { return Vec3_801BBB74(x * s, y * s, z * s); }
    Vec3_801BBB74 operator/(float d) const { float inv = lbl_8037A2A0 / d; return Vec3_801BBB74(x * inv, y * inv, z * inv); }
    void operator*=(float s) { x *= s; y *= s; z *= s; }
    void operator+=(const Vec3_801BBB74& v) { x += v.x; y += v.y; z += v.z; }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = *(const float*)&lbl_8037A2A4;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

inline Vec3_801BBB74 operator+(const Vec3_801BBB74& a, const Vec3_801BBB74& b) { return Vec3_801BBB74(a.x + b.x, a.y + b.y, a.z + b.z); }
inline Vec3_801BBB74 operator-(const Vec3_801BBB74& a, const Vec3_801BBB74& b) { return Vec3_801BBB74(a.x - b.x, a.y - b.y, a.z - b.z); }
inline Vec3_801BBB74 operator-(const Vec3_801BBB74& v) { Vec3_801BBB74 r; r.x = -v.x; r.y = -v.y; r.z = -v.z; return r; }

struct Quat_801BBB74;
extern "C" {
    void fn_801F1BB0(Quat_801BBB74*, const Quat_801BBB74*);
    Vec3_801BBB74 fn_801F1B1C(const Quat_801BBB74& q, const Vec3_801BBB74& v);
}
struct Quat_801BBB74 {
    float w, x, y, z;
    void operator*=(const Quat_801BBB74& q) { fn_801F1BB0(this, &q); }
    Quat_801BBB74() {}
    Quat_801BBB74(const Quat_801BBB74& q) { w = q.w; x = q.x; y = q.y; z = q.z; }
    void operator=(const Quat_801BBB74& q) { w = q.w; x = q.x; y = q.y; z = q.z; }
};

struct Matrix_801BBB74 {
    float a[16];
    Vec3_801BBB74 getPos() const { return Vec3_801BBB74(a[12], a[13], a[14]); }
    Vec3_801BBB74 rotate(const Vec3_801BBB74& v) const
    {
        Vec3_801BBB74 r;
        r.x = a[0] * v.x + a[4] * v.y + a[8] * v.z;
        r.y = a[1] * v.x + a[5] * v.y + a[9] * v.z;
        r.z = a[2] * v.x + a[6] * v.y + a[10] * v.z;
        return r;
    }
};

struct MatrixCache_801BBB74 {
    Matrix_801BBB74* arrays[6];
    unsigned char active;
};

struct Globals_801BBB74 {
    char unknown[0x134];
    MatrixCache_801BBB74* cache;
};

extern "C" Globals_801BBB74 lbl_801E9D24;

extern "C" {
    void fn_801F230C(const Matrix_801BBB74*, Matrix_801BBB74*);
}

struct Object_801BBB74 {
    char unknown[0xC8];
    Quat_801BBB74 rotation;
    char unknownD8[0x120 - 0xD8];
    u32 flags;
    Matrix_801BBB74 *matrix, *cached;
    char unknown12C[2];
    short index;
    Matrix_801BBB74* getMatrix()
    {
        if (flags & 0x20) {
            cached = lbl_801E9D24.cache->arrays[lbl_801E9D24.cache->active] + index;
            fn_801F230C(matrix, cached);
            flags &= ~0x20;
        }
        return cached;
    }
};

struct Item_801BBB74 {
    Object_801BBB74* object;
    Quat_801BBB74 quat;
    Vec3_801BBB74 prev;
    Vec3_801BBB74 vel;
    Quat_801BBB74 rest;
    char unknown3C[0x7C - 0x3C];
    float angVelX, angVelY;
    float spring;
    float accelGain;
    float gainZ, gainX;
};

struct Record_801BBB74 {
    Vec3_801BBB74 point;
    float radius;
    float weight, extra;
};

struct Cone_801BBB74 {
    Vec3_801BBB74 point;
    Vec3_801BBB74 dir;
    float weight;
    float maxDot;
    float minDot;
    float inner;
    float outer;
};

template<class T, int N> struct FixedArray_801BBB74 {
    T data[N];
    int count;
    T& at(const unsigned int& i) { return data[i]; }
};

struct Owner_801BBB74 {
    char unknown[0x20];
    float mass;
    char items[16 * sizeof(Item_801BBB74)];
    char unknown964[4];
    int itemCount;
    FixedArray_801BBB74<Record_801BBB74, 8> records;
    FixedArray_801BBB74<Cone_801BBB74, 8> cones;
};

extern "C" const Vec3_801BBB74 game_vec3_zero;

extern "C" Vec3_801BBB74 fn_801BBB74(Owner_801BBB74* self, Vec3_801BBB74 pos);

/* fn_801BBDC8 (record push integration) remains original code. */

#pragma opt_common_subs off
extern "C" Vec3_801BBB74 fn_801BBB74(Owner_801BBB74* self, Vec3_801BBB74 pos)
{
    Vec3_801BBB74 sum = game_vec3_zero;
    for (int i = 0; i < self->cones.count; i++) {
        Cone_801BBB74& c = self->cones.at(i);
        Vec3_801BBB74 d = c.point - pos;
        float dist = d.length();
        if (dist > *(const float*)&lbl_8037A2A8) {
        float inner = c.inner, outer = c.outer;
        if (dist < inner + outer) {
            Vec3_801BBB74 n = d;
            n *= *(const float*)&lbl_8037A2A0 / dist;
            float dot = n.x * c.dir.x + n.y * c.dir.y + n.z * c.dir.z;
            float minDot = c.minDot;
            if (dot > minDot) {
                float scale = *(const float*)&lbl_8037A2A0;
                if (dist > inner) scale = (dist - inner) / (outer - inner);
                if (dot < c.maxDot) scale *= (dot - minDot) / (c.maxDot - minDot);
                sum += n * (scale * c.weight);
            }
        }
        }
    }
    for (int i = 0; i < self->records.count; i++) {
        Record_801BBB74& r = self->records.at(i);
        Vec3_801BBB74 d = pos - r.point;
        float dist = d.length();
        if (dist > *(const float*)(unsigned long)&lbl_8037A2A8) {
        float radius = r.radius, extra = r.extra;
        if (dist < radius + extra) {
            float inv = *(const float*)&lbl_8037A2A0 / dist;
            Vec3_801BBB74 n = d;
            n *= inv;
            if (dist < radius) {
                sum += n * r.weight;
            } else {
                float t = (dist - radius) / (extra - radius);
                sum += n * (t * r.weight);
            }
        }
        }
    }
    return sum;
}
#pragma opt_common_subs reset


