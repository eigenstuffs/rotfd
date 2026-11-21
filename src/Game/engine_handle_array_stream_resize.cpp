#include "Game/engine_handle_array_stream_resize.h"

struct HandleStreamGlobals { char unknown[0x118]; void* manager; };
extern "C" HandleStreamGlobals lbl_801E9D24;

typedef char HandleStreamValueSize[sizeof(HandleStreamValue) == 4 ? 1 : -1];
typedef char HandleStreamOwnerSize[sizeof(HandleStreamOwner) == 24 ? 1 : -1];

extern "C" void fn_802642C4(HandleStreamOwner* self, HandleArrayStream* stream)
{
    self->BaseObject_Z::slot0C((HandleStreamWord)stream);
    int count;
    stream->position = fn_801E9F40(&count, stream->position, 4);
    self->handles.resize(count);
    self->handles.resize(count);
    for (int i = 0; i < count; i++)
        fn_801B3FD0(lbl_801E9D24.manager, &self->handles.data[i], stream);
}
