#include "Game/base_destructor_internal.h"

extern "C" {
extern char lbl_802ED1C4[];
void* fn_80247128(void*, int);
}

extern "C" BaseDestructorView* fn_8026D834(BaseDestructorView* self, int deleting)
{
    if (self) {
        self->table = lbl_802ED1C4;
        fn_80247128(self, 0);
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
