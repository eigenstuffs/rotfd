#ifndef GAME_EARLY_ACTOR_POSITION_STATE_CONTROL_VIEWS_H
#define GAME_EARLY_ACTOR_POSITION_STATE_CONTROL_VIEWS_H
struct PositionStateHandle{signed int tag:8;signed int index:24;};
struct PositionStateVector{float x,y,z;PositionStateVector(){}PositionStateVector(const PositionStateVector&v):x(v.x),y(v.y),z(v.z){}PositionStateVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){}PositionStateVector&operator=(const PositionStateVector&v){x=v.x;y=v.y;z=v.z;return*this;}};
struct PositionStateTransform{char unknown00[0x30];PositionStateVector position;};
struct PositionStatePrefix{char unknown00[8];};
struct PositionStateActor:PositionStatePrefix{
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
virtual const PositionStateHandle* slot37(int);
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41(int,int);
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45(const PositionStateVector&,int);
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
virtual const PositionStateHandle* slot74();
char unknown0C[0x24];unsigned long long flags;char unknown38[0x38];PositionStateHandle actor;char unknown74[0xC];PositionStateHandle related;char unknown84[0xA0];PositionStateTransform*transform;char unknown128[0x1C];PositionStateVector velocity;char unknown150[0x48];PositionStateVector position;char unknown1A4[0x1EC];PositionStateVector targetPosition;char unknown39C[0x38];float savedY;
inline void setPosition(PositionStateVector v){position=v;}
inline void setVelocity(PositionStateVector v){velocity=v;}
};
struct PositionStateOwner{char unknown00[0x58];PositionStateHandle resource;char unknown5C[0x14];PositionStateHandle actor;};
struct PositionStatePointerOwner{char unknown00[0x10];PositionStateActor*actor;};
struct PositionStateResource{char unknown00[0x120];unsigned long property;};
struct PositionStateSystemGroup{char unknown00[0xB0];PositionStateHandle*next;};
struct PositionStateGroup{char unknown00[0x70];PositionStateHandle actor;};
struct PositionStateSystem{char unknown00[0x1C];PositionStateHandle*handle;};
struct PositionStateText{char unknown00[0x48];void*text;float time;};
struct PositionStateSceneState{char unknown00[0x60];PositionStateHandle text;};
struct PositionStateScene{char unknown00[0x15058];PositionStateSceneState*state;};
struct PositionStateActorEntry{PositionStateActor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct PositionStateActorManager{char unknown00[8];PositionStateActorEntry*entries;};
struct PositionStateResourceEntry{PositionStateResource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct PositionStateResourceManager{char unknown00[8];PositionStateResourceEntry*entries;};
struct PositionStateSystemGroupEntry{PositionStateSystemGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct PositionStateSystemGroupManager{char unknown00[8];PositionStateSystemGroupEntry*entries;};
struct PositionStateGroupEntry{PositionStateGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct PositionStateGroupManager{char unknown00[8];PositionStateGroupEntry*entries;};
struct PositionStateTextEntry{PositionStateText*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct PositionStateTextManager{char unknown00[8];PositionStateTextEntry*entries;};
struct PositionStateContext{char unknown00[0x110];void*logger;char unknown114[4];PositionStateActorManager*manager;char unknown11C[8];PositionStateScene*scene;char unknown128[0x14];PositionStateSystem*system;};
extern "C"PositionStateContext lbl_801E9D24;
inline PositionStateActor*resolveActor(const PositionStateHandle&h){int index=h.index;PositionStateActorManager*m=(PositionStateActorManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline PositionStateResource*resolveResource(const PositionStateHandle&h){int index=h.index;PositionStateResourceManager*m=(PositionStateResourceManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline PositionStateSystemGroup*resolveSystemGroup(const PositionStateHandle&h){int index=h.index;PositionStateSystemGroupManager*m=(PositionStateSystemGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline PositionStateGroup*resolveGroup(const PositionStateHandle&h){int index=h.index;PositionStateGroupManager*m=(PositionStateGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline PositionStateText*resolveText(const PositionStateHandle&h){int index=h.index;PositionStateTextManager*m=(PositionStateTextManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
extern "C"unsigned long fn_801F7EB8(const PositionStateHandle*);
inline PositionStateActor*validResolve(const PositionStateHandle&h){if(fn_801F7EB8(&h))return resolveActor(h);else return 0;}
struct PositionStateResetRecord{PositionStateVector position;PositionStateActor*actor;signed char enabled;};
struct PositionStateResetOwner{void*vtable;signed char enabled;char unknown05[3];float time;signed char pending;unsigned char count;signed char state;char unknown0F;PositionStateResetRecord*records[1];};
struct PositionStateTableRecord{int key;char unknown04[8];char text[0x40];signed char enabled;char unknown4D[3];};
extern "C"{extern PositionStateTableRecord lbl_802F4208[300];extern const PositionStateVector game_vec3_zero;extern const float lbl_80378240,lbl_80379340,lbl_80379784,lbl_80379794,lbl_80379788;void fn_80068FE4(void*,signed char);void fn_80059340(PositionStateSceneState*,int);void fn_8025A0A4(PositionStateOwner*);void fn_80259164(PositionStateActor*);}
struct PositionStateHandleArrayOwner{char unknown00[0x48];PositionStateHandle*handles;};
struct PositionStateModeOwner{char unknown00[0x24];PositionStateHandle handle;char unknown28[0x2F8];int state;};
struct PositionStateTransition{char unknown00[8];PositionStateModeOwner*owner;char unknown0C[0x4C];signed char active;};
extern "C"{void fn_80255678(void*);void fn_80255D88(void*,int,int,int,int);void fn_80255CBC(void*,int,int);void fn_801FA014(void*,const char*,...);void fn_8002B824(PositionStateActor*,int);void fn_8005C264(PositionStateActor*,int);void fn_8007D6A0(void*,int);extern const char lbl_8029B9C8[];extern const float lbl_803786C0;}
#endif
