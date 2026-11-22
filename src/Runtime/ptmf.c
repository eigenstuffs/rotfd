typedef struct __ptmf {
    long this_delta;
    long v_offset;
    union {
        void* f_addr;
        long ve_offset;
    } f_data;
} __ptmf;

const __ptmf __ptmf_null = { 0, 0, 0 };

/* clang-format off */
asm void __ptmf_test(void) {
    nofralloc
    lwz r5, 0x0(r3)
    lwz r6, 0x4(r3)
    lwz r7, 0x8(r3)
    li r3, 0x1
    cmpwi r5, 0x0
    cmpwi cr6, r6, 0x0
    cmpwi cr7, r7, 0x0
    bnelr
    bnelr cr6
    bnelr cr7
    li r3, 0x0
    blr
}

asm void __ptmf_cmpr(void) {
    nofralloc
    lwz r5, 0x0(r3)
    lwz r6, 0x0(r4)
    lwz r7, 0x4(r3)
    lwz r8, 0x4(r4)
    lwz r9, 0x8(r3)
    lwz r10, 0x8(r4)
    li r3, 0x1
    cmpw r5, r6
    cmpw cr6, r7, r8
    cmpw cr7, r9, r10
    bnelr
    bnelr cr6
    bnelr cr7
    li r3, 0x0
    blr
}

asm void __ptmf_scall(void) {
    nofralloc
    lwz r0, 0x0(r12)
    lwz r11, 0x4(r12)
    lwz r12, 0x8(r12)
    add r3, r3, r0
    cmpwi r11, 0x0
    blt L_8011F4EC
    lwzx r12, r3, r12
    lwzx r12, r12, r11
L_8011F4EC:
    mtctr r12
    bctr
}
/* clang-format on */
