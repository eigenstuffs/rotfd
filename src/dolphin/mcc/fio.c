#include "mcc_abi.h"
typedef signed char s8;
extern u32 __OSBusClock : 0x800000F8;
#define OSTicksToSeconds(ticks) ((ticks) / (__OSBusClock / 4))
#define OSRoundUp32B(x) (((u32)(x) + 31) & ~31)
extern u32 OSGetTick(void);
extern void OSReport(const char *, ...);
extern int sprintf(char *, const char *, ...);
extern unsigned long strlen(const char *);
extern void *memcpy(void *, const void *, unsigned long);

static char string_FioVersion[] = "<< Dolphin SDK - FIO\trelease build: Sep  5 2002 05:35:41 (0x2301) >>";
static char string_FioTimeout[] = "Error:Time is over.\n";
static char string_FioUnlocked[] = "UNLOCKED";
static char string_FioDisconnected[] = "DISCONNECT";
static char string_FioHostOpen[] = "HOST_OPEN";
static char string_FioTargetOpen[] = "TARGET_OPEN";
static char string_FioConnected[] = "CONNECTED";
static char string_FioChannelInfo[] = "%2d: FirstBlock:%02d,BlockLength:%02d,Connect:%s,Lock:%s.\n";
static char string_FioError[] = "[fio] Error: %s\n";
static char string_FioSendWriteError[] = "fioPacketSendPacket.MCCWrite.NG";
static char string_FioSendNotifyError[] = "fioPacketSendPacket.MCCNotify.NG";
static char string_FioReadCloseError[] = "fioPacketResultRead.MCCClose.NG";
static char string_FioReadStreamOpenError[] = "fioPacketResultRead.MCCStreamOpen.NG";
static char string_FioReadStreamError[] = "fioPacketResultRead.MCCStreamRead.NG(Err:%d)";
static char string_FioStreamCloseError[] = "MCCStream:MCCStreamClose.NG\n";
static char string_FioStreamOpenError[] = "MCCStream:MCCOpen.NG\n";
static char string_FioWriteCloseError[] = "fioPacketResultWrite.MCCClose.NG";
static char string_FioWriteStreamOpenError[] = "fioPacketResultWrite.MCCStreamOpen.NG";
static char string_FioWriteStreamError[] = "fioPacketResultWrite.MCCStreamWrite.NG";

static u8 gBuf[8192];

static u8 gmSizeOfBlocks = 1;
volatile static int gProcDone = 1;

static enum MCC_CHANNEL gmChID;
static enum MCC_CHANNEL gChID;
static int gQuery;
volatile static int gProcBusy;
volatile static u32 gStreamReady;
static u8 gLastErr;
static enum FIO_ASYNC_STATE bAsyncBusy;
static u32 gAsyncDataSize;
static u32 gRequestSequenceNumber;

// functions
static inline int fioIsInitialized();
static inline u16 EndianConvert16(u16 n);
static inline u32 EndianConvert32(u32 n);
static inline int MPDWaiting(int timeout, volatile int * flag, int value);
static inline void fioErrorReport(char * msg);
static void fioMccChannelEvent(enum MCC_CHANNEL chID, u32 event, u32 value);
static void *fioPacketMakeHeader(u32 fioCode, u32 dataSize, int bEndianConvert);
static int fioPacketSendPacket(u8 sizeOfBlocks, void *pTopOfSecondBlockData);
static void *fioPacketReceiveResult(u32 fioCode, int bDone);
static void fioPacketReceiveDone(void);
static int fioPacketRead(int fd, void *buffer, int size, int async);
static int fioPacketResultRead(void *buffer, u32 dataSize);

static inline int fioIsInitialized() {
    return !!gChID;
}

static inline u16 EndianConvert16(u16 n) {
    return ((n & 0x00FF) << 8) | ((n & 0xFF00) >> 8);
}

static inline u32 EndianConvert32(u32 n) {
    return EndianConvert16((n >> 16) & 0xFFFF) | (EndianConvert16(n & 0xFFFF) << 0x10);
}

