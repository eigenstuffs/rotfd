#ifndef GAME_MOTION_CALLBACK_CONTROLS_H
#define GAME_MOTION_CALLBACK_CONTROLS_H
struct CallbackHandle{union{unsigned long word;struct{signed int tag:8,index:24;}bits;};};
struct CallbackPrefix{char unknown00[8];};
struct CallbackActor:CallbackPrefix{
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
char unknown0C[0x18];CallbackHandle handle;char unknown28[8];unsigned long long flags;char unknown38[0x2E0];char component[12];int selector;char unknown328[0x24];int counter;char unknown350[0x40];unsigned char enabled;char unknown391[3];float value;char unknown398[0x2C];int mode;char unknown3C8[4];int previous;char unknown3D0[2];unsigned char active;
signed char hasFlag(unsigned long long mask){signed char result=0;if((flags&mask)!=0)result=1;return result;}void resetEventState(){mode=0;enabled=0;}};
struct CallbackAction{char unknown00[8];CallbackActor*actor;};
struct CallbackResource;struct CallbackEntry{CallbackResource*object;char unknown04[8];signed char tag;char unknown0D[3];};struct CallbackManager{int count,capacity;CallbackEntry*entries;};struct CallbackContext{char unknown00[0x118];CallbackManager*manager;};struct CallbackMonitor{char unknown00[0x3C];unsigned char state;};
extern "C"{extern CallbackContext lbl_801E9D24;extern const float lbl_80378E44;void fn_8009FABC(CallbackActor*,int);void fn_8009FB80(CallbackActor*,int);void fn_800A4E30(CallbackAction*);void fn_800A4DF0(CallbackAction*,float);void fn_8007D6A0(void*,int);CallbackMonitor*fn_8005EE10(CallbackResource*);void fn_800699A8(CallbackMonitor*,int);}
inline CallbackResource*resolveCallback(const CallbackHandle&h){CallbackEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
#endif
