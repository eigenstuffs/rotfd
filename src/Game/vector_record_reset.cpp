#include "Game/vector_record_reset_internal.h"

extern "C" void fn_8027C40C(ResetView* self, const ResetVector* v)
{
    for (int i = 0; i < self->count; ++i) {
        self->records[i].a.assign(*v);
        self->records[i].b.assign(*v);
        self->records[i].c.assign(*v);
        self->records[i].d.assign(*v);
        self->flags[i].state = 0xFFFF;
    }
}
