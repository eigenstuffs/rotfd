#include "Game/hierarchy_position_overlay_80203d98.h"

using namespace HierarchyPositionOverlay80203D98;

extern "C" void fn_80203D98(OverlayGroup* self, OverlayContext* context) {
    if (lbl_801E9D24.flags & 8) {
        RendererReceiver renderer(context->renderer);
        float lineOffsets[4];
        for (int view = 0; view < 4; ++view)
            lineOffsets[view] = lbl_8037A928;
        for (int i = 0; i < self->entries.count; ++i) {
            OverlayObject* hierarchy = resolve(self->entries.data[i]);
            if (hierarchy->offset >= 0) {
                for (int j = 0; j < hierarchy->count; ++j) {
                    if (fn_801F7EB8(&hierarchy->secondary.data[j])) {
                        OverlayObject* object = resolve(hierarchy->secondary.data[j]);
                        int view = object->viewIndex();
                        if (view < 0 || view >= 4)
                            view = 0;
                        int x, y, width, height;
                        fn_801E2E70(renderer.view(view), &x, &y, &width, &height);
                        lineOffsets[view] += lbl_8037A92C;
                        Position position(x + 10, y + lineOffsets[view]);
                        OverlayObject* transform = resolve(object->transform);
                        char text[128];
                        fn_801BA714(text, lbl_802AD970, transform->x, transform->y, transform->z);
                        renderer.draw(position,text,lbl_8033E738);
                    }
                }
            }
        }
    }
}
