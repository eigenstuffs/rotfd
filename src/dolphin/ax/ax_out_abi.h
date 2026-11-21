/* Local output/DSP ABI extension for AX. */
#ifndef ROTFD_AX_OUT_ABI_H
#define ROTFD_AX_OUT_ABI_H
#include "ax_abi.h"
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


extern OSTime OSGetTime(void);
extern void DSPSendMailToDSP(u32), DSPInit(void), DSPHalt(void), DSPReset(void);
extern u32 DSPCheckMailToDSP(void), DSPGetDMAStatus(void);
extern BOOL DSPCheckInit(void);
extern DSPTaskInfo *DSPAddTask(DSPTaskInfo *), *DSPAssertTask(DSPTaskInfo *);
extern void AIInitDMA(u32, u32), AIStartDMA(void), AIStopDMA(void);
typedef void (*AIDCallback)(void);
extern AIDCallback AIRegisterDMACallback(AIDCallback);
#endif
