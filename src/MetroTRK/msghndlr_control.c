/* MetroTRK exact command-handler fragment. See docs/notes/MetroTRK-msghndlr.md. */
#include "msghndlr_helpers.h"

extern void __TRK_reset(void);
static bool IsTRKConnected;
bool GetTRKConnected(void) { return IsTRKConnected; }

void SetTRKConnected(bool connected) { IsTRKConnected = connected; }

DSError TRKStandardACK(MessageBuffer* b, MessageCommandID commandId,
                       DSReplyError replyError)
{
    TRKMessageIntoReply(b, commandId, replyError);
    return TRKSendACK(b);
}

DSError TRKDoUnsupported(MessageBuffer* b)
{
    return TRKStandardACK(b, kDSReplyACK, kDSReplyUnsupportedCommandError);
}

DSError TRKDoConnect(MessageBuffer* b)
{
    SetTRKConnected(true);
    return TRKStandardACK(b, kDSReplyACK, kDSReplyNoError);
}

DSError TRKDoDisconnect(MessageBuffer* b)
{
    DSError error;
    NubEvent event;
    SetTRKConnected(false);
    error = TRKStandardACK(b, kDSReplyACK, kDSReplyNoError);

    if (error == kNoError) {
        TRKConstructEvent(&event, 1);
        TRKPostEvent(&event);
    }

    return error;
}

DSError TRKDoReset(MessageBuffer* b)
{
    TRKStandardACK(b, kDSReplyACK, kDSReplyNoError);
    __TRK_reset();
    return kNoError;
}

DSError TRKDoVersions(MessageBuffer* buf)
{
    DSVersions version;
    DSError error;

    if (buf->fLength != 1) {
        return TRKStandardACK(buf, kDSReplyACK, kDSReplyPacketSizeError);
    }

    TRKMessageIntoReply(buf, kDSReplyACK, kDSReplyNoError);
    error = TRKTargetVersions(&version);

    if (error == kNoError) {
        error = TRKAppendBuffer1_ui8(buf, version.kernelMajor);
    }

    if (error == kNoError) {
        error = TRKAppendBuffer1_ui8(buf, version.kernelMinor);
    }

    if (error == kNoError) {
        error = TRKAppendBuffer1_ui8(buf, version.protocolMajor);
    }

    if (error == kNoError) {
        error = TRKAppendBuffer1_ui8(buf, version.protocolMinor);
    }

    if (error != kNoError) {
        return TRKStandardACK(buf, kDSReplyACK, kDSReplyCWDSError);
    }

    return TRKSendACK(buf);
}

DSError TRKDoSupportMask(MessageBuffer* buf)
{
    DSSupportMask mask;
    DSError error;

    if (buf->fLength != 1) {
        return TRKStandardACK(buf, kDSReplyACK, kDSReplyPacketSizeError);
    }

    TRKMessageIntoReply(buf, kDSReplyACK, kDSReplyNoError);

    error = TRKTargetSupportMask(&mask);

    if (error == kNoError) {
        error = TRKAppendBuffer(buf, &mask, sizeof(DSSupportMask));
    }

    if (error == kNoError) {
        error = TRKAppendBuffer1_ui8(buf, 2);
    }

    if (error != kNoError) {
        return TRKStandardACK(buf, kDSReplyACK, kDSReplyCWDSError);
    }

    return TRKSendACK(buf);
}

DSError TRKDoCPUType(MessageBuffer* buf)
{
    DSError error;
    DSCPUType type;

    if (buf->fLength != 1) {
        return TRKStandardACK(buf, kDSReplyACK, kDSReplyPacketSizeError);
    }

    TRKMessageIntoReply(buf, kDSReplyACK, kDSReplyNoError);
    error = TRKTargetCPUType(&type);

    if (error == kNoError) {
        error = TRKAppendBuffer1_ui8(buf, type.cpuMajor);
    }

    if (error == kNoError) {
        error = TRKAppendBuffer1_ui8(buf, type.cpuMinor);
    }

    if (error == kNoError) {
        error = TRKAppendBuffer1_ui8(buf, type.bigEndian);
    }

    if (error == kNoError) {
        error = TRKAppendBuffer1_ui8(buf, type.defaultTypeSize);
    }

    if (error == kNoError) {
        error = TRKAppendBuffer1_ui8(buf, type.fpTypeSize);
    }

    if (error == kNoError) {
        error = TRKAppendBuffer1_ui8(buf, type.extended1TypeSize);
    }

    if (error == kNoError) {
        error = TRKAppendBuffer1_ui8(buf, type.extended2TypeSize);
    }

    if (error != kNoError) {
        return TRKStandardACK(buf, kDSReplyACK, kDSReplyCWDSError);
    }

    return TRKSendACK(buf);
}
