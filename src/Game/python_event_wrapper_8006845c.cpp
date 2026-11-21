#include "Game/early_python_event_views.h"
extern "C" void fn_8006845C(PythonEventOwner*self,void* value0){
 self->active[13]=1;
 lbl_803776E4=value0;
 if(self->script){
  EventPyObject*method=PyObject_GetAttrString(self->script,lbl_803787B0);
  EventPyObject*result;
  if(method){
   result=fn_801308B4(method,0);
   if(!result){PyErr_Print();fn_801F9D68(lbl_801E9D24.diagnostics,lbl_8029C59C);}
  }else fn_801FA014(lbl_801E9D24.diagnostics,lbl_8029C5E8);
  releaseEventObject(method);releaseEventObject(result);
 }
 self->active[13]=0;
}
