#include "Game/bitset_internal.h"
BitSet_80207EE8::~BitSet_80207EE8() {}

extern "C" void fn_80207DE4(BitSet_80207EE8* self, int start, int end)
{
    int firstWord = start >> 5;
    int lastWord = end >> 5;
    u32 firstMask = (1 << (start & 31)) - 1;
    u32 lastMask = ~(((1 << (end & 31)) << 1) - 1);
    self->data[firstWord] &= firstMask;
    if (firstWord < lastWord) {
        for (++firstWord; firstWord < lastWord; ++firstWord)
            self->data[firstWord] = 0;
    }
    self->data[lastWord] &= lastMask;
}

