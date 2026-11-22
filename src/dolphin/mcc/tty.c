#include "mcc_abi.h"
#define OSRoundUp32B(x) (((u32)(x) + 31) & ~31)
typedef struct { char gpr; char fpr; char reserved[2]; char *input_arg_area; char *reg_save_area; } va_list[1];
extern void __builtin_va_info(void *);
#define va_start(ap,fmt) ((void)fmt,__builtin_va_info(&ap))
#define va_end(ap) ((void)0)
extern int vsprintf(char *, const char *, va_list);
extern unsigned long strlen(const char *);
extern char *strchr(const char *, int);

// .bss
volatile static u8 gBuf[8192]; // size: 0x2000, address: 0x0

// .sbss
volatile static enum MCC_CHANNEL gChID;
volatile static u32 gReadDone; // size: 0x4, address: 0xC
volatile static u32 gPrintfID; // size: 0x4, address: 0x10
volatile static u32 gBufHead; // size: 0x4, address: 0x14
volatile static u32 gBufTail; // size: 0x4, address: 0x18

// functions
static inline int ttyIsInitialized();
int TTYPrintf(const char *format, ...);
static int ttyWrite(u32 offset, void *data, long size);
static int ttyFlush(u32 msgID, int waitResult);

static inline int ttyIsInitialized() {
    int bResult = (gChID != 0);

    return bResult;
}

int TTYPrintf(const char *format, ...) {
    if (ttyIsInitialized() && (format != NULL)) {
        MCC_Hdr *hdr;
        u32 *id;
        char *str;
        u32 maxDataSize;
        u32 formatLength;
        u32 dataSize;
        int err;
        char * eof;
        va_list argptr;
        u32 prosecced;

        hdr = (void*)&gBuf;
        id = (u32*)(hdr + 1);
        str = (char*)(id + 1);
        maxDataSize = 8179;
        formatLength = strlen(format);
        if (formatLength > maxDataSize) {
            eof = (void*)((-1 + maxDataSize + (u32)format));
            *(eof) = 0;
        }
        va_start(argptr, format);
        err = vsprintf(str, format, argptr);
        if (strlen(str) < maxDataSize) {
            str[strlen(str)] = 0;
        } else {
            err = -1;
        }
        if (err < 0) {
            return 0;
        }
        hdr->length = strlen(str) + 0xD;
        hdr->rsvd = 0;
        hdr->protocol = 0x210;
        dataSize = OSRoundUp32B(hdr->length) & ~1;
        if ((0x2000 - (gBufTail - gBufHead)) <= dataSize) {
            ttyFlush(gPrintfID, 1);
        }
        gPrintfID += 1;
        gPrintfID = (u8) gPrintfID;
        *id = gPrintfID;
        if ((0x2000 - (gBufTail & 0x1FFF)) < dataSize) {
            prosecced = 0x2000 - (gBufTail & 0x1FFF);
            ttyWrite(gBufTail & 0x1FFF, (char*)&gBuf, prosecced);
            ttyWrite(0, (char*)&gBuf + prosecced, dataSize - prosecced);
        } else {
            ttyWrite(gBufTail & 0x1FFF, (char*)&gBuf, dataSize);
        }
        gBufTail += dataSize;
        if (strchr(str, '\n') != 0U) {
            ttyFlush(gPrintfID, 1);
        } else if (gPrintfID == 0xFF) {
            ttyFlush(gPrintfID, 1);
        }
        va_end(format);
        return 1;
    }
    return 0;
}

static int ttyWrite(u32 offset, void *data, long size) {
    if (MCCWrite(gChID, offset, data, size, 0)) {
        return 1;
    }
    return 0;
}

static int ttyFlush(u32 msgID, int waitResult) {
    u32 notify;

    notify = msgID | 0x300000;

    if ((gBufTail - gBufHead) == 0) {
        return 1;
    }
    if (MCCNotify(gChID, notify) == 0) {
        while(1)
            ;
    }
    if (waitResult != 0) {
        do {} while (gReadDone != msgID);
    }
    return 1;
}
