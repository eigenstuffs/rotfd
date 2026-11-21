#ifndef GAME_MOTION_HANDLE_EVENTS_H
#define GAME_MOTION_HANDLE_EVENTS_H
struct PhaseHandle{union{unsigned long word;struct{signed int tag:8,index:24;}bits;};};
struct PhaseActor{char unknown00[0x24];PhaseHandle handle;};
struct PhaseAction{char unknown00[8];PhaseActor*actor;};
struct PhaseResource;struct PhaseEntry{PhaseResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct PhaseManager{int count,capacity;PhaseEntry*entries;};
struct PhaseContext{char unknown00[0x118];PhaseManager*manager;};
extern "C"{extern PhaseContext lbl_801E9D24;void fn_80257828(PhaseResource*,int,int,int);void fn_800A4D6C(PhaseAction*);void fn_800A4E30(PhaseAction*);void fn_800A4EEC(PhaseAction*);}
inline PhaseResource*resolvePhase(const PhaseHandle&h){PhaseEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
#endif
