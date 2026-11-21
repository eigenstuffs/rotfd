/* Three queued resource events; see docs/notes/game-resource-event-loops.md. */
/* Three queued resource events; original callback data remains external.
 * See docs/notes/game-resource-event-loops.md. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
template<int D>struct ResourceEventLayer_8002BAB4:ResourceEventLayer_8002BAB4<D-1>{~ResourceEventLayer_8002BAB4(){}};template<>struct ResourceEventLayer_8002BAB4<1>:Handle_801F7F10{~ResourceEventLayer_8002BAB4(){}};struct Return_8002BAB4:ResourceEventLayer_8002BAB4<1>{~Return_8002BAB4(){}};
struct NodePrefix{char unknown00[8];};struct Node:NodePrefix{virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void s9();virtual void s10();virtual void s11();virtual void s12();virtual void s13();virtual void s14();virtual void s15();virtual void s16();virtual void s17();virtual void s18();virtual void s19();virtual void s20();virtual void s21();virtual void s22();virtual void s23();virtual void s24();virtual void s25();virtual void s26();virtual void s27();virtual void slot78(Node*,Word);};
struct Primary{char unknown00[0xF0];int state;};struct Scene{char unknown00[0x15058];Primary*primary;};struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{char unknown00[8];Entry*entries;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;}lbl_801E9D24;
struct Name{Word word;};struct Event{char unknown00[8];Name name;char unknown0C[0x18];Word value;};struct Owner{char unknown00[0x2C];float time;char unknown30[0x28];Handle_801F7F10 target;char unknown5C[0x30];Node*resource;};
extern "C"{extern const float lbl_80378330;signed char fn_8025E9FC(Owner*,int);Event*fn_8025E548(Owner*);void fn_80255678(Node*);void fn_802554F4(Node*);void fn_80286058(Owner*,int);Return_8002BAB4 fn_80058778(Primary*,const Name&,signed char);}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
extern "C"void fn_8002BAB4(Owner*self){
 if(fn_8025E9FC(self,0x1B))while(fn_8025E9FC(self,0x1B)){
  if(self->time>=lbl_80378330&&self->resource){fn_80255678(self->resource);return;}
  Event*event=fn_8025E548(self);self->resource=resolve(fn_80058778(lbl_801E9D24.scene->primary,event->name,0));if(self->resource){self->resource->slot78(resolve(self->target),event->value);fn_802554F4(self->resource);}fn_80286058(self,0x1B);
 }
 if(fn_8025E9FC(self,0x1C))while(fn_8025E9FC(self,0x1C)){
  if(self->time>=lbl_80378330&&self->resource){fn_80255678(self->resource);return;}
  Event*event=fn_8025E548(self);self->resource=resolve(fn_80058778(lbl_801E9D24.scene->primary,event->name,0));if(self->resource)fn_80255678(self->resource);fn_80286058(self,0x1C);
 }
 if(fn_8025E9FC(self,0xDC)&&lbl_801E9D24.scene->primary->state!=6)while(fn_8025E9FC(self,0xDC)){
  if(self->time>=lbl_80378330&&self->resource){fn_80255678(self->resource);return;}
  Event*event=fn_8025E548(self);self->resource=resolve(fn_80058778(lbl_801E9D24.scene->primary,event->name,0));if(self->resource){self->resource->slot78(resolve(self->target),event->value);fn_802554F4(self->resource);}fn_80286058(self,0xDC);
 }
}

typedef char ResourceEventHandleSize[(sizeof(Handle_801F7F10)==4)?1:-1];
typedef char ResourceEventReturnSize[(sizeof(Return_8002BAB4)==4)?1:-1];
typedef char ResourceEventEntrySize[(sizeof(Entry)==16)?1:-1];
