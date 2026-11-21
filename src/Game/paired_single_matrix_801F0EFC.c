/* Hand-written paired-single matrix routines. Both functions consist of
 * psq_l/psq_st and ps_* instructions, which this compiler only emits from
 * assembly, so they are kept as asm function bodies in the same form as the
 * SDK's own paired-single routines (src/dolphin/mtx/mtx.c).
 *   fn_801F0EFC: 4x4 source matrix to 3x4 result (saves all paired FPRs).
 *   fn_801F1080: 4x4 matrix product out = a * b (callers pass out == a). */
typedef struct Matrix44 { float m[4][4]; } Matrix44;
typedef struct Matrix34 { float m[3][4]; } Matrix34;

asm void fn_801F0EFC(const Matrix44* src, Matrix34* dst) {
    nofralloc
    stwu r1, -0x130(r1)
    stfd f31, 0x120(r1)
    psq_st f31, 0x128(r1), 0, 0
    stfd f30, 0x110(r1)
    psq_st f30, 0x118(r1), 0, 0
    stfd f29, 0x100(r1)
    psq_st f29, 0x108(r1), 0, 0
    stfd f28, 0xf0(r1)
    psq_st f28, 0xf8(r1), 0, 0
    stfd f27, 0xe0(r1)
    psq_st f27, 0xe8(r1), 0, 0
    stfd f26, 0xd0(r1)
    psq_st f26, 0xd8(r1), 0, 0
    stfd f25, 0xc0(r1)
    psq_st f25, 0xc8(r1), 0, 0
    stfd f24, 0xb0(r1)
    psq_st f24, 0xb8(r1), 0, 0
    stfd f23, 0xa0(r1)
    psq_st f23, 0xa8(r1), 0, 0
    stfd f22, 0x90(r1)
    psq_st f22, 0x98(r1), 0, 0
    stfd f21, 0x80(r1)
    psq_st f21, 0x88(r1), 0, 0
    stfd f20, 0x70(r1)
    psq_st f20, 0x78(r1), 0, 0
    stfd f19, 0x60(r1)
    psq_st f19, 0x68(r1), 0, 0
    stfd f18, 0x50(r1)
    psq_st f18, 0x58(r1), 0, 0
    stfd f17, 0x40(r1)
    psq_st f17, 0x48(r1), 0, 0
    stfd f16, 0x30(r1)
    psq_st f16, 0x38(r1), 0, 0
    stfd f15, 0x20(r1)
    psq_st f15, 0x28(r1), 0, 0
    stfd f14, 0x10(r1)
    psq_st f14, 0x18(r1), 0, 0
    stw r3, 0x8(r1)
    stw r4, 0xc(r1)
    psq_l f2, 0x0(r3), 0, 0
    psq_l f4, 0x10(r3), 0, 0
    psq_l f6, 0x20(r3), 0, 0
    psq_l f8, 0x30(r3), 0, 0
    ps_merge00 f10, f2, f4
    ps_merge11 f12, f2, f4
    ps_merge00 f11, f6, f8
    ps_merge11 f13, f6, f8
    psq_l f3, 0x8(r3), 0, 0
    psq_l f5, 0x18(r3), 0, 0
    psq_l f7, 0x28(r3), 0, 0
    psq_l f9, 0x38(r3), 0, 0
    psq_st f10, 0x0(r4), 0, 0
    psq_st f12, 0x10(r4), 0, 0
    ps_merge00 f14, f3, f5
    ps_merge00 f15, f7, f9
    psq_st f11, 0x8(r4), 0, 0
    psq_st f13, 0x18(r4), 0, 0
    psq_st f14, 0x20(r4), 0, 0
    psq_st f15, 0x28(r4), 0, 0
    psq_l f31, 0x128(r1), 0, 0
    lfd f31, 0x120(r1)
    psq_l f30, 0x118(r1), 0, 0
    lfd f30, 0x110(r1)
    psq_l f29, 0x108(r1), 0, 0
    lfd f29, 0x100(r1)
    psq_l f28, 0xf8(r1), 0, 0
    lfd f28, 0xf0(r1)
    psq_l f27, 0xe8(r1), 0, 0
    lfd f27, 0xe0(r1)
    psq_l f26, 0xd8(r1), 0, 0
    lfd f26, 0xd0(r1)
    psq_l f25, 0xc8(r1), 0, 0
    lfd f25, 0xc0(r1)
    psq_l f24, 0xb8(r1), 0, 0
    lfd f24, 0xb0(r1)
    psq_l f23, 0xa8(r1), 0, 0
    lfd f23, 0xa0(r1)
    psq_l f22, 0x98(r1), 0, 0
    lfd f22, 0x90(r1)
    psq_l f21, 0x88(r1), 0, 0
    lfd f21, 0x80(r1)
    psq_l f20, 0x78(r1), 0, 0
    lfd f20, 0x70(r1)
    psq_l f19, 0x68(r1), 0, 0
    lfd f19, 0x60(r1)
    psq_l f18, 0x58(r1), 0, 0
    lfd f18, 0x50(r1)
    psq_l f17, 0x48(r1), 0, 0
    lfd f17, 0x40(r1)
    psq_l f16, 0x38(r1), 0, 0
    lfd f16, 0x30(r1)
    psq_l f15, 0x28(r1), 0, 0
    lfd f15, 0x20(r1)
    psq_l f14, 0x18(r1), 0, 0
    lfd f14, 0x10(r1)
    addi r1, r1, 0x130
    blr
}

