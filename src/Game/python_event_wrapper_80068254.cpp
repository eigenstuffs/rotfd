#include "Game/early_python_event_views.h"
extern "C" void fn_80068254(PythonEventOwner*self,void* value0){
 self->active[11]=1;
 const char*pool=lbl_8029BF50;
 lbl_803776E0=value0;
 lbl_803776D0=value0;
 if(self->script){
  EventPyObject*method=PyObject_GetAttrString(self->script,pool+0x52c);
  EventPyObject*result;
  if(method){
   result=fn_801308B4(method,0);
   if(!result){PyErr_Print();fn_801F9D68(lbl_801E9D24.diagnostics,pool+0x538);}
  }else fn_801FA014(lbl_801E9D24.diagnostics,pool+0x588);
  releaseEventObject(method);releaseEventObject(result);
 }
 self->active[11]=0;
}
