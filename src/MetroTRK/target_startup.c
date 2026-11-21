/* MetroTRK file-service stubs and debugger kernel entry, GSQE78.
 * These routines are CodeWarrior asm functions in the debugger kernel;
 * the file stubs trap to the host debugger.
 */
typedef unsigned long u32;
void InitMetroTRKCommTable(void);
void TRKSaveExtended1Block(void);
void TRK_main(void);
void _db_stack_addr(void);
void gTRKCPUState(void);
/* clang-format off */
asm void TRKAccessFile(void) {
    nofralloc
    twi 31, r0, 0x0
    blr
}

asm void TRKOpenFile(void) {
    nofralloc
    twi 31, r0, 0x0
    blr
}

asm void TRKCloseFile(void) {
    nofralloc
    twi 31, r0, 0x0
    blr
}

asm void TRKPositionFile(void) {
    nofralloc
    twi 31, r0, 0x0
    blr
}

asm void InitMetroTRK(void) {
    nofralloc
    subi r1, r1, 0x4
    stw r3, 0x0(r1)
    lis r3, gTRKCPUState@h
    ori r3, r3, gTRKCPUState@l
    stmw r0, 0x0(r3)
    lwz r4, 0x0(r1)
    addi r1, r1, 0x4
    stw r1, 0x4(r3)
    stw r4, 0xc(r3)
    mflr r4
    stw r4, 0x84(r3)
    stw r4, 0x80(r3)
    mfcr r4
    stw r4, 0x88(r3)
    mfmsr r4
    ori r3, r4, 0x8000
    xori r3, r3, 0x8000
    mtmsr r3
    mtsrr1 r4
    bl TRKSaveExtended1Block
    lis r3, gTRKCPUState@h
    ori r3, r3, gTRKCPUState@l
    lmw r0, 0x0(r3)
    li r0, 0x0
    mtspr 1010, r0
    mtspr 1013, r0
    lis r1, _db_stack_addr@h
    ori r1, r1, _db_stack_addr@l
    mr r3, r5
    bl InitMetroTRKCommTable
    cmpwi r3, 0x1
    bne L_8011DD00
    lwz r4, 0x84(r3)
    mtlr r4
    lmw r0, 0x0(r3)
    blr
L_8011DD00:
    b TRK_main
}

/* clang-format on */
