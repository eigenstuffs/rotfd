/* Local DVD state-machine ABI, GSQE78. */
#ifndef ROTFD_DVD_STATE_ABI_H
#define ROTFD_DVD_STATE_ABI_H
#include "dvd_abi.h"
#define OSPhysicalToCached(x) ((void *)((u32)(x) + 0x80000000))
#define DVD_STATE_END 0
#define DVD_MIN_TRANSFER_SIZE 32
typedef struct OSBootInfo { DVDDiskID DVDDiskID; u32 magic; u8 reserved24[0x14]; void *FSTLocation; u32 FSTMaxLength; } OSBootInfo;
typedef struct OSThreadQueue { void *head, *tail; } OSThreadQueue;
typedef struct DVDCommandBlock DVDCommandBlock;
typedef struct DVDFileInfo DVDFileInfo;
typedef void (*DVDCBCallback)(s32, DVDCommandBlock *);
typedef void (*DVDCallback)(s32, DVDFileInfo *);
struct DVDCommandBlock {
    DVDCommandBlock *next, *prev;
    u32 command;
    s32 state;
    u32 offset, length;
    void *addr;
    u32 currTransferSize, transferredSize;
    DVDDiskID *id;
    DVDCBCallback callback;
    void *userData;
};
struct DVDFileInfo {
    DVDCommandBlock cb;
    u32 startAddr, length;
    DVDCallback callback;
};
typedef volatile u32 vu32;
typedef volatile s32 vs32;
typedef short __OSInterrupt;
typedef void (*DVDLowCallback)(u32);
typedef void (*DVDOptionalCommandChecker)(DVDCommandBlock *, DVDLowCallback);
typedef struct DVDBB2 {
    u32 bootFilePosition, FSTPosition, FSTLength, FSTMaxLength;
    void *FSTAddress;
    u32 userPosition, userLength, reserved_1C;
} DVDBB2;
#define ATTRIBUTE_ALIGN(x) __attribute__((aligned(x)))
#define nullptr NULL
#define DI_STATUS 0
#define DI_COVER_STATUS 1
#define DI_MM_BUF 8
#define OS_BOOTINFO_MAGIC_JTAG 0xE5207C22
#define DVD_STATE_FATAL_ERROR (-1)
#define DVD_STATE_PAUSING 8
#define OSRoundUp32B(x) (((u32)(x) + 31) & ~31)
#define OSErrorLine(line,msg) OSPanic("dvd.c", line, msg)
extern OSThreadQueue __DVDThreadQueue;
extern void OSPanic(const char *, int, const char *, ...);
extern void OSRegisterVersion(const char *);
extern void __DVDFSInit(void), __DVDClearWaitingQueue(void), __DVDInitWA(void), __fstLoad(void);
extern void (*__OSSetInterruptHandler(__OSInterrupt, void (*)(__OSInterrupt, OSContext *)))(__OSInterrupt, OSContext *);
extern u32 __OSUnmaskInterrupts(u32);
extern void OSInitThreadQueue(OSThreadQueue *), OSSleepThread(OSThreadQueue *), OSWakeupThread(OSThreadQueue *);
extern int DVDLowRead(void *, u32, u32, DVDLowCallback);
extern int DVDLowStopMotor(DVDLowCallback), DVDLowRequestError(DVDLowCallback);
extern int DVDLowAudioBufferConfig(int, u32, DVDLowCallback);
extern int DVDLowReadDiskID(DVDDiskID *, DVDLowCallback);
extern int DVDLowWaitCoverClose(DVDLowCallback);
extern int DVDLowAudioStream(u32, u32, u32, DVDLowCallback);
extern int DVDLowRequestAudioStatus(u32, DVDLowCallback), DVDLowInquiry(DVDDriveInfo *, DVDLowCallback);
extern void DVDLowReset(void);
extern int DVDLowBreak(void);
extern DVDLowCallback DVDLowClearCallback(void);
extern void DCInvalidateRange(void *, u32);
extern int DVDCompareDiskID(DVDDiskID *, DVDDiskID *);
extern void *memcpy(void *, const void *, u32);
extern int memcmp(const void *, const void *, u32);
extern void __DVDPrintFatalMessage(void), __DVDStoreErrorCode(u32);
extern BOOL __DVDCheckWaitingQueue(void), __DVDPushWaitingQueue(s32, DVDCommandBlock *), __DVDDequeueWaitingQueue(DVDCommandBlock *);
extern void DVDReset(void), DVDResume(void);
extern s32 DVDGetCommandBlockStatus(const DVDCommandBlock *);
#endif
