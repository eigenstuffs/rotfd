#include "Game/handle_member_dispatch_internal.h"

extern "C" void fn_80262180(DispatchMember04* self)
{
    if (fn_801F7EB8(&self->handle))
        ((DispatchVirtual*)resolved(self->handle))->slot1C();
}
