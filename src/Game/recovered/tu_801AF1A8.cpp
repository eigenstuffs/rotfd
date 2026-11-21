/* Merged translation unit for .text 0x801AF1A8-0x801B12DC, .sdata2 0x8037A1E0-0x8037A210
 * (curve sampling; bias group lbl_8037A1F8). All float constants are pooled literals. */
/* NOTE: the `struct FlushN;` forward declarations after each function are load-bearing:
 * mwcc defers functions that use inline/template members and emits a deferred batch in
 * REVERSE order at the next type declaration; flushing after every function keeps the
 * address order and the .sdata2 literal first-use order. */
/* ---- shared declarations (former pending/curve_common.h) ---- */
#define K60 (1.0f / 60.0f)
extern "C" {
void fn_801F7914(void*, const void*);
}
struct PVec2 {
    float x, y;
    PVec2() {}
    PVec2(float x_, float y_) : x(x_), y(y_) {}
    PVec2(const PVec2& o) : x(o.x), y(o.y) {}
    PVec2& operator=(const PVec2& o) { x = o.x; y = o.y; return *this; }
    PVec2 operator-(const PVec2& b) const { return PVec2(x - b.x, y - b.y); }
    PVec2 operator+(const PVec2& b) const { return PVec2(x + b.x, y + b.y); }
    PVec2 operator*(float s) const { return PVec2(x * s, y * s); }
};
extern "C" const PVec2 game_vec2_zero;
struct PVec3 {
    float x, y, z;
    PVec3() {}
    PVec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
    PVec3(const PVec3& o) : x(o.x), y(o.y), z(o.z) {}
    PVec3& operator=(const PVec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    PVec3 operator-(const PVec3& b) const { return PVec3(x - b.x, y - b.y, z - b.z); }
    PVec3 operator+(const PVec3& b) const { return PVec3(x + b.x, y + b.y, z + b.z); }
    PVec3 operator*(float s) const { return PVec3(x * s, y * s, z * s); }
    PVec3 operator-() const { return PVec3(-x, -y, -z); }
    void set(float x_, float y_, float z_) { x = x_; y = y_; z = z_; }
};
struct PQuat { float w; PVec3 v; };
struct Vec3Key { short time; PVec3 value; float getTime() const { return K60 * (float)time; } };
struct Vec3HermiteKey { short time; PVec3 value; PVec3 tanIn; PVec3 tanOut; };
struct QComp { signed short value : 12; unsigned short unused : 4; };
struct QuatKey {
    short time;
    QComp x, y, z, w;
    float angle;
    float invSin;
    float getInvSin() const { return invSin; }
    float getTime() const { return K60 * (float)time; }
    void get(PQuat* out) const {
        out->v.x = 0.0005f * (float)x.value;
        out->v.y = 0.0005f * (float)y.value;
        out->v.z = 0.0005f * (float)z.value;
        out->w = 0.0005f * (float)w.value;
    }
};
extern "C" float fn_80284DD8(float);
extern "C" float fn_80284FA8(float);
struct FloatKey { short time; float value; };
struct Vec2Key { short time; PVec2 value; float getTime() const { return K60 * (float)time; } };
struct HermiteKey { short time; float value; float tanIn; float tanOut; };
/* Generic helpers: arguments are passed BY VALUE (copy-constructed); this is
 * what reproduces the original float register allocation. */
inline float unlerp(float t0, float t1, float t) { return (t - t0) / (t1 - t0); }
template <class V> inline void curveLerp(V& o, V a, V b, float u) { o = a + (b - a) * u; }
extern "C" PVec3 fn_801AFFBC(const PVec3& v, float s);
/* Packed (s16 fixed-point) Vec3 hermite key, 0x14 bytes.
 * The 0.001f scale must be a literal (lbl_8037A20C): the per-component
 * constant loads that exist before scheduling are what make fn_801AFFE4
 * schedule/allocate like the original. */
struct PackedVec3 {
    short x, y, z;
    void get(PVec3* out) const {
        out->x = 0.001f * (float)x;
        out->y = 0.001f * (float)y;
        out->z = 0.001f * (float)z;
    }
    operator PVec3() const { return PVec3(0.001f * (float)x, 0.001f * (float)y, 0.001f * (float)z); }
};
struct PackedVec3HermiteKey { short time; PackedVec3 value; PackedVec3 tanIn; PackedVec3 tanOut; };
#define KTIME(k) (K60 * (float)(k).time)
/* Literals: the original reloads these at each use (no CSE), which only
 * happens for literal constants. They correspond to lbl_8037A200 (1/60),
 * lbl_8037A1E4 (1), lbl_8037A204 (2), lbl_8037A208 (3), lbl_8037A1EC (0). */
template <class T> struct PArray {
    int count;
    int capacity;
    T* data;
    T& operator[](int i) { return data[i]; }
};
template <class T> struct PCurve {
    unsigned short mode;
    PArray<T> keys;
    int find(int i, float t) {
        for (; i < keys.count; i++) {
            if (K60 * (float)keys[i - 1].time <= t &&
                K60 * (float)keys[i].time > t)
                break;
        }
        return i;
    }
};

/* ---- part_801AF1A8 ---- */

#define QF(c) (0.0005f * (float)(c).value)

extern "C" void fn_801AF1A8(PCurve<QuatKey>* curve) {
    for (int i = 0; i < curve->keys.count - 1; i++) {
        QuatKey& a = curve->keys[i];
        QuatKey& b = curve->keys[i + 1];
        float dot = QF(a.x) * QF(b.x) + QF(a.y) * QF(b.y) + QF(a.z) * QF(b.z) + QF(a.w) * QF(b.w);
        if (dot >= 1.0f)
            dot = 1.0f;
        else if (dot <= -1.0f)
            dot = -1.0f;
        a.angle = 0.0f;
        if (dot < 0.000001f) {
            float ang = fn_80284DD8(-dot);
            if (ang) {
                curve->keys[i].angle = 6.2831855f + ang;
                float inv = 1.0f / fn_80284FA8(ang);
                curve->keys[i].invSin = inv;
            }
        } else {
            float ang = fn_80284DD8(dot);
            if (ang) {
                curve->keys[i].angle = ang;
                float inv = 1.0f / fn_80284FA8(ang);
                curve->keys[i].invSin = inv;
            }
        }
    }
}
struct Flush1;

extern "C" int fn_801AF484(PCurve<QuatKey>* curve, PQuat* out, int i, float t) {
    for (; i < curve->keys.count; i++) {
        if (K60 * (float)curve->keys[i - 1].time <= t && K60 * (float)curve->keys[i].time > t)
            break;
    }
    if (i == curve->keys.count) {
        curve->keys[curve->keys.count - 1].get(out);
    } else {
        QuatKey& a = curve->keys[i - 1];
        float angle = a.angle;
        if (a.angle) {
            float s0;
            float inv;
            PQuat qa, qb;
            a.get(&qa);
            curve->keys[i].get(&qb);
            if (a.angle > 6.2831855f) {
                angle = a.angle - 6.2831855f;
                qb.v.x = -qb.v.x;
                qb.v.y = -qb.v.y;
                qb.v.z = -qb.v.z;
                qb.w = -qb.w;
            }
            float t0 = KTIME(a);
            float t1 = KTIME(curve->keys[i]);
            inv = a.getInvSin();
            float u = (t - t0) / (t1 - t0);
            s0 = fn_80284FA8((1.0f - u) * angle);
            float s1 = fn_80284FA8(u * angle);
            out->v = (qa.v * s0 + qb.v * s1) * inv;
            out->w = inv * (qa.w * s0 + qb.w * s1);
        } else {
            a.get(out);
        }
    }
    return i;
}
struct Flush2;

extern "C" int fn_801AFA0C(PCurve<Vec3Key>* curve, PVec3* out, int i, float t) {
    i = curve->find(i, t);
    if (i == curve->keys.count) {
        Vec3Key& k = curve->keys[curve->keys.count - 1];
        *out = k.value;
    } else if (curve->mode == 3) {
        Vec3Key& k = curve->keys[i - 1];
        *out = k.value;
    } else {
        Vec3Key& a = curve->keys[i - 1];
        Vec3Key& b = curve->keys[i];
        curveLerp(*out, a.value, b.value, unlerp(a.getTime(), b.getTime(), t));
    }
    return i;
}
struct Flush3;

extern "C" int fn_801AFBD0(PCurve<Vec3HermiteKey>* curve, PVec3* out, int i, float t) {
    int n = curve->keys.count;
    if (n == i) {
        Vec3HermiteKey& k = curve->keys[n - 1];
        *out = k.value;
    } else {
        float t0 = KTIME(curve->keys[i - 1]);
        float t1;
        for (; i < n; i++) {
            float tk = KTIME(curve->keys[i]);
            t1 = tk;
            if (t0 <= t && tk > t)
                break;
            t0 = tk;
        }
        if (n == i) {
            Vec3HermiteKey& k = curve->keys[n - 1];
            *out = k.value;
        } else if (curve->mode == 3) {
            Vec3HermiteKey& k = curve->keys[i - 1];
            *out = k.value;
        } else {
            Vec3HermiteKey& a = curve->keys[i - 1];
            Vec3HermiteKey& b = curve->keys[i];
            float u = (t - t0) / (t1 - t0);
            PVec3 p0 = a.value;
            PVec3 m0 = a.tanOut;
            PVec3 p1 = b.value;
            PVec3 m1 = b.tanIn;
            PVec3 ca = p0 * 2.0f - p1 * 2.0f + m0 + m1;
            PVec3 cb = -p0 * 3.0f + p1 * 3.0f - m0 * 2.0f - m1;
            PVec3 r = fn_801AFFBC(ca, u);
            r.set(cb.x + r.x, cb.y + r.y, cb.z + r.z);
            r.set(r.x * u, r.y * u, r.z * u);
            r.set(m0.x + r.x, m0.y + r.y, m0.z + r.z);
            r.set(r.x * u, r.y * u, r.z * u);
            r.set(p0.x + r.x, p0.y + r.y, p0.z + r.z);
            *out = r;
        }
    }
    return i;
}
struct Flush4;

/* ---- Game/scalar_middle_801AFFBC.c ---- */
/* Out of line by construction: the callers see only the struct-return C++ view
 * declared above; this definition is the raw float view in its own namespace. */
namespace scalar_middle_801AFFBC {
static inline void set3(float* out, float x, float y, float z) { out[0] = x; out[1] = y; out[2] = z; }
extern "C" void fn_801AFFBC(float* out, const float* source, float scale) {
    set3(out, source[0] * scale, source[1] * scale, source[2] * scale);
}
}

/* ---- part_801AFFE4 ---- */

extern "C" int fn_801AFFE4(PCurve<PackedVec3HermiteKey>* curve, PVec3* out, int i, float t) {
    int n = curve->keys.count;
    if (n == i) {
        PackedVec3HermiteKey& k = curve->keys[n - 1];
        k.value.get(out);
    } else {
        float t0 = KTIME(curve->keys[i - 1]);
        float t1;
        for (; i < n; i++) {
            float tk = KTIME(curve->keys[i]);
            t1 = tk;
            if (t0 <= t && tk > t)
                break;
            t0 = tk;
        }
        if (n == i) {
            PackedVec3HermiteKey& k = curve->keys[n - 1];
            k.value.get(out);
        } else if (curve->mode == 3) {
            PackedVec3HermiteKey& k = curve->keys[i - 1];
            k.value.get(out);
        } else {
            PackedVec3HermiteKey& a = curve->keys[i - 1];
            PackedVec3HermiteKey& b = curve->keys[i];
            PVec3 p0 = a.value;
            PVec3 m0 = a.tanOut;
            PVec3 p1 = b.value;
            PVec3 m1 = b.tanIn;
            float u = (t - t0) / (t1 - t0);
            PVec3 ca = p0 * 2.0f - p1 * 2.0f + m0 + m1;
            PVec3 cb = -p0 * 3.0f + p1 * 3.0f - m0 * 2.0f - m1;
            PVec3 r = fn_801AFFBC(ca, u);
            r.set(cb.x + r.x, cb.y + r.y, cb.z + r.z);
            r.set(r.x * u, r.y * u, r.z * u);
            r.set(m0.x + r.x, m0.y + r.y, m0.z + r.z);
            r.set(r.x * u, r.y * u, r.z * u);
            r.set(p0.x + r.x, p0.y + r.y, p0.z + r.z);
            *out = r;
        }
    }
    return i;
}
struct Flush5;

extern "C" void fn_801B0620(PCurve<Vec2Key>* curve, PVec2* out, float t) {
    if (curve->mode == 3) {
        *out = game_vec2_zero;
        return;
    }
    int i;
    for (i = 1; i < curve->keys.count; i++) {
        if (KTIME(curve->keys[i - 1]) <= t && KTIME(curve->keys[i]) > t)
            break;
    }
    if (i == curve->keys.count) {
        Vec2Key& k = curve->keys[curve->keys.count - 1];
        *out = k.value;
        return;
    }
    Vec2Key* data = curve->keys.data;
    Vec2Key& a = data[i - 1];
    Vec2Key& b = data[i];
    float t0 = a.getTime();
    float t1 = b.getTime();
    PVec2 va = a.value, vb = b.value;
    *out = (vb - va) * (1.0f / (t1 - t0));
}
struct Flush6;

extern "C" int fn_801B07A4(PCurve<Vec2Key>* curve, PVec2* out, int i, float t) {
    i = curve->find(i, t);
    if (i == curve->keys.count) {
        Vec2Key& k = curve->keys[curve->keys.count - 1];
        *out = k.value;
    } else if (curve->mode == 3) {
        Vec2Key& k = curve->keys[i - 1];
        *out = k.value;
    } else {
        Vec2Key* data = curve->keys.data;
        Vec2Key& a = data[i - 1];
        Vec2Key& b = data[i];
        curveLerp(*out, a.value, b.value, unlerp(a.getTime(), b.getTime(), t));
    }
    return i;
}
struct Flush7;

extern "C" int fn_801B093C(PCurve<FloatKey>* curve, float* out, int i, float t) {
    i = curve->find(i, t);
    if (i == curve->keys.count) {
        *out = curve->keys[curve->keys.count - 1].value;
    } else if (curve->mode == 3) {
        *out = curve->keys[i - 1].value;
    } else {
        FloatKey& a = curve->keys[i - 1];
        FloatKey& b = curve->keys[i];
        float t0 = KTIME(a);
        float t1 = KTIME(b);
        *out = (b.value - a.value) * ((t - t0) / (t1 - t0)) + a.value;
    }
    return i;
}
struct Flush8;

extern "C" int fn_801B0AA0(PCurve<HermiteKey>* curve, float* out, int i, float t) {
    i = curve->find(i, t);
    if (i == curve->keys.count) {
        *out = curve->keys[curve->keys.count - 1].value;
    } else if (curve->mode == 3) {
        *out = curve->keys[i - 1].value;
    } else {
        HermiteKey& a = curve->keys[i - 1];
        HermiteKey& b = curve->keys[i];
        float p0 = a.value;
        float m0 = a.tanOut;
        float p1 = b.value;
        float m1 = b.tanIn;
        float t0 = KTIME(a);
        float t1 = KTIME(b);
        float u = (t - t0) / (t1 - t0);
        float ca = 2.0f * p0 - 2.0f * p1 + m0 + m1;
        float cb = 3.0f * -p0 + 3.0f * p1 - 2.0f * m0 - m1;
        *out = u * (u * (u * ca + cb) + m0) + p0;
    }
    return i;
}
struct Flush9;

extern "C" int fn_801B0C3C(PCurve<HermiteKey>* curve, float* out, bool* rising, int i, float t) {
    float d;
    i = curve->find(i, t);
    if (i == curve->keys.count) {
        *out = curve->keys[curve->keys.count - 1].value;
        d = curve->keys[curve->keys.count - 1].tanIn;
    } else if (curve->mode == 3) {
        *out = curve->keys[i - 1].value;
        return i;
    } else {
        HermiteKey& a = curve->keys[i - 1];
        HermiteKey& b = curve->keys[i];
        float p0 = a.value;
        float m0 = a.tanOut;
        float p1 = b.value;
        float m1 = b.tanIn;
        float ca = 2.0f * p0 - 2.0f * p1 + m0 + m1;
        float cb = 3.0f * -p0 + 3.0f * p1 - 2.0f * m0 - m1;
        float t0 = KTIME(a);
        float t1 = KTIME(b);
        float u = (t - t0) / (t1 - t0);
        *out = u * (u * (u * ca + cb) + m0) + p0;
        d = u * (3.0f * u * ca + 2.0f * cb) + m0;
    }
    if (d >= 0.0f)
        *rising = true;
    else
        *rising = false;
    return i;
}
struct Flush10;

/* ---- Game/curve_handle_actions_801B0E28.cpp ---- */
namespace curve_handle_actions_801B0E28 {
/* Curve Handle action and packed encoding reconstruction; see docs/notes/game-curve-handle-encoding.md. */
typedef unsigned long CurveActionWord;

struct CurveActionNodeStorage {
    CurveActionWord unknown00[2];
};

struct CurveActionNode : CurveActionNodeStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
};

struct CurveActionHandle {
    CurveActionWord value;
};

struct CurveActionKey {
    short time;
    short unknown02;
    CurveActionHandle handle;
};

struct CurveActionTrack {
    short type;
    short unknown02;
    int count;
    int capacity;
    CurveActionKey* keys;
};

extern "C" CurveActionNode* fn_801F7EB8(const CurveActionHandle*);

extern "C" void fn_801B0E28(CurveActionTrack* self) {
    for (int i = 0; i < self->count; ++i) {
        if (fn_801F7EB8(&self->keys[i].handle)) {
            fn_801F7EB8(&self->keys[i].handle)->slot1C();
        }
    }
}
struct Flush11;

}
struct Flush12;

