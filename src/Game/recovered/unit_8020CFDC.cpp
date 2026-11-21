// Unit auto_03_8020CFDC_text: particle emitter manipulator (fn_8020CFDC emit,
// fn_8020D9C0 update, fn_8020E27C reset).  .sdata2 pool 0x8037AAB0..0x8037AAF0.
// Flags: -O4,p -fp_contract on (frontend CSE ON; no -opt nocse).
struct Handle { signed int tag:8; signed int index:24; };
struct Entry { void* object; int unknown04, unknown08; signed char tag; char unknown0D[3]; };
struct Manager { char unknown00[8]; Entry* entries; };
struct Context { char unknown00[0x118]; Manager* manager; char unknown11C[0x50]; void* particles; };

extern "C" {
extern Context lbl_801E9D24;
void fn_8020EE10(void*);
void fn_8020EDB0(void*);
void fn_8023D400(void*, int);
float fn_800AA52C(float, float); /* max */
float fn_800AA53C(float, float); /* min */
double ceil(double);
double __fabs(double);
}

static inline void* resolve(const Handle& h, Manager* manager)
{
    Entry* e = &manager->entries[h.index];
    if (e->tag == h.tag) return e->object;
    return 0;
}

struct Manager2 { char unknown00[8]; struct { Entry* entries; } table; };
struct Manager3 { Entry* a[3]; };
static inline void* resolveB(const Handle& h, Manager* manager)
{
    Entry* e = &(((Manager2*)manager)->table.entries)[h.index];
    if (e->tag == h.tag) return e->object;
    return 0;
}

struct Self {
    char unknown00[0x20];
    Handle handle20;     // 0x20
    signed char active;  // 0x24
    signed char paused;  // 0x25
    char unknown26[2];
    Handle handle28;     // 0x28
    float value2C;       // 0x2C
    float value30;       // 0x30
};

struct Curve { char data[0x10]; };

