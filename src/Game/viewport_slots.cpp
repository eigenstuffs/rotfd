// Viewport reference slots and render dispatch.
#include "viewport_slots_internal.h"
extern "C" void fn_801E1F3C(ViewportSlotsView* self, const ViewportSlotHandle& handle) {
    for (int i = 0; i < 8; ++i) {
        ViewportRenderObject* object = self->slots[i].get();
        if (object == handle.get()) {
            self->slots[i] = ViewportSlotHandle();
            break;
        }
    }
}

extern "C" void fn_801E2074(ViewportSlotsView* self, const ViewportSlotHandle& handle, signed char priority) {
    if (priority) {
        if (!fn_801F7EB8(&self->slots[7])) {
            self->slots[7] = handle;
        } else {
            ViewportSlotHandle previous(self->slots[7]);
            for (int i = 6; i >= 0; --i) {
                if (!fn_801F7EB8(&self->slots[i])) {
                    self->slots[i] = previous;
                    break;
                }
            }
            self->slots[7] = handle;
        }
    } else {
        for (int i = 0; i < 8; ++i) {
            if (!fn_801F7EB8(&self->slots[i])) {
                self->slots[i] = handle;
                break;
            }
        }
    }
}


extern "C" void fn_801E2220(ViewportSlotsView* self, ViewportContext* context) {
    self->recordCount = 0;
    context->viewport = self;
    Activable_Z* world = self->world.get();
    if (world && fn_801F7EB8(&self->camera)) {
        fn_801E8274(world, context);
    }
    self->engine->unknown_27();
    for (int i = 0; i < 8; ++i) {
        ViewportRenderObject* object = self->slots[i].get();
        if (object) {
            object->slot40(self);
            self->engine->unknown_27();
        }
    }
}

