#include "Game/early_python_event_views.h"
extern "C" void fn_80067E18(PythonEventOwner*self,void* value0){
 self->active[9]=1;
 const char*pool=lbl_8029BF50;
 lbl_803776D4=value0;
 lbl_803776D0=value0;
 if(self->script){
  EventPyObject*method=PyObject_GetAttrString(self->script,pool+0x2ec);
  EventPyObject*result;
  if(method){
   result=fn_801308B4(method,0);
   if(!result){PyErr_Print();fn_801F9D68(lbl_801E9D24.diagnostics,pool+0x2fc);}
  }else fn_801FA014(lbl_801E9D24.diagnostics,pool+0x34c);
  releaseEventObject(method);releaseEventObject(result);
 }
 self->active[9]=0;
}
