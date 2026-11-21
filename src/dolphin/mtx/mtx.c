/* Dolphin SDK mtx.c paired-single primitives, GSQE78 revision.
 * Follows reference/melee-sdk/mtx.c; PSMTXInverse uses this revision's
 * instruction schedule.
 */
typedef float f32;
typedef unsigned long u32;
typedef f32 Mtx[3][4];

#define qr0 0

/* Shared with the original constant unit (1.0f, 0.0f). */
extern const f32 lbl_80379880;
extern const f32 lbl_80379884;

void fn_800F6D0C(register Mtx m)
{
    register f32 c_zero = lbl_80379884;
    register f32 c_one = lbl_80379880;
    register f32 c_01;
    register f32 c_10;

    /* clang-format off */
    asm {
        psq_st c_zero, 8(m), 0, qr0
        ps_merge01 c_01, c_zero, c_one
        psq_st c_zero, 24(m), 0, qr0
        ps_merge10 c_10, c_one, c_zero
        psq_st c_zero, 32(m), 0, qr0
        psq_st c_01, 16(m), 0, qr0
        psq_st c_10, 0(m), 0, qr0
        psq_st c_10, 40(m), 0, qr0
    }
    /* clang-format on */
}

/* clang-format off */
asm void fn_800F6D38(register Mtx src, register Mtx dst)
{
    nofralloc
    psq_l f0, 0(src), 0, qr0
    psq_st f0, 0(dst), 0, qr0
    psq_l f1, 8(src), 0, qr0
    psq_st f1, 8(dst), 0, qr0
    psq_l f2, 16(src), 0, qr0
    psq_st f2, 16(dst), 0, qr0
    psq_l f3, 24(src), 0, qr0
    psq_st f3, 24(dst), 0, qr0
    psq_l f4, 32(src), 0, qr0
    psq_st f4, 32(dst), 0, qr0
    psq_l f5, 40(src), 0, qr0
    psq_st f5, 40(dst), 0, qr0
    blr
}

asm u32 fn_800F6D6C(register Mtx src, register Mtx inv) {
    nofralloc
    psq_l f0, 0x0(r3), 1, 0
    psq_l f1, 0x4(r3), 0, 0
    psq_l f2, 0x10(r3), 1, 0
    ps_merge10 f6, f1, f0
    psq_l f3, 0x14(r3), 0, 0
    psq_l f4, 0x20(r3), 1, 0
    ps_merge10 f7, f3, f2
    psq_l f5, 0x24(r3), 0, 0
    ps_mul f11, f3, f6
    ps_merge10 f8, f5, f4
    ps_mul f13, f5, f7
    ps_msub f11, f1, f7, f11
    ps_mul f12, f1, f8
    ps_msub f13, f3, f8, f13
    ps_msub f12, f5, f6, f12
    ps_mul f10, f3, f4
    ps_mul f9, f0, f5
    ps_mul f8, f1, f2
    ps_msub f10, f2, f5, f10
    ps_msub f9, f1, f4, f9
    ps_msub f8, f0, f3, f8
    ps_mul f7, f0, f13
    ps_sub f1, f1, f1
    ps_madd f7, f2, f12, f7
    ps_madd f7, f4, f11, f7
    ps_cmpo0 cr0, f7, f1
    bne skip_return
    li r3, 0x0
    blr
skip_return:
    fres f0, f7
    psq_st f1, 0xc(r4), 1, 0
    ps_add f6, f0, f0
    ps_mul f5, f0, f0
    psq_st f1, 0x1c(r4), 1, 0
    ps_nmsub f0, f7, f5, f6
    psq_st f1, 0x2c(r4), 1, 0
    ps_muls0 f13, f13, f0
    ps_muls0 f12, f12, f0
    ps_muls0 f11, f11, f0
    psq_st f13, 0x0(r4), 0, 0
    psq_st f12, 0x10(r4), 0, 0
    ps_muls0 f10, f10, f0
    ps_muls0 f9, f9, f0
    psq_st f11, 0x20(r4), 0, 0
    psq_st f10, 0x8(r4), 1, 0
    ps_muls0 f8, f8, f0
    li r3, 0x1
    psq_st f9, 0x18(r4), 1, 0
    psq_st f8, 0x28(r4), 1, 0
    blr
}

asm void fn_800F6E34(register Mtx m, register f32 xS, register f32 yS, register f32 zS)
{
    nofralloc
    lfs f0, lbl_80379884
    stfs f1, 0x0(r3)
    psq_st f0, 0x4(r3), 0, qr0
    psq_st f0, 0xc(r3), 0, qr0
    stfs f2, 0x14(r3)
    psq_st f0, 0x18(r3), 0, qr0
    psq_st f0, 0x20(r3), 0, qr0
    stfs f3, 0x28(r3)
    stfs f0, 0x2c(r3)
    blr
}
/* clang-format on */
