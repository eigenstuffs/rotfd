/* Dolphin TEV order fragment; the coordinate-enable mask preserves the
 * original invalid-coordinate update order. See docs/notes/GXTev.md. */
#include "gx_abi.h"

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
        gx->tevTcEnab = gx->tevTcEnab & ~(1U << stage);
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

