#include "typed_handle_layers_internal.h"
struct Handle_8004A72C:TypedHandleLayer<3> {
    ~Handle_8004A72C();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_8004A72C::~Handle_8004A72C(){}
