/* MetroTRK target C fragment; see docs/notes/MetroTRK-targimpl.md. */
#include "targimpl_helpers.h"
typedef struct memRange { u8* start; u8* end; bool readable; bool writeable; } memRange;
const memRange gTRKMemMap[] = { { (u8*)0, (u8*)0xFFFFFFFF, true, true } };
/* Export the original shared compiler-local template for fragment linkage. */
const TRKInstructionTemplate gTRKSPRTemplate = {{ INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP }};

static inline DSError TRKPPCAccessPairedSingleRegister(void* srcDestPtr, u32 psr, bool read)
{
    // all nop by default
    InstructionType instructionData[] = { INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP,
                                          INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP };

    if (read) {
        instructionData[0] =
            INSTR_PSQ_ST(psr, 0, 3, 0, 0); // psq_st psr, 0(r3), 0, 0
    } else {
        instructionData[0] =
            INSTR_PSQ_L(psr, 0, 3, 0, 0); // psq_l psr, 0(r3), 0, 0
    }

    return TRKPPCAccessSpecialReg(srcDestPtr, instructionData, read);
}

/* FP template shared with the preceding target-control fragment. */
const TRKInstructionTemplate gTRKFPTemplate = {{ INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP }};

#pragma dont_inline on
static DSError TRKValidMemory32(const void* addr, size_t length,
                                int readWriteable)
{
    DSError err = kInvalidMemory;
    const u8* start;
    const u8* end;
    int i;

    start = (const u8*) addr;
    end = ((const u8*) addr + (length - 1));

    if (end < start) {
        return kInvalidMemory;
    }

    for (i = 0; i < (int) (sizeof(gTRKMemMap) / sizeof(memRange)); i++) {
        if (start <= (const u8*) gTRKMemMap[i].end &&
            end >= (const u8*) gTRKMemMap[i].start)
        {
            if (((u8) readWriteable == kValidMemoryReadable &&
                 !gTRKMemMap[i].readable) ||
                ((u8) readWriteable == kValidMemoryWriteable &&
                 !gTRKMemMap[i].writeable))
            {
                err = kInvalidMemory;
            } else {
                err = kNoError;

                if (start < (const u8*) gTRKMemMap[i].start) {
                    err = TRKValidMemory32(
                        start, (u32) ((const u8*) gTRKMemMap[i].start - start),
                        readWriteable);
                }

                if (err == kNoError && end > (const u8*) gTRKMemMap[i].end) {
                    err = TRKValidMemory32(
                        (const u8*) gTRKMemMap[i].end,
                        (u32) (end - (const u8*) gTRKMemMap[i].end),
                        readWriteable);
                }
            }

            break;
        }
    }

    return err;
}
#pragma dont_inline reset

#pragma dont_inline on
DSError TRKTargetAccessMemory(void* data, u32 start, size_t* length,
                              MemoryAccessOptions accessOptions, bool read)
{
    DSError error;
    u32 uVar5;
    u32 addr;
    u32 param4;
    TRKExceptionStatus tempExceptionStatus;

    tempExceptionStatus = gTRKExceptionStatus;
    gTRKExceptionStatus.exceptionDetected = false;

    addr = TRKTargetTranslate(start);
    error =
        TRKValidMemory32((void*) addr, *length,
                         read ? kValidMemoryReadable : kValidMemoryWriteable);

    if (error != kNoError) {
        *length = 0;
    } else {
        uVar5 = __TRK_get_MSR();
        param4 = uVar5 | (gTRKCPUState.Extended1.MSR & MSR_DR);

        if (read) {
            TRK_ppc_memcpy(data, (void*) addr, *length, uVar5, param4);
        } else {
            TRK_ppc_memcpy((void*) addr, data, *length, param4, uVar5);
            TRK_flush_cache(addr, *length);
            if (start != addr) {
                TRK_flush_cache(start, *length);
            }
        }
    }

    if (gTRKExceptionStatus.exceptionDetected) {
        *length = 0;
        error = kCWDSException;
    }

    gTRKExceptionStatus = tempExceptionStatus;
    return error;
}
#pragma dont_inline reset

DSError TRKTargetAccessDefault(u32 firstRegister, u32 lastRegister,
                               MessageBuffer* b, size_t* registersLengthPtr,
                               bool read)
{
    DSError error;
    u32 count;
    u32* data;
    TRKExceptionStatus tempExceptionStatus;

    if (lastRegister > TRK_DEFAULT_XER) {
        return kInvalidRegister;
    }

    tempExceptionStatus = gTRKExceptionStatus;
    gTRKExceptionStatus.exceptionDetected = false;

    data = gTRKCPUState.Default.GPR + firstRegister;
    count = (lastRegister - firstRegister) + 1;
    *registersLengthPtr = count * sizeof(DefaultType);

    if (read) {
        error = TRKAppendBuffer_ui32(b, data, count);
    } else {
        error = TRKReadBuffer_ui32(b, data, count);
    }

    if (gTRKExceptionStatus.exceptionDetected) {
        *registersLengthPtr = 0;
        error = kCWDSException;
    }

    gTRKExceptionStatus = tempExceptionStatus;
    return error;
}

