#include "typed_handle_layers_internal.h"
struct Handle_8004A648:TypedHandleLayer<4> {
    ~Handle_8004A648();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_8004A648::~Handle_8004A648(){}
