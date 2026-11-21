/* Dolphin CARDDelete. See docs/notes/CARDDelete.md. */
#include "card_abi.h"
#define OSTicksToSeconds(ticks) ((ticks) / (__OSBusClock / 4))
extern OSTime OSGetTime(void);
extern void *memcpy(void *, const void *, unsigned long);
extern void *memset(void *, int, unsigned long);
extern s32 __CARDFreeBlock(s32, u16, CARDCallback);
extern s32 __CARDGetFileNo(CARDControl *, const char *, s32 *);
extern BOOL __CARDIsOpened(CARDControl *, s32);
extern s32 __CARDAccess(CARDControl *, CARDDir *);
extern s32 __CARDIsPublic(CARDDir *);
extern s32 __CARDUpdateDir(s32, CARDCallback);

// functions
static void DeleteCallback(s32 chan, s32 result);

static void DeleteCallback(s32 chan, s32 result) {
    CARDControl *card;
    CARDCallback callback;

    card = &__CARDBlock[chan];
    callback = card->apiCallback;
    card->apiCallback = NULL;

    if (result < 0)
        goto error;

    result = __CARDFreeBlock(chan, card->startBlock, callback);
    if (result < 0)
        goto error;
    return;

error:
    __CARDPutControlBlock(card, result);
    if (callback)
        callback(chan, result);
}

s32 CARDDeleteAsync(s32 chan, char *fileName, CARDCallback callback) {
    CARDControl *card;
    s32 fileNo;
    s32 result;
    CARDDir *dir;
    CARDDir *ent;

    result = __CARDGetControlBlock(chan, &card);
    if (result < 0)
        return result;
    result = __CARDGetFileNo(card, fileName, &fileNo);
    if (result < 0)
        return __CARDPutControlBlock(card, result);
    if (__CARDIsOpened(card, fileNo))
        return __CARDPutControlBlock(card, CARD_RESULT_BUSY);

    dir = (CARDDir *)__CARDGetDirBlock(card);
    ent = &dir[fileNo];
    card->startBlock = ent->startBlock;
    memset(ent, 0xff, sizeof(CARDDir));

    card->apiCallback = callback ? callback : __CARDDefaultApiCallback;
    result = __CARDUpdateDir(chan, DeleteCallback);
    if (result < 0)
        __CARDPutControlBlock(card, result);
    return result;
}

s32 CARDDelete(s32 chan, char *fileName) {
    s32 result = CARDDeleteAsync(chan, fileName, __CARDSyncCallback);

    if (result < 0)
        return result;
    return __CARDSync(chan);
}
