/* MetroTRK cache flush helper, GSQE78.
 * These routines are CodeWarrior asm functions in the debugger kernel.
 */
typedef unsigned long u32;
/* clang-format off */
asm void TRK_flush_cache(void) {
    nofralloc
    lis r5, 0xffff
    ori r5, r5, 0xfff1
    and r5, r5, r3
    subf r3, r5, r3
    add r4, r4, r3
L_8011C2E0:
    dcbst r0, r5
    dcbf r0, r5
    sync
    icbi r0, r5
    addic r5, r5, 0x8
    subic. r4, r4, 0x8
    bge L_8011C2E0
    isync
    blr
}

/* clang-format on */
