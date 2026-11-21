/* MetroTRK ABI recovered from original accesses and Melee reference. */
#ifndef ROTFD_TRK_ABI_H
#define ROTFD_TRK_ABI_H
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef int bool;
#define false 0
#define true 1
typedef unsigned long NubEventID;
typedef int MessageBufferID;
typedef enum NubEventType { kNullEvent, kShutdownEvent, kRequestEvent, kBreakpointEvent, kExceptionEvent, kSupportEvent } NubEventType;
typedef struct NubEvent { u8 fType; NubEventID fID; MessageBufferID fMessageBufferID; } NubEvent;
typedef unsigned long long u64;
typedef unsigned long size_t;
#ifndef NULL
#define NULL 0
#endif
#define NUM_BUFFERS 3
#define kMessageBufferSize 0x880
typedef struct MessageBuffer { u32 fMutex; bool fInUse; u32 fLength; u32 fPosition; u8 fData[kMessageBufferSize]; } MessageBuffer;
typedef struct TRKMsgBufs { MessageBuffer buffers[NUM_BUFFERS]; } TRKMsgBufs;
extern bool TRKGetNextEvent(NubEvent*);
extern void TRKDestructEvent(NubEvent*);
extern MessageBuffer* TRKGetBuffer(MessageBufferID);
extern int TRKDispatchMessage(MessageBuffer*);
extern bool TRKTargetStopped(void);
extern int TRKTargetContinue(void);
extern void TRKGetInput(void);
extern u8* gTRKInputPendingPtr;
typedef int DSError;
extern DSError TRKTargetSupportRequest(void), TRKTargetInterrupt(NubEvent*);
enum { kNoError = 0, kEventQueueFull = 0x100, kNoMessageBufferAvailable = 0x300, kMessageBufferOverflow = 0x301, kMessageBufferReadError = 0x302 };
extern DSError TRKInitializeMutex(void*), TRKAcquireMutex(void*), TRKReleaseMutex(void*);
extern void *TRK_memcpy(void*, const void*, unsigned long);
extern void TRKReleaseBuffer(MessageBufferID);
extern DSError TRKInitializeEventQueue(void), TRKInitializeMessageBuffers(void), TRKInitializeDispatcher(void);
extern DSError TRKInitializeSerialHandler(void), TRKTerminateSerialHandler(void), TRKInitializeTarget(void);
extern void usr_put_initialize(void), TRK_board_display(const char*), TRKTargetSetInputPendingPtr(u8*);
extern DSError TRKInitializeIntDrivenUART(u32, u32, u32, u8**);
extern bool gTRKBigEndian;
extern void *TRK_memset(void*, int, unsigned long);
extern bool usr_puts_serial(const char*);
extern void TRKResetBuffer(MessageBuffer*, u8);
extern DSError TRKAppendBuffer(MessageBuffer*, const void*, size_t);
extern DSError TRKReadBuffer(MessageBuffer*, void*, size_t);
extern DSError TRKAppendBuffer1_ui32(MessageBuffer*, const u32);
extern DSError TRKReadBuffer1_ui8(MessageBuffer*, u8*), TRKReadBuffer1_ui32(MessageBuffer*, u32*);
#endif
