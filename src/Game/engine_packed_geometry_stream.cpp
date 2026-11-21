#include "Game/engine_packed_geometry_stream.h"

typedef char PackedStreamTripleSize[sizeof(PackedStreamTriple) == 6 ? 1 : -1];
typedef char PackedStreamOwnerSize[sizeof(PackedStreamOwner) == 0x84 ? 1 : -1];

extern "C" void fn_802647FC(PackedStreamOwner* self, PackedGeometryStream* stream)
{
    int count;
    stream->position = fn_801E9F40(&count, stream->position, 4);
    self->vertices.resize(count);
    stream->position = fn_801E9F40(self->vertices.data, stream->position,
        count * sizeof(PackedStreamTriple));

    stream->position = fn_801E9F40(&count, stream->position, 4);
    self->indices.resize(count);
    stream->position = fn_801E9F40(self->indices.data, stream->position,
        count * sizeof(unsigned short));

    stream->position = fn_801E9F40(&count, stream->position, 4);
    self->flags.resize(count);
    stream->position = fn_801E9F40(self->flags.words.data, stream->position,
        self->flags.words.count * sizeof(PackedStreamWord));
    stream->position = fn_801E9F40(&self->first, stream->position,
        (char*)&self->last - (char*)&self->first + sizeof(PackedStreamVector));
}
