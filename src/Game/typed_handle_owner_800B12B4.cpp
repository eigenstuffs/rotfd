// Observed handle-member cleanup; prefix bytes are an opaque ABI view.
#include "typed_handle_layers_internal.h"
struct HandleOwner_800B12B4 {
    char unknown[0xC0];
    TypedHandleLayer<2> handle;
    ~HandleOwner_800B12B4();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
HandleOwner_800B12B4::~HandleOwner_800B12B4(){}
