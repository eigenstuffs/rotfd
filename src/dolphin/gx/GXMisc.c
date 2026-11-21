/* Dolphin GX miscellaneous controls. See docs/notes/GXMisc.md. */
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
typedef struct OSThreadQueue { OSThread *head, *tail; } OSThreadQueue;
extern void OSInitThreadQueue(OSThreadQueue *), OSSleepThread(OSThreadQueue *), OSWakeupThread(OSThreadQueue *);
typedef s64 OSTime;
extern OSTime OSGetTime(void);
extern volatile u32 __PIRegs[12] : 0xCC003000;
static GXDrawSyncCallback TokenCB;
static GXDrawDoneCallback DrawDoneCB;
static u8 DrawDone;
static OSThreadQueue FinishQueue;

void GXSetMisc(GXMiscToken token, u32 val)
{
    switch (token) {
    case GX_MT_XF_FLUSH:
        gx->vNum = val;
        gx->unk = !gx->vNum;
        gx->bpSent = 1;
        if (gx->vNum != 0) {
            gx->dirtyState |= 8;
        }
        break;
    case GX_MT_DL_SAVE_CONTEXT:
        ASSERTMSGLINE(0xC4, !gx->inDispList, "GXSetMisc: Cannot change DL context setting while making a display list");
        gx->dlSaveContext = (val > 0);
        break;
    case GX_MT_NULL:
        break;
    default:
#if DEBUG
        OSReport("GXSetMisc: bad token %d (val %d)\n", token, val);
#endif
        break;
    }
}

void GXFlush(void)
{
    u32 i;

    CHECK_GXBEGIN(0xF0, "GXFlush");
    if (gx->dirtyState) {
        __GXSetDirtyState();
    }
    for (i = 8; i > 0; i--) {
        GX_WRITE_U32(0);
    }
    PPCSync();
}

void GXResetWriteGatherPipe(void)
{
    while (PPCMfwpar() & 1) {
    }
    PPCMtwpar(OSUncachedToPhysical((void *)GXFIFO_ADDR));
}

static inline void __GXAbortWait(u32 clocks)
{
    OSTime time0;
    OSTime time1;

    time0 = OSGetTime();
    do {
        time1 = OSGetTime();
    } while (time1 - time0 <= (clocks / 4));
}



void GXAbortFrame(void)
{
    __PIRegs[6] = 1;
    __GXAbortWait(0xC8U);
    __PIRegs[6] = 0;
    __GXAbortWait(0x14U);
    __GXCleanGPFifo();
}

inline void GXSetDrawDone(void)
{
    u32 reg;
    BOOL enabled;

    CHECK_GXBEGIN(0x19C, "GXSetDrawDone");
    enabled = OSDisableInterrupts();
    reg = 0x45000002;
    GX_WRITE_RAS_REG(reg);
    GXFlush();
    DrawDone = 0;
    OSRestoreInterrupts(enabled);
}

inline void GXWaitDrawDone(void)
{
    BOOL enabled;

    CHECK_GXBEGIN(0x1CA, "GXWaitDrawDone");

    enabled = OSDisableInterrupts();
    while (!DrawDone) {
        OSSleepThread(&FinishQueue);
    }
    OSRestoreInterrupts(enabled);
}

void GXDrawDone(void)
{
    CHECK_GXBEGIN(0x1EA, "GXDrawDone");
    GXSetDrawDone();
    GXWaitDrawDone();
}

void GXPixModeSync(void)
{
    CHECK_GXBEGIN(0x20D, "GXPixModeSync");
    GX_WRITE_RAS_REG(gx->peCtrl);
    gx->bpSent = 0;
}

void GXTexModeSync(void)
{
    u32 reg;

    CHECK_GXBEGIN(0x225, "GXTexModeSync");
    reg = 0x63000000;
    GX_WRITE_RAS_REG(reg);
    gx->bpSent = 0;
}

#if DEBUG
void __GXBypass(u32 reg)
{
    CHECK_GXBEGIN(0x23B, "__GXBypass");
    GX_WRITE_RAS_REG(reg);
    gx->bpSent = 1;
}

u16 __GXReadPEReg(u32 reg)
{
    return __peReg[reg];
}
#endif

void GXPokeAlphaMode(GXCompare func, u8 threshold)
{
    u32 reg;

    CHECK_GXBEGIN(0x25F, "GXPokeAlphaMode");
    reg = (func << 8) | threshold;
    __peReg[3] = reg;
}

