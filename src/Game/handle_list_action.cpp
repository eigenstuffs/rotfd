#include "Game/handle_list_operations_internal.h"
struct Handle_801F7F10:Handle {Handle_801F7F10();~Handle_801F7F10();};
struct ListActionHandle:Handle_801F7F10 {};
extern "C" {void fn_801F86C8(Manager*,Handle*,short);void fn_801EDAAC(Object*,float,float,float);extern const float lbl_8037B640,lbl_8037B644;}
static inline Handle*findHandle(View*self,const Handle&target){for(int i=0;i<self->handles.count;++i){Object*object=resolved(self->handles[i]);if(equal(object->related,target))return &self->handles[i];}return self->handles.data;}
extern "C" signed char fn_80268194(View*self,const Handle&target){
 Handle*found=findHandle(self,target);
 ListActionHandle local;
 local.value=found->value;
 fn_801F86C8(lbl_801E9D24.manager,found,1);
 if(fn_801F7EB8(&local)){
  fn_801EDAAC(resolved(local),lbl_8037B640,lbl_8037B640,lbl_8037B644);
  return 1;
 }
 return 0;
}
