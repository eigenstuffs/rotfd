#include "typed_handle_layers_internal.h"
struct Handle_8005287C:TypedHandleLayer<1> {
    ~Handle_8005287C();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_8005287C::~Handle_8005287C(){}
