#include "typed_handle_layers_internal.h"
struct Handle_80062F24:TypedHandleLayer<4> {
    ~Handle_80062F24();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_80062F24::~Handle_80062F24(){}
