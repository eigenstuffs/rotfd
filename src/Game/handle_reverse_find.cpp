#include "Game/handle_list_operations_internal.h"
struct ReverseHandleArray8 {Handle data[8];int count;Handle&operator[](unsigned int i){return data[i];}};struct ReverseHandleView {char unknown00[0xC140];ReverseHandleArray8 handles;};
extern "C" signed char fn_8024E200(Object*,const void*,const void*);
extern "C" Object*fn_80269F2C(ReverseHandleView*self,const void*a,const void*b){
 for(int i=self->handles.count;--i>=0;){Object*object=resolved(self->handles[i]);if(fn_8024E200(object,a,b))return object;}
 return 0;
}
