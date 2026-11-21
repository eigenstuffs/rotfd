/* Dolphin SDK cache management C routines, GSQE78.
 * Adapted from doldecomp/melee; see reference/melee-sdk/PROVENANCE.md.
 * The cache-instruction routines are CodeWarrior asm functions, as in the SDK.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef double f64;
typedef int BOOL;
typedef u16 OSError;
typedef struct OSContext
{
    /*0x000*/ u32 gpr[32];
    /*0x080*/ u32 cr;
    /*0x084*/ u32 lr;
    /*0x088*/ u32 ctr;
    /*0x08C*/ u32 xer;
    /*0x090*/ f64 fpr[32];
    /*0x190*/ u32 fpscr_pad;
    /*0x194*/ u32 fpscr;
    /*0x198*/ u32 srr0;
    /*0x19C*/ u32 srr1;
    /*0x1A0*/ u16 mode;
    /*0x1A2*/ u16 state;
    /*0x1A4*/ u32 gqr[8];
    /*0x1C4*/ f64 psf[32];
} OSContext;

#define MSR_IR          0x00000020  // instruction relocate
#define MSR_DR          0x00000010  // data relocate
#define HID0_ICE        0x00008000u  // Instruction cache enable
#define HID0_DCE        0x00004000u  // Data cache enable
#define HID2_DCHERR         0x00800000  // ERROR: dcbz_l cache hit
#define HID2_DNCERR         0x00400000  // ERROR: DMA access to normal cache
#define HID2_DCMERR         0x00200000  // ERROR: DMA cache miss error
#define HID2_DQOERR         0x00100000  // ERROR: DMA queue overflow
#define SRR1_DMA_BIT                0x00200000
#define L2CR_L2E                    0x80000000  // L2 Enable
#define L2CR_L2I                    0x00200000  // Global invalidate

#define OS_ERROR_MACHINE_CHECK 1
extern u32 PPCMfmsr(void), PPCMfhid0(void), PPCMfhid2(void), PPCMfl2cr(void);
extern void PPCMtmsr(u32), PPCMthid2(u32), PPCMtl2cr(u32), PPCHalt(void);
extern void __sync(void);
extern void DCEnable(void), ICEnable(void), L2GlobalInvalidate(void);
extern void OSDumpContext(OSContext *);
extern void OSReport(const char *, ...), DBPrintf(const char *, ...);
typedef void (*OSErrorHandler)(OSError, OSContext *, ...);
extern OSErrorHandler OSSetErrorHandler(OSError, OSErrorHandler);
#define HID2 920

/* clang-format off */
asm void DCEnable(void) {
  nofralloc
  sync
  mfspr r3, HID0
  ori r3, r3, 0x4000
  mtspr HID0, r3
  blr
}

asm void DCInvalidateRange(register void* addr, register u32 nBytes) {
  nofralloc
  cmplwi nBytes, 0
  blelr
  clrlwi r5, addr, 27
  add nBytes, nBytes, r5
  addi nBytes, nBytes, 31
  srwi nBytes, nBytes, 5
  mtctr nBytes
@1
  dcbi r0, addr
  addi addr, addr, 32
  bdnz @1
  blr
}

asm void DCFlushRange(register void* addr, register u32 nBytes) {
  nofralloc
  cmplwi nBytes, 0
  blelr
  clrlwi r5, addr, 27
  add nBytes, nBytes, r5
  addi nBytes, nBytes, 31
  srwi nBytes, nBytes, 5
  mtctr nBytes
@1
  dcbf r0, addr
  addi addr, addr, 32
  bdnz @1
  sc
  blr
}

asm void DCStoreRange(register void* addr, register u32 nBytes) {
  nofralloc
  cmplwi nBytes, 0
  blelr
  clrlwi r5, addr, 27
  add nBytes, nBytes, r5
  addi nBytes, nBytes, 31
  srwi nBytes, nBytes, 5
  mtctr nBytes
@1
  dcbst r0, addr
  addi addr, addr, 32
  bdnz @1
  sc
  blr
}

asm void DCFlushRangeNoSync(register void* addr, register u32 nBytes) {
  nofralloc
  cmplwi nBytes, 0
  blelr
  clrlwi r5, addr, 27
  add nBytes, nBytes, r5
  addi nBytes, nBytes, 31
  srwi nBytes, nBytes, 5
  mtctr nBytes
@1
  dcbf r0, addr
  addi addr, addr, 32
  bdnz @1
  blr
}

/* DCStoreRangeNoSync; the target keeps its unnamed symbol. */
asm void fn_800F22F4(register void* addr, register u32 nBytes) {
  nofralloc
  cmplwi nBytes, 0
  blelr
  clrlwi r5, addr, 27
  add nBytes, nBytes, r5
  addi nBytes, nBytes, 31
  srwi nBytes, nBytes, 5
  mtctr nBytes
@1
  dcbst r0, addr
  addi addr, addr, 32
  bdnz @1
  blr
}

