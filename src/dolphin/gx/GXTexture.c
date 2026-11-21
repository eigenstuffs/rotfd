/* Dolphin GX texture state. See docs/notes/GXTexture.md. */
#include "gx_abi.h"
extern void *memset(void *, int, unsigned long);
// GXTexObj internal data
typedef struct __GXTexObjInt_struct {
    u32 mode0;
    u32 mode1;
    u32 image0;
    u32 image3;
    void *userData;
    GXTexFmt fmt;
    u32 tlutName;
    u16 loadCnt;
    u8 loadFmt;
    u8 flags;
} __GXTexObjInt;

// GXTexRegion internal data
typedef struct __GXTexRegionInt_struct {
    u32 image1;
    u32 image2;
    u16 sizeEven;
    u16 sizeOdd;
    u8 is32bMipmap;
    u8 isCached;
} __GXTexRegionInt;

// GXTlutObj internal data
typedef struct __GXTlutObjInt_struct {
    u32 tlut;
    u32 loadTlut0;
    u16 numEntries;
} __GXTlutObjInt;

// GXTlutRegion internal data
typedef struct __GXTlutRegionInt_struct {
    u32 loadTlut1;
    __GXTlutObjInt tlutObj;
} __GXTlutRegionInt;

u8 GXTexMode0Ids[8] = { 0x80, 0x81, 0x82, 0x83, 0xA0, 0xA1, 0xA2, 0xA3 };
u8 GXTexMode1Ids[8] = { 0x84, 0x85, 0x86, 0x87, 0xA4, 0xA5, 0xA6, 0xA7 };
u8 GXTexImage0Ids[8] = { 0x88, 0x89, 0x8A, 0x8B, 0xA8, 0xA9, 0xAA, 0xAB };
u8 GXTexImage1Ids[8] = { 0x8C, 0x8D, 0x8E, 0x8F, 0xAC, 0xAD, 0xAE, 0xAF };
u8 GXTexImage2Ids[8] = { 0x90, 0x91, 0x92, 0x93, 0xB0, 0xB1, 0xB2, 0xB3 };
u8 GXTexImage3Ids[8] = { 0x94, 0x95, 0x96, 0x97, 0xB4, 0xB5, 0xB6, 0xB7 };
u8 GXTexTlutIds[8] = { 0x98, 0x99, 0x9A, 0x9B, 0xB8, 0xB9, 0xBA, 0xBB };
static u8 GX2HWFiltConv[6] = { 0x00, 0x04, 0x01, 0x05, 0x02, 0x06 };

static inline void __GXGetTexTileShift(GXTexFmt fmt, u32 *rowTileS, u32 *colTileS)
{
    switch (fmt) {
    case GX_TF_I4:
    case 0x8:
    case GX_TF_CMPR:
    case GX_CTF_R4:
    case GX_CTF_Z4:
        *rowTileS = 3;
        *colTileS = 3;
        break;
    case GX_TF_I8:
    case GX_TF_IA4:
    case 0x9:
    case GX_TF_Z8:
    case GX_CTF_RA4:
    case GX_TF_A8:
    case GX_CTF_R8:
    case GX_CTF_G8:
    case GX_CTF_B8:
    case GX_CTF_Z8M:
    case GX_CTF_Z8L:
        *rowTileS = 3;
        *colTileS = 2;
        break;
    case GX_TF_IA8:
    case GX_TF_RGB565:
    case GX_TF_RGB5A3:
    case GX_TF_RGBA8:
    case 0xA:
    case GX_TF_Z16:
    case GX_TF_Z24X8:
    case GX_CTF_RA8:
    case GX_CTF_RG8:
    case GX_CTF_GB8:
    case GX_CTF_Z16L:
        *rowTileS = 2;
        *colTileS = 2;
        break;
    default:
        *rowTileS = *colTileS = 0;
        break;
    }
}

