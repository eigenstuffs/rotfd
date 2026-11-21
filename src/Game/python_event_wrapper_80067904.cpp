#include "Game/early_python_event_views.h"
extern "C" void fn_80067904(PythonEventOwner*self,void* value0,unsigned short value1){
 self->active[4]=1;
 lbl_803776CC=value0;
 lbl_803776D0=value0;
 lbl_803776C8=value1;
 if(self->script){
  EventPyObject*method=PyObject_GetAttrString(self->script,lbl_80378788);
  EventPyObject*result;
  if(method){
   result=fn_801308B4(method,0);
   if(!result){PyErr_Print();fn_801F9D68(lbl_801E9D24.diagnostics,lbl_8029BFC4);}
  }else fn_801FA014(lbl_801E9D24.diagnostics,lbl_8029C014);
  releaseEventObject(method);releaseEventObject(result);
 }
 self->active[4]=0;
}
