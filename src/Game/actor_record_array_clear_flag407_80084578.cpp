#include "Game/early_actor_array_copy_views.h"
struct ArrayIndex{int value;ArrayIndex(int v):value(v){}operator const int&()const{return value;}};
struct Entry_80084578{ArrayResource*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct Entries_80084578{Entry_80084578*p;Entry_80084578&operator[](int i)const{return p[i];}};
struct Manager_80084578{int count,capacity;Entries_80084578 entries;};
struct Context_80084578{char unknown00[0x118];Manager_80084578*manager;};
inline ArrayResource*resolve_80084578(const Handle_801F7F10&h){Manager_80084578*m=reinterpret_cast<Context_80084578*>(&lbl_801E9D24)->manager;ArrayIndex index(h.bits.index);signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
inline const Handle_801F7F10&recordHandle_80084578(const Array_80025634&a,int i){return a.data[i].handle;}
extern "C" void fn_80084578(ArrayOwner*self){self->actor->enabled407=0;Array_80025634 copy(resolve_80084578(self->actor->handle)->array);for(short i=0;i<copy.count;++i)resolve_80084578(recordHandle_80084578(copy,i))->flags&=~0x40000UL;if(lbl_803776B8&&lbl_803776B8->second)fn_80068158(lbl_803776B8,self->actor->record.key);}
