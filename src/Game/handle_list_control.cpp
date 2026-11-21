#include "Game/handle_list_operations_internal.h"
extern "C" void fn_801EDB54(Object*,float);
extern "C" void fn_801EDD8C(Object*);
static inline void finishHandles(View*self){for(int i=0;i<self->handles.count;++i)fn_801EDD8C(resolved(self->handles[i]));}
extern "C" void fn_80268364(View*self,float value){
 for(int i=0;i<self->handles.count;++i)fn_801EDB54(resolved(self->handles[i]),value);
 finishHandles(self);
}
