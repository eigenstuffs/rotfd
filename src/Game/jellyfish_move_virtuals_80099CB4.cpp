/* Part of the original CJellyfishMove source: CJellyfishMove::slot198 and the
 * functions after it, with the vtable, RTTI records and adjustor thunks that
 * the compiler emits for the class (key function: slot198).  The class
 * hierarchy comes from the original RTTI base lists; see
 * include/Game/move_classes.h.  Each function keeps its own local views of
 * the objects it reads, in its own namespace. */
#include "Game/move_classes.h"

struct Vec3 { float x, y, z; };

/* Leading .rodata objects of this unit, ahead of the compiler's RTTI data. */
extern "C" const char lbl_8029E290[] = "Anonymous New";
extern "C" const char lbl_8029E2A0[] = "JellyfishMove.cpp";

/* CJellyfishMove::slot198, the actor velocity integration: adds a planar drag of -0.1 times
   the current velocity (0x15C) to the accumulated force (0x358; the y term is
   the pooled 0.0f), lets the virtual slot 0x18C contribute unless flag bit
   0x8000000000 is set, then integrates velocity + force / mass (0x354) *
   delta, clamps its length to the maximum speed (0x370) and stores the
   result at 0x144.

   Matching notes: the original TU used pooled literals (lbl_80378D10 = 0.0f,
   lbl_80378D14 = 0.1f, lbl_80378D1C = 1.0f); the literal source is
   `Vec3 d = -velocity * 0.1f; d.y = 0.0f; force += d;` (see literal.cpp,
   EXACT-DATA). With the shared labels the literal loads are emulated:
   - the drag scale is read at each live multiply (x, z) with distinct read
     forms inside a member of the negated temporary (dragScaled), and the
     0.0f is read at the y add;
   - the two 1.0f reciprocals (force / mass, clamp) use distinct read forms
     (operator/ and divide) so the second is reloaded inside the clamp.
   The dead stack stores (negated velocity at 0x20, force / mass at 0x14,
   v * maxSpeed at 0x8) come from temporaries used as the object of inline
   members (dragScaled, operator* and divide with their locals). The engine
   square root is the established frsqrte/fres inline helper. */
namespace JellyfishVelocity {
extern "C" const float lbl_80378D10; /* 0.0f */
extern "C" const float lbl_80378D14; /* 0.1f */
extern "C" const float lbl_80378D1C; /* 1.0f */

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
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    Vec3 operator*(float s) const { float t = s; return Vec3(x * t, y * t, z * t); }
    Vec3 operator/(float s) const { float inv = lbl_80378D1C / s; return Vec3(x * inv, y * inv, z * inv); }
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3 divide(float s) const { float inv = *(const float*)&lbl_80378D1C / s; return Vec3(x * inv, y * inv, z * inv); }
    Vec3 dragScaled() const
    {
        return Vec3(x * lbl_80378D14, y * *(const float*)&lbl_80378D14,
                    z * *(const float*)(unsigned long)&lbl_80378D14);
    }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_80378D10;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

struct Prefix { char unknown00[8]; };
struct Node : Prefix {
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
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
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
    virtual void slot164();
    virtual void slot168();
    virtual void slot16C();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17C();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void applyForces();
    char unknown0C[0x30 - 0xC];
    unsigned long long flags;
    char unknown38[0x144 - 0x38];
    Vec3 position;
    char unknown150[0x15C - 0x150];
    Vec3 velocity;
    char unknown168[0x354 - 0x168];
    float mass;
    Vec3 force;
    char unknown364[0x370 - 0x364];
    float maxSpeed;
};
}

void CJellyfishMove::slot198(float delta)
{
    using JellyfishVelocity::Node;
    typedef JellyfishVelocity::Vec3 Vec3;
    using JellyfishVelocity::lbl_80378D10;
    Node* self = reinterpret_cast<Node*>(this);
    Vec3 drag = (-self->velocity).dragScaled();
    self->force.x += drag.x;
    self->force.y += lbl_80378D10;
    self->force.z += drag.z;
    if (!(self->flags & 0x8000000000ULL)) self->applyForces();
    Vec3 v = self->velocity + self->force / self->mass * delta;
    float len = v.length();
    if (len > self->maxSpeed) v = (v * self->maxSpeed).divide(len);
    self->position = v;
}

