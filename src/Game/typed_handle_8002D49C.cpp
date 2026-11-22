#include "typed_handle_layers_internal.h"
struct Handle_8002D49C:TypedHandleLayer<3> {
    ~Handle_8002D49C();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_8002D49C::~Handle_8002D49C(){}
