/* Dolphin multi-channel host communication. See docs/notes/mcc.md. */
#include "mcc_abi.h"
#define ATTRIBUTE_ALIGN(n) __attribute__((aligned(n)))
extern u32 __OSBusClock : 0x800000F8;
#define OSTicksToSeconds(ticks) ((ticks) / (__OSBusClock / 4))
#define OSSecondsToTicks(ticks) ((ticks) * (__OSBusClock / 4))
extern u32 OSGetTick(void);
extern void DCInvalidateRange(void *, u32), DCFlushRange(void *, u32);
extern void *memset(void *, int, unsigned long);
extern BOOL HIORead(u32, void *, s32), HIOWrite(u32, void *, s32);
extern BOOL HIOReadAsync(u32, void *, s32, void (*)(void)), HIOWriteAsync(u32, void *, s32, void (*)(void));
extern BOOL HIOReadStatus(u32 *), HIOWriteMailbox(u32);

// .bss
static MCC_ChannelInfo gChannelInfo[16] ATTRIBUTE_ALIGN(32);
static char gStreamWork[32] ATTRIBUTE_ALIGN(32);
static char m_szAdapterMode[32] ATTRIBUTE_ALIGN(32);
static char m_szInitCode[32] ATTRIBUTE_ALIGN(32);

static MCC_Info channelInfo[16] ATTRIBUTE_ALIGN(32);

// .sdata
volatile static int gIsChannelinfoDirty = 1;

// .sbss

volatile static unsigned char gLastError;
static int gMccInitialized;

volatile static unsigned short gAsyncResourceStatus;

// functions
static inline void mccDebugPrint(char *str);
static void callbackEventStream(enum MCC_CHANNEL chID, u32 event, u32 value);
static inline void AsyncResourceClearState(void);
static inline void AsyncResourceSetState(u16 state);
static inline void AsyncResourceStateBusy(u8 channel, u16 mode);
static inline void AsyncResourceStateDone(void);
static inline u16 AsyncResourceGetStat(void);
static inline u16 AsyncResourceGetMode(void);
static inline u8 AsyncResourceGetChannel(void);
static inline int AsyncResourceIsBusy(void);
static int LoadChannelInfo(MCC_ChannelInfo *info);
static int FlushChannelInfo(MCC_ChannelInfo *info);
static void SetChannelInfoDirty(int dirty);
static inline void ClearChannelInfo(int i);
static void MakeMemoryMap(u8 *map);
static inline int IsChannelOpened(enum MCC_CHANNEL chID);
static u8 SearchFreeBlocks(enum MCC_MODE mode, u8 *index);
static int NotifyCompulsorily(enum MCC_CHANNEL chID, u32 notify, u32 timeout);
static inline int NotifyChannelEvent(enum MCC_CHANNEL chID, u32 notify);
static int WaitAMinute(int timeout, volatile int * flag, int value);
static void MCCTxCallback(void);
static void MCCRxCallback(void);

static inline void mccDebugPrint(char *str) {
    
}

static void callbackEventStream(enum MCC_CHANNEL chID, u32 event, u32 value) {
    (void)value;
    if (event == 16) {
        gChannelInfo[chID].isStreamDone = 1;
    }
    if (event == 32) {
        gChannelInfo[chID].isStreamDone = 1;
    }
    if (event == 1) {
        gChannelInfo[chID].isStreamConnection = 1;
    }
    if (event == 2) {
        gChannelInfo[chID].isStreamConnection = 1;
    }
    if (event == 0x100) {
        gChannelInfo[chID].isStreamConnection = 1;
    }
}

int MCCStreamOpen(enum MCC_CHANNEL chID, u8 blockSize) {
    int bResult;

    bResult = 0;
    if (MCCOpen(chID, blockSize, callbackEventStream) != 0) {
        gChannelInfo[chID].unk = 0;
        gChannelInfo[chID].isStreamConnection = 0;
        gChannelInfo[chID].isStreamDone = 0;
        bResult = 1;
    }
    return bResult;
}

int MCCStreamClose(enum MCC_CHANNEL chID) {
    gChannelInfo[chID].unk = 0;
    MCCClose(chID);
}

