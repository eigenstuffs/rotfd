#include "Game/scene_mode_selection.h"

extern "C" void fn_800C4984(SceneModeSelection::Owner* self) {
    SceneModeSelection::Mode* mode = lbl_801E9D24.scene->mode;
    if (mode->category == 4 && (mode->state == 0 || mode->state == 1))
        fn_80056014(mode, 10);
    else
        fn_80056014(mode, 1);
    fn_80056540(mode, self->value8C);
    self->selected = fn_8005863C(mode).get();
    fn_8002B0A8(self);
}
