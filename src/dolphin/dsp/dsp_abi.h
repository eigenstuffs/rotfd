/* DSP task/mailbox ABI from public Dolphin SDK reconstructions. */
#ifndef ROTFD_DSP_ABI_H
#define ROTFD_DSP_ABI_H
#include "../os/OSContext_abi.h"
typedef signed short s16;
typedef signed long s32;
typedef struct DSPTaskInfo DSPTaskInfo;
typedef volatile u32 vu32;
typedef long long OSTime;
// Digital signal processor callback.
typedef void (*DSPCallback)(void* task);

// Struct for digital signal processing information (size 0x50).
struct DSPTaskInfo {
	vu32 state;            // _00, state of task.
	vu32 priority;         // _04
	vu32 flags;            // _08
	u16* iram_mmem_addr;   // _0C, IRAM image info.
	u32 iram_length;       // _10
	u32 iram_addr;         // _14
	u16* dram_mmem_addr;   // _18, DRAM image info.
	u32 dram_length;       // _1C
	u32 dram_addr;         // _20
	u16 dsp_init_vector;   // _24, start vector on first exec.
	u16 dsp_resume_vector; // _26, start vector on resume.
	DSPCallback init_cb;   // _28, callbacks for states.
	DSPCallback res_cb;    // _2C
	DSPCallback done_cb;   // _30
	DSPCallback req_cb;    // _34
	DSPTaskInfo* next;     // _38, linked list.
	DSPTaskInfo* prev;     // _3C
	OSTime t_context;      // _40
	OSTime t_task;         // _48
};



extern void OSRegisterVersion(const char *);
extern u32 DSPCheckMailToDSP(void);
extern void DSPSendMailToDSP(u32);
#define ASSERTMSGLINE(line, condition, message) ((void)0)
#define ASSERTMSGLINEV(line, condition, format, ...) ((void)0)
volatile u16 __DSPRegs[16] : 0xCC005000;
#define OS_INTERRUPTMASK_DSP_DSP 0x01000000
typedef s16 __OSInterrupt;
typedef void (*__OSInterruptHandler)(__OSInterrupt, OSContext *);
extern __OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt, __OSInterruptHandler);
extern u32 __OSUnmaskInterrupts(u32);
extern void OSClearContext(OSContext *);
extern void __DSPHandler(__OSInterrupt intr, OSContext* context);
extern void __DSP_exec_task(DSPTaskInfo *, DSPTaskInfo *), __DSP_boot_task(DSPTaskInfo *);
extern void __DSP_insert_task(DSPTaskInfo *), __DSP_remove_task(DSPTaskInfo *);
extern u32 DSPCheckMailFromDSP(void), DSPReadMailFromDSP(void);
extern void __DSP_debug_printf(const char *, ...);
#endif
