#include "Game/platform_draw_dispatch_internal.h"
extern "C" void fn_80284D80(PlatformDrawDispatchOwner* self,void* first,void* second) {
    self->dispatch(first,second,self->unknown98+0x18);
}
