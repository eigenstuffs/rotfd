/* Dolphin SDK OSContext.c lazy FPU context switch exception entry, GSQE78.
 * The SDK writes these routines as CodeWarrior asm functions.
 */
typedef unsigned long u32;
void __OSLoadFPUContext_800F26B8(void);
void __OSSaveFPUContext_800F27DC(void);
/* clang-format off */
asm void OSSwitchFPUContext(void) {
    nofralloc
    mfmsr r5
    ori r5, r5, 0x2000
    mtmsr r5
    isync
    lwz r5, 0x19c(r4)
    ori r5, r5, 0x2000
    mtsrr1 r5
    lis r3, 0x8000
    lwz r5, 0xd8(r3)
    stw r4, 0xd8(r3)
    cmpw r5, r4
    beq L_800F2E9C
    cmpwi r5, 0x0
    beq L_800F2E98
    bl __OSSaveFPUContext_800F27DC
L_800F2E98:
    bl __OSLoadFPUContext_800F26B8
L_800F2E9C:
    lwz r3, 0x80(r4)
    mtcrf 255, r3
    lwz r3, 0x84(r4)
    mtlr r3
    lwz r3, 0x198(r4)
    mtsrr0 r3
    lwz r3, 0x88(r4)
    mtctr r3
    lwz r3, 0x8c(r4)
    mtxer r3
    lhz r3, 0x1a2(r4)
    rlwinm r3, r3, 0, 31, 29
    sth r3, 0x1a2(r4)
    lwz r5, 0x14(r4)
    lwz r3, 0xc(r4)
    lwz r4, 0x10(r4)
    rfi
}

/* clang-format on */
