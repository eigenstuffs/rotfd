// Typed reference-handle cleanup; see docs/notes/game-typed-handle-layers.md.
#include "typed_handle_layers_internal.h"
struct Handle_8001FF04:TypedHandleLayer<1> {
    ~Handle_8001FF04();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_8001FF04::~Handle_8001FF04(){}
