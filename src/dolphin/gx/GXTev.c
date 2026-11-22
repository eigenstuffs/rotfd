#include "gx_abi.h"
#define GX_SET_REG_C(reg, val, start, end) SET_REG_FIELD(0, reg, (end)-(start)+1, 31-(end), val)
#define GX_SET_REG(reg, val, start, end) ((reg) = __rlwimi((reg), (val), 31-(end), (start), (end)))
static u32 TEVCOpTableST0[] = {
	0xC008F8AF, // modulate
	0xC008A89F, // decal
	0xC008AC8F, // blend
	0xC008FFF8, // replace
	0xC008FFFA, // passclr
};

static u32 TEVCOpTableST1[] = {
	0xC008F80F, // modulate
	0xC008089F, // decal
	0xC0080C8F, // blend
	0xC008FFF8, // replace
	0xC008FFF0, // passclr
};

static u32 TEVAOpTableST0[] = {
	0xC108F2F0, // modulate
	0xC108FFD0, // decal
	0xC108F2F0, // blend
	0xC108FFC0, // replace
	0xC108FFD0, // passclr
};

static u32 TEVAOpTableST1[] = {
	0xC108F070, // modulate
	0xC108FF80, // decal
	0xC108F070, // blend
	0xC108FFC0, // replace
	0xC108FF80, // passclr
};

void GXSetTevOp(GXTevStageID stage, GXTevMode mode)
{
	u32* color;
	u32* alpha;
	u32 tevReg;

	if (stage == GX_TEVSTAGE0) {
		color = &TEVCOpTableST0[mode];
		alpha = &TEVAOpTableST0[mode];
	} else {
		color = &TEVCOpTableST1[mode];
		alpha = &TEVAOpTableST1[mode];
	}

	tevReg = gx->tevc[stage];
	tevReg = (*color & ~0xFF000000) | (tevReg & 0xFF000000);

	GX_WRITE_RAS_REG(tevReg);

	gx->tevc[stage] = tevReg;

	tevReg = gx->teva[stage];
	tevReg = (*alpha & ~0xFF00000F) | (tevReg & 0xFF00000F);

	GX_WRITE_RAS_REG(tevReg);

	gx->teva[stage] = tevReg;

	gx->bpSent = GX_FALSE;
}

void GXSetTevColorIn(GXTevStageID stage, GXTevColorArg a, GXTevColorArg b, GXTevColorArg c, GXTevColorArg d)
{
	u32 tevReg;

	tevReg = gx->tevc[stage];

	GX_SET_REG(tevReg, a, 16, 19);
	GX_SET_REG(tevReg, b, 20, 23);
	GX_SET_REG(tevReg, c, 24, 27);
	GX_SET_REG(tevReg, d, 28, 31);

	GX_WRITE_RAS_REG(tevReg);

	gx->tevc[stage] = tevReg;
	gx->bpSent   = GX_FALSE;
}

void GXSetTevAlphaIn(GXTevStageID stage, GXTevAlphaArg a, GXTevAlphaArg b, GXTevAlphaArg c, GXTevAlphaArg d)
{
	u32 tevReg;

	tevReg = gx->teva[stage];

	GX_SET_REG(tevReg, a, 16, 18);
	GX_SET_REG(tevReg, b, 19, 21);
	GX_SET_REG(tevReg, c, 22, 24);
	GX_SET_REG(tevReg, d, 25, 27);

	GX_WRITE_RAS_REG(tevReg);

	gx->teva[stage] = tevReg;
	gx->bpSent   = GX_FALSE;
}

void GXSetTevColorOp(GXTevStageID stage, GXTevOp op, GXTevBias bias, GXTevScale scale, GXBool doClamp, GXTevRegID outReg)
{
	u32 tevReg;

	tevReg = gx->tevc[stage];
	GX_SET_REG(tevReg, op & 1, 13, 13);

	if (op <= 1) {
		GX_SET_REG(tevReg, scale, 10, 11);
		GX_SET_REG(tevReg, bias, 14, 15);
	} else {
		GX_SET_REG(tevReg, (op >> 1) & 3, 10, 11);
		GX_SET_REG(tevReg, 3, 14, 15);
	}

	GX_SET_REG(tevReg, doClamp, 12, 12);
	GX_SET_REG(tevReg, outReg, 8, 9);

	GX_WRITE_RAS_REG(tevReg);

	gx->tevc[stage] = tevReg;
	gx->bpSent   = GX_FALSE;
}

void GXSetTevAlphaOp(GXTevStageID stage, GXTevOp op, GXTevBias bias, GXTevScale scale, GXBool doClamp, GXTevRegID outReg)
{
	u32 tevReg;

	tevReg = gx->teva[stage];
	GX_SET_REG(tevReg, op & 1, 13, 13);

	if (op <= 1) {
		GX_SET_REG(tevReg, scale, 10, 11);
		GX_SET_REG(tevReg, bias, 14, 15);
	} else {
		GX_SET_REG(tevReg, (op >> 1) & 3, 10, 11);
		GX_SET_REG(tevReg, 3, 14, 15);
	}

	GX_SET_REG(tevReg, doClamp, 12, 12);
	GX_SET_REG(tevReg, outReg, 8, 9);

	GX_WRITE_RAS_REG(tevReg);

	gx->teva[stage] = tevReg;
	gx->bpSent   = GX_FALSE;
}

