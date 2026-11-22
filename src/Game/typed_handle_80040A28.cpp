#include "typed_handle_layers_internal.h"
struct Handle_80040A28:TypedHandleLayer<3> {
    ~Handle_80040A28();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_80040A28::~Handle_80040A28(){}