u32 MCCStreamRead(enum MCC_CHANNEL chID, void *data) {
    MCC_Info chanInfo;
    char *dataAddress;
    u32 allBlocks;
    u32 lastBlocks;

    if (gMccInitialized == 0) {
        gLastError = 1;
    } else if ((chID < 1) || (chID >= 0x10)) {
        gLastError = 0xE;
    } else if (LoadChannelInfo(gChannelInfo) == 0) {
        gLastError = 0xB;
    } else {
        if (gChannelInfo[chID].unk != 1) {
            gChannelInfo[chID].unk = 1;
        } else {
            MCCNotify(chID, 0);
        }
        if (WaitAMinute(5, &gChannelInfo[chID].isStreamConnection, 1) == 0) {
            gLastError = 2;
        } else {
            gChannelInfo[chID].isStreamConnection = 0;
            if (MCCGetChannelInfo(chID, &chanInfo) != 0) {
                if (WaitAMinute(5, &gChannelInfo[chID].isStreamDone, 1) == 0) {
                    gLastError = 2;
                } else {
                    gChannelInfo[chID].isStreamDone = 0;
                    if (MCCRead(chID, 0, gStreamWork, 0x20, 0) != 0) {
                        dataAddress = data;
                        allBlocks = lastBlocks = *(u32*)&gStreamWork[0];
                        while(lastBlocks) {
                            if (WaitAMinute(5, &gChannelInfo[chID].isStreamDone, 1) == 0) {
                                gLastError = 2;
                                break;
                            }
                            gChannelInfo[chID].isStreamDone = 0;
                            if (MCCRead(chID, 0, dataAddress, (lastBlocks > chanInfo.blockLength) ? chanInfo.blockLength << 0xD : lastBlocks << 0xD, 0) != 0) {
                                dataAddress += chanInfo.blockLength << 0xD;
                                if (lastBlocks > chanInfo.blockLength) {
                                    lastBlocks -= chanInfo.blockLength;
                                } else {
                                    lastBlocks = 0;
                                    break;
                                }
                            } else {
                                break;
                            }
                        }
                        return allBlocks - lastBlocks;
                    }
                }
            }
        }
    }
    return 0;
}

static inline void AsyncResourceClearState(void) {
    gAsyncResourceStatus = 0;
}

static inline void AsyncResourceSetState(u16 state) {
    gAsyncResourceStatus &= 0xFFFF0FFF;
    gAsyncResourceStatus |= state;    
}

static inline void AsyncResourceStateBusy(u8 channel, u16 mode) {
    AsyncResourceClearState();
    AsyncResourceSetState(0x1000);
    gAsyncResourceStatus |= channel;
    gAsyncResourceStatus |= mode;
}

static inline void AsyncResourceStateDone(void) {
    AsyncResourceSetState(0x2000);
}

static inline u16 AsyncResourceGetStat(void) {
    return gAsyncResourceStatus & 0xF000;
}

static inline u16 AsyncResourceGetMode(void) {
    return gAsyncResourceStatus & 0xF00;
}

static inline u8 AsyncResourceGetChannel(void) {
    return gAsyncResourceStatus;
}

static inline int AsyncResourceIsBusy(void) {
    return AsyncResourceGetStat() & 0x1000;
}

static int LoadChannelInfo(MCC_ChannelInfo *info) {
    volatile int result = 0;
    u8 count;
#ifndef DEBUG
    int reservedStack; /* Observed frame space; original local identity is unknown. */
#endif

    if (gIsChannelinfoDirty == 0) {
        result = 1;
    } else {
        count = 0;
        mccDebugPrint("+++ Load channel info.");
        while((result = HIORead(0x700, channelInfo, 0x40)) != 1) {
            count -= 1;
            if (count == 0) {
                break;
            }
        }
        if (result) {
            DCInvalidateRange(channelInfo, 0x40);
            for(count = 0; count < 16; count++) {
                info[count].info = channelInfo[count];
            }
            SetChannelInfoDirty(0);
        }
    }
    return result;
}

static int FlushChannelInfo(MCC_ChannelInfo *info) {
    volatile int result;
    u8 count;

    result = 0;
    for(count = 0; count < 16; count++) {
        channelInfo[count] = info[count].info;
    }
    DCFlushRange(channelInfo, 0x40);
    while((result = HIOWrite(0x700, channelInfo, 0x40)) != 1) {
        count -= 1;
        if (count == 0) {
            break;
        }
    }
    if (result != 0) {
        SetChannelInfoDirty(1);
        result = NotifyCompulsorily(0, 5, 0xAU);
    }
    return result;
}

