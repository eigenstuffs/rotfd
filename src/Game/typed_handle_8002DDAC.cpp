#include "typed_handle_layers_internal.h"
struct Handle_8002DDAC:TypedHandleLayer<4> {
    ~Handle_8002DDAC();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_8002DDAC::~Handle_8002DDAC(){}
