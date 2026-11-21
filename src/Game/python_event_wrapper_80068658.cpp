#include "Game/early_python_event_views.h"
extern "C" void fn_80068658(PythonEventOwner*self){
 self->active[15]=1;
 if(self->script){
  EventPyObject*method=PyObject_GetAttrString(self->script,lbl_803787C0);
  EventPyObject*result;
  if(method){
   result=fn_801308B4(method,0);
   if(!result){PyErr_Print();fn_801F9D68(lbl_801E9D24.diagnostics,lbl_8029C690);}
  }else fn_801FA014(lbl_801E9D24.diagnostics,lbl_8029C6D8);
  releaseEventObject(method);releaseEventObject(result);
 }
 self->active[15]=0;
}
