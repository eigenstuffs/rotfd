#include "Game/engine_handle_copy_pair.h"

HandleCopy_8023F578::HandleCopy_8023F578(const HandleCopy_8023F578 &handle)
{
    value = handle.value;
    fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
}
