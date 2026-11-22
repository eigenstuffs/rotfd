/* Related-owner tick, aim and contact selection (slot58__9LodMove_ZFv, slot134__9LodMove_ZFv,
   slot130__9LodMove_ZFv); same engine TU as slot108__9LodMove_ZFv/slot118__9LodMove_ZFv (-O4,p, no EH).
   slot58__9LodMove_ZFv: flag 0x4000 of the primary resource propagates to 0x40000 as
   a select (`test ? 0x40000 : 0`), which keeps the original operand order of
   the neg/and and both flag loads.
   slot134__9LodMove_ZFv: normalized direction (fastSqrt) passed with two slot 0x88
   points to slot 0x168; handle copies bind through reference accessors.
   slot130__9LodMove_ZFv: slot 0x48 takes a 64-bit mode (r5:r6 = 0:1/0:2); the peer
   resolve uses if/return with an Entry reference (puts the stack mask stores
   inside it); the parent resolve returns a Word so its null is not merged
   with the flag-test zero. */
inline void*operator new(unsigned long,void*p){return p;}
typedef unsigned long Word;
inline float fastSqrt(register float x){register float r;asm{frsqrte f4,x
 fres r,f4}return r;}
struct Handle_801F7F10{union{Word value;struct{signed int generation:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct EngineEntry{void*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct EngineManager{Word unknown00[2];EngineEntry*entries;};
extern "C"{
 extern struct EngineGlobals{char unknown00[0x118];EngineManager*manager;}lbl_801E9D24;
 void fn_801F86C8(EngineManager*,const Handle_801F7F10*,int);
 Word fn_801F7EB8(const Handle_801F7F10*);
 extern const float lbl_8037B0C8,lbl_8037B0CC,lbl_8037B0D0,lbl_8037B0D4,lbl_8037B0D8,lbl_8037B0DC;
}
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3(const Vec3&v):x(v.x),y(v.y),z(v.z){}
 Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return *this;}
 Vec3 operator-(const Vec3&v)const{return Vec3(x-v.x,y-v.y,z-v.z);}
 float length()const{float sq=x*x+y*y+z*z;float r=lbl_8037B0C8;if(sq!=r)r=fastSqrt(sq);return r;}
 void operator*=(float s){x*=s;y*=s;z*=s;}};
extern "C" const Vec3 game_vec4_zero;

/* ---- slot58__9LodMove_ZFv ---- */
namespace related_tick{
struct Handle{union{Word value;struct{signed int generation:8,index:24;}bits;};};
struct Storage{char unknown00[8];};
struct Owner:Storage{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void tick(void*,void*,float);virtual void slot5C();virtual void slot60();virtual void slot64();
 virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
 virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const Handle*getHandle(int);
 char unknown0C[0x24];unsigned long long flags;char unknown38[0x174];Handle related;char unknown1B0[0x48];Handle second;
 unsigned long long getFlags()const{return flags;}
};
struct Resource{char unknown00[0x120];Word flags;void addFlags(Word mask){flags|=mask;}Word test(Word mask)const{Word loadedFlags=flags;return (loadedFlags&mask)!=0;}};
inline Owner*resolve(const Handle&h){int index=h.bits.index;EngineManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();return generation==h.bits.generation?(Owner*)m->entries[index].object:0;}
}
extern "C" void slot58__12ObjectMove_ZFv(related_tick::Owner*,void*,void*,float);
extern "C" void slot58__9LodMove_ZFv(related_tick::Owner*self,void*context,void*argument,float value){
 using namespace related_tick;
 Owner*owner=resolve(self->related);
 if(owner){unsigned long long flags=owner->getFlags();if(flags&0x18ULL){if(flags&8ULL)flags|=0x2000ULL;if(flags&16ULL)flags|=0x8000ULL;owner->flags|=flags;owner->tick(context,argument,value);owner->flags&=~0xA000ULL;}}
 owner=resolve(self->second);
 if(owner){owner->tick(context,argument,value);Resource*resource=(Resource*)resolve(*owner->getHandle(0));resource->addFlags(resource->test(0x4000)?0x40000:0);}
 slot58__12ObjectMove_ZFv(self,context,argument,value);
}

/* ---- slot134__9LodMove_ZFv ---- */
namespace related_aim{
struct Vec4:Vec3{float w;Vec4(const Vec3&v,float f):Vec3(v),w(f){}};
struct Handle1:Handle_801F7F10{Handle1(){value=0;}};
struct Handle2:Handle1{Handle2(){value=0;}};
struct Copy2:Handle2{Copy2(const Handle_801F7F10&input){value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}};
struct Prefix{char unknown00[8];};
struct Node:Prefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
 virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
 virtual signed char getPoint(Vec4&,int,int);virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual void slot9C();virtual void slotA0();virtual void slotA4();
 virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();virtual void slotC0();virtual void slotC4();
 virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void slotD4();virtual void slotD8();virtual void slotDC();virtual void slotE0();virtual void slotE4();
 virtual void slotE8();virtual void slotEC();virtual void slotF0();virtual void slotF4();virtual void slotF8();virtual void slotFC();virtual void slot100();virtual void slot104();
 virtual void slot108();virtual void slot10C();virtual void slot110();virtual void slot114();virtual void slot118();virtual void slot11C();virtual void slot120();virtual void slot124();
 virtual void slot128();virtual void slot12C();virtual void slot130();virtual void slot134();virtual void slot138();virtual void slot13C();virtual void slot140();virtual void slot144();
 virtual void slot148();virtual void slot14C();virtual void slot150();virtual void slot154();virtual void slot158();virtual void slot15C();virtual void slot160();virtual void slot164();
 virtual void aim(void*,const Vec4&,const Vec3&,float);
 char unknown0C[0x168-0xC];Handle_801F7F10 first;char unknown16C[0x1F8-0x16C];Handle_801F7F10 second;
 Handle_801F7F10&getFirst(){return first;}Handle_801F7F10&getSecond(){return second;}
};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;EngineManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();return generation==h.bits.generation?(Node*)m->entries[index].object:0;}
}
extern "C" void slot134__9LodMove_ZFv(related_aim::Node*self,void*context,const Vec3*from,const Vec3*to){
 using namespace related_aim;
 Vec3 direction=*to-*from;
 float length=direction.length();
 float scale=length;
 if(length<lbl_8037B0CC){direction=Vec3(*(const float*)&lbl_8037B0C8,lbl_8037B0D4,*(const float*)&lbl_8037B0C8);scale=lbl_8037B0D0;}
 else direction*=lbl_8037B0D4/length;
 Copy2 first(self->getFirst());
 Vec4 point(game_vec4_zero,lbl_8037B0D4);
 if(!self->getPoint(point,2,0))return;
 Copy2 second(self->getSecond());
 Vec4 other(game_vec4_zero,lbl_8037B0D4);
 if(fn_801F7EB8(&second)&&resolve(second)->getPoint(other,2,0))self->aim(context,other,direction,scale);
 self->aim(context,point,direction,scale);
}

