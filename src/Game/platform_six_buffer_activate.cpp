#include "Game/platform_small_controls.h"
#include "six_handle_resource_internal.h"

extern "C" void fn_802715C8(SixHandleResource_802EA840*);

extern "C" void fn_80271944(SixHandleResource_802EA840* self) {
    self->SixHandleResource_802EA840::slot10();
    *((unsigned char*)self + 0x88) = 0;
    fn_802715C8(self);
}
