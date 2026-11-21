#include "Game/engine_array_owner_cleanup.h"

static inline void destroy24(struct EngineOwnerArray24* self)
{
    int i;
    if (self) {
        if (self->items) {
            for (i = 0; i < self->count; i++) {}
            if (self->items) {
                fn_8028FD50(lbl_8028F698, self->items, self->capacity * 24);
                self->items = 0;
            }
            self->items = 0;
        }
    }
}

static inline void destroy140(struct EngineOwnerArray140* self)
{
    int i;
    if (self) {
        if (self->items) {
            for (i = 0; i < self->count; i++) {}
            if (self->items) {
                fn_8028FD50(lbl_8028F698, self->items, self->capacity * 140);
                self->items = 0;
            }
            self->items = 0;
        }
    }
}

struct EngineArrayOwnerPair* fn_8020C5CC(struct EngineArrayOwnerPair* self, short deleting)
{
    if (self) {
        self->vptr = &lbl_802EAFF0;
        destroy140(&self->second);
        destroy24(&self->first);
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