DSError TRKTargetAccessFP(u32 firstRegister, u32 lastRegister,
                          MessageBuffer* b, size_t* registerStorageSize,
                          s32 read)
{
    DSError err;
    u32 current;
    FloatType value;
    TRKExceptionStatus savedException;

    if (lastRegister > 33) {
        return kInvalidRegister;
    }

    savedException = gTRKExceptionStatus;
    gTRKExceptionStatus.exceptionDetected = 0;

    __TRK_set_MSR(__TRK_get_MSR() | 0x2000);

    current = firstRegister;
    *registerStorageSize = 0;
    err = kNoError;

    while (current <= lastRegister && err == kNoError) {
        if (read) {
            err = TRKPPCAccessFPRegister((void*) &value, current, read);

            err = TRKAppendBuffer1_ui64(b, value);
        } else {
            err = TRKReadBuffer1_ui64(b, &value);

            err = TRKPPCAccessFPRegister((void*) &value, current, read);
        }

        *registerStorageSize += sizeof(FloatType);
        current++;
    }

    if (gTRKExceptionStatus.exceptionDetected) {
        err = kCWDSException;
        *registerStorageSize = 0;
    }

    gTRKExceptionStatus = savedException;

    return err;
}

DSError TRKTargetAccessExtended1(u32 firstRegister, u32 lastRegister,
                                 MessageBuffer* b, size_t* registerStorageSize,
                                 s32 read)
{
    TRKExceptionStatus tempExceptionStatus;
    int error;
    u32* data;
    int count;

    if (lastRegister > 0x60) {
        return kInvalidRegister;
    }

    tempExceptionStatus = gTRKExceptionStatus;
    gTRKExceptionStatus.exceptionDetected = false;

    *registerStorageSize = 0;

    if (firstRegister <= lastRegister) {
        data = (u32*) &gTRKCPUState.Extended1 + firstRegister;
        count = lastRegister - firstRegister + 1;
        *registerStorageSize += count * sizeof(u32);

        if (read) {
            error = TRKAppendBuffer_ui32(b, data, count);
        } else {
            if (data <= &gTRKCPUState.Extended1.TBU &&
                (data + count - 1) >= &gTRKCPUState.Extended1.TBL)
            {
                gTRKRestoreFlags.TBR = 1;
            }

            if (data <= &gTRKCPUState.Extended1.DEC &&
                (data + count - 1) >= &gTRKCPUState.Extended1.DEC)
            {
                gTRKRestoreFlags.DEC = 1;
            }
            error = TRKReadBuffer_ui32(b, data, count);
        }
    }
    if (gTRKExceptionStatus.exceptionDetected) {
        *registerStorageSize = 0;
        error = kCWDSException;
    }

    gTRKExceptionStatus = tempExceptionStatus;
    return error;
}

DSError TRKTargetAccessExtended2(u32 firstRegister, u32 lastRegister,
                                 MessageBuffer* b, size_t* registersLengthPtr,
                                 bool read)
{
    u32 value_buf[2];
    TRKExceptionStatus savedException;
    u32 i;
    DSError err;
    u32 value_buf0[1];

    if (lastRegister > 31) {
        return kInvalidRegister;
    }

    /*
    ** Save any existing exception status and clear the exception flag.
    ** This allows detection of exceptions that occur ONLY within this
    ** function.
    */

    savedException = gTRKExceptionStatus;
    gTRKExceptionStatus.exceptionDetected = false;

    TRKPPCAccessSPR(value_buf0, SPR_HID2, true);

    value_buf0[0] |= 0xA0000000;
    TRKPPCAccessSPR(value_buf0, SPR_HID2, false);

    value_buf0[0] = 0;
    TRKPPCAccessSPR(value_buf0, SPR_GQR0, false);

    *registersLengthPtr = 0;
    err = kNoError;

    for (i = firstRegister; (i <= lastRegister) && (err == kNoError); i++) {
        if (read) {
            err = TRKPPCAccessPairedSingleRegister((u64*) value_buf, i, read);
            err = TRKAppendBuffer1_ui64(b, *(u64*) value_buf);
        } else {
            err = TRKReadBuffer1_ui64(b, (u64*) value_buf);
            err = TRKPPCAccessPairedSingleRegister((u64*) value_buf, i, read);
        }

        *registersLengthPtr += sizeof(u64);
    }

    if (gTRKExceptionStatus.exceptionDetected) {
        *registersLengthPtr = 0;
        err = kCWDSException;
    }

    gTRKExceptionStatus = savedException;

    return err;
}

DSError TRKTargetVersions(DSVersions* version)
{
    version->kernelMajor = 0;
    version->kernelMinor = 9;
    version->protocolMajor = 1;
    version->protocolMinor = 10;
    return kNoError;
}

