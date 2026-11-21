#include "Game/platform_resource_initializers.h"

struct PlatformBasisInit { char unknown00[8]; void* table; };
extern "C" {
void* __ct__22BasisResource_802EBFD8Fv(void*);
extern char lbl_802ED218[];
}

extern "C" PlatformBasisInit* fn_8026D944(PlatformBasisInit* self) {
    __ct__22BasisResource_802EBFD8Fv(self);
    self->table = lbl_802ED218;
    return self;
}
