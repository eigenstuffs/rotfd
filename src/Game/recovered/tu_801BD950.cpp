// Original TU part 801BD950..801BE6F4: owner bounding sphere, collision height
// control, hit-receiver impulse, motion-event dispatch and the ground-ray move.
// These functions share the TU float literal pool .sdata2 0x8037A2F8..0x8037A30C
// (0.0f, -1.0f, 20.0f, 1.3f, 5.0f in first-use order); fn_801BE4D0 needs the
// pooled 0.0f as a literal, so every user of the pool lives in this object.
// The TU continues before 801BD950 (fn_801BD2F8 and the pool entries below
// 0x8037A2F8 are not matched yet and stay separate); 0x8037A30C..0x8037A310 is
// alignment padding in front of the next TU's 8-aligned .sdata2.
#include "Game/owner_collision_height_control_801bdcac.h"
struct Context {char unknown00[0x118];void*manager;};
extern "C" {extern Context lbl_801E9D24;}
#define lbl_8037A2F8 0.0f
#define lbl_8037A2FC -1.0f
#define lbl_8037A300 20.0f
#define lbl_8037A304 1.3f
#define lbl_8037A308 5.0f

/* ---- 801BD950 ---- */
namespace bounding_sphere_801BD950 {
/* fn_801BD950: compute a world-space bounding sphere for the owner's object.
   Resource type 5 selects one of several local spheres by kind (0/1: scaled
   by the matrix x-axis length and translated, 4: transformed by
   fn_80099A00, 2: translated only, 3: fn_8024673C); other resource types
   transform the resource bounds at +0xC unless kind is 3. Returns 1 when a
   sphere was written. */
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
struct Handle{signed int tag:8;signed int index:24;};
struct Vec3{float x,y,z;
Vec3(){}
Vec3(float ax,float ay,float az):x(ax),y(ay),z(az){}
Vec3(const Vec3&o):x(o.x),y(o.y),z(o.z){}
void operator*=(float s){x*=s;y*=s;z*=s;}
void operator+=(const Vec3&o){x+=o.x;y+=o.y;z+=o.z;}
float length()const{float sq=x*x+y*y+z*z;float r=lbl_8037A2F8;if(sq!=r)r=fastSqrt(sq);return r;}
};
struct Sphere{Vec3 center;float radius;
Sphere&operator=(const Sphere&o){center.x=o.center.x;center.y=o.center.y;center.z=o.center.z;radius=o.radius;return *this;}};
struct Matrix{float m[16];
Vec3 column0()const{return Vec3(m[0],m[4],m[8]);}
const Vec3&position()const{return *(const Vec3*)&m[12];}
Vec3 translation()const{return Vec3(m[12],m[13],m[14]);}
};
struct Prefix{char unknown00[8];};
struct Owner:Prefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();
virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();
virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();
virtual void slot98();virtual const Handle*getHandle(int);
};
struct Resource{char unknown00[0xC];Sphere bounds;char unknown1C[0x6C-0x1C];unsigned short type;char unknown6E[0x74-0x6E];
Sphere*sphere74;Sphere*sphere78;char unknown7C[0x90-0x7C];Sphere*sphere90;char unknown94[0xA8-0x94];Sphere*sphereA8;};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
inline void*resolve(const Handle&h){int index=h.index;Manager*m=(Manager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.tag)return m->entries[index].object;return 0;}
struct Object{char unknown00[0x1C];Handle resource;char unknown20[0x124-0x20];Matrix*matrix;
Resource*getResource()const{return static_cast<Resource*>(resolve(resource));}};
extern "C"{Sphere fn_80099A00(const Matrix*,const Sphere*);signed char fn_8024673C(Resource*,Object*,Sphere*);}
extern "C" int fn_801BD950(Owner*self,Sphere*out,unsigned short kind,int index){
    Object*object=static_cast<Object*>(resolve(*self->getHandle(index)));
    Resource*resource=object->getResource();
    Matrix*matrix=object->matrix;
    float scale=matrix->column0().length();
    Vec3 translation=matrix->position();
    if(resource->type==5){
        if(kind==0){
            if(resource->sphere74){*out=*resource->sphere74;out->center*=scale;out->center+=translation;out->radius*=scale;return 1;}
        }else if(kind==1){
            if(resource->sphere78){*out=*resource->sphere78;out->center*=scale;out->center+=translation;out->radius*=scale;return 1;}
        }else if(kind==4){
            if(resource->sphereA8){*out=fn_80099A00(matrix,resource->sphereA8);return 1;}
        }else if(kind==2){
            if(resource->sphere90){*out=*resource->sphere90;out->center+=object->matrix->translation();return 1;}
        }else if(kind==3){
            if(fn_8024673C(resource,object,out))return 1;
        }
        return 0;
    }
    if(kind==3)return 0;
    *out=fn_80099A00(matrix,&resource->bounds);
    return 1;
}

}
/* ---- 801BDCAC ---- */

