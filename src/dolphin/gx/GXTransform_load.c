typedef unsigned char u8;
typedef unsigned long u32;
typedef float f32;
typedef f32 Mtx[3][4];
typedef f32 (*MtxPtr)[4];

typedef union {
    u8 u8;
    u32 u32;
    f32 f32;
} PPCWGPipe;

#define GXWGFifo (*(volatile PPCWGPipe*)0xCC008000)
#define GX_LOAD_XF_REG 0x10
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

static inline void WriteMTXPS3x3from3x4(register const f32 mtx[3][4], register volatile void* wgpipe)
{
    register f32 a00_a01, a02, a10_a11, a12, a20_a21, a22;
    /* clang-format off */
    asm {
        psq_l a00_a01, 0x00(mtx), 0, 0
        lfs a02, 0x08(mtx)
        psq_l a10_a11, 0x10(mtx), 0, 0
        lfs a12, 0x18(mtx)
        psq_l a20_a21, 0x20(mtx), 0, 0
        lfs a22, 0x28(mtx)
        psq_st a00_a01, 0(wgpipe), 0, 0
        stfs a02, 0(wgpipe)
        psq_st a10_a11, 0(wgpipe), 0, 0
        stfs a12, 0(wgpipe)
        psq_st a20_a21, 0(wgpipe), 0, 0
        stfs a22, 0(wgpipe)
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

void GXLoadPosMtxImm(const Mtx mtx, u32 id)
{
    u32 reg;
    u32 addr;

    addr = id * 4;
    reg = addr | ((12 - 1) << 16);
    GXWGFifo.u8 = GX_LOAD_XF_REG;
    GXWGFifo.u32 = reg;
    WriteMTXPS4x3(mtx, &GXWGFifo.f32);
}

void GXLoadNrmMtxImm(const Mtx mtx, u32 id)
{
    u32 reg;
    u32 addr;

    addr = id * 3 + 0x400;
    reg = addr | ((9 - 1) << 16);
    GXWGFifo.u8 = GX_LOAD_XF_REG;
    GXWGFifo.u32 = reg;
    WriteMTXPS3x3from3x4(mtx, &GXWGFifo.f32);
}
