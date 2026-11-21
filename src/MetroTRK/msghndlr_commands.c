/* MetroTRK command handlers including target-memory reads.
 * Read and write error tables share their original contiguous allocation. */
#include "msghndlr_helpers.h"

static inline DSError TRKStandardACK(MessageBuffer* b, MessageCommandID commandId,
                       DSReplyError replyError)
{
    TRKMessageIntoReply(b, commandId, replyError);
    return TRKSendACK(b);
}
DSError fn_8011A8B4(MessageBuffer* buf)
{
    u8 buffer[0x800];
    u32 spC;
    size_t sp10;
    /* The target-memory API exchanges the count through stack state. The
     * native handler stores the returned count and reads it after testing
     * the API result, so retain that observable stack-state read. */
    volatile u16 spA;
    u8 sp8;
    u8 sp9;
    DSReplyError reply;
    DSError error;

    if (buf->fLength != 8) {
        return TRKStandardACK(buf, kDSReplyACK, kDSReplyPacketSizeError);
    }

    TRKSetBufferPosition(buf, 0);

    error = TRKReadBuffer1_ui8(buf, &sp8);

    if (error == kNoError) {
        error = TRKReadBuffer1_ui8(buf, &sp9);
    }

    if (error == kNoError) {
        error = TRKReadBuffer1_ui16(buf, (u16*)&spA);
    }

    if (error == kNoError) {
        error = TRKReadBuffer1_ui32(buf, &spC);
    }

    if (sp9 & 2) {
        return TRKStandardACK(buf, kDSReplyACK,
                              kDSReplyUnsupportedOptionError);
    }

    if (spA > sizeof(buffer)) {
        return TRKStandardACK(buf, kDSReplyACK, kDSReplyParameterError);
    }

    TRKMessageIntoReply(buf, kDSReplyACK, kDSReplyNoError);
    if (error == kNoError) {
        sp10 = spA;
        error = TRKTargetAccessMemory(
            buffer, spC, &sp10, sp9 & 8 ? kUserMemory : kDebuggerMemory, 1);
        spA = sp10;

        if (error == kNoError) {
            error = TRKAppendBuffer1_ui16(buf, spA);
        }

        if (error == kNoError) {
            error = TRKAppendBuffer(buf, buffer, sp10);
        }
    }

    if (error != kNoError) {
        switch (error) {
        case kCWDSException:
            reply = kDSReplyCWDSException;
            break;
        case kInvalidMemory:
            reply = kDSReplyInvalidMemoryRange;
            break;
        case kInvalidProcessId:
            reply = kDSReplyInvalidProcessId;
            break;
        case kInvalidThreadId:
            reply = kDSReplyInvalidThreadId;
            break;
        case kOsError:
            reply = kDSReplyOsError;
            break;
        default:
            reply = kDSReplyCWDSError;
            break;
        }

        return TRKStandardACK(buf, kDSReplyACK, reply);
    }

    return TRKSendACK(buf);
}


