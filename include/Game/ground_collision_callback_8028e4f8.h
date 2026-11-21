#ifndef GAME_GROUND_COLLISION_CALLBACK_8028E4F8_H
#define GAME_GROUND_COLLISION_CALLBACK_8028E4F8_H

// Partial native views: only observed fields and virtual slots are declared.
typedef unsigned int GroundCollisionWord;
typedef unsigned long long GroundCollisionFlags;
struct GroundCollisionVec3 {float x,y,z;GroundCollisionVec3(){} GroundCollisionVec3(float a,float b,float c):x(a),y(b),z(c){} GroundCollisionVec3(const GroundCollisionVec3&v){x=v.x;y=v.y;z=v.z;}};
struct GroundCollisionVec4:GroundCollisionVec3 {float w;GroundCollisionVec4(const GroundCollisionVec3&v,float f):GroundCollisionVec3(v),w(f){}};
struct GroundCollisionRay {GroundCollisionVec3 origin;float length;GroundCollisionVec3 direction;float unknown1C;GroundCollisionRay(const GroundCollisionVec3&o,const GroundCollisionVec3&d,float l):origin(o),direction(d){length=l;}};
struct GroundCollisionResult {GroundCollisionVec3 point;char unknown0C[0x28-12];GroundCollisionFlags flags;void*object;void*other;void*extra;signed char hit;char unknown3D[3];GroundCollisionWord end;GroundCollisionResult(){hit=0;object=0;other=0;extra=0;flags=0;}};
struct GroundCollisionActor;struct GroundCollisionOwner;struct GroundCollisionTypeObject;
struct GroundCollisionHandle {signed int generation:8,index:24;GroundCollisionActor*getActor()const;GroundCollisionOwner*getOwner()const;GroundCollisionTypeObject*getTypeObject()const;};
struct GroundCollisionStorage {GroundCollisionWord unknown00,unknown04;};
struct GroundCollisionOwner:GroundCollisionStorage {
 virtual void slot08();
 virtual void slot0C();
 virtual void slot10();
 virtual void slot14();
 virtual void slot18();
 virtual void slot1C();
 virtual void slot20();
 virtual void slot24();
 virtual void slot28();
 virtual void slot2C();
 virtual void slot30();
 virtual void slot34();
 virtual void slot38();
 virtual void slot3C();
 virtual void slot40();
 virtual void slot44();
 virtual void contact(GroundCollisionActor*,const GroundCollisionVec3&,GroundCollisionResult*,float);
 virtual void slot4C();
 virtual void slot50();
 virtual void slot54();
 virtual void slot58();
 virtual void slot5C();
 virtual void slot60();
 virtual void slot64();
 virtual void slot68();
 virtual void slot6C();
 virtual void slot70();
 virtual void slot74();
 virtual void slot78();
 virtual void slot7C();
 virtual void slot80();
 virtual void slot84();
 virtual signed char getPoint(GroundCollisionVec4&,int,int);
 virtual void slot8C();
 virtual void slot90();
 virtual void slot94();
 virtual void slot98();
 virtual const GroundCollisionHandle*getHandle(int);
 GroundCollisionWord flags;
};
struct GroundCollisionSelf:GroundCollisionOwner {char unknown10[0x30-0x10];GroundCollisionFlags mode;char unknown38[0xD0-0x38];float height;};
struct GroundCollisionActor {char unknown00[0x1C];GroundCollisionHandle type,owner;char unknown24[0x120-0x24];GroundCollisionWord flags;};
struct GroundCollisionTypeObject {char unknown00[0x6C];unsigned short type;};
struct GroundCollisionActorEntry {GroundCollisionActor*object;GroundCollisionWord key;char unknown08[4];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct GroundCollisionOwnerEntry {GroundCollisionOwner*object;GroundCollisionWord key;char unknown08[4];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct GroundCollisionTypeEntry {GroundCollisionTypeObject*object;GroundCollisionWord key;char unknown08[4];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct GroundCollisionActorManager {int count,capacity;GroundCollisionActorEntry*entries;};struct GroundCollisionOwnerManager {int count,capacity;GroundCollisionOwnerEntry*entries;};struct GroundCollisionTypeManager {int count,capacity;GroundCollisionTypeEntry*entries;};
struct GroundCollisionGlobals {char unknown00[0x118];union {GroundCollisionActorManager*actorManager;GroundCollisionOwnerManager*ownerManager;GroundCollisionTypeManager*typeManager;};};
extern "C" {extern GroundCollisionGlobals lbl_801E9D24;extern const GroundCollisionVec3 game_vec4_zero;extern const float lbl_8037B940,lbl_8037B944,lbl_8037B948,lbl_8037B94C,lbl_8037B950,lbl_8037B954,lbl_8037B958,lbl_8037B95C,lbl_8037B960;
signed char fn_80269230(void*,const GroundCollisionRay&,GroundCollisionResult*,GroundCollisionFlags,GroundCollisionFlags);void fn_801CBDE4(GroundCollisionOwner*,GroundCollisionActor*,void*,float);}
inline GroundCollisionActor*GroundCollisionHandle::getActor()const {int i=index;GroundCollisionActorManager*m=lbl_801E9D24.actorManager;int tag=m->entries[i].getGeneration();return tag==generation?m->entries[i].object:0;}
inline GroundCollisionOwner*GroundCollisionHandle::getOwner()const {int i=index;GroundCollisionOwnerManager*m=lbl_801E9D24.ownerManager;int tag=m->entries[i].getGeneration();return tag==generation?m->entries[i].object:0;}
inline GroundCollisionTypeObject*GroundCollisionHandle::getTypeObject()const {int i=index;GroundCollisionTypeManager*m=lbl_801E9D24.typeManager;int tag=m->entries[i].getGeneration();return tag==generation?m->entries[i].object:0;}

extern "C" void fn_8028E4F8(GroundCollisionSelf*,void*,void*,float);

#endif
