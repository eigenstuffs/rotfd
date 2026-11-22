#include "gx_abi.h"
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
typedef void (*GXOSInterruptHandler)(s16, OSContext *);
extern GXOSInterruptHandler __OSSetInterruptHandler(s16, GXOSInterruptHandler);
extern u32 __OSUnmaskInterrupts(u32);
extern void OSClearContext(OSContext *), OSSetCurrentContext(OSContext *);
extern s32 OSResumeThread(OSThread *), OSSuspendThread(OSThread *);
extern OSThread *OSGetCurrentThread(void);
extern BOOL OSDisableInterrupts(void), OSRestoreInterrupts(BOOL);
extern void PPCSync(void);
extern u32 PPCMfwpar(void);
#define OSPhysicalToCached(p) ((void *)((u32)(p) + 0x80000000))
static struct __GXFifoObj *CPUFifo;
static struct __GXFifoObj *GPFifo;
static OSThread *__GXCurrentThread;
static GXBool CPGPLinked;
static BOOL GXOverflowSuspendInProgress;
static GXBreakPtCallback BreakPointCB;
static u32 __GXOverflowCount;
#if DEBUG
static int IsWGPipeRedirected;
#endif

static void __GXFifoReadEnable(void);
static void __GXFifoReadDisable(void);
static void __GXFifoLink(u8 arg0);
static void __GXWriteFifoIntEnable(u8 arg0, u8 arg1);
static void __GXWriteFifoIntReset(u8 arg0, u8 arg1);

#if DEBUG
static char __data_0[] = "[GXOverflowHandler]";
#endif

static inline void GXOverflowHandler(s16 interrupt, OSContext *context)
{
#if DEBUG
    if (__gxVerif->verifyLevel > 1) {
        OSReport(__data_0);
    }
#endif
    ASSERTLINE(0x15A, !GXOverflowSuspendInProgress);

    __GXOverflowCount++;
    __GXWriteFifoIntEnable(0, 1);
    __GXWriteFifoIntReset(1, 0);
    GXOverflowSuspendInProgress = TRUE;

#if DEBUG
    if (__gxVerif->verifyLevel > 1) {
        OSReport("[GXOverflowHandler Sleeping]");
    }
#endif
    OSSuspendThread(__GXCurrentThread);
}

static inline void GXUnderflowHandler(s16 interrupt, OSContext *context)
{
#if DEBUG
    if (__gxVerif->verifyLevel > 1) {
        OSReport("[GXUnderflowHandler]");
    }
#endif
    ASSERTLINE(0x184, GXOverflowSuspendInProgress);

    OSResumeThread(__GXCurrentThread);
    GXOverflowSuspendInProgress = FALSE;
    __GXWriteFifoIntReset(1U, 1U);
    __GXWriteFifoIntEnable(1U, 0U);
}

