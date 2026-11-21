// auto_03_801BAAD4_text: sibling of owner_cone_record_push_801BBB74.cpp for a second owner class.
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
    extern const float lbl_8037A278; /* 1.0f */
    extern const float lbl_8037A27C; /* 0.0f */
    extern const float lbl_8037A290; /* 1.0e-6f */
    extern const float lbl_8037A27C;
    extern const float lbl_8037A290;
    double acos(double);
    double cos(double);
    double sin(double);
}

inline float safeSqrt_801BAAD4(float sq)
{
    float r = lbl_8037A27C;
    if (sq != r) r = fastSqrt(sq);
    return r;
}

struct Vec3_801BAAD4 {
    float x, y, z;
    Vec3_801BAAD4() {}
    Vec3_801BAAD4(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3_801BAAD4 operator*(float s) const { return Vec3_801BAAD4(x * s, y * s, z * s); }
    Vec3_801BAAD4 operator/(float d) const { float inv = lbl_8037A278 / d; return Vec3_801BAAD4(x * inv, y * inv, z * inv); }
    void operator*=(float s) { x *= s; y *= s; z *= s; }
    void operator+=(const Vec3_801BAAD4& v) { x += v.x; y += v.y; z += v.z; }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = *(const float*)&lbl_8037A27C;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

inline Vec3_801BAAD4 operator+(const Vec3_801BAAD4& a, const Vec3_801BAAD4& b) { return Vec3_801BAAD4(a.x + b.x, a.y + b.y, a.z + b.z); }
inline Vec3_801BAAD4 operator-(const Vec3_801BAAD4& a, const Vec3_801BAAD4& b) { return Vec3_801BAAD4(a.x - b.x, a.y - b.y, a.z - b.z); }
inline Vec3_801BAAD4 operator-(const Vec3_801BAAD4& v) { Vec3_801BAAD4 r; r.x = -v.x; r.y = -v.y; r.z = -v.z; return r; }

struct Quat_801BAAD4;
extern "C" {
    void fn_801F1BB0(Quat_801BAAD4*, const Quat_801BAAD4*);
    Vec3_801BAAD4 fn_801F1B1C(const Quat_801BAAD4& q, const Vec3_801BAAD4& v);
}
struct Quat_801BAAD4 {
    float w, x, y, z;
    void operator*=(const Quat_801BAAD4& q) { fn_801F1BB0(this, &q); }
    Quat_801BAAD4() {}
    Quat_801BAAD4(const Quat_801BAAD4& q) { w = q.w; x = q.x; y = q.y; z = q.z; }
    void operator=(const Quat_801BAAD4& q) { w = q.w; x = q.x; y = q.y; z = q.z; }
};

struct Matrix_801BAAD4 {
    float a[16];
    Vec3_801BAAD4 getPos() const { return Vec3_801BAAD4(a[12], a[13], a[14]); }
    Vec3_801BAAD4 rotate(const Vec3_801BAAD4& v) const
    {
        Vec3_801BAAD4 r;
        r.x = a[0] * v.x + a[4] * v.y + a[8] * v.z;
        r.y = a[1] * v.x + a[5] * v.y + a[9] * v.z;
        r.z = a[2] * v.x + a[6] * v.y + a[10] * v.z;
        return r;
    }
};

struct MatrixCache_801BAAD4 {
    Matrix_801BAAD4* arrays[6];
    unsigned char active;
};

struct Globals_801BAAD4 {
    char unknown[0x134];
    MatrixCache_801BAAD4* cache;
};

extern "C" Globals_801BAAD4 lbl_801E9D24;

extern "C" {
    void fn_801F230C(const Matrix_801BAAD4*, Matrix_801BAAD4*);
}

struct Object_801BAAD4 {
    char unknown[0xC8];
    Quat_801BAAD4 rotation;
    char unknownD8[0x120 - 0xD8];
    u32 flags;
    Matrix_801BAAD4 *matrix, *cached;
    char unknown12C[2];
    short index;
    Matrix_801BAAD4* getMatrix()
    {
        if (flags & 0x20) {
            cached = lbl_801E9D24.cache->arrays[lbl_801E9D24.cache->active] + index;
            fn_801F230C(matrix, cached);
            flags &= ~0x20;
        }
        return cached;
    }
};

struct Item_801BAAD4 {
    Object_801BAAD4* object;
    Quat_801BAAD4 quat;
    Vec3_801BAAD4 prev;
    Vec3_801BAAD4 vel;
    Quat_801BAAD4 rest;
    char unknown3C[0x7C - 0x3C];
    float angVelX, angVelY;
    float spring;
    float accelGain;
    float gainZ, gainX;
};

extern "C" const Vec3_801BAAD4 game_vec3_zero;


inline void* operator new(unsigned long, void* p) { return p; }

struct HEntry_801BAAD4 {
    void* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};
struct HManager_801BAAD4 {
    int count, capacity;
    HEntry_801BAAD4* entries;
};
struct Handle_801BAAD4 {
    signed char tag;
    signed int index : 24;
};
struct Skel_801BAAD4 {
    int bones[28];
    int& operator[](unsigned int i) { return bones[i]; }
};
struct World_801BAAD4 {
    char unknown[0x94];
    Skel_801BAAD4* skel;
};
struct Ctx_801BAAD4 {
    char unknown00[0x118];
    HManager_801BAAD4* manager;
    char unknown11C[0x144 - 0x11C];
    World_801BAAD4* world;
};
#define CTX (*(Ctx_801BAAD4*)&lbl_801E9D24)

inline void* resolve2_801BAAD4(HManager_801BAAD4* m, const Handle_801BAAD4& h)
{
    HEntry_801BAAD4* e = &m->entries[h.index];
    if (e->tag == h.tag) return e->object;
    return 0;
}
inline void* resolve_801BAAD4(const Handle_801BAAD4& h)
{
    HEntry_801BAAD4* e = &CTX.manager->entries[h.index];
    if (e->tag == h.tag) return e->object;
    return 0;
}

struct Node_801BAAD4 {
    char unknown[0xC];
    Handle_801BAAD4 parent;
    char unknown10[0xB8 - 0x10];
    Vec3_801BAAD4 pos;
    char unknownC4[4];
    Quat_801BAAD4 rot;
};

struct Link_801BAAD4 {
    Node_801BAAD4* node;
    Vec3_801BAAD4 a;
    Vec3_801BAAD4 pos;
    char unknown1C[0x34 - 0x1C];
    Quat_801BAAD4 rot;
    char unknown44[0x50 - 0x44];
    int next;
    float ratio;
    float f58;
    char unknown5C[0x68 - 0x5C];
    Link_801BAAD4() { next = -1; a = game_vec3_zero; }
    ~Link_801BAAD4() {}
};

struct Int_801BAAD4 {
    int v;
    Int_801BAAD4() {}
    Int_801BAAD4(int x) : v(x) {}
};

template<class T, int N> struct FixedArray2_801BAAD4 {
    char storage[N * sizeof(T)];
    int count;
    T& operator[](unsigned int i) { return ((T*)storage)[i]; }
    int add()
    {
        if (count >= N) {
            new ((T*)(storage + (N - 1) * sizeof(T))) T;
            return N - 1;
        }
        new (&(*this)[count++]) T;
        return count - 1;
    }
    void push(const T& v)
    {
        if (count >= N) {
            new ((T*)(storage + (N - 1) * sizeof(T))) T(v);
            return;
        }
        new (&(*this)[count++]) T(v);
    }
    void resize(int n)
    {
        if (n > count) {
            for (int i = count; i < n; ++i) new (&(*this)[i]) T;
        } else if (n < count) {
            for (int i = count - 1; i >= n; --i) (*this)[i].~T();
        }
        count = n;
    }
    void clear() { resize(0); }
};

struct Bones_801BAAD4 {
    char unknown[0x28];
    Handle_801BAAD4* handles;
};

struct Chain_801BAAD4 {
    char unknown[0x20];
    signed char ready;
    char unknown21[3];
    FixedArray2_801BAAD4<Link_801BAAD4, 16> links;
    FixedArray2_801BAAD4<Int_801BAAD4, 16> roots;
};

extern "C" const float lbl_8037A280;

#pragma opt_common_subs off
extern "C" void fn_801BAAD4(Chain_801BAAD4* self, Bones_801BAAD4* bones)
{
    self->links.clear();
    self->roots.clear();
    if (bones) {
        Node_801BAAD4* node;
        int i;
        for (i = 0; i < 16; i++) {
            node = (Node_801BAAD4*)resolve_801BAAD4(bones->handles[CTX.world->skel->operator[](i + 12)]);
            if (node) {
                int idx = self->links.add();
                Link_801BAAD4& l = self->links[idx];
                l.node = node;
                l.pos = node->pos;
                l.rot = node->rot;
                l.f58 = lbl_8037A27C;
                HManager_801BAAD4* m = CTX.manager;
                Link_801BAAD4* o;
                signed char found = 0;
                for (int j = 0; j < idx; j++) {
                    o = &((Link_801BAAD4*)self->links.storage)[(unsigned int)j];
                    if (o->node == resolve2_801BAAD4(m, node->parent)) {
                        o->next = idx;
                        found = 1;
                        break;
                    }
                }
                if (!found) self->roots.push(idx);
            }
        }
        for (i = 0; i < self->roots.count; i++) {
            int n = 0;
            int j;
            Int_801BAAD4& root = self->roots[i];
            for (j = root.v; j != -1;) {
                Link_801BAAD4& l = self->links[j];
                n++;
                j = l.next;
            }
            float t;
            float step = lbl_8037A278 / (float)n;
            t = step;
            for (j = root.v; j != -1;) {
                Link_801BAAD4& l = self->links[j];
                l.ratio = lbl_8037A280 * t;
                t += step;
                j = l.next;
            }
        }
        self->ready = 1;
    }
}
#pragma opt_common_subs reset

struct Record_801BAAD4 {
    Vec3_801BAAD4 point;
    float radius;
    float weight, extra;
};

struct Cone_801BAAD4 {
    Vec3_801BAAD4 point;
    Vec3_801BAAD4 dir;
    float weight;
    float maxDot;
    float minDot;
    float inner;
    float outer;
};

template<class T, int N> struct FixedArray_801BAAD4 {
    T data[N];
    int count;
    T& at(const unsigned int& i) { return data[i]; }
};


struct Owner_801BAAD4 {
    char unknown[0x6EC];
    FixedArray_801BAAD4<Cone_801BAAD4, 8> cones;
    FixedArray_801BAAD4<Record_801BAAD4, 8> records;
};

#pragma opt_common_subs off
extern "C" Vec3_801BAAD4 fn_801BAE74(Owner_801BAAD4* self, Vec3_801BAAD4 pos)
{
    Vec3_801BAAD4 sum = game_vec3_zero;
    for (int i = 0; i < self->cones.count; i++) {
        Cone_801BAAD4& c = self->cones.at(i);
        Vec3_801BAAD4 d = c.point - pos;
        float dist = d.length();
        if (dist > *(const float*)&lbl_8037A290) {
        float inner = c.inner, outer = c.outer;
        if (dist < inner + outer) {
            Vec3_801BAAD4 n = d;
            n *= *(const float*)&lbl_8037A278 / dist;
            float dot = n.x * c.dir.x + n.y * c.dir.y + n.z * c.dir.z;
            float minDot = c.minDot;
            if (dot > minDot) {
                float scale = *(const float*)&lbl_8037A278;
                if (dist > inner) scale = (dist - inner) / (outer - inner);
                if (dot < c.maxDot) scale *= (dot - minDot) / (c.maxDot - minDot);
                sum += n * (scale * c.weight);
            }
        }
        }
    }
    for (int i = 0; i < self->records.count; i++) {
        Record_801BAAD4& r = self->records.at(i);
        Vec3_801BAAD4 d = pos - r.point;
        float dist = d.length();
        if (dist > *(const float*)(unsigned long)&lbl_8037A290) {
        float radius = r.radius, extra = r.extra;
        if (dist < radius + extra) {
            float inv = *(const float*)&lbl_8037A278 / dist;
            Vec3_801BAAD4 n = d;
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

extern "C" {
    extern const float lbl_8037A294;
    extern const float lbl_8037A298;
    extern const float lbl_8037A29C;
    extern const Vec3_801BAAD4 game_vec4_zero;
    float fn_800AA52C(float, float);
    float fn_800AA53C(float, float);
}

struct V3 {
    float x, y, z;
    V3() {}
    V3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    void operator=(const V3& o) { x = o.x; y = o.y; z = o.z; }
    V3 operator-(const V3& o) const { return V3(x - o.x, y - o.y, z - o.z); }
    V3 operator+(const V3& o) const { return V3(x + o.x, y + o.y, z + o.z); }
    V3 operator*(float s) const { return V3(x * s, y * s, z * s); }
    void operator+=(const V3& o) { x += o.x; y += o.y; z += o.z; }
    void operator*=(float s) { x *= s; y *= s; z *= s; }
    V3& normalized() { *this *= reciprocalSqrt(x * x + y * y + z * z); return *this; }
    void normalizeFast() { *this *= reciprocalSqrt(x * x + y * y + z * z); }
};

struct Basis_B0C8 {
    float v[9];
    V3 rotate(const V3& a) const
    {
        float X = v[0] * a.x + v[3] * a.y + v[6] * a.z;
        float Y = v[1] * a.x + v[4] * a.y + v[7] * a.z;
        float Z = v[2] * a.x + v[5] * a.y + v[8] * a.z;
        return V3(X, Y, Z);
    }
};

struct Mtx_B0C8 {
    float a[16];
    V3 getPos() const { return V3(a[12], a[13], a[14]); }
    V3 trans() const { return *(const V3*)&a[12]; }
    const V3& pos() const { return *(const V3*)&a[12]; }
};

struct Q4 {
    float w;
    V3 v;
    Q4() {}
    void setFromTo(float ox, float oy, float oz, const V3& a, const V3& b);
    void operator=(const Q4& q) { w = q.w; v.x = q.v.x; v.y = q.v.y; v.z = q.v.z; }
};

struct Node_B0C8 {
    char unknown[0xC];
    Handle_801BAAD4 parent;
    char unknown10[0x30 - 0x10];
    Basis_B0C8 rotation, basis;
    char unknown78[0xB8 - 0x78];
    V3 pos;
    char unknownC4[4];
    Q4 rot;
    char unknownD8[0x120 - 0xD8];
    u32 flags;
    Mtx_B0C8* world;
    void refreshBasis()
    {
        if (flags & 0x40) {
            fn_801F2124B(&rotation, &basis);
            flags &= ~0x40;
        }
    }
    static void fn_801F2124B(const Basis_B0C8* a, Basis_B0C8* b);
};

extern "C" {
    void fn_801F2124(const Basis_B0C8*, Basis_B0C8*);
    void fn_801F27BC(Q4*, const V3*, const V3*);
    void fn_8007D4B4(V3*, const V3*, V3*, float, float);
    void fn_8023DE28(Node_B0C8*);
    void fn_8023D648(Node_B0C8*);
    void fn_8023DEF8(Node_B0C8*, Node_B0C8*);
}
inline void Q4::setFromTo(float ox, float oy, float oz, const V3& a, const V3& b)
{
    V3 want;
    V3 cur(a.x - ox, a.y - oy, a.z - oz);
    want = V3(b.x - ox, b.y - oy, b.z - oz);
    cur.normalizeFast();
    want.normalizeFast();
    fn_801F27BC(this, &cur, &want);
}
inline void Node_B0C8::fn_801F2124B(const Basis_B0C8* a, Basis_B0C8* b) { fn_801F2124(a, b); }

struct Link_B0C8 {
    Node_B0C8* node;
    V3 vel;
    V3 restPos;
    V3 pos;
    V3 target;
    Q4 restRot;
    V3 prevPos;
    int next;
    float ratio;
    float blend;
    V3 nodePos;
};

struct Sphere_B0C8 {
    V3 point;
    float radius;
    Sphere_B0C8() : point(*(const V3*)&game_vec4_zero), radius(lbl_8037A278) {}
};
struct Record_B0C8 {
    Sphere_B0C8 sphere;
    float weight, extra;
    Record_B0C8() {}
    ~Record_B0C8() {}
};
struct Cone_B0C8 {
    char data[0x2C];
    Cone_B0C8() {}
    ~Cone_B0C8() {}
};

struct ChainBase_B0C8 {
    char unknown00[8];
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual V3 getForce(const V3& pos);
};

struct Chain_B0C8 : ChainBase_B0C8 {
    char unknown0C[0x20 - 0xC];
    signed char ready;
    char unknown21[3];
    FixedArray2_801BAAD4<Link_B0C8, 16> links;
    FixedArray2_801BAAD4<Int_801BAAD4, 16> roots;
    FixedArray2_801BAAD4<Cone_B0C8, 8> cones;
    FixedArray2_801BAAD4<Record_B0C8, 8> records;
};

extern "C" void fn_801BB0C8(Chain_B0C8* self, float dt)
{
    if (self->ready) {
        self->ready = 0;
        for (int i = 0; i < self->links.count; i++) {
            Link_B0C8& l = self->links[i];
            l.prevPos = l.node->world->trans();
        }
    } else {
        for (int i = 0; i < self->links.count; i++) {
            Link_B0C8& l = self->links[i];
            Node_B0C8* node = l.node;
            l.nodePos = node->world->getPos();
            if (node->flags & 0x2000) {
                l.blend = fn_800AA52C(lbl_8037A27C, l.blend - dt / lbl_8037A294);
            } else {
                l.blend = fn_800AA53C(lbl_8037A278, l.blend + dt / lbl_8037A294);
            }
            node->pos = l.restPos;
            node->rot = l.restRot;
        }
        for (int i = 0; i < self->roots.count; i++) {
            fn_8023DE28(self->links[self->roots[i].v].node);
        }
        V3* p;
        for (int i = 0; i < self->links.count; i++) {
            Link_B0C8& l = self->links[i];
            p = &l.pos;
            *p = l.node->world->getPos();
            V3 force = self->getForce(*p);
            float k = lbl_8037A298;
            V3& vel = l.vel;
            vel += ((*p - l.prevPos) * k + force) * dt;
            l.target = l.prevPos + l.vel * dt;
            fn_8007D4B4(&l.vel, (const V3*)&game_vec3_zero, &l.vel, lbl_8037A29C, dt);
            l.target = *p * (lbl_8037A278 - l.ratio) + l.target * l.ratio;
            l.target = l.target * (lbl_8037A278 - l.blend) + l.nodePos * l.blend;
        }
        for (int i = 0; i < self->roots.count; i++) {
            int j = self->roots[i].v;
            for (;;) {
                Link_B0C8& a = self->links[j];
                int k = a.next;
                if (k == -1) break;
                Node_B0C8* node = a.node;
                Link_B0C8& b = self->links[k];
                V3 np = node->world->getPos();
                Q4 q;
                q.setFromTo(np.x, np.y, np.z, b.pos, b.target);
                node->refreshBasis();
                Basis_B0C8 m = node->basis;
                q.v = m.rotate(q.v);
                node->rot = q;
                fn_8023D648(node);
                fn_8023DEF8(node, (Node_B0C8*)resolve_801BAAD4(node->parent));
                b.prevPos = b.node->world->pos();
                j = k;
            }
        }
    }
    self->cones.resize(0);
    self->records.resize(0);
}
