/* MetroTRK serial-console option; source family: Pikmin 2 target_options.c. */
#include "trk_abi.h"
static u8 bUseSerialIO;

void SetUseSerialIO(u8 enabled)
{
    bUseSerialIO = enabled;
}

u8 GetUseSerialIO(void)
{
    return bUseSerialIO;
}
