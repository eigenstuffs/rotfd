#include "Game/engine_array_owner_cleanup.h"

static inline void destroy8(struct EngineOwnerArray8* self)
{
    int i;
    if (self) {
        if (self->items) {
            for (i = 0; i < self->count; i++) {}
            if (self->items) {
                fn_8028FD50(lbl_8028F698, self->items, self->capacity * 8);
                self->items = 0;
            }
            self->items = 0;
        }
    }
}

static inline void destroy16(struct EngineOwnerArray16* self)
{
    int i;
    if (self) {
        if (self->items) {
            for (i = 0; i < self->count; i++) {}
            if (self->items) {
                fn_8028FD50(lbl_8028F698, self->items, self->capacity * 16);
                self->items = 0;
            }
            self->items = 0;
        }
    }
}

static inline void destroy2(struct EngineOwnerArray2* self)
{
    int i;
    if (self) {
        if (self->items) {
            for (i = 0; i < self->count; i++) {}
            if (self->items) {
                fn_8028FD50(lbl_8028F698, self->items, self->capacity * 2);
                self->items = 0;
            }
            self->items = 0;
        }
    }
}

struct EngineArrayOwnerTriple* fn_80231B28(struct EngineArrayOwnerTriple* self, short deleting)
{
    if (self) {
        destroy2(&self->third);
        destroy16(&self->second);
        destroy8(&self->first);
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
