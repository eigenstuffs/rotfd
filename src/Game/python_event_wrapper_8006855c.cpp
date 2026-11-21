#include "Game/early_python_event_views.h"
extern "C" void fn_8006855C(PythonEventOwner*self){
 self->active[14]=1;
 if(self->script){
  EventPyObject*method=PyObject_GetAttrString(self->script,lbl_803787B8);
  EventPyObject*result;
  if(method){
   result=fn_801308B4(method,0);
   if(!result){PyErr_Print();fn_801F9D68(lbl_801E9D24.diagnostics,lbl_8029C618);}
  }else fn_801FA014(lbl_801E9D24.diagnostics,lbl_8029C660);
  releaseEventObject(method);releaseEventObject(result);
 }
 self->active[14]=0;
}
