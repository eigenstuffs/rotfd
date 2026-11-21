/* Merged translation unit for .text 0x802461E0-0x80246F94 (SpatialHandles ctor .. fn_80246E64).
   .sdata2 0x8037B3DC-0x8037B3E8: pooled literals 1.0f, 0.0f, 0.5f in first-use order.
   lbl_8037B3D0 (-1.0f) stays an external named constant. */


struct RootStorage_80207414 {unsigned long unknown00,identity;};
struct BaseObject_Z : RootStorage_80207414 {
 BaseObject_Z();virtual ~BaseObject_Z();virtual void slot0C(unsigned long);virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char slot1C();
};
extern "C" {extern const char lbl_801EF5C8[];void fn_801EF610(const void*,void*);}
struct Resource_802E9E20:BaseObject_Z {Resource_802E9E20(){}virtual ~Resource_802E9E20();static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}};
struct SpatialPoint {float x,y,z;SpatialPoint(const SpatialPoint&other){x=other.x;y=other.y;z=other.z;}};
/* .sdata2 0x8037B3D0..0x8037B3DC: named constants emitted ahead of the pooled literals so the unit's 8-aligned pool starts on the original boundary; defined inside a namespace so later uses are not folded into a second pooled copy. */
namespace sdata2_def { extern "C" { extern const float lbl_8037B3D0 = -1.0f; __declspec(section ".sdata2") extern const char lbl_8037B3D4[8] __attribute__((aligned(4))) = "LodData"; } }
extern "C" {extern SpatialPoint game_vec4_zero;extern const float lbl_8037B3D0;void __ct__14Light_8024405CFv(void*);}
struct SpatialSphere {SpatialPoint point;float radius;SpatialSphere(float value):point(game_vec4_zero),radius(value){}};
struct SpatialBase_802EC118:Resource_802E9E20 {
 int flags;SpatialSphere bounds;
 SpatialBase_802EC118(float radius):bounds(radius){flags=0;}
 /* The native spatial stream reader overrides Root slot0C. Its argument
  * is represented here by the original 32-bit address-word ABI. */
 virtual void slot0C(unsigned long);
 virtual ~SpatialBase_802EC118();
 virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34(void*); virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44(); virtual void slot48();

};
struct Handle_801F7F10 {unsigned long value;Handle_801F7F10();~Handle_801F7F10();};
struct SpatialZeroHandle:Handle_801F7F10 {SpatialZeroHandle(){value=0;}};
struct SpatialTwiceZeroHandle:SpatialZeroHandle {SpatialTwiceZeroHandle(){value=0;}};
struct SpatialThriceZeroHandle:SpatialTwiceZeroHandle {SpatialThriceZeroHandle(){value=0;}};
struct SpatialFields {int first,second,third;SpatialFields(){first=0;second=0;third=0;}};
struct SpatialTransform {char unknown00[0xB8];SpatialTransform(){__ct__14Light_8024405CFv(this);}};
struct SpatialHandles_802EA2E0:SpatialBase_802EC118 {
 SpatialFields fields;char unknown2C[0x4C-0x2C];SpatialTransform transform;
 SpatialTwiceZeroHandle first;SpatialThriceZeroHandle second,third;
 int tail00,tail04,tail08,tail0C,tail10,tail14;float x,y,z,w;
 SpatialHandles_802EA2E0();virtual ~SpatialHandles_802EA2E0();virtual void slot4C();
};

typedef char SpatialBaseSizeCheck[(sizeof(SpatialBase_802EC118)==0x20)?1:-1];
typedef char SpatialHandlesSizeCheck[(sizeof(SpatialHandles_802EA2E0)==0x138)?1:-1];



SpatialHandles_802EA2E0::SpatialHandles_802EA2E0():SpatialBase_802EC118(1.0f){
 tail00=0;tail04=0;tail08=0;tail0C=0;tail10=0;tail14=0;
 x=0.0f;y=0.0f;z=0.0f;w=lbl_8037B3D0;
}

extern "C" void fn_80246310(void) { }