void __GetImageTileCount(enum _GXTexFmt fmt, u16 wd, u16 ht, u32 *rowTiles, u32 *colTiles, u32 *cmpTiles)
{
    u32 texRowShift;
    u32 texColShift;

    __GXGetTexTileShift(fmt, &texRowShift, &texColShift);
    if (wd == 0) {
        wd = 1;
    }
    if (ht == 0) {
        ht = 1;
    }
    *rowTiles = (wd + (1 << texRowShift) - 1) >> texRowShift;
    *colTiles = (ht + (1 << texColShift) - 1) >> texColShift;
    *cmpTiles = (fmt == GX_TF_RGBA8 || fmt == GX_TF_Z24X8) ? 2 : 1;
}

void GXInitTexObj(GXTexObj *obj, void *image_ptr, u16 width, u16 height, GXTexFmt format, GXTexWrapMode wrap_s, GXTexWrapMode wrap_t, u8 mipmap)
{
    u32 imageBase;
    u32 maxLOD;
    u16 rowT;
    u16 colT;
    u32 rowC;
    u32 colC;
    __GXTexObjInt *t = (__GXTexObjInt *)obj;

    ASSERTMSGLINE(0x1FD, obj, "Texture Object Pointer is null");
    CHECK_GXBEGIN(0x1FF, "GXInitTexObj");
#if DEBUG
    if (wrap_s != GX_CLAMP || mipmap != 0) {
        u32 mask = 1 << (31 - __cntlzw(width));
    }
    if (wrap_t != GX_CLAMP || mipmap != 0) {
        u32 mask = 1 << (31 - __cntlzw(height));
    }
#endif
    memset(t, 0, 0x20);
    SET_REG_FIELD(0x220, t->mode0, 2, 0, wrap_s);
    SET_REG_FIELD(0x221, t->mode0, 2, 2, wrap_t);
    SET_REG_FIELD(0x222, t->mode0, 1, 4, 1);
    if (mipmap != 0) {
        u8 lmax;
        t->flags |= 1;
        if (format - 8 <= 2U) {
            t->mode0 = (t->mode0 & 0xFFFFFF1F) | 0xA0;
        } else {
            t->mode0 = (t->mode0 & 0xFFFFFF1F) | 0xC0;
        }
        if (width > height) {
            maxLOD = 31 - __cntlzw(width);
        } else {
            maxLOD = 31 - __cntlzw(height);
        }
        lmax = 16.0f * maxLOD;
        SET_REG_FIELD(0x234, t->mode1, 8, 8, lmax);
    } else {
        t->mode0 = (t->mode0 & 0xFFFFFF1F) | 0x80;
    }
    t->fmt = format;
    SET_REG_FIELD(0x240, t->image0, 10, 0, width - 1);
    SET_REG_FIELD(0x241, t->image0, 10, 10, height - 1);
    SET_REG_FIELD(0x242, t->image0, 4, 20, format & 0xF);
    imageBase = (u32)((u32)image_ptr >> 5) & 0x01FFFFFF;
    SET_REG_FIELD(0x24A, t->image3, 21, 0, imageBase);
    switch (format & 0xF) {
    case 0:
    case 8:
        t->loadFmt = 1;
        rowT = 3;
        colT = 3;
        break;
    case 1:
    case 2:
    case 9:
        t->loadFmt = 2;
        rowT = 3;
        colT = 2;
        break;
    case 3:
    case 4:
    case 5:
    case 10:
        t->loadFmt = 2;
        rowT = 2;
        colT = 2;
        break;
    case 6:
        t->loadFmt = 3;
        rowT = 2;
        colT = 2;
        break;
    case 14:
        t->loadFmt = 0;
        rowT = 3;
        colT = 3;
        break;
    default:
        t->loadFmt = 2;
        rowT = 2;
        colT = 2;
        break;
    }
    rowC = (width + (1 << rowT) - 1) >> rowT;
    colC = (height + (1 << colT) - 1) >> colT;
    t->loadCnt = (rowC * colC) & 0x7FFF;
    t->flags |= 2;
}

