/* MetroTRK notify. See docs/notes/MetroTRK-notify.md. */
#include "msghndlr_abi.h"
extern DSError TRKGetFreeBuffer(int*, MessageBuffer**);
extern DSError TRKTargetAddStopInfo(MessageBuffer*);
extern void TRKTargetAddExceptionInfo(MessageBuffer*);
extern DSError TRKRequestSend(MessageBuffer*, int*, u32, u32, int);

DSError TRKDoNotifyStopped(u8 cmdId)
{
    DSError result;
    int sp8;
    int spC;
    MessageBuffer* buffer;

    result = TRKGetFreeBuffer(&spC, &buffer);

    if (result == kNoError) {
        result = TRKAppendBuffer1_ui8(buffer, cmdId);

        if (result == kNoError) {
            if (cmdId == kDSNotifyStopped) {
                TRKTargetAddStopInfo(buffer);
            } else {
                TRKTargetAddExceptionInfo(buffer);
            }
        }

        result = TRKRequestSend(buffer, &sp8, 2, 3, 1);

        if (result == kNoError) {
            TRKReleaseBuffer(sp8);
        }

        TRKReleaseBuffer(spC);
    }

    return result;
}