/* fn_80099E40 picks a random point on a disc of radius 0x3D8 (fn_801F1200 =
   random unit float, lbl_80378D38 = full-turn angle scale, fn_8028506C/
   fn_80284FA8 = cos/sin) around the agent's center (0x3C4), and stores the
   normalized planar (XZ) direction from the position of the entity resolved
   through virtual getHandle(0) (slot 0x9C) to that point in the direction
   field (0x3B8). lbl_80378D10 (0.0f) is the pooled planar Y. Same shape as
   owner_random_disc_planar_direction_8009D820.cpp except that the offset is
   the left operand of the add (offset + center). */
namespace JellyfishRandomDisc {
typedef unsigned long Word;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Vec3{float x,y,z;
 Vec3(){}
 Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3&operator=(const Vec3&o){x=o.x;y=o.y;z=o.z;return*this;}
 Vec3 operator+(const Vec3&o)const{return Vec3(x+o.x,y+o.y,z+o.z);}
};
struct Geometry{char unknown00[0x30];Vec3 position;};
struct Entity{char unknown00[0x124];Geometry*geometry;};
struct Entry{Entity*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline Entity*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
struct Prefix{char unknown00[8];};
struct Agent:Prefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
 virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
 virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();
 virtual const Handle*getHandle(int); /* vtable +0x9C */
 char unknown0C[0x3B8-0xC];
 Vec3 direction; /* 0x3B8 */
 Vec3 center;    /* 0x3C4 */
 char unknown3D0[0x3D8-0x3D0];
 float radius;   /* 0x3D8 */
};
extern "C"{float fn_801F1200(void);float fn_8028506C(float);float fn_80284FA8(float);}
extern "C" const float lbl_80378D38; /* angle scale */
extern "C" const float lbl_80378D10; /* 0.0f */
extern "C" void fn_80099E40(Agent*self){
 float radius=self->radius;
 float r=fn_801F1200();
 r*=radius;
 float angle=lbl_80378D38*fn_801F1200();
 Vec3 offset;
 offset.x=r*fn_8028506C(angle);
 offset.z=r*fn_80284FA8(angle);
 offset.y=lbl_80378D10;
 Vec3 point=offset+self->center;
 const Vec3&p=resolve(*self->getHandle(0))->geometry->position;
 Vec3 d(point.x-p.x,lbl_80378D10,point.z-p.z);
 float inv=reciprocalSqrt(d.x*d.x+d.y+d.z*d.z);
 d.x*=inv;d.y*=inv;d.z*=inv;
 self->direction=d;
}
}

/* Planar (XZ) distance from the related actor (service +0x13C -> handle ->
   child 0xB0 -> actor handle 0x70, validity-checked with fn_801F7EB8) to this
   owner (fn_80099F74), written to *out. Each position component is read
   through its own query(0) resolve of the geometry (0x124 -> position 0x30).
   Matching notes: the difference is a planar Vec2 temporary bound to a const
   reference (dead stores at 0x8/0xC); the pooled 0.0f (lbl_80378D10) is the
   only literal and is read once; the engine square root is the established
   frsqrte/fres inline helper. */
