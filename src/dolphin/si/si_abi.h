/* Private serial-interface ABI; existing DVD/OS types are reused read-only. */
#ifndef ROTFD_SI_ABI_H
#define ROTFD_SI_ABI_H
#include "../dvd/dvd_abi.h"
typedef volatile u32 vu32;
typedef signed short __OSInterrupt;
typedef void (*__OSInterruptHandler)(__OSInterrupt, OSContext*);
extern __OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt, __OSInterruptHandler);
extern u32 __OSUnmaskInterrupts(u32);
extern void OSRegisterVersion(const char*), SISetSamplingRate(u32);
extern void OSSetWirelessID(s32, u16);
extern u16 OSGetWirelessID(s32);
extern u32 VIGetCurrentLine(void);
extern volatile u32 __SIRegs[128] : 0xCC006400;
#define SI_CC_STAT 13
#define SI_STAT 14
#define SI_IO_BUFFER 32
#define SI_POLL 12
#define SI_MAX_COMCSR_OUTLNGTH 128
#define SI_MAX_COMCSR_INLNGTH 128
#define SI_CHAN0_BIT 0x80000000
#define __OS_INTERRUPT_PI_SI 20
#define OS_INTERRUPTMASK_PI_SI (0x80000000u >> 20)
#define PAD_CHAN0_BIT 0x80000000
#define PAD_CHAN1_BIT 0x40000000
#define PAD_CHAN2_BIT 0x20000000
#define PAD_CHAN3_BIT 0x10000000

#define SI_ERROR_UNDER_RUN 0x0001
#define SI_ERROR_OVER_RUN 0x0002
#define SI_ERROR_COLLISION 0x0004
#define SI_ERROR_NO_RESPONSE 0x0008
#define SI_ERROR_WRST 0x0010
#define SI_ERROR_RDST 0x0020
#define SI_ERROR_UNKNOWN 0x0040
#define SI_ERROR_BUSY 0x0080

#define SI_TYPE_MASK 0x18000000u
#define SI_TYPE_N64 0x00000000u
#define SI_TYPE_DOLPHIN 0x08000000u
#define SI_TYPE_GC SI_TYPE_DOLPHIN
#define SI_GC_WIRELESS 0x80000000
#define SI_GC_NOMOTOR 0x20000000
#define SI_GC_STANDARD 0x01000000
#define SI_WIRELESS_RECEIVED 0x40000000
#define SI_WIRELESS_IR 0x04000000
#define SI_WIRELESS_STATE 0x02000000
#define SI_WIRELESS_ORIGIN 0x00200000
#define SI_WIRELESS_FIX_ID 0x00100000
#define SI_WIRELESS_TYPE 0x000f0000
#define SI_WIRELESS_LITE_MASK 0x000c0000
#define SI_WIRELESS_LITE 0x00040000
#define SI_WIRELESS_CONT_MASK 0x00080000
#define SI_WIRELESS_CONT 0x00000000
#define SI_WIRELESS_ID 0x00c0ff00
#define SI_WIRELESS_TYPE_ID (SI_WIRELESS_TYPE | SI_WIRELESS_ID)
#define SI_N64_CONTROLLER (SI_TYPE_N64 | 0x05000000)
#define SI_N64_MIC (SI_TYPE_N64 | 0x00010000)
#define SI_N64_KEYBOARD (SI_TYPE_N64 | 0x00020000)
#define SI_N64_MOUSE (SI_TYPE_N64 | 0x02000000)
#define SI_GBA (SI_TYPE_N64 | 0x00040000)
#define SI_GC_CONTROLLER (SI_TYPE_GC | SI_GC_STANDARD)
#define SI_GC_RECEIVER (SI_TYPE_GC | SI_GC_WIRELESS)
#define SI_GC_WAVEBIRD                                                                             \
  (SI_TYPE_GC | SI_GC_WIRELESS | SI_GC_STANDARD | SI_WIRELESS_STATE | SI_WIRELESS_FIX_ID)
#define SI_GC_KEYBOARD (SI_TYPE_GC | 0x00200000)
#define SI_GC_STEERING (SI_TYPE_GC | 0x00000000)

#define SI_MAX_CHAN 4


typedef void (*SICallback)(s32 chan, u32 sr, OSContext* context);
typedef void (*SITypeAndStatusCallback)(s32 chan, u32 type);


typedef struct SIPacket {
	s32 chan;            
	void* output;        
	u32 outputBytes;     
	void* input;         
	u32 inputBytes;      
	SICallback callback; 
	OSTime fire;         
} SIPacket;


typedef struct SIControl {
	s32 chan;            
	u32 poll;            
	u32 inputBytes;      
	void* input;         
	SICallback callback; 
} SIControl;


typedef struct SICommFlags {
	u32 tcint : 1;
	u32 tcintmsk : 1;
	u32 comerr : 1;
	u32 rdstint : 1;
	u32 rdstintmsk : 1;
	u32 pad0 : 4;
	u32 outlngth : 7;
	u32 pad1 : 1;
	u32 inlngth : 7;
	u32 pad2 : 5;
	u32 channel : 2;
	u32 tstart : 1;
} SICommFlags;


typedef union SIComm {
	u32 val;
	SICommFlags flags;
} SIComm;




BOOL SIBusy();
BOOL SIIsChanBusy(s32 chan);

BOOL SIRegisterPollingHandler(__OSInterruptHandler handler);
BOOL SIUnregisterPollingHandler(__OSInterruptHandler handler);

void SIInit(void);
u32 SIGetStatus(s32 chan);
void SISetCommand(s32 chan, u32 command);
void SITransferCommands(void);
u32 SISetXY(u32 x, u32 y);
u32 SIEnablePolling(u32 poll);
u32 SIDisablePolling(u32 poll);
BOOL SIGetResponse(s32 chan, void* data);
BOOL SITransfer(s32 chan, void* output, u32 outputBytes, void* input, u32 inputBytes, SICallback callback, OSTime delay);
u32 SIGetType(s32 chan);
u32 SIGetTypeAsync(s32 chan, SITypeAndStatusCallback callback);
u32 SIDecodeType(u32 type);
u32 SIProbe(s32 chan);




#endif
