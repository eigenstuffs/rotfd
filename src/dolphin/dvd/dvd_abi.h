/* Local declarations for the recovered DVD low-level C unit. */
#ifndef ROTFD_DVD_ABI_H
#define ROTFD_DVD_ABI_H
#include "../os/OSContext_abi.h"
typedef signed long s32;
typedef signed long long OSTime;
#define TRUE 1
#define FALSE 0
extern volatile u32 __DIRegs[16] : 0xCC006000;
extern volatile u32 __PIRegs[16] : 0xCC003000;
extern u32 __OSBusClock : 0x800000F8;
#define OSSecondsToTicks(x) ((x) * (__OSBusClock / 4))
#define OSMillisecondsToTicks(x) ((x) * ((__OSBusClock / 4) / 1000))
#define OSMicrosecondsToTicks(x) ((x) * ((__OSBusClock / 4) / 125000) / 8)
typedef struct OSAlarm OSAlarm;
typedef void (*OSAlarmHandler)(OSAlarm *, OSContext *);
struct OSAlarm {
    OSAlarmHandler handler;
    u32 tag;
    OSTime fire;
    OSAlarm *prev, *next;
    OSTime period, start;
};
typedef struct DVDDiskID {
    char gameName[4];
    char company[2];
    u8 diskNumber, gameVersion, streaming, streamingBufSize;
    u8 padding[22];
} DVDDiskID;
typedef struct DVDDriveInfo {
    u16 revisionLevel, deviceCode;
    u32 releaseDate;
    u8 padding[24];
} DVDDriveInfo;
extern void OSCancelAlarm(OSAlarm *);
extern void OSInitAlarm(void), OSCreateAlarm(OSAlarm *);
extern void OSSetAlarm(OSAlarm *, OSTime, OSAlarmHandler);
extern OSTime __OSGetSystemTime(void);
extern u32 __OSMaskInterrupts(u32);
extern int DVDLowSeek(u32, void (*)(u32));
extern DVDDiskID *DVDGetCurrentDiskID(void);
#endif