namespace JellyfishRelatedDistance {
typedef unsigned long Word;
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
extern "C" const float lbl_80378D10; /* 0.0f */
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
struct Vec2{float x,y;Vec2(){}Vec2(float a,float b):x(a),y(b){}
 Vec2 operator-(const Vec2&o)const{return Vec2(x-o.x,y-o.y);}
 float length()const{float sq=x*x+y*y;float r=lbl_80378D10;if(sq!=r)r=fastSqrt(sq);return r;}
};
struct Vec3{float x,y,z;};
struct Geometry{char unknown0[0x30];Vec3 position;};
struct Prefix{char unknown0[8];};
struct Node:Prefix{
    virtual void slot8();virtual void slotC();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();
    virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
    virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();
    virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
    virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();
    virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();
    virtual void slot98();
    virtual const Handle&query(int);
    char unknownC[0x70-0xC];Handle actor;char unknown74[0xB0-0x74];Handle*child;char unknownB4[0x124-0xB4];Geometry*geometry;
};
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Related{char unknown0[0x1C];Handle*handle;};
extern "C"struct Global{char unknown0[0x118];Manager*manager;char unknown11C[0x20];Related*related;}lbl_801E9D24;
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
extern "C"{Word fn_801F7EB8(const Handle*);}
inline Node*relatedActor(){const Handle*h=&resolve(*resolve(*lbl_801E9D24.related->handle)->child)->actor;if(fn_801F7EB8(h))return resolve(*h);return 0;}

extern "C" void fn_80099F74(Node*self,float*out){
    Node*other=relatedActor();
    float ox=resolve(other->query(0))->geometry->position.x;
    float oz=resolve(other->query(0))->geometry->position.z;
    float sx=resolve(self->query(0))->geometry->position.x;
    float sz=resolve(self->query(0))->geometry->position.z;
    const Vec2&d=Vec2(sx-ox,sz-oz);
    *out=d.length();
}
}

/* Planar (XZ) distance from the owner geometry position (resolved twice from
   virtual query(0), slot 0x9C) to the point at 0x3C4, written to *out.
   Same layout as planarDirection_8009A6D4 (ox declared first fixes the FPR
   assignment). The planar difference is built by an inline helper
   that returns its result through get() (the dead stack copy at 0x8), and
   the function is built with fp_contract off (no fmadds). The engine square root is the
   bare reciprocal of a reciprocal-square-root estimate (frsqrte into f4,
   then fres), written as the shared minimal inline asm math helper. */
#pragma fp_contract off
namespace JellyfishOwnerDistance {
typedef unsigned long Word;
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Vec3{float x,y,z;};
struct Geometry{char unknown0[0x30];Vec3 position;};
struct Prefix{char unknown0[8];};
struct Node:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const Handle&query(int);char unknownC[0x124-0xC];Geometry*geometry;char unknown128[0x3C4-0x128];Vec3 point;};
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
extern "C" struct Global{char unknown0[0x118];Manager*manager;}lbl_801E9D24;
extern "C" const float lbl_80378D10; /* 0.0f */
inline Node*resolve(const Handle&h){const Entry*entries=lbl_801E9D24.manager->entries;int index=h.bits.index;int tag=entries[index].getTag();return tag==h.bits.tag?entries[index].object:0;}
inline float fastSqrt(register float x){register float r;asm{frsqrte f4,x
 fres r,f4}return r;}
struct Vec2{float x,y;Vec2(){}Vec2(float ax,float ay):x(ax),y(ay){}
 const Vec2&get()const{return *this;}
 float length()const{float sq=x*x+y*y;float r=lbl_80378D10;if(sq!=r)r=fastSqrt(sq);return r;}};
inline Vec2 planarDifference(float ax,float ay,float bx,float by){Vec2 r(ax-bx,ay-by);return r.get();}
extern "C" void fn_8009A270(Node*self,float*out){
 float ox;float x=self->point.x;float z=self->point.z;
 ox=resolve(self->query(0))->geometry->position.x;
 float oz=resolve(self->query(0))->geometry->position.z;
 *out=planarDifference(x,z,ox,oz).length();
}
}
#pragma fp_contract reset

/* Planar (XZ) unit direction from this owner's geometry position to the
   related actor's (service +0x13C -> handle -> child 0xB0 -> actor handle
   0x70, validated with fn_801F7EB8), with y cleared, written to *out.
   Same shape as planarDirection_8009A6D4; the related-actor helper keeps the
   manager pointer in resolve, reloading entries per resolve. The fast normalize
   uses a bare reciprocal-square-root estimate (frsqrte with no frsp), which
   no compiler built-in emits, so the math helper uses a minimal inline asm
   statement. */