/* ---- part_801B0EB8 ---- */
struct HandleKey8 { short time; short pad; unsigned int value; };

extern "C" int fn_801B0EB8(PCurve<HandleKey8>* curve, void* out, int i, float t) {
    for (; i < curve->keys.count; i++) {
        if (K60 * (float)curve->keys[i - 1].time <= t &&
            K60 * (float)curve->keys[i].time > t)
            break;
    }
    fn_801F7914(out, &curve->keys[i - 1].value);
    return i;
}
struct Flush13;

extern "C" int fn_801B0F8C(PCurve<HandleKey8>* curve, unsigned int* out, int i, float t) {
    for (; i < curve->keys.count; i++) {
        if (K60 * (float)curve->keys[i - 1].time <= t &&
            K60 * (float)curve->keys[i].time > t)
            break;
    }
    *out = curve->keys[i - 1].value;
    return i;
}
struct Flush14;

/* ---- Game/curve_base.c ---- */
extern "C" {
/* Minimal base operations shared by the reconstructed curve arrays. */
extern struct { char reserved[16]; } lbl_801EF5C8;
extern void fn_801EF610(void *,void *);
void *__dt__18CurveBase_801B1088Fv(void *object,short delete_flag)
{
    if (object && delete_flag>0)
        fn_801EF610(&lbl_801EF5C8,object);
    return object;
}
void __ct__18CurveBase_801B1088Fv(unsigned short *object)
{
    *object=1;
}
struct Flush15;

}
struct Flush16;

