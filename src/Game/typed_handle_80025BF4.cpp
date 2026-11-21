// Typed reference-handle cleanup; see docs/notes/game-typed-handle-layers.md.
#include "typed_handle_layers_internal.h"
struct Handle_80025BF4:TypedHandleLayer<3> {
    ~Handle_80025BF4();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_80025BF4::~Handle_80025BF4(){}