static inline int MPDWaiting(int timeout, volatile int * flag, int value) {
    u32 tickStart;
    u32 tickDist;

    tickStart = OSGetTick();
    while(*flag != value) {
        tickDist = OSGetTick() - tickStart;
        tickDist = (tickDist & 0x80000000) ? (0x80000000 - tickStart) + OSGetTick() : tickDist;
        if (OSTicksToSeconds(tickDist) >= timeout) {
            OSReport(string_FioTimeout);
            return 0;
        }
    }
    return 1;
}

static inline void fioErrorReport(char * msg) {
    OSReport(string_FioError, msg);
}

static void fioMccChannelEvent(enum MCC_CHANNEL chID, u32 event, u32 value) {
    u32 notify;

    switch(event) {
        case 0x1:
            gChID = chID;
            return;
        case 0x2:
            gChID = 0;
            return;
        case 0x100:
            notify = value & 0xF00000;
            switch (notify) {                         
            case 0x200000:                              
                if ((u16)value == 0x120) {
                    gQuery = 1;
                }
                return;
            case 0xF00000:                              
                gProcDone = 1;
                if ((s32) bAsyncBusy != 0) {
                    bAsyncBusy = 2;
                    return;
                }
                break;
            }
            break;
        case 0x10:
            gStreamReady = 0x10U;
            return;
        case 0x20:
            gStreamReady = 0x20U;
            break;
    }
}

int FIOFclose(int handle) {
    struct FIO_Code {
        /* 0x00 */ u32 descriptor;
    } * code;
    struct FIO_Coder {
        /* 0x00 */ u32 result;
    } * coder;

    if (handle == 0) {
        gLastErr = 0xB0;
        goto exit;
    }
    if (handle == -1) {
        gLastErr = 0xB0;
        goto exit;
    }
    if (bAsyncBusy != 0) {
        gLastErr = 0xA1;
        goto exit;
    }
    code = fioPacketMakeHeader(2, sizeof(struct FIO_Code), 0);
    code->descriptor = handle;
    if (fioPacketSendPacket(1, NULL) != 0) {
        coder = fioPacketReceiveResult(3, 1);
        if (coder != NULL) {
            gLastErr = coder->result;
            return 1;
        }
    }
exit:;
    return 0;
}

u32 FIOFread(int handle, void *data, u32 size) {
    char * pBuf;
    volatile int nSizeRemain;
    int nResult;
    int nReadSize;

    pBuf = data;
    nSizeRemain = size;
    nResult = -1;

    if (handle == 0) {
        gLastErr = 0xB0;
        goto exit;
    }
    if (handle == -1) {
        gLastErr = 0xB0;
        goto exit;
    }
    if (data == NULL || ((u32)data & 31) != 0) {
        gLastErr = 0xB0;
        goto exit;
    }
    if (size == 0) {
        return 0;
    }
    if (bAsyncBusy != 0) {
        gLastErr = 0xA1;
        goto exit;
    }
    nReadSize = fioPacketRead(handle, pBuf, nSizeRemain, 0);
    nSizeRemain = nSizeRemain - nReadSize;
    if (nReadSize < 0) {
        gLastErr = 0x84;
        return -1;
    }
    gLastErr = 0;
    return size - nSizeRemain;
exit:;
    return -1;
}

u32 FIOFseek(int handle, long offset, u32 mode) {
    struct FIO_Code {
        /* 0x00 */ u32 descriptor;
        /* 0x04 */ u32 offset;
        /* 0x08 */ u32 base;
    } *code;
    struct FIO_Coder {
        /* 0x00 */ u32 result;
        /* 0x04 */ u32 pos;
    } *coder;

    if (handle == 0) {
        gLastErr = 0xB0;
        goto exit;
    }
    if (handle == -1) {
        gLastErr = 0xB0;
        goto exit;
    }
    if (!((mode == 0) || (mode == 2) || (mode == 1U))) {
        gLastErr = 0xB0;
        goto exit;
    }
    if ((mode == 0U) && (offset < 0)) {
        gLastErr = 0xB0;
        goto exit;
    }
    if ((mode == 2U) && (offset > 0)) {
        gLastErr = 0xB0;
        goto exit;
    }
    if (bAsyncBusy != 0) {
        gLastErr = 0xA1;
        goto exit;
    }
    code = fioPacketMakeHeader(8, sizeof(struct FIO_Code), 0);
    code->descriptor = handle;
    code->offset = offset;
    code->base = mode;
    if (fioPacketSendPacket(1, NULL) != 0) {
        coder = fioPacketReceiveResult(9, 1);
        if ((coder != NULL) && (coder->result == 0)) {
            gLastErr = 0;
            return coder->pos;
        }
    }
exit:
    return -1;
}

