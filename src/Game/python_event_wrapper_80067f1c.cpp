#include "Game/early_python_event_views.h"
extern "C" void fn_80067F1C(PythonEventOwner*self,void* value0){
 self->active[10]=1;
 const char*pool=lbl_8029BF50;
 lbl_803776DC=value0;
 lbl_803776D0=value0;
 if(self->script){
  EventPyObject*method=PyObject_GetAttrString(self->script,lbl_803787A8);
  EventPyObject*result;
  if(!method){printf(pool+0x380);abort();}
  if(method){
   result=fn_801308B4(method,0);
   if(!result){PyErr_Print();fn_801F9D68(lbl_801E9D24.diagnostics,pool+0x394);}
  }else fn_801FA014(lbl_801E9D24.diagnostics,pool+0x3e0);
  releaseEventObject(method);releaseEventObject(result);
 }
 self->active[10]=0;
}
