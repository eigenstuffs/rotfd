#include "Game/engine_stream_layers.h"

extern "C" void fn_80243D38(EngineStreamLayerView* self, void** cursor)
{
    fn_80243E44(self, cursor);
    *cursor = fn_801E9F40(self->field74, *cursor, 0x10);
}
