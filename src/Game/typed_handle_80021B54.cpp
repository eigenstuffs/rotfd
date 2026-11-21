// Typed reference-handle cleanup; see docs/notes/game-typed-handle-layers.md.
#include "typed_handle_layers_internal.h"
struct Handle_80021B54:TypedHandleLayer<2> {
    ~Handle_80021B54();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_80021B54::~Handle_80021B54(){}
