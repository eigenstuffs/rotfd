#include "Game/early_python_event_views.h"
extern "C" void fn_80067B0C(PythonEventOwner*self,unsigned short value0){
 self->active[6]=1;
 const char*pool=lbl_8029BF50;
 lbl_803776C4=value0;
 if(self->script){
  EventPyObject*method=PyObject_GetAttrString(self->script,pool+0x16c);
  EventPyObject*result;
  if(method){
   result=fn_801308B4(method,0);
   if(!result){PyErr_Print();fn_801F9D68(lbl_801E9D24.diagnostics,pool+0x178);}
  }else fn_801FA014(lbl_801E9D24.diagnostics,pool+0x1c4);
  releaseEventObject(method);releaseEventObject(result);
 }
 self->active[6]=0;
}
