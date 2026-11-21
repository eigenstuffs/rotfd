/* Per-frame queued event dispatch for the scripted-agent component (subobject at +0x90). */
typedef unsigned long Word;typedef unsigned long long Wide;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Node{char unknown00[0x120];Word mode;char unknown124[0x2B4];void*script;};
struct Entry{Node*object;char unknown04[8];signed char tag;char pad[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Actor{char unknown00[0x38];Wide flags;char unknown40[0x18];Handle handle;};
struct Agent{char unknown00[0x38];Wide flags;char unknown40[0x44];unsigned char kind84;char pad85;unsigned short value86;unsigned char kind88;char pad89;unsigned short value8A;
 signed char hasFlags(Wide mask)const{if(flags&mask)return 1;return 0;}};
struct Holder{char unknown00[0x2C];Agent*agent;};
struct SelfPrefix{char unknown00[4];};
struct Self:SelfPrefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();
 virtual Actor*actor();
 virtual Agent*agent();
 virtual float value();
 virtual Holder*holder();
 virtual signed char hasEvent(int);
 virtual const Handle*getHandle();
 virtual void slot2C();virtual void slot30();virtual void slot34();
 virtual void setMode(int);
 char unknown08[0x34];signed char active;char unknown3D[0xD7];
 void*handler114;void*handler118;void*handler11C;void*handler120;void*handler124;void*handler128;void*handler12C;void*handler130;void*handler134;void*handler138;void*handler13C;void*handler140;void*handler144;void*handler148;void*handler14C;
 signed char triggered;
};
extern "C"{
extern const float lbl_803786A8;
signed char fn_8006653C(Self*,int);
void fn_80067F1C(Self*,Agent*);
void fn_80067D0C(Self*,Agent*,unsigned char,short);
void fn_802073E8(Actor*,int,Agent*,float);
void fn_80069330(Self*,Actor*,int);
void fn_80068254(Self*,Agent*);
void fn_80068358(Self*,Agent*);
void fn_80068754(Self*,void*);
void fn_80067904(Self*,Agent*,int);
void fn_80067E18(Self*,Agent*);
void fn_80069078(Self*,int);
void fn_8006EEC0(Self*,int);
void fn_80286058(Actor*,int);
void fn_80067B0C(Self*,unsigned short);
void fn_80067C0C(Self*,unsigned short);
void fn_80068CB4(Self*,int);
}
extern "C" void fn_8005EED4(Self*self){
 if(!(self->actor()->flags&0x8000000000ULL)){
  if(self->hasEvent(5))self->setMode(0x86);
  if(self->hasEvent(6))self->setMode(0);
 }
 if(self->hasEvent(0x85)){
  if((resolve(self->actor()->handle)->mode&0x40000)&&self->handler12C)fn_80067F1C(self,self->agent());
 }
 int kind=0;int value=0;
 if(!(self->actor()->flags&0x8000000000ULL)){
  resolve(*self->getHandle());
  if(!fn_8006653C(self,0xC)&&!fn_8006653C(self,0xD)){
   if(self->hasEvent(0x87)&&self->handler124){
    if((self->agent()->flags&0x200000000000ULL)||(self->agent()->flags&0x20000000ULL)){
     kind=(unsigned char)self->agent()->kind88;value=self->agent()->value8A;
    }else if(self->agent()->flags&0x400000000000ULL){
     kind=5;value=0x22;
    }
    if(self->agent()->flags&0x10000000ULL)fn_802073E8(self->actor(),0xAB,self->agent(),lbl_803786A8);
    fn_80067D0C(self,self->agent(),kind,value);
   }
   signed char direct=0;
   if(self->hasEvent(0x86)||self->hasEvent(0x81)||self->hasEvent(0x82)||self->hasEvent(0x84)||(direct=self->hasEvent(0x83))){
    if((resolve(self->actor()->handle)->mode&0x40000)&&!self->triggered){
     self->triggered=1;
     if(self->handler124){
      Agent*agent=self->holder()->agent;
      if(agent->hasFlags(0x200000000000ULL)){kind=(unsigned char)agent->kind88;value=agent->value8A;}
      else if(agent->flags&0x20000000ULL){kind=(unsigned char)agent->kind84;value=agent->value86;}
      else if(agent->flags&0x400000000000ULL){kind=5;value=0x22;}
      if(agent->flags&0x10000000ULL)fn_802073E8(self->actor(),0xAB,agent,lbl_803786A8);
      if(direct==1)fn_80069330(self,self->actor(),999);
      else fn_80067D0C(self,agent,kind,value);
     }
    }
   }else self->triggered=0;
  }
 }
 if(self->hasEvent(0x8A)&&self->handler138)fn_80068254(self,self->agent());
 if(self->hasEvent(0x8B)&&self->handler13C)fn_80068358(self,self->agent());
 self->active=0;
 if(self->hasEvent(0x90)||self->hasEvent(0x8D)){
  self->active=1;
  if(self->handler14C)fn_80068754(self,resolve(*self->getHandle())->script);
 }
 if(!(self->actor()->flags&0x8000000000ULL)){
  if(self->hasEvent(0xAE))fn_80067904(self,self->agent(),900);
  if(resolve(self->actor()->handle)->mode&0x80){
   if(self->hasEvent(0xB0))fn_80067904(self,self->agent(),0x389);
   if(self->hasEvent(0xAF))fn_80067904(self,self->agent(),0x385);
   if(self->hasEvent(0xB1))fn_80067904(self,self->agent(),0x38D);
   if(self->hasEvent(0xB2))fn_80067904(self,self->agent(),0x38E);
   if(self->hasEvent(0xB3))fn_80067904(self,self->agent(),0x398);
   if(self->hasEvent(0xB4))fn_80067904(self,self->agent(),0x3A2);
   if(self->hasEvent(0xB5))fn_80067904(self,self->agent(),0x3AC);
   if(self->hasEvent(0xB6))fn_80067904(self,self->agent(),0x3B6);
   if(self->hasEvent(0xB7))fn_80067904(self,self->agent(),0x3C0);
   if(self->hasEvent(0xB8))fn_80067904(self,self->agent(),0x3CA);
   if(self->hasEvent(0xB9))fn_80067904(self,self->agent(),0x3D4);
   if(self->hasEvent(0xBA))fn_80067904(self,self->agent(),0x3DE);
  }
 }
 if(self->hasEvent(0xAB)&&self->handler128)fn_80067E18(self,self->agent());
 if(self->hasEvent(0xA6))fn_80069078(self,1);
 if(self->hasEvent(0xA7))fn_80069078(self,0);
 if(self->hasEvent(0xA5))fn_8006EEC0(self,1);
 if(self->hasEvent(0xA4))fn_8006EEC0(self,0);
 while(self->hasEvent(0xAA)){
  if(self->handler114)fn_80067904(self,self->agent(),(int)self->value());
  fn_80286058(self->actor(),0xAA);
 }
 if(self->hasEvent(0xA2)){
  int v=(int)self->value();
  if(self->handler11C)fn_80067B0C(self,v);
 }
 if(self->hasEvent(0xA3)){
  int v=(int)self->value();
  if(self->handler120)fn_80067C0C(self,v);
 }
 if(self->hasEvent(0xCF))fn_80068CB4(self,0);
 if(self->hasEvent(0xDE))fn_80069330(self,self->actor(),0x3E5);
}
