#include "Game/engine_mesh_owner_controls.h"

extern "C" void fn_801CDC38(void*);
extern "C" void fn_8026D980(void*);

extern "C" void fn_8026DFA4(void* self)
{
    fn_801CDC38(self);
    fn_8026D980(self);
}