static void *fioPacketMakeHeader(u32 fioCode, u32 dataSize, int bEndianConvert) {
    MCC_Hdr *hdrDpci;
    MCC_HdrFio *hdrFio;
    char *data;

    hdrDpci = (void*)&gBuf[0];
    hdrFio = (void*)((char*)hdrDpci + 0x8);
    data = (void*)((char*)hdrFio + 0x8);
    gRequestSequenceNumber += 1;
    hdrFio->code = fioCode;
    hdrFio->number = gRequestSequenceNumber;
    hdrDpci->length = dataSize + 0x10;
    hdrDpci->rsvd = 0;
    hdrDpci->protocol = 0x120;
    if (bEndianConvert) {
        hdrFio->code = EndianConvert32(hdrFio->code);
        hdrFio->number = EndianConvert32(hdrFio->number);
        hdrDpci->length = EndianConvert32(hdrDpci->length);
        hdrDpci->protocol = EndianConvert16(hdrDpci->protocol);
    }
    return (data);
}

static int fioPacketSendPacket(u8 sizeOfBlocks, void *pTopOfSecondBlockData) {
    u32 oldMaskWrite;
    u8 indexOfBlocks;

    oldMaskWrite = MCCSetChannelEventMask(gChID, 0xA0);
    do {} while (gProcBusy != 0);
    do {} while (gProcDone == 0);
    gProcDone = 0;
    gProcBusy = 1;
    for(indexOfBlocks = 0; indexOfBlocks < sizeOfBlocks; indexOfBlocks++) {
        if (MCCWrite(gChID, ((u8)indexOfBlocks << 0xD), &gBuf, 0x2000, 0) == 0) {
            gLastErr = 0x83;
            MCCSetChannelEventMask(gChID, oldMaskWrite);
            fioErrorReport(string_FioSendWriteError);
            return 0;
        }
        if (sizeOfBlocks > 1U) {
            memcpy(&gBuf, pTopOfSecondBlockData, 0x2000);
            ((char*)pTopOfSecondBlockData) += 0x2000;
        }
    }
    MCCSetChannelEventMask(gChID, oldMaskWrite);
    if (MCCNotify(gChID, 0xF00000) == 0) {
        gLastErr = 0x87;
        fioErrorReport(string_FioSendNotifyError);
        return 0;
    }
    gLastErr = 0;
    return 1;
}

static void *fioPacketReceiveResult(u32 fioCode, int bDone) {
    u32 oldMaskRead;
    MCC_Hdr *hdrDpci;
    MCC_HdrFio *hdrFio;
    char *data;

    if (MPDWaiting(0xAU, &gProcDone, 1) == 0) {
        gLastErr = 0x88;
        goto exit;
    }
    oldMaskRead = MCCSetChannelEventMask(gChID, 0x50);
    if (MCCRead(gChID, 0, &gBuf, 0x2000U, 0) == 0) {
        gLastErr = 0x84;
        MCCSetChannelEventMask(gChID, oldMaskRead);
        goto exit;
    }
    hdrDpci = (void*)((char*)&gBuf[0]);
    hdrFio = (void*)((char*)hdrDpci + 0x8);
    data = (void*)((char*)hdrFio + 0x8);
    MCCSetChannelEventMask(gChID, oldMaskRead);
    if (hdrFio->code != fioCode) {
        gLastErr = 0x81;
        goto exit;
    }
    if (hdrFio->number != gRequestSequenceNumber) {
        gLastErr = 0x82;
        goto exit;
    }
    if (bDone != 0) {
        fioPacketReceiveDone();
    }
    gLastErr = 0;
    return data;
exit:;
    fioPacketReceiveDone();
    return NULL;
}

