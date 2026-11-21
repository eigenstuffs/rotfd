#include "Game/engine_record_dispatch.h"

extern "C" void fn_802377B4(EngineDispatchController* self,
    const EngineDispatchEvent* event, float value)
{
    if (event->command == 0x43)
        self->slot54(0);
    if (event->command == 0x44)
        self->slot54(1);
    if (event->command == 0x45)
        self->slot54(2);
    if (event->command == 0x46)
        self->slot4C();
    if (event->command == 0x47)
        self->slot50(0, value);
    if (event->command == 0x48)
        self->slot50(1, value);
    if (event->command == 0x49)
        self->slot50(2, value);
    if (event->command == 0x4A)
        self->position = game_vec3_zero;
}
