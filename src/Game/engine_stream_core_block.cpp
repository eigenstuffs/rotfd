#include "Game/engine_stream_layers.h"

extern "C" void fn_80243E44(EngineStreamLayerView* self, void** cursor)
{
    slot0C__12BaseObject_ZFUl(self, cursor);
    *cursor = fn_801E9F40(self->field0C, *cursor, 0x64);
}
