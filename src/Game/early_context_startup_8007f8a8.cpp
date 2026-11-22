#include "Game/early_context_startup_views.h"

extern "C" void slot40__15CProjectileMoveFPC4Vec3PC4Vec3PC4Vec3if(StartupNode* self, void* a, void* b, void* c,
                           void* d, double delta) {
    if (!(resolveStartup(*self->slot37(0))->flags & 0x10000))
        fn_8022993C(self, a, b, c, d, delta);
    else
        self->slot45(a, 0);
}
