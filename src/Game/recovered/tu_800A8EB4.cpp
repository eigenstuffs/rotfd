/* Merged TU: .text 0x800A8EB4-0x800AA554, extab 0x80010ABC-0x80010B3C,
   extabindex 0x8001BB88-0x8001BC00, .sdata2 0x80379000-0x8037902C.
   GC/1.3.2 -O4,s -Cpp_exceptions on -RTTI off -fp_contract on. */
extern "C" float fn_800AA52C(float, float);
extern "C" float fn_800AA53C(float, float);
extern "C" void __dt__15Object_800A8F90Fv();
extern "C" { extern char lbl_801EF5C8[]; void fn_801EF610(void*, void*); }
namespace p93d8 { struct Contact; }
struct Object_8007A280 {
    unsigned long storage[0xA00];
    int count;
    Object_8007A280() : count(0) {}
    ~Object_8007A280() { for (int i = 0; i < count; ++i) {} }
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
    p93d8::Contact* data() { return (p93d8::Contact*)storage; }
};
namespace p8eb4 {
/* Original engine vector and scalar initialization with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-vector-setup.md. */
extern "C" {
    void __ct__15Object_8009A9D8Fv(void*);
    extern char lbl_802BCB24[];
    extern float game_vec3_zero[3];
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x138];
    float field144;
    float field148;
    float field14C;
    char unknown150[0xC];
    float field15C;
    float field160;
    float field164;
    char unknown168[0x50];
    float field1B8;
    float field1BC;
    float field1C0;
    char unknown1C4[0x154];
    void* field318;
    char unknown31C[0x28];
    unsigned int field344;
    char unknown348[0x48];
    float field390;
    float field394;
    float field398;
    float field39C;
    float field3A0;
    float field3A4;
    float field3A8;
    float field3AC;
};

extern "C" View* fn_800A8EB4(View* self) {
    __ct__15Object_8009A9D8Fv(self);
    self->field08 = lbl_802BCB24;
    self->field318 = lbl_802BCB24 + 0x170;
    self->field390 = game_vec3_zero[0];
    self->field394 = game_vec3_zero[1];
    self->field398 = game_vec3_zero[2];
    self->field39C = 0.0f;
    self->field3A0 = 1.0f;
    self->field3A4 = game_vec3_zero[0];
    self->field3A8 = game_vec3_zero[1];
    self->field3AC = game_vec3_zero[2];
    self->field344 = 0;
    self->field144 = game_vec3_zero[0];
    self->field148 = game_vec3_zero[1];
    self->field14C = game_vec3_zero[2];
    self->field15C = game_vec3_zero[0];
    self->field160 = game_vec3_zero[1];
    self->field164 = game_vec3_zero[2];
    self->field1B8 = game_vec3_zero[0];
    self->field1BC = game_vec3_zero[1];
    self->field1C0 = game_vec3_zero[2];
    return self;
}

}
/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-small-eh.md. */
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
struct Handle_801F7F10 {
    u32 word;
    ~Handle_801F7F10();
};
struct H1:Handle_801F7F10 {
};
struct H2:H1 {
};
struct H3:H2 {
};
struct H4:H3 {
};
extern "C" char lbl_802BCB24[];
struct Object_8009AA98 {
    u32 unknown00[2];
    void*vtable;
    char unknown0C[0x318-0xC];
    void*secondaryVtable;
    char unknown31C[0x344-0x31C];
    u32 unknown344,unknown348;
    ~Object_8009AA98();
};
struct Object_800A8F90:Object_8009AA98 {
    ~Object_800A8F90();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800A8F90::~Object_800A8F90() {
    vtable=lbl_802BCB24;
    secondaryVtable=lbl_802BCB24+0x170;
    unknown344=0;
}

namespace p901c {
extern "C" void fn_8009AB58(void*);
extern "C" void fn_800A901C(void* self){fn_8009AB58(self);}

}
namespace p903c {
extern "C" void fn_8009BEE8(void*);
extern "C" void fn_800A903C(void* self){fn_8009BEE8(self);}

}
namespace p905c {
/* Actor frame update (fn_800A905C): unless the actor's own resource (handle
 * from virtual slot 0x9C) has property bit 0x10000 set, saves velocity
 * (+0x144) as previous velocity (+0x15C), clears velocity, runs
 * fn_8009B50C and the update virtual (slot 0x198), clears the force
 * accumulator (+0x358) and forwards the velocity to the actor's resource
 * (+0x24 handle, slot 0xB4). Always finishes with fn_80222E44(self, delta).
 * Matching note: the entry-pointer resolve form (as in
 * early_owner_position_transfer_views.h) gives the original context/self/zero
 * callee-saved register assignment (r31/r30/r29). */
typedef unsigned long Word;
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return*this;}};
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Prefix{Word unknown00,unknown04;};
struct Resource:Prefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40();virtual void v44();virtual void v48();virtual void v4C();virtual void v50();virtual void v54();virtual void v58();virtual void v5C();virtual void v60();virtual void v64();virtual void v68();virtual void v6C();virtual void v70();virtual void v74();virtual void v78();virtual void v7C();virtual void v80();virtual void v84();virtual void v88();virtual void v8C();virtual void v90();virtual void v94();virtual void v98();virtual void v9C();virtual void vA0();virtual void vA4();virtual void vA8();virtual void vAC();virtual void vB0();
 virtual void setVelocity(const Vec3&);
 char unknown0C[0x114];unsigned long property;};
