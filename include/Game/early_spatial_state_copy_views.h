#ifndef GAME_EARLY_SPATIAL_STATE_COPY_VIEWS_H
#define GAME_EARLY_SPATIAL_STATE_COPY_VIEWS_H
struct ResetSpatialHandle{signed int tag:8;signed int index:24;};
struct ResetSpatialVector{float x,y,z;ResetSpatialVector(){}ResetSpatialVector(const ResetSpatialVector&v):x(v.x),y(v.y),z(v.z){}ResetSpatialVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){}ResetSpatialVector&operator=(const ResetSpatialVector&v){x=v.x;y=v.y;z=v.z;return*this;}};
struct ResetSpatialTransform{char unknown00[0x30];ResetSpatialVector position;};
struct ResetSpatialPrefix{char unknown00[8];};
struct ResetSpatialActor:ResetSpatialPrefix{
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
virtual const ResetSpatialHandle* slot37(int);
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45(const ResetSpatialVector&,int);
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
virtual const ResetSpatialHandle* slot74();
char unknown0C[0x24];unsigned long long flags;char unknown38[0x48];ResetSpatialHandle related;char unknown84[0xA0];ResetSpatialTransform*transform;char unknown128[0x1C];ResetSpatialVector velocity;char unknown150[0x48];ResetSpatialVector position;char unknown1A4[0x1F4];ResetSpatialVector origin;
inline void setPosition(ResetSpatialVector v){position=v;}
inline void setVelocity(ResetSpatialVector v){velocity=v;}
};
struct ResetSpatialOwner{char unknown00[0x58];ResetSpatialHandle resource;char unknown5C[0x14];ResetSpatialHandle actor;};
struct ResetSpatialPointerOwner{char unknown00[0x10];ResetSpatialActor*actor;};
struct ResetSpatialResource{char unknown00[0x120];unsigned long property;};
struct ResetSpatialSystemGroup{char unknown00[0xB0];ResetSpatialHandle*next;};
struct ResetSpatialGroup{char unknown00[0x70];ResetSpatialHandle actor;};
struct ResetSpatialSystem{char unknown00[0x1C];ResetSpatialHandle*handle;};
struct ResetSpatialText{char unknown00[0x48];void*text;float time;};
struct ResetSpatialSceneState{char unknown00[0x60];ResetSpatialHandle text;};
struct ResetSpatialScene{char unknown00[0x15058];ResetSpatialSceneState*state;};
struct ResetSpatialActorEntry{ResetSpatialActor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ResetSpatialActorManager{char unknown00[8];ResetSpatialActorEntry*entries;};
struct ResetSpatialResourceEntry{ResetSpatialResource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ResetSpatialResourceManager{char unknown00[8];ResetSpatialResourceEntry*entries;};
struct ResetSpatialSystemGroupEntry{ResetSpatialSystemGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ResetSpatialSystemGroupManager{char unknown00[8];ResetSpatialSystemGroupEntry*entries;};
struct ResetSpatialGroupEntry{ResetSpatialGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ResetSpatialGroupManager{char unknown00[8];ResetSpatialGroupEntry*entries;};
struct ResetSpatialTextEntry{ResetSpatialText*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ResetSpatialTextManager{char unknown00[8];ResetSpatialTextEntry*entries;};
struct ResetSpatialContext{char unknown00[0x118];ResetSpatialActorManager*manager;char unknown11C[8];ResetSpatialScene*scene;char unknown128[0x14];ResetSpatialSystem*system;};
extern "C"ResetSpatialContext lbl_801E9D24;
inline ResetSpatialActor*resolveActor(const ResetSpatialHandle&h){int index=h.index;ResetSpatialActorManager*m=(ResetSpatialActorManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline ResetSpatialResource*resolveResource(const ResetSpatialHandle&h){int index=h.index;ResetSpatialResourceManager*m=(ResetSpatialResourceManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline ResetSpatialSystemGroup*resolveSystemGroup(const ResetSpatialHandle&h){int index=h.index;ResetSpatialSystemGroupManager*m=(ResetSpatialSystemGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline ResetSpatialGroup*resolveGroup(const ResetSpatialHandle&h){int index=h.index;ResetSpatialGroupManager*m=(ResetSpatialGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline ResetSpatialText*resolveText(const ResetSpatialHandle&h){int index=h.index;ResetSpatialTextManager*m=(ResetSpatialTextManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
extern "C"unsigned long fn_801F7EB8(const ResetSpatialHandle*);
inline ResetSpatialActor*validResolve(const ResetSpatialHandle&h){if(fn_801F7EB8(&h))return resolveActor(h);else return 0;}
struct ResetSpatialResetRecord{ResetSpatialVector position;ResetSpatialActor*actor;signed char enabled;};
struct ResetSpatialResetOwner{void*vtable;signed char enabled;char unknown05[3];float time;signed char pending;unsigned char count;signed char state;char unknown0F;ResetSpatialResetRecord*records[256];};
struct ResetSpatialTableRecord{int key;char unknown04[8];char text[0x40];signed char enabled;char unknown4D[3];};
extern "C"{extern ResetSpatialTableRecord lbl_802F4208[300];extern const ResetSpatialVector game_vec3_zero;extern const float lbl_80378240,lbl_80379340,lbl_80379784,lbl_80379794,lbl_80379788;signed char fn_80068FE4(void*,signed char);void fn_80059340(ResetSpatialSceneState*,int);void fn_8025A0A4(ResetSpatialOwner*);void fn_80259164(ResetSpatialActor*);}
#endif
