#include "Game/platform_resource_initializers.h"

struct PlatformSpatialInit { char unknown00[8]; void* table; };
struct PlatformSpatialInitGlobals { char unknown00[0x114]; void* resource; };
extern "C" {
void* __ct__23SpatialHandles_802EA2E0Fv(void*);
void fn_8027235C(void*);
extern char lbl_802ED178[];
extern PlatformSpatialInitGlobals lbl_801E9D24;
}

extern "C" PlatformSpatialInit* fn_8026C174(PlatformSpatialInit* self) {
    __ct__23SpatialHandles_802EA2E0Fv(self);
    self->table = lbl_802ED178;
    fn_8027235C(lbl_801E9D24.resource);
    return self;
}