static void SetChannelInfoDirty(int dirty) {
    gIsChannelinfoDirty = dirty;
}

static inline void ClearChannelInfo(int i) {
    gChannelInfo[i].info.firstBlock = 0;
    gChannelInfo[i].info.blockLength = 0;
    gChannelInfo[i].info.connect = 0;
    gChannelInfo[i].info.isLocked = 0;
    gChannelInfo[i].eventMask = 0;
    gChannelInfo[i].callbackEvent = NULL;
    gChannelInfo[i].isStreamDone = 0;
    //! isStreamConnection isnt cleared. Intentional?
}

static void MakeMemoryMap(u8 *map) {
    u8 iMap;
    u8 jMap;

    memset(map, 0, 0x10);
    for(iMap = 0; iMap < 16; iMap++) {
        if (gChannelInfo[iMap].info.connect) {
            for(jMap = 0; jMap < gChannelInfo[iMap].info.blockLength; jMap++) {
                if (jMap + gChannelInfo[iMap].info.firstBlock < 0x10) {
                    map[gChannelInfo[iMap].info.firstBlock + jMap] = iMap + 1;
                } else {
                    gLastError = 0xD;
                }
            }
        }
    }
    *map = 0xFF;
}

static inline int IsChannelOpened(enum MCC_CHANNEL chID) {
    u8 connectSide;

    if ((chID <= 0) || (chID >= 0x10)) {
        gLastError = 0xE;
        goto exit;
    }
    connectSide = 2;

    return (connectSide & gChannelInfo[chID].info.connect) ? 1 : 0;

exit:;
    return 0;
}

static u8 SearchFreeBlocks(enum MCC_MODE mode, u8 *index) {
    u8 map[16];
    u8 iMap;
    u8 fIndex;
    u8 fSize;
    u8 fCount;

    MakeMemoryMap(map);
    fCount = 0;
    fIndex = 0;
    fSize = (mode == 0) ? 0x10 : 0;

    //! @bug I think this will read OOB of the map array by 1.
    for(iMap = 0; iMap <= 16; iMap++) {
        if (map[iMap] || iMap == 16) {
            if (fCount != 0) {
                if (mode == 0) {
                    if (fSize > fCount) {
                        fSize = fCount;
                        fIndex = iMap - fCount;
                    }
                } else if (mode == 1) {
                    if (fSize < fCount) {
                        fSize = fCount;
                        fIndex = iMap - fCount;
                    }
                } else if (mode == 2) {
                    fSize += fCount;
                }
                fCount = 0;
            }
        } else {
            fCount += 1;
        }
    }
    if (index) {
        *index = fIndex;
    }
    return fSize;
}

static int NotifyCompulsorily(enum MCC_CHANNEL chID, u32 notify, u32 timeout) {
    u32 status;
    u32 notifyData;
    volatile u32 tickStart;
    volatile u32 tickCur;
    volatile u32 tickSec;
#ifndef DEBUG
    int reservedStack; /* Observed frame space; original local identity is unknown. */
#endif

    status = 0;
    tickStart = OSGetTick();

    notifyData = (chID << 0x18);
    notifyData |= (notify & 0x10000000);
    notifyData |= (notify & 0xFFFFFF);

    while(1) {
        if (!HIOReadStatus(&status)) {
            mccDebugPrint("ERROR:HIOReadStatus\n");
        }
        if ((status & 2) == 0) {
            break;
        }
        tickCur = OSGetTick();
        tickSec = (tickStart < tickCur) ? tickCur - tickStart : (-1 - tickStart) + tickCur;
        tickSec = OSTicksToSeconds(tickSec);
        if (timeout == 0 || tickSec > timeout) {
            break;
        }
    }
    if (!HIOWriteMailbox(notifyData)) {
        gLastError = 6;
        goto exit;
    }
    return 1;
exit:;
    return 0;
}