DSError TRKDoWriteMemory(MessageBuffer* b)
{
    u8 buffer[0x800];
    u32 spC;
    size_t sp10;
    u16 spA;
    u8 sp8;
    u8 sp9;
    DSReplyError reply;
    DSError error;

    if (b->fLength <= 8) {
        return TRKStandardACK(b, kDSReplyACK, kDSReplyPacketSizeError);
    }

    TRKSetBufferPosition(b, 0);

    error = TRKReadBuffer1_ui8(b, &sp8);

    if (error == kNoError) {
        error = TRKReadBuffer1_ui8(b, &sp9);
    }

    if (error == kNoError) {
        error = TRKReadBuffer1_ui16(b, &spA);
    }

    if (error == kNoError) {
        error = TRKReadBuffer1_ui32(b, &spC);
    }

    if (sp9 & 2) {
        return TRKStandardACK(b, kDSReplyACK, kDSReplyUnsupportedOptionError);
    }

    if (b->fLength != spA + 8 || spA > sizeof(buffer)) {
        return TRKStandardACK(b, kDSReplyACK, kDSReplyParameterError);
    }

    if (error == kNoError) {
        sp10 = spA;
        error = TRKReadBuffer(b, buffer, sp10);

        if (error == kNoError) {
            error = TRKTargetAccessMemory(
                buffer, spC, &sp10, sp9 & 8 ? kUserMemory : kDebuggerMemory,
                0);
        }

        spA = sp10;
    }

    if (error == kNoError) {
        TRKMessageIntoReply(b, kDSReplyACK, kDSReplyNoError);
    }

    if (error == kNoError) {
        error = TRKAppendBuffer1_ui16(b, spA);
    }

    if (error != kNoError) {
        switch (error) {
        case kCWDSException:
            reply = kDSReplyCWDSException;
            break;
        case kInvalidMemory:
            reply = kDSReplyInvalidMemoryRange;
            break;
        case kInvalidProcessId:
            reply = kDSReplyInvalidProcessId;
            break;
        case kInvalidThreadId:
            reply = kDSReplyInvalidThreadId;
            break;
        case kOsError:
            reply = kDSReplyOsError;
            break;
        default:
            reply = kDSReplyCWDSError;
            break;
        }

        return TRKStandardACK(b, kDSReplyACK, reply);
    }

    return TRKSendACK(b);
}

DSError TRKDoReadRegisters(MessageBuffer* b)
{
    size_t sp10;
    u16 spA;
    u16 spC;
    u8 sp8;
    u8 sp9;
    DSError error;
    DSReplyError reply;

    if (b->fLength != 6) {
        return TRKStandardACK(b, kDSReplyACK, kDSReplyPacketSizeError);
    }

    TRKSetBufferPosition(b, 0);

    error = TRKReadBuffer1_ui8(b, &sp8);

    if (error == kNoError) {
        error = TRKReadBuffer1_ui8(b, &sp9);
    }

    if (error == kNoError) {
        error = TRKReadBuffer1_ui16(b, &spA);
    }

    if (error == kNoError) {
        error = TRKReadBuffer1_ui16(b, &spC);
    }

    if (spA > spC) {
        return TRKStandardACK(b, kDSReplyACK, kDSReplyInvalidRegisterRange);
    }

    if (error == kNoError) {
        TRKMessageIntoReply(b, kDSReplyACK, kDSReplyNoError);
    }

    switch (sp9 & 7) {
    case 0:
        error = TRKTargetAccessDefault((u32) spA, (u32) spC, b, &sp10, 1);
        break;
    case 1:
        error = TRKTargetAccessFP((u32) spA, (u32) spC, b, &sp10, 1);
        break;
    case 2:
        error = TRKTargetAccessExtended1((u32) spA, (u32) spC, b, &sp10, 1);
        break;
    case 3:
        error = TRKTargetAccessExtended2((u32) spA, (u32) spC, b, &sp10, 1);
        break;
    default:
        error = kUnsupportedError;
        break;
    }

    if (error != kNoError) {
        switch (error) {
        case kUnsupportedError:
            reply = kDSReplyUnsupportedOptionError;
            break;
        case kInvalidRegister:
            reply = kDSReplyInvalidRegisterRange;
            break;
        case kCWDSException:
            reply = kDSReplyCWDSException;
            break;
        case kInvalidProcessId:
            reply = kDSReplyInvalidProcessId;
            break;
        case kInvalidThreadId:
            reply = kDSReplyInvalidThreadId;
            break;
        case kOsError:
            reply = kDSReplyOsError;
            break;
        default:
            reply = kDSReplyCWDSError;
            break;
        }

        return TRKStandardACK(b, kDSReplyACK, reply);
    }

    return TRKSendACK(b);
}

