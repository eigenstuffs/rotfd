/* Owner event 8A/BE related-target notification control (fn_8004E058). */
typedef unsigned long Word;
struct Handle_801F7F10 {union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct Entry {Node*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager {int count,capacity;Entry*entries;};
struct Related {char unknown00[0x1C];Handle_801F7F10*handle;};
struct Context {char unknown00[0x118];Manager*manager;char unknown11C[8];void*events;char unknown128[0x14];Related*related;};
extern "C" {extern Context lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,short);}
struct Handle_80020478:Handle_801F7F10 {Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478 {Handle_80020834(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Handle_80020834(const Handle_80020834&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Vec {float x,y,z;};
struct Node {char unknown00[0x38];unsigned long long flags38;char unknown40[0x30];Handle_801F7F10 handle70;char unknown74[0x24];Handle_801F7F10*child;char unknown9C[0x14];Handle_801F7F10*related;};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
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
virtual void slot7C();
virtual void notify(int);
char unknown0C[0x1C];Handle_801F7F10 handle;char unknown2C[0x4C];Vec direction;float low;char unknown88[4];float high;float scale90;char unknown94;signed char notifyOn;signed char notifyOff;char unknown97;float second,first;
};
template<int N>struct ReturnLayer:ReturnLayer<N-1>{~ReturnLayer(){}};
template<>struct ReturnLayer<1>:Handle_801F7F10{~ReturnLayer(){}};
struct Handle_8004A648:ReturnLayer<4> {~Handle_8004A648(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C" {signed char fn_8025E9FC(Owner*,int);Node*fn_801F7EB8(const Handle_801F7F10*);Handle_8004A648 fn_8004A6C8(const Node*);float fn_80285124(float,float);void fn_8007D1F8(Node*,const Vec*,float,float,float,float);void fn_802603A0(void*,int,Node*,float);void fn_802073BC(Owner*,int,Owner*,float,float);void fn_8007D6A0(void*,int);extern const float lbl_80378584,lbl_80378560,lbl_80378570;}
inline Node*resolveEntry(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline Node*currentRoot(){return resolve(*lbl_801E9D24.related->handle);}
inline Node*currentChild(){return resolve(*currentRoot()->child);}
inline Node*relatedTarget(){Handle_801F7F10*handle=&resolve(*currentRoot()->related)->handle70;if(fn_801F7EB8(handle))return resolveEntry(*handle);return 0;}
extern "C" void fn_8004E058(Owner*self){
 if(fn_8025E9FC(self,0x8A)){
  Node*target=relatedTarget();
  Node*actor=currentChild();
  Handle_80020834 held(Handle_80020834(self->handle));
  if(resolve(held)->flags38&0x200000000000ULL){
   fn_8007D6A0((char*)target+0x318,6);
   float value=lbl_80378584*fn_80285124(self->high,self->low);
   fn_8007D1F8(resolve(fn_8004A6C8(actor)),&self->direction,self->first,self->second,lbl_80378570,value);
   fn_802603A0(lbl_801E9D24.events,0xA0,actor,lbl_80378560);
   fn_802073BC(self,0xBE,self,self->scale90,lbl_80378560);
   if(self->notifyOn)self->notify(0x8A);
  }
 }
 if(fn_8025E9FC(self,0xBE)){
  Node*target=relatedTarget();
  fn_802603A0(lbl_801E9D24.events,0xA1,resolveEntry(*currentRoot()->child),lbl_80378560);
  fn_8007D6A0((char*)target+0x318,0);
  if(self->notifyOff)self->notify(0x8B);
 }
}
