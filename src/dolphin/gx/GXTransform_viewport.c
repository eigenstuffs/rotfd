#include "gx_abi.h"

void GXSetViewportJitter(f32 left, f32 top, f32 wd, f32 ht, f32 nearz,
                         f32 farz, u32 field)
{
    f32 sx;
    f32 sy;
    f32 sz;
    f32 ox;
    f32 oy;
    f32 oz;
    f32 zmin;
    f32 zmax;
    u32 reg;

    CHECK_GXBEGIN(0x340, "GXSetViewport"); // not the correct function name

    if (field == 0) {
        top -= 0.5f;
    }
    sx = wd / 2.0f;
    sy = -ht / 2.0f;
    ox = 342.0f + (left + (wd / 2.0f));
    oy = 342.0f + (top + (ht / 2.0f));
    zmin = 1.6777215e7f * nearz;
    zmax = 1.6777215e7f * farz;
    sz = zmax - zmin;
    oz = zmax;
    gx->vpLeft = left;
    gx->vpTop = top;
    gx->vpWd = wd;
    gx->vpHt = ht;
    gx->vpNearz = nearz;
    gx->vpFarz = farz;
    if (gx->fgRange != 0) {
        __GXSetRange(nearz, gx->fgSideX);
    }
    reg = 0x5101A;
    GX_WRITE_U8(0x10);
    GX_WRITE_U32(reg);
    GX_WRITE_XF_REG_F(26, sx);
    GX_WRITE_XF_REG_F(27, sy);
    GX_WRITE_XF_REG_F(28, sz);
    GX_WRITE_XF_REG_F(29, ox);
    GX_WRITE_XF_REG_F(30, oy);
    GX_WRITE_XF_REG_F(31, oz);
    gx->bpSent = 1;
}

void GXSetViewport(f32 left, f32 top, f32 wd, f32 ht, f32 nearz, f32 farz)
{
    GXSetViewportJitter(left, top, wd, ht, nearz, farz, 1U);
}

void GXSetScissor(u32 left, u32 top, u32 wd, u32 ht)
{
    u32 tp;
    u32 lf;
    u32 bm;
    u32 rt;

    CHECK_GXBEGIN(0x3B4, "GXSetScissor");

    ASSERTMSGLINE(0x3B5, left < 1708, "GXSetScissor: Left origin > 1708");
    ASSERTMSGLINE(0x3B6, top < 1708, "GXSetScissor: top origin > 1708");
    ASSERTMSGLINE(0x3B7, left + wd < 1708, "GXSetScissor: right edge > 1708");
    ASSERTMSGLINE(0x3B8, top + ht < 1708, "GXSetScissor: bottom edge > 1708");

    tp = top + 342;
    lf = left + 342;
    bm = tp + ht - 1;
    rt = lf + wd - 1;

    SET_REG_FIELD(0x3BF, gx->suScis0, 11, 0, tp);
    SET_REG_FIELD(0x3C0, gx->suScis0, 11, 12, lf);
    SET_REG_FIELD(0x3C2, gx->suScis1, 11, 0, bm);
    SET_REG_FIELD(0x3C3, gx->suScis1, 11, 12, rt);

    GX_WRITE_RAS_REG(gx->suScis0);
    GX_WRITE_RAS_REG(gx->suScis1);
    gx->bpSent = 0;
}

void GXSetScissorBoxOffset(s32 x_off, s32 y_off)
{
    u32 reg = 0;
    u32 hx;
    u32 hy;

    CHECK_GXBEGIN(0x3FB, "GXSetScissorBoxOffset");

    ASSERTMSGLINE(0x3FE, (u32) (x_off + 340) < 2048,
                  "GXSetScissorBoxOffset: x offset > 2048");
    ASSERTMSGLINE(0x400, (u32) (y_off + 340) < 2048,
                  "GXSetScissorBoxOffset: y offset > 2048");

    hx = (u32) (x_off + 342) >> 1;
    hy = (u32) (y_off + 342) >> 1;

    SET_REG_FIELD(0x405, reg, 10, 0, hx);
    SET_REG_FIELD(0x406, reg, 10, 10, hy);
    SET_REG_FIELD(0x407, reg, 8, 24, 0x59);
    GX_WRITE_RAS_REG(reg);
    gx->bpSent = 0;
}

void GXSetClipMode(GXClipMode mode)
{
    CHECK_GXBEGIN(0x41B, "GXSetClipMode");
    GX_WRITE_XF_REG(5, mode);
    gx->bpSent = 1;
}

void __GXSetMatrixIndex(GXAttr matIdxAttr)
{
    if (matIdxAttr < GX_VA_TEX4MTXIDX) {
        GX_WRITE_SOME_REG4(8, 0x30, gx->matIdxA, -12);
        GX_WRITE_XF_REG(24, gx->matIdxA);
    } else {
        GX_WRITE_SOME_REG4(8, 0x40, gx->matIdxB, -12);
        GX_WRITE_XF_REG(25, gx->matIdxB);
    }
    gx->bpSent = 1;
}
