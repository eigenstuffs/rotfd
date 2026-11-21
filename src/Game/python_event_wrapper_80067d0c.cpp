#include "Game/early_python_event_views.h"
extern "C" void fn_80067D0C(PythonEventOwner*self,void* value0,unsigned short value1,unsigned short value2){
 self->active[8]=1;
 lbl_803776CA=value2;
 lbl_803776D8=value0;
 lbl_803776D0=value0;
 lbl_803776C6=value1;
 if(self->script){
  EventPyObject*method=PyObject_GetAttrString(self->script,lbl_803787A0);
  EventPyObject*result;
  if(method){
   result=fn_801308B4(method,0);
   if(!result){PyErr_Print();fn_801F9D68(lbl_801E9D24.diagnostics,lbl_8029C1C0);}
  }else fn_801FA014(lbl_801E9D24.diagnostics,lbl_8029C20C);
  releaseEventObject(method);releaseEventObject(result);
 }
 self->active[8]=0;
}
