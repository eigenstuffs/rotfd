/* Local target declarations for the recovered C fragments of OSContext.c.
 * Structure and low-memory bindings follow the Melee SDK reconstruction.
 */
#ifndef ROTFD_OSCONTEXT_ABI_H
#define ROTFD_OSCONTEXT_ABI_H
#define NULL ((void *)0)
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef double f64;
typedef int BOOL;
typedef u8 __OSException;
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


#define OS_CONTEXT_STATE_FPSAVED 0x01u
#define __OS_EXCEPTION_FLOATING_POINT 7
volatile OSContext* __OSCurrentContext : 0x800000D4;
volatile OSContext* __OSFPUContext : 0x800000D8;
extern void OSReport(const char *, ...), DBPrintf(char *, ...);
extern BOOL OSDisableInterrupts(void), OSRestoreInterrupts(BOOL);
extern void OSSetCurrentContext(OSContext *);
typedef void (*__OSExceptionHandler)(__OSException, OSContext *);
extern __OSExceptionHandler __OSSetExceptionHandler(__OSException, __OSExceptionHandler);
extern void OSSwitchFPUContext(__OSException, OSContext *);
#ifdef OS_CONTEXT_INLINE_HELPERS
static inline OSContext* OSGetCurrentContext(void) {
  return (OSContext*)__OSCurrentContext;
}

static inline void OSClearContext(register OSContext* context) {
  context->mode = 0;
  context->state = 0;
  if (context == __OSFPUContext)
    __OSFPUContext = NULL;
}

#endif
#endif
