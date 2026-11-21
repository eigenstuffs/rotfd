/* Dolphin GX TEV stage-count C fragment. See docs/notes/GXTev.md. */
#include "gx_abi.h"

void GXSetNumTevStages(u8 nStages)
{
    CHECK_GXBEGIN(0x331, "GXSetNumTevStages");

    ASSERTMSGLINE(0x333, nStages != 0 && nStages <= 16,
                  "GXSetNumTevStages: Exceed max number of tex stages");
    SET_REG_FIELD(0x334, gx->genMode, 4, 10, nStages - 1);
    gx->dirtyState |= 4;
}
