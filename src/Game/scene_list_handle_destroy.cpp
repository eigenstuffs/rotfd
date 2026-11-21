#include "Game/object_list_acquire_controls.h"

struct SceneListHandle_80260F08 {
    unsigned long value;
};

extern "C" {
void* __dt__15Handle_801F7F10Fv(void*, short);
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
}

extern "C" SceneListHandle_80260F08* fn_80260F08(SceneListHandle_80260F08* self,
                                             short flag)
{
    if (self) {
        __dt__15Handle_801F7F10Fv(self, -1);
        if (flag > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
