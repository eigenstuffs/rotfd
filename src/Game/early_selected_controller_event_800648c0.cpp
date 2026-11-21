#include "Game/early_selected_controller_event_views.h"

extern "C" void fn_800648C0(SelectedObject* self) {
    if (fn_8025E9FC(self, 0x97)) {
        const SelectedHandle& handle = resolveRelated(
            *resolveSelected(*lbl_801E9D24.selection->current)->related)->controller;
        SelectedObject* object = fn_801F7EB8(&handle) ? resolveSelected(handle) : 0;
        if (object->enabled)
            fn_802603A0(lbl_801E9D24.scene, 0x97,
                resolveSelected(object->owner), lbl_80378738);
    }
}