void GXInitTexObjCI(GXTexObj *obj, void *image_ptr, u16 width, u16 height, GXTexFmt format, GXTexWrapMode wrap_s, GXTexWrapMode wrap_t, u8 mipmap, u32 tlut_name)
{
    __GXTexObjInt *t = (__GXTexObjInt *)obj;

    ASSERTMSGLINE(0x29B, obj, "Texture Object Pointer is null");
    CHECK_GXBEGIN(0x29D, "GXInitTexObjCI");
    GXInitTexObj(obj, image_ptr, width, height, format, wrap_s, wrap_t, mipmap);
    t->flags &= 0xFFFFFFFD;
    t->tlutName = tlut_name;
}

void GXInitTexObjLOD(GXTexObj *obj, GXTexFilter min_filt, GXTexFilter mag_filt, f32 min_lod, f32 max_lod, f32 lod_bias, u8 bias_clamp, u8 do_edge_lod, GXAnisotropy max_aniso)
{
    u8 lbias;
    u8 lmin;
    u8 lmax;
    __GXTexObjInt *t = (__GXTexObjInt *)obj;

    ASSERTMSGLINE(0x2C2, obj, "Texture Object Pointer is null");
    CHECK_GXBEGIN(0x2C4, "GXInitTexObjLOD");

    if (lod_bias < -4.0f) {
        lod_bias = -4.0f;
    } else if (lod_bias >= 4.0f) {
        lod_bias = 3.99f;
    }
    lbias = 32.0f * lod_bias;
    SET_REG_FIELD(0x2CE, t->mode0, 8, 9, lbias);
    SET_REG_FIELD(0x2CF, t->mode0, 1, 4, (mag_filt == GX_LINEAR) ? 1 : 0);
    ASSERTMSGLINE(0x2D1, (u32)min_filt <= 5, "GXInitTexObjLOD: invalid min_filt value");
    SET_REG_FIELD(0x2D2, t->mode0, 3, 5, GX2HWFiltConv[min_filt]);
    SET_REG_FIELD(0x2D3, t->mode0, 1, 8, do_edge_lod ? 0 : 1);
    t->mode0 &= 0xFFFDFFFF;
    t->mode0 &= 0xFFFBFFFF;
    SET_REG_FIELD(0x2D6, t->mode0, 2, 19, max_aniso);
    SET_REG_FIELD(0x2D7, t->mode0, 1, 21, bias_clamp);
    if (min_lod < 0.0f) {
        min_lod = 0.0f;
    } else if (min_lod > 10.0f) {
        min_lod = 10.0f;
    }
    lmin = 16.0f * min_lod;
    if (max_lod < 0.0f) {
        max_lod = 0.0f;
    } else if (max_lod > 10.0f) {
        max_lod = 10.0f;
    }
    lmax = 16.0f * max_lod;
    SET_REG_FIELD(0x2E5, t->mode1, 8, 0, lmin);
    SET_REG_FIELD(0x2E6, t->mode1, 8, 8, lmax);
}

void GXInitTexObjWrapMode(GXTexObj *obj, GXTexWrapMode sm, GXTexWrapMode tm)
{
    __GXTexObjInt *t = (__GXTexObjInt *)obj;

    ASSERTMSGLINE(0x313, obj, "Texture Object Pointer is null");
    CHECK_GXBEGIN(0x315, "GXInitTexObjWrapMode");
    SET_REG_FIELD(0x317, t->mode0, 2, 0, sm);
    SET_REG_FIELD(0x318, t->mode0, 2, 2, tm);
}

GXTexFmt GXGetTexObjFmt(const GXTexObj *to)
{
    const __GXTexObjInt *t = (const __GXTexObjInt *)to;

    ASSERTMSGLINE(0x378, to, "Texture Object Pointer is null");
    return t->fmt;
}