/* DCTouchRange; the target keeps its unnamed symbol. */
asm void fn_800F2320(register void* addr, register u32 nBytes) {
  nofralloc
  cmplwi nBytes, 0
  blelr
  clrlwi r5, addr, 27
  add nBytes, nBytes, r5
  addi nBytes, nBytes, 31
  srwi nBytes, nBytes, 5
  mtctr nBytes
@1
  dcbt r0, addr
  addi addr, addr, 32
  bdnz @1
  blr
}

asm void ICInvalidateRange(register void* addr, register u32 nBytes) {
  nofralloc
  cmplwi nBytes, 0
  blelr
  clrlwi r5, addr, 27
  add nBytes, nBytes, r5
  addi nBytes, nBytes, 31
  srwi nBytes, nBytes, 5
  mtctr nBytes
@1
  icbi r0, addr
  addi addr, addr, 32
  bdnz @1
  sync
  isync
  blr
}

asm void ICFlashInvalidate(void) {
  nofralloc
  mfspr r3, HID0
  ori r3, r3, 0x800
  mtspr HID0, r3
  blr
}

asm void ICEnable(void) {
  nofralloc
  isync
  mfspr r3, HID0
  ori r3, r3, 0x8000
  mtspr HID0, r3
  blr
}

asm void LCDisable(void) {
  nofralloc
  lis r3, 0xE000
  li r4, 512
  mtctr r4
@1
  dcbi r0, r3
  addi r3, r3, 32
  bdnz @1
  mfspr r4, HID2
  rlwinm r4, r4, 0, 4, 2
  mtspr HID2, r4
  blr
}
/* clang-format on */

static inline void L2Disable(void);
static inline void L2Init(void) {
  u32 oldMSR;
  oldMSR = PPCMfmsr();
  __sync();
  PPCMtmsr(MSR_IR | MSR_DR);
  __sync();
  L2Disable();
  L2GlobalInvalidate();
  PPCMtmsr(oldMSR);
}

static inline void L2Enable(void) { 
    PPCMtl2cr((PPCMfl2cr() | L2CR_L2E) & ~L2CR_L2I);
}

/* clang-format on */
static inline void L2Disable(void) {
  __sync();
  PPCMtl2cr(PPCMfl2cr() & ~0x80000000);
  __sync();
}

void L2GlobalInvalidate(void) {
  L2Disable();
  PPCMtl2cr(PPCMfl2cr() | 0x00200000);
  while (PPCMfl2cr() & 0x00000001u)
    ;
  PPCMtl2cr(PPCMfl2cr() & ~0x00200000);
  while (PPCMfl2cr() & 0x00000001u) {
    DBPrintf(">>> L2 INVALIDATE : SHOULD NEVER HAPPEN\n");
  }
}

static inline void L2SetDataOnly(BOOL dataOnly) {
    if (dataOnly) {
        PPCMtl2cr(PPCMfl2cr() | 0x400000);
        return;
    }
    PPCMtl2cr(PPCMfl2cr() & 0xFFBFFFFF);
}

static inline void L2SetWriteThrough(BOOL writeThrough) {
    if (writeThrough) {
        PPCMtl2cr(PPCMfl2cr() | 0x80000);
        return;
    }
    PPCMtl2cr(PPCMfl2cr() & 0xFFF7FFFF);
}

void DMAErrorHandler(OSError error, OSContext* context, ...) {
  u32 hid2 = PPCMfhid2();

  OSReport("Machine check received\n");
  OSReport("HID2 = 0x%x   SRR1 = 0x%x\n", hid2, context->srr1);
  if (!(hid2 & (HID2_DCHERR | HID2_DNCERR | HID2_DCMERR | HID2_DQOERR)) ||
      !(context->srr1 & SRR1_DMA_BIT)) {
    OSReport("Machine check was not DMA/locked cache related\n");
    OSDumpContext(context);
    PPCHalt();
  }

  OSReport("DMAErrorHandler(): An error occurred while processing DMA.\n");
  OSReport("The following errors have been detected and cleared :\n");

  if (hid2 & HID2_DCHERR) {
    OSReport("\t- Requested a locked cache tag that was already in the cache\n");
  }

  if (hid2 & HID2_DNCERR) {
    OSReport("\t- DMA attempted to access normal cache\n");
  }

  if (hid2 & HID2_DCMERR) {
    OSReport("\t- DMA missed in data cache\n");
  }

  if (hid2 & HID2_DQOERR) {
    OSReport("\t- DMA queue overflowed\n");
  }

  // write hid2 back to clear the error bits
  PPCMthid2(hid2);
}

void __OSCacheInit() {
  if (!(PPCMfhid0() & HID0_ICE)) {
    ICEnable();
    DBPrintf("L1 i-caches initialized\n");
  }
  if (!(PPCMfhid0() & HID0_DCE)) {
    DCEnable();
    DBPrintf("L1 d-caches initialized\n");
  }

  if (!(PPCMfl2cr() & L2CR_L2E)) {
    L2Init();
    L2Enable();
    DBPrintf("L2 cache initialized\n");
  }

  OSSetErrorHandler(OS_ERROR_MACHINE_CHECK, DMAErrorHandler);
  DBPrintf("Locked cache machine check handler installed\n");
}
