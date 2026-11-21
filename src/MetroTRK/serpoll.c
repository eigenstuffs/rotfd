/* MetroTRK serial framing and event input. See docs/notes/MetroTRK-serpoll.md. */
#include "trk_abi.h"

typedef enum ReceiverState { kWaitFlag, kFoundFlag, kInFrame, kFrameOverflow } ReceiverState;
typedef struct FramingState {
    MessageBufferID fBufferID;
    MessageBuffer *fBuffer;
    u8 fReceiveState;
    int fEscape;
    u8 fFCS;
} FramingState;
static FramingState gTRKFramingState;
u8 *gTRKInputPendingPtr;

extern DSError TRKReadUART1(signed char *);
extern DSError TRKGetFreeBuffer(int *, MessageBuffer **);
extern DSError TRKStandardACK(MessageBuffer *, int, int);
extern DSError TRKSetBufferPosition(MessageBuffer *, u32);
extern void TRKConstructEvent(NubEvent *, int);
extern DSError TRKPostEvent(NubEvent *);
void TRKProcessInput(MessageBufferID);

static inline DSError TRKAppendInputByte(MessageBuffer *buffer, const u8 data)
{
    if (buffer->fPosition >= kMessageBufferSize) return kMessageBufferOverflow;
    buffer->fData[buffer->fPosition++] = data;
    buffer->fLength++;
    return kNoError;
}

static inline void TRKDiscardFrame(void)
{
    if (gTRKFramingState.fBufferID != -1) {
        TRKReleaseBuffer(gTRKFramingState.fBufferID);
        gTRKFramingState.fBufferID = -1;
    }
    gTRKFramingState.fBuffer = NULL;
    gTRKFramingState.fReceiveState = kWaitFlag;
}

static inline bool TRKCheckPacket(void)
{
    MessageBuffer *buffer = gTRKFramingState.fBuffer;
    if (buffer->fLength < 2) {
        TRKStandardACK(buffer, 0xFF, 2);
        TRKDiscardFrame();
        return false;
    }
    buffer->fPosition = 0;
    buffer->fLength--;
    return true;
}

MessageBufferID TRKTestForPacket(void)
{
    signed char byte;
    DSError error = kNoError;
    DSError readError = TRKReadUART1(&byte);
    while (readError == kNoError && error == kNoError) {
        if (gTRKFramingState.fReceiveState != kInFrame) {
            gTRKFramingState.fEscape = false;
        }
        switch (gTRKFramingState.fReceiveState) {
        case kWaitFlag:
            if (byte == 0x7E) {
                error = TRKGetFreeBuffer(&gTRKFramingState.fBufferID, &gTRKFramingState.fBuffer);
                gTRKFramingState.fFCS = 0;
                gTRKFramingState.fReceiveState = kFoundFlag;
            }
            break;
        case kFoundFlag:
            if (byte == 0x7E) break;
            gTRKFramingState.fReceiveState = kInFrame;
            /* fall through */
        case kInFrame:
            if (byte == 0x7E) {
                if (gTRKFramingState.fEscape) {
                    TRKStandardACK(gTRKFramingState.fBuffer, 0xFF, 4);
                    TRKDiscardFrame();
                } else {
                    if (TRKCheckPacket()) {
                        MessageBufferID id = gTRKFramingState.fBufferID;
                        gTRKFramingState.fBufferID = -1;
                        gTRKFramingState.fBuffer = NULL;
                        gTRKFramingState.fReceiveState = kWaitFlag;
                        return id;
                    }
                    gTRKFramingState.fReceiveState = kWaitFlag;
                }
            } else {
                if (gTRKFramingState.fEscape) {
                    byte ^= 0x20;
                    gTRKFramingState.fEscape = false;
                } else if (byte == 0x7D) {
                    gTRKFramingState.fEscape = true;
                    break;
                }
                error = TRKAppendInputByte(gTRKFramingState.fBuffer, byte);
                gTRKFramingState.fFCS += (u8)byte;
            }
            break;
        case kFrameOverflow:
            if (byte == 0x7E) TRKDiscardFrame();
            break;
        }
        readError = TRKReadUART1(&byte);
    }
    return -1;
}

void TRKGetInput(void)
{
    MessageBuffer *msgbuffer;
    MessageBufferID bufID;
    u8 command;
    bufID = TRKTestForPacket();
    if (bufID != -1) {
        msgbuffer = TRKGetBuffer(bufID);
        TRKSetBufferPosition(msgbuffer, 0);
        TRKReadBuffer1_ui8(msgbuffer, &command);
        if (command < 0x80) TRKProcessInput(bufID);
        else TRKReleaseBuffer(bufID);
    }
}

void TRKProcessInput(MessageBufferID bufID)
{
    NubEvent event;
    TRKConstructEvent(&event, 2);
    event.fMessageBufferID = bufID;
    gTRKFramingState.fBufferID = -1;
    TRKPostEvent(&event);
}

DSError TRKInitializeSerialHandler(void)
{
    gTRKFramingState.fBufferID = -1;
    gTRKFramingState.fReceiveState = 0;
    gTRKFramingState.fEscape = 0;
    return kNoError;
}

DSError TRKTerminateSerialHandler(void)
{
    return kNoError;
}