/* ---- part_801B1094 ---- */
extern "C" void fn_801B1094(const QuatKey* self, PQuat* out) {
    out->v.x = 0.0005f * (float)self->x.value;
    out->v.y = 0.0005f * (float)self->y.value;
    out->v.z = 0.0005f * (float)self->z.value;
    out->w = 0.0005f * (float)self->w.value;
}
struct Flush17;

/* ---- Game/curve_packed_quaternion_encode_801B115C.cpp ---- */
namespace curve_packed_quaternion_encode_801B115C {
/* Curve Handle action and packed encoding reconstruction; see docs/notes/game-curve-handle-encoding.md. */
struct CurvePackedQuaternionComponent {
    signed short value : 12;
    unsigned short unused : 4;
};

struct CurvePackedQuaternionKey {
    short time;
    CurvePackedQuaternionComponent x;
    CurvePackedQuaternionComponent y;
    CurvePackedQuaternionComponent z;
    CurvePackedQuaternionComponent w;
};

struct CurvePackedQuaternionInput {
    float w;
    float x;
    float y;
    float z;
};

extern "C" const float lbl_8037A210;

extern "C" void fn_801B115C(CurvePackedQuaternionKey* self,
                              const CurvePackedQuaternionInput* value) {
    self->x.value = lbl_8037A210 * value->x;
    self->y.value = lbl_8037A210 * value->y;
    self->z.value = lbl_8037A210 * value->z;
    self->w.value = lbl_8037A210 * value->w;
}
struct Flush18;

}
struct Flush19;

/* ---- Game/packed_vector_convert_801B11EC.c ---- */
namespace packed_vector_convert_801B11EC {
extern "C" {
/* Decode three signed 16-bit vector components with the original scale. */

void fn_801B11EC(const unsigned char* input, float* output)
{
    const short* packed = (const short*)(input + 8);
    output[0] = (float)packed[0] * 0.001f;
    output[1] = (float)packed[1] * 0.001f;
    output[2] = (float)packed[2] * 0.001f;
}
struct Flush20;

void fn_801B1264(const unsigned char* input, float* output)
{
    const short* packed = (const short*)(input + 2);
    output[0] = (float)packed[0] * 0.001f;
    output[1] = (float)packed[1] * 0.001f;
    output[2] = (float)packed[2] * 0.001f;
}
struct Flush21;

}
struct Flush22;

}
struct Flush23;

