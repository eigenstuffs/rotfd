/* Registry destructor reconstructed from GSQE78.
 * See docs/notes/game-registry-lookup.md. */
typedef unsigned long u32;
#include "Game/registry_abi_tables.h"
extern "C" {extern char lbl_8028F698[],lbl_801EF5C8[];void fn_8028FD50(void*,void*,u32);void fn_801EF610(void*,void*);void fn_80287BEC(void*);void fn_801F551C(void*,short);void fn_801F56A8(void*,short);}
template<class T>struct Array {
 int size,capacity;T*data;
 void releaseStorage(){if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}
 ~Array(){if(data){for(int i=0;i<size;++i)data[i].~T();releaseStorage();data=0;}}
};
struct RegistryPrefix {char unknown[0x7c];};
struct Registry:RegistryPrefix {
 virtual void cleanup();
 Array<u32>first;Array<int>firstIndex;Array<u32>second;Array<int>secondIndex;
 char handleArrays[0x24];
};
extern "C" Registry*fn_801F5944(Registry*r,short flag){
 if(r){
  *(const void**)((char*)r+0x7c)=&lbl_802EAA80;
  r->cleanup();
  fn_80287BEC(r);
  fn_801F551C(r->handleArrays,-1);
  r->secondIndex.~Array<int>();
  r->second.~Array<u32>();
  r->firstIndex.~Array<int>();
  r->first.~Array<u32>();
  fn_801F56A8(r,0);
  if(flag>0)fn_801EF610(lbl_801EF5C8,r);
 }
 return r;
}
