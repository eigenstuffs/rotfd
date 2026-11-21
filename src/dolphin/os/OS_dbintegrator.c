/* Dolphin SDK OS.c debugger integrator fragment, GSQE78.
 * CodeWarrior asm functions as in the SDK (see reference/melee-sdk/OS.c).
 * OSExceptionInit copies these instructions between the entry labels.
 */
#define OS_DBINTERFACE_ADDR 0x00000040
#define DB_EXCEPTIONRET_OFFSET 0xC
#define DB_EXCEPTIONDEST_OFFSET 0x8
#define OS_CACHED_REGION_PREFIX 0x8000
#define OS_DBJUMPPOINT_ADDR 0x60

void __OSDBINTSTART(void);
void __OSDBINTEND(void);
void __OSDBJUMPEND(void);

/* clang-format off */
static asm void __OSDBIntegrator(void) {
    nofralloc
entry __OSDBINTSTART
    li      r5, OS_DBINTERFACE_ADDR
    mflr    r3
    stw     r3, DB_EXCEPTIONRET_OFFSET(r5)
    lwz     r3, DB_EXCEPTIONDEST_OFFSET(r5)
    oris    r3, r3, OS_CACHED_REGION_PREFIX
    mtlr    r3
    li      r3, 0x30
    mtmsr   r3
    blr
entry __OSDBINTEND
}

asm void __OSDBJUMPSTART(void) {
    nofralloc
    bla     OS_DBJUMPPOINT_ADDR
entry __OSDBJUMPEND
}
/* clang-format on */
