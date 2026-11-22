#include "Game/engine_owner_transform_update.h"

extern "C" void fn_8023D9B8(TransformUpdateOwner* self, void* context,
                            const TransformUpdateOwner* parent) {
    if (self->flags & 4) {
        self->matrix = lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active] +
                       self->index;
        if (parent) fn_8027B508(self, parent);
        else fn_8027B2E4(self);
        self->flags |= 0x60;

        TransformUpdateHook* primary =
            (TransformUpdateHook*)transformUpdateResolve(self->primary);
        if (primary) {
            TransformUpdateHook* secondary =
                (TransformUpdateHook*)transformUpdateResolve(self->secondary);
            if (secondary) secondary->bind(self);
            primary->apply(self, secondary);
        }
        TransformUpdateOwner* child =
            (TransformUpdateOwner*)transformUpdateResolve(self->first);
        while (child) {
            child->flags |= 4;
            fn_8023D9B8(child, context, self);
            child = (TransformUpdateOwner*)transformUpdateResolve(child->next);
        }
        if (context) fn_8023F90C(self, context, primary);
        self->flags &= ~0x15;
    } else if (self->flags & 0x10) {
        TransformUpdateHook* primary =
            (TransformUpdateHook*)transformUpdateResolve(self->primary);
        if (primary) {
            TransformUpdateHook* secondary =
                (TransformUpdateHook*)transformUpdateResolve(self->secondary);
            if (secondary) secondary->bind(self);
            primary->apply(self, secondary);
        }
        TransformUpdateOwner* child =
            (TransformUpdateOwner*)transformUpdateResolve(self->first);
        while (child) {
            fn_8023D9B8(child, context, self);
            child = (TransformUpdateOwner*)transformUpdateResolve(child->next);
        }
        if (context) fn_8023F90C(self, context, primary);
        self->flags &= ~0x11;
    } else if (self->flags & 1) {
        TransformUpdateOwner* child =
            (TransformUpdateOwner*)transformUpdateResolve(self->first);
        while (child) {
            fn_8023D9B8(child, context, self);
            child = (TransformUpdateOwner*)transformUpdateResolve(child->next);
        }
        self->flags &= ~1;
    }
}
