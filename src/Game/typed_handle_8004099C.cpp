#include "typed_handle_layers_internal.h"
struct Handle_8004099C:TypedHandleLayer<7> {
    ~Handle_8004099C();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_8004099C::~Handle_8004099C(){}
