#include "Game/handle_member_dispatch_internal.h"

extern "C" void fn_80260F64(DispatchMember18* self)
{
    if (fn_801F7EB8(&self->handle))
        ((DispatchVirtual*)resolved(self->handle))->slot1C();
}
