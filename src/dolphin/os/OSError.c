/* Dolphin SDK error reporting and exception handling, GSQE78.
 * Adapted from public doldecomp/melee and projectPiki/pikmin2 SDK
 * reconstructions; see reference/pikmin2-sdk/PROVENANCE.md.
 */
#include "OSContext_abi.h"
typedef signed long s32;
typedef unsigned long long u64;
typedef signed long long OSTime;
typedef u16 OSError;
typedef void (*OSErrorHandler)(OSError, OSContext *, ...);
typedef s32 OSPriority;

struct OSThread;
struct OSMutex;
struct OSMutexQueue;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue
{
    struct OSThread *head;
    struct OSThread *tail;
} OSThreadQueue;

typedef struct OSThreadLink
{
    struct OSThread *next;
    struct OSThread *prev;
} OSThreadLink;

typedef struct OSMutexQueue
{
    struct OSMutex *head;
    struct OSMutex *tail;
} OSMutexQueue;

typedef struct OSMutexLink
{
    struct OSMutex *next;
    struct OSMutex *prev;
} OSMutexLink;

typedef struct OSThread
{
    /*0x000*/ struct OSContext context;   
    /*0x2C8*/ u16 state;     
    /*0x2CA*/ u16 attr;      
    /*0x2CC*/ s32 suspend;   
    /*0x2D0*/ OSPriority priority;  
    /*0x2D4*/ OSPriority base;
    /*0x2D8*/ void *val;                          
    /*0x2DC*/ struct OSThreadQueue *queue;     
    /*0x2E0*/ struct OSThreadLink link;                    
    /*0x2E8*/ struct OSThreadQueue queueJoin;              
    /*0x2F0*/ struct OSMutex *mutex;     
    /*0x2F4*/ struct OSMutexQueue queueMutex;              
    /*0x2FC*/ struct OSThreadLink linkActive;             
    /*0x304*/ u8 *stackBase; 
    /*0x308*/ u32 *stackEnd;  
} OSThread;


OSThreadQueue __OSActiveThreadQueue : 0x800000DC;
volatile u16 __DSPRegs[] : 0xCC005000;
volatile u32 __DIRegs[] : 0xCC006000;
#define DSP_DMA_START_HI 24
#define DSP_DMA_START_LO 25
#define DSP_ARAM_DMA_MM_HI 16
#define DSP_ARAM_DMA_MM_LO 17
#define DI_DMA_MEM_ADDR 5
#define OS_ERROR_FPE 16
#define OS_ERROR_MAX 17
#define OS_ERROR_DECREMENTER 8
#define OS_ERROR_PROTECTION 15
#define __OS_EXCEPTION_PROGRAM 6
#define __OS_EXCEPTION_ALIGNMENT 5
#define __OS_EXCEPTION_DSI 2
#define __OS_EXCEPTION_ISI 3
#define WEAKFUNC
#define nullptr NULL
extern s32 OSDisableScheduler(void), OSEnableScheduler(void);
extern void __OSReschedule(void), OSLoadContext(OSContext *), OSDumpContext(OSContext *), OSSaveFPUContext(OSContext *);
extern u32 OSGetStackPointer(void), PPCMfmsr(void), PPCMffpscr(void);
extern void PPCMtmsr(u32), PPCMtfpscr(u32), PPCHalt(void);
extern OSTime OSGetTime(void);
extern volatile signed short __OSLastInterrupt;
extern volatile u32 __OSLastInterruptSrr0;
extern volatile OSTime __OSLastInterruptTime;
typedef struct { char gpr; char fpr; char reserved[2]; char *input_arg_area; char *reg_save_area; } va_list[1];
extern void __builtin_va_info(void *);
#define va_start(ap,fmt) ((void)fmt,__builtin_va_info(&ap))
#define va_end(ap) ((void)0)
extern int vprintf(const char *, va_list);
#define FPSCR_FX            0x80000000  // Exception summary
#define FPSCR_FEX           0x40000000  // Enabled exception summary
#define FPSCR_VX            0x20000000  // Invalid operation
#define FPSCR_OX            0x10000000  // Overflow exception
#define FPSCR_UX            0x08000000  // Underflow exception
#define FPSCR_ZX            0x04000000  // Zero divide exception
#define FPSCR_XX            0x02000000  // Inexact exception
#define FPSCR_VXSNAN        0x01000000  // SNaN
#define FPSCR_VXISI         0x00800000  // Infinity - Infinity
#define FPSCR_VXIDI         0x00400000  // Infinity / Infinity
#define FPSCR_VXZDZ         0x00200000  // 0 / 0
#define FPSCR_VXIMZ         0x00100000  // Infinity * 0
#define FPSCR_VXVC          0x00080000  // Invalid compare
#define FPSCR_FR            0x00040000  // Fraction rounded
#define FPSCR_FI            0x00020000  // Fraction inexact
#define FPSCR_VXSOFT        0x00000400  // Software request
#define FPSCR_VXSQRT        0x00000200  // Invalid square root
#define FPSCR_VXCVI         0x00000100  // Invalid integer convert
#define FPSCR_VE            0x00000080  // Invalid operation exception enable
#define FPSCR_OE            0x00000040  // Overflow exception enable
#define FPSCR_UE            0x00000020  // Underflow exception enable
#define FPSCR_ZE            0x00000010  // Zero divide exception enable
#define FPSCR_XE            0x00000008  // Inexact exception enable
#define FPSCR_NI            0x00000004  // Non-IEEE mode
#define FPSCR_FX_BIT        0           // Exception summary
#define FPSCR_FEX_BIT       1           // Enabled exception summary
#define FPSCR_VX_BIT        2           // Invalid operation
#define FPSCR_OX_BIT        3           // Overflow exception
#define FPSCR_UX_BIT        4           // Underflow exception
#define FPSCR_ZX_BIT        5           // Zero divide exception
#define FPSCR_XX_BIT        6           // Inexact exception
#define FPSCR_VXSNAN_BIT    7           // SNaN
#define FPSCR_VXISI_BIT     8           // Infinity - Infinity
#define FPSCR_VXIDI_BIT     9           // Infinity / Infinity
#define FPSCR_VXZDZ_BIT     10          // 0 / 0
#define FPSCR_VXIMZ_BIT     11          // Infinity * 0
#define FPSCR_VXVC_BIT      12          // Invalid compare
#define FPSCR_FR_BIT        13          // Fraction rounded
#define FPSCR_FI_BIT        14          // Fraction inexact
#define FPSCR_VXSOFT_BIT    21          // Software request
#define FPSCR_VXSQRT_BIT    22          // Invalid square root
#define FPSCR_VXCVI_BIT     23          // Invalid integer convert
#define FPSCR_VE_BIT        24          // Invalid operation exception enable
#define FPSCR_OE_BIT        25          // Overflow exception enable
#define FPSCR_UE_BIT        26          // Underflow exception enable
#define FPSCR_ZE_BIT        27          // Zero divide exception enable
#define FPSCR_XE_BIT        28          // Inexact exception enable
#define FPSCR_NI_BIT        29          // Non-IEEE mode