typedef unsigned int CollisionHeightWord;
typedef unsigned long long CollisionHeightFlags;

struct CollisionHeightPoint_801BDCAC {
    float x, y, z;
    CollisionHeightPoint_801BDCAC() {}
    CollisionHeightPoint_801BDCAC(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct CollisionHeightRay_801BDCAC {
    CollisionHeightPoint_801BDCAC origin;
    float length;
    CollisionHeightPoint_801BDCAC direction;
    float unknown1C;
    CollisionHeightRay_801BDCAC(const CollisionHeightPoint_801BDCAC& o,
                              const CollisionHeightPoint_801BDCAC& d, float l)
        : origin(o), direction(d) { length = l; }
};

struct CollisionHeightResult_801BDCAC {
    CollisionHeightPoint_801BDCAC point;
    char unknown0C[0x28 - 12];
    CollisionHeightFlags flags;
    CollisionHeightWord object, other, extra;
    signed char hit;
    char unknown3D[3];
    CollisionHeightWord end;
    CollisionHeightResult_801BDCAC() {
        hit = 0;
        object = 0;
        other = 0;
        extra = 0;
        flags = 0;
    }
};

// Partial virtual view: the original vptr follows eight bytes of base storage.
struct CollisionHeightStorage_801BDCAC { CollisionHeightWord unknown00, unknown04; };
struct CollisionHeightOwner_801BDCAC : CollisionHeightStorage_801BDCAC {
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
    virtual void contact(CollisionHeightResult_801BDCAC*,CollisionHeightPoint_801BDCAC*,int);
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual float radius();
    virtual float height(int);
    virtual void setHeight(float,int);
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
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
    virtual void clearFlags(CollisionHeightFlags,int);
    virtual signed char hasFlags(CollisionHeightFlags,int);

};

extern "C" {
signed char fn_80269230(void*, const CollisionHeightRay_801BDCAC&,
                       CollisionHeightResult_801BDCAC*, CollisionHeightFlags,
                       CollisionHeightFlags);
extern const float lbl_8037A2F0;
double __fabs(double);
}

extern "C" void fn_801BDCAC(CollisionHeightOwner_801BDCAC* self, void* world,
                            CollisionHeightPoint_801BDCAC* position, int index)
{
    CollisionHeightPoint_801BDCAC origin = *position;
    float radius = self->radius();
    CollisionHeightResult_801BDCAC result;
    origin.y += radius;
    if (fn_80269230(world,
                   CollisionHeightRay_801BDCAC(origin,
                       CollisionHeightPoint_801BDCAC(lbl_8037A2F8, lbl_8037A2FC,
                                                    lbl_8037A2F8), radius),
                   &result, 8, 0)) {
        self->contact(&result, position, index);
    } else if (self->hasFlags(0x2000000000000ULL, index)) {
        float distance = self->height(index);
        origin.y = radius + distance;
        distance = (float)__fabs(origin.y - position->y);
        if (distance > lbl_8037A2F0) {
            if (fn_80269230(world,
                           CollisionHeightRay_801BDCAC(origin,
                               CollisionHeightPoint_801BDCAC(lbl_8037A2F8,
                                   lbl_8037A2FC, lbl_8037A2F8), distance),
                           &result, 8, 0)) {
                self->setHeight(result.point.y - position->y, index);
            } else {
                self->clearFlags(0x2000000000000ULL, index);
                self->setHeight(lbl_8037A2F8, index);
            }
        }
    }
}

/* ---- 801BDEF8 ---- */
namespace hit_receiver_801BDEF8 {
/* fn_801BDEF8: ask the owner (vtable slot 0x88) for its bounding sphere,
   collect the colliders touching it (fn_80268918), and when the first hit's
   owner has state flag 0x80 forward the sphere and a speed-derived strength
   (20 * max(distance(a, b), radius)) to that owner's linked receiver
   (vtable slot 0x44). */
typedef unsigned long Word;
extern "C" const float lbl_8037A2E8;
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
inline void*resolve(const Handle&h){int index=h.bits.index;Manager*m=(Manager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
struct Vec3{float x,y,z;
float distance(const Vec3&o)const{float dy=y-o.y;float dx=x-o.x;float dz=z-o.z;float sq=dx*dx+dy*dy+dz*dz;float r=lbl_8037A2F8;if(sq!=r)r=fastSqrt(sq);return r;}};
struct Sphere{Vec3 center;float radius;Sphere(const Vec3&c,float r){center.x=c.x;center.y=c.y;center.z=c.z;radius=r;}};
struct Prefix{char unknown00[8];};
struct Owner;
struct Collider{char unknown00[0x130];Handle owner;Owner*getOwner()const{return (Owner*)resolve(owner);}};
struct Collected{char unknown00[0x1C];Collider*collider;char unknown20[8];~Collected(){}};
struct Results{Word storage[0xA00];int count;Results():count(0){}~Results(){for(int i=0;i<count;++i)reinterpret_cast<Collected*>(storage)[i].~Collected();}
Collected&at(int i){return reinterpret_cast<Collected*>(storage)[i];}};
struct Receiver:Prefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44(const Sphere*,float,float);
};
struct Owner{char unknown00[0x38];unsigned long long flags;char unknown40[0x24];Handle receiver;Receiver*getReceiver()const{return (Receiver*)resolve(receiver);}};
struct Self:Prefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();
virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();
virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
virtual signed char slot88(Sphere*,int,int);
};
extern "C"{
extern Vec3 game_vec4_zero;
int fn_80268918(void*,const Sphere*,Results*,unsigned long long,unsigned long long);
float fn_800AA52C(float,float); /* max */
}
extern "C" void fn_801BDEF8(Self*self,void*world,const Vec3*a,const Vec3*b,int index){
    Sphere sphere(game_vec4_zero,lbl_8037A2E8);
    if(!self->slot88(&sphere,4,index))return;
    float dist=a->distance(*b);
    Results results;
    if((signed char)fn_80268918(world,&sphere,&results,0x00002E0000000000ULL,0x0000000200000000ULL)){
        Owner*owner=results.at(0).collider->getOwner();
        if(!owner||!(owner->flags&0x80))return;
        Receiver*receiver=owner->getReceiver();
        float larger=fn_800AA52C(dist,sphere.radius);
        receiver->slot44(&sphere,lbl_8037A300*larger,lbl_8037A304);
    }
}

}
/* ---- 801BE188 ---- */
/* Resource motion-event dispatch; see docs/notes/game-resource-motion-event-dispatch.md. */
typedef unsigned long Word;typedef unsigned long long Wide;
struct Handle_801F7F10 {union{Word word;struct{signed int tag:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ResourceEventZero2_801BE188;
extern "C" {extern Context lbl_801E9D24;void fn_801F86C8(void*,const void*,short);struct ResourceEventCopy2_801BE188 fn_801BE46C(void*);signed char fn_801BD2F8(void*,const Handle_801F7F10&,Word,Word,void*);void fn_80038098(void*,const Handle_801F7F10&);}
struct ResourceEventZero1_801BE188:Handle_801F7F10 {ResourceEventZero1_801BE188(){word=0;}~ResourceEventZero1_801BE188(){}};
struct ResourceEventZero2_801BE188:ResourceEventZero1_801BE188 {ResourceEventZero2_801BE188(){word=0;}~ResourceEventZero2_801BE188(){}};
struct ResourceEventZero3_801BE188:ResourceEventZero2_801BE188 {ResourceEventZero3_801BE188(){word=0;}~ResourceEventZero3_801BE188(){}};
struct ResourceEventCopy1_801BE188:ResourceEventZero1_801BE188 {ResourceEventCopy1_801BE188(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~ResourceEventCopy1_801BE188(){}};
struct ResourceEventCopy2_801BE188:ResourceEventZero2_801BE188 {ResourceEventCopy2_801BE188(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~ResourceEventCopy2_801BE188(){}};
struct Point {float x,y,z;Point(const Point&p):x(p.x),y(p.y),z(p.z){}Point&operator=(const Point&p){x=p.x;y=p.y;z=p.z;return *this;}};
struct Prefix {char unknown00[8];};
struct Owner:Prefix {
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
virtual void move(void*,Word,Word);
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
virtual const Handle_801F7F10&getHandle(int);
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
virtual signed char query(Wide,Word);
virtual void slotE8();
virtual void slotEC();
virtual void slotF0();
virtual void slotF4();
virtual void slotF8();
virtual void slotFC();
virtual void slot100();
virtual void dispatchFirst(void*,Word,Word,Word);
virtual void dispatchSecond(void*,Word,Word,Word,int);
char unknown0C[0x114];Word flags;char unknown124[0x20];Point point;};
struct Entry {Owner*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager {char unknown00[8];Entry*entries;inline Owner*get(const Handle_801F7F10&h){Entry*e=entries+h.bits.index;return e->tag==h.bits.tag?e->object:0;}};
static inline Owner*resolve(const Handle_801F7F10&h){return ((Manager*)lbl_801E9D24.manager)->get(h);}
extern "C" void fn_801BE188(Owner*self,void*other,Word first,Word unused,Word second,Word mode){
 if(self->query(0x4000ULL,mode))self->dispatchFirst(other,first,second,mode);
 if(self->query(0x1000ULL,mode))self->dispatchSecond(other,first,second,mode,0);
 if(self->query(0x10000ULL,mode))self->move(other,second,mode);
 Owner*related=resolve(fn_801BE46C(self));
 if(related){
  Point saved(self->point);
  ResourceEventCopy1_801BE188 copy(related->getHandle(0));
  if(fn_801BD2F8(self,copy,first,second,&saved)){
   Owner*target=resolve(copy);target->flags|=0x40000;target->flags&=~0x4000;
   fn_80038098(self,ResourceEventZero3_801BE188());
   fn_80038098(related,ResourceEventZero3_801BE188());
  }else self->point=saved;
 }
}

/* ---- 801BE46C ---- */
extern "C" ResourceEventCopy2_801BE188 fn_801BE46C(void* object)
{
    return ResourceEventCopy2_801BE188(*(const Handle_801F7F10*)((char*)object + 0x28));
}
/* ---- 801BE4D0 ---- */
namespace ground_ray_801BE4D0 {
/* fn_801BE4D0. Notes: pos must be 'const Vec3*' (fixes the s.z / pos.z load
 * schedule); the tail difference uses sub2 (no named locals) and a literal 0.0f
 * (an extern lbl_8037A2F8 is CSE'd by the frontend into a temp and changes the
 * float colouring); the literal must end up as lbl_8037A2F8. */
typedef unsigned long Word;
typedef unsigned long long Wide;
extern "C" const float lbl_8037A2E8;
struct Vec3{float x,y,z;
Vec3(){}
Vec3(float a,float b,float c):x(a),y(b),z(c){}
Vec3 operator+(const Vec3&o)const{return Vec3(x+o.x,y+o.y,z+o.z);}

void set(float a,float b,float c){x=a;y=b;z=c;}
Vec3 sub2(const Vec3&b)const{return Vec3(x-b.x,y-b.y,z-b.z);}
};
struct Sphere{Vec3 center;float radius;Sphere(const Vec3&c,float r){center.x=c.x;center.y=c.y;center.z=c.z;radius=r;}
};
struct Ray{Vec3 origin;float length;Vec3 direction;float unknown1C;
Ray(const Vec3&o,const Vec3&d,float l):origin(o),direction(d){length=l;}};
struct Result{Vec3 point;char unknown0C[0x28-12];Wide flags;Word object,other,extra;signed char hit;char unknown3D[3];Word end;
Result(){hit=0;object=0;other=0;extra=0;flags=0;}};
struct Prefix{char unknown00[8];};
struct Owner:Prefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();
virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();
virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
virtual signed char slot88(Sphere*,int,int);virtual void slot8C();virtual void slot90();virtual void slot94();
virtual void slot98();virtual void*slot9C(int);virtual void slotA0();virtual void slotA4();
virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();
virtual void slotB8();virtual void slotBC();virtual void slotC0();virtual void slotC4();
virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void slotD4();
virtual void slotD8();virtual void slotDC();virtual void slotE0();virtual signed char slotE4(Wide,int);
virtual void slotE8();virtual void slotEC();virtual void slotF0();virtual void slotF4();
virtual void slotF8();virtual void slotFC();virtual void slot100(float,void*,const Vec3*,const Vec3*,Vec3*,int);
};
extern "C"{
extern Vec3 game_vec4_zero;
signed char fn_80269230(void*,const Ray&,Result*,Wide,Wide);
}
extern "C" void fn_801BE4D0(Owner*self,float dt,void*world,const Vec3*pos,Vec3*vel,Wide mask,int id){
    Sphere s(game_vec4_zero,lbl_8037A2E8);
    if(self->slot88(&s,0,id)){
        {float d[3];d[0]=s.center.x-pos->x;float dy=s.center.y-pos->y;float dz=s.center.z-pos->z;s.center.z=dz;s.center.x=d[0];s.center.y=dy;}
        Result res;
        Vec3 p=s.center+*vel;
        p.y+=s.radius;
        if(self->slotE4(0x40000,id)){
            Ray ray(p,Vec3(lbl_8037A2F8,lbl_8037A2FC,lbl_8037A2F8),lbl_8037A308);
            if(fn_80269230(world,ray,&res,0x000001E000000002ULL,0x0000000400000008ULL)){
                {float r=s.radius;*vel=res.point.sub2(s.center)+Vec3(0.0f,r,0.0f);}
            }
        }
        self->slot100(dt,world,pos,pos,vel,id);
    }
}

}
