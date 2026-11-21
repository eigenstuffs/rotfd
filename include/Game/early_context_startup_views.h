#ifndef GAME_EARLY_CONTEXT_STARTUP_VIEWS_H
#define GAME_EARLY_CONTEXT_STARTUP_VIEWS_H

struct StartupInput{virtual ~StartupInput();};
struct StartupScenePrefix{char unknown00[0x30];};
struct StartupScene:StartupScenePrefix{virtual ~StartupScene();};
struct StartupAux{char unknown00[0x18];signed char enabled;};
struct StartupLogger{char unknown00[0x860];int mode;char unknown864[4];void*device;};
struct StartupContext{char unknown00[0x104];unsigned long flags;char unknown108[8];StartupLogger*logger;char unknown114[0x10];StartupScene*scene;char unknown128[0x2C];StartupAux*aux;char unknown158[0xC];StartupInput*input;};
extern "C" StartupContext lbl_801E9D24;
struct StartupSingleton{char opaque;};
extern "C"{extern StartupSingleton*lbl_80377760;extern char lbl_801EF5C8[0x100];extern const char game_type_registry_SpongeBob___RegisterGameClasses[],lbl_8029D524[];void fn_801FA014(StartupLogger*,const char*,...);void*fn_801EFA1C(void*,unsigned long,const char*,const char*,int,int);StartupInput*__ct__15Object_800B5EC8Fv(void*);void fn_8001F834();void*fn_8001F518(StartupSingleton*,int);StartupSingleton*fn_8001F38C(void*);int fn_8001F754(StartupSingleton*,void*);}
struct StartupHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct StartupNodePrefix{char unknown00[8];};
struct StartupNode:StartupNodePrefix{
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
virtual const StartupHandle* slot37(int);
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45(void*,int);
char unknown0C[0x114];unsigned long flags;};
struct StartupEntry{StartupNode*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct StartupManager{int count,capacity;StartupEntry*entries;};
struct StartupManagerContext{char unknown00[0x118];StartupManager*manager;};
inline StartupNode*resolveStartup(const StartupHandle&h){StartupEntry*e=&((StartupManagerContext*)&lbl_801E9D24)->manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
extern "C" void fn_8022993C(StartupNode*,void*,void*,void*,void*,double);

#endif
