#ifndef GAME_EARLY_AGENT_PROFILE_VIEWS_H
#define GAME_EARLY_AGENT_PROFILE_VIEWS_H
// Observed agent profile storage and virtual interfaces.
struct Handle_801F7F10{unsigned long value;Handle_801F7F10();~Handle_801F7F10();};
struct AgentProfile;
struct AgentProfileHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct AgentProfileEntry{AgentProfile*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct AgentProfileManager{int count,capacity;AgentProfileEntry*entries;};
struct AgentProfileContext{char unknown00[0x110];void*logger;char unknown114[4];AgentProfileManager*manager;};
extern "C" AgentProfileContext lbl_801E9D24;
struct AgentProfilePrefix{char unknown00[8];};
struct AgentProfile:AgentProfilePrefix{
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
virtual void slot21(int);
virtual void slot22(int);
char unknown0C[0x24];unsigned long long actorFlags,flags;char unknown40[0x30];AgentProfileHandle controller;char unknown74[0x1C];signed char active;char unknown91[3];float high,low;char unknown9C[0x14];float rate,limit;char unknownB8[0x29C];float speed;char unknown358[0xC];float acceleration,deceleration;char unknown36C[4];float radius;char unknown374[0x2C];float scale;};
inline AgentProfile*resolveAgentProfile(const AgentProfileHandle&h){AgentProfileEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
extern "C"{Handle_801F7F10 fn_801B52EC(AgentProfileManager*,const char*);void fn_8025A3C8(AgentProfile*,const Handle_801F7F10&);void fn_8002B780(AgentProfile*);void fn_8002B824(AgentProfile*,void*);void fn_801FA014(void*,const char*,...);signed char fn_8025E9FC(AgentProfile*,int);extern const char lbl_8029C7A8[],lbl_8029C7B8[];extern const float lbl_803788AC,lbl_803788B0;}
extern "C" {extern const float lbl_803788B4,lbl_803788B8,lbl_803788BC,lbl_803788C0,lbl_803788C4,lbl_803788C8,lbl_803788CC;}
extern "C" {extern const float lbl_803788A8,lbl_803788D0;}

#endif
