#include "typed_handle_layers_internal.h"
struct Handle_8002BA20:TypedHandleLayer<1> {
    ~Handle_8002BA20();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_8002BA20::~Handle_8002BA20(){}
