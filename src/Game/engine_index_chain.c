#include "Game/engine_index_chain.h"

EngineIndexChainRange fn_8020C8CC(EngineIndexChainOwner *self, short first, short count)
{
    EngineIndexChainRange range;
    int i;

    range.first = first;
    range.count = count;
    range.last = first + count - 1;

    for (i = range.first; i <= range.last; ++i) {
        *(short *)(self->records + i * 0x8C + 0x88) = i - 1;
        *(short *)(self->records + i * 0x8C + 0x8A) = i + 1;
    }
    *(short *)(self->records + range.first * 0x8C + 0x88) = -1;
    *(short *)(self->records + range.last * 0x8C + 0x8A) = -1;
    return range;
}
