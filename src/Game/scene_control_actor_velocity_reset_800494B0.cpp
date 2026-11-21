/* Scene control 8A/8B handler: releases the related actor control state and resets the controlled actor velocity from the owner direction. */
typedef unsigned long Word;
struct Handle_801F7F10 {union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct ActorIndex{int value;ActorIndex(int v):value(v){}operator const int&()const{return value;}};
struct Entry {Node*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}bool matchesTag(signed char t)const{return tag==t;}};struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};
struct Manager {int count,capacity;EntryArray entries;};
struct Related {char unknown00[0x1C];Handle_801F7F10*handle;};
struct Context {char unknown00[0x118];Manager*manager;char unknown11C[0x20];Related*related;};
extern "C" {extern Context lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,short);}
struct Handle_80020478:Handle_801F7F10 {Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478 {Handle_80020834(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Handle_80020834(const Handle_80020834&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
template<int N>struct Layer:Layer<N-1>{Layer(){this->word=0;}~Layer(){}};
template<>struct Layer<1>:Handle_801F7F10{Layer(){word=0;}~Layer(){}};
struct Handle_80040A28:Layer<3>{Handle_80040A28(){word=0;}~Handle_80040A28(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ActorHandle:Handle_80040A28{ActorHandle(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~ActorHandle(){}};
struct Vec {float x,y,z;Vec(){}Vec(float a,float b,float c):x(a),y(b),z(c){}Vec operator*(float k)const{return Vec(x*k,y*k,z*k);}Vec&operator=(const Vec&v){x=v.x;y=v.y;z=v.z;return*this;}Vec&operator+=(const Vec&v){x+=v.x;y+=v.y;z+=v.z;return*this;}};
struct Actor;
struct Node {char unknown00[0x30];unsigned long long flags30;unsigned long long flags38;char unknown40[0x30];Handle_801F7F10 handle70;char unknown74[0x3C];Handle_801F7F10*child;};
struct Actor {char unknown00[0x30];unsigned long long flags30;char unknown38[0x110];float value148;char unknown14C[0x14];float value160;char unknown164[0x1B4];char controller[0x40];Vec velocity;char unknown364[0xA1];unsigned char flag405;};
inline Node*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const ActorIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
struct Prefix {char unknown00[8];};
struct Owner:Prefix {
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
virtual void resetFirst();
virtual void slot80();
virtual void resetSecond();
char unknown0C[0x1C];Handle_801F7F10 handle;char unknown2C[0x48];float scale;Vec direction;
};
extern "C" {signed char fn_8025E9FC(Owner*,int);Node*fn_801F7EB8(const Handle_801F7F10*);signed char fn_8007D604(void*,int);void fn_8007D6A0(void*,int);extern const float lbl_80378570;extern const Vec game_vec3_zero;}
inline Node*currentChild(){return resolve(*resolve(*lbl_801E9D24.related->handle)->child);}
inline Actor*optionalActor(const Handle_801F7F10*h){if(fn_801F7EB8(h))return (Actor*)resolve(*h);return 0;}
extern "C" void fn_800494B0(Owner*self){
 if(fn_8025E9FC(self,0x8A)){
  self->resetFirst();self->resetSecond();
  Handle_80020834 held(Handle_80020834(self->handle));
  if(resolve(held)->flags38&0x200000000000ULL){
   if(resolve(held)->flags38&0x2000000ULL){
    const Handle_801F7F10*h=&currentChild()->handle70;Actor*actor=fn_801F7EB8(h)?(Actor*)resolve(*h):0;
    if(fn_8007D604(actor->controller,0x2F))return;
    fn_8007D6A0(actor->controller,0xB);
    actor->flag405=1;
   }
   Actor*actor=(Actor*)resolve(resolve(ActorHandle(held))->handle70);
   float zero=lbl_80378570;actor->velocity=game_vec3_zero;
   actor->value160=zero;actor->value148=zero;
   actor->velocity+=self->direction*self->scale;
   actor->flags30&=~0x1000000000ULL;
   actor->flags30&=~0x8000000000ULL;
  }
 }else if(fn_8025E9FC(self,0x8B)){self->resetFirst();self->resetSecond();}
}
