#include "Game/early_python_event_views.h"
extern "C" void fn_80068754(PythonEventOwner*self,void* value0){
 self->active[16]=1;
 lbl_803744A0=value0;
 if(self->script){
  EventPyObject*method=PyObject_GetAttrString(self->script,lbl_803787C4);
  EventPyObject*result;
  if(method){
   result=fn_801308B4(method,0);
   if(!result){PyErr_Print();fn_801F9D68(lbl_801E9D24.diagnostics,lbl_8029C704);}
  }else fn_801FA014(lbl_801E9D24.diagnostics,lbl_8029C750);
  releaseEventObject(method);releaseEventObject(result);
 }
 self->active[16]=0;
}
