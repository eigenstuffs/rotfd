/* fn_8009BF08: push the actor away from the system group's tracked actor in
   the XZ plane. Resolves system(+0x13C)->handle(+0x1C) -> group(+0xA4) ->
   actor, takes the transform (+0x124) of the actor behind that actor's
   virtual slot 0x9C handle, and of the one behind self's slot 0x9C handle,
   builds the flat offset (mine - target, y = 0), normalizes it (bare frsqrte
   scale) and adds offset * 16 (lbl_80378D8C) to the force at +0x358.
   Matching notes: the original computed the offset's length() on a
   stack-resident copy (dead stores at 0x8..0x10; the unused fastSqrt is
   dropped, leaving a dead fcmpu), then normalized a second register copy
   whose 0.0f*0.0f term the compiler folded to the pooled 0.0f literal.
   normalizeFlat() spells that folded term as the shared lbl_80378D5C; the
   pointer-read forms keep the original's separate literal loads. */
extern "C" {extern const float lbl_80378D5C,lbl_80378D8C;}
inline float fastSqrt(register float x){register float r;asm{frsqrte f4,x
 fres r,f4}return r;}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3 operator*(float a)const{return Vec3(x*a,y*a,z*a);}
 Vec3&operator+=(const Vec3&v){x+=v.x;y+=v.y;z+=v.z;return*this;}
 const Vec3&get()const{return*this;}
 float lengthSquared()const{return x*x+y*y+z*z;}
 float length()const{float sq=lengthSquared();float r=lbl_80378D5C;if(sq!=r)r=fastSqrt(sq);return r;}
 /* normalize() of a vector whose y is the 0.0f literal: y*y folded to 0.0f. */
 void normalizeFlat(){float sq=x*x+*(const float*)&lbl_80378D5C+z*z;float r=*(const float*)&lbl_80378D5C;
  if(sq!=r){float inverse=reciprocalSqrt(sq);x*=inverse;y*=inverse;z*=inverse;}}};
struct Handle{signed int tag:8;signed int index:24;};
struct Transform{char unknown00[0x30];Vec3 position;};
struct Prefix{char unknown00[8];};
struct Actor:Prefix{
 virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();
 virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();
 virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();
 virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();
 virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();
 virtual void slot25();virtual void slot26();virtual void slot27();virtual void slot28();virtual void slot29();
 virtual void slot30();virtual void slot31();virtual void slot32();virtual void slot33();virtual void slot34();
 virtual void slot35();virtual void slot36();
 virtual const Handle*slot37(int);
 char unknown0C[0x118];Transform*transform;char unknown128[0x230];Vec3 force;};
struct Group{char unknown00[0xA4];Handle*actor;};
struct System{char unknown00[0x1C];Handle*handle;};
struct ActorEntry{Actor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ActorManager{char unknown00[8];ActorEntry*entries;};
struct GroupEntry{Group*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct GroupManager{char unknown00[8];GroupEntry*entries;};
struct Context{char unknown00[0x118];ActorManager*manager;char unknown11C[0x20];System*system;};
extern "C" Context lbl_801E9D24;
inline Actor*resolveActor(const Handle&h){int index=h.index;ActorManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline Group*resolveGroup(const Handle&h){int index=h.index;GroupManager*m=(GroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
extern "C" void fn_8009BF08(Actor*self){
 Transform*target=resolveActor(*resolveActor(*resolveGroup(*lbl_801E9D24.system->handle)->actor)->slot37(0))->transform;
 float tx,tz;tz=target->position.z;tx=target->position.x;
 Transform*mine=resolveActor(*self->slot37(0))->transform;
 Vec3 offset(mine->position.x-tx,lbl_80378D5C,mine->position.z-tz);
 const Vec3&r=offset.get();
 float distance=r.length();
 Vec3 direction(mine->position.x-tx,*(const float*)&lbl_80378D5C,mine->position.z-tz);
 direction.normalizeFlat();
 self->force+=direction**(const float*)&lbl_80378D8C;
}
