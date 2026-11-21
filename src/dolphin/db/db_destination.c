/* Dolphin SDK db.c exception destination, GSQE78.
 * A CodeWarrior asm function as in the SDK; it enables address translation
 * before continuing in __DBExceptionDestinationAux.
 */
void __DBExceptionDestinationAux(void);

/* clang-format off */
asm void __DBExceptionDestination(void)
{
    nofralloc
    mfmsr   r3
    ori     r3, r3, 0x30
    mtmsr   r3
    b       __DBExceptionDestinationAux
}
/* clang-format on */
