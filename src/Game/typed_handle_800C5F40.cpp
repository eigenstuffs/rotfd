#include "typed_handle_layers_internal.h"
struct Handle_800C5F40:TypedHandleLayer<1> {
    ~Handle_800C5F40();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_800C5F40::~Handle_800C5F40(){}