struct Def {
    char unknown00[0x76];
    short count76;       // 0x76
    float value78;       // 0x78
    float speed7C;       // 0x7C
    float value80;       // 0x80
    float angle1Base;    // 0x84
    float angle1Spread;  // 0x88
    float angle2Base;    // 0x8C
    float angle2Spread;  // 0x90
    float period;        // 0x94
    float life98;        // 0x98
    float value9C;       // 0x9C
    float valueA0;       // 0xA0
    float sizeA4;        // 0xA4
    float valueA8;       // 0xA8
    float varianceAC;    // 0xAC
    float valueB0;       // 0xB0
    unsigned int flagsB4; // 0xB4
    Curve lifeCurve;     // 0xB8
    Curve curveC8;       // 0xC8
    Curve curveD8;       // 0xD8
    Curve speedCurve;    // 0xE8
    Curve rateCurve;     // 0xF8
    Curve colorCurve;    // 0x108
    Curve curve118;      // 0x118
    Curve curve128;      // 0x128
    Curve curve138;      // 0x138
    Curve curve148;      // 0x148
    Curve curve158;      // 0x158
    Curve curve168;      // 0x168
    Curve curve178;      // 0x178
};
// ---- fn_8020CFDC: particle emission ----
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float fastSqrtOr(register float x, register float r)
{
    if (x != r) asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
inline float sqr(float x) { return x * x; }

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    float lengthSq() const { return x * x + y * y + z * z; }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    Vec3 operator*(const Vec3& v) const { return Vec3(x * v.x, y * v.y, z * v.z); }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    float length() const
    {
        float sq = sqr(x) + sqr(y) + sqr(z);
        float r = 0.0f;
        return sq != r ? fastSqrt(sq) : r;
    }
    void setCross(const Vec3& a, const Vec3& b) { x = a.y * b.z - a.z * b.y; y = a.z * b.x - a.x * b.z; z = a.x * b.y - a.y * b.x; }
    Vec3& operator+=(const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
    Vec3 cross(const Vec3& v) const { return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }
};

inline Vec3 operator/(const Vec3& v, float s) { return Vec3(v.x / s, v.y / s, v.z / s); }

inline float rsqrt(register float x)
{
    register float r;
    asm { frsqrte r, x }
    return r;
}

inline Vec3 normalize(const Vec3& v)
{
    float r = rsqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    return Vec3(v.x * r, v.y * r, v.z * r);
}

inline Vec3 cross(const Vec3& a, const Vec3& b)
{
    return Vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}


struct Matrix {
    float m[4][4];
    float scaleX() const
    {
        Vec3 c; c.x = m[0][0]; c.y = m[1][0]; c.z = m[2][0];
        float sq = c.lengthSq();
        float r = 0.0f;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    Vec3 rotate(const Vec3& v) const
    {
        Vec3 r;
        r.x = m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z;
        r.y = m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z;
        r.z = m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z;
        return r;
    }
void transform3(Vec3& o, float vx, float vy, float vz) const { float x = m[3][0] + (m[0][0] * vx + m[1][0] * vy + m[2][0] * vz); float y = m[3][1] + (m[0][1] * vx + m[1][1] * vy + m[2][1] * vz); float z = m[3][2] + (m[0][2] * vx + m[1][2] * vy + m[2][2] * vz); o.z = z; o.y = y; o.x = x; }
    Vec3 transform(const Vec3& v) const
    {
        Vec3 r;
        r.x = m[3][0] + (m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z);
        r.y = m[3][1] + (m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z);
        r.z = m[3][2] + (m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z);
        return r;
    }
};


inline float lsq3(float x, float y, float z) { return x * x + y * y + z * z; }
struct Shape {
    char unknown00[0x9C];
    float length;
};

struct Updatable {
    char unknown00[8];
    virtual void s08(); virtual void s0C(); virtual void s10(); virtual void s14();
    virtual void s18(); virtual void s1C(); virtual void s20(); virtual void s24();
    virtual void s28(); virtual void s2C(); virtual void s30(); virtual void s34();
    virtual void s38(); virtual void s3C(); virtual void s40(); virtual void s44();
    virtual void s48(); virtual void s4C(); virtual void s50(); virtual void s54();
    virtual void s58(); virtual void s5C(); virtual void s60(); virtual void s64();
    virtual void s68(); virtual void s6C(); virtual void s70();
    virtual void update();
};

struct Index { int value; };

struct Chunk { Vec3 center; float radius; short first; short count; };

struct Pool { char unknown00[0x20]; Index index20; int chunkCount; char unknown28[4]; Chunk* chunks; short capacity; Index getIndex() const { Index r; r = index20; return r; } };

struct Node {
    char unknown00[0x1C];
    Handle parent;       // 0x1C
    Handle handle20;     // 0x20
    char unknown24[0x100];
    Matrix* matrix;      // 0x124
    char unknown128[8];
    Handle handle130;    // 0x130
};

struct Target {
    char unknown00[0x1C];
    Handle parent;
    char unknown20[0x104];
    Matrix* matrix;
};

struct Particle {
    Vec3 position;     // 0x00
    Vec3 velocity;     // 0x0C
    Vec3 spin;         // 0x18
    float size24;      // 0x24
    Vec3 color;        // 0x28
    float age;         // 0x34
    float life;        // 0x38
    float value3C;     // 0x3C
    float value40;     // 0x40
    float size44;      // 0x44
    float value48;     // 0x48
    Vec3 side;         // 0x4C
    Vec3 up;           // 0x58
    Vec3 tint;         // 0x64
    float alpha;       // 0x70
    Vec3 render;       // 0x74
    float value80;     // 0x80
    float value84;     // 0x84
    short prev;        // 0x88
    short next;        // 0x8A
};

struct Range { short first, last, count; };
struct Record { Particle* items; int state; Range used, unused; float stamp; };

extern "C" {
extern float fn_8028506C(float); /* cosf */
extern float fn_80284FA8(float); /* sinf */
int rand(void);
double fmod(double, double);
void fn_801B093C(const Curve*, float*, float, int);
void fn_801AFA0C(const Curve*, Vec3*, float, int);
void fn_8024D868(Shape*, int*, float*, Vec3*, float);
Record* fn_8020E46C(void*, Index, signed char*);
}

inline float randSigned() { return (float)((rand() & 0x3FF) - 0x200) / 512.0f; }

inline short allocParticle(Record* rec)
{
    short index;
    short n = rec->unused.count;
    if (!n) {
        index = -1;
    } else {
        index = rec->unused.first;
        if (n == 1) {
            rec->unused.last = -1;
            rec->unused.first = -1;
        } else {
            rec->unused.first = rec->items[index].next;
        }
        if (rec->used.count == 0) {
            rec->items[index].prev = -1;
            rec->items[index].next = -1;
            rec->used.last = index;
            rec->used.first = index;
        } else {
            rec->items[index].prev = rec->used.last;
            rec->items[index].next = -1;
            rec->items[rec->used.last].next = index;
            rec->used.last = index;
        }
        rec->used.count++;
        rec->unused.count--;
    }
    return index;
}

static inline bool feq(float a, float b) { return a == b; }

extern "C" void fn_8020CFDC(Self* self, Node* node, Def* def, float dt)
{
    Context* ctx;
    float value;
    int cursor;
    float acc;
    Vec3 color;
    Vec3 pos;
    if (!self->active) return;
    ctx = &lbl_801E9D24;
    Record* rec = fn_8020E46C(lbl_801E9D24.particles, ((Pool*)resolve(node->handle20, ctx->manager))->getIndex(), 0);
    if (!rec) return;
    float period = def->period;
    Particle* items = rec->items;
    float t = (float)fmod(self->value30, period) / period;
    fn_801B093C(&def->rateCurve, &value, t, 1);
    self->value2C += value * (dt * (float)def->count76);
    float count;
    if (self->value2C > 1.0f) {
        count = (float)(int)self->value2C;
        self->value2C = self->value2C - count;
    } else {
        return;
    }
    ((Updatable*)resolve(node->handle130, ctx->manager))->update();
    Matrix* matrix = node->matrix;
    float scale = matrix->scaleX();
    Manager* manager = ctx->manager;
    float steps = 1.0f;
    Target* target = (Target*)resolve(self->handle28, manager);
    float length = 0.0f;
    Shape* shape = 0;
    if (target) shape = (Shape*)resolveB(target->parent, manager);
    if (shape) {
        float r; float len;
        len = shape->length;
        r = 0.0f;
        length = len;
        if (len != r) {
            Matrix* m = target->matrix;
            float sq = lsq3(m->m[0][0], m->m[1][0], m->m[2][0]);
            float s = len * fastSqrtOr(sq, r);
            steps = s * def->value78;
        }
    }
    fn_801B093C(&def->speedCurve, &value, t, 1);
    float speed = scale * (value * def->speed7C);
    fn_801B093C(&def->lifeCurve, &value, t, 1);
    float life = value * def->life98;
    fn_801B093C(&def->curveC8, &value, t, 1);
    float value3C = value * def->value9C;
    float value40 = value * def->valueA0;
    fn_801B093C(&def->curveD8, &value, t, 1);
    float size24 = value * def->value80;
    fn_801B093C(&def->curve118, &value, t, 1);
    float spin = value * def->valueB0;
    fn_801AFA0C(&def->colorCurve, &color, t, 1);
    color *= 0.003921569f;
    float r = randSigned();
    float variance = def->varianceAC / 100.0f;
    cursor = -1;
    float sizeScale = (1.0f - variance) + variance * (float)__fabs(r);
    float step;
    if ((def->flagsB4 & 8) && feq(t, 0.0f))
        step = 0.0f;
    else
        step = dt / count;
    float zero = 0.0;
    for (float i = 0.0f; i < steps; i += 1.0f) {
        if (length != zero) {
            fn_8024D868(shape, &cursor, &acc, &pos, length * i / steps);
pos = target->matrix->transform(pos);
        } else {
            pos = matrix->transform(Vec3(zero, zero, zero));
        }
        float age, j;
        for (j = age = 0.0f; j < count; j += 1.0f) {
            short id = allocParticle(rec);
            if (id == -1) return;
            Particle* p = &items[id];
            float r1 = randSigned();
            float theta = def->angle1Base + r1 * def->angle1Spread;
            float r2 = randSigned();
            float phi = def->angle2Base + r2 * def->angle2Spread;
            float radius = 1.0f;
            float cp = fn_8028506C(phi);
            float sp = fn_80284FA8(phi);
            theta = -theta;
            float st = fn_80284FA8(theta);
            Vec3 dir;
            dir.x = radius * (cp * st);
            dir.z = radius * (sp * st);
            dir.y = radius * fn_8028506C(theta);
            Vec3 v = matrix->rotate(dir);
            Vec3 n = v; n *= rsqrt(n.lengthSq());
            Vec3 side;
            if (__fabs(n.z) < 1e-6f && __fabs(n.x) < 1e-6f) {
                side = Vec3(1.0f, 0.0f, 0.0f);
            } else {
                side = normalize(Vec3(n.z, 0.0f, -n.x));
            }
            Vec3 up; up.setCross(side, n);
            up *= rsqrt(up.lengthSq());
            p->spin.x = spin;
            p->spin.y = 0.0;
            p->velocity = v * speed;
            p->spin.z = 0.0;
            p->color = color;
            p->size24 = size24;
            p->life = life;
            p->age = age;
            age += step;
            p->size44 = scale * (sizeScale * def->sizeA4);
            p->value48 = sizeScale * def->valueA8;
            p->position = pos;
            p->value3C = value3C;
            p->value40 = value40;
            p->side = side;
            p->up = up;
        }
    }
}

// ---- fn_8020D9C0: particle update ----

inline void resetRate(Self* self, Context* ctx)
{
    Manager* manager = ctx->manager;
    Node* a = (Node*)resolve(self->handle20, manager);
    Def* b = (Def*)resolveB(a->parent, manager);
    if (b->flagsB4 & 8) {
        float v;
        fn_801B093C(&b->rateCurve, &v, 0.0f, 1);
        self->value2C = v * (float)b->count76;
    }
    self->value30 = 0.0f;
}

inline void freeParticle(Record* rec, short index)
{
    if (rec->used.count == 0) return;
    if (index == -1) return;
    Particle* q = &rec->items[index];
    if (q->prev == -1)
        rec->used.first = q->next;
    else
        rec->items[q->prev].next = q->next;
    if (q->next == -1)
        rec->used.last = q->prev;
    else
        rec->items[q->next].prev = q->prev;
    q->next = rec->unused.first;
    if (rec->unused.count == 0) {
        rec->unused.last = index;
        rec->unused.first = index;
    } else {
        rec->unused.first = index;
    }
    rec->used.count--;
    rec->unused.count++;
}


inline void modulate(Vec3& out, const Vec3& a, const Vec3& b, float s)
{
    out.x = a.x * b.x / s;
    out.y = a.y * b.y / s;
    out.z = a.z * b.z / s;
}

inline void finishChunk(Chunk* chunk, const Vec3& lo, const Vec3& hi)
{
    Vec3 d;
    chunk->center = (lo + hi) * 0.5f;
    const Vec3& e = (d = lo - hi);
    chunk->radius = 0.5f * e.length();
}

extern "C" void fn_8020D9C0(Self* self, float dt)
{
    Context* ctx;
    Manager* manager;
    if (self->paused) return;
    ctx = &lbl_801E9D24;
    manager = ctx->manager;
    Node* node = (Node*)resolve(self->handle20, manager);
    Def* def = (Def*)resolveB(node->parent, manager);
    float period = def->period;
    Pool* pool = (Pool*)resolveB(node->handle20, manager);
    Record* rec = fn_8020E46C(lbl_801E9D24.particles, pool->getIndex(), 0);
    if (self->value30 > period) {
        if (def->flagsB4 & 1) {
            resetRate(self, ctx);
        } else {
            self->active = 0;
            if (rec && rec->used.count == 0) {
                fn_8020EDB0(self);
                return;
            }
        }
    }
    if (!rec) return;
    fmod(self->value30, period);
    fn_8020CFDC(self, node, def, dt);
    Particle* items;
    int chunkCount;
    Chunk* chunk;
    short first = rec->used.first;
    int chunkIndex = -1;
    Vec3 pos(0.0f, 0.0f, 0.0f);
    Vec3 base(0.0f, 0.0f, 0.0f);
    Vec3 lo, hi;
    lo.x = 65536.0f;
    hi.x = -65536.0f;
    lo.y = lo.x;
    lo.z = lo.x;
    hi.y = hi.x;
    hi.z = hi.x;
    items = rec->items;
    short capacity = pool->capacity;
    chunkCount = pool->chunkCount;
    chunk = pool->chunks - 1;
    short next = first;
    if (first >= 0) {
        int perChunk = (int)(float)ceil(0.5f + (float)capacity / (float)chunkCount);
        int n = perChunk;
        while (next >= 0) {
            short cur = next;
            Particle* p = &items[cur];
            next = p->next;
            if (p->age > p->life) {
                freeParticle(rec, cur);
                continue;
            }
            float value;
            float t = p->age / p->life;
            fn_801B093C(&def->curve148, &value, t, 1);
            p->position += p->velocity * dt * value;
            fn_801B093C(&def->curve178, &value, t, 1);
            p->spin.y += value * (p->spin.x * dt);
            p->position += Vec3(0.0f, -1.0f, 0.0f) * (p->spin.y * dt);
            fn_801B093C(&def->curve138, &value, t, 1);
            p->spin.z += value * (p->size24 * dt);
            base = p->position;
            if (p->size44 > 0.001f) {
                float w = p->size44 * fn_80284FA8(6.2831855f * (p->age / p->value48));
                pos = base + p->side * w;
                pos += p->up * w;
            } else pos = base;
            if (n == perChunk) {
                n = 0;
                if (++chunkIndex > 0) finishChunk(chunk, lo, hi);
                lo.x = 65536.0f;
                hi.x = -65536.0f;
                lo.y = lo.x;
                lo.z = lo.x;
                hi.y = hi.x;
                hi.z = hi.x;
                chunk[1].first = cur;
                chunk[1].count = 0;
                chunk++;
            }
            chunk->count++;
            n++;
            lo.x = fn_800AA53C(lo.x, pos.x);
            lo.y = fn_800AA53C(lo.y, pos.y);
            lo.z = fn_800AA53C(lo.z, pos.z);
            hi.x = fn_800AA52C(hi.x, pos.x);
            hi.y = fn_800AA52C(hi.y, pos.y);
            hi.z = fn_800AA52C(hi.z, pos.z);
            Vec3 color;
            fn_801AFA0C(&def->curve158, &color, t, 1);
            modulate(p->tint, p->color, color, 255.0f);
            fn_801B093C(&def->curve168, &p->alpha, t, 1);
            fn_801B093C(&def->curve128, &value, t, 1);
            p->value80 = p->value3C * value;
            p->value84 = p->value40 * value;
            p->render = pos;
            p->age += dt;
        }
    }
    self->value30 += dt;
    if (chunkIndex >= 0 && chunk->count != 0) finishChunk(chunk, lo, hi);
    if (chunkIndex < chunkCount - 1) {
        chunk[1].count = 0;
        chunk[1].first = -1;
    }
    fn_8023D400(node, 0x10);
}

// ---- fn_8020E27C: reset ----



extern "C" void fn_8020E27C(Self* self)
{
    fn_8020EE10(self);
    self->value30 = 0.0f;
    self->value2C = 0.0f;
    resetRate(self, &lbl_801E9D24);
}

// ---- fn_8020E394: range activate (was Game/engine_range_activate.c) ----
namespace range_activate {
struct RNode { char unknown00[0x1C]; Handle first, second; char unknown24[0x90]; unsigned int flagsB4; };
struct REntry { RNode* object; int unknown04, unknown08; signed char tag; char unknown0D[3]; };
struct RManager { char unknown00[8]; REntry* entries; };
struct RCallback { char unknown00[0x20]; Handle handle; signed char active, state; char unknown26[2]; Handle target; float value2C, value30; };
struct RManager2 { char unknown00[8]; struct { REntry* entries; } table; };
static inline RNode* resolve2(RManager* manager, const Handle* handle)
{
    REntry* entry = &((RManager2*)manager)->table.entries[handle->index];
    if (entry->tag == handle->tag)
        return entry->object;
    return 0;
}
static inline RNode* resolve(RManager* manager, const Handle* handle)
{
    REntry* entry = &manager->entries[handle->index];
    if (entry->tag == handle->tag)
        return entry->object;
    return 0;
}
extern "C" void fn_8020EE70(RCallback*);
extern "C" void fn_8020EDB0(void*);
extern "C" void fn_8020E394(RCallback* self)
{
    RManager* manager;
    RNode* object;
    fn_8020EE70(self);
    self->value30 = 0.0f;
    self->value2C = 0.0f;
    manager = (RManager*)lbl_801E9D24.manager;
    object = resolve(manager, &self->handle);
    if (resolve2(manager, &object->first)->flagsB4 & 0x10) {
        self->active = 0;
        fn_8020EDB0(self);
    }
}
}
