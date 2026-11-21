/* Dolphin SDK OSSync.c system-call vector, GSQE78.
 * The SDK writes these routines as CodeWarrior asm functions.
 */
typedef unsigned long u32;
void __OSSystemCallVectorStart(void);
void __OSSystemCallVectorEnd(void);
/* clang-format off */
asm void __OSSystemCallVector(void) {
    nofralloc
entry __OSSystemCallVectorStart
    mfspr r9, HID0
    ori r10, r9, 0x8
    mtspr HID0, r10
    isync
    sync
    mtspr HID0, r9
    rfi
entry __OSSystemCallVectorEnd
    nop
}

/* clang-format on */
