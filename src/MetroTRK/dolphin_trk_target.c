/* C target initialization and address translation; native startup stays fallback. */
#include "targimpl_abi.h"

u32 gTRKLockedCacheBase;
extern void EnableEXI2Interrupts(void);

void EnableMetroTRKInterrupts(void)
{
    EnableEXI2Interrupts();
}

u32 TRKTargetTranslate(u32 addr)
{
    if (addr >= gTRKLockedCacheBase &&
        addr < gTRKLockedCacheBase + 0x4000 &&
        (gTRKCPUState.Extended1.DBAT3U & 3))
    {
        return addr;
    }
    return (addr & 0x3FFFFFFF) | 0x80000000;
}

DSError TRKInitializeTarget(void)
{
    gTRKState.stopped = true;
    gTRKState.MSR = __TRK_get_MSR();
    gTRKLockedCacheBase = 0xE0000000;
    return kNoError;
}
