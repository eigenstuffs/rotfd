/* Related-action flag sweeps over an owner's records (fn_801C4C78 clears the
 * related target's 0x40000 action flag, marks the selected records and forwards
 * the self handle to the viewport; fn_801C4F7C advances the owner time and
 * clears the same flag through a retained key handle). */
typedef unsigned long Word;
struct Handle_801F7F10 { union { Word value; struct { signed int tag:8,index:24; } bits; }; Handle_801F7F10();~Handle_801F7F10();int getIndex()const{return bits.index;}int getTag()const{return bits.tag;} };
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
