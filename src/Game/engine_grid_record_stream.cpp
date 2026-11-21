#include "Game/engine_grid_record_stream.h"

typedef char GridStreamRecordSize[sizeof(GridStreamRecord) == 20 ? 1 : -1];
typedef char GridStreamOwnerSize[sizeof(GridStreamOwner) == 0x40 ? 1 : -1];

extern "C" void fn_802668E0(GridStreamOwner* self, GridRecordStream* stream)
{
    stream->position = fn_801E9F40(self, stream->position,
        (char*)&self->freeCount - (char*)self + sizeof(int));
    self->heads.resize(self->columns * self->rows);
    stream->position = fn_801E9F40(self->heads.data, stream->position,
        self->rows * self->columns * sizeof(int));

    int count;
    stream->position = fn_801E9F40(&count, stream->position, 4);
    self->records.resize(count);
    for (int i = 0; i < count; i++) {
        stream->position = fn_801E9F40(&self->records.data[i].previous, stream->position,
            (char*)&self->records.data[i].cell -
            (char*)&self->records.data[i].previous + sizeof(int));
        stream->position = fn_801E9F40(&self->records.data[i].context, stream->position, 4);
    }
}
