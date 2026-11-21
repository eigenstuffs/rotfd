/* fn_800A91D4: spins the actor about the axis perpendicular to its angular
   velocity (+0x15C) and the up axis lbl_802F4148. Unless the resolved node of
   the slot 0x9C handle has property bit 0x10000, the normalized spin vector is
   crossed with the up axis, the spin speed times delta advances the stored
   angle (+0x39C, wrapped once at 2*pi), and the half-angle rotation about the
   cross axis goes to the actor's facing slot 0xC0; otherwise slot 0xBC is
   called with the target and 0.

   Matching notes: lbl_80379000 (0.0f), lbl_80379008 (2*pi) and lbl_8037900C
   (0.5f) were pooled literals of the original TU. The spin length is read
   through a reference so its loads are not merged with the normalized copy
   (and stay unfused, as for memory operands); the wrap subtraction reads 2*pi
   through the pointer form. */
extern "C" const float lbl_80379000; /* 0.0f */
extern "C" const float lbl_80379008; /* 6.2831855f */
extern "C" const float lbl_8037900C; /* 0.5f */
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
 float length()const{float sq=lengthSquared();float r=*(const float*)&lbl_80379000;if(sq!=r)r=fastSqrt(sq);return r;}
 void normalize(){if(lbl_80379000!=lengthSquared()){float inv=reciprocalSqrt(lengthSquared());x*=inv;y*=inv;z*=inv;}}
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
  if(self->angle>lbl_80379008)self->angle=self->angle-*(const float*)&lbl_80379008;
  Rotation r(c.x,c.y,c.z,self->angle*lbl_8037900C);
  self->setFacing(target,&r,0);
 }else{
  self->clearFacing(target,0);
 }
}
