/* Dolphin GX lighting C fragment. See docs/notes/GXLight.md. */
#include "gx_abi.h"
void GXSetNumChans(u8 nChans)
{
    CHECK_GXBEGIN(0x2D5, "GXSetNumChans");
    ASSERTMSGLINE(0x2D6, nChans <= 2, "GXSetNumChans: nChans > 2");

    SET_REG_FIELD(0x2D8, gx->genMode, 3, 4, nChans);
    GX_WRITE_XF_REG(9, nChans);
    gx->dirtyState |= 4;
}

void GXSetChanCtrl(GXChannelID chan, GXBool enable, GXColorSrc amb_src,
                   GXColorSrc mat_src, u32 light_mask, GXDiffuseFn diff_fn,
                   GXAttnFn attn_fn)
{
    u32 reg; // r31
    u32 idx; // r26

    CHECK_GXBEGIN(0x2F8, "GXSetChanCtrl");

    ASSERTMSGLINE(0x2FB, chan >= 0 && chan <= 5,
                  "GXSetChanCtrl: Invalid Channel Id");

    idx = (u32)chan & 3;

    reg = 0;
    SET_REG_FIELD(0x302, reg, 1, 1, enable);
    SET_REG_FIELD(0x303, reg, 1, 0, mat_src);
    SET_REG_FIELD(0x304, reg, 1, 6, amb_src);
    SET_REG_FIELD(0x30E, reg, 2, 7, (attn_fn == 0) ? 0 : diff_fn);
    SET_REG_FIELD(0x30F, reg, 1, 9, (attn_fn != 2));
    SET_REG_FIELD(0x310, reg, 1, 10, (attn_fn != 0));

    reg = (reg & ~(0xF << 2)) | ((light_mask & 0xF) << 2);
    reg = (reg & ~(0xF << 11)) | (((light_mask >> 4) & 0xF) << 11);

    GX_WRITE_XF_REG(idx + 14, reg);
    if (chan == GX_COLOR0A0) {
        GX_WRITE_XF_REG(16, reg);
    } else if (chan == GX_COLOR1A1) {
        GX_WRITE_XF_REG(17, reg);
    }
    gx->bpSent = 1;
}
