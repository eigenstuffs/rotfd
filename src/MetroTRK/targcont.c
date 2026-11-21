/* MetroTRK target continuation, from the original target-control flow. */
#include "trk_abi.h"
extern void TRKTargetSetStopped(bool);
extern void UnreserveEXI2Port(void), ReserveEXI2Port(void), TRKSwapAndGo(void);

DSError TRKTargetContinue(void)
{
    TRKTargetSetStopped(false);
    UnreserveEXI2Port();
    TRKSwapAndGo();
    ReserveEXI2Port();
    return kNoError;
}