void GXSetTevColor(GXTevRegID id, GXColor color)
{
    u32 regRA;
    u32 regBG;

    CHECK_GXBEGIN(0x182, "GXSetTevColor");

    regRA = 0;
    SET_REG_FIELD(0x185, regRA, 11, 0, color.r);
    SET_REG_FIELD(0x186, regRA, 11, 12, color.a);
    SET_REG_FIELD(0x187, regRA, 8, 24, 224 + id * 2);

    regBG = 0;
    SET_REG_FIELD(0x18A, regBG, 11, 0, color.b);
    SET_REG_FIELD(0x18B, regBG, 11, 12, color.g);
    SET_REG_FIELD(0x18C, regBG, 8, 24, 225 + id * 2);

    GX_WRITE_RAS_REG(regRA);
    GX_WRITE_RAS_REG(regBG);
    GX_WRITE_RAS_REG(regBG);
    GX_WRITE_RAS_REG(regBG);
    gx->bpSent = 0;
}

void GXSetTevKColor(GXTevKColorID id, GXColor color)
{
    u32 regRA;
    u32 regBG;

    CHECK_GXBEGIN(0x1DD, "GXSetTevKColor");

    regRA = 0;
    SET_REG_FIELD(0x1E0, regRA, 8, 0, color.r);
    SET_REG_FIELD(0x1E1, regRA, 8, 12, color.a);
    SET_REG_FIELD(0x1E2, regRA, 4, 20, 8);
    SET_REG_FIELD(0x1E3, regRA, 8, 24, 224 + id * 2);

    regBG = 0;
    SET_REG_FIELD(0x1E6, regBG, 8, 0, color.b);
    SET_REG_FIELD(0x1E7, regBG, 8, 12, color.g);
    SET_REG_FIELD(0x1E8, regBG, 4, 20, 8);
    SET_REG_FIELD(0x1E9, regBG, 8, 24, 225 + id * 2);

    GX_WRITE_RAS_REG(regRA);
    GX_WRITE_RAS_REG(regBG);
    gx->bpSent = 0;
}

void GXSetTevKColorSel(GXTevStageID stage, GXTevKColorSel sel)
{
    u32* Kreg;

    CHECK_GXBEGIN(0x204, "GXSetTevKColorSel");
    ASSERTMSGLINE(0x205, stage < 16,
                  "GXSetTevKColor*: Invalid Tev Stage Index");

    Kreg = &gx->tevKsel[stage >> 1];
    if (stage & 1) {
        SET_REG_FIELD(0x20A, *Kreg, 5, 14, sel);
    } else {
        SET_REG_FIELD(0x20C, *Kreg, 5, 4, sel);
    }

    GX_WRITE_RAS_REG(*Kreg);
    gx->bpSent = 0;
}

void GXSetTevKAlphaSel(GXTevStageID stage, GXTevKAlphaSel sel)
{
    u32* Kreg;

    CHECK_GXBEGIN(0x225, "GXSetTevKAlphaSel");
    ASSERTMSGLINE(0x226, stage < 16,
                  "GXSetTevKColor*: Invalid Tev Stage Index");

    Kreg = &gx->tevKsel[stage >> 1];
    if (stage & 1) {
        SET_REG_FIELD(0x22B, *Kreg, 5, 19, sel);
    } else {
        SET_REG_FIELD(0x22D, *Kreg, 5, 9, sel);
    }

    GX_WRITE_RAS_REG(*Kreg);
    gx->bpSent = 0;
}

void GXSetTevSwapMode(GXTevStageID stage, GXTevSwapSel ras_sel,
                      GXTevSwapSel tex_sel)
{
    u32* pTevReg;

    CHECK_GXBEGIN(0x24A, "GXSetTevSwapMode");
    ASSERTMSGLINE(0x24B, stage < 16,
                  "GXSetTevSwapMode: Invalid Tev Stage Index");

    pTevReg = &gx->teva[stage];
    SET_REG_FIELD(0x24E, *pTevReg, 2, 0, ras_sel);
    SET_REG_FIELD(0x24F, *pTevReg, 2, 2, tex_sel);

    GX_WRITE_RAS_REG(*pTevReg);
    gx->bpSent = 0;
}

