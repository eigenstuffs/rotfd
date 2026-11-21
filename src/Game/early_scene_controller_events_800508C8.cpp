/* fn_800508C8: early scene controller event handler (events 0x8A/0x8B/0x8E).
 * EXACT: the alternate-flag predicate must be a nested if with a local result
 * (bool r=false; if(alternate){if(flags&mask)r=true;}) so result colours first. */
typedef unsigned long Word;
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Node{
 char unknown0[0x38];unsigned long long flags;char unknown40[0x30];Handle actor;char unknown74[0x3C];Handle*child;char unknownB4[0x264];char controller;
 signed char hasFlags(unsigned long long mask)const{if(flags&mask)return 1;return 0;}
};
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Related{char unknown0[0x1C];Handle*handle;};
extern "C"struct Global{char unknown0[0x118];Manager*manager;char unknown11C[0x20];Related*related;}lbl_801E9D24;
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
extern "C"Word fn_801F7EB8(const Handle*);
inline Node*relatedActor(){const Handle*h=&resolve(*resolve(*lbl_801E9D24.related->handle)->child)->actor;if(fn_801F7EB8(h))return resolve(*h);return 0;}
struct Prefix{char unknown0[8];};
struct Self:Prefix{
 virtual void slot8();virtual void slotC();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
 virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void finish();virtual void slot80();virtual void update();
 char unknownC[0x1C];Handle target;float value;char unknown30[0x40];signed char flag70,flag71;char unknown72[0xA];signed char alternate;unsigned char kind;
 int getKind()const{return kind;}
 char unknown7E[2];Handle first,second;
 bool alternative(Node*node)const{bool r=false;if(alternate){if(node->flags&0x10000000ULL)r=true;}return r;}
 signed char activeTarget()const{Node*node=resolve(target);signed char result=1;if(!node->hasFlags(0x2000000ULL)&&!alternative(node))result=0;return result;}
};
struct State{char unknown0[0x218];unsigned char enabled;};
extern "C"{signed char fn_8025E9FC(Self*,int);void fn_80050D74(Self*,signed char);void fn_8005112C(Self*,unsigned char);void fn_8005123C(Self*);State*fn_8007D074();void fn_8006D2DC(Node*,Node*);signed char fn_8007D604(void*,int);void fn_8006D684(int);extern const float lbl_80378578,lbl_8037857C;}
extern "C"void fn_800508C8(Self*self){
 if(fn_8025E9FC(self,0x8A)){
  if(self->activeTarget()){
   if(self->flag70)fn_80050D74(self,1);else fn_80050D74(self,0);
   if(self->flag71)fn_8005112C(self,0);else if(self->getKind()!=1)fn_8005112C(self,1);
   fn_8005123C(self);
   if(self->getKind()==1){State*state=fn_8007D074();state->enabled=1;Node*first=resolve(self->first);fn_8006D2DC(first,resolve(self->second));}
  }
  self->update();self->finish();
 }else if(fn_8025E9FC(self,0x8B)){
  int active=self->activeTarget();
  signed char state=fn_8007D604(&relatedActor()->controller,6);
  self->update();self->finish();
  if((signed char)active&&state){fn_80050D74(self,1);fn_8005112C(self,0);}
 }else if(fn_8025E9FC(self,0x8E)){
  if(lbl_80378578==self->value)fn_80050D74(self,1);
  else if(lbl_8037857C==self->value){fn_8005112C(self,0);if(self->getKind()==1){State*state=fn_8007D074();state->enabled=1;fn_8006D684(1);}}
 }
}
