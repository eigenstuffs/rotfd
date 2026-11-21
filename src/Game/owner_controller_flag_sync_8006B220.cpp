/* Bounded native views for owner/controller flag synchronization.
 * The flag predicate and resolver are ordinary inline members/helpers.
 * fn_801F7EB8 returns a borrowed opaque resource pointer, tested for null only.
 * This entry changes no Handle reference counts or object lifetimes. */
struct SyncOwner;
struct SyncHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct SyncEntry{SyncOwner*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct SyncManager{int count,capacity;SyncEntry*entries;};
struct SyncContext{char unknown00[0x118];SyncManager*manager;};
extern "C" SyncContext lbl_801E9D24;
struct SyncOwner{char unknown00[0x30];unsigned long long actorFlags;unsigned long long flags;char unknown40[0x30];SyncHandle controller;char unknown74[0xAC];unsigned long stateFlags;char unknown124[0xC];SyncHandle target;signed char blocked()const{if(flags&0x2000000ULL)return 1;return 0;}};
inline SyncOwner*resolveSync(const SyncHandle&h){SyncEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
struct SyncResolvedResource;
extern "C" SyncResolvedResource*fn_801F7EB8(const SyncHandle*);

extern "C" signed char fn_8006B220(void*self,SyncOwner*other,signed char state){
if(!state){
other->stateFlags&=~0x40000UL;
if(fn_801F7EB8(&other->target)){
SyncOwner*owner=resolveSync(other->target);
if(owner->flags&0x200000000000ULL){const SyncHandle&controller=owner->controller;if(fn_801F7EB8(&controller))resolveSync(controller)->actorFlags&=~0x200ULL;}
}
}else{
other->stateFlags|=0x40000UL;
if(fn_801F7EB8(&other->target)){
SyncOwner*owner=resolveSync(other->target);
if(!owner->blocked() && (owner->flags&0x200000000000ULL)){const SyncHandle&controller=owner->controller;if(fn_801F7EB8(&controller))resolveSync(controller)->actorFlags|=0x200ULL;}
}
}
return 1;
}
