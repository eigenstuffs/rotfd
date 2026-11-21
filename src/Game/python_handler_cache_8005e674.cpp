#include "Game/python_handler_cache_views.h"
extern "C" void fn_8005E674(PythonHandlerCache*self,CachedScriptObject*script){
 self->script=script;
 if(PyObject_HasAttrString(self->script,lbl_80378658))self->handlers[0]=PyObject_GetAttrString(self->script,lbl_80378658);
 if(PyObject_HasAttrString(self->script,"Activate"))self->handlers[1]=PyObject_GetAttrString(self->script,"Activate");
 if(PyObject_HasAttrString(self->script,lbl_80378660))self->handlers[2]=PyObject_GetAttrString(self->script,lbl_80378660);
 if(PyObject_HasAttrString(self->script,lbl_80378668))self->handlers[3]=PyObject_GetAttrString(self->script,lbl_80378668);
 if(PyObject_HasAttrString(self->script,"RTCStart"))self->handlers[4]=PyObject_GetAttrString(self->script,"RTCStart");
 if(PyObject_HasAttrString(self->script,lbl_80378670))self->handlers[5]=PyObject_GetAttrString(self->script,lbl_80378670);
 if(PyObject_HasAttrString(self->script,"DamagedAgent"))self->handlers[7]=PyObject_GetAttrString(self->script,"DamagedAgent");
 if(PyObject_HasAttrString(self->script,lbl_80378678))self->handlers[6]=PyObject_GetAttrString(self->script,lbl_80378678);
 if(PyObject_HasAttrString(self->script,lbl_80378680))self->handlers[8]=PyObject_GetAttrString(self->script,lbl_80378680);
 if(PyObject_HasAttrString(self->script,"EnterState"))self->handlers[9]=PyObject_GetAttrString(self->script,"EnterState");
 if(PyObject_HasAttrString(self->script,"ExitState"))self->handlers[10]=PyObject_GetAttrString(self->script,"ExitState");
 if(PyObject_HasAttrString(self->script,"EnterVolume"))self->handlers[11]=PyObject_GetAttrString(self->script,"EnterVolume");
 if(PyObject_HasAttrString(self->script,"ExitVolume"))self->handlers[12]=PyObject_GetAttrString(self->script,"ExitVolume");
 if(PyObject_HasAttrString(self->script,lbl_80378688))self->handlers[13]=PyObject_GetAttrString(self->script,lbl_80378688);
 if(PyObject_HasAttrString(self->script,lbl_80378690))self->handlers[14]=PyObject_GetAttrString(self->script,lbl_80378690);
 if(PyObject_HasAttrString(self->script,lbl_80378698))self->handlers[15]=PyObject_GetAttrString(self->script,lbl_80378698);
 if(PyObject_HasAttrString(self->script,lbl_8037869C))self->handlers[16]=PyObject_GetAttrString(self->script,lbl_8037869C);
}
