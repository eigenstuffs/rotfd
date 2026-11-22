#include "typed_handle_layers_internal.h"
struct Handle_80021C40:Handle_801F7F10 {
    ~Handle_80021C40();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_80021C40::~Handle_80021C40(){}