void GXLoadTexObjPreLoaded(GXTexObj *obj, GXTexRegion *region, GXTexMapID id)
{
    __GXTlutRegionInt *tlr;
    __GXTexObjInt *t = (__GXTexObjInt *)obj;
    __GXTexRegionInt *r = (__GXTexRegionInt *)region;

    ASSERTMSGLINE(0x3FE, obj, "Texture Object Pointer is null");
    ASSERTMSGLINE(0x3FE, region, "TexRegion Object Pointer is null");
    CHECK_GXBEGIN(0x400, "GXLoadTexObjPreLoaded");

    SET_REG_FIELD(0x403, t->mode0, 8, 24, GXTexMode0Ids[id]);
    SET_REG_FIELD(0x404, t->mode1, 8, 24, GXTexMode1Ids[id]);
    SET_REG_FIELD(0x405, t->image0, 8, 24, GXTexImage0Ids[id]);
    SET_REG_FIELD(0x406, r->image1, 8, 24, GXTexImage1Ids[id]);
    SET_REG_FIELD(0x407, r->image2, 8, 24, GXTexImage2Ids[id]);
    SET_REG_FIELD(0x408, t->image3, 8, 24, GXTexImage3Ids[id]);

    GX_WRITE_RAS_REG(t->mode0);
    GX_WRITE_RAS_REG(t->mode1);
    GX_WRITE_RAS_REG(t->image0);
    GX_WRITE_RAS_REG(r->image1);
    GX_WRITE_RAS_REG(r->image2);
    GX_WRITE_RAS_REG(t->image3);

    if (!(t->flags & 2)) {
        tlr = (__GXTlutRegionInt *)gx->tlutRegionCallback(t->tlutName);

        SET_REG_FIELD(0x417, tlr->tlutObj.tlut, 8, 24, GXTexTlutIds[id]);
        GX_WRITE_RAS_REG(tlr->tlutObj.tlut);
    }
    gx->tImage0[id] = t->image0;
    gx->tMode0[id] = t->mode0;
    gx->dirtyState |= 1;
    gx->bpSent = 0;
}

void GXLoadTexObj(GXTexObj *obj, GXTexMapID id)
{
    GXTexRegion *r;

    CHECK_GXBEGIN(0x432, "GXLoadTexObj");
    r = gx->texRegionCallback(obj, id);
    GXLoadTexObjPreLoaded(obj, r, id);
}

void GXInitTlutObj(GXTlutObj *tlut_obj, void *lut, GXTlutFmt fmt, u16 n_entries)
{
    __GXTlutObjInt *t = (__GXTlutObjInt *)tlut_obj;

    ASSERTMSGLINE(0x452, tlut_obj, "TLut Object Pointer is null");
    CHECK_GXBEGIN(0x453, "GXInitTlutObj");
    t->tlut = 0;
    SET_REG_FIELD(0x45B, t->tlut, 2, 10, fmt);
    SET_REG_FIELD(0x45C, t->loadTlut0, 21, 0, ((u32)lut & 0x3FFFFFFF) >> 5);
    SET_REG_FIELD(0x45D, t->loadTlut0, 8, 24, 0x64);
    t->numEntries = n_entries;
}

void GXLoadTlut(GXTlutObj *tlut_obj, u32 tlut_name)
{
    __GXTlutRegionInt *r;
    u32 tlut_offset;
    __GXTlutObjInt *t = (__GXTlutObjInt *)tlut_obj;

    ASSERTMSGLINE(0x4A4, tlut_obj, "TLut Object Pointer is null");
    CHECK_GXBEGIN(0x4A6, "GXLoadTlut");
    r = (__GXTlutRegionInt *)gx->tlutRegionCallback(tlut_name);
    __GXFlushTextureState();
    GX_WRITE_RAS_REG(t->loadTlut0);
    GX_WRITE_RAS_REG(r->loadTlut1);
    __GXFlushTextureState();
    tlut_offset = r->loadTlut1 & 0x3FF;
    SET_REG_FIELD(0x4B9, t->tlut, 10, 0, tlut_offset);
    r->tlutObj = *t;
}

