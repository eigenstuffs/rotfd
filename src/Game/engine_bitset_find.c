#include "Game/engine_bitset_find.h"

static inline int firstBit(unsigned int value)
{
    int result = 0;
    unsigned int mask = value & -value;
    if (mask & 0xFFFF0000)
        result = 16;
    if (mask & 0xFF00FF00)
        result += 8;
    if (mask & 0xF0F0F0F0)
        result += 4;
    if (mask & 0xCCCCCCCC)
        result += 2;
    if (mask & 0xAAAAAAAA)
        result += 1;
    return result;
}

int fn_80207B94(EngineBitsetFind *self, signed char state, int start)
{
    int bitCount = self->bitCount;
    int count;
    int shift;
    int value;
    if (start >= bitCount)
        return -1;
    count = self->wordCount;
    shift = start & 31;
    start >>= 5;
    if (shift) {
        unsigned int mask = 1U << shift;
        value = self->words[start];
        if (!state)
            value = ~value;
        value &= ~(mask - 1);
        if (value) {
            int result = (start << 5) + firstBit(value);
            if (result >= bitCount)
                return -1;
            return result;
        }
        start++;
    }
    if (state) {
        while (start < count && (value = self->words[start]) == 0)
            start++;
        if (start < count) {
            int result = (start << 5) + firstBit(value);
            if (result >= bitCount)
                return -1;
            return result;
        }
    } else {
        while (start < count && (value = ~self->words[start]) == 0)
            start++;
        if (start < count) {
            int result = (start << 5) + firstBit(value);
            if (result >= bitCount)
                return -1;
            return result;
        }
    }
    return -1;
}
