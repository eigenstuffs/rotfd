#ifndef GAME_EARLY_OWNER_OPERATION_CONTROL_VIEWS_H
#define GAME_EARLY_OWNER_OPERATION_CONTROL_VIEWS_H
struct OperationVector{float x,y,z;OperationVector(float xx,float yy,float zz):x(xx),y(yy),z(zz){}};
struct OperationTransform{char unknown00[0x30];OperationVector position;};
struct OperationResource;
struct OperationHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct OperationEntry{OperationResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct OperationManager{int count,capacity;OperationEntry*entries;};
struct OperationContext{char unknown00[0x118];OperationManager*manager;};
extern "C" OperationContext lbl_801E9D24;
struct OperationResourcePrefix{char unknown00[8];};
struct OperationResourceBase:OperationResourcePrefix{
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
};
struct OperationResource:OperationResourceBase{
virtual void slot12();
char unknown0C[0x2C];unsigned long long flags;char unknown40[0x18];OperationHandle owner;char unknown5C[0xC4];unsigned long actorFlags;OperationTransform*transform;char unknown128[0xC5];signed char mode;
};
struct OperationActor{char unknown00[0x120];unsigned long flags;};
struct OperationActorEntry{OperationActor*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct OperationActorManager{int count,capacity;OperationActorEntry*entries;};
inline OperationResource*resolveOperation(const OperationHandle&h){OperationEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
inline OperationActor*resolveOperationActor(const OperationHandle&h){OperationActorEntry*entry=&((OperationActorManager*)lbl_801E9D24.manager)->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
struct OperationPrefix{char unknown00[4];};
struct OperationObject:OperationPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual OperationResource*getResource();};
struct OperationData{char unknown00[0x45];unsigned char active;char unknown46[0x112];signed char notify;};
extern "C" {void fn_8023D100(OperationResource*,const OperationVector*);void fn_8023DE28(OperationResource*);OperationData*fn_8005EE10(OperationResource*);void fn_8006B470(OperationObject*,OperationResource*,int);}
struct OperationActorHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct OperationActorResource{char unknown00[0x58];OperationActorHandle owner;};
inline OperationActor*resolveOperationActorTyped(const OperationActorHandle&h){OperationActorEntry*entry=&((OperationActorManager*)lbl_801E9D24.manager)->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}

#endif