static inline int NotifyChannelEvent(enum MCC_CHANNEL chID, u32 notify) {
#ifndef DEBUG
    int reservedStack[2]; /* Observed frame space; original local identity is unknown. */
#endif

    if (LoadChannelInfo(gChannelInfo) == 0) {
        mccDebugPrint("Error:Could not update channelInfo.\n");
        gLastError = 0xB;
    } else if (IsChannelOpened(chID) == 0) {
        mccDebugPrint("Error:Channel is not opened.\n");
        gLastError = 0x12;
    } else if (NotifyCompulsorily(chID, notify, 0xAU) != 0) {
        return 1;
    }
    return 0;
}

static int WaitAMinute(int timeout, volatile int * flag, int value) {
    u32 tickStart;
    u32 tickDist;

    tickStart = OSGetTick();
    while(*flag != value) {
        tickDist = OSGetTick() - tickStart;
        tickDist = (tickDist & 0x80000000) ? (0x80000000 - tickStart) + OSGetTick() : tickDist;
        if (OSTicksToSeconds(tickDist) >= timeout) {
            mccDebugPrint("Error:Time is over.\n");
            return 0;
        }
    }
    return 1;
}

static void MCCTxCallback(void) {
    AsyncResourceStateDone();
}

static void MCCRxCallback(void) {
    AsyncResourceStateDone();
}

u8 MCCGetLastError(void) {
    mccDebugPrint("MCCGetFreeBlocks\n"); //! wrong print?
    return gLastError;
}

int MCCGetChannelInfo(enum MCC_CHANNEL chID, MCC_Info *info) {
#ifndef DEBUG
    int reservedStack[3]; /* Observed frame space; original local identity is unknown. */
#endif

    mccDebugPrint("MCCGetChannelInfo\n");
    if (gMccInitialized == 0) {
        gLastError = 1;
    } else if ((chID <= 0) || (chID >= 0x10)) {
        gLastError = 0xE;
    } else if (!info) {
        mccDebugPrint("Error:Bad parameter channelInfo.\n");
        gLastError = 0xD;
    } else {
        if (LoadChannelInfo(gChannelInfo) == 0) {
            mccDebugPrint("Error:Could not update channelInfo.\n");
            gLastError = 0xB;
        } else {
            memcpy(info, &gChannelInfo[chID].info, sizeof(MCC_Info));
            gLastError = 0;
            return 1;
        }
    }
    return 0;
}

int MCCGetConnectionStatus(enum MCC_CHANNEL chID, enum MCC_CONNECT *connect) {
    MCC_Info info;
#ifndef DEBUG
    int reservedStack[2]; /* Observed frame space; original local identity is unknown. */
#endif

    mccDebugPrint("MCCGetConnectionStatus\n");
    if (gMccInitialized == 0) {
        gLastError = 1;
        return 0;
    }
    if ((chID < 1) || (chID >= 0x10)) {
        gLastError = 0xE;
        return 0;
    }
    if (AsyncResourceIsBusy() != 0) {
        gLastError = 0x15;
        return 0;
    }
    if (!connect) {
        mccDebugPrint("Error:Parameter error.\n");
        gLastError = 0xD;
    } else {
        if (MCCGetChannelInfo(chID, &info) != 0) {
            *connect = info.connect;
            gLastError = 0;
            return 1;
        }
    }
    return 0;
}

int MCCNotify(enum MCC_CHANNEL chID, u32 notify) {
    enum MCC_CONNECT connect;
#ifndef DEBUG
    int reservedStack[3]; /* Observed frame space; original local identity is unknown. */
#endif

    mccDebugPrint("MCCNotify\n");
    if (gMccInitialized == 0) {
        gLastError = 1;
    } else if((chID <= 0) || (chID >= 0x10)) {
        gLastError = 0xE;;
    } else if (LoadChannelInfo(gChannelInfo) == 0) {
        mccDebugPrint("Error:Could not update channelInfo.\n");
        gLastError = 0xB;
    } else if(MCCGetConnectionStatus(chID, &connect) == 0) {
        gLastError = 9;
    } else {
        if (connect != 3) {
            mccDebugPrint("Error:Channel is not opened.\n");
            gLastError = 0x12;
        } else {
            notify |= 0x10000000;
            return NotifyCompulsorily(chID, notify, 0xAU);
        }
    }
    return 0;
}

