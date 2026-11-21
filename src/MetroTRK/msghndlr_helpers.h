/* Shared MetroTRK reply construction and retry logic. */
#ifndef ROTFD_TRK_MSGHNDLR_HELPERS_H
#define ROTFD_TRK_MSGHNDLR_HELPERS_H
#include "msghndlr_abi.h"
static inline void TRKMessageIntoReply(MessageBuffer* b, MessageCommandID commandId,
                         DSReplyError replyError)
{
    TRKResetBuffer(b, true);

    if (b->fPosition < kMessageBufferSize) {
        b->fData[b->fPosition++] = commandId;
        b->fLength++;
    }

    if (b->fPosition < kMessageBufferSize) {
        b->fData[b->fPosition++] = replyError;
        b->fLength++;
    }
}

static inline DSError TRKSendACK(MessageBuffer* b)
{
    DSError error;
    s32 i = 3;

    while (i > 0) {
        error = TRKMessageSend(b);
        i--;

        if (error == kNoError) {
            break;
        }
    }

    return error;
}


#endif