namespace part_80246314 {
/* auto_03_80246314_text: fn_80246314, composite bounds refresh.
 *
 * For every valid child handle of the owner whose node type is 3 (composite),
 * looks up the matching per-instance state (h -> +0x20 info handle -> info's
 * handle array [i]) and, for each binding of that child whose first group id
 * names a valid, enabled sub-node, transforms the sub-node sphere by the bound
 * bone's world matrix (fn_80099A00) and accumulates it into the owner's bounds
 * (first hit assigns, later hits merge via fn_801F0A20).  Ends with
 * fn_80246798(self).
 *
 * Allocation-sensitive spellings (all verified):
 * - handle resolves use a non-template inline (RES macro casts the void*
 *   result); the template form reorders callee-saved registers;
 * - the bounds pointer is taken through the inline accessor sphere();
 *   &self->bounds gives the same code with three saved registers rotated;
 * - the sub-node id is read as groups.data->id in the validity/flag tests and
 *   as groups[0].id (operator[]) for the sphere lookup, which keeps the
 *   original reload of the id in both branches.
 * Flags: GC/1.3.2 -O4,p -inline auto -Cpp_exceptions off (no extab). */
struct Handle {
    union { unsigned long word; struct { signed int tag : 8, index : 24; } bits; };
    signed char getTag() const { return *(const signed char*)this; }
};
struct Entry {
    void* object;
    char unknown04[8];
    signed char tag;
    char pad0D[3];
    signed char getTag() const { return tag; }
};
struct Manager { char unknown00[8]; Entry* entries; };
extern "C" struct Global {
    char unknown00[0x118];
    Manager* manager;
} lbl_801E9D24;

#define RES(T, x) ((T*)resolveAny(x))
inline void* resolveAny(const Handle& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.getTag() ? m->entries[index].object : 0;
}

struct Sphere {
    float x, y, z, r;
    Sphere& operator=(const Sphere& o) { x = o.x; y = o.y; z = o.z; r = o.r; return *this; }
};
struct Matrix { float m[16]; };

struct HandleArray { int count, capacity; Handle* data; };
struct Group { short id; char pad02[2]; int count, capacity; void* data; char unknown10[0xC]; };
struct GroupArray {
    int count, capacity;
    Group* data;
    Group& operator[](int i) { return data[i]; }
    const Group& operator[](int i) const { return data[i]; }
};
struct Binding { int bone; GroupArray groups; };
struct BindingArray { int count, capacity; Binding* data; };

struct Flagged { char unknown00[0xC]; unsigned long flags; };
struct WorldObject { char unknown00[0x124]; Matrix* matrix; };
struct State {
    char unknown00[0x20];
    HandleArray bones;
    char unknown2C[0x64 - 0x2C];
    HandleArray handles;
};
struct Info { char unknown00[0x20]; HandleArray handles; };
struct Target { char unknown00[0x20]; Handle info; };
struct Owner {
    char unknown00[0xC];
    Sphere bounds;
    char unknown1C[0x6C - 0x1C];
    unsigned short type;
    char unknown6E[0x74 - 0x6E];
    BindingArray bindings;
    HandleArray handles;
    char unknown8C[0xC0 - 0x8C];
    HandleArray children;
    Sphere* sphere() { return &bounds; }
};

extern "C" {
unsigned long fn_801F7EB8(const Handle*);
Sphere fn_80099A00(const Matrix*, const Sphere*);
Sphere fn_801F0A20(const Sphere&, const Sphere&);
void fn_80246798(Owner*);
}

extern "C" void fn_80246314(Owner* self, const Handle& h)
{
    Sphere* bounds = self->sphere();
    signed char found = 0;
    for (int i = 0; i < self->children.count; ++i) {
        if (fn_801F7EB8(&self->children.data[i]) && RES(Owner, self->children.data[i])->type == 3) {
            State* state = RES(State, RES(Info, RES(Target, h)->info)->handles.data[i]);
            Owner* child = RES(Owner, self->children.data[i]);
            for (int j = 0; j < child->bindings.count; ++j) {
                if (fn_801F7EB8(&child->handles.data[child->bindings.data[j].groups.data->id])) {
                    if (!(RES(Flagged, state->handles.data[child->bindings.data[j].groups.data->id])->flags & 1)) {
                        if (!found) {
                            Matrix* m = RES(WorldObject, state->bones.data[child->bindings.data[j].bone])->matrix;
                            *bounds = fn_80099A00(m, &RES(Owner, child->handles.data[child->bindings.data[j].groups[0].id])->bounds);
                        } else {
                            Matrix* m = RES(WorldObject, state->bones.data[child->bindings.data[j].bone])->matrix;
                            *bounds = fn_801F0A20(*bounds, fn_80099A00(m, &RES(Owner, child->handles.data[child->bindings.data[j].groups[0].id])->bounds));
                        }
                        found = 1;
                    }
                }
            }
        }
    }
    fn_80246798(self);
}
}

extern "C" int fn_80246710(void *object,void *unused,float *out) {const float *source=*(const float **)((char *)object+0xb0);out[0]=source[0];out[1]=source[1];out[2]=source[2];out[3]=source[3];return 1;}

