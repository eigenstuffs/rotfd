typedef unsigned long Word;
extern "C" {Word fn_801F948C(void*,const char*);extern const char lbl_80378B64[7];}
struct TargetName {Word word;TargetName(const char*s){word=fn_801F948C(this,s);}};
struct Handle_801F7F10 {union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct TargetReturn_8008BB40:Handle_801F7F10 {TargetReturn_8008BB40();~TargetReturn_8008BB40(){}};
struct TargetEntry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct TargetManager{int count,capacity;TargetEntry*entries;};
extern "C" struct TargetContext {char unknown00[0x118];TargetManager*manager;}lbl_801E9D24;
inline void*resolve(const Handle_801F7F10&h){int index=h.bits.index;TargetManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct TargetRelated{char unknown00[0x1F0];Handle_801F7F10 handle;};
struct TargetRecord{char unknown00[0x64];Handle_801F7F10 handle;};
struct TargetActor{char unknown00[0x24];Handle_801F7F10 handle;char unknown28[0x400];void*target;};
struct TargetState{char unknown00[0x88];signed char state;};
struct TargetOwner{char unknown00[8];TargetActor*actor;TargetRecord*record;};
extern "C" TargetReturn_8008BB40 fn_8024BDA0(void*,const TargetName&);

extern "C" void fn_8008BB40(TargetOwner* self) {
    void* resource = resolve(((TargetRelated*)resolve(self->record->handle))->handle);
    TargetName name(lbl_80378B64);
    self->actor->target = resolve(fn_8024BDA0(resource, name));
    ((TargetState*)resolve(self->actor->handle))->state = 5;
}
