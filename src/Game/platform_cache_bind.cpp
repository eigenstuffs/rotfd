#include "Game/platform_cache_internal.h"
struct CacheMapping {unsigned short index,unknown2;};
template<int Offset> struct CacheMappingView {char unknown[Offset];CacheMapping*entries;};
extern "C" void fn_801F7914(Handle_801F7F10*,const Handle_801F7F10*);
template<int Offset> inline void clearMapping(CacheNode&node){
 unsigned short id=node.index;
 if(id!=0xffff){
  Activable_Z*object=((OwnerHandle&)node.handle).get();
  if(object)((CacheMappingView<Offset>*)object)->entries[id].index=0xffff;
 }
}
unsigned short Cache900_802F149C::bind(const Handle_801F7F10&handle,unsigned short id){
 unsigned short n=at(count-1).prev-1;
 CacheNode&node=at(n+1);
 clearMapping<0x104>(node);
 node.index=id;
 fn_801F7914(&node.handle,&handle);
 return n;
}
unsigned short Cache10_802F1490::bind(const Handle_801F7F10&handle,unsigned short id){
 unsigned short n=at(count-1).prev-1;
 CacheNode&node=at(n+1);
 clearMapping<0x38>(node);
 node.index=id;
 fn_801F7914(&node.handle,&handle);
 return n;
}
