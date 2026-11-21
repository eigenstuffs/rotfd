#include "group_runtime_internal.h"

extern "C" void fn_801FFBB0(Group* self, float delta) {
    if (!self->paused) {
        fn_8023AAAC(lbl_801E9D24.updateContext);
        for (int i = 0; i < self->entries.count; ++i) {
            Object* object = resolve(self->entries.data[i]);
            if (object)
                fn_8020349C(object, delta);
        }
    }
}

extern "C" void fn_801FFA58(Group* self) {
    lbl_801E9D24.game->reset();
    int i;
    for (i = 0; i < self->entries.count; ++i) {
        Object* object = resolve(self->entries.data[i]);
        if (object)
            object->slot5();
    }
    for (i = 0; i < 4; ++i) {
        if (fn_801F7EB8(&self->fixed[i]))
            resolve(self->fixed[i])->slot5();
    }
}
