#ifndef GAME_OWNER_TARGET_ACTION_VIEWS_H
#define GAME_OWNER_TARGET_ACTION_VIEWS_H
struct TargetActionHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct TargetActionResource{char unknown00[0x58];TargetActionHandle owner;char unknown5C[0x60];unsigned short flagsBC;char unknownBE[0x62];unsigned int flags;};
struct TargetActionEntry{TargetActionResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct TargetActionManager{int count,capacity;TargetActionEntry*entries;};
struct TargetActionCollection{int count,capacity;TargetActionHandle*items;};
struct TargetActionContext{char unknown00[0x118];TargetActionManager*manager;TargetActionCollection*collection;};
extern "C" TargetActionContext lbl_801E9D24;
inline TargetActionResource*resolveTargetAction(const TargetActionHandle&h){TargetActionEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct TargetActionGenericEntry{void*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct TargetActionGenericManager{int count,capacity;TargetActionGenericEntry*entries;};
inline TargetActionResource*resolveGenericTargetAction(const TargetActionHandle&h){TargetActionGenericEntry*e=&((TargetActionGenericManager*)lbl_801E9D24.manager)->entries[h.bits.index];if(e->tag==h.bits.tag)return (TargetActionResource*)e->object;return 0;}
struct TargetActionVec2{float x,y;};
struct TargetActionVec3{float x,y,z;TargetActionVec3(float a,float b,float c):x(a),y(b),z(c){}TargetActionVec3&operator=(const TargetActionVec3&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct TargetActionPrefix{char unknown00[8];};
struct TargetActionAgent:TargetActionPrefix{
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
virtual const TargetActionHandle*getHandle(int);
char unknown0C[0x18];TargetActionHandle owner;char unknown28[0x368];signed char cachedActive;char unknown391[0x13];TargetActionVec3 direction;char unknown3B0[0x14];TargetActionResource*cached;char unknown3C8[9];signed char reverse;char unknown3D2[0xB];signed char lookupFlag;
TargetActionResource*currentTarget();
};
extern "C"{TargetActionResource*fn_8005E9A0();void fn_8009F3E8(TargetActionAgent*,TargetActionResource*,TargetActionVec2*);void fn_8009F754(TargetActionAgent*,TargetActionResource*);signed char fn_8009FD38(TargetActionAgent*);const TargetActionHandle*fn_80268080(TargetActionResource*,const TargetActionHandle*);extern const float lbl_80378DD8;}
inline TargetActionResource*TargetActionAgent::currentTarget(){if(cached==(TargetActionResource*)-1){cached=resolveTargetAction(fn_8005E9A0()->owner);cachedActive=1;}if(cached){if(cachedActive)cached=resolveTargetAction(fn_8005E9A0()->owner);}else cachedActive=0;return cached;}
#endif
