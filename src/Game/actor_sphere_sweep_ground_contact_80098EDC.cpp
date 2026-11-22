/* Owner movement step with sphere sweep (slot4C__14CJellyfishMoveFv).
   Defers to slot4C__12ObjectMove_ZFv when fn_8021F23C holds the owner or flag 0x40000 is
   set, and to slot4C__13ObjectThrow_ZFv for flag 0x800000000. Otherwise, when flag 0x400 is
   set and the resource behind the handle at 0x168 has a primary sphere, the
   target-pos delta is tried through virtual tryMove (0x16C); failing that, the
   start is offset by virtual compute (0x10C), a fixed array of up to ten
   spheres (Object_80099B10, inline empty-loop destructor recorded in extab) is
   filled with the primary sphere, the optional secondary sphere (flag
   0x800000), the rider's transformed sphere (handle 0x1AC, flag 0x400000000)
   and a raised foot sphere (unless flag 0x1000000000), and the delta is swept
   in ceil(|d| / (0.5 r)) steps through virtual step (0x164). A downward ray
   (fn_80269818) lifts the target, hit results go to virtual onHit (0x114),
   and the planar output is written before virtual finish (0x100).

   Two handle-resolve overloads (non-const and const) reproduce where the
   original reloads the handle/entry table and where it reuses them. The
   secondary sphere goes through Owner::res() and Resource::secondary() (that
   inline nesting fixes the register choice of the push), and the downward
   ray is filled per component with a second read form of the pooled 0.0f
   (lbl_80378D10) for z. The int-to-float conversion owns the signed bias
   double (lbl_80378D30). */
typedef unsigned long Word;
typedef unsigned long long Flags;

inline void* operator new(unsigned long, void* p) { return p; }