/* ---- slot130__9LodMove_ZFv ---- */
namespace related_select{
struct Pair{float x,y;Pair(float a,float b):x(a),y(b){}};
struct Sphere{Vec3 center;float radius;Sphere(const Vec3&p,float r):center(p),radius(r){}};
struct Candidate{char unknown00[0x10];Handle_801F7F10 early;char unknown14[8];Handle_801F7F10 owner,peer;char unknown24[0xFC];Word flags;char unknown124[0xC];Handle_801F7F10 identity;};
struct Results;
struct Storage{Word unknown00;Handle_801F7F10 identity;};
struct Owner:Storage{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();
 virtual signed char collect(Candidate*,Owner*,const Sphere*,Results*,unsigned long long,unsigned long long);
 virtual signed char attach(const Handle_801F7F10*,unsigned long long);
 virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
 virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
 virtual signed char getSphere(Sphere*,int,int);
 char unknown0C[0x18];Handle_801F7F10 resource,second;unsigned long long flags,flags2;char unknown40[0x30];Handle_801F7F10 parent;char unknown74[0x138];Handle_801F7F10 related,target;
 char unknown1B4[0x128];float height;char unknown2E0[0x18];Word selectedF8,selectedFC;Candidate*selected;Word selected04,selected08;signed char ready;
};
inline Owner*resolve(const Handle_801F7F10&h){int index=h.bits.index;EngineManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();return generation==h.bits.generation?(Owner*)m->entries[index].object:0;}
inline Owner*resolvePeer(const Handle_801F7F10&h){int index=h.bits.index;EngineManager*m=lbl_801E9D24.manager;EngineEntry&e=m->entries[index];int generation=e.getGeneration();if(generation==h.bits.generation)return (Owner*)e.object;return 0;}
inline Word resolveWord(const Handle_801F7F10&h){int index=h.bits.index;EngineManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();return generation==h.bits.generation?(Word)m->entries[index].object:0;}
struct Collected{char unknown00[0xC];float height;char unknown10[0xC];Candidate*candidate;char unknown20[8];Collected(){candidate=0;}~Collected(){}};
struct Results{Word storage[0xA00];int count;Results():count(0){}Collected*data(){return reinterpret_cast<Collected*>(storage);}Collected&operator[](unsigned int i){return data()[i];}
 void resize(int n){if(n>count){for(int i=count;i<n;++i)new(&(*this)[i])Collected();}else if(n<count){for(int i=count-1;i>=n;--i)(*this)[i].~Collected();}count=n;}
 ~Results(){for(int i=0;i<count;++i)(*this)[i].~Collected();}};
struct Zero1:Handle_801F7F10{Zero1(){value=0;}};struct Zero2:Zero1{Zero2(){value=0;}};struct Zero3:Zero2{Zero3(){value=0;}};
struct Copied3:Zero3{Copied3(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Copied3(){}};
struct Grid{char unknown00[0x40];Candidate*candidates[4096];};
struct Context{char unknown00[0x80BC];Grid grid;Grid&getGrid(){return grid;}};
inline Word isValid(const Handle_801F7F10&h){return fn_801F7EB8(&h)!=0;}
}
extern "C"{int fn_80266C78(void*,const related_select::Pair*,const related_select::Pair*);signed char fn_8021F308(related_select::Owner*);void fn_80229098(related_select::Owner*,const Handle_801F7F10&);}
extern "C" void slot130__9LodMove_ZFv(related_select::Owner*self,related_select::Context*context){
 using namespace related_select;
 Sphere sphere(game_vec4_zero,lbl_8037B0D8);
 if(!self->getSphere(&sphere,2,0))return;
 sphere.radius*=lbl_8037B0DC;
 Pair minimum(sphere.center.x-sphere.radius,sphere.center.z-sphere.radius);
 Pair maximum(sphere.center.x+sphere.radius,sphere.center.z+sphere.radius);
 self->ready=0;self->selected=0;self->selected04=0;self->selected08=0;self->selectedFC=0;self->selectedF8=0;
 Results results;
 int count=fn_80266C78(&context->grid,&minimum,&maximum);
 Candidate**current=context->getGrid().candidates;
 for(int i=0;i<count;++i){
  Candidate*candidate=*current++;
  if(candidate->flags&0x10000)continue;
  if(!(candidate->flags&0x40000))continue;
  Owner*owner=resolve(candidate->owner);
  if(!owner)continue;
  if(!resolve(candidate->identity))continue;
  if(owner->collect(candidate,resolvePeer(candidate->peer),&sphere,&results,0x00001E0000000000ULL,0ULL)){
   if(!self->ready||results[0].height<self->height){self->ready=1;self->selected=results[0].candidate;self->height=results[0].height;}
   results.resize(0);
  }
 }
 if(self->ready){
  if(!resolve(self->resource)->attach(&self->selected->identity,1))return;
  Owner*owner=resolve(self->selected->identity);
  if(!owner->attach(&self->resource,2))return;
  if(fn_801F7EB8(&self->related))return;
  if(resolve(self->selected->early))return;
  Owner*parent;
  if(owner->flags2&0x400000ULL)parent=(Owner*)resolveWord(owner->parent);
  else return;
  if(!fn_8021F308(parent)){
   if(fn_801F7EB8(&parent->target))return;
   if((signed char)isValid(parent->second))return;
  }
  const Handle_801F7F10&original=parent->identity;
  fn_80229098(self,Copied3(original));
 }
}
