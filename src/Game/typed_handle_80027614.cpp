// Typed reference-handle cleanup; see docs/notes/game-typed-handle-layers.md.
#include "typed_handle_layers_internal.h"
struct Handle_80027614:TypedHandleLayer<1> {
    ~Handle_80027614();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_80027614::~Handle_80027614(){}
