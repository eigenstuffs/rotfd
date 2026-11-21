#include "Game/early_python_event_views.h"
extern "C" void fn_80067C0C(PythonEventOwner*self,unsigned short value0){
 self->active[7]=1;
 lbl_803776C4=value0;
 if(self->script){
  EventPyObject*method=PyObject_GetAttrString(self->script,lbl_80378798);
  EventPyObject*result;
  if(method){
   result=fn_801308B4(method,0);
   if(!result){PyErr_Print();fn_801F9D68(lbl_801E9D24.diagnostics,lbl_8029C144);}
  }else fn_801FA014(lbl_801E9D24.diagnostics,lbl_8029C190);
  releaseEventObject(method);releaseEventObject(result);
 }
 self->active[7]=0;
}
