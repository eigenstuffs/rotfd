#include "Game/handle_list_operations_internal.h"
extern "C" {void fn_801F86C8(void*,const void*,int);void* __ct__15Handle_801F7F10Fv(void*);}
struct LookupValue : Handle {
 LookupValue(){__ct__15Handle_801F7F10Fv(this);value=0;value=0;}
 LookupValue(const LookupValue&other){__ct__15Handle_801F7F10Fv(this);value=0;value=other.value;fn_801F86C8(lbl_801E9D24.manager,&other,1);}
};
struct LookupRecord {unsigned long key;LookupValue handle;};
struct LookupView {char unknown00[12];Array handles;};
extern "C" LookupValue fn_8026420C(LookupView*self,const unsigned long*target) {
 LookupValue*result;
 for(int i=0;i<self->handles.count;++i){
  LookupRecord*record=(LookupRecord*)fn_801F7EB8(&self->handles[i]);
  unsigned long key=record->key;unsigned long other=*target;
  if(key==other){result=&record->handle;return *result;}
 }
 return LookupValue();
}
