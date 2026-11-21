#include "Game/engine_mesh_owner_controls.h"

extern "C" void fn_80238F64(NamedOwnerCopySource*, Handle_801F7F10&);

extern "C" void fn_8026D89C(NamedOwnerCopySource* self, Handle_801F7F10& target)
{
    fn_80238F64(self, target);
}