// All enable
#define FPSCR_ENABLE 0xF8

OSErrorHandler __OSErrorTable[OS_ERROR_MAX];
u32 __OSFpscrEnableBits = FPSCR_ENABLE;


WEAKFUNC void OSReport(const char* msg, ...)
{
	va_list marker;

	va_start(marker, msg);
	vprintf(msg, marker);
	va_end(marker);
}


static inline void OSVReport(const char* msg, va_list list)
{
	vprintf(msg, list);
}


WEAKFUNC void OSPanic(const char* file, int line, const char* msg, ...)
{
	va_list marker;
	u32 i;
	u32* p;

	OSDisableInterrupts();
	va_start(marker, msg);
	vprintf(msg, marker);
	va_end(marker);
	OSReport(" in \"%s\" on line %d.\n", file, line);

	// actually useful for debugging- stack crawl
	OSReport("\nAddress:      Back Chain    LR Save\n");
	for (i = 0, p = (u32*)OSGetStackPointer();                // get current stack pointer
	     p && (u32)p != 0xffffffff && i++ < 16; p = (u32*)*p) // get caller stack pointer
	{
		OSReport("0x%08x:   0x%08x    0x%08x\n", p, p[0], p[1]);
	}

	PPCHalt();
}


OSErrorHandler OSSetErrorHandler(OSError error, OSErrorHandler handler)
{
	OSErrorHandler oldHandler;
	BOOL enabled;

	enabled               = OSDisableInterrupts();
	oldHandler            = __OSErrorTable[error];
	__OSErrorTable[error] = handler;

	if (error == OS_ERROR_FPE) {
		u32 msr;
		u32 fpscr;
		OSThread* thread;

		msr = PPCMfmsr();
		PPCMtmsr(msr | 0x2000); // Enable FPU
		fpscr = PPCMffpscr();
		if (handler) {
			for (thread = __OSActiveThreadQueue.head; thread; thread = thread->linkActive.next) {
				thread->context.srr1 |= 0x900;
				if ((thread->context.state & OS_CONTEXT_STATE_FPSAVED) == 0) {
					int i;

					// Initialize FPU context too so that FPSCR can be changed per thread
					thread->context.state |= OS_CONTEXT_STATE_FPSAVED;
					for (i = 0; i < 32; ++i) {
						*(u64*)&thread->context.fpr[i] = (u64)0xffffffffffffffffLL;
						*(u64*)&thread->context.psf[i] = (u64)0xffffffffffffffffLL;
					}
					thread->context.fpscr = 4;
				}
				thread->context.fpscr |= __OSFpscrEnableBits & FPSCR_ENABLE;
				thread->context.fpscr &= 0x6005F8FF; // Clear accumulated floating-point exception status.
			}
			fpscr |= __OSFpscrEnableBits & FPSCR_ENABLE;
			msr |= 0x900;
		} else {
			for (thread = __OSActiveThreadQueue.head; thread; thread = thread->linkActive.next) {
				thread->context.srr1 &= ~(0x900);
				thread->context.fpscr &= ~FPSCR_ENABLE;
				thread->context.fpscr &= 0x6005F8FF;
			}
			fpscr &= ~FPSCR_ENABLE;
			msr &= ~0x900;
		}

		fpscr &= 0x6005F8FF; // Preserve control bits, clear accumulated exception status.

		PPCMtfpscr(fpscr);
		PPCMtmsr(msr); // Restore FPU
	}

	OSRestoreInterrupts(enabled);
	return oldHandler;
}


