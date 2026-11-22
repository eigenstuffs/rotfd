typedef unsigned long Word;
extern "C" {extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);extern const float lbl_80379784,lbl_80379790;}
struct Handle_801F7F10 { Word value;~Handle_801F7F10(); };
struct EventRecordHandle1:Handle_801F7F10{};
struct EventRecordHandle2:EventRecordHandle1{};
struct EventRecordHandle3:EventRecordHandle2{};
struct Record_800218F8 {char unknown00[8];float value;char unknown0C[0x80];EventRecordHandle3 first,second;Record_800218F8();~Record_800218F8(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle {signed int generation:8,index:24;};
struct Actor {char unknown00[0x30];unsigned long long flags;};
struct Entry {Actor*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct Manager {int count,capacity;Entry*entries;};
extern "C" struct{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
struct Target {char unknown00[0x80];Handle actor;};
struct Owner {char unknown00[0xC];void*events;char unknown10[0x94];Target*target;};
extern "C" {void fn_802594B4(Target*,Record_800218F8*);void fn_802073BC(Target*,int,Target*,float,float);void fn_80255D88(void*,int,int,int,int);}
inline Actor*resolve(const Handle&h){Entry*entry=lbl_801E9D24.manager->entries+h.index;return entry->generation==h.generation?entry->object:0;}
extern "C" void fn_800E1B94(Owner*self){
 Record_800218F8 record;record.value=lbl_80379784;
 resolve(self->target->actor)->flags&=~0x0000001000300200ULL;
 fn_802594B4(self->target,&record);
 fn_802073BC(self->target,0xAC,self->target,record.value,lbl_80379790);
 fn_80255D88(self->events,0x7B,15,0,0);
}
