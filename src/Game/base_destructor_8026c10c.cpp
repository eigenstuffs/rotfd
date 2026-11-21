#include "Game/base_destructor_internal.h"

extern "C" {
extern char lbl_802ED178[];
void* fn_801CC4F0(void*, int);
}

extern "C" BaseDestructorView* fn_8026C10C(BaseDestructorView* self, int deleting)
{
    if (self) {
        self->table = lbl_802ED178;
        fn_801CC4F0(self, 0);
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