void GXInitTexCacheRegion(GXTexRegion *region, u8 is_32b_mipmap, u32 tmem_even, GXTexCacheSize size_even, u32 tmem_odd, GXTexCacheSize size_odd)
{
    u32 WidthExp2;
    __GXTexRegionInt *t = (__GXTexRegionInt *)region;

    ASSERTMSGLINE(0x4D8, region, "TexRegion Object Pointer is null");
    CHECK_GXBEGIN(0x4DA, "GXInitTexCacheRegion");
    switch (size_even) {
    case GX_TEXCACHE_32K:
        WidthExp2 = 3;
        break;
    case GX_TEXCACHE_128K:
        WidthExp2 = 4;
        break;
    case GX_TEXCACHE_512K:
        WidthExp2 = 5;
        break;
    default:
        break;
    }
    t->image1 = 0;
    SET_REG_FIELD(0x4EB, t->image1, 15, 0, tmem_even >> 5);
    SET_REG_FIELD(0x4EC, t->image1, 3, 15, WidthExp2);
    SET_REG_FIELD(0x4ED, t->image1, 3, 18, WidthExp2);
    t->image1 &= 0xFFDFFFFF;
    switch (size_odd) {
    case GX_TEXCACHE_32K:
        WidthExp2 = 3;
        break;
    case GX_TEXCACHE_128K:
        WidthExp2 = 4;
        break;
    case GX_TEXCACHE_512K:
        WidthExp2 = 5;
        break;
    case GX_TEXCACHE_NONE:
        WidthExp2 = 0;
        break;
    default:
        break;
    }
    t->image2 = 0;
    SET_REG_FIELD(0x4FB, t->image2, 15, 0, tmem_odd >> 5);
    SET_REG_FIELD(0x4FC, t->image2, 3, 15, WidthExp2);
    SET_REG_FIELD(0x4FD, t->image2, 3, 18, WidthExp2);
    t->is32bMipmap = is_32b_mipmap;
    t->isCached = 1;
}

void GXInitTlutRegion(GXTlutRegion *region, u32 tmem_addr, GXTlutSize tlut_size)
{
    __GXTlutRegionInt *t = (__GXTlutRegionInt *)region;

    ASSERTMSGLINE(0x580, region, "TLutRegion Object Pointer is null");
    CHECK_GXBEGIN(0x582, "GXInitTlutRegion");
    t->loadTlut1 = 0;
    tmem_addr -= 0x80000;
    SET_REG_FIELD(0x588, t->loadTlut1, 10, 0, tmem_addr >> 9);
    SET_REG_FIELD(0x589, t->loadTlut1, 11, 10, tlut_size);
    SET_REG_FIELD(0x58A, t->loadTlut1, 8, 24, 0x65);
}

void GXInvalidateTexAll(void)
{
    u32 reg0;
    u32 reg1;

    CHECK_GXBEGIN(0x5E7, "GXInvalidateTexAll");
    reg0 = 0x66001000;
    reg1 = 0x66001100;
    __GXFlushTextureState();
    GX_WRITE_RAS_REG(reg0);
    GX_WRITE_RAS_REG(reg1);
    __GXFlushTextureState();
}

GXTexRegionCallback GXSetTexRegionCallback(GXTexRegionCallback f)
{
    GXTexRegionCallback oldcb = gx->texRegionCallback;

    gx->texRegionCallback = f;
    return oldcb;
}

GXTlutRegionCallback GXSetTlutRegionCallback(GXTlutRegionCallback f)
{
    GXTlutRegionCallback oldcb = gx->tlutRegionCallback;

    gx->tlutRegionCallback = f;
    return oldcb;
}

