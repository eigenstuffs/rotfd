/* Record activation, randomized setup and event dispatch; private layout views.
 * See docs/notes/game-early-record-activation.md. */
typedef unsigned long Word;
extern "C" {extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);extern const float lbl_803781E8,lbl_803781EC,lbl_803781F0,lbl_803781F4,lbl_803781F8,lbl_803781FC,lbl_80378200;}
struct Handle_801F7F10 {union{Word value;struct{signed int tag:8,index:24;}bits;};~Handle_801F7F10();};
struct RecordHandle1_80021724:Handle_801F7F10{};
struct RecordHandle2_80021724:RecordHandle1_80021724{};
struct RecordHandle3_80021724:RecordHandle2_80021724{};
struct Record_800218F8 {float f00,f04,f08,f0C,f10,f14,f18,f1C,f20;char unknown24[0x68];RecordHandle3_80021724 first,second;Record_800218F8();~Record_800218F8(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Actor_80021724 {char unknown00[0x30];unsigned long long flags;void removeFlags(unsigned long long mask){flags&=~mask;}};
struct Entry_80021724 {Actor_80021724*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager_80021724 {int count,capacity;Entry_80021724*entries;};
struct Globals_80021724 {char unknown00[0x118];Manager_80021724*manager;};extern "C" Globals_80021724 lbl_801E9D24;
struct OwnerPrefix_80021724 {char unknown00[8];};
struct Owner_80021724:OwnerPrefix_80021724 {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual void reset(int,int);
char unknown0C[0x2C];unsigned long long flags;void addFlags(unsigned long long mask){flags|=mask;}char unknown40[0x30];Handle_801F7F10 first;char unknown74[12];Handle_801F7F10 second;char unknown84[0x34];void*callback;};
extern "C" {void fn_80021CB0(Owner_80021724*);float fn_801F1200();void fn_802594B4(Owner_80021724*,Record_800218F8*);void fn_802073BC(Owner_80021724*,int,Owner_80021724*,float,float);void fn_80255D88(void*,void*,int,int,int);}
inline Actor_80021724*resolve_80021724(const Handle_801F7F10&h){Entry_80021724*e=lbl_801E9D24.manager->entries+h.bits.index;if(e->tag==h.bits.tag)return e->object;return 0;}
extern "C" void fn_80021724(Owner_80021724*self){
fn_80021CB0(self);resolve_80021724(self->first)->flags|=0x400ULL;
Record_800218F8 record;record.f18=lbl_803781E8;record.f0C=lbl_803781EC*(lbl_803781F0*fn_801F1200());record.f10=lbl_803781F4*fn_801F1200();record.f14=lbl_803781F8;record.f20=lbl_803781FC;
fn_802594B4(self,&record);self->reset(0,0);resolve_80021724(self->second)->removeFlags(0x818FFE00ULL);self->addFlags(0x20000ULL);
fn_802073BC(self,0xAC,self,record.f20,lbl_80378200);if(self->callback)fn_80255D88(self,self->callback,15,0,0);
}