void GXPokeAlphaRead(GXAlphaReadMode mode)
{
    u32 reg;

    CHECK_GXBEGIN(0x26A, "GXPokeAlphaRead");
    reg = 0;
    SET_REG_FIELD(0x26D, reg, 2, 0, mode);
    SET_REG_FIELD(0x26E, reg, 1, 2, 1);
    __peReg[4] = reg;
}

void GXPokeAlphaUpdate(GXBool update_enable)
{
    u32 reg;

    CHECK_GXBEGIN(0x277, "GXPokeAlphaUpdate");
    reg = __peReg[1];
    SET_REG_FIELD(0x27A, reg, 1, 4, update_enable);
    __peReg[1] = reg;
}

void GXPokeBlendMode(GXBlendMode type, GXBlendFactor src_factor, GXBlendFactor dst_factor, GXLogicOp op)
{
    u32 reg;

    CHECK_GXBEGIN(0x284, "GXPokeBlendUpdate");
    reg = __peReg[1];
    SET_REG_FIELD(0x28C, reg, 1, 0, (type == GX_BM_BLEND) || (type == GX_BM_SUBTRACT));
    SET_REG_FIELD(0x28D, reg, 1, 11, (type == GX_BM_SUBTRACT));
    SET_REG_FIELD(0x28F, reg, 1, 1, (type == GX_BM_LOGIC));
    SET_REG_FIELD(0x290, reg, 4, 12, op);
    SET_REG_FIELD(0x291, reg, 3, 8, src_factor);
    SET_REG_FIELD(0x292, reg, 3, 5, dst_factor);
    SET_REG_FIELD(0x293, reg, 8, 24, 0x41);
    __peReg[1] = reg;
}

void GXPokeColorUpdate(GXBool update_enable)
{
    u32 reg;

    CHECK_GXBEGIN(0x29D, "GXPokeColorUpdate");
    reg = __peReg[1];
    SET_REG_FIELD(0x2A0, reg, 1, 3, update_enable);
    __peReg[1] = reg;
}

void GXPokeDstAlpha(GXBool enable, u8 alpha)
{
    u32 reg = 0;

    CHECK_GXBEGIN(0x2A9, "GXPokeDstAlpha");
    SET_REG_FIELD(0x2AB, reg, 8, 0, alpha);
    SET_REG_FIELD(0x2AC, reg, 1, 8, enable);
    __peReg[2] = reg;
}

void GXPokeDither(GXBool dither)
{
    u32 reg;

    CHECK_GXBEGIN(0x2B5, "GXPokeDither");
    reg = __peReg[1];
    SET_REG_FIELD(0x2B8, reg, 1, 2, dither);
    __peReg[1] = reg;
}

void GXPokeZMode(GXBool compare_enable, GXCompare func, GXBool update_enable)
{
    u32 reg = 0;

    CHECK_GXBEGIN(0x2C1, "GXPokeZMode");

    SET_REG_FIELD(0x2C3, reg, 1, 0, compare_enable);
    SET_REG_FIELD(0x2C4, reg, 3, 1, func);
    SET_REG_FIELD(0x2C5, reg, 1, 4, update_enable);
    __peReg[0] = reg;
}











static void GXTokenInterruptHandler(s16 interrupt, OSContext *context)
{
    u16 token;
    OSContext exceptionContext;
    u32 reg;

    token = __peReg[7];
    if (TokenCB != NULL) {
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        TokenCB(token);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
    reg = __peReg[5];
    SET_REG_FIELD(0, reg, 1, 2, 1);
    __peReg[5] = reg;
}



static void GXFinishInterruptHandler(s16 interrupt, OSContext *context)
{
    OSContext exceptionContext;
    u32 reg;

    reg = __peReg[5];
    SET_REG_FIELD(0, reg, 1, 3, 1);
    __peReg[5] = reg;
    DrawDone = 1;
    if (DrawDoneCB != NULL) {
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        DrawDoneCB();
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
    OSWakeupThread(&FinishQueue);
}

void __GXPEInit(void)
{
    u32 reg;
    __OSSetInterruptHandler(0x12, GXTokenInterruptHandler);
    __OSSetInterruptHandler(0x13, GXFinishInterruptHandler);
    OSInitThreadQueue(&FinishQueue);
    __OSUnmaskInterrupts(0x2000);
    __OSUnmaskInterrupts(0x1000);
    reg = __peReg[5];
    SET_REG_FIELD(0, reg, 1, 2, 1);
    SET_REG_FIELD(0, reg, 1, 3, 1);
    SET_REG_FIELD(0, reg, 1, 0, 1);
    SET_REG_FIELD(0, reg, 1, 1, 1);
    __peReg[5] = reg;
}




