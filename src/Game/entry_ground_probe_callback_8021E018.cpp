/* fn_8021E018: per-entry ground probe (sibling of fn_8028E4F8): ray-casts down from the
 * entry point, stores the hit height, notifies the owner and updates contact flags.
 * The owner handle resolve is an explicit if/else into the local (register choice). */
// Partial native views: only observed fields and virtual slots are declared.
typedef unsigned int CollisionWord;
typedef unsigned long long CollisionFlags;
struct CollisionVec3 {float x,y,z;CollisionVec3(){} CollisionVec3(float a,float b,float c):x(a),y(b),z(c){} CollisionVec3(const CollisionVec3&v){x=v.x;y=v.y;z=v.z;}};
struct CollisionVec4:CollisionVec3 {float w;CollisionVec4(const CollisionVec3&v,float f):CollisionVec3(v),w(f){}};
struct CollisionRay {CollisionVec3 origin;float length;CollisionVec3 direction;float unknown1C;CollisionRay(const CollisionVec3&o,const CollisionVec3&d,float l):origin(o),direction(d){length=l;}};
struct CollisionResult {CollisionVec3 point;char unknown0C[0x28-12];CollisionFlags flags;void*object;void*other;void*extra;signed char hit;char unknown3D[3];CollisionWord end;CollisionResult(){hit=0;object=0;other=0;extra=0;flags=0;}};
struct CollisionActor;struct CollisionOwner;struct CollisionTypeObject;
struct CollisionHandle {signed int generation:8,index:24;CollisionActor*getActor()const;CollisionOwner*getOwner()const;CollisionTypeObject*getTypeObject()const;};
struct CollisionStorage {CollisionWord unknown00,unknown04;};
struct CollisionOwner:CollisionStorage {
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
 virtual void contact(CollisionActor*,const CollisionVec3&,CollisionResult*,float);
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
 virtual signed char getPoint(CollisionVec4&,int,int);
 virtual void slot8C();
 virtual void slot90();
 virtual void slot94();
 virtual void slot98();
 virtual void slot9C();
 virtual void slotA0();
 virtual void slotA4();
 virtual void slotA8();
 virtual void slotAC();
 virtual void slotB0();
 virtual void slotB4();
 virtual void slotB8();
 virtual void slotBC();
 virtual void slotC0();
 virtual void slotC4();
 virtual void slotC8();
 virtual void slotCC();
 virtual void slotD0();
 virtual void slotD4();
 virtual void slotD8();
 virtual void slotDC();
 virtual void slotE0();
 virtual void slotE4();
 virtual CollisionFlags getMode(int);
 CollisionWord flags;
};
struct CollisionEntry {char unknown00[0x28];float height;char unknown2C[0x38-0x2C];CollisionFlags flags;CollisionHandle actor;char unknown44[0xA8-0x44];};
struct CollisionSelf:CollisionOwner {char unknown10[0x188-0x10];CollisionEntry*entries;};
struct CollisionActor {char unknown00[0x1C];CollisionHandle type,owner;char unknown24[0x120-0x24];CollisionWord flags;};
struct CollisionTypeObject {char unknown00[0x6C];unsigned short type;};
struct CollisionActorEntry {CollisionActor*object;CollisionWord key;char unknown08[4];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct CollisionOwnerEntry {CollisionOwner*object;CollisionWord key;char unknown08[4];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct CollisionTypeEntry {CollisionTypeObject*object;CollisionWord key;char unknown08[4];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct CollisionActorManager {int count,capacity;CollisionActorEntry*entries;};struct CollisionOwnerManager {int count,capacity;CollisionOwnerEntry*entries;};struct CollisionTypeManager {int count,capacity;CollisionTypeEntry*entries;};
struct CollisionGlobals {char unknown00[0x118];union {CollisionActorManager*actorManager;CollisionOwnerManager*ownerManager;CollisionTypeManager*typeManager;};};
extern "C" {extern CollisionGlobals lbl_801E9D24;extern const CollisionVec3 game_vec4_zero;extern const float lbl_8037B050,lbl_8037B054,lbl_8037B058,lbl_8037B05C,lbl_8037B060,lbl_8037B064,lbl_8037B068,lbl_8037B06C;
signed char fn_80269230(void*,const CollisionRay&,CollisionResult*,CollisionFlags,CollisionFlags);void fn_801CBDE4(CollisionOwner*,CollisionActor*,void*,float);}
inline CollisionActor*CollisionHandle::getActor()const {int i=index;CollisionActorManager*m=lbl_801E9D24.actorManager;int tag=m->entries[i].getGeneration();return tag==generation?m->entries[i].object:0;}
inline CollisionOwner*CollisionHandle::getOwner()const {int i=index;CollisionOwnerManager*m=lbl_801E9D24.ownerManager;int tag=m->entries[i].getGeneration();return tag==generation?m->entries[i].object:0;}
inline CollisionTypeObject*CollisionHandle::getTypeObject()const {int i=index;CollisionTypeManager*m=lbl_801E9D24.typeManager;int tag=m->entries[i].getGeneration();return tag==generation?m->entries[i].object:0;}

extern "C" void fn_8021E018(CollisionSelf*self,float delta,void*context,int index){
 CollisionFlags flags=self->getMode(index);
 if(flags&0xA000ULL){
  CollisionVec4 point(game_vec4_zero,lbl_8037B050);
  if(self->getPoint(point,3,index)){
   CollisionEntry*entry=&self->entries[index];
   CollisionActor*actor=entry->actor.getActor();
   CollisionOwner*owner;
   {int i=actor->owner.index;CollisionOwnerManager*m=lbl_801E9D24.ownerManager;int tag=m->entries[i].getGeneration();if(tag==actor->owner.generation)owner=m->entries[i].object;else owner=0;}
   CollisionResult result;
   point.y+=lbl_8037B054;
   CollisionVec3 oldPoint=point;
   float span=lbl_8037B054+entry->height;
   if(span<lbl_8037B058)span=lbl_8037B05C;
   else if(span>=lbl_8037B060)span=lbl_8037B064;
   float remaining=lbl_8037B060-span;
   while(remaining>lbl_8037B058 && !fn_80269230(context,CollisionRay(point,CollisionVec3(lbl_8037B068,lbl_8037B06C,lbl_8037B068),span),&result,0x0000876000000002ULL,0x0000000400000008ULL)){
    remaining-=span;point.y-=span;span=lbl_8037B050;
   }
   if(remaining>lbl_8037B058){
    entry->height=oldPoint.y-result.point.y;
    if(actor->type.getTypeObject()->type==5)fn_801CBDE4(owner,actor,result.object,delta);
    owner->contact(actor,oldPoint,&result,point.w);
    if(!(flags&0x2000ULL))actor->flags&=~0x80000;
    if((flags&0x8000ULL)&&(result.flags&0x100ULL))owner->flags|=0x10;
    else owner->flags&=~0x10;
   }else{actor->flags&=~0x80000;owner->flags&=~0x10;}
   if(entry->flags&0x80ULL)entry->flags&=~0xA000ULL;
  }
 }
}
