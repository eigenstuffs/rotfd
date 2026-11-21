#include "Game/callback_object_wrappers_internal.h"
extern "C" void fn_80252DE0(CallbackWrapperOwnerArray*self,const int&index){
    if(index>=0)fn_8020E938(self,&self->records[index],1);
}
