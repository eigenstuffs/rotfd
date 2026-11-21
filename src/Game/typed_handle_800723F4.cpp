// Typed reference-handle cleanup; see docs/notes/game-typed-handle-layers.md.
#include "typed_handle_layers_internal.h"
struct Handle_800723F4:TypedHandleLayer<1> {
    ~Handle_800723F4();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_800723F4::~Handle_800723F4(){}
