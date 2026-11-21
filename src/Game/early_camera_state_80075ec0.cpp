#include "Game/early_camera_state_views.h"

extern "C" void fn_80075EC0(CameraPairOwner* self, const CameraHandle& a, const CameraHandle& b) {
    self->first = a;
    self->second = b;
    self->ready = 1;
}
