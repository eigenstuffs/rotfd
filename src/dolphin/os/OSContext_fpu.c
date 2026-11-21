/* Dolphin SDK OSContext.c FPU context load/save and current-context selection, GSQE78.
 * The SDK writes these routines as CodeWarrior asm functions.
 */
typedef unsigned long u32;
/* clang-format off */
asm void __OSLoadFPUContext_800F26B8(void) {
    nofralloc
    lhz r5, 0x1a2(r4)
    clrlwi. r5, r5, 31
    beq L_800F27D8
    lfd f0, 0x190(r4)
    mtfsf 255, f0
    mfspr r5, 920
    rlwinm. r5, r5, 3, 31, 31
    beq L_800F2758
    psq_l f0, 0x1c8(r4), 0, 0
    psq_l f1, 0x1d0(r4), 0, 0
    psq_l f2, 0x1d8(r4), 0, 0
    psq_l f3, 0x1e0(r4), 0, 0
    psq_l f4, 0x1e8(r4), 0, 0
    psq_l f5, 0x1f0(r4), 0, 0
    psq_l f6, 0x1f8(r4), 0, 0
    psq_l f7, 0x200(r4), 0, 0
    psq_l f8, 0x208(r4), 0, 0
    psq_l f9, 0x210(r4), 0, 0
    psq_l f10, 0x218(r4), 0, 0
    psq_l f11, 0x220(r4), 0, 0
    psq_l f12, 0x228(r4), 0, 0
    psq_l f13, 0x230(r4), 0, 0
    psq_l f14, 0x238(r4), 0, 0
    psq_l f15, 0x240(r4), 0, 0
    psq_l f16, 0x248(r4), 0, 0
    psq_l f17, 0x250(r4), 0, 0
    psq_l f18, 0x258(r4), 0, 0
    psq_l f19, 0x260(r4), 0, 0
    psq_l f20, 0x268(r4), 0, 0
    psq_l f21, 0x270(r4), 0, 0
    psq_l f22, 0x278(r4), 0, 0
    psq_l f23, 0x280(r4), 0, 0
    psq_l f24, 0x288(r4), 0, 0
    psq_l f25, 0x290(r4), 0, 0
    psq_l f26, 0x298(r4), 0, 0
    psq_l f27, 0x2a0(r4), 0, 0
    psq_l f28, 0x2a8(r4), 0, 0
    psq_l f29, 0x2b0(r4), 0, 0
    psq_l f30, 0x2b8(r4), 0, 0
    psq_l f31, 0x2c0(r4), 0, 0
L_800F2758:
    lfd f0, 0x90(r4)
    lfd f1, 0x98(r4)
    lfd f2, 0xa0(r4)
    lfd f3, 0xa8(r4)
    lfd f4, 0xb0(r4)
    lfd f5, 0xb8(r4)
    lfd f6, 0xc0(r4)
    lfd f7, 0xc8(r4)
    lfd f8, 0xd0(r4)
    lfd f9, 0xd8(r4)
    lfd f10, 0xe0(r4)
    lfd f11, 0xe8(r4)
    lfd f12, 0xf0(r4)
    lfd f13, 0xf8(r4)
    lfd f14, 0x100(r4)
    lfd f15, 0x108(r4)
    lfd f16, 0x110(r4)
    lfd f17, 0x118(r4)
    lfd f18, 0x120(r4)
    lfd f19, 0x128(r4)
    lfd f20, 0x130(r4)
    lfd f21, 0x138(r4)
    lfd f22, 0x140(r4)
    lfd f23, 0x148(r4)
    lfd f24, 0x150(r4)
    lfd f25, 0x158(r4)
    lfd f26, 0x160(r4)
    lfd f27, 0x168(r4)
    lfd f28, 0x170(r4)
    lfd f29, 0x178(r4)
    lfd f30, 0x180(r4)
    lfd f31, 0x188(r4)
L_800F27D8:
    blr
}

