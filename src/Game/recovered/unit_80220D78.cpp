/* fn_80220D78: owner ground-follow step. Either blends toward the midpoint
 * of two related nodes (flag bit 33) or probes the ground below the midpoint
 * height, validates the hit edge and attaches to it (flag bit 32).
 * w13 shape notes: Hit is 0x48 bytes (stack objects are placed by size);
 * `direction` must be a non-const Vec3* (loads through pointer-to-const are
 * hoisted over stack stores); the probe Ray ctor takes the direction by value;
 * the edge distance is root((origin - point).lengthSq()) so the difference
 * temp stays on the stack.
 * w29 shape notes (all needed for EXACT): the second handle index of each
 * pair is held in a one-member struct box (scalarized member = CSE-phase
 * temp, so prop->firstB/secondB load early); block A's box is copy-initialized
 * from an uninitialized box (two definitions). transformOf takes the Matrix
 * and keeps z in a one-member box with three uses. Repeated float constants
 * use mixed spellings (plain vs *(const float*)&lbl) so the frontend does not
 * CSE them but the backend still merges the loads. origin is built member-wise
 * with a dead 'origin.x = 0' first so its scalarized x temp is created first. */
typedef unsigned long Word;
typedef unsigned long long Flags;
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
extern "C" const float lbl_8037B0A0;
extern "C" const float lbl_8037B098;
extern "C" const float lbl_8037B09C;
extern "C" const float lbl_8037B0AC;
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 half() const { return Vec3(x * lbl_8037B098, y * lbl_8037B098, z * (*(const float*)&lbl_8037B098)); }
    Vec3 scaledEdge() const { return Vec3(x * lbl_8037B0AC, y * lbl_8037B0AC, z * (*(const float*)&lbl_8037B0AC)); }
    Vec3& operator+=(const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
    Vec3 scaledRay() const { return Vec3(x * lbl_8037B09C, y * lbl_8037B09C, z * (*(const float*)&lbl_8037B09C)); }
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    float length() const
    {
        float sq = lengthSq();
        float r = lbl_8037B0A0;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    float lengthSq() const
    {
        float xx = x * x; float yy = y * y; float zz = z * z;
        return xx + yy + zz;
    }
};
inline float root(float sq)
{
    float r = lbl_8037B0A0;
    if (sq != r) r = fastSqrt(sq);
    return r;
}
struct Vec4 : Vec3 {
    float w;
    Vec4() {}
    Vec4(const Vec3& v) : Vec3(v) {}
    Vec4(const Vec3& v, float f) : Vec3(v), w(f) {}
    Vec4(const Vec4& v) : Vec3(v), w(v.w) {}
    Vec4& operator=(const Vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }
};
struct Ray {
    Vec3 origin;
    float length;
    Vec3 direction;
    float extra;
    Ray() {}
    Ray(const Vec3& o, float l, Vec3 d, float e) : origin(o), length(l), direction(d), extra(e) {}
};
struct Matrix {
    float a[16];
    const Vec3& getPosition() const { return *(const Vec3*)&a[12]; }
    float transformY(const Vec3& p) const { float pz = p.z; pz = pz; return a[13] + (a[1] * p.x + a[5] * p.y + a[9] * pz); }
    Vec3 transformOf(const Matrix& m) const
    {
        float py = m.a[13]; float px = m.a[12];
        struct { float v; } pz; pz.v = m.a[14];
        float Z, Y, X;
        Y = a[13] + (a[1] * px + a[5] * py + a[9] * pz.v);
        Z = a[14] + (a[2] * px + a[6] * py + a[10] * pz.v);
        X = a[12] + (a[0] * px + a[4] * py + a[8] * pz.v);
        return Vec3(X, Y, Z);
    }
    Vec3 transform(const Vec3& p) const
    {
        float X = a[12] + (a[0] * p.x + a[4] * p.y + a[8] * p.z);
        float Y = a[13] + (a[1] * p.x + a[5] * p.y + a[9] * p.z);
        float Z = a[14] + (a[2] * p.x + a[6] * p.y + a[10] * p.z);
        return Vec3(X, Y, Z);
    }
};
struct MatrixCache {
    Matrix* arrays[6];
    unsigned char active;
};
struct Handle {
    signed int generation : 8, index : 24;
};
struct Actor;
struct Entry {
    Actor* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct Manager { int count, capacity; Entry* entries; };
struct Property { Word unknown00; Word firstA, firstB, secondA, secondB; };
struct PropertyContext { char unknown00[0x94]; Property* property; };
struct Globals {
    char unknown00[0x110];
    void* logger;
    char unknown114[4];
    Manager* manager;
    char unknown11C[0x18];
    MatrixCache* cache;
    char unknown138[0xC];
    PropertyContext* propertyContext;
};
struct EdgeInfo { unsigned short flags; char unknown02[0x16]; };
struct Mesh { char unknown00[0xA0]; EdgeInfo* edges; };
struct Hit {
    Vec3 point;
    char unknown0C[0x1C];
    Flags flags;
    Actor* object;
    void* other;
    void* extra;
    signed char hit;
    char unknown3D[0xB];
    Hit() { hit = 0; object = 0; other = 0; extra = 0; flags = 0; }
};
struct EdgeHit {
    Vec3 point;
    float unknown0C;
    Vec3 normal;
    float fraction;
    Actor* object;
    Mesh* mesh;
    int index;
    signed char hit;
    EdgeHit() { hit = 0; object = 0; mesh = 0; }
};
struct Settings { char unknown00[0xC]; float height; };
extern "C" {
extern Globals lbl_801E9D24;
extern const Vec3 game_vec3_zero;
extern const float lbl_8037B098, lbl_8037B09C, lbl_8037B0A0, lbl_8037B0A4, lbl_8037B0A8, lbl_8037B0AC, lbl_8037B0B0, lbl_8037B0B4, lbl_8037B0B8;
extern const char lbl_802AE938[], lbl_802AE974[];
void fn_801F230C(const Matrix*, Matrix*);
float fn_800AA53C(float, float);
float fn_800A8E8C(float, float, float);
signed char fn_80269228(void*, const Ray&, int, EdgeHit*);
signed char fn_80269230(void*, const Ray&, Hit*, Flags, Flags);
float fn_801D6FB4(Mesh* mesh, const Matrix& mtx, int index, Vec3* out, float u);
float fn_801D75C0(Mesh* mesh, const Matrix& mtx, int index, Vec3* out, float dist);
void fn_801FA014(void*, const char*, ...);
}
struct Actor {
    char unknown00[0x28];
    Handle* handles;
    char unknown2C[0x48];
    Settings* settings;
    char unknown78[0xA8];
    Word flags;
    Matrix* matrix;
    Matrix* cached;
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
inline Actor* resolve(const Handle& h)
{
    int i = h.index;
    Manager* m = lbl_801E9D24.manager;
    int generation = m->entries[i].getGeneration();
    return generation == h.generation ? m->entries[i].object : 0;
}
struct ABox { Actor* a; };
inline void resolveTo(Actor*& out, const Handle& h)
{
    int i = h.index;
    Manager* m = lbl_801E9D24.manager;
    int generation = m->entries[i].getGeneration();
    if (generation == h.generation) out = m->entries[i].object; else out = 0;
}
inline Actor* resolveK(const Handle& h, ABox& dst, const ABox& src)
{
    int i = h.index;
    Manager* m = lbl_801E9D24.manager;
    int generation = m->entries[i].getGeneration();
    Actor* r;
    if (generation == h.generation) { r = m->entries[i].object; dst.a = src.a; }
    else { r = 0; dst.a = src.a; }
    return r;
}
struct WordBox0 { Word v; };
struct Prefix { Word unknown00, unknown04; };
struct Owner : Prefix {
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
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual const Handle& getHandle(int);
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual void slotAC();
    virtual void slotB0();
    virtual void slotB4();
    virtual void slotB8();
    virtual void slotBC();
    virtual void slotC0();
    virtual void slotC4();
    virtual void slotC8();
    virtual void slotCC();
    virtual void slotD0();
    virtual void slotD4();
    virtual void slotD8();
    virtual void slotDC();
    virtual void slotE0();
    virtual void slotE4();
    virtual void slotE8();
    virtual void slotEC();
    virtual void slotF0();
    virtual void slotF4();
    virtual void slotF8();
    virtual void slotFC();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10C();
    virtual Vec3 step(const Vec3& position, const Vec3* direction, void* arg, int mode);
    virtual void attach(Hit* hit, Vec3* normal, int mode);
    char unknown0C[0x30 - 0xC];
    Flags flags;
    char unknown38[0x50];
    Vec3 anchor;
    char unknown94[0x34];
    float time;
    char unknownCC[0x9C];
    Handle settingsHandle;
    Handle related;
    signed char test(Flags f) const { return (flags & f) ? 1 : 0; }
};
extern "C" int fn_80220D78(Owner* self, void* world, const Vec3* position, Vec3* out, Vec3* direction, void* arg, float dt)
{
    if (!self->test(0x100000000ULL) && !(self->flags & 0x200000000ULL))
        return 0;
    ABox O;
    O.a = 0;
    ABox R;
    resolveTo(R.a, self->related);
    ABox R2;
    Actor* actor = resolveK(self->getHandle(0), R2, R);
    if (self->test(0x200000000ULL)) {
        Property* prop = lbl_801E9D24.propertyContext->property;
        WordBox0 z;
        WordBox0 bx = z;
        bx.v = prop->firstB;
        Actor* a = resolve(R2.a->handles[prop->firstA]);
        Actor* b = resolve(R2.a->handles[bx.v]);
        Vec3 tb = actor->matrix->transformOf(*b->matrix);
        Vec3 ta = actor->matrix->transformOf(*a->matrix);
        Vec3 mid = (tb + ta).half();
        *out = self->step(mid, direction, arg, 0);
        float s = fn_800AA53C(self->time, lbl_8037B09C) / lbl_8037B09C;
        out->x = out->x * s;
        out->y = out->y * s;
        out->z = out->z * s;
        self->time += dt;
        return 1;
    }
    if (!(self->flags & 0x100000000ULL))
        return 0;
    Settings* settings = resolve(self->settingsHandle)->settings;
    if (!settings)
        return 0;
    Property* prop = lbl_801E9D24.propertyContext->property;
    struct { Word v; } bx;
    bx.v = prop->secondB;
    Actor* a = resolve(R2.a->handles[prop->secondA]);
    Actor* b = resolve(R2.a->handles[bx.v]);
    float unset;
    float height = settings->height;
    float yb = actor->matrix->transformY(b->matrix->getPosition());
    float ya = actor->matrix->transformY(a->matrix->getPosition());
    Vec3 origin;
    origin.x = 0;
    float y = yb + ya;
    origin.y = y * lbl_8037B098;
    origin.z = position->z;
    origin.x = position->x;
    EdgeHit edge;
    Ray probe(origin, (*(const float*)&lbl_8037B09C) + height, *direction, unset);
    if (!fn_80269228(world, probe, 1, &edge))
        return 0;
    float u = fn_800A8E8C(edge.fraction, lbl_8037B0A0, lbl_8037B0A4);
    Vec3 normal = edge.normal;
    Vec3 point = edge.point;
    Matrix* matrix;
    int index = edge.index;
    Hit hit;
    float length = root((origin - point).lengthSq());
    Ray ray;
    ray.origin = origin;
    ray.direction = *direction;
    ray.length = length;
    if (fn_80269230(world, ray, &hit, 1ULL, 0x400000008ULL))
        return 0;
    O.a = edge.object;
    matrix = O.a->matrix;
    Matrix* cached = O.a->getMatrix();
    Mesh* mesh = edge.mesh;
    float total = fn_801D6FB4(mesh, *matrix, index, 0, lbl_8037B0A4);
    Vec3 unused;
    float along = fn_801D6FB4(mesh, *matrix, index, &unused, u);
    float margin = height + lbl_8037B0A8;
    unsigned short flags = mesh->edges[index].flags;
    if (total < margin && !(flags & 6))
        return 0;
    if (along < margin && !(flags & 2)) {
        fn_801FA014(lbl_801E9D24.logger, lbl_802AE938, fn_801D75C0(mesh, *matrix, index, &point, margin));
    } else if (total - along < margin && !(flags & 4)) {
        fn_801FA014(lbl_801E9D24.logger, lbl_802AE974, fn_801D75C0(mesh, *matrix, index, &point, total - margin));
    }
    point += normal.scaledEdge();
    point.y -= lbl_8037B0B0;
    normal = -normal;
    Ray down;
    down.origin = point + Vec3((*(const float*)&lbl_8037B0A0), lbl_8037B0A4, lbl_8037B0A0) + normal.scaledRay();
    down.direction = Vec3(lbl_8037B0A0, lbl_8037B0B4, lbl_8037B0A0);
    down.length = lbl_8037B0B8;
    if (!fn_80269230(world, down, &hit, 1ULL, 0x68ULL))
        return 0;
    if (hit.object != edge.object)
        return 0;
    Hit contact;
    contact.object = edge.object;
    contact.point = point;
    contact.flags = 0;
    self->attach(&contact, &normal, 0);
    self->anchor = cached->transform(hit.point);
    self->step(*position, direction, arg, 0);
    *out = game_vec3_zero;
    self->flags |= 0x200000000ULL;
    return 1;
}
