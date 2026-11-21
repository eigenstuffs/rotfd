#include "Game/platform_followup_controls.h"
#include "six_handle_resource_internal.h"

extern "C" u32 fn_801E9F40(void*, u32, int);

extern "C" void fn_80271980(SixHandleResource_802EA840* self, u32* stream) {
    self->SixHandleResource_802EA840::slot0C((u32)stream);
    *stream = fn_801E9F40((char*)self + 0x8C, *stream, 32);
}
