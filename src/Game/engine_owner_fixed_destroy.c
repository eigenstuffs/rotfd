#include "Game/engine_owner_lifecycle.h"

OwnerLifecycleFixed *fn_8020B7DC(OwnerLifecycleFixed *self, int deleting)
{
    if (self) {
        self->table = &lbl_802EC030;
        __destroy_arr(self->items, (void (*)(void *, int))fn_8020B860,
                      sizeof(OwnerLifecycleRecord), 32);
        fn_801F56A8(self, 0);
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