extern "C" {
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
extern const float lbl_80378D10; /* 0.0f */
extern const float lbl_80378D18; /* 0.5f */
extern const float lbl_80378D1C; /* 1.0f */
extern const float lbl_80378D20; /* -1.0f */
extern const float lbl_80378D24; /* 1e-6f */
extern const float lbl_80378D28; /* 0.05f */
double ceil(double);
}

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float ceilf(float x) { return ceil(x); }

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3& operator-=(const Vec3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
    Vec3& operator+=(const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
    float lengthSq() const { return x * x + y * y + z * z; }
    float length() const
    {
        float sq = lengthSq();
        float r = lbl_80378D10;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

struct Sphere {
    Vec3 c;
    float r;
    Sphere(const Vec3& cc, float rr) : c(cc), r(rr) {}
    Sphere(const Sphere& s) : c(s.c), r(s.r) {}
};

struct Object_80099B10 {
    char storage[10 * sizeof(Sphere)];
    int count;
    Sphere* data() { return (Sphere*)storage; }
    Object_80099B10() : count(0) {}
    ~Object_80099B10() { for (int i = 0; i < count; i++) {} }
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
    void add(const Sphere& s)
    {
        int n = count;
        if (n >= 10) {
            new (&data()[9]) Sphere(s);
            return;
        }
        count = n + 1;
        new (&data()[n]) Sphere(s);
    }
};

struct Handle { union { Word word; struct { signed int tag : 8, index : 24; } bits; }; };
struct Entry { void* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct Manager { int count, capacity; Entry* entries; };
extern "C" struct Global { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;

template <class T> inline T* resolve(Handle& h)
{
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    if (e->tag == h.bits.tag) return (T*)e->object;
    return 0;
}
template <class T> inline T* resolve(const Handle& h)
{
    const Entry* e = &((const Manager*)lbl_801E9D24.manager)->entries[h.bits.index];
    if (e->tag == h.bits.tag) return (T*)e->object;
    return 0;
}

struct Matrix { float m[12]; };
struct Node { char unknown00[0xC]; Handle h0C; char unknown10[0x124 - 0x10]; const Matrix* matrix; };
struct HitObject { char unknown00[4]; Handle h04; char unknown08[0x120 - 8]; Word flags; };
struct Resource { char unknown00[0x74]; const Sphere* sphere74; const Sphere* sphere78; const Sphere& secondary() const { return *sphere78; } };

struct Result {
    Vec3 point;
    float t;
    char unknown10[0x28 - 0x10];
    Word unknown28, unknown2C;
    HitObject* object;
    Word unknown34, unknown38;
    signed char hit;
    char unknown3D[3];
    Flags mask40;
    Result() { hit = 0; object = 0; unknown34 = 0; unknown38 = 0; unknown2C = 0; unknown28 = 0; }
};

struct Ray {
    Vec3 origin;
    float length;
    Vec3 direction;
    float unknown1C;
    Ray() {}
};

struct World;
struct Prefix { char unknown00[8]; };
struct Owner : Prefix {
    virtual void slot8();
    virtual void slotC();
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
    virtual const Handle* getHandle(int);
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
    virtual void finish(World*,const Vec3*,const Vec3*,Vec3*,int,float);
    virtual void slot104();
    virtual void slot108();
    virtual Vec3 compute(World*,const Vec3*,const Sphere*,const Vec3*,Vec3*,int,int);
    virtual void slot110();
    virtual void onHit(Result*,const Vec3*,int);
    virtual void slot118(int,int);
    virtual void slot11C();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12C();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13C();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14C();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15C();
    virtual void slot160();
    virtual void step(World*,Vec3*,const Vec3*,Object_80099B10*,Result*,Vec3*);
    virtual void slot168();
    virtual signed char tryMove(World*,const Vec3*,Vec3*,const Vec3*,Vec3*,float);
    char unknown0C[0x30 - 0xC];
    Flags flags;
    char unknown38[0x168 - 0x38];
    Handle h168;
    char unknown16C[0x1AC - 0x16C];
    Handle h1AC;
    Resource* res() { return resolve<Resource>(h168); }
    signed char hasFlags(Flags m) const { signed char r = 0; if (flags & m) r = 1; return r; }
};

extern "C" {
signed char fn_8021F23C(Owner*);
void slot4C__12ObjectMove_ZFv(Owner*, World*, const Vec3*, Vec3*, Vec3*, const Vec3*, int, float);
void slot4C__13ObjectThrow_ZFv(Owner*, World*, const Vec3*, Vec3*, Vec3*, const Vec3*, int, float);
Sphere fn_80099A00(const Matrix*, const Sphere*);
signed char fn_80269818(World*, const Ray&, Result*, Flags, Flags);
}

extern "C" void slot4C__14CJellyfishMoveFv(Owner* self, World* world, const Vec3* pos, Vec3* target, Vec3* out,
                            Vec3* vel, int index, float dt)
{
    if (fn_8021F23C(self) || self->hasFlags(0x40000ULL)) {
        slot4C__12ObjectMove_ZFv(self, world, pos, target, out, vel, index, dt);
        return;
    }
    if (self->flags & 0x800000000ULL) {
        slot4C__13ObjectThrow_ZFv(self, world, pos, target, out, vel, index, dt);
        return;
    }
    Vec3 start = *pos;
    if (self->flags & 0x400ULL) {
        if (!resolve<Resource>(self->h168)->sphere74) return;
        Vec3 d = *target - *pos;
        if (d.x * d.x + d.z * d.z < lbl_80378D24) self->flags |= 0x80000000000ULL;
        if (self->tryMove(world, pos, &d, vel, out, dt)) {
            *target = *pos + d;
        } else {
            Sphere sphere = *resolve<Resource>(self->h168)->sphere74;
            start += self->compute(world, pos, &sphere, vel, out, index, 1);
            Vec3 cur = start;
            int steps = (int)ceilf(d.length() / (lbl_80378D18 * sphere.r));
            if (steps == 0) steps++;
            Owner* rider = resolve<Owner>(self->h1AC);
            Object_80099B10 spheres;
            spheres.add(sphere);
            if (self->flags & 0x800000ULL) {
                if (resolve<Resource>(((const Owner*)self)->h168)->sphere78) spheres.add(self->res()->secondary());
            }
            if (rider && (rider->flags & 0x400000000ULL) && resolve<Resource>(rider->h168)->sphere74) {
                const Matrix* m = resolve<Node>(*rider->getHandle(0))->matrix;
                Sphere s = fn_80099A00(m, resolve<Resource>(rider->h168)->sphere74);
                Sphere t = s;
                t.c -= cur;
                spheres.add(t);
            }
            if (!(self->flags & 0x1000000000ULL)) {
                spheres.add(Sphere(Vec3(sphere.c.x, lbl_80378D28 + sphere.r, sphere.c.z), sphere.r));
            }
            Result result;
            float inv = lbl_80378D1C / (float)steps;
            Vec3 stepVec = d * inv;
            for (int i = 0; i < steps; i++) {
                self->step(world, &cur, &stepVec, &spheres, &result, target);
                cur = *target;
            }
            self->slot118(1, index);
            Result ground;
            Ray ray;
            ray.origin = *target;
            ray.direction.x = lbl_80378D10;
            ray.direction.y = lbl_80378D20;
            ray.direction.z = *(const float*)&lbl_80378D10;
            ray.length = lbl_80378D1C;
            if (fn_80269818(world, ray, &ground, 0xFFFFFFFFFFFFFFFFULL, 0ULL)) {
                target->y += lbl_80378D1C - ground.t;
                self->flags |= 0x8000000000ULL;
            }
            if (result.hit) {
                if (result.object->flags & 0x200) {
                    Node* n = resolve<Node>(*self->getHandle(index));
                    if (resolve<Node>(result.object->h04) != resolve<Node>(n->h0C)) {
                        self->onHit(&result, vel, index);
                        goto done;
                    }
                }
                if (result.object->flags & 0x800) self->onHit(&result, vel, index);
            }
        done:
            if (!(self->flags & 0x40ULL)) {
                if (d.x * d.x + d.z * d.z < lbl_80378D24) d = *vel;
                *out = *target + d;
            }
        }
    } else {
        *out = start + *vel;
    }
    self->finish(world, pos, &start, target, index, dt);
}
