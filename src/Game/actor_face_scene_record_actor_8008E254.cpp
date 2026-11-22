/* fn_8008E254: turns the actor toward the current scene record's actor.
   The record is selected by the index (+0x20) of fn_8007D074's object in the
   0x4C-byte scene records at lbl_801E9D24+0x114 (handle at +0x14). The
   actor's current yaw comes from its basis (+0x30) applied to the forward axis
   (0,0,1), flattened to XZ and normalized (bare frsqrte scale); the wanted yaw
   from the planar unit direction from the actor's geometry position (+0x124,
   +0x30) to the other actor's. Both become rotations about the up axis
   lbl_802F4148; their slerp (fn_8008D420) by 1.75*rate goes to the actor's
   facing slot 0xC0 with the target, and when the two rotations' w differ by
   less than 0.002 the actor counter (+0x318) is set to 0x35 (fn_8007D6A0).
   Sibling of fn_8008E7AC (same TU; shapes shared) and slot40__14CJellyfishMoveFPC4Vec3PC4Vec3PC4Vec3if.

   lbl_80378AD0 (0.0f), lbl_80378ADC (1.0f) and lbl_80378AEC (0.5f) were pooled
   literals; the transform factors use the three read forms per component (as
   in fn_80084C50) and the folded y*y zero of the forward length the pointer
   form. The planar direction is a normalized temporary (memory resident, as in
   the original); reading the two z components into locals mine-first gives
   the original load order and register assignment. */
extern "C" const float lbl_80378AD0; /* 0.0f */
extern "C" const float lbl_80378ADC; /* 1.0f */
extern "C" const float lbl_80378AEC; /* 0.5f */
extern "C" const float lbl_80378B6C; /* 1.75f */
extern "C" const float lbl_80378B70; /* 0.002f */
typedef unsigned long Word;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3 operator*(float a)const{return Vec3(x*a,y*a,z*a);}
 float lengthSquared()const{return x*x+y*y+z*z;}
 Vec3&normalize(){float inv=reciprocalSqrt(lengthSquared());x*=inv;y*=inv;z*=inv;return *this;}
};
extern "C"{float fn_80285124(float,float);float fn_8028506C(float);float fn_80284FA8(float);double __fabs(double);}
struct Rotation{
 float w,x,y,z;
 Rotation(){}
 Rotation(const Vec3&axis,float angle){float h=angle*lbl_80378AEC;float c=fn_8028506C(h);Vec3 v=axis*fn_80284FA8(h);w=c;x=v.x;y=v.y;z=v.z;}
};
extern "C" const Vec3 lbl_802F4148; /* up axis */
struct Matrix{float m[9];};
struct Geometry{char unknown00[0x30];Vec3 position;};
struct Prefix{char unknown00[8];};
struct Counter{int value;};
struct Actor:Prefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
 virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
 virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();
 virtual const Handle*getHandle(int);
 virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();
 virtual void setFacing(void*,const Rotation*,int);
 char unknown0C[0x30-0xC];Matrix basis;char unknown54[0x124-0x54];Geometry*geometry;char unknown128[0x318-0x128];Counter counter;
};
struct Entry{Actor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
struct SceneRecord{char unknown00[0x14];Handle handle;char unknown18[0x34];};
extern "C" struct Global{char unknown00[0x114];SceneRecord*records;Manager*manager;}lbl_801E9D24;
inline Actor*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Owner{char unknown00[8];Actor*actor;};
struct Current{char unknown00[0x20];int index;};
extern "C"{Current*fn_8007D074(Owner*);void fn_8007D6A0(Counter*,int);Rotation fn_8008D420(const Rotation&,const Rotation&,float);}
extern "C" void fn_8008E254(Owner*self,void*,void*target,float rate){
 Actor*other=resolve(lbl_801E9D24.records[fn_8007D074(self)->index].handle);
 const Matrix&m=resolve(*self->actor->getHandle(0))->basis;
 float x=m.m[0]*lbl_80378AD0+m.m[3]**(const float*)&lbl_80378AD0+m.m[6]*lbl_80378ADC;
 float z=m.m[2]**(const float*)(unsigned long)&lbl_80378AD0+m.m[5]**(const float*)(unsigned long)&lbl_80378AD0+m.m[8]**(const float*)&lbl_80378ADC;
 float inv=reciprocalSqrt(x*x+*(const float*)&lbl_80378AD0+z*z);
 Rotation from(lbl_802F4148,fn_80285124(x*inv,z*inv));
 Geometry*mine=resolve(*self->actor->getHandle(0))->geometry;
 const Vec3&a=other->geometry->position;
 const Vec3&b=mine->position;
 float bz=b.z;float az=a.z;
 Vec3 n=Vec3(a.x-b.x,lbl_80378AD0,az-bz).normalize();
 Rotation to(lbl_802F4148,fn_80285124(n.x,n.z));
 Rotation r=fn_8008D420(from,to,lbl_80378B6C*rate);
 self->actor->setFacing(target,&r,0);
 if((float)__fabs(to.w-from.w)<lbl_80378B70)fn_8007D6A0(&self->actor->counter,0x35);
}
