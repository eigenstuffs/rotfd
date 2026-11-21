/* Dolphin SDK OSInterrupt.c external interrupt exception entry, GSQE78.
 * The SDK writes these routines as CodeWarrior asm functions.
 */
typedef unsigned long u32;
void __OSDispatchInterrupt(void);
/* clang-format off */
asm void ExternalInterruptHandler(void) {
    nofralloc
    stw r0, 0x0(r4)
    stw r1, 0x4(r4)
    stw r2, 0x8(r4)
    stmw r6, 0x18(r4)
    mfspr r0, 913
    stw r0, 0x1a8(r4)
    mfspr r0, 914
    stw r0, 0x1ac(r4)
    mfspr r0, 915
    stw r0, 0x1b0(r4)
    mfspr r0, 916
    stw r0, 0x1b4(r4)
    mfspr r0, 917
    stw r0, 0x1b8(r4)
    mfspr r0, 918
    stw r0, 0x1bc(r4)
    mfspr r0, 919
    stw r0, 0x1c0(r4)
    stwu r1, -0x8(r1)
    b __OSDispatchInterrupt
}

/* clang-format on */
