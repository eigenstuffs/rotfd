/* Resource-owner array and sparse-slot cleanup.
 * See docs/notes/game-engine-resource-owner-teardown.md. */
#include "Game/engine_resource_owner_teardown.h"

extern "C" ResourceOwnerTeardown* fn_8026A710(
    ResourceOwnerTeardown* self, short deleting) {
    if (self) {
        self->table = lbl_802ED148;
        if (lbl_801E9D24.manager && fn_801F7EB8(&self->handleC168))
            fn_80263524(lbl_801E9D24.manager, &self->handleC168);
        self->arrayDA00.~ResourceOwnerTeardownArray<ResourceOwnerTeardownElement40>();
        self->sparseC170.~ResourceOwnerTeardownSparse();
        self->handleC168.~ResourceOwnerTeardownHandle2();
        self->handleC164.~ResourceOwnerTeardownHandle2();
        self->fixedC140.~ResourceOwnerTeardownFixed<ResourceOwnerTeardownHandle5>();
        self->arrayC134.~ResourceOwnerTeardownArray<ResourceOwnerTeardownHandle3>();
        self->fixedC110.~ResourceOwnerTeardownFixed<ResourceOwnerTeardownHandle5>();
        self->arrayC100.~ResourceOwnerTeardownArray<ResourceOwnerTeardownHandle1>();
        self->group80BC.~ResourceOwnerTeardownGroup();
        self->group4078.~ResourceOwnerTeardownGroup();
        self->group34.~ResourceOwnerTeardownGroup();
        self->handle30.~ResourceOwnerTeardownHandle2();
        self->array24.~ResourceOwnerTeardownArray<ResourceOwnerTeardownHandle2>();
        self->array18.~ResourceOwnerTeardownArray<ResourceOwnerTeardownHandle2>();
        self->array0C.~ResourceOwnerTeardownArray<ResourceOwnerTeardownHandle2>();
        if (self) {
            self->table = __vt__17Resource_802E9E20;
            __dt__12BaseObject_ZFv(self, 0);
        }
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
