#include "Game/handle_list_operations_internal.h"
extern "C"{void fn_801F86C8(void*,const void*,int);void fn_80281830(void*,void*,int,int,int);}
struct HandleSelectView{char unknown00[0x224];Handle handle;char unknown228[0xA8];unsigned short flags;};
struct SelectObject{char unknown00[0x3F];unsigned char kind;};
extern "C" void fn_80272854(HandleSelectView*self,const Handle&handle){fn_801F86C8(lbl_801E9D24.manager,&self->handle,-1);self->handle.value=handle.value;fn_801F86C8(lbl_801E9D24.manager,&handle,1);SelectObject*object=(SelectObject*)resolved(self->handle);if(object){self->flags|=8;switch(object->kind){case 1:self->flags|=2;break;case 2:self->flags|=1;break;}fn_80281830(*(void**)((char*)&lbl_801E9D24+0x184),object,1,1,0);}}
