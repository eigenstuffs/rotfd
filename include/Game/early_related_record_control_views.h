#ifndef GAME_EARLY_RELATED_RECORD_CONTROL_VIEWS_H
#define GAME_EARLY_RELATED_RECORD_CONTROL_VIEWS_H
struct RelatedRecordHandle{signed int tag:8;signed int index:24;};
struct RelatedRecordVector{float x,y,z;RelatedRecordVector(){}RelatedRecordVector(const RelatedRecordVector&v):x(v.x),y(v.y),z(v.z){}RelatedRecordVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){}RelatedRecordVector&operator=(const RelatedRecordVector&v){x=v.x;y=v.y;z=v.z;return*this;}};
struct RelatedRecordTransform{char unknown00[0x30];RelatedRecordVector position;};
struct RelatedRecordPrefix{char unknown00[8];};
struct RelatedRecordActor:RelatedRecordPrefix{
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
virtual const RelatedRecordHandle* slot37(int);
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41(int,int);
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45(const RelatedRecordVector&,int);
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
virtual const RelatedRecordHandle* slot74();
char unknown0C[0x24];unsigned long long flags;char unknown38[0x38];RelatedRecordHandle actor;char unknown74[0xC];RelatedRecordHandle related;char unknown84[0xA0];RelatedRecordTransform*transform;char unknown128[0x84];RelatedRecordVector targetPosition;char unknown1B8[0x21C];float savedY;
};
struct RelatedRecordOwner{char unknown00[0x58];RelatedRecordHandle resource;char unknown5C[0x14];RelatedRecordHandle actor;};
struct RelatedRecordPointerOwner{char unknown00[0x10];RelatedRecordActor*actor;};
struct RelatedRecordResource{char unknown00[0x120];unsigned long property;};
struct RelatedRecordSystemGroup{char unknown00[0xB0];RelatedRecordHandle*next;};
struct RelatedRecordGroup{char unknown00[0x70];RelatedRecordHandle actor;};
struct RelatedRecordSystem{char unknown00[0x1C];RelatedRecordHandle*handle;};
struct RelatedRecordText{char unknown00[0x48];void*text;float time;};
struct RelatedRecordSceneState{char unknown00[0x60];RelatedRecordHandle text;};
struct RelatedRecordScene{char unknown00[0x15058];RelatedRecordSceneState*state;};
struct RelatedRecordActorEntry{RelatedRecordActor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct RelatedRecordActorManager{char unknown00[8];RelatedRecordActorEntry*entries;};
struct RelatedRecordResourceEntry{RelatedRecordResource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct RelatedRecordResourceManager{char unknown00[8];RelatedRecordResourceEntry*entries;};
struct RelatedRecordSystemGroupEntry{RelatedRecordSystemGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct RelatedRecordSystemGroupManager{char unknown00[8];RelatedRecordSystemGroupEntry*entries;};
struct RelatedRecordGroupEntry{RelatedRecordGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct RelatedRecordGroupManager{char unknown00[8];RelatedRecordGroupEntry*entries;};
struct RelatedRecordTextEntry{RelatedRecordText*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct RelatedRecordTextManager{char unknown00[8];RelatedRecordTextEntry*entries;};
struct RelatedRecordContext{char unknown00[0x110];void*logger;char unknown114[4];RelatedRecordActorManager*manager;char unknown11C[8];RelatedRecordScene*scene;char unknown128[0x14];RelatedRecordSystem*system;};
extern "C"RelatedRecordContext lbl_801E9D24;
inline RelatedRecordActor*resolveActor(const RelatedRecordHandle&h){int index=h.index;RelatedRecordActorManager*m=(RelatedRecordActorManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline RelatedRecordResource*resolveResource(const RelatedRecordHandle&h){int index=h.index;RelatedRecordResourceManager*m=(RelatedRecordResourceManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline RelatedRecordSystemGroup*resolveSystemGroup(const RelatedRecordHandle&h){int index=h.index;RelatedRecordSystemGroupManager*m=(RelatedRecordSystemGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline RelatedRecordGroup*resolveGroup(const RelatedRecordHandle&h){int index=h.index;RelatedRecordGroupManager*m=(RelatedRecordGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline RelatedRecordText*resolveText(const RelatedRecordHandle&h){int index=h.index;RelatedRecordTextManager*m=(RelatedRecordTextManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
extern "C"unsigned long fn_801F7EB8(const RelatedRecordHandle*);
inline RelatedRecordActor*validResolve(const RelatedRecordHandle&h){if(fn_801F7EB8(&h))return resolveActor(h);else return 0;}
struct RelatedRecordResetRecord{RelatedRecordVector position;RelatedRecordActor*actor;signed char enabled;};
struct RelatedRecordResetOwner{void*vtable;signed char enabled;char unknown05[3];float time;signed char pending;unsigned char count;signed char state;char unknown0F;RelatedRecordResetRecord*records[256];};
struct RelatedRecordTableRecord{int key;char unknown04[8];char text[0x40];signed char enabled;char unknown4D[3];};
extern "C"{extern RelatedRecordTableRecord lbl_802F4208[300];extern const RelatedRecordVector game_vec3_zero;extern const float lbl_80378240,lbl_80379340,lbl_80379784,lbl_80379794,lbl_80379788;signed char fn_80068FE4(void*,signed char);void fn_80059340(RelatedRecordSceneState*,int);void fn_8025A0A4(RelatedRecordOwner*);void fn_80259164(RelatedRecordActor*);}
struct RelatedRecordHandleArrayOwner{char unknown00[0x48];RelatedRecordHandle*handles;};
struct RelatedRecordModeOwner{char unknown00[0x24];RelatedRecordHandle handle;char unknown28[0x2F8];int state;};
struct RelatedRecordTransition{char unknown00[8];RelatedRecordModeOwner*owner;char unknown0C[0x4C];signed char active;};
extern "C"{void fn_80255678(void*);void fn_80255D88(void*,int,int,int,int);void fn_80255CBC(void*,int,int);void fn_801FA014(void*,const char*,...);void fn_8002B824(RelatedRecordActor*,int);void fn_8005C264(RelatedRecordActor*,int);void fn_8007D6A0(void*,int);extern const char lbl_8029B9C8[];extern const float lbl_803786C0;}
struct RelatedRecordItem{char unknown00[0x70];RelatedRecordHandle actor;};
struct RelatedRecordPool{char unknown00[0x2C8];RelatedRecordItem**items;};
struct RelatedRecordPending{char unknown00[0x100];int state;};
struct RelatedRecordTimedResource{char unknown00[0x24];RelatedRecordHandle related;};
struct RelatedRecordTimed{char unknown00[8];RelatedRecordTimedResource*owner;float time;};
extern "C"{void fn_8005686C(RelatedRecordPool*);signed char fn_8007D604(void*,int);void fn_8007D7F4(void*,int);extern const float lbl_80379164;signed char fn_8025E9FC(void*,int);signed char slot1C__12BaseObject_ZFv(void*);}
#endif
