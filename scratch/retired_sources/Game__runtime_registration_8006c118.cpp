#include "Game/resource_runtime_update_views.h"

extern "C" signed char fn_8006C118(RuntimeQuery* self, unsigned char mode)
{
    if (mode == 1) {
        self->activate();
        static_cast<RuntimeGlobalOwner*>(lbl_803776B8)->registration->active = self;
    } else if (mode == 2) {
        self->deactivate();
    }
    return 1;
}
