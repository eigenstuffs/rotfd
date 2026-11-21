/* Dolphin SDK PPCArch.c, GSQE78 revision.
 * Register accessors follow the SDK's CodeWarrior asm functions (see
 * reference/melee-sdk/PPCArch.c); this revision also provides the FPSCR
 * accessors, HID2/WPAR accessors and the non-IEEE mode helper.
 */
typedef unsigned long u32;
typedef double f64;

#define HID2 920
#define WPAR 921

union FpscrUnion {
    f64 f;
    struct {
        u32 fpscr_pad;
        u32 fpscr;
    } u;
};

/* clang-format off */
asm u32 PPCMfmsr(void) {
    nofralloc
    mfmsr r3
    blr
}

asm void PPCMtmsr(register u32 newMSR) {
    nofralloc
    mtmsr newMSR
    blr
}

asm u32 PPCMfhid0(void) {
    nofralloc
    mfspr r3, HID0
    blr
}

asm void PPCMthid0(register u32 newHID0) {
    nofralloc
    mtspr HID0, newHID0
    blr
}

asm u32 PPCMfl2cr(void) {
    nofralloc
    mfspr r3, L2CR
    blr
}

asm void PPCMtl2cr(register u32 newL2cr) {
    nofralloc
    mtspr L2CR, newL2cr
    blr
}

asm void PPCMtdec(register u32 newDec) {
    nofralloc
    mtdec newDec
    blr
}

asm void PPCSync(void) {
    nofralloc
    sc
    blr
}

asm void PPCHalt(void) {
    nofralloc
    sync
loop:
    nop
    li r3, 0
    nop
    b loop
}
/* clang-format on */

u32 PPCMffpscr(void)
{
    union FpscrUnion m;

    asm {
        mffs fp31
        stfd fp31, m.f
    }

    return m.u.fpscr;
}

void PPCMtfpscr(register u32 newFPSCR)
{
    union FpscrUnion m;

    asm {
        li r4, 0
        stw r4, m.u.fpscr_pad
        stw newFPSCR, m.u.fpscr
        lfd fp31, m.f
        mtfsf 0xff, fp31
    }
}

/* clang-format off */
asm u32 PPCMfhid2(void) {
    nofralloc
    mfspr r3, HID2
    blr
}

asm void PPCMthid2(register u32 newhid2) {
    nofralloc
    mtspr HID2, newhid2
    blr
}

asm u32 PPCMfwpar(void) {
    nofralloc
    sync
    mfspr r3, WPAR
    blr
}

asm void PPCMtwpar(register u32 newwpar) {
    nofralloc
    mtspr WPAR, newwpar
    blr
}
/* clang-format on */

void PPCDisableSpeculation(void)
{
    PPCMthid0(PPCMfhid0() | 0x200);
}

/* clang-format off */
asm void PPCSetFpNonIEEEMode(void) {
    nofralloc
    mtfsb1 29
    blr
}
/* clang-format on */
