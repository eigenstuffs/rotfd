/* Dolphin SDK OS.c exception vector fragment, GSQE78.
 * CodeWarrior asm functions as in the SDK (see reference/melee-sdk/OS.c);
 * this revision allocates a frame before entering __OSUnhandledException.
 */
typedef unsigned char u8;
typedef unsigned long u32;
typedef u8 __OSException;
typedef struct OSContext OSContext;

#define OS_CURRENTCONTEXT_PADDR 0x00C0
#define OS_EXCEPTIONTABLE_ADDR 0x3000
#define OS_CONTEXT_R0 0x0
#define OS_CONTEXT_R1 0x4
#define OS_CONTEXT_R2 0x8
#define OS_CONTEXT_R3 0xC
#define OS_CONTEXT_R4 0x10
#define OS_CONTEXT_R5 0x14
#define OS_CONTEXT_R6 0x18
#define OS_CONTEXT_CR 0x80
#define OS_CONTEXT_LR 0x84
#define OS_CONTEXT_CTR 0x88
#define OS_CONTEXT_XER 0x8C
#define OS_CONTEXT_SRR0 0x198
#define OS_CONTEXT_SRR1 0x19C
#define OS_CONTEXT_STATE 0x1A2
#define OS_CONTEXT_GQR1 0x1A8
#define OS_CONTEXT_GQR2 0x1AC
#define OS_CONTEXT_GQR3 0x1B0
#define OS_CONTEXT_GQR4 0x1B4
#define OS_CONTEXT_GQR5 0x1B8
#define OS_CONTEXT_GQR6 0x1BC
#define OS_CONTEXT_GQR7 0x1C0
#define OS_CONTEXT_STATE_EXC 0x02
#define MSR_RI_BIT 30

void OSDefaultExceptionHandler(register __OSException exception, register OSContext* context);
void __OSUnhandledException(__OSException exception, OSContext* context, u32 dsisr, u32 dar);
void __OSEVStart(void);
void __DBVECTOR(void);
void __OSEVSetNumber(void);
void __OSEVEnd(void);
extern u32 PPCMfhid2(void);
extern void PPCMthid2(u32);
extern void ICFlashInvalidate(void);

/* clang-format off */
static asm void OSExceptionVector(void) {
    nofralloc
entry __OSEVStart
    mtsprg  0, r4
    lwz     r4, OS_CURRENTCONTEXT_PADDR
    stw     r3, OS_CONTEXT_R3(r4)
    mfsprg  r3, 0
    stw     r3, OS_CONTEXT_R4(r4)
    stw     r5, OS_CONTEXT_R5(r4)
    lhz     r3, OS_CONTEXT_STATE(r4)
    ori     r3, r3, OS_CONTEXT_STATE_EXC
    sth     r3, OS_CONTEXT_STATE(r4)
    mfcr    r3
    stw     r3, OS_CONTEXT_CR(r4)
    mflr    r3
    stw     r3, OS_CONTEXT_LR(r4)
    mfctr   r3
    stw     r3, OS_CONTEXT_CTR(r4)
    mfxer   r3
    stw     r3, OS_CONTEXT_XER(r4)
    mfsrr0  r3
    stw     r3, OS_CONTEXT_SRR0(r4)
    mfsrr1  r3
    stw     r3, OS_CONTEXT_SRR1(r4)
    mr      r5, r3
entry __DBVECTOR
    nop
    mfmsr   r3
    ori     r3, r3, 0x30
    mtsrr1  r3
entry __OSEVSetNumber
    addi    r3, 0, 0x0000
    lwz     r4, 0xD4
    rlwinm. r5, r5, 0, MSR_RI_BIT, MSR_RI_BIT
    bne     recoverable
    addis   r5, 0, OSDefaultExceptionHandler@ha
    addi    r5, r5, OSDefaultExceptionHandler@l
    mtsrr0  r5
    rfi
recoverable:
    rlwinm  r5, r3, 2, 22, 29
    lwz     r5, OS_EXCEPTIONTABLE_ADDR(r5)
    mtsrr0  r5
    rfi
entry __OSEVEnd
    nop
}

asm void OSDefaultExceptionHandler(register __OSException exception, register OSContext* context) {
    nofralloc
    stw     r0, OS_CONTEXT_R0(context)
    stw     r1, OS_CONTEXT_R1(context)
    stw     r2, OS_CONTEXT_R2(context)
    stmw    r6, OS_CONTEXT_R6(context)
    mfspr   r0, GQR1
    stw     r0, OS_CONTEXT_GQR1(context)
    mfspr   r0, GQR2
    stw     r0, OS_CONTEXT_GQR2(context)
    mfspr   r0, GQR3
    stw     r0, OS_CONTEXT_GQR3(context)
    mfspr   r0, GQR4
    stw     r0, OS_CONTEXT_GQR4(context)
    mfspr   r0, GQR5
    stw     r0, OS_CONTEXT_GQR5(context)
    mfspr   r0, GQR6
    stw     r0, OS_CONTEXT_GQR6(context)
    mfspr   r0, GQR7
    stw     r0, OS_CONTEXT_GQR7(context)
    mfdsisr r5
    mfdar   r6
    stwu    r1, -8(r1)
    b       __OSUnhandledException
}
/* clang-format on */

void __OSPSInit(void)
{
    PPCMthid2(PPCMfhid2() | 0x80000000 | 0x20000000);
    ICFlashInvalidate();
    asm { sync }
    /* clang-format off */
    asm
    {
        li      r3, 0
        mtspr   GQR0, r3
    }
    /* clang-format on */
}