asm void __OSSaveFPUContext_800F27DC(void) {
    nofralloc
    lhz r3, 0x1a2(r5)
    ori r3, r3, 0x1
    sth r3, 0x1a2(r5)
    stfd f0, 0x90(r5)
    stfd f1, 0x98(r5)
    stfd f2, 0xa0(r5)
    stfd f3, 0xa8(r5)
    stfd f4, 0xb0(r5)
    stfd f5, 0xb8(r5)
    stfd f6, 0xc0(r5)
    stfd f7, 0xc8(r5)
    stfd f8, 0xd0(r5)
    stfd f9, 0xd8(r5)
    stfd f10, 0xe0(r5)
    stfd f11, 0xe8(r5)
    stfd f12, 0xf0(r5)
    stfd f13, 0xf8(r5)
    stfd f14, 0x100(r5)
    stfd f15, 0x108(r5)
    stfd f16, 0x110(r5)
    stfd f17, 0x118(r5)
    stfd f18, 0x120(r5)
    stfd f19, 0x128(r5)
    stfd f20, 0x130(r5)
    stfd f21, 0x138(r5)
    stfd f22, 0x140(r5)
    stfd f23, 0x148(r5)
    stfd f24, 0x150(r5)
    stfd f25, 0x158(r5)
    stfd f26, 0x160(r5)
    stfd f27, 0x168(r5)
    stfd f28, 0x170(r5)
    stfd f29, 0x178(r5)
    stfd f30, 0x180(r5)
    stfd f31, 0x188(r5)
    mffs f0
    stfd f0, 0x190(r5)
    lfd f0, 0x90(r5)
    mfspr r3, 920
    rlwinm. r3, r3, 3, 31, 31
    beq L_800F2900
    psq_st f0, 0x1c8(r5), 0, 0
    psq_st f1, 0x1d0(r5), 0, 0
    psq_st f2, 0x1d8(r5), 0, 0
    psq_st f3, 0x1e0(r5), 0, 0
    psq_st f4, 0x1e8(r5), 0, 0
    psq_st f5, 0x1f0(r5), 0, 0
    psq_st f6, 0x1f8(r5), 0, 0
    psq_st f7, 0x200(r5), 0, 0
    psq_st f8, 0x208(r5), 0, 0
    psq_st f9, 0x210(r5), 0, 0
    psq_st f10, 0x218(r5), 0, 0
    psq_st f11, 0x220(r5), 0, 0
    psq_st f12, 0x228(r5), 0, 0
    psq_st f13, 0x230(r5), 0, 0
    psq_st f14, 0x238(r5), 0, 0
    psq_st f15, 0x240(r5), 0, 0
    psq_st f16, 0x248(r5), 0, 0
    psq_st f17, 0x250(r5), 0, 0
    psq_st f18, 0x258(r5), 0, 0
    psq_st f19, 0x260(r5), 0, 0
    psq_st f20, 0x268(r5), 0, 0
    psq_st f21, 0x270(r5), 0, 0
    psq_st f22, 0x278(r5), 0, 0
    psq_st f23, 0x280(r5), 0, 0
    psq_st f24, 0x288(r5), 0, 0
    psq_st f25, 0x290(r5), 0, 0
    psq_st f26, 0x298(r5), 0, 0
    psq_st f27, 0x2a0(r5), 0, 0
    psq_st f28, 0x2a8(r5), 0, 0
    psq_st f29, 0x2b0(r5), 0, 0
    psq_st f30, 0x2b8(r5), 0, 0
    psq_st f31, 0x2c0(r5), 0, 0
L_800F2900:
    blr
}

asm void OSSaveFPUContext(void) {
    nofralloc
    addi r5, r3, 0x0
    b __OSSaveFPUContext_800F27DC
}

asm void OSSetCurrentContext(void) {
    nofralloc
    lis r4, 0x8000
    stw r3, 0xd4(r4)
    clrlwi r5, r3, 2
    stw r5, 0xc0(r4)
    lwz r5, 0xd8(r4)
    cmpw r5, r3
    bne L_800F2944
    lwz r6, 0x19c(r3)
    ori r6, r6, 0x2000
    stw r6, 0x19c(r3)
    mfmsr r6
    ori r6, r6, 0x2
    mtmsr r6
    blr
L_800F2944:
    lwz r6, 0x19c(r3)
    rlwinm r6, r6, 0, 19, 17
    stw r6, 0x19c(r3)
    mfmsr r6
    rlwinm r6, r6, 0, 19, 17
    ori r6, r6, 0x2
    mtmsr r6
    isync
    blr
}

/* clang-format on */
