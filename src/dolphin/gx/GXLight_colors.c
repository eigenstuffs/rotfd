/* Dolphin GX lighting C fragment. See docs/notes/GXLight.md. */
#include "gx_abi.h"
void GXSetChanAmbColor(GXChannelID chan, GXColor amb_color)
{
    u32 reg = 0;
    u32 colIdx;
    u32 alpha;

    CHECK_GXBEGIN(0x239, "GXSetChanAmbColor");

    switch (chan) {
    case GX_COLOR0:
        alpha = gx->ambColor[0];
        reg = __rlwimi(*(u32 *)&amb_color & ~0xFF, alpha, 0, 24, 31);
        colIdx = 0;
        break;
    case GX_COLOR1:
        alpha = gx->ambColor[1];
        reg = __rlwimi(*(u32 *)&amb_color & ~0xFF, alpha, 0, 24, 31);
        colIdx = 1;
        break;
    case GX_ALPHA0:
        reg = gx->ambColor[0];
        SET_REG_FIELD(0x250, reg, 8, 0, amb_color.a);
        colIdx = 0;
        break;
    case GX_ALPHA1:
        reg = gx->ambColor[1];
        SET_REG_FIELD(0x256, reg, 8, 0, amb_color.a);
        colIdx = 1;
        break;
    case GX_COLOR0A0:
        reg = *(u32 *)&amb_color;
        colIdx = 0;
        break;
    case GX_COLOR1A1:
        reg = *(u32 *)&amb_color;
        colIdx = 1;
        break;
    default:
        ASSERTMSGLINE(0x26B, 0, "GXSetChanAmbColor: Invalid Channel Id");
        return;
    }

    GX_WRITE_XF_REG(colIdx + 10, reg);
    gx->bpSent = 1;
    gx->ambColor[colIdx] = reg;
}

void GXSetChanMatColor(GXChannelID chan, GXColor mat_color)
{
    u32 reg = 0;
    u32 alpha;
    u32 colIdx;

    CHECK_GXBEGIN(0x28A, "GXSetChanMatColor");

    switch (chan) {
    case GX_COLOR0:
        alpha = gx->matColor[0];
        reg = __rlwimi(*(u32 *)&mat_color & ~0xFF, alpha, 0, 24, 31);
        colIdx = 0;
        break;
    case GX_COLOR1:
        alpha = gx->matColor[1];
        reg = __rlwimi(*(u32 *)&mat_color & ~0xFF, alpha, 0, 24, 31);
        colIdx = 1;
        break;
    case GX_ALPHA0:
        reg = gx->matColor[0];
        SET_REG_FIELD(0x2A1, reg, 8, 0, mat_color.a);
        colIdx = 0;
        break;
    case GX_ALPHA1:
        reg = gx->matColor[1];
        SET_REG_FIELD(0x2A7, reg, 8, 0, mat_color.a);
        colIdx = 1;
        break;
    case GX_COLOR0A0:
        reg = *(u32 *)&mat_color;
        colIdx = 0;
        break;
    case GX_COLOR1A1:
        reg = *(u32 *)&mat_color;
        colIdx = 1;
        break;
    default:
        ASSERTMSGLINE(0x2BC, 0, "GXSetChanMatColor: Invalid Channel Id");
        return;
    }

    GX_WRITE_XF_REG(colIdx + 12, reg);
    gx->bpSent = 1;
    gx->matColor[colIdx] = reg;
}