u32 MCCSetChannelEventMask(enum MCC_CHANNEL chID, u32 event) {
    u32 oldMask;
#ifndef DEBUG
    int reservedStack[2]; /* Observed frame space; original local identity is unknown. */
#endif

    oldMask = 0xFFFFFFFF;
    if (gMccInitialized == 0) {
        gLastError = 1;
    } else if ((chID <= 0) || (chID >= 0x10)) {
        gLastError = 0xE;
    } else if (LoadChannelInfo(gChannelInfo) == 0) {
        mccDebugPrint("Error:Could not update channelInfo.\n");
        gLastError = 0xB;
    } else if (IsChannelOpened(chID) == 0) {
        mccDebugPrint("Error:This channel is closed.");
        gLastError = 0x12;
    } else {
        oldMask = gChannelInfo[chID].eventMask;
        gChannelInfo[chID].eventMask = (u16)event;
    }
    return oldMask;
}

int MCCOpen(enum MCC_CHANNEL chID, u8 blockSize, MCC_CBEvent callbackEvent) {
    u8 connectSide;
    u8 blockIndex;
#ifndef DEBUG
    int unused2[2];
#endif
    u8 freeBlocks;
#ifndef DEBUG
    int reservedStack[6]; /* Observed frame space; original local identity is unknown. */
#endif

    mccDebugPrint("MCCOpen\n");
    if (gMccInitialized == 0) {
        gLastError = 1;
        return 0;
    }
    if ((chID < 1) || (chID >= 0x10)) {
        gLastError = 0xE;
        return 0;
    }
    if (AsyncResourceIsBusy() != 0) {
        gLastError = 0x15;
        return 0;
    }
    if (blockSize == 0) {
        gLastError = 0xF;
        return 0;
    }
    if ((chID <= 0) || (chID >= 0x10)) {
        mccDebugPrint("Error:Invalid channel.\n");
        gLastError = 0xE;
        goto exit;
    } else {
        connectSide = 2;
        if (LoadChannelInfo(gChannelInfo) == 0) {
            mccDebugPrint("Error:Could not update channelInfo.\n");
            gLastError = 0xB;
            goto exit;
        } else if (!gChannelInfo[chID].info.connect) {
            freeBlocks = SearchFreeBlocks(1, &blockIndex);
            if (blockSize > freeBlocks) {
                mccDebugPrint("Error:Not enough free blocks.\n");
                gLastError = 0xC;
                goto exit;
            } else {
                gChannelInfo[chID].info.firstBlock = blockIndex;
                gChannelInfo[chID].info.blockLength = blockSize;
                gChannelInfo[chID].info.connect = connectSide;
                gChannelInfo[chID].info.isLocked = 0;
                gChannelInfo[chID].eventMask = 0;
                gChannelInfo[chID].callbackEvent = callbackEvent;
                gChannelInfo[chID].isStreamDone = 0;
                if (FlushChannelInfo(gChannelInfo) == 0) {
                    mccDebugPrint("Error:Could not flush channelInfo.\n");
                    gLastError = 0xA;
                    goto exit;
                }
                gLastError = 0;
                return 1;
            }
        }
    }
    if (gChannelInfo[chID].info.connect & connectSide) {
        mccDebugPrint("Error:Already opened.\n");
        gLastError = 0x11;
        goto exit;
    } else if (blockSize != gChannelInfo[chID].info.blockLength) {
        mccDebugPrint("Error:Block size error.\n");
        gLastError = 0xD;
        goto exit;
    }
    gChannelInfo[chID].info.connect = 3;
    gChannelInfo[chID].callbackEvent = callbackEvent;
    if (FlushChannelInfo(gChannelInfo) == 0) {
        mccDebugPrint("Error:Could not flush channelInfo.\n");
        gLastError = 0xA;
        goto exit;
    }
    if (~(gChannelInfo[chID].eventMask) & 1) {
        NotifyCompulsorily(chID, 1, 0xAU);
        if (gChannelInfo[chID].callbackEvent) {
            gChannelInfo[chID].callbackEvent(chID, 1, 0);
        }
    }
    gLastError = 0;
    return 1;
exit:;
    return 0;
}

