#include "typed_handle_layers_internal.h"
struct Handle_8002F6B0:TypedHandleLayer<2> {
    ~Handle_8002F6B0();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_8002F6B0::~Handle_8002F6B0(){}