namespace JellyfishRelatedDirection {
typedef unsigned long Word;
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Vec3{float x,y,z;};
struct Geometry{char unknown0[0x30];Vec3 position;};
struct Prefix{char unknown0[8];};
struct Node:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const Handle&query(int);
 char unknownC[0x70-0xC];Handle actor;char unknown74[0xB0-0x74];Handle*child;char unknownB4[0x124-0xB4];Geometry*geometry;};
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Related{char unknown0[0x1C];Handle*handle;};
extern "C" struct Global{char unknown0[0x118];Manager*manager;char unknown11C[0x20];Related*related;}lbl_801E9D24;
extern "C" const float lbl_80378D10; /* 0.0f */
extern "C" Word fn_801F7EB8(const Handle*);
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Node*relatedActor(){const Handle*h=&resolve(*resolve(*lbl_801E9D24.related->handle)->child)->actor;if(fn_801F7EB8(h))return resolve(*h);return 0;}
inline float rsqrt(register float x){register float r=lbl_80378D10;if(x!=lbl_80378D10){asm{frsqrte r,x}}return r;}
extern "C" void fn_8009A3CC(Node*self,Vec3*out){
 Node*other=relatedActor();
 float ox=resolve(other->query(0))->geometry->position.x;
 float oz=resolve(other->query(0))->geometry->position.z;
 float sx=resolve(self->query(0))->geometry->position.x;
 float sz=resolve(self->query(0))->geometry->position.z;
 float dx=ox-sx;float dz=oz-sz;
 float sq=dx*dx+dz*dz;
 if(lbl_80378D10!=sq){float inv=rsqrt(sq);dx*=inv;dz*=inv;}
 out->x=dx;out->y=lbl_80378D10;out->z=dz;
}
}

/* CJellyfishMove::planarDirection_8009A6D4: planar (XZ) unit direction from
   the owner geometry position to the point at 0x3C4, with y cleared. The fast
   normalize uses a bare reciprocal-square-root estimate (frsqrte with no frsp),
   which no compiler built-in emits, so the math helper uses a minimal inline
   asm statement. It is the last function of the original translation unit;
   the compiler emits the destructor adjustor thunk after it. */
namespace JellyfishPlanarDirection {
typedef unsigned long Word;
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Geometry{char unknown0[0x30];Vec3 position;};
struct Prefix{char unknown0[8];};
struct Node:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const Handle&query(int);char unknownC[0x124-0xC];Geometry*geometry;char unknown128[0x3C4-0x128];Vec3 point;};
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
extern "C" struct Global{char unknown0[0x118];Manager*manager;}lbl_801E9D24;
extern "C" const float lbl_80378D10;
inline Node*resolve(const Handle&h){const Entry*entries=lbl_801E9D24.manager->entries;int index=h.bits.index;int tag=entries[index].getTag();return tag==h.bits.tag?entries[index].object:0;}
inline float rsqrt(register float x){register float r=lbl_80378D10;if(x!=lbl_80378D10){asm{frsqrte r,x}}return r;}
}
void CJellyfishMove::planarDirection_8009A6D4(Vec3*out){
 using namespace JellyfishPlanarDirection;
 float ox;float x=reinterpret_cast<Node*>(this)->point.x;float z=reinterpret_cast<Node*>(this)->point.z;
 ox=resolve(reinterpret_cast<Node*>(this)->query(0))->geometry->position.x;
 float oz=resolve(reinterpret_cast<Node*>(this)->query(0))->geometry->position.z;
 float dx=x-ox;float dz=z-oz;
 float sq=dx*dx+dz*dz;
 if(lbl_80378D10!=sq){float inv=rsqrt(sq);dx*=inv;dz*=inv;}
 out->x=dx;out->y=lbl_80378D10;out->z=dz;
}

/* Object of this unit ahead of the compiler RTTI data (.sdata2). */
extern "C" const float lbl_80378D38 = 6.2831854820251465f;