void __OSUnhandledException(__OSException exception, OSContext* context, u32 dsisr, u32 dar)
{
	OSTime now;

	now = OSGetTime();

	if (!(context->srr1 & 2)) {
		OSReport("Non-recoverable Exception %d", exception);

	} else {
		if (exception == __OS_EXCEPTION_PROGRAM && (context->srr1 & (0x80000000 >> 11)) && __OSErrorTable[OS_ERROR_FPE] != 0) {
			u32 fpscr;
			u32 msr;

			exception = OS_ERROR_FPE;

			msr = PPCMfmsr();
			PPCMtmsr(msr | 0x2000);

			if (__OSFPUContext) {
				OSSaveFPUContext((OSContext*)__OSFPUContext);
			}

			fpscr = PPCMffpscr();
			fpscr &= ~(FPSCR_VXVC | FPSCR_VXIMZ | FPSCR_VXZDZ | FPSCR_VXIDI | FPSCR_VXISI | FPSCR_VXSNAN | FPSCR_VXSOFT | FPSCR_VXSQRT
			           | FPSCR_VXCVI | FPSCR_XX | FPSCR_ZX | FPSCR_UX | FPSCR_OX | FPSCR_FX | FPSCR_FI);
			PPCMtfpscr(fpscr);

			PPCMtmsr(msr);

			if (__OSFPUContext == context) {
				OSDisableScheduler();
				__OSErrorTable[exception](exception, context, dsisr, dar);
				context->srr1 &= ~0x2000;
				__OSFPUContext = nullptr;

				context->fpscr &= ~(FPSCR_VXVC | FPSCR_VXIMZ | FPSCR_VXZDZ | FPSCR_VXIDI | FPSCR_VXISI | FPSCR_VXSNAN | FPSCR_VXSOFT
				                    | FPSCR_VXSQRT | FPSCR_VXCVI | FPSCR_XX | FPSCR_ZX | FPSCR_UX | FPSCR_OX | FPSCR_FX | FPSCR_FI);
				OSEnableScheduler();
				__OSReschedule();
			} else {
				context->srr1 &= ~0x2000;
				__OSFPUContext = nullptr;
			}

			OSLoadContext(context);
		}

		if (__OSErrorTable[exception]) {
			OSDisableScheduler();
			__OSErrorTable[exception](exception, context, dsisr, dar);
			OSEnableScheduler();
			__OSReschedule();
			OSLoadContext(context);
		}

		if (exception == OS_ERROR_DECREMENTER) {
			OSLoadContext(context);
		}

		OSReport("Unhandled Exception %d", exception);
	}

	OSReport("\n");
	OSDumpContext(context);
	OSReport("\nDSISR = 0x%08x                   DAR  = 0x%08x\n", dsisr, dar);
	OSReport("TB = 0x%016llx\n", now);

	switch (exception) {
	case __OS_EXCEPTION_DSI:
		OSReport("\nInstruction at 0x%x (read from SRR0) attempted to access "
		         "invalid address 0x%x (read from DAR)\n",
		         context->srr0, dar);
		break;
	case __OS_EXCEPTION_ISI:
		OSReport("\nAttempted to fetch instruction from invalid address 0x%x "
		         "(read from SRR0)\n",
		         context->srr0);
		break;
	case __OS_EXCEPTION_ALIGNMENT:
		OSReport("\nInstruction at 0x%x (read from SRR0) attempted to access "
		         "unaligned address 0x%x (read from DAR)\n",
		         context->srr0, dar);
		break;
	case __OS_EXCEPTION_PROGRAM:
		OSReport("\nProgram exception : Possible illegal instruction/operation "
		         "at or around 0x%x (read from SRR0)\n",
		         context->srr0, dar);
		break;
	case OS_ERROR_PROTECTION:
		OSReport("\n");
		OSReport("AI DMA Address =   0x%04x%04x\n", __DSPRegs[DSP_DMA_START_HI], __DSPRegs[DSP_DMA_START_LO]);
		OSReport("ARAM DMA Address = 0x%04x%04x\n", __DSPRegs[DSP_ARAM_DMA_MM_HI], __DSPRegs[DSP_ARAM_DMA_MM_LO]);
		OSReport("DI DMA Address =   0x%08x\n", __DIRegs[DI_DMA_MEM_ADDR]);
		break;
	}

	OSReport("\nLast interrupt (%d): SRR0 = 0x%08x  TB = 0x%016llx\n", __OSLastInterrupt, __OSLastInterruptSrr0, __OSLastInterruptTime);

	PPCHalt();
}