int MCCClose(enum MCC_CHANNEL chID) {
    u8 connectSide;
#ifndef DEBUG
    int reservedStack[4]; /* Observed frame space; original local identity is unknown. */
#endif

    connectSide = 2;
    mccDebugPrint("MCCClose\n");
    if (gMccInitialized == 0) {
        gLastError = 1;
        return 0;
    }
    if ((chID < 1) || (chID >= 0x10)) {
        gLastError = 0xE;
        return 0;
    }
    if (AsyncResourceIsBusy() != 0) {
        gLastError = 0x15;
        return 0;
    }
    if (LoadChannelInfo(gChannelInfo) == 0) {
        mccDebugPrint("Error:Could not update channelInfo.\n");
        gLastError = 0xB;
        goto exit;
    }
    if (IsChannelOpened(chID) == 0) {
        mccDebugPrint("Error:This channel is closed.");
        gLastError = 0x12;
        goto exit;
    }
    gChannelInfo[chID].info.connect &= ~connectSide;
    if (gChannelInfo[chID].info.connect == 0) {
        ClearChannelInfo(chID);
    }
    if (FlushChannelInfo(gChannelInfo) == 0) {
        mccDebugPrint("Error:Could not flush channelInfo.\n");
        gLastError = 0xA;
        goto exit;
    }
    if (gChannelInfo[chID].info.connect != 0) {
        if (~(gChannelInfo[chID].eventMask) & 2) {
            NotifyCompulsorily(chID, 2, 0xAU);
            if (gChannelInfo[chID].callbackEvent) {
                gChannelInfo[chID].callbackEvent(chID, 2, 0);
            }
        }
    }
    gLastError = 0;
    return 1;
exit:;
    return 0;
}

int MCCRead(enum MCC_CHANNEL chID, u32 offset, void *data, long size, enum MCC_SYNC_STATE async) {
#ifndef DEBUG
    int reservedStack[11]; /* Observed frame space; original local identity is unknown. */
#endif

    mccDebugPrint("MCCRead\n");
    if (gMccInitialized == 0) {
        gLastError = 1;
        return 0;
    }
    if ((chID < 1) || (chID >= 0x10)) {
        gLastError = 0xE;
        return 0;
    }
    if (!((async == 1) || (async == 0))) {
        gLastError = 0xD;
        return 0;
    }
    if ((offset & 3) || ((u32)data & 0x1F) || (size % 32) != 0) {
        gLastError = 0xD;
        return 0;
    }
    if (AsyncResourceIsBusy() != 0) {
        gLastError = 0x15;
        return 0;
    }
    if (LoadChannelInfo(gChannelInfo) == 0) {
        mccDebugPrint("Error:Could not update channelInfo.\n");
        gLastError = 0xB;
        goto exit;
    }
    if (IsChannelOpened(chID) == 0) {
        mccDebugPrint("Error:This channel is closed.");
        gLastError = 0x12;
        goto exit;
    }
    if (offset > gChannelInfo[chID].info.blockLength << 0xD) {
        mccDebugPrint("Error:Invarid offset");
        gLastError = 0x10;
        goto exit;
    }
    if ((offset + size) > gChannelInfo[chID].info.blockLength << 0xD) {
        mccDebugPrint("Error:Invarid data size.");
        gLastError = 0xF;
        goto exit;
    }
    if (async == 1) {
        if (MCCCheckAsyncDone() == 0) {
            mccDebugPrint("Error:Channel busy.");
            gLastError = 0x15;
            goto exit;
        }
        AsyncResourceStateBusy(chID, 0U);
        if (HIOReadAsync(offset + (gChannelInfo[chID].info.firstBlock << 0xD), data, size, MCCRxCallback) == 0) {
            mccDebugPrint("Error:Read data error.");
            gLastError = 7;
            goto exit;
        }
        DCInvalidateRange(data, size);
        gLastError = 0;
        return 1;
    }
    if (HIORead(offset + (gChannelInfo[chID].info.firstBlock << 0xD), data, size) == 0) {
        mccDebugPrint("Error:Read data error.");
        gLastError = 7;
        goto exit;
    }
    DCInvalidateRange(data, size);
    if (~(gChannelInfo[chID].eventMask) & 0x10) {
        NotifyChannelEvent(chID, 0x10);
    }
    if (~(gChannelInfo[chID].eventMask) & 0x40 && gChannelInfo[chID].callbackEvent) {
        gChannelInfo[chID].callbackEvent(chID, 0x40, 0);
    }
    gLastError = 0;
    return 1;
exit:;
    return 0;
}

