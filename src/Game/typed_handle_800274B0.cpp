#include "typed_handle_layers_internal.h"
struct Handle_800274B0:TypedHandleLayer<2> {
    ~Handle_800274B0();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_800274B0::~Handle_800274B0(){}
