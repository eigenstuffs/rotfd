#include "Game/base_destructor_internal.h"

extern "C" {
extern char lbl_802ED3B0[];
void* fn_8024C8CC(void*, int);
}

extern "C" BaseDestructorView* fn_8026F010(BaseDestructorView* self, int deleting)
{
    if (self) {
        self->table = lbl_802ED3B0;
        fn_8024C8CC(self, 0);
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
