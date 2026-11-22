/* Resource-owner reset and action sweep; see docs/notes/game-owner-resource-action-reset.md. */
typedef unsigned long Word;typedef unsigned long long Wide;
struct CollectionManager;
struct Context {char unknown00[0x110];void*logger;char*actors;CollectionManager*manager;};
extern "C" {extern Context lbl_801E9D24;extern const char lbl_802ACAD8[];extern const float lbl_8037A3D0;void fn_801F86C8(void*,const void*,short);void*fn_801F7EB8(const void*);void fn_801FA014(void*,const char*,...);void fn_8023297C(void*,const void*,int,int);void fn_8023DE28(void*);void fn_801E2074(void*,const void*,int);void fn_80213A18(void*);}
struct Handle_801F7F10 {union {Word word;struct{signed int tag:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ActionResetZero1_801C5180:Handle_801F7F10 {ActionResetZero1_801C5180(){word=0;}~ActionResetZero1_801C5180(){}};
struct ActionResetZero2_801C5180:ActionResetZero1_801C5180 {ActionResetZero2_801C5180(){word=0;}~ActionResetZero2_801C5180(){}};
struct ActionResetCopy_801C5180:ActionResetZero2_801C5180 {ActionResetCopy_801C5180(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~ActionResetCopy_801C5180(){}};
struct HandleView {signed int tag:8;signed int index:24;};
struct ManagerEntry {void*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager {char unknown00[8];ManagerEntry*entries;};
static inline void assign(HandleView&out,const HandleView&in){fn_801F86C8(lbl_801E9D24.manager,&out,-1);*(Word*)&out=*(const Word*)&in;fn_801F86C8(lbl_801E9D24.manager,&in,1);}
struct ActionStorage {Word unknown00;Handle_801F7F10 own;const Handle_801F7F10&getOwn()const{return own;}};
struct Action:ActionStorage {
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38(float);virtual void slot3C();
};
struct Record {char unknown00[0xC];signed char active;char unknown0D[3];HandleView object;Word unknown14;HandleView retained;};
struct IndexRecord {int index;char unknown04[16];};
struct SelectedIndex {Word unknown00;short index;};
struct Collection {char unknown00[0x18];int selectedCount;Word unknown1C;SelectedIndex*selected;char unknown24[0xC];int recordCount,recordCapacity;Record*records;int indexCount,indexCapacity;IndexRecord*indices;};
struct FlagObject {char unknown00[0x38];Wide flags;};
struct FlagTarget {char unknown00[0xC];Word flags;};
struct LinkTarget {char unknown00[0x20];HandleView related;};
struct ParentTarget {char unknown00[0x130];HandleView parent;};
struct ParentAction:Action {char unknown0C[0x2C];Wide flags;};
struct NodeTarget {char unknown00[0x30];HandleView related;};
struct ActorSlot {char unknown00[0x14];HandleView selected;char unknown18[0x34];};
struct Owner:Action {char unknown0C[0x14];int count,capacity;HandleView*handles;int pairCount,pairCapacity;HandleView*pairs;int recordCount,recordCapacity;Record*records;HandleView collection,target,flags,empty;float time;Word unknown58;int actorIndex;unsigned short flags60;unsigned char state62,state63;};
struct CollectionEntry { Collection*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct CollectionManager {int count,capacity;CollectionEntry*entries;inline Collection*get(const HandleView&h){CollectionEntry*e=entries+h.index;return e->tag==h.tag?e->object:0;}};
static inline Collection*resolveCollection(const HandleView&h){return ((CollectionManager*)lbl_801E9D24.manager)->get(h);}
struct ActionEntry { Action*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct ActionManager {int count,capacity;ActionEntry*entries;inline Action*get(const HandleView&h){ActionEntry*e=entries+h.index;return e->tag==h.tag?e->object:0;}};
static inline Action*resolveAction(const HandleView&h){return ((ActionManager*)lbl_801E9D24.manager)->get(h);}
struct FlagObjectEntry { FlagObject*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct FlagObjectManager {int count,capacity;FlagObjectEntry*entries;inline FlagObject*get(const HandleView&h){FlagObjectEntry*e=entries+h.index;return e->tag==h.tag?e->object:0;}};
static inline FlagObject*resolveFlagObject(const HandleView&h){return ((FlagObjectManager*)lbl_801E9D24.manager)->get(h);}
struct LinkTargetEntry { LinkTarget*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct LinkTargetManager {int count,capacity;LinkTargetEntry*entries;inline LinkTarget*get(const HandleView&h){LinkTargetEntry*e=entries+h.index;return e->tag==h.tag?e->object:0;}};
static inline LinkTarget*resolveLinkTarget(const HandleView&h){return ((LinkTargetManager*)lbl_801E9D24.manager)->get(h);}
struct FlagTargetEntry { FlagTarget*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct FlagTargetManager {int count,capacity;FlagTargetEntry*entries;inline FlagTarget*get(const HandleView&h){FlagTargetEntry*e=entries+h.index;return e->tag==h.tag?e->object:0;}};
static inline FlagTarget*resolveFlagTarget(const HandleView&h){return ((FlagTargetManager*)lbl_801E9D24.manager)->get(h);}
struct ParentTargetEntry { ParentTarget*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct ParentTargetManager {int count,capacity;ParentTargetEntry*entries;inline ParentTarget*get(const HandleView&h){ParentTargetEntry*e=entries+h.index;return e->tag==h.tag?e->object:0;}};
static inline ParentTarget*resolveParentTarget(const HandleView&h){return ((ParentTargetManager*)lbl_801E9D24.manager)->get(h);}
struct ParentActionEntry { ParentAction*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct ParentActionManager {int count,capacity;ParentActionEntry*entries;inline ParentAction*get(const HandleView&h){ParentActionEntry*e=entries+h.index;return e->tag==h.tag?e->object:0;}};
static inline ParentAction*resolveParentAction(const HandleView&h){return ((ParentActionManager*)lbl_801E9D24.manager)->get(h);}
struct NodeTargetEntry { NodeTarget*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct NodeTargetManager {int count,capacity;NodeTargetEntry*entries;inline NodeTarget*get(const HandleView&h){NodeTargetEntry*e=entries+h.index;return e->tag==h.tag?e->object:0;}};
static inline NodeTarget*resolveNodeTarget(const HandleView&h){return ((NodeTargetManager*)lbl_801E9D24.manager)->get(h);}
extern "C" void fn_801C5180(Owner*self){
 int i; Collection*collection=resolveCollection(self->collection);
 for(i=0;i<self->count;++i){Action*action=resolveAction(self->handles[i]);fn_8023297C(action,&self->pairs[i],0,1);action->slot3C();}
 FlagObject*object=resolveFlagObject(self->flags);
 if(object->flags&0x200000ULL)self->flags60|=0x20;
 else{
  self->flags60&=0xFFDF;
  ActorSlot*actor=&((ActorSlot*)lbl_801E9D24.actors)[self->actorIndex];
  if(collection->selectedCount)assign(actor->selected,self->records[collection->selected->index].object);
  else fn_801FA014(lbl_801E9D24.logger,lbl_802ACAD8);
 }
 for(i=0;i<collection->indexCount;++i){LinkTargetManager*manager=(LinkTargetManager*)lbl_801E9D24.manager;LinkTarget*link=manager->get(self->records[collection->indices[i].index].object);FlagTarget*target=((FlagTargetManager*)manager)->get(link->related);target->flags&=~1;}
 for(i=0;i<collection->recordCount;++i){
  if(collection->records[i].active&&fn_801F7EB8(&collection->records[i].retained)){
   ParentTargetManager*manager=(ParentTargetManager*)lbl_801E9D24.manager;ParentTarget*target=manager->get(collection->records[i].object);ParentAction*parent=((ParentActionManager*)manager)->get(target->parent);
   if(parent){parent->slot30();parent->flags|=0x40000ULL;}
  }
 }
 self->flags60=0;self->state63=0;
 {ActionResetZero2_801C5180 empty;assign(self->empty,*(HandleView*)&empty);}
 self->time=lbl_8037A3D0;self->slot38(lbl_8037A3D0);
 NodeTargetManager*manager=(NodeTargetManager*)lbl_801E9D24.manager;NodeTarget*node=manager->get(self->target);fn_8023DE28(((ActionManager*)manager)->get(node->related));
 if(self->actorIndex>=0){ActionResetCopy_801C5180 copy(self->getOwn());fn_801E2074(&((ActorSlot*)lbl_801E9D24.actors)[self->actorIndex],&copy,0);}
 fn_80213A18(self);
}
