#include "Game/handle_list_operations_internal.h"
extern "C" extern const float lbl_8037B6AC;
struct HandleStatusView {char unknown00[0x18];float value;char unknown1C[0x4C];unsigned long flags;char unknown6C[8];Handle handles[1];};
struct StatusObject {char unknown00[0x3F];unsigned char kind;};
extern "C" signed char fn_80270F78(HandleStatusView*self,int index){if(index==1)return 1;if(fn_801F7EB8(&self->handles[index])){StatusObject*object=(StatusObject*)resolved(self->handles[index]);if(object->kind==2)return 1;}if(self->value<lbl_8037B6AC)return 1;return (self->flags>>3)&1;}
