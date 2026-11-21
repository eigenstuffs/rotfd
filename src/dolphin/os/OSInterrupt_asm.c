/* Dolphin SDK OSInterrupt.c MSR[EE] disable/enable/restore, GSQE78.
 * The SDK writes these routines as CodeWarrior asm functions.
 */
typedef unsigned long u32;
/* clang-format off */
asm void OSDisableInterrupts(void) {
    nofralloc
    mfmsr r3
    rlwinm r4, r3, 0, 17, 15
    mtmsr r4
    rlwinm r3, r3, 17, 31, 31
    blr
}

asm void OSEnableInterrupts(void) {
    nofralloc
    mfmsr r3
    ori r4, r3, 0x8000
    mtmsr r4
    rlwinm r3, r3, 17, 31, 31
    blr
}

asm void OSRestoreInterrupts(void) {
    nofralloc
    cmpwi r3, 0x0
    mfmsr r4
    beq L_800F3668
    ori r5, r4, 0x8000
    b L_800F366C
L_800F3668:
    rlwinm r5, r4, 0, 17, 15
L_800F366C:
    mtmsr r5
    rlwinm r3, r4, 17, 31, 31
    blr
}

/* clang-format on */