namespace part_8024673C {
struct SphereReturnPoint {
    float x, y, z;
    SphereReturnPoint() {}
    SphereReturnPoint(const SphereReturnPoint& p): x(p.x), y(p.y), z(p.z) {}
    SphereReturnPoint& operator=(const SphereReturnPoint& p)
    { x = p.x; y = p.y; z = p.z; return *this; }
};
struct SphereReturnValue {
    SphereReturnPoint point;
    float radius;
    SphereReturnValue() {}
    SphereReturnValue(const SphereReturnValue& s): point(s.point), radius(s.radius) {}
    SphereReturnValue& operator=(const SphereReturnValue& s)
    { point = s.point; radius = s.radius; return *this; }
};
struct SphereReturnOwner { char unknown00[0xB0]; SphereReturnValue* sphere; };
struct SphereReturnObject { char unknown00[0x124]; void* matrix; };

extern "C" {
SphereReturnValue fn_80099A00(const void*, const SphereReturnValue*);
SphereReturnValue fn_80246E64(const void*);
SphereReturnValue fn_801F0A20(const SphereReturnValue&, const SphereReturnValue&);
int fn_8024673C(SphereReturnOwner*, SphereReturnObject*, SphereReturnValue*);
SphereReturnValue fn_80246E14(const SphereReturnValue&, const void*);
}
typedef char SphereReturnValueSize[sizeof(SphereReturnValue) == 16 ? 1 : -1];




extern "C" int fn_8024673C(SphereReturnOwner* self, SphereReturnObject* object, SphereReturnValue* out)
{
    *out = fn_80099A00(object->matrix, self->sphere);
    return 1;
}
}

#define BOUNDS_POOLED_LITERALS
#pragma push
#pragma inline_max_size(1024)
#pragma fp_contract off
namespace part_80246798 {
/* fn_80246798: composite node bounds refresh -- merges every attached
 * primitive (spheres, capsules, matrix shapes) into the node bounds.
 *
 * The capsule -> bounding sphere conversion is register- and stack-layout
 * sensitive; what matters is the inline nesting depth of each piece (the
 * compiler creates inline temporaries breadth-first, and colours them in
 * creation order):
 *   - "edge" (pos + (0,0,radius)) and the difference are built by operators
 *     called directly from the Sphere constructor;
 *   - the fast square root (with its zero-initialised result) is also called
 *     directly from the constructor, not through Vec3::length();
 *   - the centre goes through one wrapper (Capsule::mid -> addScaled);
 *   - the axis goes through two (Capsule::axis -> scaledDir -> operator*),
 *     while its temporary still belongs to the constructor (const Vec3& half).
 *
 * 0.0f / 0.5f are pooled literals of the original translation unit
 * (lbl_8037B3E0 / lbl_8037B3E4). Define BOUNDS_POOLED_LITERALS to build with
 * real literals (EXACT-MOD-POOL, 8 pool refs); the default references the
 * existing labels, with the casts keeping the three zero uses separate loads
 * for the front end exactly as literals are (EXACT). */

#ifdef BOUNDS_POOLED_LITERALS
#define BOUNDS_ZERO_A 0.0f
#define BOUNDS_ZERO_B 0.0f
#define BOUNDS_ZERO_C 0.0f
#define BOUNDS_HALF 0.5f
#else
extern "C" const float lbl_8037B3E0; /* 0.0f */
extern "C" const float lbl_8037B3E4; /* 0.5f */
#define BOUNDS_ZERO_A lbl_8037B3E0
#define BOUNDS_ZERO_B (*(const float*)&lbl_8037B3E0)
#define BOUNDS_ZERO_C (*(const float*)(unsigned long)&lbl_8037B3E0)
#define BOUNDS_HALF lbl_8037B3E4
#endif

inline float fastSqrt(register float x)
{
    register float r = BOUNDS_ZERO_C;
    if (x != r) {
        asm { frsqrte f4, x
              fres r, f4 }
    }
    return r;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 addScaled(const Vec3& v, float s) const { return Vec3(x + v.x * s, y + v.y * s, z + v.z * s); }
    float lengthSquared() const { return x * x + y * y + z * z; }
};

struct Capsule {
    Vec3 pos;
    float length;
    Vec3 dir;
    float unknown1C;
    float radius;
    Vec3 scaledDir(float s) const { return dir * s; }
    Vec3 axis() const { return scaledDir(length); }
    Vec3 mid(const Vec3& half) const { return pos.addScaled(half, BOUNDS_HALF); }
};

struct Sphere {
    Vec3 center;
    float r;
    Sphere() {}
    Sphere(const Capsule& c)
    {
        const Vec3& half = c.axis();
        center = c.mid(half);
        const Vec3& d = (c.pos + Vec3(BOUNDS_ZERO_A, BOUNDS_ZERO_B, c.radius)) - center;
        r = fastSqrt(d.lengthSquared());
    }
    Sphere& operator=(const Sphere& o)
    {
        center.x = o.center.x;
        center.y = o.center.y;
        center.z = o.center.z;
        r = o.r;
        return *this;
    }
};

struct Node {
    char unknown00[0xC];
    Sphere bounds;
    char unknown1C[0x70 - 0x1C];
    Sphere* extra70;
    Sphere* a0;
    Sphere* a1;
    Capsule* a2;
    void* a3;
    Sphere* b0;
    Capsule* b1;
    void* b2;
    Sphere* c0;
    Capsule* c1;
    void* c2;
    Sphere* d0;
    Capsule* d1;
    void* d2;
    Sphere* extraA8;
    Sphere* sphere() { return &bounds; }
};

extern "C" {
Sphere fn_801F0A20(const Sphere&, const Sphere&);
Sphere fn_80246E14(const Sphere&, const void*);
}

inline Sphere merge(const Sphere& a, const Capsule& c)
{
    return fn_801F0A20(a, Sphere(c));
}

extern "C" void fn_80246798(Node* self)
{
    Sphere* bounds = self->sphere();
    if (self->a0) *bounds = fn_801F0A20(*bounds, *self->a0);
    if (self->a1) *bounds = fn_801F0A20(*bounds, *self->a1);
    if (self->a2) *bounds = merge(*bounds, *self->a2);
    if (self->a3) *bounds = fn_80246E14(*bounds, self->a3);
    if (self->c0) *bounds = fn_801F0A20(*bounds, *self->c0);
    if (self->c1) *bounds = merge(*bounds, *self->c1);
    if (self->c2) *bounds = fn_80246E14(*bounds, self->c2);
    if (self->b0) *bounds = fn_801F0A20(*bounds, *self->b0);
    if (self->b1) *bounds = merge(*bounds, *self->b1);
    if (self->b2) *bounds = fn_80246E14(*bounds, self->b2);
    if (self->d0) *bounds = fn_801F0A20(*bounds, *self->d0);
    if (self->d1) *bounds = merge(*bounds, *self->d1);
    if (self->d2) *bounds = fn_80246E14(*bounds, self->d2);
    if (self->extraA8) *bounds = fn_801F0A20(*bounds, *self->extraA8);
    if (self->extra70) *bounds = fn_801F0A20(*bounds, *self->extra70);
}
}
#pragma pop

