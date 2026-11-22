/* Merged translation unit .text 0x801C453C-0x801C6968, .sdata2 0x8037A3D0-0x8037A3E8:
 * fn_801C453C, fn_801C4968, fn_801C4B7C, fn_801C4BC4, fn_801C4C78, fn_801C4F7C, fn_801C5180, fn_801C5698,
 * fn_801C6968, fn_801C6980, fn_801C6C94, fn_801C6DE0 (.text to 0x801C7F64, .sdata2 0x8037A3C8-0x8037A408).
 * .sdata2 is compiler-pooled only: 0.0f (0x8037A3D0), signed int->float bias (0x8037A3D8),
 * unsigned bias (0x8037A3E0), in first-use order (fn_801C453C).  Every former use of
 * 0.0f is the literal 0.0f; a named definition would add a second pooled copy. */
typedef unsigned long Word;
typedef unsigned long long Wide;
/* Shared handle type: its out-of-line ctor/dtor are referenced by mangled name. */
struct Handle_801F7F10 { union { Word word; Word value; struct { signed int tag:8; signed int index:24; } bits; }; Handle_801F7F10(); ~Handle_801F7F10(); int getIndex() const { return bits.index; } int getTag() const { return bits.tag; } template<class T> T* get() const; };
inline void* operator new(unsigned long, void* p) { return p; }

