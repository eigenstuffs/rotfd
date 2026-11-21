/* Local file-system and command-block ABI, GSQE78. */
#ifndef ROTFD_DVDFS_ABI_H
#define ROTFD_DVDFS_ABI_H
#include "dvd_abi.h"
#define OSPhysicalToCached(x) ((void *)((u32)(x) + 0x80000000))
#define DVD_STATE_END 0
#define DVD_MIN_TRANSFER_SIZE 32
struct OSBootInfo_s { u8 prefix[0x38]; struct FSTEntry *FSTLocation; };
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
extern BOOL DVDGetCurrentDir(char *, u32);
extern BOOL DVDCancel(DVDCommandBlock *);
extern BOOL DVDReadAbsAsyncPrio(DVDCommandBlock *, void *, u32, u32, DVDCBCallback, s32);
extern int tolower(int);
extern void OSPanic(const char *, int, const char *, ...);
#endif