DSError TRKDoWriteRegisters(MessageBuffer* b)
{
    size_t sp10;
    u16 spA;
    u16 spC;
    u8 sp8;
    u8 sp9;
    DSError error;
    DSReplyError reply;

    if (b->fLength <= 6) {
        return TRKStandardACK(b, kDSReplyACK, kDSReplyPacketSizeError);
    }

    TRKSetBufferPosition(b, 0);

    error = TRKReadBuffer1_ui8(b, &sp8);

    if (error == kNoError) {
        error = TRKReadBuffer1_ui8(b, &sp9);
    }

    if (error == kNoError) {
        error = TRKReadBuffer1_ui16(b, &spA);
    }

    if (error == kNoError) {
        error = TRKReadBuffer1_ui16(b, &spC);
    }

    if (spA > spC) {
        return TRKStandardACK(b, kDSReplyACK, kDSReplyInvalidRegisterRange);
    }

    switch (sp9) {
    case 0:
        error = TRKTargetAccessDefault((u32) spA, (u32) spC, b, &sp10, 0);
        break;
    case 1:
        error = TRKTargetAccessFP((u32) spA, (u32) spC, b, &sp10, 0);
        break;
    case 2:
        error = TRKTargetAccessExtended1((u32) spA, (u32) spC, b, &sp10, 0);
        break;
    case 3:
        error = TRKTargetAccessExtended2((u32) spA, (u32) spC, b, &sp10, 0);
        break;
    default:
        error = kUnsupportedError;
        break;
    }

    if (error == kNoError) {
        TRKMessageIntoReply(b, kDSReplyACK, kDSReplyNoError);
    }

    if (error != kNoError) {
        switch (error) {
        case kUnsupportedError:
            reply = kDSReplyUnsupportedOptionError;
            break;
        case kInvalidRegister:
            reply = kDSReplyInvalidRegisterRange;
            break;
        case kMessageBufferReadError:
            reply = kDSReplyPacketSizeError;
            break;
        case kCWDSException:
            reply = kDSReplyCWDSException;
            break;
        case kInvalidProcessId:
            reply = kDSReplyInvalidProcessId;
            break;
        case kInvalidThreadId:
            reply = kDSReplyInvalidThreadId;
            break;
        case kOsError:
            reply = kDSReplyOsError;
            break;
        default:
            reply = kDSReplyCWDSError;
            break;
        }

        return TRKStandardACK(b, kDSReplyACK, reply);
    }

    return TRKSendACK(b);
}

DSError TRKDoFlushCache(MessageBuffer* b)
{
    u32 spC;
    u32 sp10;
    u8 sp8;
    u8 sp9;
    DSReplyError reply;
    DSError error;

    if (b->fLength != 0xA) {
        return TRKStandardACK(b, kDSReplyACK, kDSReplyPacketSizeError);
    }

    TRKSetBufferPosition(b, 0);
    error = TRKReadBuffer1_ui8(b, &sp8);

    if (error == kNoError) {
        error = TRKReadBuffer1_ui8(b, &sp9);
    }

    if (error == kNoError) {
        error = TRKReadBuffer1_ui32(b, &spC);
    }

    if (error == kNoError) {
        error = TRKReadBuffer1_ui32(b, &sp10);
    }

    if (spC > sp10) {
        return TRKStandardACK(b, kDSReplyACK, kDSReplyInvalidMemoryRange);
    }

    if (error == kNoError) {
        error = TRKTargetFlushCache(sp9, spC, sp10);
    }

    if (error == kNoError) {
        TRKMessageIntoReply(b, kDSReplyACK, kDSReplyNoError);
    }

    if (error != kNoError) {
        switch (error) {
        case kUnsupportedError:
            reply = kDSReplyUnsupportedOptionError;
            break;
        default:
            reply = kDSReplyCWDSError;
            break;
        }

        return TRKStandardACK(b, kDSReplyACK, reply);
    }

    return TRKSendACK(b);
}