struct Entry{Resource*object;char unknown04[8];signed char tag;char pad[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline Resource*resolve(const Handle&h){Entry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
struct Actor:Prefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40();virtual void v44();virtual void v48();virtual void v4C();virtual void v50();virtual void v54();virtual void v58();virtual void v5C();virtual void v60();virtual void v64();virtual void v68();virtual void v6C();virtual void v70();virtual void v74();virtual void v78();virtual void v7C();virtual void v80();virtual void v84();virtual void v88();virtual void v8C();virtual void v90();virtual void v94();virtual void v98();
 virtual const Handle*getHandle(int);
 virtual void vA0();virtual void vA4();virtual void vA8();virtual void vAC();virtual void vB0();virtual void vB4();virtual void vB8();virtual void vBC();virtual void vC0();virtual void vC4();virtual void vC8();virtual void vCC();virtual void vD0();virtual void vD4();virtual void vD8();virtual void vDC();virtual void vE0();virtual void vE4();virtual void vE8();virtual void vEC();virtual void vF0();virtual void vF4();virtual void vF8();virtual void vFC();virtual void v100();virtual void v104();virtual void v108();virtual void v10C();virtual void v110();virtual void v114();virtual void v118();virtual void v11C();virtual void v120();virtual void v124();virtual void v128();virtual void v12C();virtual void v130();virtual void v134();virtual void v138();virtual void v13C();virtual void v140();virtual void v144();virtual void v148();virtual void v14C();virtual void v150();virtual void v154();virtual void v158();virtual void v15C();virtual void v160();virtual void v164();virtual void v168();virtual void v16C();virtual void v170();virtual void v174();virtual void v178();virtual void v17C();virtual void v180();virtual void v184();virtual void v188();virtual void v18C();virtual void v190();virtual void v194();
 virtual void update(float);
 char unknown0C[0x18];Handle resource;char unknown28[0x11C];Vec3 velocity;char unknown150[0xC];Vec3 previousVelocity;
 char unknown168[0x1F0];Vec3 force;};
extern "C" {extern const Vec3 game_vec3_zero;void fn_8009B50C(Actor*);void fn_80222E44(Actor*,float);}
extern "C" void fn_800A905C(Actor*self,float delta){
 if(!(resolve(*self->getHandle(0))->property&0x10000)){
  self->previousVelocity=self->velocity;
  self->velocity=game_vec3_zero;
  fn_8009B50C(self);
  self->update(delta);
  self->force=game_vec3_zero;
  resolve(self->resource)->setVelocity(self->velocity);
 }
 fn_80222E44(self,delta);
}

}
namespace p91d4 {
/* fn_800A91D4: spins the actor about the axis perpendicular to its angular
   velocity (+0x15C) and the up axis lbl_802F4148. Unless the resolved node of
   the slot 0x9C handle has property bit 0x10000, the normalized spin vector is
   crossed with the up axis, the spin speed times delta advances the stored
   angle (+0x39C, wrapped once at 2*pi), and the half-angle rotation about the
   cross axis goes to the actor's facing slot 0xC0; otherwise slot 0xBC is
   called with the target and 0.

   Matching notes: 0.0f, 2*pi and 0.5f (angle/2) are pooled literals of this TU
   (.sdata2 +0x0, +0x8, +0xC). The spin length is read
   through a reference so its loads are not merged with the normalized copy
   (and stay unfused, as for memory operands). */
inline float fastSqrt(register float x){register float r;asm{frsqrte f4,x
 fres r,f4}return r;}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
typedef unsigned long Word;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Vec3{
 float x,y,z;
 Vec3(){}
 Vec3(float a,float b,float c):x(a),y(b),z(c){}
 float lengthSquared()const{return x*x+y*y+z*z;}
 float length()const{float sq=lengthSquared();float r=0.0f;if(sq!=r)r=fastSqrt(sq);return r;}
 void normalize(){if(0.0f!=lengthSquared()){float inv=reciprocalSqrt(lengthSquared());x*=inv;y*=inv;z*=inv;}}
 Vec3 normalized()const{Vec3 r=*this;r.normalize();return r;}
 Vec3 cross(const Vec3&b)const{return Vec3(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);}
};
extern "C" const Vec3 lbl_802F4148; /* up axis */
extern "C"{float fn_8028506C(float);float fn_80284FA8(float);}
struct Rotation{
 float w,x,y,z;
 Rotation(){}
 Rotation(float ax,float ay,float az,float half){w=fn_8028506C(half);float s=fn_80284FA8(half);x=ax*s;y=ay*s;z=az*s;}
};
struct Resource{char unknown00[0x120];unsigned long property;};
struct Entry{Resource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline Resource*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Prefix{char unknown00[8];};
struct Actor:Prefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
 virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
 virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();
 virtual const Handle*getHandle(int);
 virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();
 virtual void clearFacing(const Vec3&,int);
 virtual void setFacing(const Vec3&,const Rotation*,int);
 char unknown0C[0x15C-0xC];Vec3 spin;char unknown168[0x39C-0x168];float angle;
};
extern "C" void fn_800A91D4(Actor*self,void*unused,const Vec3&target,float delta){
 if(!(resolve(*self->getHandle(0))->property&0x10000)){
  Vec3 axis=self->spin.normalized();
  Vec3 c=lbl_802F4148.cross(axis);
  {const Vec3&s=self->spin;float l=s.length();self->angle+=l*delta;}
  if(self->angle>6.2831855f)self->angle=self->angle-6.2831855f;
  Rotation r(c.x,c.y,c.z,self->angle/2.0f);
  self->setFacing(target,&r,0);
 }else{
  self->clearFacing(target,0);
 }
}

}
namespace p93d8 {
/* fn_800A93D8: actor ground/sphere collision step (draft).
   GC/1.3.2 -O4,s -Cpp_exceptions on -fp_contract on. */
typedef unsigned long Word;
typedef unsigned long long Flags;
extern "C" {
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
double fabs(double);
}
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
inline float absf(float x) { return __fabs(x); }
inline float sqz(register float sq)
{
    register float r = 0.0f;
    if (sq != r) {
        asm { frsqrte f4, sq
              fres r, f4 }
    }
    return r;
}
inline bool pairEqual(float x, float y) { bool result = false; if ((float)__fabs(x) < 0.000001f) { if ((float)__fabs(y) < 0.000001f) result = true; } return result; }
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator-(const Vec3& v) const { Vec3 r; r.x = x - v.x; r.y = y - v.y; r.z = z - v.z; return r; }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3& operator+=(const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
    Vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    float lengthSq() const { return x * x + y * y + z * z; }
    float length() const
    {
        float sq = lengthSq();
        float r = 0.0f;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    float lengthNC() const
    {
        float xx = x * x;
        float yy = y * y;
        float zz = z * z;
        float sq = xx + yy + zz;
        float r = 0.0f;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    signed char isSmall() const { signed char result = 0; if (pairEqual(x, y) && (float)__fabs(z) < 0.000001f) result = 1; return result; }
    signed char isNear(const Vec3& v) const { float ex = x - v.x; float ey = y - v.y; float ez = z - v.z; return Vec3(ex, ey, ez).isSmall(); }
};
extern "C" Vec3 game_vec3_zero;
inline float length2(float x, float z)
{
    float sq = x * x + z * z;
    float r = 0.0f;
    if (sq != r) r = fastSqrt(sq);
    return r;
}
struct Sphere {
    Vec3 c;
    float r;
    Sphere(const Vec3& cc, float rr) : c(cc), r(rr) {}
};
struct Shape {
    Sphere spheres[10];
    int count;
};
struct Ray {
    Vec3 origin;
    float length;
    Vec3 direction;
    float unknown1C;
    Ray() {}
    Ray(const Vec3& o, const Vec3& d, float l) { origin = o; direction = d; length = l; }
};
struct Contact {
    Vec3 point;
    float t;
    Vec3 normal;
    char unknown1C[0xC];
};
struct Handle { signed int tag : 8, index : 24; };
struct Node { char unknown00[0x120]; bool has(Word f) const { return (flags & f) != 0; } Word get() const { return flags; } union { Word flags; struct { Word pad0 : 13; Word bit18 : 1; Word pad1 : 18; } bits; }; };
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct Manager { int count, capacity; Entry* entries; };
extern "C" struct Global { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;
inline Node* resolve(const Handle& h)
{
    Entry* e = &lbl_801E9D24.manager->entries[h.index];
    if (e->tag == h.tag) return e->object;
    return 0;
}
struct World;
struct Prefix { char unknown00[8]; };
struct Owner : Prefix {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58();
    virtual signed char onGround(Contact*, Vec3*, int);
    virtual void onContact(Contact*, Vec3*, int);
    virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74();
    virtual void slot78(); virtual void slot7C(); virtual void slot80(); virtual void slot84();
    virtual void slot88(); virtual void slot8C(); virtual void slot90(); virtual void slot94();
    virtual void slot98();
    virtual const Handle* getHandle(int);
    char unknown0C[0x30 - 0xC];
    Flags flags;
    char unknown38[0x1B8 - 0x38];
    Vec3 ground1B8;
    char unknown1C4[0x3A4 - 0x1C4];
    Vec3 wall3A4;
};
struct Camera { char unknown00[0x58]; Handle h58; };
extern "C" {
Camera* fn_8005E9A0();
signed char fn_80269818(World*, const Ray&, Contact*, Flags, Flags);
signed char fn_80268918(World*, const Sphere*, Object_8007A280*, Flags, Flags);
}

inline float neg(float a) { return -a; }
struct FBox { float v; };

struct Scalar { float v; Scalar() {} };
extern "C" signed char fn_800A93D8(Owner* self, World* world, const Vec3* pos, const Vec3* vel,
                                   Shape* shape, Contact* hit, Vec3* out)
{
    signed char result = 0;
    if (!(resolve(*self->getHandle(0))->flags & 0x10000)) {
    Object_8007A280 contacts;
    float radius;
    float margin;
    float top;
    float ox;
    float oy;
    float oz;
    Vec3 wall;
    Scalar lim;
    Vec3 push;
    float depth;
    float vx = vel->x;
    float vy = vel->y;
    float vz = vel->z;
    Flags sphInclude = 0x0002000000000002ULL;
    Flags sphExclude = 8ULL;
    Flags segInclude = 2ULL;
    Flags segExclude = 0x0000000400000008ULL;
    if (self->flags & 0x1000000000ULL) margin = 0.1f; else margin = 0.0f;
    if (self->flags & 0x800ULL) sphInclude |= 0x0000000400000002ULL;
    if (self->flags & 0x200ULL) {
        sphInclude |= 0x00008E0000000000ULL;
        segInclude |= 0x00008E0000000002ULL;
    } else {
        sphExclude |= 0x0000F00000000008ULL;
        segExclude |= 0x0000F00000000008ULL;
    }
    ox = shape->spheres[0].c.x;
    oy = shape->spheres[0].c.y;
    oz = shape->spheres[0].c.z;
    radius = shape->spheres[0].r;
    top = oy;
    if (top < radius) top = radius;
    if (vy <= 0.0f
        && fn_80269818(world, Ray(*pos + Vec3(ox, oy, oz), Vec3(0.0f, -1.0f, 0.0f), (top + margin) - vy), hit, segInclude, segExclude)) {
        float speed = sqz(vx * vx + vz * vz);
        const Vec3& p = hit->point;
        float zero = 0.0f;
        float qz = p.z + vz;
        float qy = p.y + zero;
        float qx = p.x + vx;
        Vec3 q(qx, qy, qz);
        float dq = hit->normal.dot(q);
        float d = -hit->normal.dot(p);
        float t = -((d + dq) / hit->normal.y);
        Vec3 proj = Vec3(0.0f, 1.0f, 0.0f) * t + q;
        Vec3 slide = proj - p;
        float len = sqz(slide.lengthSq());
        Vec3 move;
        if (len < 0.000001f) move = game_vec3_zero;
        else move = (slide * (1.0f / len)) * speed;
        hit->point.x -= ox;
        hit->point.z -= oz;
        if (!move.isNear(game_vec3_zero)) {
            move = move - (*pos - hit->point);
            move.y += radius;
        }
        *out = *pos + move;
        if (self->flags & 0x1000000000ULL) self->flags |= 0x4000000000ULL;
        if (self->onGround(hit, out, 0)) {
            self->flags |= 0x40000000000ULL;
            self->flags |= 0x8000000000ULL;
        }
    } else {
        *out = *pos + *vel;
    }
    wall = game_vec3_zero;
    lim.v = 0.0f;
    push.x = 0.0f;
    FBox bx;
    bx.v = *(const float*)&game_vec3_zero.x;
    push.x = bx.v;
    push.y = game_vec3_zero.y;
    push.z = game_vec3_zero.z;
    depth = 0.0f;
    wall = push;
    Node* node = resolve(fn_8005E9A0()->h58);
    bool saved = (node->get() & 0x40000) != 0;
    node->flags &= ~0x40000;
    float k = 0.707f;
    lim.v = -k;
    for (int i = 0; i < shape->count; i++) {
        Sphere s(shape->spheres[i].c + *out, shape->spheres[i].r);
        if (fn_80268918(world, &s, &contacts, sphInclude, sphExclude)) {
            result = 1;
            int n = contacts.count;
            Contact* c = contacts.data();
            for (int j = 0; j < n; j++, c++) {
                self->onContact(c, out, 0);
                c->normal.y = fn_800AA53C(c->normal.y, 0.0f);
                float len = c->normal.lengthNC();
                if (len > 0.000001f) {
                    float inv = 1.0f / len;
                    c->normal *= inv;
                    depth = fn_800AA52C(depth, shape->spheres[i].r - c->t);
                    push += c->normal * (shape->spheres[i].r - c->t);
                    if (c->normal.y < lim.v) {
                        self->flags |= 0x10000000000ULL;
                    } else {
                        self->flags |= 0x100000000000ULL;
                        wall += c->normal * (shape->spheres[i].r - c->t);
                    }
                }
            }
        }
    }
    if ((int)saved == 1) node->flags |= 0x40000;
    if (result) {
        float len = push.length();
        if (len > 0.000001f) {
            push *= 1.0f / len;
            *out += push * depth;
        }
        if (self->flags & 0x100000000000ULL) {
            float wlen = wall.length();
            if (wlen > 0.000001f) {
                wall *= 1.0f / wlen;
                FBox in;
                FBox iv;
                in.v = 0.0f;
                iv.v = 0.0f;
                Vec3 flatN = wall;
                flatN.y = 0.0f;
                Vec3 flatV = *vel;
                flatV.y = 0.0f;
                float ln = flatN.length();
                float lv = flatV.length();
                if (ln > 0.000001f && lv > 0.000001f) {
                    in.v = 1.0f / ln;
                    iv.v = 1.0f / lv;
                    flatN *= in.v;
                    flatV *= iv.v;
                    if (flatN.dot(flatV) <= -1.0f) {
                        self->flags |= 0x20000000000ULL;
                        self->wall3A4 = flatN;
                    }
                }
            }
        }
    }
    if (fn_80269818(world, Ray(*out + Vec3(ox, oy, oz), Vec3(0.0f, -1.0f, 0.0f), 0.0001f + (top + margin)), hit, segInclude, segExclude)) {
        hit->point.x -= ox;
        hit->point.z -= oz;
        *out = hit->point;
        out->y = hit->point.y + radius;
        if (self->flags & 0x1000000000ULL) self->flags |= 0x4000000000ULL;
        if (self->onGround(hit, out, 0)) {
            self->flags |= 0x40000000000ULL;
            self->flags |= 0x8000000000ULL;
            self->ground1B8 = hit->normal;
        }
    }
    }
    return result;
}

}
namespace p9fa0 {
/* Actor movement step (fn_800A9FA0). Resolves the handle from virtual slot
 * 0x9C; when the resolved object's word at +0x120 has bit 0x10000 set the
 * velocity (+0x144) is reset to game_vec3_zero. The 64-bit flags at +0x30 are
 * masked with 0x1000003FFFFFFE3F, next = position + velocity * delta and
 * direction = the local z axis transformed by the basis at +0x30 of the
 * re-resolved object. Same body shape as fn_8009DC60
 * (actor_movement_step_pinned_8009DC60.cpp).
 * Matching notes: the original read pooled literals (0.0f at 0.0f,
 * 1.0f at 1.0f); each use in the axis transform takes a distinct read
 * form so it is not CSE'd. */
typedef unsigned long Word;
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec operator*(float v) const { return Vec(x * v, y * v, z * v); }
    Vec operator+(const Vec& v) const { return Vec(x + v.x, y + v.y, z + v.z); }
    Vec& operator=(const Vec& v) { x = v.x; y = v.y; z = v.z; return *this; }
};
struct Handle { signed int tag : 8; signed int index : 24; };
extern "C" {
extern Vec game_vec3_zero;
}
struct Matrix {
    float m[9];
    Vec axisZ() const {
        float a = 0.0f, b = 0.0f, c = 1.0f;
        float x = m[0] * a + m[3] * b + m[6] * c;
        float y = m[1] * a + m[4] * b + m[7] * c;
        float z = m[2] * a + m[5] * b + m[8] * c;
        return Vec(x, y, z);
    }
};
struct Node { char unknown00[0x30]; Matrix matrix; char unknown54[0xCC]; Word flags; };
struct Entry { Node* object; Word unknown04, unknown08; signed char tag; char unknown0D[3];
    signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
extern "C" { extern struct { char unknown00[0x118]; Manager* manager; } lbl_801E9D24; }
inline Node* resolve(const Handle& h) {
    int index = h.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.tag ? m->entries[index].object : 0;
}
struct Header { char unknown00[8]; };
struct Actor : Header {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74();
    virtual void slot78(); virtual void slot7C(); virtual void slot80(); virtual void slot84();
    virtual void slot88(); virtual void slot8C(); virtual void slot90(); virtual void slot94();
    virtual void slot98();
    virtual const Handle* getHandle(int);
    char unknown0C[0x24];
    unsigned long long flags;
    char unknown38[0x10C];
    Vec velocity;
};
extern "C" void fn_800A9FA0(Actor* self, const Vec* position, Vec* next, Vec* direction, float delta) {
    if (resolve(*self->getHandle(0))->flags & 0x10000) {
        self->velocity = game_vec3_zero;
    }
    self->flags &= 0x1000003FFFFFFE3FULL;
    *next = *position + self->velocity * delta;
    *direction = resolve(*self->getHandle(0))->matrix.axisZ();
}

}
namespace paa180 {
/* Actor velocity integration step (fn_800AA180).
 * Skipped while the resolved resource (virtual slot 0x9C) has property bit
 * 0x10000. Without the grounded flag (bit 0x8000000000) calls the gravity
 * virtual (slot 0x18C); otherwise clamps a downward base velocity (+0x15C)
 * to zero and applies contact friction (fn_8009B674). With the bounce flag
 * (bit 0x20000000000) reflects the base velocity about the contact normal
 * (+0x3A4) and scales it by the restitution (+0x3A0). Finally
 * velocity(+0x144) = base + (force(+0x358) / mass(+0x354)) * delta, clamped
 * to the maximum speed (+0x370).
 *
 * Matching notes: hasFlag must use the if/return form (the first flag test
 * materialises a signed char); the reflection copies the base vector through
 * value parameters in y, x, z order and computes 2*dot as its own statement
 * (FPR colouring); the clamp's 1.0f uses a second read form of the pooled
 * label so it is reloaded instead of CSE'd with the mass reciprocal. */

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
    Vec3 operator*(float f) const { return Vec3(x * f, y * f, z * f); }
    Vec3 operator/(float f) const { float inverse = 1.0f / f; return Vec3(x * inverse, y * inverse, z * inverse); }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    float dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    float lengthSquared() const { return x * x + y * y + z * z; }
    float length() const { float sq = lengthSquared(); float r = 0.0f; if (sq != r) r = fastSqrt(sq); return r; }
};

inline Vec3 vec3FromYXZ(float y, float x, float z) { return Vec3(x, y, z); }

struct Handle { signed int tag : 8; signed int index : 24; };
struct Resource { char unknown00[0x120]; unsigned long property; };
struct Entry { Resource* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { char unknown00[8]; Entry* entries; };
struct Context { char unknown00[0x118]; Manager* manager; };
extern "C" Context lbl_801E9D24;
inline Resource* resolveResource(const Handle& h)
{
    int index = h.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.tag ? m->entries[index].object : 0;
}

struct Prefix { char unknown00[8]; };
struct Agent : Prefix {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
    virtual void slot36();
    virtual const Handle* slot37(int);
    virtual void slot38(); virtual void slot39();
    virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
    virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47();
    virtual void slot48(); virtual void slot49(); virtual void slot50(); virtual void slot51();
    virtual void slot52(); virtual void slot53(); virtual void slot54(); virtual void slot55();
    virtual void slot56(); virtual void slot57(); virtual void slot58(); virtual void slot59();
    virtual void slot60(); virtual void slot61(); virtual void slot62(); virtual void slot63();
    virtual void slot64(); virtual void slot65(); virtual void slot66(); virtual void slot67();
    virtual void slot68(); virtual void slot69(); virtual void slot70(); virtual void slot71();
    virtual void slot72(); virtual void slot73(); virtual void slot74(); virtual void slot75();
    virtual void slot76(); virtual void slot77(); virtual void slot78(); virtual void slot79();
    virtual void slot80(); virtual void slot81(); virtual void slot82(); virtual void slot83();
    virtual void slot84(); virtual void slot85(); virtual void slot86(); virtual void slot87();
    virtual void slot88(); virtual void slot89(); virtual void slot90(); virtual void slot91();
    virtual void slot92(); virtual void slot93(); virtual void slot94(); virtual void slot95();
    virtual void slot96();
    virtual void applyGravity();
    char unknown0C[0x24];
    unsigned long long flags;
    char unknown38[0x10C];
    Vec3 velocity;
    char unknown150[0xC];
    Vec3 base;
    char unknown168[0x1EC];
    float mass;
    Vec3 force;
    char unknown364[0xC];
    float maxSpeed;
    char unknown374[0x2C];
    float restitution;
    Vec3 normal;
    signed char hasFlag(unsigned long long mask) const { if (flags & mask) return 1; return 0; }
};

extern "C" void fn_8009B674(Agent*);

extern "C" void fn_800AA180(Agent* self, float delta)
{
    if (!(resolveResource(*self->slot37(0))->property & 0x10000)) {
        if (!self->hasFlag(0x8000000000ULL)) {
            self->applyGravity();
        } else if ((self->flags & 0x8000000000ULL) && self->base.y < 0.0f) {
            self->base = Vec3(self->base.x, 0.0f, self->base.z);
            fn_8009B674(self);
        } else if (self->flags & 0x8000000000ULL) {
            fn_8009B674(self);
        }
        if (self->flags & 0x20000000000ULL) {
            Vec3 b = vec3FromYXZ(self->base.y, self->base.x, self->base.z);
            float k = b.dot(self->normal);
            k = 2.0f * k;
            Vec3 d = b - self->normal * k;
            self->base = d * self->restitution;
        }
        Vec3 next = self->base + (self->force / self->mass) * delta;
        float len = next.length();
        if (len > self->maxSpeed)
            next = (next * self->maxSpeed) / len;
        self->velocity = next;
    }
}

}
namespace paa400 {
extern "C" const float lbl_80378D58;
static inline void add3(float *out,float x,float y,float z) {out[0]+=x;out[1]+=y;out[2]+=z;}
extern "C" void fn_800AA400(float *object) {add3(object+0x358/4,0.0f,20.0f*(lbl_80378D58*object[0x354/4]),0.0f);}

}
namespace paa440 {
#ifndef GAME_EARLY_MOTION_VECTOR_CONTROL_VIEWS_H
#define GAME_EARLY_MOTION_VECTOR_CONTROL_VIEWS_H
struct MotionVectorHandle{signed int tag:8;signed int index:24;};
struct MotionVector{float x,y,z;MotionVector(){}MotionVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){}MotionVector&operator=(const MotionVector&v){x=v.x;y=v.y;z=v.z;return*this;}MotionVector operator*(float s)const{return MotionVector(x*s,y*s,z*s);}MotionVector operator+(const MotionVector&v)const{return MotionVector(x+v.x,y+v.y,z+v.z);}MotionVector&operator+=(const MotionVector&v){x+=v.x;y+=v.y;z+=v.z;return*this;}};
struct MotionVectorTransform{char unknown00[0x30];MotionVector position;};
struct MotionVectorPrefix{char unknown00[8];};
struct MotionVectorActor:MotionVectorPrefix{
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual const MotionVectorHandle* slot37(int);
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45(const MotionVector&,int);
char unknown0C[0x18];MotionVectorHandle handle;char unknown28[0x10];unsigned long long flags;char unknown40[0x104];MotionVector velocity;char unknown150[0x18];char controller[8];int state;char unknown174[0x28];MotionVector origin;signed char originActive;char unknown1A9[3];MotionVector position;char unknown1B8[0x1A0];MotionVector acceleration;char unknown364[8];float scale;char unknown370[0x14];MotionVector impulse;MotionVector saved;
};
struct MotionVectorResource{char unknown00[0x38];unsigned long long flags;char unknown40[0xE0];unsigned long property;MotionVectorTransform*transform;};
struct MotionVectorEntry{MotionVectorResource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct MotionVectorManager{char unknown00[8];MotionVectorEntry*entries;};
struct MotionVectorContext{char unknown00[0x118];MotionVectorManager*manager;};
extern "C"MotionVectorContext lbl_801E9D24;
inline MotionVectorResource*resolveResource(const MotionVectorHandle&h){int index=h.index;MotionVectorManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct MotionVectorController{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void update(float,void*,const MotionVector*,void*,void*);};
struct MotionVectorOscillator{char unknown00[8];MotionVectorActor*actor;char unknown0C[8];float offset,phase,amplitude,speed;};
struct MotionVectorStatus{char unknown00[0x70];signed char active;};
struct MotionVectorGroup{char unknown00[0x94];MotionVectorStatus*status;};
struct MotionVectorTimed{char unknown00[8];MotionVectorActor*actor;MotionVectorGroup*group;char unknown10[4];float duration,time,rate;MotionVector velocity;};
extern "C"{MotionVectorController*fn_8007DCF8(void*);float fn_80284FA8(float);MotionVector fn_800AB440(MotionVectorTimed*);void fn_8007D6A0(void*,int);extern const float lbl_80379038,lbl_80379048,lbl_8037907C,lbl_80379088,lbl_80378D68;}
#endif
extern "C" void fn_800AA440(MotionVectorActor*self,const MotionVector&input){if(!(resolveResource(*self->slot37(0))->property&0x10000)){self->saved=input;self->acceleration+=input*self->scale;}}

}
extern "C" float fn_800AA52C(float a, float b) { return a > b ? a : b; }
extern "C" float fn_800AA53C(float a, float b) { return a < b ? a : b; }
extern "C" asm void fn_800AA54C() {
    nofralloc
    subi r3, r3, 0x318
    b __dt__15Object_800A8F90Fv
}

/* Former original/rtti_name_8037902C data 0x8037902C..0x80379031 (.sdata2), referenced as part of this unit; it starts mid-line (not 8-aligned), so it can only follow the data above. */
#pragma explicit_zero_data on
#pragma force_active on
extern "C" __declspec(section ".sdata2") const char lbl_8037902C[] = "CFSM";

#pragma force_active reset
