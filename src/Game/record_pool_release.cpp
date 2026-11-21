// Release an occupied record and return its slot to the pool.
#include "record_pool_internal.h"

static inline const u32& occupiedWord(const BitSet_80207EE8& occupied, int index) {
    const u32* base = occupied.data;
    return base[index];
}
static inline signed char isOccupied(const BitSet_80207EE8& occupied, int index) {
    return (occupiedWord(occupied, index >> 5) & (1UL << (index & 31))) ? 1 : 0;
}
static inline void clearOccupied(BitSet_80207EE8& occupied, int index) {
    u32 mask = 1UL << (index & 31);
    u32 word = occupied.data[index >> 5];
    word &= ~mask;
    occupied.data[index >> 5] = word;
}
extern "C" signed char fn_80209DF8(RecordPool_80209D30* self, int index) {
    if (isOccupied(self->occupied, index)) {
        self->data[index].~Record_80209EA0();
        clearOccupied(self->occupied, index);
        --self->live;
        return 1;
    }
    return 0;
}
