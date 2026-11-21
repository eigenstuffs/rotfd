#include "Game/engine_stream_layers.h"

extern "C" void fn_80244190(EngineStreamLayerView* self, void** cursor)
{
    fn_80243E44(self, cursor);
    unsigned long length = (unsigned long)self->field88 - (unsigned long)self->field74 + 4;
    *cursor = fn_801E9F40(self->field74, *cursor, length);
}