namespace part_8024673C {
extern "C" SphereReturnValue fn_80246E14(const SphereReturnValue& first, const void* matrix)
{
    return fn_801F0A20(first, fn_80246E64(matrix));
}
}

namespace part_80246E64 {
/* fn_80246E64: bounding sphere of a unit-ish box through a matrix:
 * centre = m * (0, 0.5, 0), radius = |m * (1, 0, 1) - centre|.
 * EXACT-MOD-POOL: the 1.0f must be a literal (pool, resolves to
 * lbl_8037B3DC); 0.0f/0.5f are extern 0.0f/0.5f.
 * Load-bearing: the zero test lives in its own inline (fastSqrtOrZero) taking the
 * squared length as a parameter (float r = 0; if (x != r) r = fastSqrt(x)), which
 * keeps the first matrix temp out of f0. Build -O4,p -fp_contract on. */
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
inline float fastSqrtOrZero(float x) { float r = 0.0f; if (x != r) r = fastSqrt(x); return r; }
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    float length() const { float sq = x * x + y * y + z * z; return fastSqrtOrZero(sq); }
};
inline Vec3 operator-(const Vec3& a, const Vec3& b) { return Vec3(a.x - b.x, a.y - b.y, a.z - b.z); }
struct Mtx { float m[4][4]; };
inline Vec3 operator*(const Mtx& m, const Vec3& v) {
    Vec3 r;
    r.x = m.m[0][0] * v.x + m.m[1][0] * v.y + m.m[2][0] * v.z + m.m[3][0];
    r.y = m.m[0][1] * v.x + m.m[1][1] * v.y + m.m[2][1] * v.z + m.m[3][1];
    r.z = m.m[0][2] * v.x + m.m[1][2] * v.y + m.m[2][2] * v.z + m.m[3][2];
    return r;
}
struct Sphere { Vec3 c; float r; };
extern "C" void fn_80246E64(Sphere* out, const Mtx* m)
{
    out->c = *m * Vec3(0.0f, 0.5f, 0.0f);
    out->r = (*m * Vec3(1.0f, 0.0f, 1.0f) - out->c).length();
}
}
