/* fn_8008E7AC: rotates the forward axis (0,0,1) by the 3x3 basis (+0x30) of
   the node behind the actor's virtual slot 0x9C handle, flattens it to the XZ
   plane and normalizes it (bare frsqrte scale), and takes its yaw. Two
   rotations about the up axis lbl_802F4148 are built: one for the yaw and one
   for yaw + lbl_80378B8C (0.1*pi). A function-local static (lbl_8037776C,
   guard lbl_80377770, initialized from lbl_80378B90 = 50.0f) is advanced by
   0.5 every call; the slerp (fn_8008D420) of the two rotations by
   static*rate is passed to the actor's facing slot 0xC0 with the target.
   Sibling of slot40__14CJellyfishMoveFPC4Vec3PC4Vec3PC4Vec3if (owner_yaw_toward_direction_80098CD0.cpp) and
   fn_80084C50 (actor_related_yaw_transform_80084C50.cpp).

   lbl_80378AD0 (0.0f), lbl_80378ADC (1.0f) and lbl_80378AEC (0.5f) were pooled
   literals of the original translation unit; the transform factors use the
   three distinct read forms per component as in fn_80084C50, and the folded
   zero y*y term of the planar length uses the pointer form. The static local
   is written with an explicit guard on the existing .sbss labels (the original
   compiler-generated guard has the same code). */
extern "C" const float lbl_80378AD0; /* 0.0f */
extern "C" const float lbl_80378ADC; /* 1.0f */
extern "C" const float lbl_80378AEC; /* 0.5f */
extern "C" const float lbl_80378B8C; /* 0.31415927f */
extern "C" const float lbl_80378B90; /* 50.0f */
typedef unsigned long Word;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3 operator*(float a)const{return Vec3(x*a,y*a,z*a);}};
extern "C"{float fn_80285124(float,float);float fn_8028506C(float);float fn_80284FA8(float);}
struct Rotation{
 float w,x,y,z;
 Rotation(){}
 Rotation(const Vec3&axis,float angle){float h=angle*lbl_80378AEC;float c=fn_8028506C(h);Vec3 v=axis*fn_80284FA8(h);w=c;x=v.x;y=v.y;z=v.z;}
};
extern "C" const Vec3 lbl_802F4148; /* up axis */
extern "C" signed char lbl_80377770; /* static guard */
extern "C" float lbl_8037776C; /* static accumulator */
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
struct Matrix{float m[9];};
struct Entity{char unknown00[0x30];Matrix basis;};
struct Entry{Entity*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline Entity*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Prefix{char unknown00[8];};
struct Actor:Prefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
 virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
 virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();
 virtual const Handle*getHandle(int);
 virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();
 virtual void setFacing(void*,const Rotation*,int);
};
struct Owner{char unknown00[8];Actor*actor;};
extern "C"{Rotation fn_8008D420(const Rotation&,const Rotation&,float);}
extern "C" void fn_8008E7AC(Owner*self,void*target,float rate){
 const Matrix&m=resolve(*self->actor->getHandle(0))->basis;
 float x=m.m[0]*lbl_80378AD0+m.m[3]**(const float*)&lbl_80378AD0+m.m[6]*lbl_80378ADC;
 float z=m.m[2]**(const float*)(unsigned long)&lbl_80378AD0+m.m[5]**(const float*)(unsigned long)&lbl_80378AD0+m.m[8]**(const float*)&lbl_80378ADC;
 float inv=reciprocalSqrt(x*x+*(const float*)&lbl_80378AD0+z*z);
 float yaw=fn_80285124(x*inv,z*inv);
 Rotation from(lbl_802F4148,yaw);
 Rotation to(lbl_802F4148,lbl_80378B8C+yaw);
 if(!lbl_80377770){lbl_80377770=1;lbl_8037776C=lbl_80378B90;}
 lbl_8037776C=lbl_8037776C+lbl_80378AEC;
 Rotation r=fn_8008D420(from,to,lbl_8037776C*rate);
 self->actor->setFacing(target,&r,0);
}
