// Typed reference-handle cleanup; see docs/notes/game-typed-handle-layers.md.
#include "typed_handle_layers_internal.h"
struct Handle_8001FF78:Handle_801F7F10 {
    ~Handle_8001FF78();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_8001FF78::~Handle_8001FF78(){}
