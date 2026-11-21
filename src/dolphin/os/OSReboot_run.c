/* Dolphin SDK OSReboot.c reboot entry, GSQE78.
 * The SDK writes these routines as CodeWarrior asm functions.
 */
typedef unsigned long u32;
/* clang-format off */
asm void OSRebootRun(void) {
    nofralloc
    sync
    isync
    mtlr r3
    blr
}

/* clang-format on */
