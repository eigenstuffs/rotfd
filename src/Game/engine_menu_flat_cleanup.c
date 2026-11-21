#include "Game/engine_menu_array_cleanup.h"

static inline void destroyHandle(struct EngineMenuCleanupHandle* handle)
{
    if (handle)
        __dt__15Handle_801F7F10Fv(handle, 0);
}

static inline void destroyWrapped(struct EngineMenuCleanupWrapped* handle)
{
    if (handle)
        destroyHandle(&handle->handle);
}

static inline void destroyArray(struct EngineMenuCleanupFlatArray* self)
{
    int i;
    if (self) {
        if (self->items) {
            for (i = 0; i < self->count; i++) {}
            if (self->items) {
                fn_8028FD50(lbl_8028F698, self->items, self->capacity * 144);
                self->items = 0;
            }
            self->items = 0;
        }
    }
}

struct EngineMenuCleanupFlatOwner* fn_8021B688(struct EngineMenuCleanupFlatOwner* self, short deleting)
{
    if (self) {
        self->vptr = __vt__18MenuArray_802EB348;
        destroyArray(&self->array);
        destroyWrapped(&self->second);
        destroyWrapped(&self->first);
        __dt__17MenuBase_8021D7E4Fv(self, 0);
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
