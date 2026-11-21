#ifndef GAME_MOTION_CONTROLLER_EVENT_VIEWS_H
#define GAME_MOTION_CONTROLLER_EVENT_VIEWS_H
struct ControllerHandle{union{unsigned long word;struct{signed int tag:8,index:24;}bits;};};
struct ControllerPrefix{char unknown00[8];};
struct ControllerActor:ControllerPrefix{
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
virtual void slot37();
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45(void*,int);
char unknown0C[0x18];ControllerHandle handle;char unknown28[0x2F8];int key;char unknown324[0x70];float value;};
struct ControllerAction{char unknown00[8];ControllerActor*actor;};
struct ControllerResource;struct ControllerEntry{ControllerResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct ControllerManager{int count,capacity;ControllerEntry*entries;};
struct ControllerContext{char unknown00[0x118];ControllerManager*manager;};
struct ControllerMonitor{char unknown00[0x130];void*first;void*second;};
extern "C"{extern ControllerContext lbl_801E9D24;extern const float lbl_80378E60;ControllerMonitor*fn_8005EE10(ControllerResource*);void fn_8006803C(ControllerMonitor*,int);void fn_80068158(ControllerMonitor*,int);}
inline ControllerResource*resolveController(const ControllerHandle&h){ControllerEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
#endif
