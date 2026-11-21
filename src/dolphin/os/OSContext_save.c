/* Dolphin SDK OSContext.c register context save/load and stack pointer query, GSQE78.
 * The SDK writes these routines as CodeWarrior asm functions.
 */
typedef unsigned long u32;
void OSDisableInterrupts(void);
void xC(void);
/* clang-format off */
asm void OSSaveContext(void) {
    nofralloc
    stmw r13, 0x34(r3)
    mfspr r0, 913
    stw r0, 0x1a8(r3)
    mfspr r0, 914
    stw r0, 0x1ac(r3)
    mfspr r0, 915
    stw r0, 0x1b0(r3)
    mfspr r0, 916
    stw r0, 0x1b4(r3)
    mfspr r0, 917
    stw r0, 0x1b8(r3)
    mfspr r0, 918
    stw r0, 0x1bc(r3)
    mfspr r0, 919
    stw r0, 0x1c0(r3)
    mfcr r0
    stw r0, 0x80(r3)
    mflr r0
    stw r0, 0x84(r3)
    stw r0, 0x198(r3)
    mfmsr r0
    stw r0, 0x19c(r3)
    mfctr r0
    stw r0, 0x88(r3)
    mfxer r0
    stw r0, 0x8c(r3)
    stw r1, 0x4(r3)
    stw r2, 0x8(r3)
    li r0, 0x1
    stw r0, 0xc(r3)
    li r3, 0x0
    blr
}

asm void OSLoadContext(void) {
    nofralloc
    lis r4, OSDisableInterrupts@ha
    lwz r6, 0x198(r3)
    addi r5, r4, OSDisableInterrupts@l
    cmplw r6, r5
    ble L_800F2A1C
    lis r4, OSDisableInterrupts+0xC@ha
    addi r0, r4, OSDisableInterrupts+0xC@l
    cmplw r6, r0
    bge L_800F2A1C
    stw r5, 0x198(r3)
L_800F2A1C:
    lwz r0, 0x0(r3)
    lwz r1, 0x4(r3)
    lwz r2, 0x8(r3)
    lhz r4, 0x1a2(r3)
    rlwinm. r5, r4, 0, 30, 30
    beq L_800F2A44
    rlwinm r4, r4, 0, 31, 29
    sth r4, 0x1a2(r3)
    lmw r5, 0x14(r3)
    b L_800F2A48
L_800F2A44:
    lmw r13, 0x34(r3)
L_800F2A48:
    lwz r4, 0x1a8(r3)
    mtspr 913, r4
    lwz r4, 0x1ac(r3)
    mtspr 914, r4
    lwz r4, 0x1b0(r3)
    mtspr 915, r4
    lwz r4, 0x1b4(r3)
    mtspr 916, r4
    lwz r4, 0x1b8(r3)
    mtspr 917, r4
    lwz r4, 0x1bc(r3)
    mtspr 918, r4
    lwz r4, 0x1c0(r3)
    mtspr 919, r4
    lwz r4, 0x80(r3)
    mtcrf 255, r4
    lwz r4, 0x84(r3)
    mtlr r4
    lwz r4, 0x88(r3)
    mtctr r4
    lwz r4, 0x8c(r3)
    mtxer r4
    mfmsr r4
    rlwinm r4, r4, 0, 17, 15
    rlwinm r4, r4, 0, 31, 29
    mtmsr r4
    lwz r4, 0x198(r3)
    mtsrr0 r4
    lwz r4, 0x19c(r3)
    mtsrr1 r4
    lwz r4, 0x10(r3)
    lwz r3, 0xc(r3)
    rfi
}

asm void OSGetStackPointer(void) {
    nofralloc
    mr r3, r1
    blr
}

/* clang-format on */
