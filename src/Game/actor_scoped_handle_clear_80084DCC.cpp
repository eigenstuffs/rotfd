// Bounded actor resource reset. Both generation resolvers use the same
// native manager and entry type; the immutable index controls ordinary access.
struct ScopedIndex{int value;ScopedIndex(int v):value(v){}operator const int&()const{return value;}};
struct Handle_801F7F10{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ScopedComponent{char unknown00[0xC];float value;};
struct ScopedResource{char unknown00[0x70];Handle_801F7F10 handle;ScopedComponent*first,*second;};
struct ScopedEntry{ScopedResource*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct ScopedEntryArray{ScopedEntry*p;ScopedEntry&operator[](int i)const{return p[i];}};struct ScopedManager{int count,capacity;ScopedEntryArray entries;};struct ScopedContext{char unknown00[0x118];ScopedManager*manager;};extern "C" ScopedContext lbl_801E9D24;
inline ScopedResource*resolveScoped(const Handle_801F7F10&h){ScopedManager*m=lbl_801E9D24.manager;ScopedIndex index(h.bits.index);signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
struct ScopedRecord{char unknown00[8];int key;};
struct ScopedActor{char unknown00[0x168];Handle_801F7F10 resource;char unknown16C[0x1AC];ScopedRecord record;char unknown324[0xE8];signed char enabled40C;};
struct ScopedOwner{char unknown00[8];ScopedActor*actor;void*controller;char unknown10[0x34];float first,second;};
struct ScopedMonitor{char unknown00[0x130];void*first,*second;};
extern "C" {extern ScopedMonitor*lbl_803776B8;void fn_80224038(ScopedActor*,const Handle_801F7F10*);void fn_80068158(ScopedMonitor*,int);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];}
struct Handle_80021C40:Handle_801F7F10{Handle_80021C40(){value=0;}~Handle_80021C40(){};static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021BCC:Handle_80021C40{Handle_80021BCC(){value=0;}~Handle_80021BCC(){};static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021B54:Handle_80021BCC{Handle_80021B54(){value=0;}~Handle_80021B54(){};static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
inline ScopedResource*resolveScopedFirst(const Handle_801F7F10&h){ScopedEntry*e=lbl_801E9D24.manager->entries.p+h.bits.index;if(e->tag==h.bits.tag)return e->object;return 0;}

extern "C" void fn_80084DCC(ScopedOwner*self){{Handle_80021B54 empty;fn_80224038(self->actor,&empty);}ScopedComponent*second=resolveScoped(self->actor->resource)->second;if(second)second->value=self->second;ScopedComponent*first=resolveScopedFirst(self->actor->resource)->first;if(first)first->value=self->first;if(lbl_803776B8&&lbl_803776B8->second)fn_80068158(lbl_803776B8,self->actor->record.key);}
