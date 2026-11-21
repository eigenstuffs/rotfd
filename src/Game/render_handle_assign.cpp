#include "Game/handle_list_operations_internal.h"
extern "C"{void fn_801F86C8(void*,const void*,int);void fn_80272968(void*,void*,int);}
struct HandleAssignView{char unknown00[0x220];Handle handle;};
extern "C" void fn_80272DE8(HandleAssignView*self,const Handle&handle){fn_801F86C8(lbl_801E9D24.manager,&self->handle,-1);self->handle.value=handle.value;fn_801F86C8(lbl_801E9D24.manager,&handle,1);fn_80272968(self,resolved(self->handle),4);}
