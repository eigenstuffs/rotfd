#include "typed_handle_layers_internal.h"
struct Handle_80085054:TypedHandleLayer<3> {
    ~Handle_80085054();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
Handle_80085054::~Handle_80085054(){}