DSError TRKTargetSupportMask(DSSupportMask* mask)
{
    mask[0][0x00] = 0x7A;
    mask[0][0x01] = 0x00;
    mask[0][0x02] = 0x4F;
    mask[0][0x03] = 0x07;
    mask[0][0x04] = 0x00;
    mask[0][0x05] = 0x00;
    mask[0][0x06] = 0x00;
    mask[0][0x07] = 0x00;
    mask[0][0x08] = 0x00;
    mask[0][0x09] = 0x00;
    mask[0][0x0A] = 0x00;
    mask[0][0x0B] = 0x00;
    mask[0][0x0C] = 0x00;
    mask[0][0x0D] = 0x00;
    mask[0][0x0E] = 0x00;
    mask[0][0x0F] = 0x00;
    mask[0][0x10] = 0x01;
    mask[0][0x11] = 0x00;
    mask[0][0x12] = 0x03;
    mask[0][0x13] = 0x00;
    mask[0][0x14] = 0x00;
    mask[0][0x15] = 0x00;
    mask[0][0x16] = 0x00;
    mask[0][0x17] = 0x00;
    mask[0][0x18] = 0x00;
    mask[0][0x19] = 0x00;
    mask[0][0x1A] = 0x03;
    mask[0][0x1B] = 0x00;
    mask[0][0x1C] = 0x00;
    mask[0][0x1D] = 0x00;
    mask[0][0x1E] = 0x00;
    mask[0][0x1F] = 0x80;
    return kNoError;
}

DSError TRKTargetCPUType(DSCPUType* cpuType)
{
    cpuType->cpuMajor = 0;
    cpuType->cpuMinor = TRKTargetCPUMinorType();
    cpuType->bigEndian = gTRKBigEndian;
    cpuType->defaultTypeSize = 4;
    cpuType->fpTypeSize = 8;
    cpuType->extended1TypeSize = 4;
    cpuType->extended2TypeSize = 8;
    return kNoError;
}

void TRKPostInterruptEvent(void)
{
    NubEventType eventType;
    NubEvent event;
    u32 inst;

    if (gTRKState.inputActivated) {
        gTRKState.inputActivated = false;
        return;
    }

    switch ((u16) (gTRKCPUState.Extended1.exceptionID & 0xFFFF)) {
    case PPC_PROGRAMERROR:
    case PPC_TRACE:
        TRKTargetReadInstruction((void*) &inst, gTRKCPUState.Default.PC);

        if (inst == SUPPORT_TRAP) {
            eventType = kSupportEvent;
        } else {
            eventType = kBreakpointEvent;
        }
        break;
    default:
        eventType = kExceptionEvent;
        break;
    }

    TRKConstructEvent(&event, eventType);
    TRKPostEvent(&event);
}

DSError TRKTargetInterrupt(NubEvent* event)
{
    DSError error = kNoError;

    switch (event->fType) {
    case kBreakpointEvent:
    case kExceptionEvent:
        if (TRKTargetCheckStep() == false) {
            TRKSetStoppedInternal(true);
            error = TRKDoNotifyStopped(kDSNotifyStopped);
        }
        break;
    default:
        break;
    }

    return error;
}

DSError TRKTargetAddStopInfo(MessageBuffer* arg0)
{
    DSError error;
    s32 data;

    error = TRKAppendBuffer1_ui32(arg0, gTRKCPUState.Default.PC);

    if (error == kNoError) {
        error = TRKTargetReadInstruction(&data, gTRKCPUState.Default.PC);
    }

    if (error == kNoError) {
        error = TRKAppendBuffer1_ui32(arg0, data);
    }

    if (error == kNoError) {
        error = TRKAppendBuffer1_ui16(
            arg0, gTRKCPUState.Extended1.exceptionID & 0xFFFF);
    }

    if (error == kNoError) {
        int i;
        for (i = 0; i < 32; i++)
            error = TRKAppendBuffer1_ui32(arg0, (u16)gTRKCPUState.Default.GPR[i]);
        for (i = 0; i < 32; i++)
            error = TRKAppendBuffer1_ui64(arg0, (u16)gTRKCPUState.Float.FPR[i]);
    }
    return error;
}

void TRKTargetAddExceptionInfo(MessageBuffer* b)
{
    DSError error;
    s32 data;

    error = TRKAppendBuffer1_ui32(b, gTRKExceptionStatus.exceptionInfo.PC);

    if (error == kNoError) {
        error = TRKTargetReadInstruction(&data,
                                         gTRKExceptionStatus.exceptionInfo.PC);
    }

    if (error == kNoError) {
        error = TRKAppendBuffer1_ui32(b, data);
    }

    if (error == kNoError) {
        TRKAppendBuffer1_ui16(b,
                              gTRKExceptionStatus.exceptionInfo.exceptionID);
    }
}
