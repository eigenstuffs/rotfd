/* fn_800A0A84: resets the actor behavior (fn_8006BA70(fn_8005EE10(owner),0)),
   then measures the planar (XZ) distance from the query(0) target geometry
   position to the actor anchor (0x398). Below nearDistance (0x3B4) it starts
   control 0; otherwise the normalized target-to-anchor direction is applied
   (direction 0x3A4, fn_8009ED90, fn_800A4DF0). Shape copied from
   actor_target_range_normalize_8009CC54.cpp (pooled 0.0f read forms). */
#pragma fp_contract off
typedef unsigned long Word;
extern "C" const float lbl_80378E40; /* 0.0f */
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
inline float fastSqrt(register float x){register float r;asm{frsqrte f4,x
 fres r,f4}return r;}
struct Vec3{float x,y,z;Vec3(){}Vec3(float ax,float ay,float az):x(ax),y(ay),z(az){}
 const Vec3&get()const{return *this;}
 float length()const{float sq=x*x+y*y+z*z;float r=y;if(sq!=r)r=fastSqrt(sq);return r;}
 Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Geometry{char unknown0[0x30];Vec3 position;};
struct Prefix{char unknown0[8];};
struct Node:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const Handle&query(int);
 char unknownC[0x24-0xC];Handle handle;char unknown28[0x124-0x28];Geometry*geometry;char unknown128[0x318-0x128];char control;char unknown319[0x398-0x319];Vec3 anchor;Vec3 direction;float distance;float nearDistance;};
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
extern "C" struct Global{char unknown0[0x118];Manager*manager;}lbl_801E9D24;
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Owner{char unknown0[8];Node*actor;};
extern "C"{void fn_8007D6A0(void*,int);void*fn_8005EE10(Node*);void fn_8006BA70(void*,int);void fn_8009ED90(Node*,const Vec3&,float);void fn_800A4DF0(Owner*,float);}
inline void applyMotionControl(Owner*self,float delta,const Vec3&v){self->actor->direction=v;fn_8009ED90(self->actor,v,delta);fn_800A4DF0(self,delta);}

extern "C" void fn_800A0A84(Owner*self,float delta){
 fn_8006BA70(fn_8005EE10(resolve(self->actor->handle)),0);
 const Vec3&tp=resolve(self->actor->query(0))->geometry->position;
 Node*actor=self->actor;
 float tx=tp.x;float tz=tp.z;float px=actor->anchor.x;float pz=actor->anchor.z;
 if(Vec3(tx-px,lbl_80378E40,tz-pz).get().length()<actor->nearDistance)fn_8007D6A0(&actor->control,0);
 else{
  Vec3 n;n.x=px-tx;n.y=*(const float*)&lbl_80378E40;n.z=pz-tz;
  float sq=n.x*n.x+n.y*n.y+n.z*n.z;
  if(*(const float*)&lbl_80378E40!=sq){float s=reciprocalSqrt(sq);n.x*=s;n.y*=s;n.z*=s;}
  applyMotionControl(self,delta,n);
 }
}
