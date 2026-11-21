/* Private boot ABI for the recovered C fragments of Dolphin OS.c. */
#ifndef ROTFD_OS_ABI_H
#define ROTFD_OS_ABI_H
#include "../dvd/dvdfs_abi.h"
typedef volatile u16 vu16;
#define ATTRIBUTE_ALIGN(x) __attribute__((aligned(x)))
#define OS_BASE_CACHED 0x80000000
#define OS_CONSOLE_RETAIL 0x00000000
#define OS_CONSOLE_EMULATOR 0x10000000
#define OS_CONSOLE_PC_EMULATOR 0x10000001
#define OS_CONSOLE_ARTHUR 0x10000002
#define OS_CONSOLE_MINNOW 0x10000003
#define __OS_INTERRUPT_PI_RSW 22
#define __OS_EXCEPTION_MAX 15

typedef struct OSBootInfo {
    DVDDiskID disk;
    u32 magic, version, memorySize, consoleType;
    void *arenaLo, *arenaHi;
    void *FSTLocation;
    u32 FSTMaxLength;
} OSBootInfo;
typedef struct BI2Debug {
    u32 debugMonSize, simMemSize, argOffset, debugFlag;
    u32 trackLocation, trackSize, countryCode, reserved, longFileNameSupport;
    u32 padSpec;
} BI2Debug;
extern void *memset(void *, int, u32), *memcpy(void *, const void *, u32);
extern u32 OSGetResetCode(void);
extern void *OSGetArenaLo(void), *OSGetArenaHi(void);
extern void OSSetArenaLo(void *), OSSetArenaHi(void *);
extern void PPCDisableSpeculation(void), PPCSetFpNonIEEEMode(void);
extern u32 PPCMfhid2(void);
extern void PPCMthid2(u32);
extern void __OSInitSystemCall(void), __OSModuleInit(void), __OSInterruptInit(void);
extern void *__OSSetInterruptHandler(int, void *);
extern void __OSContextInit(void), __OSCacheInit(void), EXIInit(void), SIInit(void);
extern void __OSInitSram(void), __OSThreadInit(void), __OSInitAudioSystem(void);
extern void __OSInitMemoryProtection(void), EnableMetroTRKInterrupts(void);
extern BOOL OSEnableInterrupts(void);
extern void DVDInit(void);
extern BOOL DVDInquiryAsync(void *, DVDDriveInfo *, DVDCBCallback);
extern void DCInvalidateRange(void *, u32), DCFlushRangeNoSync(void *, u32), ICInvalidateRange(void *, u32);
extern void __sync(void);
extern void OSRegisterVersion(const char *);
#endif
