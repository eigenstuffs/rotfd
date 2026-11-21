typedef unsigned long Word;
extern "C" void fn_801F7CB4(void*,const void*);
struct Handle_801F7F10{union{Word value;struct{signed int generation:8;signed int index:24;}bits;};Handle_801F7F10();Handle_801F7F10(const Handle_801F7F10&h){fn_801F7CB4(this,&h);}~Handle_801F7F10();};
struct Vector{float x,y,z;};struct Actor{char unknown00[0x168];char component[0x3C];Vector value;};struct Entry{Actor*object;char unknown04[8];signed char generation;char unknown0D[3];};struct Manager{int count,capacity;Entry*entries;};struct Scene{char unknown00[0x15058];void*mode;};struct Context{char unknown00[0x110];void*logger;char unknown114[4];Manager*manager;char unknown11C[8];Scene*scene;};extern "C" Context lbl_801E9D24;
struct Owner{char unknown00[0x70];Handle_801F7F10 handle;char unknown74[4];Actor*selected;int state;};
inline Actor*resolve(const Handle_801F7F10&h){Entry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->generation==h.bits.generation)return entry->object;return 0;}
struct Returned_800C540C:Handle_801F7F10{Actor*get()const{return resolve(*this);}};
extern "C"{Word fn_801F948C(void*,const char*);void fn_801FA014(void*,const char*,...);void fn_8002AF3C(void*,void*);void fn_8007D6A0(void*,int);extern const char lbl_802A2618[],lbl_802A2630[];extern const float lbl_803795F0,lbl_803795F4,lbl_803795F8;}
struct Name{Word value;Name(const char*s){value=fn_801F948C(this,s);}};
extern "C" Returned_800C540C fn_80058778(void*,const Name&,signed char);
extern "C" void fn_800C540C(Owner*self,void*arg){fn_801FA014(lbl_801E9D24.logger,lbl_802A2618);fn_8002AF3C(self,arg);Actor*actor=resolve(self->handle);actor->value.x=lbl_803795F0;actor->value.y=lbl_803795F4;actor->value.z=lbl_803795F8;fn_8007D6A0(actor->component,2);self->selected=fn_80058778(lbl_801E9D24.scene->mode,Name(lbl_802A2630),0).get();self->state=2;}
