#include "typed_handle_layers_internal.h"
struct Handle_8002759C:TypedHandleLayer<2> {
    ~Handle_8002759C();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_8002759C::~Handle_8002759C(){}
