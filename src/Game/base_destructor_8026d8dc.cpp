#include "Game/base_destructor_internal.h"

extern "C" {
extern char lbl_802ED218[];
void* fn_80239638(void*, int);
}

extern "C" BaseDestructorView* fn_8026D8DC(BaseDestructorView* self, int deleting)
{
    if (self) {
        self->table = lbl_802ED218;
        fn_80239638(self, 0);
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
