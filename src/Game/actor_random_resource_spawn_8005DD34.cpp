struct ActorIndex{int value;ActorIndex(int v):value(v){}operator const int&()const{return value;}};
/* Queued actor action and random resource activation, reconstructed from GSQE78. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct SpawnHandle:Handle_801F7F10{~SpawnHandle(){}};
struct ActionStack{char unknown00[1];};
struct NodePrefix{char unknown00[8];};
struct Node:NodePrefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78(Node*,void*);
 char unknown0C[0x2C];unsigned long long flags;char unknown40[0x2D8];ActionStack actions;
};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}bool matchesTag(signed char t)const{return tag==t;}};
struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};struct Manager{int count,capacity;EntryArray entries;};
struct Primary{};struct Scene{char unknown00[0x15058];Primary*primary;};
extern "C" struct Globals{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;}lbl_801E9D24;
inline Node*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const ActorIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
struct Owner{char unknown00[0x2C];float time;char unknown30[0x28];Handle_801F7F10 target;char unknown5C[0x14];Handle_801F7F10 agent;};
struct Event{int code,probability;char unknown08[0x1C];void*value;};
extern "C"{signed char fn_8025E9FC(Owner*,int);Event*fn_8025E548(Owner*);void fn_80286058(Owner*,int);signed char fn_8007D604(ActionStack*,int);void fn_8007D6A0(ActionStack*,int);float fn_801F1200();SpawnHandle fn_80059AA4(Primary*);void fn_802554F4(Node*);void fn_8005C52C(Owner*);extern const float lbl_80378638,lbl_8037863C;}
extern "C" void fn_8005DD34(Owner*self){
 if(fn_8025E9FC(self,0x82)&&!fn_8007D604(&resolve(self->agent)->actions,3)&&!fn_8007D604(&resolve(self->agent)->actions,4))fn_8007D6A0(&resolve(self->agent)->actions,3);
 if(fn_8025E9FC(self,0xD0))while(fn_8025E9FC(self,0xD0)){
  if(self->time>=lbl_80378638)return;
  Event*event=fn_8025E548(self);
  float random=fn_801F1200();random*=lbl_8037863C;
  if(random<=(float)event->probability){
   Node*node=resolve(fn_80059AA4(lbl_801E9D24.scene->primary));
   if(node){node->flags|=0x20000ULL;node->slot34();node->slot78(resolve(self->target),event->value);fn_802554F4(node);}
  }
  fn_80286058(self,0xD0);
 }
 if(fn_8025E9FC(self,0x85))fn_8005C52C(self);
}
