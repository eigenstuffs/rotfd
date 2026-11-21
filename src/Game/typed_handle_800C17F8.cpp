// Typed reference-handle cleanup; see docs/notes/game-typed-handle-layers.md.
#include "typed_handle_layers_internal.h"
struct Handle_800C17F8:TypedHandleLayer<6> {
    ~Handle_800C17F8();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_800C17F8::~Handle_800C17F8(){}
