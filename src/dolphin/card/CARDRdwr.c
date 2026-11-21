/* Dolphin CARD support. See docs/notes/CARDRdwr.md and reference provenance. */
#include "card_abi.h"
extern void *memcpy(void *, const void *, unsigned long);
extern void DCStoreRange(void *, u32);
extern s32 __CARDRead(s32, u32, s32, void *, CARDCallback);
extern s32 __CARDWrite(s32, u32, s32, void *, CARDCallback);


static void BlockReadCallback(s32 channel, s32 result)
{
	CARDControl* card;
	CARDCallback callback;

	card = &__CARDBlock[channel];
	if (result < 0) {
		goto error;
	}

	card->xferred += CARD_SEG_SIZE;

	card->addr += CARD_SEG_SIZE;
	(u8*)card->buffer += CARD_SEG_SIZE;
	if (--card->repeat <= 0) {
		goto error;
	}

	result = __CARDReadSegment(channel, BlockReadCallback);
	if (result < 0) {
		goto error;
	}
	return;

error:
	if (card->apiCallback == NULL) {
		__CARDPutControlBlock(card, result);
	}
	callback = card->xferCallback;
	if (callback) {
		card->xferCallback = NULL;
		callback(channel, result);
	}
}


s32 __CARDRead(s32 channel, u32 addr, s32 length, void* dst, CARDCallback callback)
{
	CARDControl* card;
	card = &__CARDBlock[channel];
	if (!card->attached) {
		return CARD_RESULT_NOCARD;
	}

	card->xferCallback = callback;
	card->repeat       = (int)(length / CARD_SEG_SIZE);
	card->addr         = addr;
	card->buffer       = dst;

	return __CARDReadSegment(channel, BlockReadCallback);
}


static void BlockWriteCallback(s32 channel, s32 result)
{
	CARDControl* card;
	CARDCallback callback;

	card = &__CARDBlock[channel];
	if (result < 0) {
		goto error;
	}

	card->xferred += CARD_PAGE_SIZE;

	card->addr += CARD_PAGE_SIZE;
	(u8*)card->buffer += CARD_PAGE_SIZE;
	if (--card->repeat <= 0) {
		goto error;
	}

	result = __CARDWritePage(channel, BlockWriteCallback);
	if (result < 0) {
		goto error;
	}
	return;

error:
	if (card->apiCallback == NULL) {
		__CARDPutControlBlock(card, result);
	}
	callback = card->xferCallback;
	if (callback) {
		card->xferCallback = NULL;
		callback(channel, result);
	}
}


s32 __CARDWrite(s32 channel, u32 addr, s32 length, void* dst, CARDCallback callback)
{
	CARDControl* card;
	card = &__CARDBlock[channel];
	if (!card->attached) {
		return CARD_RESULT_NOCARD;
	}

	card->xferCallback = callback;
	card->repeat       = (int)(length / CARD_PAGE_SIZE);
	card->addr         = addr;
	card->buffer       = dst;

	return __CARDWritePage(channel, BlockWriteCallback);
}
