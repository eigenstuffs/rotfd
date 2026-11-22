#include "typed_handle_layers_internal.h"
struct Handle_80021BCC:TypedHandleLayer<1> {
    ~Handle_80021BCC();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_80021BCC::~Handle_80021BCC(){}
