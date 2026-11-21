// Observed handle-member cleanup; prefix bytes are an opaque ABI view.
#include "typed_handle_layers_internal.h"
struct HandleOwner_8007B3C8 {
    char unknown[0x4];
    TypedHandleLayer<5> handle;
    ~HandleOwner_8007B3C8();
    static void operator delete(void*object)throw(){fn_801EF610(lbl_801EF5C8,object);}
};
HandleOwner_8007B3C8::~HandleOwner_8007B3C8(){}
