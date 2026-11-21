#ifndef GAME_EARLY_SELECTION_EVENT_CONTROL_VIEWS_H
#define GAME_EARLY_SELECTION_EVENT_CONTROL_VIEWS_H
struct SelectionHandle{signed int tag:8;signed int index:24;};
struct SelectionVector{float x,y,z;SelectionVector(){}SelectionVector(const SelectionVector&v):x(v.x),y(v.y),z(v.z){}SelectionVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){}SelectionVector&operator=(const SelectionVector&v){x=v.x;y=v.y;z=v.z;return*this;}};
struct SelectionTransform{char unknown00[0x30];SelectionVector position;};
struct SelectionPrefix{char unknown00[8];};
struct SelectionActor:SelectionPrefix{
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
virtual void slot35(int,int);
virtual void slot36();
virtual const SelectionHandle* slot37(int);
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45(const SelectionVector&,int);
virtual void slot46();
virtual void slot47();
virtual void slot48();
virtual void slot49();
virtual void slot50();
virtual void slot51();
virtual void slot52();
virtual void slot53();
virtual void slot54();
virtual void slot55();
virtual void slot56();
virtual void slot57();
virtual void slot58();
virtual void slot59();
virtual void slot60();
virtual void slot61();
virtual void slot62();
virtual void slot63();
virtual void slot64();
virtual void slot65();
virtual void slot66();
virtual void slot67();
virtual void slot68();
virtual void slot69();
virtual void slot70();
virtual void slot71();
virtual void slot72();
virtual void slot73();
virtual const SelectionHandle* slot74();
virtual void slot75();
virtual void slot76();
virtual void slot77();
virtual void slot78();
virtual void slot79();
virtual void slot80();
virtual void slot81();
virtual void slot82();
virtual void slot83();
virtual void slot84();
virtual void slot85();
virtual void slot86();
virtual void slot87();
virtual void slot88();
virtual void slot89();
virtual void slot90();
virtual void slot91();
virtual void slot92();
virtual void slot93();
virtual void slot94();
virtual void slot95();
virtual void slot96();
virtual void setMotion(const SelectionVector&);
char unknown0C[0x24];unsigned long long flags;unsigned long long ownerFlags;char unknown40[0x30];SelectionHandle handle;char unknown74[0xC];SelectionHandle related;char unknown84[0xA0];SelectionTransform*transform;char unknown128[0x1C];SelectionVector velocity;char unknown150[0x48];SelectionVector position;char unknown1A4[0x48];unsigned char recordIndex;char unknown1ED[0x1AB];SelectionVector origin;char unknown3A4[0x6C];float stateTime;unsigned char active;unsigned char state;
inline void setPosition(SelectionVector v){position=v;}
inline void setVelocity(SelectionVector v){velocity=v;}
};
struct SelectionOwner{char unknown00[0x38];unsigned long long flags;char unknown40[0x30];SelectionHandle actor;char unknown74[0xC];SelectionHandle related;};
struct SelectionPointerOwner{char unknown00[0x10];SelectionActor*actor;};
struct SelectionResource{char unknown00[0x120];unsigned long property;};
struct SelectionSystemGroup{char unknown00[0xB0];SelectionHandle*next;};
struct SelectionGroup{char unknown00[0x70];SelectionHandle actor;};
struct SelectionSystem{char unknown00[0x1C];SelectionHandle*handle;};
struct SelectionText{char unknown00[0x48];void*text;float time;};
struct SelectionSceneState{char unknown00[0x60];SelectionHandle text;};
struct SelectionScene{char unknown00[0x15068];SelectionOwner*current;};
struct SelectionActorEntry{SelectionActor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct SelectionActorManager{char unknown00[8];SelectionActorEntry*entries;};
struct SelectionResourceEntry{SelectionResource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct SelectionResourceManager{char unknown00[8];SelectionResourceEntry*entries;};
struct SelectionSystemGroupEntry{SelectionSystemGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct SelectionSystemGroupManager{char unknown00[8];SelectionSystemGroupEntry*entries;};
struct SelectionGroupEntry{SelectionGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct SelectionGroupManager{char unknown00[8];SelectionGroupEntry*entries;};
struct SelectionTextEntry{SelectionText*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct SelectionTextManager{char unknown00[8];SelectionTextEntry*entries;};
struct SelectionContext{char unknown00[0x118];SelectionActorManager*manager;char unknown11C[8];SelectionScene*scene;char unknown128[0x14];SelectionSystem*system;};
extern "C"SelectionContext lbl_801E9D24;
inline SelectionActor*resolveActor(const SelectionHandle&h){int index=h.index;SelectionActorManager*m=(SelectionActorManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline SelectionResource*resolveResource(const SelectionHandle&h){int index=h.index;SelectionResourceManager*m=(SelectionResourceManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline SelectionSystemGroup*resolveSystemGroup(const SelectionHandle&h){int index=h.index;SelectionSystemGroupManager*m=(SelectionSystemGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline SelectionGroup*resolveGroup(const SelectionHandle&h){int index=h.index;SelectionGroupManager*m=(SelectionGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline SelectionText*resolveText(const SelectionHandle&h){int index=h.index;SelectionTextManager*m=(SelectionTextManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
extern "C"unsigned long fn_801F7EB8(const SelectionHandle*);
inline SelectionActor*validResolve(const SelectionHandle&h){if(fn_801F7EB8(&h))return resolveActor(h);else return 0;}
extern "C" const float lbl_80378240;
struct SelectionResetRecord{SelectionVector position;SelectionActor*actor;signed char enabled;SelectionResetRecord():position(lbl_80378240,lbl_80378240,lbl_80378240),actor(0),enabled(0){}};
struct SelectionResetOwner{void*vtable;signed char enabled;char unknown05[3];float time;signed char pending;unsigned char count;signed char state;char unknown0F;SelectionResetRecord*records[256];};
struct SelectionTableRecord{int key;char unknown04[8];char text[0x40];signed char enabled;char unknown4D[3];};
extern "C"{extern SelectionTableRecord lbl_802F4208[300];extern const SelectionVector game_vec3_zero;extern const float lbl_80378240,lbl_80379340,lbl_80379784,lbl_80379794,lbl_80379788;signed char fn_80068FE4(void*,signed char);void fn_80059340(SelectionSceneState*,int);void fn_8025A0A4(SelectionOwner*);void fn_80259164(SelectionActor*);}
extern "C"{extern char lbl_801EF5C8[];extern const char lbl_80299C4C[],lbl_80299C5C[];extern const float lbl_80378420,lbl_80378450,lbl_80378454;void*fn_801EFA1C(void*,unsigned long,const char*,const char*,int,int);void fn_8025795C(void*,int,int);void fn_80255D88(void*,int,int,int,int);void fn_800356DC(SelectionOwner*);void fn_80259008(SelectionOwner*);void fn_800E3094(SelectionActor*,SelectionOwner*);signed char fn_8025E9FC(void*,int);void fn_80286058(void*,int);void fn_8007D6A0(void*,int);}
inline void*operator new(unsigned long,void*p){return p;}
#endif
