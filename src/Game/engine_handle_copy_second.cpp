#include "Game/engine_handle_copy_pair.h"

HandleCopy_8023F5EC::HandleCopy_8023F5EC(const HandleCopy_8023F5EC &handle)
{
    value = handle.value;
    fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
}
