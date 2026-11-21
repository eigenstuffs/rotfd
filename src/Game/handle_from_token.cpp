#include "handle_from_token_internal.h"

// Keep the native return copy constructor inline in this recovered function.
#pragma push
#pragma inline_max_size(1024)
extern "C" Handle_801F7F10 fn_801F8114(Manager* self,u32 value) {
 Handle_801F7F10 handle;
 handle.token.value=value;
 self->retain(handle.token);
 return handle;
}

#pragma pop