static inline void GXBreakPointHandler(s16 interrupt, OSContext *context)
{
    OSContext exceptionContext;

    gx->cpEnable = gx->cpEnable & 0xFFFFFFDF;
    __cpReg[1] = gx->cpEnable;
    if (BreakPointCB != NULL) {
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        BreakPointCB();
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}

static void GXCPInterruptHandler(s16 interrupt, OSContext *context)
{
    gx->cpStatus = __cpReg[0];
    if (GET_REG_FIELD(gx->cpEnable, 1, 3) && GET_REG_FIELD(gx->cpStatus, 1, 1)) {
        GXUnderflowHandler(interrupt, context);
    }
    if (GET_REG_FIELD(gx->cpEnable, 1, 2) && GET_REG_FIELD(gx->cpStatus, 1, 0)) {
        GXOverflowHandler(interrupt, context);
    }
    if (GET_REG_FIELD(gx->cpEnable, 1, 5) && GET_REG_FIELD(gx->cpStatus, 1, 4)) {
        GXBreakPointHandler(interrupt, context);
    }
}

void GXInitFifoBase(GXFifoObj *fifo, void *base, u32 size)
{
    struct __GXFifoObj *realFifo = (struct __GXFifoObj *)fifo;

    ASSERTMSGLINE(0x1FF, realFifo != CPUFifo,     "GXInitFifoBase: fifo is attached to CPU");
    ASSERTMSGLINE(0x201, realFifo != GPFifo,      "GXInitFifoBase: fifo is attached to GP");
    ASSERTMSGLINE(0x203, ((u32)base & 0x1F) == 0, "GXInitFifoBase: base must be 32B aligned");
    ASSERTMSGLINE(0x205, base != NULL,            "GXInitFifoBase: base pointer is NULL");
    ASSERTMSGLINE(0x207, (size & 0x1F) == 0,      "GXInitFifoBase: size must be 32B aligned");
    ASSERTMSGLINE(0x209, size >= 0x10000,         "GXInitFifoBase: fifo is not large enough");

    realFifo->base = base;
    realFifo->top = (u8 *)base + size - 4;
    realFifo->size = size;
    realFifo->count = 0;
    GXInitFifoLimits(fifo, size - 0x4000, (size >> 1) & ~0x1F);
    GXInitFifoPtrs(fifo, base, base);
}

void GXInitFifoPtrs(GXFifoObj *fifo, void *readPtr, void *writePtr)
{
    struct __GXFifoObj *realFifo = (struct __GXFifoObj *)fifo;
    BOOL enabled;

    ASSERTMSGLINE(0x231, realFifo != CPUFifo,         "GXInitFifoPtrs: fifo is attached to CPU");
    ASSERTMSGLINE(0x233, realFifo != GPFifo,          "GXInitFifoPtrs: fifo is attached to GP");
    ASSERTMSGLINE(0x235, ((u32)readPtr & 0x1F) == 0,  "GXInitFifoPtrs: readPtr not 32B aligned");
    ASSERTMSGLINE(0x237, ((u32)writePtr & 0x1F) == 0, "GXInitFifoPtrs: writePtr not 32B aligned");
    ASSERTMSGLINE(0x23A, realFifo->base <= readPtr && readPtr < realFifo->top,   "GXInitFifoPtrs: readPtr not in fifo range");
    ASSERTMSGLINE(0x23D, realFifo->base <= writePtr && writePtr < realFifo->top, "GXInitFifoPtrs: writePtr not in fifo range");

    enabled = OSDisableInterrupts();
    realFifo->rdPtr = readPtr;
    realFifo->wrPtr = writePtr;
    realFifo->count = (u8 *)writePtr - (u8 *)readPtr;
    if (realFifo->count < 0) {
        realFifo->count += realFifo->size;
    }
    OSRestoreInterrupts(enabled);
}

void GXInitFifoLimits(GXFifoObj *fifo, u32 hiWatermark, u32 loWatermark)
{
    struct __GXFifoObj *realFifo = (struct __GXFifoObj *)fifo;

    ASSERTMSGLINE(0x262, realFifo != GPFifo,        "GXInitFifoLimits: fifo is attached to GP");
    ASSERTMSGLINE(0x264, (hiWatermark & 0x1F) == 0, "GXInitFifoLimits: hiWatermark not 32B aligned");
    ASSERTMSGLINE(0x266, (loWatermark & 0x1F) == 0, "GXInitFifoLimits: loWatermark not 32B aligned");
    ASSERTMSGLINE(0x268, hiWatermark < realFifo->top - realFifo->base, "GXInitFifoLimits: hiWatermark too large");
    ASSERTMSGLINE(0x26A, loWatermark < hiWatermark, "GXInitFifoLimits: hiWatermark below lo watermark");

    realFifo->hiWatermark = hiWatermark;
    realFifo->loWatermark = loWatermark;
}

void GXSetCPUFifo(GXFifoObj *fifo)
{
    struct __GXFifoObj *realFifo = (struct __GXFifoObj *)fifo;
    BOOL enabled;
    u32 reg;

    enabled = OSDisableInterrupts();

    CPUFifo = realFifo;
    if (CPUFifo == GPFifo)
    {
        __piReg[3] = (u32)realFifo->base & 0x3FFFFFFF;
        __piReg[4] = (u32)realFifo->top & 0x3FFFFFFF;
        reg = (u32)realFifo->wrPtr & 0x3FFFFFE0;
        reg &= 0xFBFFFFFF;
        __piReg[5] = reg;
        CPGPLinked = GX_TRUE;
        __GXWriteFifoIntReset(1, 1);
        __GXWriteFifoIntEnable(1, 0);
        __GXFifoLink(1);
    }
    else
    {
        if (CPGPLinked)
        {
            __GXFifoLink(0);
            CPGPLinked = GX_FALSE;
        }
        __GXWriteFifoIntEnable(0, 0);
        __piReg[3] = (u32)realFifo->base & 0x3FFFFFFF;
        __piReg[4] = (u32)realFifo->top & 0x3FFFFFFF;
        reg = (u32)realFifo->wrPtr & 0x3FFFFFE0;
        reg &= 0xFBFFFFFF;
        __piReg[5] = reg;
    }

    PPCSync();

    OSRestoreInterrupts(enabled);
}

void GXSetGPFifo(GXFifoObj *fifo)
{
    struct __GXFifoObj *realFifo = (struct __GXFifoObj *)fifo;
    BOOL enabled = OSDisableInterrupts();

    __GXFifoReadDisable();
    __GXWriteFifoIntEnable(0, 0);
    GPFifo = realFifo;

    __cpReg[16] = (u32)realFifo->base & 0xFFFF;
    __cpReg[18] = (u32)realFifo->top & 0xFFFF;
    __cpReg[24] = realFifo->count & 0xFFFF;
    __cpReg[26] = (u32)realFifo->wrPtr & 0xFFFF;
    __cpReg[28] = (u32)realFifo->rdPtr & 0xFFFF;
    __cpReg[20] = (u32)realFifo->hiWatermark & 0xFFFF;
    __cpReg[22] = (u32)realFifo->loWatermark & 0xFFFF;
    __cpReg[17] = ((u32)realFifo->base & 0x3FFFFFFF) >> 16;
    __cpReg[19] = ((u32)realFifo->top & 0x3FFFFFFF) >> 16;
    __cpReg[25] = realFifo->count >> 16;
    __cpReg[27] = ((u32)realFifo->wrPtr & 0x3FFFFFFF) >> 16;
    __cpReg[29] = ((u32)realFifo->rdPtr & 0x3FFFFFFF) >> 16;
    __cpReg[21] = (u32)realFifo->hiWatermark >> 16;
    __cpReg[23] = (u32)realFifo->loWatermark >> 16;

    PPCSync();

    if (CPUFifo == GPFifo) {
        CPGPLinked = GX_TRUE;
        __GXWriteFifoIntEnable(1, 0);
        __GXFifoLink(1);
    }
    else {
        CPGPLinked = GX_FALSE;
        __GXWriteFifoIntEnable(0, 0);
        __GXFifoLink(0);
    }
    __GXWriteFifoIntReset(1, 1);
    __GXFifoReadEnable();
    OSRestoreInterrupts(enabled);
}

void GXSaveCPUFifo(GXFifoObj *fifo)
{
    struct __GXFifoObj *realFifo = (struct __GXFifoObj *)fifo;
    ASSERTMSGLINE(0x321, realFifo == CPUFifo, "GXSaveCPUFifo: fifo is not attached to CPU");
    __GXSaveCPUFifoAux(realFifo);
}

#define SOME_MACRO1(fifo) \
do { \
    u32 temp = __cpReg[29] << 16; \
    temp |= __cpReg[28]; \
    fifo->rdPtr = OSPhysicalToCached(temp); \
} while (0)

#define SOME_MACRO2(fifo) \
do { \
    u32 temp = __cpReg[25] << 16; \
    temp |= __cpReg[24]; \
    fifo->count = temp; \
} while (0)

void __GXSaveCPUFifoAux(struct __GXFifoObj *realFifo)
{
    BOOL enabled = OSDisableInterrupts();

    GXFlush();
    realFifo->base = OSPhysicalToCached(__piReg[3]);
    realFifo->top = OSPhysicalToCached(__piReg[4]);
    realFifo->wrPtr = OSPhysicalToCached(__piReg[5] & 0xFBFFFFFF);
    if (CPGPLinked) {
        SOME_MACRO1(realFifo);
        SOME_MACRO2(realFifo);
    } else {
        realFifo->count = (u8 *)realFifo->wrPtr - (u8 *)realFifo->rdPtr;
        if (realFifo->count < 0)
            realFifo->count += realFifo->size;
    }
    OSRestoreInterrupts(enabled);
}

static inline void *GXGetFifoBase(GXFifoObj *fifo)
{
    struct __GXFifoObj *realFifo = (struct __GXFifoObj *)fifo;

    return realFifo->base;
}

void __GXFifoInit(void)
{
    __OSSetInterruptHandler(0x11, GXCPInterruptHandler);
    __OSUnmaskInterrupts(0x4000);
    __GXCurrentThread = OSGetCurrentThread();
    GXOverflowSuspendInProgress = FALSE;
    CPUFifo = NULL;
    GPFifo = NULL;
}

static void __GXFifoReadEnable(void)
{
    SET_REG_FIELD(0, gx->cpEnable, 1, 0, 1);
    __cpReg[1] = gx->cpEnable;
}

static void __GXFifoReadDisable(void)
{
    SET_REG_FIELD(0, gx->cpEnable, 1, 0, 0);
    __cpReg[1] = gx->cpEnable;
}

static void __GXFifoLink(u8 en)
{
    SET_REG_FIELD(0x4B0, gx->cpEnable, 1, 4, (en != 0) ? 1 : 0);
    __cpReg[1] = gx->cpEnable;
}

static void __GXWriteFifoIntEnable(u8 hiWatermarkEn, u8 loWatermarkEn)
{
    SET_REG_FIELD(0x4C6, gx->cpEnable, 1, 2, hiWatermarkEn);
    SET_REG_FIELD(0x4C7, gx->cpEnable, 1, 3, loWatermarkEn);
    __cpReg[1] = gx->cpEnable;
}

static void __GXWriteFifoIntReset(u8 hiWatermarkClr, u8 loWatermarkClr)
{
    SET_REG_FIELD(0x4DE, gx->cpClr, 1, 0, hiWatermarkClr);
    SET_REG_FIELD(0x4DF, gx->cpClr, 1, 1, loWatermarkClr);
    __cpReg[2] = gx->cpClr;
}

void __GXCleanGPFifo(void)
{
    GXFifoObj dummyFifo;
    GXFifoObj *gpFifo = GXGetGPFifo();
    GXFifoObj *cpuFifo;
    void *base;
    if (gpFifo == NULL) {
        return;
    }
    cpuFifo = GXGetCPUFifo();
    base = GXGetFifoBase(gpFifo);

    dummyFifo = *gpFifo;
    GXInitFifoPtrs(&dummyFifo, base, base);
    GXSetGPFifo(&dummyFifo);
    if (cpuFifo == gpFifo) {
        GXSetCPUFifo(&dummyFifo);
    }
    GXInitFifoPtrs(gpFifo, base, base);
    GXSetGPFifo(gpFifo);
    if (cpuFifo == gpFifo) {
        GXSetCPUFifo(cpuFifo);
    }
}

GXFifoObj *GXGetCPUFifo(void)
{
    return (GXFifoObj *)CPUFifo;
}

GXFifoObj *GXGetGPFifo(void)
{
    return (GXFifoObj *)GPFifo;
}