void GXSetTevSwapModeTable(GXTevSwapSel table, GXTevColorChan red,
                           GXTevColorChan green, GXTevColorChan blue,
                           GXTevColorChan alpha)
{
    u32* Kreg;
#if !DEBUG
    // not a real variable, but needed to match release
    int index = table * 2;
#endif

    CHECK_GXBEGIN(0x26E, "GXSetTevSwapModeTable");
    ASSERTMSGLINE(0x26F, table < 4,
                  "GXSetTevSwapModeTable: Invalid Swap Selection Index");

#if DEBUG
    Kreg = &gx->tevKsel[table * 2];
#else
    Kreg = &gx->tevKsel[index];
#endif
    SET_REG_FIELD(0x272, *Kreg, 2, 0, red);
    SET_REG_FIELD(0x273, *Kreg, 2, 2, green);

    GX_WRITE_RAS_REG(*Kreg);

    Kreg = &gx->tevKsel[table * 2 + 1];
    SET_REG_FIELD(0x277, *Kreg, 2, 0, blue);
    SET_REG_FIELD(0x278, *Kreg, 2, 2, alpha);

    GX_WRITE_RAS_REG(*Kreg);
    gx->bpSent = 0;
}



void GXSetAlphaCompare(GXCompare comp0, u8 ref0, GXAlphaOp op, GXCompare comp1, u8 ref1)
{
	u32 reg = 0xF3000000;

	GX_SET_REG_C(reg, ref0, 24, 31);
	GX_SET_REG_C(reg, ref1, 16, 23);
	GX_SET_REG_C(reg, comp0, 13, 15);
	GX_SET_REG_C(reg, comp1, 10, 12);
	GX_SET_REG_C(reg, op, 8, 9);

	GX_WRITE_RAS_REG(reg);

	gx->bpSent = GX_FALSE;
}


void GXSetZTexture(GXZTexOp op, GXTexFmt fmt, u32 bias)
{
    u32 zenv0;
    u32 zenv1;
    u32 type;

    CHECK_GXBEGIN(0x2D1, "GXSetZTexture");

    zenv0 = 0;
    SET_REG_FIELD(0x2D4, zenv0, 24, 0, bias);
    SET_REG_FIELD(0x2D5, zenv0, 8, 24, 0xF4);

    zenv1 = 0;
    switch (fmt) {
    case GX_TF_Z8:
        type = 0;
        break;
    case GX_TF_Z16:
        type = 1;
        break;
    case GX_TF_Z24X8:
        type = 2;
        break;
    default:
        ASSERTMSGLINE(0x2DD, 0, "GXSetZTexture: Invalid z-texture format");
        type = 2;
        break;
    }
    SET_REG_FIELD(0x2E0, zenv1, 2, 0, type);
    SET_REG_FIELD(0x2E1, zenv1, 2, 2, op);
    SET_REG_FIELD(0x2E2, zenv1, 8, 24, 0xF5);

    GX_WRITE_RAS_REG(zenv0);
    GX_WRITE_RAS_REG(zenv1);
    gx->bpSent = 0;
}

void GXSetTevOrder(GXTevStageID stage, GXTexCoordID coord, GXTexMapID map,
                   GXChannelID color)
{
    u32* ptref;
    u32 tmap;
    u32 tcoord;
    static int c2r[] = { 0, 1, 0, 1, 0, 1, 7, 5, 6 };

    CHECK_GXBEGIN(0x307, "GXSetTevOrder");
    ASSERTMSGLINE(0x308, stage < 16, "GXSetTevColor: Invalid Tev Stage Index");

    ptref = &gx->tref[stage / 2];
    gx->texmapId[stage] = map;

    tmap = map & ~0x100;
    tmap = (tmap >= GX_MAX_TEXMAP) ? GX_TEXMAP0 : tmap;
    if (coord >= GX_MAX_TEXCOORD) {
        tcoord = GX_TEXCOORD0;
        gx->tevTcEnab = ~(1UL << stage) & gx->tevTcEnab;
    } else {
        tcoord = coord;
        gx->tevTcEnab = gx->tevTcEnab | (1UL << stage);
    }

    if (stage & 1) {
        SET_REG_FIELD(0x314, *ptref, 3, 12, tmap);
        SET_REG_FIELD(0x315, *ptref, 3, 15, tcoord);
        SET_REG_FIELD(0x317, *ptref, 3, 19,
                      (color == GX_COLOR_NULL) ? 7 : c2r[color]);
        SET_REG_FIELD(0x319, *ptref, 1, 18,
                      (map != GX_TEXMAP_NULL && !(map & 0x100)));
    } else {
        SET_REG_FIELD(0x31C, *ptref, 3, 0, tmap);
        SET_REG_FIELD(0x31D, *ptref, 3, 3, tcoord);
        SET_REG_FIELD(0x31F, *ptref, 3, 7,
                      (color == GX_COLOR_NULL) ? 7 : c2r[color]);
        SET_REG_FIELD(0x321, *ptref, 1, 6,
                      (map != GX_TEXMAP_NULL && !(map & 0x100)));
    }

    GX_WRITE_RAS_REG(*ptref);
    gx->bpSent = 0;
    gx->dirtyState |= 1;
}

void GXSetNumTevStages(u8 nStages)
{
    CHECK_GXBEGIN(0x331, "GXSetNumTevStages");

    ASSERTMSGLINE(0x333, nStages != 0 && nStages <= 16,
                  "GXSetNumTevStages: Exceed max number of tex stages");
    SET_REG_FIELD(0x334, gx->genMode, 4, 10, nStages - 1);
    gx->dirtyState |= 4;
}
