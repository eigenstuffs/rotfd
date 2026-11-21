/* Dolphin SDK GXTransform.c texture matrix load, GSQE78.
 * Dual-texture (post-transform) matrices start at XF address 0x500.
 */
typedef unsigned char u8;
typedef unsigned long u32;
typedef float f32;
typedef f32 Mtx[3][4];

typedef union {
    u8 u8;
    u32 u32;
    f32 f32;
} PPCWGPipe;

#define GXWGFifo (*(volatile PPCWGPipe*)0xCC008000)
#define GX_LOAD_XF_REG 0x10
#define GX_PTTEXMTX0 64
#define GX_MTX3x4 0
#define GX_MTX2x4 1

static inline void WriteMTXPS4x3(register const f32 mtx[3][4], register volatile void* wgpipe)
{
    register f32 a00_a01, a02_a03, a10_a11, a12_a13, a20_a21, a22_a23;
    /* clang-format off */
    asm {
        psq_l a00_a01, 0x00(mtx), 0, 0
        psq_l a02_a03, 0x08(mtx), 0, 0
        psq_l a10_a11, 0x10(mtx), 0, 0
        psq_l a12_a13, 0x18(mtx), 0, 0
        psq_l a20_a21, 0x20(mtx), 0, 0
        psq_l a22_a23, 0x28(mtx), 0, 0
        psq_st a00_a01, 0(wgpipe), 0, 0
        psq_st a02_a03, 0(wgpipe), 0, 0
        psq_st a10_a11, 0(wgpipe), 0, 0
        psq_st a12_a13, 0(wgpipe), 0, 0
        psq_st a20_a21, 0(wgpipe), 0, 0
        psq_st a22_a23, 0(wgpipe), 0, 0
    }
    /* clang-format on */
}

static inline void WriteMTXPS4x2(register const f32 mtx[2][4], register volatile void* wgpipe)
{
    register f32 a00_a01, a02_a03, a10_a11, a12_a13;
    /* clang-format off */
    asm {
        psq_l a00_a01, 0x00(mtx), 0, 0
        psq_l a02_a03, 0x08(mtx), 0, 0
        psq_l a10_a11, 0x10(mtx), 0, 0
        psq_l a12_a13, 0x18(mtx), 0, 0
        psq_st a00_a01, 0(wgpipe), 0, 0
        psq_st a02_a03, 0(wgpipe), 0, 0
        psq_st a10_a11, 0(wgpipe), 0, 0
        psq_st a12_a13, 0(wgpipe), 0, 0
    }
    /* clang-format on */
}

void GXLoadTexMtxImm(const f32 mtx[][4], u32 id, int type)
{
    u32 reg;
    u32 addr;
    u32 count;

    if (id >= GX_PTTEXMTX0) {
        addr = (id - GX_PTTEXMTX0) * 4 + 0x500;
    } else {
        addr = id * 4;
    }
    count = (type == GX_MTX2x4) ? 8 : 12;
    reg = addr | ((count - 1) << 16);
    GXWGFifo.u8 = GX_LOAD_XF_REG;
    GXWGFifo.u32 = reg;
    if (type == GX_MTX3x4) {
        WriteMTXPS4x3(mtx, &GXWGFifo.f32);
    } else {
        WriteMTXPS4x2(mtx, &GXWGFifo.f32);
    }
}
