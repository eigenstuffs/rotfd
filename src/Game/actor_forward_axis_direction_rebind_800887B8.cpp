/* fn_800887B8: on control event 0xB with a valid actor handle (+0x1AC), rotate
   the forward axis (0,0,1) by the 3x3 basis (+0x30) of the node behind the
   actor's virtual slot 0x9C handle, clamp it to unit length (fast sqrt; bare
   frsqrte scale), hand it to the handle target's virtual slot 0x18C, rebind the
   actor slot (fn_80038098) and clear its tracked handle (fn_80229098); then
   the usual counter refresh (+0x40F/+0x318) and fn_80092DAC(actor, dt).
   Sibling of fn_80084C50 (actor_related_yaw_transform_80084C50.cpp).
   Matching notes: lbl_80378AD0 (0.0f) / lbl_80378ADC (1.0f) were pooled
   literals; the factors use the three distinct read forms per component (see
   GUIDE "Pooled-literal emulation"). Handle_80038014 target is built from a
   temporary (no copy elision), as in fn_80087D04. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
extern "C" struct Context{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F7EB8(const Handle_801F7F10*);
 extern const float lbl_80378AD0,lbl_80378ADC;}
struct Handle_80021C40:Handle_801F7F10{Handle_80021C40(){word=0;}~Handle_80021C40(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021BCC:Handle_80021C40{Handle_80021BCC(){word=0;}~Handle_80021BCC(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021B54:Handle_80021BCC{Handle_80021B54(){word=0;}Handle_80021B54(const Handle_80021B54&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80021B54(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80025BF4:Handle_80021B54{Handle_80025BF4(){word=0;}Handle_80025BF4(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80025BF4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80025B74:Handle_80025BF4{Handle_80025B74(){word=0;}~Handle_80025B74(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80038014:Handle_80025B74{Handle_80038014(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Handle_80038014(const Handle_80038014&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80038014(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
inline float fastSqrt(register float x){register float r;asm{frsqrte f4,x
 fres r,f4}return r;}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}
 float lengthSquared()const{return x*x+y*y+z*z;}
 float length()const{float sq=lengthSquared();float r=lbl_80378AD0;if(sq!=r)r=fastSqrt(sq);return r;}};
struct Matrix{Vec3 r0,r1,r2;};
struct Prefix{char unknown00[8];};
struct Frame:Prefix{char unknown08[0x28];Matrix matrix;};
struct Target:Prefix{
 virtual void s02();virtual void s03();virtual void s04();virtual void s05();virtual void s06();virtual void s07();virtual void s08();virtual void s09();
 virtual void s10();virtual void s11();virtual void s12();virtual void s13();virtual void s14();virtual void s15();virtual void s16();virtual void s17();virtual void s18();virtual void s19();
 virtual void s20();virtual void s21();virtual void s22();virtual void s23();virtual void s24();virtual void s25();virtual void s26();virtual void s27();virtual void s28();virtual void s29();
 virtual void s30();virtual void s31();virtual void s32();virtual void s33();virtual void s34();virtual void s35();virtual void s36();virtual void s37();virtual void s38();virtual void s39();
 virtual void s40();virtual void s41();virtual void s42();virtual void s43();virtual void s44();virtual void s45();virtual void s46();virtual void s47();virtual void s48();virtual void s49();
 virtual void s50();virtual void s51();virtual void s52();virtual void s53();virtual void s54();virtual void s55();virtual void s56();virtual void s57();virtual void s58();virtual void s59();
 virtual void s60();virtual void s61();virtual void s62();virtual void s63();virtual void s64();virtual void s65();virtual void s66();virtual void s67();virtual void s68();virtual void s69();
 virtual void s70();virtual void s71();virtual void s72();virtual void s73();virtual void s74();virtual void s75();virtual void s76();virtual void s77();virtual void s78();virtual void s79();
 virtual void s80();virtual void s81();virtual void s82();virtual void s83();virtual void s84();virtual void s85();virtual void s86();virtual void s87();virtual void s88();virtual void s89();
 virtual void s90();virtual void s91();virtual void s92();virtual void s93();virtual void s94();virtual void s95();virtual void s96();virtual void s97();virtual void s98();
 virtual void setDirection(const Vec3&);};
struct Counter{int value;};
struct Actor:Prefix{
 virtual void s02();virtual void s03();virtual void s04();virtual void s05();virtual void s06();virtual void s07();virtual void s08();virtual void s09();
 virtual void s10();virtual void s11();virtual void s12();virtual void s13();virtual void s14();virtual void s15();virtual void s16();virtual void s17();virtual void s18();virtual void s19();
 virtual void s20();virtual void s21();virtual void s22();virtual void s23();virtual void s24();virtual void s25();virtual void s26();virtual void s27();virtual void s28();virtual void s29();
 virtual void s30();virtual void s31();virtual void s32();virtual void s33();virtual void s34();virtual void s35();virtual void s36();virtual void s37();virtual void s38();
 virtual const Handle_801F7F10*getHandle(int);
 char unknown0C[0x1AC-0xC];Handle_801F7F10 handle;char unknown1B0[0x318-0x1B0];Counter counter;char unknown31C[0x40F-0x31C];signed char enabled;};
struct Owner{char unknown00[8];Actor*actor;void*control;};
inline void*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
extern "C"{signed char fn_8025E9FC(void*,int);void fn_80038098(Actor*,const Handle_80021B54&);void fn_80229098(Actor*,const Handle_80025BF4&);int fn_80092844(Actor*);void fn_8007D6A0(Counter*,int);void fn_80092DAC(Actor*,float);}
extern "C" void fn_800887B8(Owner*self,float dt){
 if(fn_8025E9FC(self->control,0xB)&&fn_801F7EB8(&self->actor->handle)){
  Frame*frame=(Frame*)resolve(*self->actor->getHandle(0));
  const Matrix&m=frame->matrix;
  float x=m.r0.x*lbl_80378AD0+m.r1.x**(const float*)&lbl_80378AD0+m.r2.x*lbl_80378ADC;
  float y=m.r0.y*lbl_80378AD0+m.r1.y*lbl_80378AD0+m.r2.y**(const float*)(unsigned long)&lbl_80378ADC;
  float z=m.r0.z**(const float*)(unsigned long)&lbl_80378AD0+m.r1.z**(const float*)(unsigned long)&lbl_80378AD0+m.r2.z**(const float*)&lbl_80378ADC;
  Vec3 direction(x,y,z);
  if(direction.length()>*(const float*)&lbl_80378ADC){float s=reciprocalSqrt(direction.lengthSquared());direction.x*=s;direction.y*=s;direction.z*=s;}
  Handle_80025BF4 handle(self->actor->handle);
  Handle_80038014 target((Handle_80038014(handle)));
  ((Target*)resolve(target))->setDirection(direction);
  fn_80038098(self->actor,Handle_80021B54(handle));
  fn_80229098(self->actor,Handle_80025BF4());
 }
 if(self->actor->enabled)fn_8007D6A0(&self->actor->counter,fn_80092844(self->actor));
 fn_80092DAC(self->actor,dt);
}
