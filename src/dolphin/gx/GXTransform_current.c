#include "gx_abi.h"

void GXSetCurrentMtx(u32 id)
{
    CHECK_GXBEGIN(0x2A1, "GXSetCurrentMtx");
    SET_REG_FIELD(0x2A5, gx->matIdxA, 6, 0, id);
    __GXSetMatrixIndex(GX_VA_PNMTXIDX);
}
