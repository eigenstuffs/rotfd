#include "Game/early_actor_array_copy_views.h"
struct ArrayIndex{int value;ArrayIndex(int v):value(v){}operator const int&()const{return value;}};
struct Entry_800842B0{ArrayResource*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct Entries_800842B0{Entry_800842B0*p;Entry_800842B0&operator[](int i)const{return p[i];}};
struct Manager_800842B0{int count,capacity;Entries_800842B0 entries;};
struct Context_800842B0{char unknown00[0x118];Manager_800842B0*manager;};
inline ArrayResource*resolve_800842B0(const Handle_801F7F10&h){Manager_800842B0*m=reinterpret_cast<Context_800842B0*>(&lbl_801E9D24)->manager;ArrayIndex index(h.bits.index);signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
inline const Handle_801F7F10&recordHandle_800842B0(const Array_80025634&a,int i){return a.data[i].handle;}
extern "C" void fn_800842B0(ArrayOwner*self){Array_80025634 copy(resolve_800842B0(self->actor->handle)->array);for(short i=0;i<copy.count;++i)resolve_800842B0(recordHandle_800842B0(copy,i))->flags&=~0x40000UL;self->actor->enabled406=0;if(lbl_803776B8&&lbl_803776B8->second)fn_80068158(lbl_803776B8,self->actor->record.key);}
