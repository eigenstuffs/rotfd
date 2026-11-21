/* Dolphin SDK GXLight.c light load and channel colors, GSQE78.
 * GXLoadLightObjImm uses the SDK's inlined PushLight paired-single copy
 * (an asm block over register locals); see docs/notes/GXLight.md.
 */
#include "gx_abi.h"

typedef struct {
    u32 reserved[3];
    u32 Color;
    f32 a[3];
    f32 k[3];
    f32 lpos[3];
    f32 ldir[3];
} GXLightObjInt;

static inline void PushLight(const register GXLightObjInt* lt_obj, register void* dest)
{
    register u32 zero, color;
    register f32 a0_a1, a2_k0, k1_k2;
    register f32 px_py, pz_dx, dy_dz;
    /* clang-format off */
    asm {
        lwz color, 12(lt_obj)
        xor zero, zero, zero
        psq_l a0_a1, 16(lt_obj), 0, 0
        psq_l a2_k0, 24(lt_obj), 0, 0
        psq_l k1_k2, 32(lt_obj), 0, 0
        psq_l px_py, 40(lt_obj), 0, 0
        psq_l pz_dx, 48(lt_obj), 0, 0
        psq_l dy_dz, 56(lt_obj), 0, 0
        stw zero, 0(dest)
        stw zero, 0(dest)
        stw zero, 0(dest)
        stw color, 0(dest)
        psq_st a0_a1, 0(dest), 0, 0
        psq_st a2_k0, 0(dest), 0, 0
        psq_st k1_k2, 0(dest), 0, 0
        psq_st px_py, 0(dest), 0, 0
        psq_st pz_dx, 0(dest), 0, 0
        psq_st dy_dz, 0(dest), 0, 0
    }
    /* clang-format on */
}

void GXLoadLightObjImm(GXLightObj* lt_obj, GXLightID light)
{
    u32 addr;
    u32 idx;
    GXLightObjInt* obj;

    obj = (GXLightObjInt*)lt_obj;
    idx = 31 - __cntlzw(light);
    idx &= 7;
    addr = 0x600 + idx * 0x10;

    GX_WRITE_U8(0x10);
    GX_WRITE_U32(addr | ((0x10 - 1) << 16));

    PushLight(obj, (void*)&GXWGFifo);
    gx->bpSent = 1;
}

void GXSetChanAmbColor(GXChannelID chan, GXColor amb_color)
{
    u32 reg;
    u32 colIdx;

    switch (chan) {
    case GX_COLOR0:
        reg = gx->ambColor[GX_COLOR0];
        reg = (reg & ~(0xFFFFFF << 8)) | ((*(u32*)&amb_color >> 8) << 8);
        colIdx = 0;
        break;
    case GX_COLOR1:
        reg = gx->ambColor[GX_COLOR1];
        reg = (reg & ~(0xFFFFFF << 8)) | ((*(u32*)&amb_color >> 8) << 8);
        colIdx = 1;
        break;
    case GX_ALPHA0:
        reg = gx->ambColor[GX_COLOR0];
        reg = (reg & 0xFFFFFF00) | amb_color.a;
        colIdx = 0;
        break;
    case GX_ALPHA1:
        reg = gx->ambColor[GX_COLOR1];
        reg = (reg & 0xFFFFFF00) | amb_color.a;
        colIdx = 1;
        break;
    case GX_COLOR0A0:
        reg = *(u32*)&amb_color;
        colIdx = 0;
        break;
    case GX_COLOR1A1:
        reg = *(u32*)&amb_color;
        colIdx = 1;
        break;
    default:
        return;
    }

    GX_WRITE_XF_REG(colIdx + 10, reg);
    gx->bpSent = 1;
    gx->ambColor[colIdx] = reg;
}

void GXSetChanMatColor(GXChannelID chan, GXColor mat_color)
{
    u32 reg;
    u32 colIdx;

    switch (chan) {
    case GX_COLOR0:
        reg = gx->matColor[GX_COLOR0];
        reg = (reg & ~(0xFFFFFF << 8)) | ((*(u32*)&mat_color >> 8) << 8);
        colIdx = 0;
        break;
    case GX_COLOR1:
        reg = gx->matColor[GX_COLOR1];
        reg = (reg & ~(0xFFFFFF << 8)) | ((*(u32*)&mat_color >> 8) << 8);
        colIdx = 1;
        break;
    case GX_ALPHA0:
        reg = gx->matColor[GX_COLOR0];
        reg = (reg & 0xFFFFFF00) | mat_color.a;
        colIdx = 0;
        break;
    case GX_ALPHA1:
        reg = gx->matColor[GX_COLOR1];
        reg = (reg & 0xFFFFFF00) | mat_color.a;
        colIdx = 1;
        break;
    case GX_COLOR0A0:
        reg = *(u32*)&mat_color;
        colIdx = 0;
        break;
    case GX_COLOR1A1:
        reg = *(u32*)&mat_color;
        colIdx = 1;
        break;
    default:
        return;
    }

    GX_WRITE_XF_REG(colIdx + 12, reg);
    gx->bpSent = 1;
    gx->matColor[colIdx] = reg;
}
