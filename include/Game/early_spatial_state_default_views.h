#ifndef GAME_EARLY_SPATIAL_STATE_DEFAULT_VIEWS_H
#define GAME_EARLY_SPATIAL_STATE_DEFAULT_VIEWS_H
struct ForwardSpatialHandle{signed int tag:8;signed int index:24;};
struct ForwardSpatialVector{float x,y,z;ForwardSpatialVector(){}ForwardSpatialVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){}ForwardSpatialVector&operator=(const ForwardSpatialVector&v){x=v.x;y=v.y;z=v.z;return*this;}};
struct ForwardSpatialTransform{char unknown00[0x30];ForwardSpatialVector position;};
struct ForwardSpatialPrefix{char unknown00[8];};
struct ForwardSpatialActor:ForwardSpatialPrefix{
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
virtual const ForwardSpatialHandle* slot37(int);
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45(const ForwardSpatialVector&,int);
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
virtual const ForwardSpatialHandle* slot74();
char unknown0C[0x24];unsigned long long flags;char unknown38[0x48];ForwardSpatialHandle related;char unknown84[0xA0];ForwardSpatialTransform*transform;char unknown128[0x1C];ForwardSpatialVector velocity;char unknown150[0x48];ForwardSpatialVector position;char unknown1A4[0x1F4];ForwardSpatialVector origin;
inline void setPosition(ForwardSpatialVector v){position=v;}
inline void setVelocity(ForwardSpatialVector v){velocity=v;}
};
struct ForwardSpatialOwner{char unknown00[0x58];ForwardSpatialHandle resource;char unknown5C[0x14];ForwardSpatialHandle actor;};
struct ForwardSpatialPointerOwner{char unknown00[0x10];ForwardSpatialActor*actor;};
struct ForwardSpatialResource{char unknown00[0x120];unsigned long property;};
struct ForwardSpatialSystemGroup{char unknown00[0xB0];ForwardSpatialHandle*next;};
struct ForwardSpatialGroup{char unknown00[0x70];ForwardSpatialHandle actor;};
struct ForwardSpatialSystem{char unknown00[0x1C];ForwardSpatialHandle*handle;};
struct ForwardSpatialText{char unknown00[0x48];void*text;float time;};
struct ForwardSpatialSceneState{char unknown00[0x60];ForwardSpatialHandle text;};
struct ForwardSpatialScene{char unknown00[0x15058];ForwardSpatialSceneState*state;};
struct ForwardSpatialActorEntry{ForwardSpatialActor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ForwardSpatialActorManager{char unknown00[8];ForwardSpatialActorEntry*entries;};
struct ForwardSpatialResourceEntry{ForwardSpatialResource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ForwardSpatialResourceManager{char unknown00[8];ForwardSpatialResourceEntry*entries;};
struct ForwardSpatialSystemGroupEntry{ForwardSpatialSystemGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ForwardSpatialSystemGroupManager{char unknown00[8];ForwardSpatialSystemGroupEntry*entries;};
struct ForwardSpatialGroupEntry{ForwardSpatialGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ForwardSpatialGroupManager{char unknown00[8];ForwardSpatialGroupEntry*entries;};
struct ForwardSpatialTextEntry{ForwardSpatialText*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ForwardSpatialTextManager{char unknown00[8];ForwardSpatialTextEntry*entries;};
struct ForwardSpatialContext{char unknown00[0x118];ForwardSpatialActorManager*manager;char unknown11C[8];ForwardSpatialScene*scene;char unknown128[0x14];ForwardSpatialSystem*system;};
extern "C"ForwardSpatialContext lbl_801E9D24;
inline ForwardSpatialActor*resolveActor(const ForwardSpatialHandle&h){int index=h.index;ForwardSpatialActorManager*m=(ForwardSpatialActorManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline ForwardSpatialResource*resolveResource(const ForwardSpatialHandle&h){int index=h.index;ForwardSpatialResourceManager*m=(ForwardSpatialResourceManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline ForwardSpatialSystemGroup*resolveSystemGroup(const ForwardSpatialHandle&h){int index=h.index;ForwardSpatialSystemGroupManager*m=(ForwardSpatialSystemGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline ForwardSpatialGroup*resolveGroup(const ForwardSpatialHandle&h){int index=h.index;ForwardSpatialGroupManager*m=(ForwardSpatialGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline ForwardSpatialText*resolveText(const ForwardSpatialHandle&h){int index=h.index;ForwardSpatialTextManager*m=(ForwardSpatialTextManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
extern "C"unsigned long fn_801F7EB8(const ForwardSpatialHandle*);
inline ForwardSpatialActor*validResolve(const ForwardSpatialHandle&h){if(fn_801F7EB8(&h))return resolveActor(h);else return 0;}
struct ForwardSpatialResetRecord{ForwardSpatialVector position;ForwardSpatialActor*actor;signed char enabled;};
struct ForwardSpatialResetOwner{void*vtable;signed char enabled;char unknown05[3];float time;signed char pending;unsigned char count;signed char state;char unknown0F;ForwardSpatialResetRecord*records[256];};
struct ForwardSpatialTableRecord{int key;char unknown04[8];char text[0x40];signed char enabled;char unknown4D[3];};
extern "C"{extern ForwardSpatialTableRecord lbl_802F4208[300];extern const ForwardSpatialVector game_vec3_zero;extern const float lbl_80378240,lbl_80379340,lbl_80379784,lbl_80379794,lbl_80379788;signed char fn_80068FE4(void*,signed char);void fn_80059340(ForwardSpatialSceneState*,int);void fn_8025A0A4(ForwardSpatialOwner*);void fn_80259164(ForwardSpatialActor*);}
#endif
