/* Owner event 8A: push the related target along the owner-to-holder direction (fn_8004EB90).
 * Layout and handle idioms follow actor_transition_update_8004A238.cpp; the
 * retained related handle uses the empty typed-handle layers of
 * Handle_80040A28. The engine's fast normalize uses a raw reciprocal-square-root
 * estimate (frsqrte without frsp), which no compiler built-in produces, so it is
 * written as a minimal inline asm statement in the math helper. */
typedef unsigned long Word;
struct Handle_801F7F10 {union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct Entry {Node*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager {int count,capacity;Entry*entries;};
struct Context {char unknown00[0x118];Manager*manager;};
extern "C" {extern Context lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,short);}
struct Handle_80020478:Handle_801F7F10 {Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478 {Handle_80020834(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Handle_80020834(const Handle_80020834&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
template<int N>struct Layer:Layer<N-1>{Layer(){this->word=0;}~Layer(){}};
template<>struct Layer<1>:Handle_801F7F10{Layer(){word=0;}~Layer(){}};
struct Handle_80040A28:Layer<3> {Handle_80040A28(){word=0;}~Handle_80040A28(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct RetainedHandle:Handle_80040A28 {RetainedHandle(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~RetainedHandle(){}};
extern "C" {extern const float lbl_80378570,lbl_80378578;}
inline float rsqrtEstimate(register float x){register float r;asm{frsqrte r,x}return r;}
struct Vec {
 float x,y,z;
 Vec(){}
 Vec(float a,float b,float c):x(a),y(b),z(c){}
 Vec(const Vec&v):x(v.x),y(v.y),z(v.z){}
 Vec&operator=(const Vec&v){x=v.x;y=v.y;z=v.z;return*this;}
 Vec operator-(const Vec&v)const{return Vec(x-v.x,y-v.y,z-v.z);}
 Vec operator*(float k)const{return Vec(x*k,y*k,z*k);}
 Vec&operator+=(const Vec&v){x+=v.x;y+=v.y;z+=v.z;return*this;}
 float lengthSquared()const{return x*x+y*y+z*z;}
 void normalize(){if(lbl_80378570!=lengthSquared()){float inverse=rsqrtEstimate(lengthSquared());x*=inverse;y*=inverse;z*=inverse;}}
};
struct Placed {char unknown00[0x30];Vec position;};
struct Holder {char unknown00[0x124];Placed*placed;};
struct Prefix {char unknown00[8];};
struct Target:Prefix {
 virtual void s08();virtual void s0C();virtual void s10();virtual void s14();virtual void s18();virtual void s1C();
 virtual void s20();virtual void s24();virtual void s28();virtual void s2C();virtual void s30();virtual void s34();virtual void s38();virtual void s3C();
 virtual void s40();virtual void s44();virtual void s48();virtual void s4C();virtual void s50();virtual void s54();virtual void s58();virtual void s5C();
 virtual void s60();virtual void s64();virtual void s68();virtual void s6C();virtual void s70();virtual void s74();virtual void s78();virtual void s7C();
 virtual void s80();virtual void s84();virtual void s88();virtual void s8C();virtual void s90();virtual void s94();virtual void s98();virtual void s9C();
 virtual void sA0();virtual void sA4();virtual void sA8();virtual void sAC();
 virtual Vec position(int);
 char unknown0C[0x24];unsigned long long flags30;char unknown38[0x320];Vec velocity;
};
struct Node {char unknown00[0x38];unsigned long long flags38;char unknown40[0x30];Handle_801F7F10 handle70;};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Owner {char unknown00[0x28];Handle_801F7F10 handle;char unknown2C[0x34];Handle_801F7F10 holder;float speed;Vec direction;};
extern "C" {signed char fn_8025E9FC(Owner*,int);void*fn_801F7EB8(const Handle_801F7F10*);}
inline Vec placedPosition(const Handle_801F7F10&h){const Vec&p=((Holder*)resolve(h))->placed->position;return Vec(p.x,p.y,p.z);}
extern "C" void fn_8004EB90(Owner*self){
 if(fn_8025E9FC(self,0x8A)){
  Handle_80020834 held(Handle_80020834(self->handle));
  if(resolve(held)->flags38&0x200000000000ULL){
   Target*target=(Target*)resolve(resolve(RetainedHandle(held))->handle70);
   if(fn_801F7EB8(&self->holder)){
    self->direction=placedPosition(self->holder)-target->position(0);
   }else{
    self->direction=Vec(lbl_80378570,lbl_80378578,lbl_80378570);
   }
   self->direction.normalize();
   target->velocity+=self->direction*self->speed;
   target->flags30&=~0x1000000000ULL;
   target->flags30&=~0x8000000000ULL;
  }
 }
}