DSError TRKDoContinue(MessageBuffer* b)
{
    DSError result;

    if (!TRKTargetStopped()) {
        result = TRKStandardACK(b, kDSReplyACK, kDSReplyNotStopped);
    } else {
        result = TRKStandardACK(b, kDSReplyACK, kDSReplyNoError);

        if (result == kNoError) {
            result = TRKTargetContinue();
        }
    }

    return result;
}

DSError TRKDoStep(MessageBuffer* b)
{
    DSError error;
    u32 spC;
    size_t sp10;
    u8 sp8;
    u8 sp9;
    u8 spA;
    u32 pc;

    if (b->fLength < 3) {
        return TRKStandardACK(b, kDSReplyACK, kDSReplyPacketSizeError);
    }

    TRKSetBufferPosition(b, 0);

    error = TRKReadBuffer1_ui8(b, &sp8);

    if (error == kNoError) {
        error = TRKReadBuffer1_ui8(b, &sp9);
    }

    switch (sp9) {
    case kDSStepIntoCount:
    case kDSStepOverCount:
        if (error == kNoError) {
            TRKReadBuffer1_ui8(b, &spA);
        }

        if (spA < 1) {
            return TRKStandardACK(b, kDSReplyACK, kDSReplyParameterError);
        }
        break;
    case kDSStepIntoRange:
    case kDSStepOverRange:
        if (b->fLength != 0xA) {
            return TRKStandardACK(b, kDSReplyACK, kDSReplyPacketSizeError);
        }

        if (error == kNoError) {
            error = TRKReadBuffer1_ui32(b, &spC);
        }

        if (error == kNoError) {
            TRKReadBuffer1_ui32(b, &sp10);
        }

        pc = TRKTargetGetPC();
        if (pc < spC || pc > sp10) {
            return TRKStandardACK(b, kDSReplyACK, kDSReplyParameterError);
        }
        break;
    default:
        return TRKStandardACK(b, kDSReplyACK, kDSReplyUnsupportedOptionError);
    }

    if (!TRKTargetStopped()) {
        return TRKStandardACK(b, kDSReplyACK, kDSReplyNotStopped);
    }

    error = TRKStandardACK(b, kDSReplyACK, kDSReplyNoError);

    if (error == kNoError) {
        switch (sp9) {
        case kDSStepIntoCount:
        case kDSStepOverCount:
            error = TRKTargetSingleStep(spA, sp9 == kDSStepOverCount);
            break;
        case kDSStepIntoRange:
        case kDSStepOverRange:
            error =
                TRKTargetStepOutOfRange(spC, sp10, sp9 == kDSStepOverRange);
            break;
        default:
            break;
        }
    }

    return error;
}

DSError TRKDoStop(MessageBuffer* b)
{
    enum DSReplyError reply;

    switch (TRKTargetStop()) {
    case kNoError:
        reply = kDSReplyNoError;
        break;
    case kInvalidProcessId:
        reply = kDSReplyInvalidProcessId;
        break;
    case kInvalidThreadId:
        reply = kDSReplyInvalidThreadId;
        break;
    case kOsError:
        reply = kDSReplyOsError;
        break;
    default:
        reply = kDSReplyError;
        break;
    }

    return TRKStandardACK(b, kDSReplyACK, reply);
}

DSError TRKDoSetOption(MessageBuffer* b)
{
    u8 command = 0;
    u8 option = 0;
    u8 enable = 0;
    DSError error;
    TRKSetBufferPosition(b, 0);
    error = TRKReadBuffer1_ui8(b, &command);
    if (error == kNoError) error = TRKReadBuffer1_ui8(b, &option);
    if (error == kNoError) error = TRKReadBuffer1_ui8(b, &enable);
    if (error != kNoError) {
        TRKStandardACK(b, kDSReplyACK, kDSReplyError);
    } else if (option == 1) {
        SetUseSerialIO(enable);
    }
    return TRKStandardACK(b, kDSReplyACK, kDSReplyNoError);
}
