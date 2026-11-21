#ifndef GAME_EARLY_ACTOR_RECORD_DISPATCH_VIEWS_H
#define GAME_EARLY_ACTOR_RECORD_DISPATCH_VIEWS_H
struct RecordDispatchHandle{signed int tag:8;signed int index:24;};
struct RecordDispatchVector{float x,y,z;RecordDispatchVector(){}RecordDispatchVector(const RecordDispatchVector&v):x(v.x),y(v.y),z(v.z){}RecordDispatchVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){}RecordDispatchVector&operator=(const RecordDispatchVector&v){x=v.x;y=v.y;z=v.z;return*this;}};
struct RecordDispatchTransform{char unknown00[0x30];RecordDispatchVector position;};
struct RecordDispatchPrefix{char unknown00[8];};
struct RecordDispatchOptional{char unknown00[0xC];float value;};
struct RecordDispatchActor:RecordDispatchPrefix{
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
virtual unsigned long query(const RecordDispatchHandle&,const RecordDispatchHandle&);
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
virtual const RecordDispatchHandle* slot37(int);
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41(int,int);
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45(const RecordDispatchVector&,int);
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
virtual const RecordDispatchHandle* slot74();
char unknown0C[0x24];unsigned long long flags;char unknown38[0x38];RecordDispatchHandle actor;RecordDispatchOptional*optional74;RecordDispatchOptional*optional78;char unknown7C[4];RecordDispatchHandle related;char unknown84[0xA0];RecordDispatchTransform*transform;char unknown128[0x40];RecordDispatchHandle relatedTarget;char unknown16C[0x284];RecordDispatchVector targetPosition;float optionalValue;
};
struct RecordDispatchPointerOwner{char unknown00[0x10];RecordDispatchActor*actor;};
struct RecordDispatchResource{char unknown00[0x120];unsigned long property;};
struct RecordDispatchSystemGroup{char unknown00[0xB0];RecordDispatchHandle*next;};
struct RecordDispatchGroup{char unknown00[0x70];RecordDispatchHandle actor;};
struct RecordDispatchSystem{char unknown00[0x1C];RecordDispatchHandle*handle;};
struct RecordDispatchText{char unknown00[0x48];void*text;float time;};
struct RecordDispatchSceneState{char unknown00[0x60];RecordDispatchHandle text;};
struct RecordDispatchScene{char unknown00[0x15058];void*state;};
struct RecordDispatchActorEntry{RecordDispatchActor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct RecordDispatchActorManager{char unknown00[8];RecordDispatchActorEntry*entries;};
struct RecordDispatchResourceEntry{RecordDispatchResource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct RecordDispatchResourceManager{char unknown00[8];RecordDispatchResourceEntry*entries;};
struct RecordDispatchSystemGroupEntry{RecordDispatchSystemGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct RecordDispatchSystemGroupManager{char unknown00[8];RecordDispatchSystemGroupEntry*entries;};
struct RecordDispatchGroupEntry{RecordDispatchGroup*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct RecordDispatchGroupManager{char unknown00[8];RecordDispatchGroupEntry*entries;};
struct RecordDispatchTextEntry{RecordDispatchText*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct RecordDispatchTextManager{char unknown00[8];RecordDispatchTextEntry*entries;};
struct RecordDispatchServicePrefix{char unknown00[0x7C];};
struct RecordDispatchService:RecordDispatchServicePrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void remove(RecordDispatchHandle*);};
struct RecordDispatchContext{char unknown00[0x110];void*logger;char unknown114[4];RecordDispatchActorManager*manager;char unknown11C[8];RecordDispatchScene*scene;char unknown128[0x14];RecordDispatchSystem*system;char unknown140[0x18];RecordDispatchService*service;};
extern "C"RecordDispatchContext lbl_801E9D24;
inline RecordDispatchActor*resolveActor(const RecordDispatchHandle&h){int index=h.index;RecordDispatchActorManager*m=(RecordDispatchActorManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline RecordDispatchResource*resolveResource(const RecordDispatchHandle&h){int index=h.index;RecordDispatchResourceManager*m=(RecordDispatchResourceManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline RecordDispatchSystemGroup*resolveSystemGroup(const RecordDispatchHandle&h){int index=h.index;RecordDispatchSystemGroupManager*m=(RecordDispatchSystemGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline RecordDispatchGroup*resolveGroup(const RecordDispatchHandle&h){int index=h.index;RecordDispatchGroupManager*m=(RecordDispatchGroupManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline RecordDispatchText*resolveText(const RecordDispatchHandle&h){int index=h.index;RecordDispatchTextManager*m=(RecordDispatchTextManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
extern "C"unsigned long fn_801F7EB8(const RecordDispatchHandle*);
inline RecordDispatchActor*validResolve(const RecordDispatchHandle&h){if(fn_801F7EB8(&h))return resolveActor(h);else return 0;}
struct RecordDispatchResetRecord{RecordDispatchVector position;RecordDispatchActor*actor;signed char enabled;};
struct RecordDispatchResetOwner{void*vtable;signed char enabled;char unknown05[3];float time;signed char pending;unsigned char count;signed char state;char unknown0F;RecordDispatchResetRecord*records[256];};
struct RecordDispatchTableRecord{int key;char unknown04[8];char text[0x40];signed char enabled;char unknown4D[3];};
extern "C"{extern RecordDispatchTableRecord lbl_802F4208[300];extern const RecordDispatchVector game_vec3_zero;extern const float lbl_80378240,lbl_80379340,lbl_80379784,lbl_80379794,lbl_80379788;signed char fn_80068FE4(void*,signed char);void fn_80059340(RecordDispatchSceneState*,int);void fn_80259164(RecordDispatchActor*);}
struct RecordDispatchHandleArrayOwner{char unknown00[0x48];RecordDispatchHandle*handles;};
struct RecordDispatchModeOwner{char unknown00[0x24];RecordDispatchHandle handle;char unknown28[0x2F8];int state;};
struct RecordDispatchTransition{char unknown00[8];RecordDispatchModeOwner*owner;char unknown0C[0x4C];signed char active;};
extern "C"{void fn_80255678(void*);void fn_80255D88(void*,int,int,int,int);void fn_80255CBC(void*,int,int);void fn_801FA014(void*,const char*,...);void fn_8002B824(RecordDispatchActor*,int);void fn_8005C264(RecordDispatchActor*,int);void fn_8007D6A0(void*,int);extern const char lbl_8029B9C8[];extern const float lbl_803786C0;}
struct RecordDispatchItem{char unknown00[0x70];RecordDispatchHandle actor;};
struct RecordDispatchPool{char unknown00[0x2C8];RecordDispatchItem**items;};
struct RecordDispatchPending{char unknown00[0x100];int state;};
struct RecordDispatchTimedResource{char unknown00[0x24];RecordDispatchHandle related;};
struct RecordDispatchTimed{char unknown00[8];RecordDispatchTimedResource*owner;float time;};
extern "C"{void fn_8005686C(RecordDispatchPool*);signed char fn_8007D604(void*,int);void fn_8007D7F4(void*,int);extern const float lbl_80379164;signed char fn_8025E9FC(void*,int);signed char slot1C__12BaseObject_ZFv(void*);}
struct RecordDispatchOwner{char unknown00[0x70];RecordDispatchHandle handle;char unknown74[0xFC];int count,capacity;RecordDispatchHandle*handles;};
struct RecordDispatchRecord{char unknown00[0x80];RecordDispatchHandle key;char unknown84[0xC];RecordDispatchHandle handles[8];char unknownB0[2];unsigned char count;char unknownB3[0x11];};
struct RecordDispatchQuery{char unknown00[0x24];RecordDispatchHandle handle;char unknown28[0x48];RecordDispatchRecord*records;};
extern "C"{void fn_8003543C(RecordDispatchOwner*,int);void fn_8025A0A4(RecordDispatchOwner*,int);void fn_802073E8(void*,int,void*,float);void fn_8025D054(void*);void fn_801F44DC(void*,RecordDispatchRecord*,unsigned long*);extern const char lbl_8029A604[];extern const float lbl_803784C0;extern const double lbl_80378490;}
#endif