static void __SetSURegs(u32 tmap, u32 tcoord)
{
    u32 w;
    u32 h;
    u8 s_bias;
    u8 t_bias;

    w = GET_REG_FIELD(gx->tImage0[tmap], 10, 0);
    h = GET_REG_FIELD(gx->tImage0[tmap], 10, 10);
    SET_REG_FIELD(0x735, gx->suTs0[tcoord], 16, 0, w);
    SET_REG_FIELD(0x736, gx->suTs1[tcoord], 16, 0, h);
    s_bias = GET_REG_FIELD(gx->tMode0[tmap], 2, 0) == 1;
    t_bias = GET_REG_FIELD(gx->tMode0[tmap], 2, 2) == 1;
    SET_REG_FIELD(0x73C, gx->suTs0[tcoord], 1, 16, s_bias);
    SET_REG_FIELD(0x73D, gx->suTs1[tcoord], 1, 16, t_bias);
    GX_WRITE_RAS_REG(gx->suTs0[tcoord]);
    GX_WRITE_RAS_REG(gx->suTs1[tcoord]);
    gx->bpSent = 0;
}

void __GXSetSUTexRegs(void)
{
    u32 nStages;
    u32 nIndStages;
    u32 i;
    u32 map;
    u32 tmap;
    u32 coord;
    u32 *ptref;

    if (gx->tcsManEnab != 0xFF) {
        nStages = GET_REG_FIELD(gx->genMode, 4, 10) + 1;
        nIndStages = GET_REG_FIELD(gx->genMode, 3, 16);
        for (i = 0; i < nIndStages; i++) {
            switch (i) {
            case 0:
                tmap = GET_REG_FIELD(gx->iref, 3, 0);
                coord = GET_REG_FIELD(gx->iref, 3, 3);
                break;
            case 1:
                tmap = GET_REG_FIELD(gx->iref, 3, 6);
                coord = GET_REG_FIELD(gx->iref, 3, 9);
                break;
            case 2:
                tmap = GET_REG_FIELD(gx->iref, 3, 12);
                coord = GET_REG_FIELD(gx->iref, 3, 15);
                break;
            case 3:
                tmap = GET_REG_FIELD(gx->iref, 3, 18);
                coord = GET_REG_FIELD(gx->iref, 3, 21);
                break;
            }
            if (!(gx->tcsManEnab & (1 << coord))) {
                __SetSURegs(tmap, coord);
            }
        }
        i = 0;
        for (i = 0; i < nStages; i++) {
            ptref = &gx->tref[i / 2];
            map = gx->texmapId[i];
            tmap = map & 0xFFFFFEFF;
            if (i & 1) {
                coord = GET_REG_FIELD(*ptref, 3, 15);
            } else {
                coord = GET_REG_FIELD(*ptref, 3, 3);
            }
            if ((tmap != 0xFF) && !(gx->tcsManEnab & (1 << coord)) && (gx->tevTcEnab & (1 << i))) {
                __SetSURegs(tmap, coord);
            }
        }
    }
}

void __GXSetTmemConfig(u32 arg0)
{
    switch (arg0) {
    case 1:
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0x8C0D8000);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0x900DC000);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0x8D0D8800);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0x910DC800);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0x8E0D9000);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0x920DD000);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0x8F0D9800);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0x930DD800);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0xAC0DA000);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0xB00DE000);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0xAD0DA800);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0xB10DE800);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0xAE0DB000);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0xB20DF000);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0xAF0DB800);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0xB30DF800);
        break;
    case 0:
    default:
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0x8C0D8000);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0x900DC000);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0x8D0D8400);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0x910DC400);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0x8E0D8800);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0x920DC800);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0x8F0D8C00);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0x930DCC00);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0xAC0D9000);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0xB00DD000);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0xAD0D9400);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0xB10DD400);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0xAE0D9800);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0xB20DD800);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0xAF0D9C00);
        GX_WRITE_U8(0x61);
        GX_WRITE_U32(0xB30DDC00);
        break;
    }
}