static void fioPacketReceiveDone(void) {
    gProcBusy = 0;
}

static int fioPacketRead(int fd, void *buffer, int size, int async) {
    struct FIO_Code {
        /* 0x00 */ u32 descriptor;
        /* 0x04 */ u32 nbytes;
    } *code;

    code = fioPacketMakeHeader(4, sizeof(struct FIO_Code), 0);
    code->descriptor = fd;
    code->nbytes = size;
    gStreamReady = 0;
    if (fioPacketSendPacket(1U, NULL) != 0) {
        if (async == 0) {
            return fioPacketResultRead(buffer, size);
        }
        gAsyncDataSize = size;
        return 0;
    }
    return -1;
}

static int fioPacketResultRead(void *buffer, u32 dataSize) {
    int bResult;
    enum MCC_CHANNEL nChID;
    u8 nChannelBlocks;
    u32 dataBlockSize;
    u32 readDataBlocks;
    u32 nPacketSize;
    u32 nDataPacketSize;
    u32 nFraction;
    enum MCC_CONNECT state;
    int bNeedWaitDisconnect;
    u32 oldMaskWrite;
    u8 err;
    char msg[256];

    bResult = 1;
    nChID = gmChID;
    nChannelBlocks = gmSizeOfBlocks;
    dataBlockSize = (u32) (dataSize + 0x1FFF) >> 0xDU;
    nPacketSize = ((u8)nChannelBlocks << 0xD);
    nDataPacketSize = dataSize / nPacketSize;
    nFraction = dataSize - (nDataPacketSize * nPacketSize);
    nFraction = OSRoundUp32B(nFraction) & ~1;

    if (nFraction != 0) {
        do {} while ((u32) gStreamReady != 0x20U);
        MCCRead(nChID, 0, buffer, nFraction, 0);
        ((char*)buffer) += nFraction;
    }
    if (nDataPacketSize != 0) {
        bNeedWaitDisconnect = 0;
        oldMaskWrite = MCCSetChannelEventMask(nChID, 0);
        MCCSetChannelEventMask(nChID, oldMaskWrite);
        if (MCCClose(nChID) == 0) {
            fioErrorReport(string_FioReadCloseError);
            bResult = 0;
        } else {
            do {
                MCCGetConnectionStatus(nChID, &state);
            } while (state != 0);
            if (MCCStreamOpen(nChID, nChannelBlocks) == 0) {
                fioErrorReport(string_FioReadStreamOpenError);
                bResult = 0;
            } else {
                do {
                    MCCGetConnectionStatus(nChID, &state);
                } while (state != 3);

                if ((nDataPacketSize * nChannelBlocks) != (readDataBlocks = MCCStreamRead(nChID, buffer))) {
                    err = MCCGetLastError();
                    sprintf(msg, string_FioReadStreamError, err);
                    fioErrorReport(msg);
                    bResult = 0;
                }
                if (MCCStreamClose(nChID) == 0) {
                    OSReport(string_FioStreamCloseError);
                    bResult = 0;
                } else {
                    enum MCC_CONNECT state; // r1+0x10
                    do {
                        MCCGetConnectionStatus(nChID, &state);
                    } while (state != 0);
                    if (MCCOpen(nChID, nChannelBlocks, fioMccChannelEvent) == 0) {
                        OSReport(string_FioStreamOpenError);
                        bResult = 0;
                    } else {
                        do {
                            MCCGetConnectionStatus(nChID, &state);
                        } while (state != 3);
                    }
                }
            }
        }
        MCCSetChannelEventMask(gChID, oldMaskWrite);
    }
    // scope for variable?
    {
        struct FIO_Coder {
            /* 0x00 */ u32 result;
            /* 0x04 */ u32 nbytes;
            /* 0x08 */ char data;
        } * coder;

        coder = fioPacketReceiveResult(5U, 0);
        if (coder == NULL) {
            bResult = 0;
        } else if (coder->result != 0) {
            gLastErr = coder->result;
            bResult = 0;
        } else {
            gLastErr = 0;
        }
        fioPacketReceiveDone();
        if (bResult == 1) {
            return dataSize;
        }
        goto exit;
    }
exit:;
    return -1;
    
}