asm void fn_801F1080(const Matrix44* a, const Matrix44* b, Matrix44* out) {
    nofralloc
    psq_l f0, 0x0(r4), 0, 0
    psq_l f2, 0x0(r3), 0, 0
    ps_muls0 f6, f2, f0
    psq_l f3, 0x10(r3), 0, 0
    psq_l f4, 0x20(r3), 0, 0
    ps_madds1 f6, f3, f0, f6
    psq_l f1, 0x8(r4), 0, 0
    psq_l f5, 0x30(r3), 0, 0
    ps_madds0 f6, f4, f1, f6
    psq_l f0, 0x10(r4), 0, 0
    ps_madds1 f6, f5, f1, f6
    psq_l f1, 0x18(r4), 0, 0
    ps_muls0 f8, f2, f0
    ps_madds1 f8, f3, f0, f8
    psq_l f0, 0x20(r4), 0, 0
    ps_madds0 f8, f4, f1, f8
    ps_madds1 f8, f5, f1, f8
    psq_l f1, 0x28(r4), 0, 0
    ps_muls0 f10, f2, f0
    ps_madds1 f10, f3, f0, f10
    psq_l f0, 0x30(r4), 0, 0
    ps_madds0 f10, f4, f1, f10
    ps_madds1 f10, f5, f1, f10
    psq_l f1, 0x38(r4), 0, 0
    ps_muls0 f12, f2, f0
    psq_l f2, 0x8(r3), 0, 0
    ps_madds1 f12, f3, f0, f12
    psq_l f0, 0x0(r4), 0, 0
    ps_madds0 f12, f4, f1, f12
    psq_l f3, 0x18(r3), 0, 0
    ps_madds1 f12, f5, f1, f12
    psq_l f1, 0x8(r4), 0, 0
    ps_muls0 f7, f2, f0
    psq_l f4, 0x28(r3), 0, 0
    ps_madds1 f7, f3, f0, f7
    psq_l f5, 0x38(r3), 0, 0
    ps_madds0 f7, f4, f1, f7
    psq_l f0, 0x10(r4), 0, 0
    ps_madds1 f7, f5, f1, f7
    psq_l f1, 0x18(r4), 0, 0
    ps_muls0 f9, f2, f0
    psq_st f6, 0x0(r5), 0, 0
    ps_madds1 f9, f3, f0, f9
    psq_l f0, 0x20(r4), 0, 0
    ps_madds0 f9, f4, f1, f9
    psq_st f8, 0x10(r5), 0, 0
    ps_madds1 f9, f5, f1, f9
    psq_l f1, 0x28(r4), 0, 0
    ps_muls0 f11, f2, f0
    psq_st f10, 0x20(r5), 0, 0
    ps_madds1 f11, f3, f0, f11
    psq_l f0, 0x30(r4), 0, 0
    ps_madds0 f11, f4, f1, f11
    psq_st f12, 0x30(r5), 0, 0
    ps_madds1 f11, f5, f1, f11
    psq_l f1, 0x38(r4), 0, 0
    ps_muls0 f13, f2, f0
    psq_st f7, 0x8(r5), 0, 0
    ps_madds1 f13, f3, f0, f13
    psq_st f9, 0x18(r5), 0, 0
    ps_madds0 f13, f4, f1, f13
    psq_st f11, 0x28(r5), 0, 0
    ps_madds1 f13, f5, f1, f13
    psq_st f13, 0x38(r5), 0, 0
    blr
}