int MCCWrite(enum MCC_CHANNEL chID, u32 offset, void *data, long size, enum MCC_SYNC_STATE async) {
#ifndef DEBUG
    int reservedStack[11]; /* Observed frame space; original local identity is unknown. */
#endif
    mccDebugPrint("MCCWrite\n");

    if (gMccInitialized == 0) {
        gLastError = 1;
        return 0;
    }
    if ((chID < 1) || (chID >= 0x10)) {
        gLastError = 0xE;
        return 0;
    }
    if (!((async == 1) || (async == 0))) {
        gLastError = 0xD;
        return 0;
    }
    if ((offset & 3) || ((u32)data & 0x1F) || (size % 32) != 0) {
        gLastError = 0xD;
        return 0;
    }
    if (AsyncResourceIsBusy() != 0) {
        gLastError = 0x15;
        return 0;
    }
    if (LoadChannelInfo(gChannelInfo) == 0) {
        mccDebugPrint("Error:Could not update channelInfo.\n");
        gLastError = 0xB;
        goto exit;
    }
    if (IsChannelOpened(chID) == 0) {
        mccDebugPrint("Error:This channel is closed.");
        gLastError = 0x12;
        goto exit;
    }
    if (gChannelInfo[chID].info.isLocked == 1) {
        mccDebugPrint("Error:This channel was locked.");
        gLastError = 0x13;
        goto exit;
    }
    if (offset > (gChannelInfo[chID].info.blockLength << 0xD)) {
        mccDebugPrint("Error:Invarid offset");
        gLastError = 0x10;
        goto exit;
    }
    if (offset + size > (gChannelInfo[chID].info.blockLength << 0xD)) {
        mccDebugPrint("Error:Invarid data size.");
        gLastError = 0xF;
        goto exit;
    }
    if (async == 1) {
        if (MCCCheckAsyncDone() == 0) {
            mccDebugPrint("Error:Channel busy.");
            gLastError = 0x15;
            goto exit;
        }
        AsyncResourceStateBusy(chID, 0x100U);
        DCFlushRange(data, size);
        if (HIOWriteAsync(offset + (gChannelInfo[chID].info.firstBlock << 0xD), data, size, MCCTxCallback) == 0) {
            mccDebugPrint("Error:Write data error.");
            gLastError = 8;
            goto exit;
        }
        gLastError = 0;
        return 1;
    }
    DCFlushRange(data, size);
    if (HIOWrite(offset + (gChannelInfo[chID].info.firstBlock << 0xD), data, size) == 0) {
        mccDebugPrint("Error:Write data error.");
        gLastError = 8;
        goto exit;
    }
    if (~(gChannelInfo[chID].eventMask) & 0x20) {
        NotifyChannelEvent(chID, 0x20);
    }
    if (~(gChannelInfo[chID].eventMask) & 0x80 && gChannelInfo[chID].callbackEvent) {
        gChannelInfo[chID].callbackEvent(chID, 0x80, 0);
    }
    gLastError = 0;
    return 1;
exit:
    return 0;
}

int MCCCheckAsyncDone() {
    u16 stat;
    u16 mode;
    u8 chID;
#ifndef DEBUG
    int reservedStack[5]; /* Observed frame space; original local identity is unknown. */
#endif

    if (gMccInitialized == 0) {
        gLastError = 1;
        return 0;
    }
    stat = AsyncResourceGetStat();
    if (stat == 0x1000) {
        return 0;
    } else if (stat && stat == 0x2000) {
        mode = AsyncResourceGetMode();
        chID = AsyncResourceGetChannel();
        AsyncResourceClearState();
        if (mode == 0) {
            if (~(gChannelInfo[chID].eventMask) & 0x10) {
                NotifyChannelEvent(chID, 0x10);
            }
            if (~(gChannelInfo[chID].eventMask) & 0x40 && gChannelInfo[chID].callbackEvent) {
                gChannelInfo[chID].callbackEvent(chID, 0x40, 0);
            }
        } else {
            if (~(gChannelInfo[chID].eventMask) & 0x20) {
                NotifyChannelEvent(chID, 0x20);
            }
            if (~(gChannelInfo[chID].eventMask) & 0x80 && gChannelInfo[chID].callbackEvent) {
                gChannelInfo[chID].callbackEvent(chID, 0x80, 0);
            }
        }
    }
    return 1;
}
