#include "Game/early_python_event_views.h"
extern "C" void fn_80068158(PythonEventOwner*self){
 self->active[1]=1;
 const char*pool=lbl_8029BF50;
 if(self->script){
  EventPyObject*method=PyObject_GetAttrString(self->script,pool+0x4a0);
  EventPyObject*result;
  if(method){
   result=fn_801308B4(method,0);
   if(!result){PyErr_Print();fn_801F9D68(lbl_801E9D24.diagnostics,pool+0x4ac);}
  }else fn_801FA014(lbl_801E9D24.diagnostics,pool+0x4f8);
  releaseEventObject(method);releaseEventObject(result);
 }
 self->active[1]=0;
}
