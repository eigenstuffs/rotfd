/* Merged TU .text 0x801E1AC4-0x801E2E04, .sdata2 0x8037A598-0x8037A5B0:
 * viewport_fit_on_object_801E1AC4.cpp, viewport_slots.cpp, scalar_middle_more_801E2370.c,
 * auto_03_801E23A0_text (fn_801E23A0). */
/* ---- shared declarations (objects_owner_internal.h, viewport_storage_internal.h, game_engine.h, viewport_slots_internal.h) ---- */

typedef unsigned long u32;
struct Activable_Z;
struct OwnerList;
struct Entry {
    Activable_Z* object;
    u32 unknown[2];
    signed char generation;
    char pad[3];
    signed char getGeneration() const { return generation; }
};
struct Manager { int count, capacity; Entry* entries; };
struct Cache900_802F149C;struct Cache10_802F1490;struct PlatformResource;struct PlatformPool_80281EA4;struct PlatformItem_802859A8;
struct Globals {
    char unknown0[0x118];
    Manager* manager;
    char unknown11C[0x1C];
    OwnerList* list;
    char unknown13C[0x1C];void*allocation;char unknown15C[0x1C];
    Cache900_802F149C*cache900;Cache10_802F1490*cache10;PlatformResource*resource;PlatformPool_80281EA4*pool;void*unknown188;PlatformItem_802859A8*item;
};
extern "C" {
extern Globals lbl_801E9D24;
extern char lbl_801EF5C8[];
void fn_801F86C8(Manager*, const void*, short);
Activable_Z* fn_801F7EB8(const void*);
void fn_80212AA0(OwnerList*, const void*);
void fn_801EF610(void*, void*);
void fn_80213A18(Activable_Z*);
}
struct Handle_801F7F10 {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct IdentityHandle : Handle_801F7F10 {
    IdentityHandle(const Handle_801F7F10& h) {
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
};
struct OwnerHandle : Handle_801F7F10 {
    OwnerHandle() { value = 0; }
    OwnerHandle(const IdentityHandle& h) {
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    OwnerHandle& operator=(const OwnerHandle& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
    Activable_Z* get() const {
        int index = bits.index;
        Manager* m = lbl_801E9D24.manager;
        int generation = m->entries[index].getGeneration();
        return generation == bits.generation ? m->entries[index].object : 0;
    }
};
struct RootStorage_80207414 { u32 unknown0; Handle_801F7F10 identity; };
struct BaseObject_Z : RootStorage_80207414 {
    BaseObject_Z();
    virtual ~BaseObject_Z();
    virtual void slot0C(u32);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
    const Handle_801F7F10& getIdentity() const { return identity; }
};
struct Activable_Z : BaseObject_Z {
    OwnerHandle prev, next;
    u32 field14;
    signed char field18;
    char pad19[3];
    Activable_Z();
    virtual ~Activable_Z();
    virtual void slot18();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    static void operator delete(void* p) { fn_801EF610(lbl_801EF5C8, p); }
};
struct OwnerList {
    OwnerHandle head, tail;
    void append(const OwnerHandle& h) {
        h.get()->prev = tail;
        if (!fn_801F7EB8(&tail))
            head = h;
        else
            tail.get()->next = h;
        tail = h;
    }
};
typedef char CheckOwnerSize[sizeof(Activable_Z) == 0x1C ? 1 : -1];

struct ViewportHandle1 : Handle_801F7F10 {
    ViewportHandle1() { value = 0; }
    ~ViewportHandle1() {}
};
struct ViewportHandle2 : ViewportHandle1 {
    ViewportHandle2() { value = 0; }
    ~ViewportHandle2() {}
    ViewportHandle2& operator=(const ViewportHandle2& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
};
struct Handle_8002F6B0 : ViewportHandle2 {
    Handle_8002F6B0();
    ~Handle_8002F6B0();
};
struct Vector2_800C3BC4 {
    float x, y;
    Vector2_800C3BC4();
};
struct ViewportEntry_801E2F08 {
    u32 unknown[5];
    ViewportEntry_801E2F08();
};
extern "C" {
void* fn_801EFA1C(void*, u32, const char*, const char*, int, int);
extern const char lbl_802ACEAC[], lbl_802ACEBC[];
}
struct ViewportRecord_801E2EA8 {
    Vector2_800C3BC4 points[16];
    ViewportEntry_801E2F08 entries[16];
    u32 unknown1C0;
    ViewportRecord_801E2EA8();
    static void* operator new[](u32 size) {
        return fn_801EFA1C(lbl_801EF5C8, size, lbl_802ACEAC, lbl_802ACEBC, 33, 4);
    }
    static void operator delete[](void* p) { fn_801EF610(lbl_801EF5C8, p); }
};
struct Viewport_801E300C {
    int left, top, right, bottom;
    ViewportHandle2 handle10, handle14;
    u32 unknown18[2];
    ViewportRecord_801E2EA8* records;
    u32 unknown24;
    Handle_8002F6B0 handles[8];
    u32 field48;
    Viewport_801E300C();
    ~Viewport_801E300C();
    static void operator delete(void* p) { fn_801EF610(lbl_801EF5C8, p); }
};
typedef char CheckViewportSize[sizeof(Viewport_801E300C)==0x4C?1:-1];
typedef char CheckViewportRecordSize[sizeof(ViewportRecord_801E2EA8)==0x1C4?1:-1];

struct EngineBase { unsigned char prefix[0x278]; };
/* Unknown virtual declarations preserve the observed notify slot at 0xAC.
 * These are layout placeholders, not reconstructed function bodies. */
struct Engine : EngineBase {
    virtual void unknown_00();
    virtual void unknown_01();
    virtual void unknown_02();
    virtual void unknown_03();
    virtual void unknown_04();
    virtual void unknown_05();
    virtual void unknown_06();
    virtual void unknown_07();
    virtual void unknown_08();
    virtual void unknown_09();
    virtual void unknown_10();
    virtual void unknown_11();
    virtual void unknown_12();
    virtual void unknown_13();
    virtual void unknown_14();
    virtual void unknown_15();
    virtual void unknown_16();
    virtual void unknown_17();
    virtual void unknown_18();
    virtual void unknown_19();
    virtual void unknown_20();
    virtual void unknown_21();
    virtual void unknown_22();
    virtual void unknown_23();
    virtual void unknown_24();
    virtual void unknown_25();
    virtual void unknown_26();
    virtual void unknown_27();
    virtual void unknown_28();
    virtual void unknown_29();
    virtual void unknown_30();
    virtual void unknown_31();
    virtual void unknown_32();
    virtual void unknown_33();
    virtual void unknown_34();
    virtual void unknown_35();
    virtual void unknown_36();
    virtual void unknown_37();
    virtual void unknown_38();
    virtual void unknown_39();
    virtual void unknown_40();
    virtual void notify(int);
    virtual void set_rectangle(int, int, int, int);
};

struct ViewportSlotsView;
struct ViewportRenderObject : Activable_Z {
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40(ViewportSlotsView*);
};
struct ViewportSlotHandle : ViewportHandle2 {
    ViewportSlotHandle() { value = 0; }
    ~ViewportSlotHandle() {}
    ViewportSlotHandle(const ViewportSlotHandle& h) {
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    ViewportSlotHandle& operator=(const ViewportSlotHandle& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
    ViewportRenderObject* get() const {
        int index = bits.index;
        Manager* m = lbl_801E9D24.manager;
        int generation = m->entries[index].getGeneration();
        return generation == bits.generation ? (ViewportRenderObject*)m->entries[index].object : 0;
    }
};
struct ViewportSlotsView {
    int bounds[4];
    OwnerHandle world;
    ViewportHandle2 camera;
    float horizontal, vertical;
    ViewportRecord_801E2EA8* records;
    int recordCount;
    ViewportSlotHandle slots[8];
    Engine* engine;
};
struct ViewportContext { ViewportSlotsView* viewport; };
extern "C" void fn_801E8274(Activable_Z*, ViewportContext*);

/* ---- fn_801E1AC4 (viewport_fit_on_object_801E1AC4.cpp) ---- */
namespace fit_on_object {
/* Viewport FitOnObject: finds the named child of the viewport's scene root
 * (handle +0x10), takes its world bounding sphere (local sphere of the bound
 * object, transformed by fn_80099A00) and moves the camera (handle +0x14) along
 * its current view direction so that it sits lbl_8037A59C + radius in front of
 * the sphere centre (fn_8023D100).  "Object Not Found..." is logged otherwise. */
typedef unsigned long Word;
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Console;
struct Context{char unknown00[0x110];Console*console;char unknown114[4];Manager*manager;};
struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&v){x=v.x;y=v.y;z=v.z;}Vec3(float ax,float ay,float az){x=ax;y=ay;z=az;}
 void operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;}
 Vec3 operator-(const Vec3&v)const{return Vec3(x-v.x,y-v.y,z-v.z);}
 Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
 void operator*=(float s){x*=s;y*=s;z*=s;}
 float lengthSquared()const{return x*x+y*y+z*z;}};
extern "C"{
extern Context lbl_801E9D24;
extern const Vec3 game_vec4_zero;
extern const char lbl_802ACE98[];
void fn_801F86C8(Manager*,const void*,int);
void*fn_801F7EB8(const Handle_801F7F10*);
void fn_801FA014(Console*,const char*,...);
}
struct Sphere{Vec3 point;float radius;Sphere():point(game_vec4_zero),radius(1.0f){}
 void operator=(const Sphere&s){point=s.point;radius=s.radius;}};
template<class T>inline T*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.generation)return (T*)m->entries[index].object;return 0;}
struct Zero1:Handle_801F7F10{Zero1(){value=0;}~Zero1(){}};
struct Ref:Zero1{
 Ref(){value=0;}
 Ref(const Ref&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 Ref(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 ~Ref(){}
};
struct Child:Ref{
 Child(){value=0;}
 Child(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 ~Child(){}
};
struct Name{Word word;};
struct Matrix;
struct Bounds{char unknown00[0xC];Sphere sphere;};
struct Object{char unknown00[0x1C];Handle_801F7F10 bounds;char unknown20[0x104];Matrix*matrix;};
struct Target{char unknown00[0x124];Vec3 position;};
struct Camera{char unknown00[0x1C];Handle_801F7F10 target;char unknown20[0x98];Vec3 position;};
struct Root;
struct Viewport{char unknown00[0x10];Handle_801F7F10 root,camera;};
extern "C"{Ref fn_8026A494(Root*,const Name&);Sphere fn_80099A00(const Matrix*,const Sphere*);void fn_8023D100(Camera*,const Vec3*);}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
extern "C" void fn_801E1AC4(Viewport*self,Name name){
 if(!fn_801F7EB8(&self->camera))return;
 if(!fn_801F7EB8(&self->root))return;
 Ref object(fn_8026A494(resolve<Root>(self->root),name));
 if(!fn_801F7EB8(&object)){fn_801FA014(lbl_801E9D24.console,lbl_802ACE98);return;}
 Sphere sphere;
 if(fn_801F7EB8(&resolve<Object>(object)->bounds))sphere=resolve<Bounds>(resolve<Object>(object)->bounds)->sphere;
 sphere=fn_80099A00(resolve<Object>(object)->matrix,&sphere);
 Target*target=resolve<Target>(Child(resolve<Camera>(self->camera)->target));
 Camera*camera=resolve<Camera>(self->camera);
 float tx=target->position.x,ty=target->position.y,tz=target->position.z;
 Vec3 direction(tx-camera->position.x,ty-camera->position.y,tz-camera->position.z);
 float inverse=reciprocalSqrt(direction.lengthSquared());
 float distance=2.5f+sphere.radius;
 direction*=inverse;
 Vec3 position=sphere.point-direction*distance;
 fn_8023D100(resolve<Camera>(self->camera),&position);
}
struct Flush1; /* emit fn_801E1AC4 before the viewport_slots functions */
}

/* ---- fn_801E1F3C, fn_801E2074, fn_801E2220 (viewport_slots.cpp) ---- */
// Viewport reference slots and render dispatch.
extern "C" void fn_801E1F3C(ViewportSlotsView* self, const ViewportSlotHandle& handle) {
    for (int i = 0; i < 8; ++i) {
        ViewportRenderObject* object = self->slots[i].get();
        if (object == handle.get()) {
            self->slots[i] = ViewportSlotHandle();
            break;
        }
    }
}

extern "C" void fn_801E2074(ViewportSlotsView* self, const ViewportSlotHandle& handle, signed char priority) {
    if (priority) {
        if (!fn_801F7EB8(&self->slots[7])) {
            self->slots[7] = handle;
        } else {
            ViewportSlotHandle previous(self->slots[7]);
            for (int i = 6; i >= 0; --i) {
                if (!fn_801F7EB8(&self->slots[i])) {
                    self->slots[i] = previous;
                    break;
                }
            }
            self->slots[7] = handle;
        }
    } else {
        for (int i = 0; i < 8; ++i) {
            if (!fn_801F7EB8(&self->slots[i])) {
                self->slots[i] = handle;
                break;
            }
        }
    }
}


extern "C" void fn_801E2220(ViewportSlotsView* self, ViewportContext* context) {
    self->recordCount = 0;
    context->viewport = self;
    Activable_Z* world = self->world.get();
    if (world && fn_801F7EB8(&self->camera)) {
        fn_801E8274(world, context);
    }
    self->engine->unknown_27();
    for (int i = 0; i < 8; ++i) {
        ViewportRenderObject* object = self->slots[i].get();
        if (object) {
            object->slot40(self);
            self->engine->unknown_27();
        }
    }
}


/* ---- fn_801E2370 (scalar_middle_more_801E2370.c) ---- */
namespace scalar_801E2370 {
extern "C" void *fn_8026C028(void *,void *,void *,void *);
extern "C" void *fn_801E2370(void *unused,void *a,void *b,void *c,void *d) {return fn_8026C028(b,c,a,d);}
}

/* ---- fn_801E23A0 (auto_03_801E23A0_text) ---- */
namespace frustum_801E23A0 {
/* fn_801E23A0: viewport frustum update (auto_03_801E23A0_text, GC/1.3.2 -O4,p -fp_contract on).
 * Resolves the camera (handle +0x14) and its lens node (camera +0x1C), derives the
 * projection depth/aspect, builds the four view-space corner rays, stores the four
 * side-plane normals (SoA: nx[4], ny[4], nz[4] at lens+0x74), transforms the eight
 * near/far corners by the camera matrix and fits the bounding sphere (centre +
 * squared radius) around them (inlined twin of fn_801F0C68).
 *
 * STATUS: exact inside this merged TU (standalone it was EXACT-MOD-POOL). Pooled literals:
 * 1.0f (lbl_8037A598, first used by fn_801E1AC4), 2.0f (lbl_8037A5A0), 0.5f (lbl_8037A5A4,
 * from "/ 2.0f") and the int->float bias (lbl_8037A5A8).
 *
 * Notes on the shape (all driven by MWCC's FPR colouring order / block cut):
 *  - MWCC starts a new basic block once a block has more than ~100 initial PCode
 *    instructions (checked before each expression statement). The original splits
 *    right after the third cross product; the d0/e0 copies of the first two rays
 *    (copy-propagated away later) and the copy inside normalize2() keep the count.
 *  - n0, n1, n3 are computed in place (raw and normalised components share one
 *    vreg); n2 keeps x,y in place but z through a separate copy (Vec3B's y,z,x copy
 *    ctor lets the frontend propagate x and y); crossL keeps the raw components in
 *    inline temporaries so n2.z (raw) is numbered above n1.x.
 *  - member assignment order of n0/n1 (x,y,z) and the declaration order of the
 *    scaledM locals for q0 set the vreg numbering the original colouring needs.
 */
#pragma inline_max_size(100000)
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Context{char unknown00[0x118];Manager*manager;};
extern "C"{
extern Context lbl_801E9D24;

extern float lbl_80377FA8;
float fn_80284E34(float);
float fn_800AA52C(float, float); /* max */
float fn_800AA53C(float, float); /* min */
}
template<class T>inline T*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return (T*)m->entries[index].object;return 0;}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3 scaledM(float s) const { float az, ay, ax; ax = x * s; ay = y * s; az = z * s; return Vec3(ax, ay, az); }
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 operator/(float s) const { return Vec3(x / s, y / s, z / s); }
    void setCross(const Vec3& a, const Vec3& v) { z = a.x * v.y - a.y * v.x; y = a.z * v.x - a.x * v.z; x = a.y * v.z - a.z * v.y; }
    float dot() const { return x * x + y * y + z * z; }
    void normalize() { float s = reciprocalSqrt(dot()); x *= s; y *= s; z *= s; }
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
struct Sphere {
    Vec3 center;
    float radius;
};
struct Frustum {
    float nx[4], ny[4], nz[4];
    Sphere bounds;
    float nearZ, farZ;
    Vec3 corners[8];
};
struct Lens { char unknown00[0x74]; Frustum frustum; float fov; };
struct Camera { char unknown00[0x1C]; Handle_801F7F10 lens; char unknown20[0x104]; Matrix* matrix; };
struct Screen { char unknown00[0x218]; int width, height; };
struct Viewport {
    char unknown00[8];
    int width, height;
    Handle_801F7F10 root, camera;
    float depth, aspect;
    char unknown20[0x28];
    Screen* screen;
};

inline void normalize2(Vec3& v) { Vec3 t; t = v; float s = reciprocalSqrt(t.dot()); v.x *= s; v.y *= s; v.z *= s; }
inline void setCrossF(Vec3& n, const Vec3& a, const Vec3& v) { n.x = a.y * v.z - a.z * v.y; n.y = a.z * v.x - a.x * v.z; n.z = a.x * v.y - a.y * v.x; }
struct Vec3B : Vec3 { Vec3B(const Vec3& o) { y = o.y; z = o.z; x = o.x; } };
inline Vec3 crossL(const Vec3& a, const Vec3& v) { float rz = a.x * v.y - a.y * v.x; float ry = a.z * v.x - a.x * v.z; float rx = a.y * v.z - a.z * v.y; return Vec3(rx, ry, rz); }

#define MATRIX resolve<Camera>(self->camera)->matrix
extern "C" void fn_801E23A0(Viewport* self)
{
    Camera* camera = resolve<Camera>(self->camera);
    if (camera) {
        Lens* lens = resolve<Lens>(camera->lens);
        int w = self->screen->width;
        int h = self->screen->height;
        self->depth = (float)self->width / (2.0f * fn_80284E34(lens->fov / 2.0f));
        float ratio = (float)h / (float)w;
        self->aspect = ratio * lbl_80377FA8;
        float x = (float)self->width / 2.0f;
        float y = (float)self->height / (2.0f * self->aspect);

        Vec3 p0(-x, y, self->depth);
        Vec3 p1(p0.x, -y, self->depth);
        Vec3 p2(x, -y, self->depth);
        Vec3 p3(x, y, self->depth);
        Vec3 d0; d0 = p0;
        Vec3 e0; e0 = p1;
        Vec3 n0; setCrossF(n0, d0, e0);
        normalize2(n0);
        Vec3 n1; setCrossF(n1, p1, p2);
        normalize2(n1);
        Vec3B n2 = crossL(p2, p3);
        n2.normalize();
        Vec3 n3; n3.setCross(p3, p0);
        n3.normalize();
        Frustum* f = &lens->frustum;
        f->nx[0] = n0.x; f->nx[1] = n1.x; f->nx[2] = n2.x; f->nx[3] = n3.x;
        f->ny[0] = n0.y; f->ny[1] = n1.y; f->ny[2] = n2.y; f->ny[3] = n3.y;
        f->nz[0] = n0.z; f->nz[1] = n1.z; f->nz[2] = n2.z; f->nz[3] = n3.z;
        Vec3 q0 = p0.scaledM(1.0f / p0.z);
        Vec3 q1 = p1 * (1.0f / p1.z);
        Vec3 q2 = p2 * (1.0f / p2.z);
        Vec3 q3 = p3 * (1.0f / p3.z);
        f->corners[0] = MATRIX->transform(q0 * f->nearZ);
        f->corners[4] = MATRIX->transform(q0 * f->farZ);
        f->corners[1] = MATRIX->transform(q1 * f->nearZ);
        f->corners[5] = MATRIX->transform(q1 * f->farZ);
        f->corners[2] = MATRIX->transform(q2 * f->nearZ);
        f->corners[6] = MATRIX->transform(q2 * f->farZ);
        f->corners[3] = MATRIX->transform(q3 * f->nearZ);
        f->corners[7] = MATRIX->transform(q3 * f->farZ);
        Vec3 high;
        Vec3 low = f->corners[0];
        high = low;
        int i;
        for (i = 1; i < 8; i++) {
            low.x = fn_800AA53C(low.x, f->corners[i].x);
            low.y = fn_800AA53C(low.y, f->corners[i].y);
            low.z = fn_800AA53C(low.z, f->corners[i].z);
            high.x = fn_800AA52C(high.x, f->corners[i].x);
            high.y = fn_800AA52C(high.y, f->corners[i].y);
            high.z = fn_800AA52C(high.z, f->corners[i].z);
        }
        f->bounds.center = (high + low) / 2.0f;
        f->bounds.radius = (f->bounds.center - f->corners[0]).dot();
        for (i = 1; i < 8; i++) {
            f->bounds.radius = fn_800AA52C(f->bounds.radius, (f->bounds.center - f->corners[i]).dot());
        }
    }
}
}
