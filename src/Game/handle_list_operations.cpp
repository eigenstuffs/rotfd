#include "Game/handle_list_operations_internal.h"
extern "C" void fn_80267FCC(View*self){for(int i=0;i<self->handles.count;++i){if(fn_801F7EB8(&self->handles[i]))fn_801EE978(resolved(self->handles[i]));}}
extern "C" Handle*fn_80268080(View*self,const Handle&target){for(int i=0;i<self->handles.count;++i){Object*object=resolved(self->handles[i]);if(equal(object->related,target))return &self->handles[i];}return self->handles.data;}
