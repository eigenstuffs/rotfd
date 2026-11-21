#include "Game/early_python_event_views.h"
extern "C" void fn_80067A0C(PythonEventOwner*self,unsigned short value0){
 self->active[5]=1;
 lbl_803776C2=value0;
 if(self->script){
  EventPyObject*method=PyObject_GetAttrString(self->script,lbl_80378790);
  EventPyObject*result;
  if(method){
   result=fn_801308B4(method,0);
   if(!result){PyErr_Print();fn_801F9D68(lbl_801E9D24.diagnostics,lbl_8029C044);}
  }else fn_801FA014(lbl_801E9D24.diagnostics,lbl_8029C08C);
  releaseEventObject(method);releaseEventObject(result);
 }
 self->active[5]=0;
}
