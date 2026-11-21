/* Local PAD and SI declarations from public Dolphin SDK reconstructions. */
#ifndef ROTFD_PAD_ABI_H
#define ROTFD_PAD_ABI_H
#include "../os/OSContext_abi.h"
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef long long OSTime;
#define TRUE 1
#define FALSE 0
#define nullptr NULL
#define ASSERT(cond) ((void)0)
#define ASSERTMSG(cond, msg) ((void)0)
typedef s16 __OSInterrupt;
typedef void (*__OSInterruptHandler)(__OSInterrupt, OSContext *);
typedef void (*SICallback)(s32, u32, OSContext *);
typedef void (*SITypeAndStatusCallback)(s32, u32);
typedef struct OSResetFunctionInfo { BOOL (*func)(BOOL); u32 priority; struct OSResetFunctionInfo *next, *prev; } OSResetFunctionInfo;
extern void OSRegisterVersion(const char *), OSRegisterResetFunction(OSResetFunctionInfo *), OSClearContext(OSContext *);
extern void *memset(void *, int, unsigned long);
extern OSTime OSGetTime(void);
extern void SISetCommand(s32, u32), SITransferCommands(void), SIRefreshSamplingRate(void);
extern u32 SIEnablePolling(u32), SIDisablePolling(u32), SIGetType(s32), SIGetStatus(s32), SIGetTypeAsync(s32, SITypeAndStatusCallback);
extern BOOL SIGetResponse(s32, void *), SIBusy(void), SIIsChanBusy(s32);
extern BOOL SIRegisterPollingHandler(__OSInterruptHandler), SIUnregisterPollingHandler(__OSInterruptHandler);
extern BOOL SITransfer(s32, void *, u32, void *, u32, SICallback, OSTime);
extern void OSSetWirelessID(s32, u16);
extern u16 __OSWirelessPadFixMode : 0x800030E0;
extern u8 GameChoice : 0x800030E3;
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


typedef struct PADStatus {
	u16 button;      // _00, Or-ed PAD_BUTTON_* bits
	s8 stickX;       // _02, -128 <= stickX       <= 127
	s8 stickY;       // _03, -128 <= stickY       <= 127
	s8 substickX;    // _04, -128 <= substickX    <= 127
	s8 substickY;    // _05, -128 <= substickY    <= 127
	u8 triggerLeft;  // _06,   0 <= triggerLeft  <= 255
	u8 triggerRight; // _07,   0 <= triggerRight <= 255
	u8 analogA;      // _08,   0 <= analogA      <= 255
	u8 analogB;      // _09,   0 <= analogB      <= 255
	s8 err;          // _0A, one of PAD_ERR_* number
} PADStatus;

#define PAD_MAX_CONTROLLERS 4

#define PAD_BUTTON_LEFT  0x0001
#define PAD_BUTTON_RIGHT 0x0002
#define PAD_BUTTON_DOWN  0x0004
#define PAD_BUTTON_UP    0x0008
#define PAD_TRIGGER_Z    0x0010
#define PAD_TRIGGER_R    0x0020
#define PAD_TRIGGER_L    0x0040
#define PAD_BUTTON_A     0x0100
#define PAD_BUTTON_B     0x0200
#define PAD_BUTTON_X     0x0400
#define PAD_BUTTON_Y     0x0800
#define PAD_BUTTON_MENU  0x1000
#define PAD_BUTTON_START 0x1000

#define PAD_ALL                                                                                                                          \
	(PAD_BUTTON_LEFT | PAD_BUTTON_RIGHT | PAD_BUTTON_DOWN | PAD_BUTTON_UP | PAD_TRIGGER_Z | PAD_TRIGGER_R | PAD_TRIGGER_L | PAD_BUTTON_A \
	 | PAD_BUTTON_B | PAD_BUTTON_X | PAD_BUTTON_Y | PAD_BUTTON_MENU | 0x2000 | 0x0080)

#define PAD_SPEC_0 0
#define PAD_SPEC_1 1
#define PAD_SPEC_2 2
#define PAD_SPEC_3 3
#define PAD_SPEC_4 4
#define PAD_SPEC_5 5

#define PAD_CHAN0   0
#define PAD_CHAN1   1
#define PAD_CHAN2   2
#define PAD_CHAN3   3
#define PAD_CHANMAX 4

#define PAD_CHAN0_BIT 0x80000000
#define PAD_CHAN1_BIT 0x40000000
#define PAD_CHAN2_BIT 0x20000000
#define PAD_CHAN3_BIT 0x10000000

#define PAD_ERR_NONE          0
#define PAD_ERR_NO_CONTROLLER -1
#define PAD_ERR_NOT_READY     -2
#define PAD_ERR_TRANSFER      -3

#define PAD_MOTOR_STOP      0
#define PAD_MOTOR_RUMBLE    1
#define PAD_MOTOR_STOP_HARD 2

// PADSetAnalogMode() param
#define PAD_MODE_0 0
#define PAD_MODE_1 1
#define PAD_MODE_2 2
#define PAD_MODE_3 3
#define PAD_MODE_4 4
#define PAD_MODE_5 5
#define PAD_MODE_6 6
#define PAD_MODE_7 7

#define PADButtonDown(buttonLast, button) ((u16)(((buttonLast) ^ (button)) & (button)))

#define PADButtonUp(buttonLast, button) ((u16)(((buttonLast) ^ (button)) & (buttonLast)))

#define PADStartMotor(chan)    PADControlMotor((chan), PAD_MOTOR_RUMBLE)
#define PADStopMotorHard(chan) PADControlMotor((chan), PAD_MOTOR_STOP_HARD)
#define PADStopMotor(chan)     PADControlMotor((chan), PAD_MOTOR_STOP)

BOOL PADInit(void);
BOOL PADReset(u32 mask);
u32 PADRead(PADStatus* status);
void PADSetSamplingRate(u32 msec);
void PADClamp(PADStatus* status);
void PADClampCircle(PADStatus* status);
void PADControlAllMotors(u32* command);
void PADControlMotor(s32 chan, u32 command);
BOOL PADRecalibrate(u32 mask);

void PADSetAnalogMode(u32 mode);
void PADSetSpec(u32 spec);

typedef void (*PADSamplingCallback)(void);

PADSamplingCallback PADSetSamplingCallback(PADSamplingCallback callback);

extern u32 __PADFixBits;


#endif
