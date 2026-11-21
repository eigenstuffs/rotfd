/* Local AR/ARQ ABI and hardware register declarations from public Dolphin references. */
#ifndef ROTFD_AR_ABI_H
#define ROTFD_AR_ABI_H
#include "../os/OSContext_abi.h"
typedef signed short __OSInterrupt;
typedef void (*__OSInterruptHandler)(__OSInterrupt, OSContext *);
extern void OSRegisterVersion(const char *), OSClearContext(OSContext *);
extern __OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt, __OSInterruptHandler);
extern u32 __OSUnmaskInterrupts(u32);
extern void DCFlushRange(void *, u32), DCInvalidateRange(void *, u32), PPCSync(void);
extern void *memset(void *, int, unsigned long);
extern volatile u16 __DSPRegs[32] : 0xCC005000;
#define TRUE 1
#define FALSE 0
#define nullptr NULL
#define __OS_INTERRUPT_DSP_ARAM 6
#define OS_INTERRUPTMASK_DSP_ARAM 0x02000000
#define OSRoundUp32B(x) (((u32)(x) + 31) & ~31)
#define OSPhysicalToUncached(p) ((void *)((u32)(p) + 0xC0000000))
#define DSP_MAILBOX_IN_HI  (0)
#define DSP_MAILBOX_IN_LO  (1)
#define DSP_MAILBOX_OUT_HI (2)
#define DSP_MAILBOX_OUT_LO (3)
#define DSP_CONTROL_STATUS (5)
#define DSP_ARAM_SIZE        (9)
#define DSP_ARAM_MODE        (11)
#define DSP_ARAM_REFRESH     (13)
#define DSP_ARAM_DMA_MM_HI   (16) // Main mem address
#define DSP_ARAM_DMA_MM_LO   (17)
#define DSP_ARAM_DMA_ARAM_HI (18) // ARAM address
#define DSP_ARAM_DMA_ARAM_LO (19)
#define DSP_ARAM_DMA_SIZE_HI (20) // DMA buffer size
#define DSP_ARAM_DMA_SIZE_LO (21)
#define DSP_DMA_START_HI    (24) // DMA start address
#define DSP_DMA_START_LO    (25)
#define DSP_DMA_CONTROL_LEN (27)
#define DSP_DMA_BYTES_LEFT  (29)
#define DSP_DMA_START_FLAG (0x8000) // set to start DSP
typedef struct ARQRequest ARQRequest;

// AR callback function type.
typedef void (*ARCallback)(void);

// ARQ callback function type.
typedef void (*ARQCallback)(u32 ptrToRequest);

struct ARQRequest {
	ARQRequest* next;     // _00
	u32 owner;            // _04
	u32 type;             // _08
	u32 priority;         // _0C
	u32 source;           // _10
	u32 dest;             // _14
	u32 length;           // _18
	ARQCallback callback; // _1C
};

////////////////////////////////////////////

/////////////// AR FUNCTIONS ///////////////
// ARQ functions.
void ARQInit();
void ARQPostRequest(ARQRequest* task, u32 owner, u32 type, u32 priority, u32 source, u32 dest, u32 length, ARQCallback callback);

// AR functions.
ARCallback ARRegisterDMACallback(ARCallback callback);
u32 ARGetDMAStatus();
void ARStartDMA(u32 type, u32 mainmem_addr, u32 aram_addr, u32 length);
u32 ARAlloc(u32 length);
u32 ARInit(u32* stack_index_addr, u32 num_entries);
u32 ARGetBaseAddress();
u32 ARGetSize();

// Unused/inlined in P2.
u32 ARFree(u32* length);
BOOL ARCheckInit();
void ARReset();
void ARSetSize();
u32 ARGetInternalSize();
void ARClear(u32 flag);

////////////////////////////////////////////
u16 __ARGetInterruptStatus();
//////////////// AR DEFINES ////////////////
// AR defines.
#define AR_STACK_INDEX_ENTRY_SIZE sizeof(u32)

#define ARAM_DIR_MRAM_TO_ARAM 0x00
#define ARAM_DIR_ARAM_TO_MRAM 0x01

#define AR_CLEAR_INTERNAL_ALL  0x00
#define AR_CLEAR_INTERNAL_USER 0x01
#define AR_CLEAR_EXPANSION     0x02

#define __AR_ARAM_OS_BASE_ADDR  0x0000 // OS area at bottom of ARAM
#define __AR_ARAM_USR_BASE_ADDR 0x4000 // USR area at 16KB (0x4000)

// AR macros.
#define ARStartDMARead(mmem, aram, len)  ARStartDMA(ARAM_DIR_ARAM_TO_MRAM, mmem, aram, len)
#define ARStartDMAWrite(mmem, aram, len) ARStartDMA(ARAM_DIR_MRAM_TO_ARAM, mmem, aram, len)

// ARQ defines.
#define ARQ_DMA_ALIGNMENT      32
#define ARQ_CHUNK_SIZE_DEFAULT 4096

#define ARQ_TYPE_MRAM_TO_ARAM ARAM_DIR_MRAM_TO_ARAM
#define ARQ_TYPE_ARAM_TO_MRAM ARAM_DIR_ARAM_TO_MRAM

#define ARQ_PRIORITY_LOW  0
#define ARQ_PRIORITY_HIGH 1

////////////////////////////////////////////


#endif