/* ---- part_801C453C (fn_801C453C, fn_801C4968) ---- */
namespace part_801C453C {
struct HZero1 : Handle_801F7F10 { HZero1(){word=0;} ~HZero1(){} };
struct HZero2 : HZero1 { HZero2(){word=0;} ~HZero2(){} };
struct HandleView { signed int tag:8; signed int index:24; };
struct Record { int type; unsigned long value, extra; Record(){type=-1;extra=0;value=0;} };
struct RecordB { int type; unsigned long value, extra; RecordB(){extra=0;} };
struct Event { RecordB rec; float time; int a,b,c,d,e,f; int g,h; Event(){} Event& operator=(const Event&o){rec.type=o.rec.type;rec.value=o.rec.value;rec.extra=o.rec.extra;time=o.time;a=o.a;b=o.b;c=o.c;d=o.d;e=o.e;f=o.f;return *this;} };
struct EvItem { short time; short pad; int count, capacity; Record* items; };
struct Collection { char unknown00[0x58]; int evCount, evCapacity; EvItem* events; char unknown64[0x10]; float length; };
struct CollectionEntry { Collection* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct CollectionManager { int count, capacity; CollectionEntry* entries;
  inline Collection* get(const HandleView& h){ CollectionEntry* e = entries + h.index; return e->tag == h.tag ? e->object : 0; } };
struct Context { char unknown00[0x110]; void* logger; char* actors; CollectionManager* manager; };
extern "C" { extern Context lbl_801E9D24; void fn_801F86C8(void*, const void*, short); void* fn_801F7EB8(const void*); }

struct Vec2f { float x, y; Vec2f() {} Vec2f(float a, float b) { x = a; y = b; } void Set(float a, float b) { x = a; y = b; } };
struct Vec3f { float x, y, z; Vec3f(float a, float b, float c) { x = a; y = b; z = c; } };
struct Color { float r, g, b, a; Color(const Color& o) { r = o.r; g = o.g; b = o.b; a = o.a; } };
struct HCopy1 : HZero1 { HCopy1(const Handle_801F7F10& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); } ~HCopy1() {} };
struct RendererBase { char unknown00[0x278]; };
struct Renderer : RendererBase {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28();
    virtual void DrawTex(const Vec2f&, const Vec2f&, const Vec2f&, const Vec2f&, const Vec3f&, const Vec3f&, float);
    virtual void DrawGrad(const Vec2f&, const Vec2f&, const Color&, const Color&, float);
    virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void SetA(const Handle_801F7F10&);
    virtual void SetB(const Handle_801F7F10&);
};
struct Viewport { char unknown00[0x48]; Renderer* renderer; };
struct Owner { char unknown00[0x44]; HandleView collection; char unknown48[0x8]; Handle_801F7F10 texture; float time, previous; int actorIndex; unsigned short flags60; unsigned char total, step, top, bottom; char pad66[2]; Color color; };

struct Record3 { int type; unsigned long value, extra; };
struct EvItem2 { short time; short pad; int count, capacity; Record3* items; };
extern "C" {

void fn_801E2E70(Viewport*, int*, int*, int*, int*);
void fn_801C453C(Owner*, Viewport*);
void fn_801C5698(Owner*, int);
signed char fn_801C4968(Owner* self, Record* key, Event* out, signed char any);
}
template<class T> struct DynArr { int size, cap; T* data; T& operator[](int i){ return data[i]; } int GetSize() const { return size; } T& Get(int i) { return data[i]; } };
struct Key2 { short time; short pad; DynArr<Record> msgs; float GetTime() const { return 0.016666668f * (float)time; } };
struct Key3 { short time; short pad; DynArr<Record3> msgs; };
struct Anim2 { char unknown00[0x58]; DynArr<Key2> keys; char unknown64[0x10]; float length; };
struct AE { Anim2* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct AM { int count, capacity; AE* entries; inline Anim2* get(const HandleView& h){ AE* e = entries + h.index; return e->tag == h.tag ? e->object : 0; } };
extern "C" void fn_801C453C(Owner* self, Viewport* vp)
{
    int x, y, w, h;
    Renderer* r = vp->renderer;
    int top, bottom;
    fn_801E2E70(vp, &x, &y, &w, &h);
    if (fn_801F7EB8(&self->texture)) {
        r->SetA(HZero2());
        r->SetB(HCopy1(self->texture));
        float half = 0.5f;
        r->DrawTex(Vec2f(0.0f, 0.0f), Vec2f(w, h), Vec2f(0.0f, 0.0f), Vec2f(1.0f, 1.0f),
                   Vec3f(half, half, half), Vec3f(half, half, half), 1.0f);
    }
    Color col = self->color;
    Vec2f p, q;
    col.a = 1.0f;
    if (self->step < self->total) {
        float ratio = (float)self->step / (float)self->total;
        if (!(self->flags60 & 1)) ratio = 1.0f - ratio;
        top = (int)((float)self->top * ratio);
        bottom = (int)((float)self->bottom * ratio);
        self->color.a = ratio;
        self->step++;
    } else {
        if (!(self->flags60 & 1)) return;
        top = self->top;
        bottom = self->bottom;
        self->color.a = 1.0f;
    }
    r->SetB(HZero2());
    if (top) {
        p.Set(x, y); q.Set(x + w, y + top);
        r->DrawGrad(p, q, col, self->color, 1.0f);
    }
    if (bottom) {
        p.Set(x, y + h - bottom); q.Set(x + w, y + h);
        r->DrawGrad(p, q, self->color, col, 1.0f);
    }
}
extern "C" signed char fn_801C4968(Owner* self, Record* key, Event* out, signed char any)
{
    
    Anim2* c = ((AM*)lbl_801E9D24.manager)->get(self->collection);
    if (!c) return 0;
    if (c->keys.GetSize()) {
        for (int i = 0; i < c->keys.GetSize(); i++) {
            Key2& e = c->keys[i];
            float t = 0.016666668f * (float)e.time;
            if (t > self->time && t <= c->length) {
                for (int j = 0; j < e.msgs.GetSize(); j++) {
                    
                    if (key->type == e.msgs[j].type && (any || (int)key->value == (int)e.msgs[j].value)) {
                        *(Record3*)&out->rec = ((Key3*)&e)->msgs[j];
                        Event old;
                        Event* q = &old; *q = *out;
                        out->time = t;
                        self->previous = self->time;
                        self->time = t;
                        fn_801C5698(self, 1);
                        self->flags60 &= ~0xA;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
}

/* ---- Game/small_delegate_801C4B7C.cpp ---- */
namespace small_delegate_801C4B7C {
struct Record{int type;unsigned long value,extra;Record(){type=-1;extra=0;value=0;}};
extern "C"signed char fn_801C4968(void*,Record*,void*,signed char);
extern "C"signed char fn_801C4B7C(void*self,void*value){Record record;record.type=0x23;return fn_801C4968(self,&record,value,1);}

}

/* ---- Game/engine_record_output_801C4BC4.cpp ---- */
namespace engine_record_output_801C4BC4 {
typedef unsigned int u32;
struct Globals_801C4BC4 {
    char unknown[0x114];
    char*viewports;
    void*manager;
};
extern "C" Globals_801C4BC4 lbl_801E9D24;
extern "C" {
    void fn_801F86C8(void*,const void*,short);
    void fn_801E1F3C(void*,const void*);
    void fn_802139D8(void*);
}
struct Layer1_801C4BC4:Handle_801F7F10 {
    Layer1_801C4BC4() {
        word=0;
    }
    ~Layer1_801C4BC4() {
    }
};
struct Layer2_801C4BC4:Layer1_801C4BC4 {
    Layer2_801C4BC4() {
        word=0;
    }
    ~Layer2_801C4BC4() {
    }
};
struct Copy_801C4BC4:Layer2_801C4BC4 {
    Copy_801C4BC4(const Handle_801F7F10&h) {
        word=h.word;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
    }
    ~Copy_801C4BC4() {
    }
};
struct Owner_801C4BC4 {
    u32 first;
    Handle_801F7F10 identity;
    char unknown8[0x54];
    int index;
};
extern "C" void fn_801C4BC4(Owner_801C4BC4*self) {
    if(self->index>=0) {
        const Handle_801F7F10&identity=self->identity;
        Copy_801C4BC4 copy(identity);
        fn_801E1F3C(lbl_801E9D24.viewports+self->index*0x4C,&copy);
    }
    fn_802139D8(self);
}

}
namespace related_action_flag_sweep_801C4C78 {
/* ---- Game/related_action_flag_sweep_801C4C78.cpp ---- */
/* Related-action flag sweeps over an owner's records (fn_801C4C78 clears the
 * related target's 0x40000 action flag, marks the selected records and forwards
 * the self handle to the viewport; fn_801C4F7C advances the owner time and
 * clears the same flag through a retained key handle). */
struct Target { char prefix[0x38];unsigned long long flags;void clear(unsigned long long mask){flags&=~mask;} };
struct Related { char prefix[0x130];Handle_801F7F10 related; };
struct Entry { void*object;char prefix[8];signed char tag;char tail[3];int getTag()const{return tag;} };
struct Manager { int count,capacity;Entry*entries; };
struct Viewport { char storage[0x4C]; };
struct Globals { char prefix[0x114];Viewport*viewports;Manager*manager; };
extern "C" { extern Globals lbl_801E9D24;void fn_801F86C8(Manager*,const Handle_801F7F10*,int);void*fn_801F7EB8(const Handle_801F7F10*);void fn_802139D8(void*);void fn_801E1F3C(Viewport*,const Handle_801F7F10&); }
struct FlagSweepZero1_801C4C78:Handle_801F7F10 { FlagSweepZero1_801C4C78(){value=0;}~FlagSweepZero1_801C4C78(){} };
struct FlagSweepZero2_801C4C78:FlagSweepZero1_801C4C78 { FlagSweepZero2_801C4C78(){value=0;}~FlagSweepZero2_801C4C78(){} };
struct FlagSweepCopy1_801C4C78:FlagSweepZero1_801C4C78 { FlagSweepCopy1_801C4C78(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~FlagSweepCopy1_801C4C78(){} };
struct FlagSweepCopy2_801C4C78:FlagSweepZero2_801C4C78 { FlagSweepCopy2_801C4C78(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~FlagSweepCopy2_801C4C78(){} };
inline void*resolve(const Handle_801F7F10&h){int index=h.getIndex();Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.getTag()?m->entries[index].object:0;}
struct Record50 { char prefix[4];short index;char tail[0x4A]; };
struct Record1C { char prefix[0xC];signed char active;char unknown0D[0xB];Handle_801F7F10 handle; };
struct IndexRecord { int index;char tail[0x10]; };
struct Owner { char prefix[0xC];int count;char unknown10[4];Record50*records;char unknown18[0x20];Record1C*related;int selectedCount;char unknown40[4];IndexRecord*selected;char unknown48[0x2C];float time; };
struct Node { char prefix[0x20];Handle_801F7F10 related; };
struct FlagOwner { char prefix[0xC];Word flags;void set(Word mask){flags|=mask;} };
struct SelfRecord { char prefix[0x10];Handle_801F7F10 handle;char tail[8]; };
struct Self { char prefix[4];Handle_801F7F10 self;char unknown08[0x38];SelfRecord*records;Handle_801F7F10 owner;char unknown48[0xC];float current,previous;int viewport;Owner*getOwner(){return (Owner*)resolve(owner);} };
extern "C" void fn_801C5698(Self*,int);

/* Marks every selected record's related node; inlined into fn_801C4C78. */
inline void markSelected(Self*self){
 Owner*owner=self->getOwner();
 if(owner){
  fn_802139D8(self);
  for(int i=0;i<owner->selectedCount;++i)((FlagOwner*)resolve(((Node*)resolve(self->records[owner->selected[i].index].handle))->related))->set(1);
 }
}

extern "C" void fn_801C4C78(Self*self){
 int i; Owner*owner=self->getOwner();
 if(owner){
  for(i=0;i<owner->count;++i){
   if(owner->related[owner->records[i].index].active&&fn_801F7EB8(&owner->related[owner->records[i].index].handle)){
    Target*target=(Target*)resolve(((Related*)resolve(self->records[i].handle))->related);
    if(target)target->clear(0x40000ULL);
   }
  }
  markSelected(self);
  if(self->viewport>=0){const Handle_801F7F10&source=self->self;fn_801E1F3C(&lbl_801E9D24.viewports[self->viewport],FlagSweepCopy2_801C4C78(source));}
  fn_802139D8(self);
 }
}

extern "C" void fn_801C4F7C(Self*self){
 Owner*owner=self->getOwner();
 if(owner){
  self->previous=self->current;self->current=owner->time;fn_801C5698(self,1);
  for(int i=0;i<owner->count;++i){
   int relatedIndex=owner->records[i].index;
   const Record1C&related=owner->related[relatedIndex];
   const Record1C*record=&related;
   if(record->active){
    FlagSweepCopy1_801C4C78 key(self->records[i].handle);
    if(!fn_801F7EB8(&owner->related[relatedIndex].handle))continue;
    Target*target=(Target*)resolve(((Related*)resolve(key))->related);
    if(!target)continue;
    target->clear(0x40000ULL);
   }
  }
 }
}
}
namespace owner_resource_action_reset_801C5180 {
/* ---- Game/owner_resource_action_reset_801C5180.cpp ---- */

struct CollectionManager;
struct Context {char unknown00[0x110];void*logger;char*actors;CollectionManager*manager;};
extern "C" {extern Context lbl_801E9D24;extern const char lbl_802ACAD8[];void fn_801F86C8(void*,const void*,short);void*fn_801F7EB8(const void*);void fn_801FA014(void*,const char*,...);void fn_8023297C(void*,const void*,int,int);void fn_8023DE28(void*);void fn_801E2074(void*,const void*,int);void fn_80213A18(void*);}
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
 self->time=0.0f;self->slot38(0.0f);
 NodeTargetManager*manager=(NodeTargetManager*)lbl_801E9D24.manager;NodeTarget*node=manager->get(self->target);fn_8023DE28(((ActionManager*)manager)->get(node->related));
 if(self->actorIndex>=0){ActionResetCopy_801C5180 copy(self->getOwn());fn_801E2074(&((ActorSlot*)lbl_801E9D24.actors)[self->actorIndex],&copy,0);}
 fn_80213A18(self);
}
}
namespace part_801C5698 {
/* ---- part_801C5698 ---- */
/* fn_801C5698: dispatches the animation messages of an anim player for the
 * current [previous,time] window (per-node tracks, then global track).
 * Register allocation (w22, EXACT-MOD-POOL):
 * - the resolved world pointer is held in a one-member struct (WBox W) filled
 *   by an inline if/else resolver (two definitions), so it stays a frontend
 *   temporary instead of a named local; named locals never coalesce with
 *   other virtual registers, temporaries do (the higher-numbered one is merged
 *   into the lower one);
 * - wb.w is a second such temporary: a copy of the world pointer made in both
 *   arms of the parent test after the 16-register matrix copy and used by the
 *   second raycast.  It is coalesced into W.w and stays in the interference
 *   graph as a node live across the matrix copy (no code);
 * - 'wb.w = 0;' before the world lookup is a dead store that only makes wb's
 *   temporary be created before W's, so wb gets the higher vreg number and is
 *   the one merged into W (not the other way round);
 * - locals declared parent, type, owner, node, m, j, sphere (ascending vreg
 *   order sphere < j < m < node < owner < type < parent). */
struct Manager;
struct Sound;
struct Viewport;
struct Globals { char unknown00[0x114]; Viewport* viewports; Manager* manager; char unknown11C[0x3C]; Sound* sound; };
extern "C" {
extern Globals lbl_801E9D24;
void fn_801F86C8(Manager*, const void*, short);
void* fn_801F7EB8(const void*);
}
struct HZero1 : Handle_801F7F10 { HZero1() { word = 0; } ~HZero1() {} };
struct HZero2 : HZero1 { HZero2() { word = 0; } ~HZero2() {} };
struct HCopy1 : HZero1 { HCopy1(const Handle_801F7F10& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); } HCopy1(const HCopy1& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); } ~HCopy1() {} };
struct HCopy2 : HZero2 { HCopy2(const Handle_801F7F10& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); } HCopy2(const HCopy2& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); } ~HCopy2() {} };
struct Entry { void* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct Manager { int count, capacity; Entry* entries; char unknown0C[0xC8]; char* names; };
inline void* resolve(const Handle_801F7F10& h) { Entry* e = lbl_801E9D24.manager->entries + h.bits.index; return e->tag == h.bits.tag ? e->object : 0; }
template <class T> struct TEntry { T* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
template <class T> struct TManager { int count, capacity; TEntry<T>* entries; };
template <class T> struct THandle { signed int tag:8; signed int index:24; };
template <class T> inline T* get(const Handle_801F7F10& h, T* = 0) { TEntry<T>* e = ((TManager<T>*)lbl_801E9D24.manager)->entries + ((const THandle<T>&)h).index; return e->tag == ((const THandle<T>&)h).tag ? e->object : 0; }
struct TypeProbe { char unknown00[0x6C]; unsigned short type; };
inline void assign(Handle_801F7F10& dst, const Handle_801F7F10& src) { fn_801F86C8(lbl_801E9D24.manager, &dst, -1); dst.word = src.word; fn_801F86C8(lbl_801E9D24.manager, &src, 1); }

struct Vec3 { float x, y, z; Vec3() {} Vec3(float a, float b, float c) : x(a), y(b), z(c) {} Vec3(const Vec3& v) { x = v.x; y = v.y; z = v.z; } Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; } Vec3& operator+=(const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; } };
inline Vec3 operator+(const Vec3& a, const Vec3& b) { return Vec3(a.x + b.x, a.y + b.y, a.z + b.z); }
struct Vec4 : Vec3 { float w; Vec4() {} Vec4(const Vec4& v) : Vec3(v) { w = v.w; } Vec4& operator=(const Vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; } };
struct Sphere : Vec4 { int index; };
struct Matrix { float m[16]; };
struct Ray { Vec3 origin; float length; Vec3 direction; float unknown1C; Ray(const Vec3& o, const Vec3& d, float l) : origin(o), direction(d) { length = l; } Ray(const Vec3& o, const Vec3& off, const Vec3& d, float l) : origin(o + off), direction(d) { length = l; } };
struct HitObject { char unknown00[0x24]; Handle_801F7F10 owner, ground; };
struct Result { Vec3 point; char unknown0C[0x28 - 12]; Wide flags; HitObject* object; void* other; void* extra; signed char hit; char unknown3D[3]; Word end; Result() { hit = 0; object = 0; other = 0; extra = 0; flags = 0; } };

struct Msg { int type; Word value; Word extra; float time; char unknown10[0x10]; Word w20, w24; void* node; };
struct Node { char unknown00[0x1C]; Handle_801F7F10 type, owner; Word unknown24; Handle_801F7F10 ground; char unknown2C[0xF8]; Matrix* matrix; };
struct TypeObject { char unknown00[0x6C]; unsigned short type; char unknown6E[0x3E]; Sphere* sphere; char unknownB0[0xC]; unsigned short flags; };
struct Storage { Word unknown00, unknown04; };
struct NodeOwner : Storage {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34(); virtual void slot38(float); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void contact(Node*, const Vec4&, Result*, float);
    virtual void slot4C(); virtual void slot50(); virtual void slot54(); virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74(); virtual void slot78(); virtual void slot7C(); virtual void slot80();
    virtual void globalMessage(Msg*, signed char);
    virtual void nodeMessage(Msg*, signed char);
    char unknown0C[0x14]; int count, capacity; Handle_801F7F10* handles;
};
struct SoundBase { char unknown00[0x7C]; };
struct Sound : SoundBase {
    virtual void s08(); virtual void s0C(); virtual void s10(); virtual void s14(); virtual void s18(); virtual void s1C(); virtual void s20(); virtual void s24();
    virtual void s28(); virtual void s2C(); virtual void s30(); virtual void s34(); virtual void s38(); virtual void s3C(); virtual void s40(); virtual void s44();
    virtual void playNamed(const char*, int, const Handle_801F7F10*, const Handle_801F7F10&);
    virtual void stopNamed(const char*);
    virtual void s50();
    virtual void play(const Handle_801F7F10&, int, const Handle_801F7F10*, const Handle_801F7F10&);
    virtual void playAt(const Handle_801F7F10&, const Handle_801F7F10*, float);
};
struct Track { Word unknown00; short index; };
template <class T> struct Arr { int count, capacity; T* data; };
struct Track50 { Word unknown00; short index; char pad[0x4A]; };
struct Track4C { Word unknown00; short index; char pad[0x46]; };
struct Track3C { Word unknown00; short index; char pad[0x36]; };
struct Curve { int unknown00, count; void* data; int unknown0C; };
struct Anim { char unknown00[0xC]; Arr<Track50> nodes; Arr<Track4C> second; Arr<Track3C> third; char unknown30[0x24]; Curve actions; char unknown64[0x10]; float duration; };
struct Record1C { char unknown00[0x10]; Handle_801F7F10 handle; char unknown14[8]; };
struct Viewport { char unknown00[0x14]; Handle_801F7F10 selected; char unknown18[0x34]; };
struct Color { float r, g, b, a; };
struct Self { char unknown00[0x20]; int count, capacity; Handle_801F7F10* handles; char unknown2C[0x14]; Record1C* records; Handle_801F7F10 anim, world, listener, texture; float time, previous; int viewport; unsigned short flags; unsigned char total, step, top, bottom; char pad66[2]; Color color; };

extern "C" {

void fn_801C6968(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned int, unsigned int);
void fn_8028C058(Track50*, Node*, Msg*, int*, float, float, float);
short fn_801F72E4(Curve*, Msg*, int*, short, float, float, float);
Handle_801F7F10 fn_801F8114(Manager*, Word);
float fn_801F1200();
signed char fn_80269230(void*, const Ray&, Result*, Wide, Wide);
void fn_801CBDE4(NodeOwner*, Node*, void*, float);
void fn_801F1080(const Matrix*, const Matrix*, Matrix*);
Vec4 fn_80099A00(const Matrix*, const Sphere*);
void fn_801AC88C(Track4C*, const Handle_801F7F10*, float);
void fn_801AF078(Track3C*, const Handle_801F7F10*, float);
int fn_801E49B4(Anim*, const Word*);
void fn_801E2E70(Viewport*, int*, int*, int*, int*);
void fn_801C5698(Self*, signed char);
}
inline Vec3 getT(const Matrix* m) { return Vec3(m->m[12], m->m[13], m->m[14]); }
inline Vec3 getT2(const Matrix* m) { return getT(m); }
inline Vec3 getT3(const Node* n) { return getT2(n->matrix); }
inline Matrix operator*(const Matrix& a, const Matrix& b) { Matrix out; fn_801F1080(&a, &b, &out); return out; }

struct WBox { void* w; };
inline void resolveTo(void*& out, const Handle_801F7F10& h) { Entry* e = lbl_801E9D24.manager->entries + h.bits.index; if (e->tag == h.bits.tag) out = e->object; else out = 0; }
extern "C" void fn_801C5698(Self* self, signed char silent)
{
    WBox wb; Anim* anim; WBox W; NodeOwner* listener; int i; int index; NodeOwner* parent; TypeObject* type; NodeOwner* owner; Node* node; Msg* m; int j; Sphere* sphere;
    { TEntry<Anim>* e = ((TManager<Anim>*)lbl_801E9D24.manager)->entries + ((const THandle<Anim>&)self->anim).index; if (e->tag == ((const THandle<Anim>&)self->anim).tag) anim = e->object; else anim = 0; }
    wb.w = 0;
    resolveTo(W.w, self->world);
    listener = (NodeOwner*)resolve(self->listener);
    Result hit;
    for (i = 0; i < anim->nodes.count; i++) {
        index = anim->nodes.data[i].index;
        node = (Node*)resolve(self->records[index].handle);
        Msg msgs[64];
        __construct_array(msgs, fn_801C6968, 0, sizeof(Msg), 64);
        int n = 0;
        fn_8028C058(&anim->nodes.data[i], node, msgs, &n, self->previous, self->time, anim->duration);
        m = msgs;
        type = 0;
        owner = 0;
        parent = 0;
        if (fn_801F7EB8(&node->type)) {
            if (get<TypeProbe>(node->type)->type == 5) {
                type = (TypeObject*)resolve(node->type);
                owner = (NodeOwner*)resolve(node->owner);
                if (type->flags & 0x80) parent = (NodeOwner*)resolve(owner->handles[0]);
            }
        }
        for (j = 0; j < n; j++, m++) {
            m->node = node;
            m->w20 = 0;
            m->w24 = 0;
            if (m->type == 0xE) {
                if (!silent) {
                    HCopy1 h(fn_801F8114(lbl_801E9D24.manager, m->value));
                    lbl_801E9D24.sound->play(h, 0xF, &self->records[index].handle, HZero2());
                }
            } else if (m->type == 0x10) {
                if (fn_801F1200() < 0.5f) {
                    if (!silent) {
                        HCopy1 h(fn_801F8114(lbl_801E9D24.manager, m->value));
                        lbl_801E9D24.sound->play(h, 0xF, &self->records[index].handle, HZero2());
                    }
                }
            } else if (m->type == 0x11) {
                if (!silent) lbl_801E9D24.sound->playNamed(lbl_801E9D24.manager->names + m->value * 0x81, 0, &self->records[index].handle, HZero2());
            } else if (m->type == 0x12) {
                if (!silent) lbl_801E9D24.sound->playNamed(lbl_801E9D24.manager->names + m->value * 0x81, 2, &self->records[index].handle, HZero2());
            } else if (m->type == 0xF) {
                HCopy1 h((HCopy1(fn_801F8114(lbl_801E9D24.manager, m->value))));
                lbl_801E9D24.sound->playAt(h, &self->records[index].handle, -1.0f);
            } else if (m->type == 0x13) {
                lbl_801E9D24.sound->stopNamed(lbl_801E9D24.manager->names + m->value * 0x81);
            } else {
                listener->nodeMessage(m, silent);
            }
        }
        if (type) {
            
            if (fn_80269230(W.w, Ray(getT3(node), Vec3(0.0f, 0.5f, 0.0f), Vec3(0.0f, -1.0f, 0.0f), 30.0f), &hit, 0x0000860000000002ULL, 0x0000000400000008ULL)) {
                if (owner) {
                    if (resolve(hit.object->owner)) fn_801CBDE4(owner, node, hit.object, 0.0f);
                    sphere = type->sphere;
                    if (sphere) {
                        Vec4 v = *sphere;
                        Matrix mtx = *node->matrix;
                        if (parent) { mtx = *node->matrix * *((Node*)resolve(parent->handles[sphere->index]))->matrix; wb.w = W.w; } else wb.w = W.w;
                        v = fn_80099A00(&mtx, sphere);
                        v += Vec3(0.0f, 0.05f, 0.0f);
                        if (fn_80269230(wb.w, Ray(v, Vec3(0.0f, -1.0f, 0.0f), 30.0f), &hit, 0x0000860000000002ULL, 0x0000000400000008ULL)) {
                            owner->contact(node, v, &hit, v.w);
                        }
                    }
                }
                assign(node->ground, hit.object->ground);
            }
        }
    }
    for (i = 0; i < self->count; i++) ((NodeOwner*)resolve(self->handles[i]))->slot38(self->time - self->previous);
    for (i = 0; i < anim->second.count; i++) {
        Node* node = (Node*)resolve(self->records[anim->second.data[i].index].handle);
        const Handle_801F7F10& src = node->type;
        HCopy2 h((HCopy2(src)));
        fn_801AC88C(&anim->second.data[i], &h, self->time);
    }
    for (i = 0; i < anim->third.count; i++) {
        Node* node = (Node*)resolve(self->records[anim->third.data[i].index].handle);
        const Handle_801F7F10& src = node->type;
        HCopy2 h((HCopy2(src)));
        fn_801AF078(&anim->third.data[i], &h, self->time);
    }
    if (anim->actions.count) {
        Msg msgs[64];
        __construct_array(msgs, fn_801C6968, 0, sizeof(Msg), 64);
        int n = 0;
        fn_801F72E4(&anim->actions, msgs, &n, 0, self->previous, self->time, anim->duration);
        HCopy1 none = HZero2();
        Viewport* vp; Msg* m = msgs;
        vp = &lbl_801E9D24.viewports[self->viewport];
        for (int j = 0; j < n; j++, m++) {
            m->node = 0;
            m->w24 = 0;
            m->w20 = 0;
            if (m->type == 0xE) {
                if (!silent) {
                    HCopy1 h(fn_801F8114(lbl_801E9D24.manager, m->value));
                    lbl_801E9D24.sound->play(h, 0xF, &none, HZero2());
                }
            } else if (m->type == 0x10 && !silent) {
                if (fn_801F1200() < 0.5f) {
                    if (!silent) {
                        HCopy1 h(fn_801F8114(lbl_801E9D24.manager, m->value));
                        lbl_801E9D24.sound->play(h, 0xF, &none, HZero2());
                    }
                }
            } else if (m->type == 0x11) {
                if (!silent) lbl_801E9D24.sound->playNamed(lbl_801E9D24.manager->names + m->value * 0x81, 0, &none, HZero2());
            } else if (m->type == 0x12 && !silent) {
                if (!silent) lbl_801E9D24.sound->playNamed(lbl_801E9D24.manager->names + m->value * 0x81, 2, &none, HZero2());
            } else if (m->type == 0x21) {
                assign(self->texture, HCopy1(fn_801F8114(lbl_801E9D24.manager, m->value)));
            } else if (m->type == 0x22) {
                assign(self->texture, HZero2());
            } else if (m->type == 0x20) {
                int k = fn_801E49B4(anim, &m->extra);
                if (!(self->flags & 0x20)) assign(vp->selected, self->records[k].handle);
            } else if (m->type == 0x13) {
                lbl_801E9D24.sound->stopNamed(lbl_801E9D24.manager->names + m->value * 0x81);
            } else if (m->type == 0x26) {
                self->color.r = (float)(int)((m->value >> 16) & 0xFF) / 255.0f;
                self->color.g = (float)(int)((m->value >> 8) & 0xFF) / 255.0f;
                self->color.b = (float)(int)(m->value & 0xFF) / 255.0f;
            } else if (m->type == 0x24) {
                int x, y, w, h;
                fn_801E2E70(vp, &x, &y, &w, &h);
                self->total = (m->value >> 16) & 0xFF;
                self->step = 0;
                self->top = h * (int)((m->value >> 8) & 0xFF) / 100;
                self->bottom = h * (int)(m->value & 0xFF) / 100;
                self->flags |= 1;
            } else if (m->type == 0x25) {
                self->total = m->value;
                self->step = 0;
                self->flags &= ~1;
            } else {
                listener->globalMessage(m, silent);
            }
        }
    }
}
}

/* fn_801C5698 is held back by mwcc until the next declaration; flush it before fn_801C6968. */
struct Flush801C5698;
/* ---- Game/scalar_middle_801C6968.c ---- */
extern "C" void fn_801C6968(unsigned int *object) {object[2]=0;object[0]=~0U;object[1]=0;}
/* ---- Game/timed_record_update_801C6980.cpp ---- */
namespace timed_record_update_801C6980 {
struct Handle { signed int tag:8; signed int index:24; };
struct Target;
struct Entry { Target*object;char unknown04[8];signed char tag;char unknown0D[3]; };
struct Manager { char unknown00[8];Entry*entries; };
struct Context { char unknown00[0x118];Manager*manager;char unknown11C[8];void*scene; };
extern "C" Context lbl_801E9D24;
struct Curve { int unknown00,count;void*data;int unknown0C; };
struct Resource { char unknown00[0x54];Curve actions;char unknown64[0x10];float duration; };
struct Work { int type,value,unknown08;float time;char unknown10[0x1C]; };
struct Owner { char unknown00[0x20];int handleCount,handleCapacity;Handle*handles;char unknown2C[0x18];Handle resource;Word unknown48;Handle event;Word unknown50;float current,previous;Word unknown5C;unsigned short flags;char unknown62[0x18];unsigned short repeatCount;float marker; };
extern "C" { void fn_801C6968(void*);void __construct_array(void*,void(*)(void*),void(*)(void*),unsigned int,unsigned int);short fn_801F72E4(Curve*,Work*,int*,short,float,float,float);void fn_801C5698(Owner*,int);void fn_802322B8(Target*,float);void fn_802073E8(Owner*,int,Target*,float);void fn_802603E8(void*,float); }
static inline Target*resolve(const Handle&handle){Entry*entry=&lbl_801E9D24.manager->entries[handle.index];return entry->tag==handle.tag?entry->object:0;}
static inline Word resolveWord(const Handle&handle){Entry*entry=&lbl_801E9D24.manager->entries[handle.index];return entry->tag==handle.tag?(Word)entry->object:0;}
typedef char HandleSize[(sizeof(Handle)==4)?1:-1];
typedef char WorkSize[(sizeof(Work)==44)?1:-1];
extern "C" void fn_801C6980(Owner*self,float delta){
 if(delta<0.000001f)return;
 Resource*resource=(Resource*)resolve(self->resource);
 self->previous=self->current;
 self->current+=delta;
 if(resource->actions.count && !(self->flags&8)){
  signed char repeat;
  do{
   Work records[64];__construct_array(records,fn_801C6968,0,sizeof(Work),64);
   int count=0;Work*record=records;repeat=0;
   float end=self->current;if(end>resource->duration)end=resource->duration;
   fn_801F72E4(&resource->actions,records,&count,0,self->previous,end,resource->duration);
   for(int i=0;i<count;++i,++record){
    if(record->type==12 && !(self->flags&2)){
     repeat=1;self->marker=record->time;self->flags|=2;self->flags&=~4;
    }else if(record->type==13){
     if(self->flags&4){
      if(self->repeatCount-- && !self->repeatCount)self->flags&=~6;
     }else{
      self->repeatCount=(unsigned short)record->value;self->flags|=4;
     }
     if(self->flags&4){
      float carry=self->current-record->time;self->current=record->time;
      fn_801C5698(self,0);self->previous=self->marker;
      int offset;int j=0;offset=0;for(;j<self->handleCount;++j){fn_802322B8(resolve(*(Handle*)((char*)self->handles+offset)),self->previous);offset+=4;}
      repeat=1;self->current=self->previous+carry;
     }
    }
   }
  }while(repeat);
 }
 signed char ended;
 if(self->current>resource->duration){self->current=resource->duration;ended=1;}else ended=0;
 fn_801C5698(self,0);
 if(ended){fn_802073E8(self,0x1F,(Target*)resolveWord(self->event),-1612.0f);fn_802603E8(lbl_801E9D24.scene,0.0f);}
}
}
/* ---- Game/engine_record_output_801C6C94.cpp ---- */
namespace engine_record_output_801C6C94 {
typedef unsigned int u32;
struct Entry_801C6C94 {
    void*object;
    u32 unknown[2];
    signed char generation;
    char padD[3];
    signed char getGeneration()const {
        return generation;
    }
};
struct Manager_801C6C94 {
    int count,capacity;
    Entry_801C6C94*entries;
};
struct Globals_801C6C94 {
    char unknown[0x118];
    Manager_801C6C94*manager;
};
extern "C" Globals_801C6C94 lbl_801E9D24;
struct Handle_801C6C94 {
    signed int generation:8;
    signed int index:24;
    template<class T>T*get()const {
        int i=index;
        Manager_801C6C94*m=lbl_801E9D24.manager;
        int gen=m->entries[i].getGeneration();
        return gen==generation?(T*)m->entries[i].object:0;
    }
};
struct IndexRecord_801C6C94 {
    int index;
    char unknown[0x10];
};
struct Resource_801C6C94 {
    char unknown[0x3C];
    int count,capacity;
    IndexRecord_801C6C94*records;
};
struct Target_801C6C94 {
    char unknown[0xC];
    u32 flags;
};
struct Node_801C6C94 {
    char unknown[0x20];
    Handle_801C6C94 related;
};
struct Record_801C6C94 {
    char unknown[0x10];
    Handle_801C6C94 handle;
    char unknown14[8];
};
struct Owner_801C6C94 {
    char unknown[0x40];
    Record_801C6C94*records;
    Handle_801C6C94 resource;
};
extern "C" void fn_802139D8(Owner_801C6C94*);
extern "C" void fn_801C6C94(Owner_801C6C94*self) {
    Resource_801C6C94*resource=self->resource.get<Resource_801C6C94>();
    if(resource) {
        fn_802139D8(self);
        for(int i=0; i<resource->count; ++i)self->records[resource->records[i].index].handle.get<Node_801C6C94>()->related.get<Target_801C6C94>()->flags|=1;
    }
}
}
/* ---- Game/anim_owner_collection_bind_801C6DE0.cpp ---- */
namespace anim_owner_collection_bind_801C6DE0 {
/* fn_801C6DE0: bind an animation owner to its collection/target/flags handles
 * and, on first use, copy the collection's records into the owner, attach each
 * record's node (named child lookup through the target for unlinked records),
 * relink selected nodes, create the per-index and per-retained "PlayAnim"
 * handle/pair entries, clear the state bytes and finish with the inlined
 * reset (fn_801C6C94 body).
 * Native Handle_801F7F10 ctor/dtor stay external; Zero1/Ref/Child are the
 * zero-initialising inline layers (their weak dtors are discarded at link).
 * Register allocation depends on the resolver shapes: if/return (resolve),
 * conditional-expression (resolveOr) and member-template (resolveMember)
 * variants are used at the original call sites, and the first records.add
 * argument goes through Array::operator[].
 * Flags: GC/1.3.2 -O4,p -Cpp_exceptions off -use_lmw_stmw on (C++, no extab). */
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Context{char unknown00[0x118];Manager*manager;};
extern "C"{
extern Context lbl_801E9D24;
extern char lbl_8028F698[];
extern const char lbl_8037A404[4];
extern const char lbl_802ACAEC[];

void fn_801F86C8(Manager*,const void*,int);
void*fn_801F7EB8(const Handle_801F7F10*);
Word fn_801F948C(void*,const char*);
void fn_8028FD50(void*,void*,int);
void*fn_8028FAF4(void*,void*,int,int);
void*fn_8028FF24(void*,int);
Handle_801F7F10 fn_801B52EC(Manager*,const char*);
}
}
template<class T>inline T*Handle_801F7F10::get()const{int index=bits.index;anim_owner_collection_bind_801C6DE0::Manager*m=anim_owner_collection_bind_801C6DE0::lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==bits.tag)return (T*)m->entries[index].object;return 0;}
namespace anim_owner_collection_bind_801C6DE0 {
template<class T>inline T*resolveMember(const Handle_801F7F10&h){return h.get<T>();}
template<class T>inline T*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return (T*)m->entries[index].object;return 0;}
template<class T>inline T*resolveOr(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?(T*)m->entries[index].object:0;}
struct Zero1:Handle_801F7F10{Zero1(){word=0;}~Zero1(){}};
struct Ref:Zero1{
 Ref(){word=0;}
 Ref(const Ref&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 Ref(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 ~Ref(){}
 Ref&operator=(const Ref&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
struct Child:Ref{
 Child(){word=0;}
 Child(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 ~Child(){}
 Child&operator=(const Child&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
struct Param:Handle_801F7F10{
 Param&operator=(const Param&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
struct Name{Word word;Name(const char*text){word=fn_801F948C(this,text);}bool operator!=(const Name&o)const{return word!=o.word;}bool operator==(const Name&o)const{return word==o.word;}};
template<class T>struct Array{
 int count,capacity;T*data;
 void resize(int n){if(n){if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}
 T&operator[](int i){return data[i];}
 void grow(){if(count+1>capacity){resize(capacity+16);capacity+=16;}}
 void add(const T&v){grow();new(data+count++)T(v);}
 void add(){grow();new(data+count++)T();}
};
struct Record{Name name;Name key;int link;signed char active;Ref object;Ref h14;Ref retained;};
struct IndexRecord{int index;Word unknown04;Ref h8;Ref hc;Ref h10;};
struct Selected{Word unknown00;short index;char unknown06[0x46];};
struct Collection{char unknown00[0x18];Array<Selected>selected;char unknown24[0xC];Array<Record>records;Array<IndexRecord>indices;};
struct Named{Name name;};
struct Linker{char unknown00[0x130];Ref h130;void setH130(const Handle_801F7F10&p){h130=p;}};
struct NodePrefix{char unknown00[8];};
struct Node:NodePrefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30(Ref&,const Ref&);
 char unknown0C[0x10];Ref h1c;Ref h20;
};
struct Target{char unknown00[0x30];Ref h30;};
struct Flagged{char unknown00[0xC];Word flags;};
struct Linked{char unknown00[0x20];Ref related;};
struct OwnerPrefix{char unknown00[0x20];};
struct Owner:OwnerPrefix{
 Array<Child>handles;Array<Ref>pairs;Array<Record>records;Param collection,target,flags;Word unknown50;float time;Word unknown58;int actorIndex;unsigned short flags60;signed char b62,b63,b64,b65;
 void reset();
};
extern "C"{
void fn_802139D8(Owner*);
Ref*fn_80240F28(Node*);
void fn_8023E994(Node*,Ref*,int);
void fn_802408BC(Node*,Ref,int);
Ref fn_8026A494(Target*,const Name&);
void fn_80269FE0(Target*);
void fn_8023D648(Node*);
void fn_8023E1B4(Node*);
void fn_8023232C(Node*,const Ref*);
void fn_8023297C(Node*,const Ref*,int,int);
}
inline void Owner::reset(){
 Collection*resource=resolveOr<Collection>(collection);
 if(resource){
  fn_802139D8(this);
  for(int i=0;i<resource->indices.count;++i)resolve<Flagged>(resolve<Linked>(records.data[resource->indices.data[i].index].object)->related)->flags|=1;
 }
}
extern "C" void fn_801C6DE0(Owner*self,const Param&target,const Param&collection,const Param&flags,int actorIndex){
 self->collection=collection;
 self->actorIndex=actorIndex;
 self->target=target;
 self->flags=flags;
 self->time=0.0f;
 Collection*col=resolve<Collection>(self->collection);
 Target*tgt=resolve<Target>(self->target);
 if(self->records.count==0){
  int i;
  for(i=0;i<col->records.count;i++){
   self->records.add(col->records[i]);
   if(col->records.data[i].active){
    Ref unused(*fn_80240F28(resolve<Node>(col->records.data[i].object)));
   }else{
    Ref obj(col->records.data[i].object);
    fn_8023E994(resolve<Node>(obj),&self->records.data[i].object,0);
    Linker*l=resolveOr<Linker>(self->records.data[i].object);
    l->setH130(flags);
   }
  }
  for(i=0;i<self->records.count;i++){
   if(!self->records.data[i].active){
    if(!fn_801F7EB8(&self->records.data[i].h14)){
     int link=self->records.data[i].link;
     if(link<0){
      const Ref&h30=tgt->h30;
      Ref t(h30);
      if(self->records.data[i].name!=Name(lbl_8037A404))t=fn_8026A494(tgt,self->records.data[i].name);
      fn_802408BC(resolve<Node>(t),self->records.data[i].object,0);
     }else{
      fn_802408BC(resolve<Node>(self->records.data[link].object),self->records.data[i].object,0);
     }
    }else{
     fn_802408BC(resolve<Node>(self->records.data[i].h14),self->records.data[i].object,0);
    }
   }
  }
  for(i=0;i<col->selected.count;i++){
   Node*a=resolve<Node>(self->records.data[col->selected.data[i].index].object);
   Linker*b=resolveMember<Linker>(a->h1c);
   for(int j=0;j<self->records.count;j++){
    if(resolve<Named>(b->h130)->name==self->records.data[j].key){
     b->h130=self->records.data[j].object;
     break;
    }
   }
  }
  fn_80269FE0(tgt);
  for(i=0;i<col->indices.count;i++){
   Node*a=resolve<Node>(self->records.data[col->indices.data[i].index].object);
   a->h1c=col->indices.data[i].hc;
   fn_8023D648(a);
   Ref t;
   if(fn_801F7EB8(&col->indices.data[i].h10))resolve<Node>(col->indices.data[i].h10)->slot30(t,a->h1c);
   a->h20=t;
   fn_8023D648(a);
   fn_8023E1B4(a);
   a->slot14();
   if(!fn_801F7EB8(&col->indices.data[i].h8))continue;
   self->handles.add();
   int k=self->handles.count-1;
   self->handles[k]=fn_801B52EC(lbl_801E9D24.manager,lbl_802ACAEC);
   self->pairs.add(col->indices.data[i].h8);
   fn_8023232C(resolve<Node>(self->handles.data[k]),&self->records.data[col->indices.data[i].index].object);
   fn_8023297C(resolve<Node>(self->handles.data[k]),&self->pairs.data[k],0,1);
  }
  for(i=0;i<col->records.count;i++){
   if(fn_801F7EB8(&col->records.data[i].retained)){
    Ref t(col->records.data[i].object);
    self->handles.add();
    int k=self->handles.count-1;
    self->handles[k]=fn_801B52EC(lbl_801E9D24.manager,lbl_802ACAEC);
    Node*o=resolveMember<Node>(self->handles.data[k]);
    self->pairs.add(col->records.data[i].retained);
    fn_8023232C(o,&t);
    fn_8023297C(o,&self->pairs.data[k],0,1);
   }
  }
  self->b62=0;self->b63=0;self->b64=0;self->b65=0;
  self->reset();
 }
}
}
/* .sdata2 0x8037A404: "" (named; after the pooled literals 0x8037A3C8-0x8037A404). */
extern "C" { __declspec(section ".sdata2") extern const char lbl_8037A404[4] __attribute__((aligned(4))) = ""; }
