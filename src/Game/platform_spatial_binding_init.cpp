#include "Game/platform_resource_initializers.h"

struct PlatformBindingInit { char unknown00[8]; void* table; };
extern "C" {
void* __ct__23SpatialBinding_802EC2C0Fv(void*);
extern char lbl_802ED3B0[];
}

extern "C" PlatformBindingInit* fn_8026F078(PlatformBindingInit* self) {
    __ct__23SpatialBinding_802EC2C0Fv(self);
    self->table = lbl_802ED3B0;
    return self;
}
