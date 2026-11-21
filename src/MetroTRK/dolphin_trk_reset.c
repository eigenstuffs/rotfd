/* C exception-vector installation from the Dolphin MetroTRK source family. */
#include "targimpl_abi.h"
extern u32 gTRKLockedCacheBase;
extern u8 gTRKInterruptVectorTable[];

static u32 TRK_ISR_OFFSETS[15] = {
    0x100, 0x200, 0x300, 0x400, 0x500, 0x600, 0x700, 0x800,
    0x900, 0xC00, 0xD00, 0xF00, 0x1300, 0x1400, 0x1700
};

static inline u32 TRKTranslateVectorAddress(u32 addr)
{
    if (addr >= gTRKLockedCacheBase &&
        addr < gTRKLockedCacheBase + 0x4000 &&
        (gTRKCPUState.Extended1.DBAT3U & 3))
    {
        return addr;
    }
    return (addr & 0x3FFFFFFF) | 0x80000000;
}

static inline void TRK_copy_vector(u32 offset)
{
    u32 destPtr = TRKTranslateVectorAddress(offset);
    TRK_memcpy((void*)destPtr, gTRKInterruptVectorTable + offset, 0x100);
    TRK_flush_cache(destPtr, 0x100);
}

static inline void __TRK_copy_vectors(void)
{
    int i;
    u32 mask;
    mask = *(u32*)TRKTranslateVectorAddress(0x44);
    for (i = 0; i <= 14; i++) {
        if ((mask & (1 << i)) != 0) {
            TRK_copy_vector(TRK_ISR_OFFSETS[i]);
        }
    }
}

__declspec(section ".init") void __TRK_reset(void)
{
    __TRK_copy_vectors();
}
