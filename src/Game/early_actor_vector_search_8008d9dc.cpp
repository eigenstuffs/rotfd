struct SearchHandle{signed int tag:8;signed int index:24;};
struct SearchVector{float x,y,z;SearchVector&operator=(const SearchVector&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct SearchObject{char unknown00[0x1C];SearchVector point;char unknown28[8];int count,capacity;SearchHandle*items;char unknown3C[0x1B4];SearchHandle related;};
struct SearchEntry{SearchObject*object;char unknown04[8];signed char tag;char unknown0D[3];};struct SearchManager{int count,capacity;SearchEntry*entries;};
struct SearchContext{char unknown00[0x118];SearchManager*manager;};
struct SearchControl{char unknown00[0x64];SearchHandle handle;};
struct SearchOwner{char unknown00[0xC];SearchControl*control;char unknown10[0x3C];SearchVector point;};
extern "C"{extern SearchContext lbl_801E9D24;void*fn_801F7EB8(const SearchHandle*);}
inline SearchObject*resolve(const SearchHandle&h){SearchEntry*e=&lbl_801E9D24.manager->entries[h.index];if(e->tag==h.tag)return e->object;return 0;}
struct SearchSecondEntry{SearchObject*object;char unknown04[8];signed char tag;char unknown0D[3];};struct SearchSecondManager{int count,capacity;SearchSecondEntry*entries;};
inline SearchObject*resolveSecond(const SearchHandle&h){SearchSecondEntry*e=&((SearchSecondManager*)lbl_801E9D24.manager)->entries[h.index];if(e->tag==h.tag)return e->object;return 0;}
extern "C"void fn_8008D9DC(SearchOwner*self){
 SearchObject*group=resolveSecond(resolve(self->control->handle)->related);
 for(int i=0;i<group->count;++i){
  if(fn_801F7EB8(&group->items[i])){self->point=resolve(group->items[i])->point;break;}
 }
}
