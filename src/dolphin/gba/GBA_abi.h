#ifndef ROTFD_GBA_ABI_H
#define ROTFD_GBA_ABI_H
#include "../os/OSContext_abi.h"
typedef signed long s32;
typedef volatile unsigned char vu8;
typedef volatile unsigned long vu32;
typedef signed long long OSTime;
typedef unsigned long OSTick;
typedef struct OSThread OSThread;
typedef struct OSThreadQueue { OSThread *head, *tail; } OSThreadQueue;
#define TRUE 1
#define FALSE 0
#define ASSERT(...) ((void)0)
#define ATTRIBUTE_ALIGN(n) __attribute__((aligned(n)))
u32 __OSBusClock : 0x800000F8;
#define OS_TIMER_CLOCK (__OSBusClock / 4)
#define OSMicrosecondsToTicks(usec) ((usec) * (OS_TIMER_CLOCK / 125000) / 8)
#define OSMillisecondsToTicks(msec) ((msec) * (OS_TIMER_CLOCK / 1000))
#define OSSecondsToTicks(sec) ((sec) * OS_TIMER_CLOCK)
#define OSTicksToMilliseconds(ticks) ((ticks) / (OS_TIMER_CLOCK / 1000))
#define OSCachedToPhysical(x) ((u32)(x) - 0x80000000)
extern void *memcpy(void *, const void *, unsigned long);
extern OSTime OSGetTime(void);
extern OSTick OSGetTick(void);
extern void OSWakeupThread(OSThreadQueue *), OSSleepThread(OSThreadQueue *);
extern void OSClearContext(OSContext *);
extern OSContext *OSGetCurrentContext(void);
extern void __OSReschedule(void);
extern void DCInvalidateRange(void *, u32), DCFlushRange(void *, u32);
extern void OSPanic(const char *, int, const char *, ...);
typedef void (*DSPCallback)(void* task);

typedef struct STRUCT_DSP_TASK {
  vu32 state;
  vu32 priority;
  vu32 flags;
  u16* iram_mmem_addr;
  u32 iram_length;
  u32 iram_addr;

  u16* dram_mmem_addr;
  u32 dram_length;
  u32 dram_addr;

  u16 dsp_init_vector;
  u16 dsp_resume_vector;

  DSPCallback init_cb;
  DSPCallback res_cb;
  DSPCallback done_cb;
  DSPCallback req_cb;

  struct STRUCT_DSP_TASK* next;
  struct STRUCT_DSP_TASK* prev;

  OSTime t_context;
  OSTime t_task;

} DSPTaskInfo;

void DSPInit();
void DSPReset();
void DSPHalt();
void DSPSendMailToDSP(u32 mail);
u32 DSPCheckMailToDSP();
u32 DSPCheckMailFromDSP();
u32 DSPGetDMAStatus();

DSPTaskInfo* DSPAddTask(DSPTaskInfo* task);

void __DSP_exec_task(DSPTaskInfo* curr, DSPTaskInfo* next);
void __DSP_boot_task(DSPTaskInfo* task);
void __DSP_remove_task(DSPTaskInfo* task);
void __DSP_add_task(DSPTaskInfo* task);
void __DSP_debug_printf(const char* fmt, ...);

#define GBA_CHAN0 0
#define GBA_CHAN1 1
#define GBA_CHAN2 2
#define GBA_CHAN3 3
#define GBA_MAX_CHAN 4

#define GBA_ALL_KEY_MASK 0x03ff
#define GBA_A_BUTTON 0x0001
#define GBA_B_BUTTON 0x0002
#define GBA_SELECT_BUTTON 0x0004
#define GBA_START_BUTTON 0x0008
#define GBA_R_KEY 0x0010
#define GBA_L_KEY 0x0020
#define GBA_U_KEY 0x0040
#define GBA_D_KEY 0x0080
#define GBA_R_BUTTON 0x0100
#define GBA_L_BUTTON 0x0200

