#ifndef GAME_EARLY_ACTOR_FLAG_GATE_VIEWS_H
#define GAME_EARLY_ACTOR_FLAG_GATE_VIEWS_H
struct GateHandle{signed int tag:8,index:24;};
struct GateRecord{char unknown00;};struct GateActor{char unknown00[0x318];GateRecord record;};
struct GateGroup{char unknown00[0x70];GateHandle actor;const GateHandle&getActor(){return actor;}};struct GateSystemGroup{char unknown00[0xB0];GateHandle*next;};struct GateSystem{char unknown00[0x1C];GateHandle*handle;};
struct GateActorEntry{GateActor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct GateActorManager{char unknown00[8];GateActorEntry*entries;};
struct GateGroupEntry{GateGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct GateGroupManager{char unknown00[8];GateGroupEntry*entries;};
struct GateSystemGroupEntry{GateSystemGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct GateSystemGroupManager{char unknown00[8];GateSystemGroupEntry*entries;};
struct GateContext{char unknown00[0x118];GateSystemGroupManager*manager;char unknown11C[0x20];GateSystem*system;};extern "C"GateContext lbl_801E9D24;
extern "C"{unsigned long fn_801F7EB8(const GateHandle*);signed char fn_8007D604(GateRecord*,int);void fn_8007D6A0(GateRecord*,int);void*fn_8007DCF8(GateRecord*);void fn_800AEBE8(void*,void*,void*,void*,void*,float);void fn_8022993C(void*,void*,void*,void*,void*,float);}
inline GateActor*resolveActor(const GateHandle&h){int index=h.index;GateActorManager*m=(GateActorManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline GateGroup*resolveGroup(const GateHandle&h){int index=h.index;GateGroupManager*m=(GateGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline GateSystemGroup*resolveSystemGroup(const GateHandle&h){int index=h.index;GateSystemGroupManager*m=(GateSystemGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline GateActor*optionalActor(const GateHandle&h){if(fn_801F7EB8(&h))return resolveActor(h);return 0;}
struct GateOwner{char unknown00[0x1F8];GateRecord record;char unknown1F9[0xCF];unsigned char flag;};
#endif
