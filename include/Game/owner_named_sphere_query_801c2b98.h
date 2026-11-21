#ifndef GAME_OWNER_NAMED_SPHERE_QUERY_801C2B98_H
#define GAME_OWNER_NAMED_SPHERE_QUERY_801C2B98_H

typedef unsigned int OwnerSphereWord;
struct OwnerSphereVec3 { float x,y,z;OwnerSphereVec3(){} OwnerSphereVec3(const OwnerSphereVec3&p){x=p.x;y=p.y;z=p.z;} OwnerSphereVec3&operator=(const OwnerSphereVec3&p){x=p.x;y=p.y;z=p.z;return *this;} };
struct OwnerSphereSphere {OwnerSphereVec3 point;float radius;OwnerSphereSphere&operator=(const OwnerSphereSphere&s){point=s.point;radius=s.radius;return *this;} };
struct OwnerSphereMatrix {float values[16];};
struct OwnerSphereInfo {OwnerSphereSphere bounds;int index;};
struct OwnerSphereHandle;struct OwnerSphereOwner;struct OwnerSphereResource;struct OwnerSphereObject;struct OwnerSphereOtherObject;
struct OwnerSphereHandle {signed int generation:8;signed int index:24;OwnerSphereOwner*getOwner()const;OwnerSphereResource*getResource()const;OwnerSphereObject*getObject()const;OwnerSphereOtherObject*getOther()const;};

struct OwnerSphereStorage {OwnerSphereWord unknown00,unknown04;};
struct OwnerSphereOwner:OwnerSphereStorage {
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
 virtual void slot48();
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
 virtual void slot88();
 virtual void slot8C();
 virtual void slot90();
 virtual void slot94();
 virtual void slot98();
 virtual OwnerSphereHandle*getHandle(int);
 char unknown0C[0x1A8-0xC];OwnerSphereHandle parent;
};
struct OwnerSphereResource{};
struct OwnerSphereObject {char unknown00[0x124];OwnerSphereMatrix*matrix;};
struct OwnerSphereOtherObject {char unknown00[0x124];OwnerSphereMatrix*matrix;};
struct OwnerSphereEntry {OwnerSphereOwner*object;OwnerSphereWord key;char unknown08[4];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct OwnerSphereResourceEntry {OwnerSphereResource*object;OwnerSphereWord key;char unknown08[4];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct OwnerSphereObjectEntry {OwnerSphereObject*object;OwnerSphereWord key;char unknown08[4];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct OwnerSphereOtherEntry {OwnerSphereOtherObject*object;OwnerSphereWord key;char unknown08[4];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct OwnerSphereManager {int count,capacity;OwnerSphereEntry*entries;};struct OwnerSphereResourceManager {int count,capacity;OwnerSphereResourceEntry*entries;};struct OwnerSphereObjectManager {int count,capacity;OwnerSphereObjectEntry*entries;};struct OwnerSphereOtherManager {int count,capacity;OwnerSphereOtherEntry*entries;};
struct OwnerSphereGlobals {char unknown00[0x118];union{OwnerSphereManager*manager;OwnerSphereResourceManager*resourceManager;OwnerSphereObjectManager*objectManager;OwnerSphereOtherManager*otherManager;};};
extern "C" OwnerSphereGlobals lbl_801E9D24;

 inline OwnerSphereOwner*OwnerSphereHandle::getOwner()const{int i=index;OwnerSphereManager*m=lbl_801E9D24.manager;int tag=m->entries[i].getGeneration();return tag==generation?m->entries[i].object:0;}
 inline OwnerSphereResource*OwnerSphereHandle::getResource()const{int i=index;OwnerSphereResourceManager*m=lbl_801E9D24.resourceManager;int tag=m->entries[i].getGeneration();return tag==generation?m->entries[i].object:0;}
 inline OwnerSphereObject*OwnerSphereHandle::getObject()const{int i=index;OwnerSphereObjectManager*m=lbl_801E9D24.objectManager;int tag=m->entries[i].getGeneration();return tag==generation?m->entries[i].object:0;}
 inline OwnerSphereOtherObject*OwnerSphereHandle::getOther()const{int i=index;OwnerSphereOtherManager*m=lbl_801E9D24.otherManager;int tag=m->entries[i].getGeneration();return tag==generation?m->entries[i].object:0;}

struct OwnerSphereName;
extern "C" {OwnerSphereWord fn_801F948C(OwnerSphereName*,const char*);OwnerSphereHandle*fn_8022E63C(OwnerSphereOwner*);signed char fn_8024C138(OwnerSphereResource*,const OwnerSphereName&,const OwnerSphereHandle*,OwnerSphereInfo*);void fn_801F1080(const OwnerSphereMatrix*,const OwnerSphereMatrix*,OwnerSphereMatrix*);OwnerSphereSphere fn_80099A00(OwnerSphereMatrix,const OwnerSphereSphere*);extern const OwnerSphereVec3 game_vec4_zero;extern const float lbl_8037A3B0;extern const char lbl_8037A3B4[4],lbl_8037A3B8[7],lbl_802ACA78[];}
struct OwnerSphereName {OwnerSphereWord value;OwnerSphereName(const char*s){value=fn_801F948C(this,s);}};
static inline OwnerSphereMatrix product(const OwnerSphereMatrix*a,const OwnerSphereMatrix*b){OwnerSphereMatrix m;fn_801F1080(a,b,&m);return m;}

extern "C" signed char fn_801C2B98(OwnerSphereOwner*,OwnerSphereSphere*,unsigned short,int);

#endif
