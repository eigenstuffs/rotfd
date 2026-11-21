#ifndef GAME_EARLY_ACTOR_EVENT_CONTROL_VIEWS_H
#define GAME_EARLY_ACTOR_EVENT_CONTROL_VIEWS_H

struct EventHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct EventComponent{char unknown00[0xC];float value;};
struct EventResource{char unknown00[0x74];EventComponent*first;EventComponent*second;char unknown7C[0xA4];unsigned long flags;};
struct EventEntry{EventResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct EventManager{int count,capacity;EventEntry*entries;};
struct EventContext{char unknown00[0x118];EventManager*manager;};
extern "C" EventContext lbl_801E9D24;
inline EventResource*resolveEvent(const EventHandle&h){EventEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct EventRecord{char unknown00[8];int key;};
struct EventActorPrefix{char unknown00[8];};
struct EventActor:EventActorPrefix{
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
virtual const EventHandle* slot37(int);
char unknown0C[0x24];unsigned long long flags;char unknown38[0x128];float threshold;char unknown164[4];EventHandle handle;char unknown16C[0x1AC];EventRecord record;char unknown324[0xD8];float value;char unknown400[5];signed char enabled405,enabled406;char unknown407[2];signed char enabled409,enabled40A;char unknown40B[2];signed char enabled40D;
inline signed char hasFlags(unsigned long long mask)const{if(flags&mask)return 1;return 0;}
};
struct EventOwner{char unknown00[8];EventActor*actor;void*controller;char unknown10[0x30];signed char enabled40;};
struct EventMonitor{char unknown00[0x130];void*first;void*second;};
extern "C"{extern EventMonitor*lbl_803776B8;extern const float lbl_80378AA8,lbl_80378AF0,lbl_80378AD8;EventResource* fn_801F7EB8(const EventHandle*);signed char fn_8007D604(EventRecord*,int);void fn_8025795C(void*,int,int);void fn_8006803C(EventMonitor*,int);void fn_80068158(EventMonitor*,int);void fn_80285ED8(void*,int,int);int fn_80092844(EventActor*);void fn_8007D6A0(EventRecord*,int);void fn_80092BF4(EventActor*,int,float);void fn_80092DAC(EventActor*,float);void fn_80257828(void*,int,int,int);}
struct EventFirstResource{char unknown00[0x74];EventComponent*first;};
struct EventFirstEntry{EventFirstResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct EventFirstManager{int count,capacity;EventFirstEntry*entries;};
inline EventFirstResource*resolveEventFirst(const EventHandle&h){EventFirstEntry*e=&((EventFirstManager*)lbl_801E9D24.manager)->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}

#endif