#define GBA_JSTAT_MASK 0x3a
#define GBA_JSTAT_FLAGS_SHIFT 4
#define GBA_JSTAT_FLAGS_MASK 0x30
#define GBA_JSTAT_PSF1 0x20
#define GBA_JSTAT_PSF0 0x10
#define GBA_JSTAT_SEND 0x08
#define GBA_JSTAT_RECV 0x02

#define GBA_READY 0
#define GBA_NOT_READY 1
#define GBA_BUSY 2
#define GBA_JOYBOOT_UNKNOWN_STATE 3
#define GBA_JOYBOOT_ERR_INVALID 4

#define GBA_JOYBOOT_PROGRAM_SIZE_MAX 0x40000

#define GBA_JOYBOOT_BOOTPARAM_OFFSET 0xc8
#define GBA_JOYBOOT_BOOTPARAM_SIZE 0x18
typedef void (*GBACallback)(s32 chan, s32 ret);
void GBAInit(void);
s32 GBAGetStatus(s32 chan, u8* status);
s32 GBAGetStatusAsync(s32 chan, u8* status, GBACallback callback);
s32 GBAReset(s32 chan, u8* status);
s32 GBAResetAsync(s32 chan, u8* status, GBACallback callback);
s32 GBAGetProcessStatus(s32 chan, u8* percentp);
s32 GBARead(s32 chan, u8* dst, u8* status);
s32 GBAReadAsync(s32 chan, u8* dst, u8* status, GBACallback callback);
s32 GBAWrite(s32 chan, u8* src, u8* status);
s32 GBAWriteAsync(s32 chan, u8* src, u8* status, GBACallback callback);
s32 GBAJoyBoot(s32 chan, s32 palette_color, s32 palette_speed, u8* programp, s32 length,
               u8* status);
s32 GBAJoyBootAsync(s32 chan, s32 palette_color, s32 palette_speed, u8* programp, s32 length,
                    u8* status, GBACallback callback);
typedef void (*GBATransferCallback)(s32 chan);

typedef struct GBASecParam {
  u8 readbuf[4];
  s32 paletteColor;
  s32 paletteSpeed;
  s32 length;
  u32* out;
  u8 _padding0[12];
  u32 keyA;
  s32 keyB;
  u8 _padding1[24];
} GBASecParam;

typedef struct GBABootInfo {
  s32 paletteColor;
  s32 paletteSpeed;
  u8* programp;
  s32 length;
  u8* status;
  GBACallback callback;
  u8 readbuf[4];
  u8 writebuf[4];
  int i;
  OSTick start;
  OSTime begin;
  int firstXfer;
  int curOffset;
  u32 crc;
  u32 dummyWord[7];
  u32 keyA;
  s32 keyB;
  u32 initialCode;
  int realLength;
} GBABootInfo;

typedef struct GBAControl {
  u8 output[5];
  u8 input[5];
  s32 outputBytes;
  s32 inputBytes;
  u8* status;
  u8* ptr;
  GBACallback callback;
  s32 ret;
  OSThreadQueue threadQueue;
  OSTime delay;
  GBATransferCallback proc;
  GBABootInfo bootInfo;
  DSPTaskInfo task;
  GBASecParam* param;
} GBAControl;

extern GBAControl __GBA[4];
extern BOOL __GBAReset;

void __GBASyncCallback(s32 chan, s32 ret);
s32 __GBASync(s32 chan);
OSTime __GBASetDelay(s32 chan, OSTime delay);
s32 __GBATransfer(s32 chan, s32 w1, s32 w2, GBATransferCallback callback);
void __GBAX01(s32 chan, s32 ret);
void __GBAX02(s32 chan, u8* readBuf);

extern BOOL SITransfer(s32, void *, u32, void *, u32, void (*)(s32,u32,OSContext *), OSTime);
extern u32 SIGetTypeAsync(s32, void (*)(s32,u32));
#endif
