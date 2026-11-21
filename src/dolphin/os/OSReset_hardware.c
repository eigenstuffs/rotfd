/* Dolphin SDK OSReset.c hardware reset sequence, GSQE78.
 * The SDK writes these routines as CodeWarrior asm functions.
 */
typedef unsigned long u32;
/* clang-format off */
asm void OSResetHardware(void) {
    nofralloc
    b L_800F47E8
L_800F47CC:
    mfspr r8, HID0
    ori r8, r8, 0x8
    mtspr HID0, r8
    isync
    sync
    nop
    b L_800F47EC
L_800F47E8:
    b L_800F4808
L_800F47EC:
    mftb r5, 268
L_800F47F0:
    mftb r6, 268
    subf r7, r5, r6
    cmplwi r7, 0x1124
    blt L_800F47F0
    nop
    b L_800F480C
L_800F4808:
    b L_800F4828
L_800F480C:
    lis r8, 0xcc00
    ori r8, r8, 0x3000
    li r4, 0x3
    stw r4, 0x24(r8)
    stw r3, 0x24(r8)
    nop
    b L_800F482C
L_800F4828:
    b L_800F4834
L_800F482C:
    nop
    b L_800F482C
L_800F4834:
    b L_800F47CC
}

/* clang-format on */
