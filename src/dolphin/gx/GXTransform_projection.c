#include "gx_abi.h"

void GXSetProjection(f32 mtx[4][4], GXProjectionType type)
{
    u32 reg;

    CHECK_GXBEGIN(0xCD, "GXSetProjection");

    gx->projType = type;
    gx->projMtx[0] = mtx[0][0];
    gx->projMtx[2] = mtx[1][1];
    gx->projMtx[4] = mtx[2][2];
    gx->projMtx[5] = mtx[2][3];
    if (type == GX_ORTHOGRAPHIC) {
        gx->projMtx[1] = mtx[0][3];
        gx->projMtx[3] = mtx[1][3];
    } else {
        gx->projMtx[1] = mtx[0][2];
        gx->projMtx[3] = mtx[1][2];
    }

    reg = 0x00061020;
    GX_WRITE_U8(0x10);
    GX_WRITE_U32(reg);
    GX_WRITE_XF_REG_F(32, gx->projMtx[0]);
    GX_WRITE_XF_REG_F(33, gx->projMtx[1]);
    GX_WRITE_XF_REG_F(34, gx->projMtx[2]);
    GX_WRITE_XF_REG_F(35, gx->projMtx[3]);
    GX_WRITE_XF_REG_F(36, gx->projMtx[4]);
    GX_WRITE_XF_REG_F(37, gx->projMtx[5]);
    GX_WRITE_XF_REG_2(38, gx->projType);
    gx->bpSent = 1;
}

void GXSetProjectionv(f32* ptr)
{
    u32 reg;

    CHECK_GXBEGIN(0x109, "GXSetProjectionv");

    gx->projType = ptr[0];
    gx->projMtx[0] = ptr[1];
    gx->projMtx[1] = ptr[2];
    gx->projMtx[2] = ptr[3];
    gx->projMtx[3] = ptr[4];
    gx->projMtx[4] = ptr[5];
    gx->projMtx[5] = ptr[6];

    reg = 0x00061020;
    GX_WRITE_U8(0x10);
    GX_WRITE_U32(reg);
    GX_WRITE_XF_REG_F(32, gx->projMtx[0]);
    GX_WRITE_XF_REG_F(33, gx->projMtx[1]);
    GX_WRITE_XF_REG_F(34, gx->projMtx[2]);
    GX_WRITE_XF_REG_F(35, gx->projMtx[3]);
    GX_WRITE_XF_REG_F(36, gx->projMtx[4]);
    GX_WRITE_XF_REG_F(37, gx->projMtx[5]);
    GX_WRITE_XF_REG_2(38, gx->projType);
    gx->bpSent = 1;
}
