#include "Game/engine_stream_layers.h"

extern "C" void fn_80243DE4(EngineStreamLayerView* self, void** cursor)
{
    slot0C__12BaseObject_ZFUl(self, cursor);
    *cursor = fn_801E9F40(self->field0C, *cursor, 4);
    *cursor = fn_801E9F40(self->field10, *cursor, 0x10);
}
