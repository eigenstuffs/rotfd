/* Dolphin initial FST loading, GSQE78. Public Melee SDK adaptation. */
#include "dvd_state_abi.h"
extern void *OSGetArenaHi(void);
extern void OSSetArenaHi(void *);
extern s32 DVDGetDriveStatus(void);
extern BOOL DVDReadDiskID(DVDCommandBlock *, DVDDiskID *, DVDCBCallback);
extern BOOL DVDReadAbsAsyncForBS(DVDCommandBlock *, void *, s32, s32, DVDCBCallback);

// .bss
static unsigned char bb2Buf[63];

// .sbss
static unsigned long status;   
static struct DVDBB2* bb2;     
static struct DVDDiskID* idTmp;

// functions
static void cb(long result, struct DVDCommandBlock* block);
void __fstLoad();

static void cb(long result, struct DVDCommandBlock* block)
{
    if (result > 0) {
        switch (status) {
        case 0:
            status = 1;
            DVDReadAbsAsyncForBS(block, bb2, 0x20, 0x420, cb);
            return;
        case 1:
            status = 2;
            DVDReadAbsAsyncForBS(block, bb2->FSTAddress,
                                 (bb2->FSTLength + 0x1F) & 0xFFFFFFE0,
                                 bb2->FSTPosition, cb);
        default:
            return;
        }
    }
    if (result == -1) {
        return;
    } else if (result == -4) {
        status = 0;
        DVDReset();
        DVDReadDiskID(block, idTmp, cb);
    }
}

void __fstLoad()
{
    OSBootInfo* bootInfo;
    struct DVDDiskID* id;
    unsigned char idTmpBuf[63];
    long state;
    void* arenaHi;
    static struct DVDCommandBlock block;

    arenaHi = OSGetArenaHi();
    bootInfo = (void*) OSPhysicalToCached(0);
    idTmp = (void*) OSRoundUp32B(idTmpBuf);
    bb2 = (void*) OSRoundUp32B(bb2Buf);
    DVDReset();
    DVDReadDiskID(&block, idTmp, cb);
    while (1) {
        state = DVDGetDriveStatus();
        if (state == 0) {
            break;
        }

    }
    bootInfo->FSTLocation = (void*) bb2->FSTAddress;
    bootInfo->FSTMaxLength = bb2->FSTMaxLength;
    id = &bootInfo->DVDDiskID;
    memcpy(id, idTmp, 0x20);
    OSReport("\n");
    OSReport("  Game Name ... %c%c%c%c\n", id->gameName[0], id->gameName[1],
             id->gameName[2], id->gameName[3]);
    OSReport("  Company ..... %c%c\n", id->company[0], id->company[1]);
    OSReport("  Disk # ...... %d\n", id->diskNumber);
    OSReport("  Game ver .... %d\n", id->gameVersion);
    OSReport("  Streaming ... %s\n", !(id->streaming) ? "OFF" : "ON");
    OSReport("\n");
    OSSetArenaHi(bb2->FSTAddress);
}
