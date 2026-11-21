/* Dolphin SDK OSTime.c time-base readers, GSQE78.
 * The SDK writes these routines as CodeWarrior asm functions.
 */
typedef unsigned long u32;
/* clang-format off */
asm void OSGetTime(void) {
    nofralloc
    mftb r3, 269
    mftb r4, 268
    mftb r5, 269
    cmpw r3, r5
    bne OSGetTime
    blr
}

asm void OSGetTick(void) {
    nofralloc
    mftb r3, 268
    blr
}

/* clang-format on */
