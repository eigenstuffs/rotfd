/* Python event wrapper for owner event slot 0: records the argument in the
   current-owner or other-owner slot, then calls the script method. Built with
   -opt nocse (the original reloads lbl_803776B8 before the second compare; the
   adjacent wrappers 80067F1C/80068158 also match under -opt nocse). Layout
   follows include/Game/early_python_event_views.h. */
struct EventPyObject;
struct EventPyType{char unknown00[0x18];void(*destroy)(EventPyObject*);};
struct EventPyObject{int references;EventPyType*type;};
struct PythonEventOwner{char unknown00[0x40];EventPyObject*script;char unknown44[0x30];signed char active[17];};
struct PythonEventContext{char unknown00[0x110];void*diagnostics;};
static inline void releaseEventObject(EventPyObject*object){if(object){if(--object->references==0)object->type->destroy(object);}}
extern "C" {
extern PythonEventContext lbl_801E9D24;
EventPyObject*PyObject_GetAttrString(EventPyObject*,const char*);
EventPyObject*fn_801308B4(EventPyObject*,void*);
void PyErr_Print();
void fn_801F9D68(void*,const char*,...);
void fn_801FA014(void*,const char*,...);
extern const char lbl_8029BF50[];
extern void* lbl_80374498;
extern void* lbl_8037449C;
extern PythonEventOwner*lbl_803776B8;
}
extern "C" void fn_8006803C(PythonEventOwner*self,void* value0){
 self->active[0]=1;
 const char*pool=lbl_8029BF50;
 if(self==lbl_803776B8)lbl_8037449C=value0;
 if(self!=lbl_803776B8)lbl_80374498=value0;
 if(self->script){
  EventPyObject*method=PyObject_GetAttrString(self->script,pool+0x410);
  EventPyObject*result;
  if(method){
   result=fn_801308B4(method,0);
   if(!result){PyErr_Print();fn_801F9D68(lbl_801E9D24.diagnostics,pool+0x41c);}
  }else fn_801FA014(lbl_801E9D24.diagnostics,pool+0x46c);
  releaseEventObject(method);releaseEventObject(result);
 }
 self->active[0]=0;
}
