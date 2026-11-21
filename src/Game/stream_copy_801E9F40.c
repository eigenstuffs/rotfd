/* fn_801E9F40 copies `size` bytes from a stream cursor (one byte first when
 * the size is odd, then halfwords) and returns the advanced cursor. It is
 * hand-written assembly: it touches the source line with dcbt, masks with
 * andi. and compares against a register holding zero, none of which the
 * compiler produces from C (it emits clrlwi and folds the zero), so it is
 * kept as an asm function body like the SDK's assembly routines. */
asm const void* fn_801E9F40(void* dst, const void* src, unsigned long size) {
    nofralloc
    dcbt r0, r4
    li r6, 0x0
    cmplw r6, r5
    beq L_801E9F84
    andi. r0, r5, 0x1
    cmplw r6, r0
    beq L_801E9F70
    lbzx r0, r4, r6
    stbx r0, r3, r6
    addi r6, r6, 0x1
    cmplwi r5, 0x1
    beq L_801E9F84
L_801E9F70:
    lhzx r0, r4, r6
    sthx r0, r3, r6
    addi r6, r6, 0x2
    cmplw r6, r5
    blt L_801E9F70
L_801E9F84:
    add r3, r4, r5
    blr
}
