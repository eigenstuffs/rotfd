/* MetroTRK C target control. Native exception/MSR routines stay original fallback. */
#include "targimpl_abi.h"
static inline DSError TRKTargetReadInstruction(void* data, u32 start);
static inline DSError TRKTargetEnableTrace(bool enable);
static inline bool TRKTargetStepDone(void);
static inline DSError TRKTargetDoStep(void);
static inline bool TRKTargetCheckStep(void);
static inline DSError TRKPPCAccessSPR(void* srcDestPtr, u32 spr, bool read);
static inline DSError TRKPPCAccessPairedSingleRegister(void* srcDestPtr, u32 psr, bool read);
static inline DSError TRKPPCAccessSpecialReg(void* srcDestPtr, u32* instructionData,
                               bool read);
typedef struct memRange { u8* start; u8* end; bool readable; bool writeable; } memRange;
const memRange gTRKMemMap[] = { { (u8*)0, (u8*)0xFFFFFFFF, true, true } };
/// Instruction macros
#define INSTR_NOP 0x60000000
#define INSTR_BLR 0x4E800020
#define INSTR_PSQ_ST(psr, offset, rDest, w, gqr)                              \
    (0xF0000000 | (psr << 21) | (rDest << 16) | (w << 15) | (gqr << 12) |     \
     offset)
#define INSTR_PSQ_L(psr, offset, rSrc, w, gqr)                                \
    (0xE0000000 | (psr << 21) | (rSrc << 16) | (w << 15) | (gqr << 12) |      \
     offset)
#define INSTR_STW(rSrc, offset, rDest)                                        \
    (0x90000000 | (rSrc << 21) | (rDest << 16) | offset)
#define INSTR_LWZ(rDest, offset, rSrc)                                        \
    (0x80000000 | (rDest << 21) | (rSrc << 16) | offset)
#define INSTR_STFD(fprSrc, offset, rDest)                                     \
    (0xD8000000 | (fprSrc << 21) | (rDest << 16) | offset)
#define INSTR_LFD(fprDest, offset, rSrc)                                      \
    (0xC8000000 | (fprDest << 21) | (rSrc << 16) | offset)
#define INSTR_MFSPR(rDest, spr)                                               \
    (0x7C000000 | (rDest << 21) | ((spr & 0xFE0) << 6) |                      \
     ((spr & 0x1F) << 16) | 0x2A6)
#define INSTR_MTSPR(spr, rSrc)                                                \
    (0x7C000000 | (rSrc << 21) | ((spr & 0xFE0) << 6) |                       \
     ((spr & 0x1F) << 16) | 0x3A6)


#define FP_FPSCR_ACCESS 32
#define FP_FPECR_ACCESS 33
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

static inline DSError TRKTargetReadInstruction(void* data, u32 start)
{
    DSError error = kNoError;
    size_t registersLength = sizeof(InstructionType);

    error = TRKTargetAccessMemory(data, start, &registersLength, kUserMemory,
                                  true);

    if (error == kNoError && registersLength != sizeof(InstructionType)) {
        error = kInvalidMemory;
    }

    return error;
}

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
            TRKTargetSetStopped(true);
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

static inline DSError TRKTargetEnableTrace(bool enable)
{
    if (enable) {
        gTRKCPUState.Extended1.MSR |= 0x400;
    } else {
        gTRKCPUState.Extended1.MSR &= ~0x400;
    }

    return kNoError;
}

static inline bool TRKTargetStepDone(void)
{
    bool result = true;

    if (gTRKStepStatus.active &&
        ((u16) gTRKCPUState.Extended1.exceptionID) == PPC_TRACE)
    {
        switch (gTRKStepStatus.type) {
        case kDSStepIntoCount:
            if (gTRKStepStatus.count > 0) {
                result = false;
            }
            break;
        case kDSStepIntoRange:
            if (gTRKCPUState.Default.PC >= gTRKStepStatus.rangeStart &&
                gTRKCPUState.Default.PC <= gTRKStepStatus.rangeEnd)
            {
                result = false;
            }
            break;
        default:
            break;
        }
    }

    return result;
}

static inline DSError TRKTargetDoStep(void)
{
    DSError err = kNoError;
    gTRKStepStatus.active = 1;
    TRKTargetEnableTrace(true);

    if ((gTRKStepStatus.type == kDSStepIntoCount) ||
        (gTRKStepStatus.type == kDSStepOverCount))
    {
        gTRKStepStatus.count--;
    }

    TRKTargetSetStopped(false);

    return err;
}

static inline bool TRKTargetCheckStep(void)
{
    if (gTRKStepStatus.active) {
        TRKTargetEnableTrace(false);

        if (TRKTargetStepDone()) {
            gTRKStepStatus.active = false;
        } else {
            TRKTargetDoStep();
        }
    }

    return gTRKStepStatus.active;
}

DSError TRKTargetSingleStep(u32 count, bool stepOver)
{
    DSError err = kNoError;

    if (stepOver) {
        err = kUnsupportedError;
    } else {
        gTRKStepStatus.type = kDSStepIntoCount;
        gTRKStepStatus.count = count;

        err = TRKTargetDoStep();
    }

    return err;
}

DSError TRKTargetStepOutOfRange(u32 rangeStart, u32 rangeEnd, bool stepOver)
{
    DSError error = kNoError;

    if (stepOver) {
        // Stepping over isn't supported for PowerPC
        error = kUnsupportedError;
    } else {
        gTRKStepStatus.type = kDSStepIntoRange;
        gTRKStepStatus.rangeStart = rangeStart;
        gTRKStepStatus.rangeEnd = rangeEnd;

        error = TRKTargetDoStep();
    }

    return error;
}

u32 TRKTargetGetPC(void)
{
    return gTRKCPUState.Default.PC;
}

DSError TRKTargetSupportRequest(void)
{
    DSError err;
    size_t* length;
    u32 command;
    u8 io_result;
    NubEvent event;

    command = (u8) gTRKCPUState.Default.GPR[3];

    if ((command != kDSReadFile) && (command != kDSWriteFile) &&
        (command != kDSOpenFile) && (command != kDSCloseFile) &&
        (command != kDSPositionFile)) {
        TRKConstructEvent(&event, kExceptionEvent);
        TRKPostEvent(&event);
        return kNoError;
    }

    if (command == kDSOpenFile) {
        err = HandleOpenFileSupportRequest((const char*)gTRKCPUState.Default.GPR[4], (u8)gTRKCPUState.Default.GPR[5], (u32*)gTRKCPUState.Default.GPR[6], &io_result);
        if (io_result == kDSIONoError && err != kNoError) io_result = kDSIOError;
        gTRKCPUState.Default.GPR[3] = (DefaultType)io_result;
    } else if (command == kDSCloseFile) {
        err = HandleCloseFileSupportRequest(gTRKCPUState.Default.GPR[4], &io_result);
        if (io_result == kDSIONoError && err != kNoError) io_result = kDSIOError;
        gTRKCPUState.Default.GPR[3] = (DefaultType)io_result;
    } else if (command == kDSPositionFile) {
        err = HandlePositionFileSupportRequest(gTRKCPUState.Default.GPR[4], gTRKCPUState.Default.GPR[5], (u8)gTRKCPUState.Default.GPR[6], &io_result);
        if (io_result == kDSIONoError && err != kNoError) io_result = kDSIOError;
        gTRKCPUState.Default.GPR[3] = (DefaultType)io_result;
    } else {
    length = (size_t*) gTRKCPUState.Default.GPR[5];

    err = TRKSuppAccessFile((u8) gTRKCPUState.Default.GPR[4],
                            (u8*) gTRKCPUState.Default.GPR[6], length,
                            &io_result, 1, (command == kDSReadFile));

    if ((io_result == kDSIONoError) && (err != kNoError)) {
        io_result = kDSIOError;
    }

    gTRKCPUState.Default.GPR[3] = (DefaultType) io_result;

    if (command == kDSReadFile) {
        TRK_flush_cache((u32) gTRKCPUState.Default.GPR[6], *length);
    }

    }

    gTRKCPUState.Default.PC += 4;
    return err;
}

DSError TRKTargetFlushCache(u8 arg0, u32 arg1, u32 arg2)
{
    if (arg1 < arg2) {
        TRK_flush_cache(arg1, arg2 - arg1);
        return kNoError;
    }

    return kInvalidMemory;
}

bool TRKTargetStopped(void)
{
    return gTRKState.stopped;
}

void TRKTargetSetStopped(bool val)
{
    gTRKState.stopped = val;
}

DSError TRKTargetStop(void)
{
    TRKTargetSetStopped(true);
    return kNoError;
}

static inline DSError TRKPPCAccessSPR(void* srcDestPtr, u32 spr, bool read)
{
    // all nop by default
    InstructionType instructionData[] = { INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP,
                                          INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP };

    if (read) {
        instructionData[0] = INSTR_MFSPR(4, spr); // mfspr r4, spr
        instructionData[1] = INSTR_STW(4, 0, 3);  // stw r4, 0(r3)
    } else {
        instructionData[0] = INSTR_LWZ(4, 0, 3);  // lwz r4, 0(r3)
        instructionData[1] = INSTR_MTSPR(spr, 4); // mtspr spr, r4
    }

    return TRKPPCAccessSpecialReg(srcDestPtr, instructionData, read);
}

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

#pragma dont_inline on
DSError TRKPPCAccessFPRegister(void* srcDestPtr, u32 fpr, bool read)
{
    DSError error = kNoError;
    // all nop by default
    InstructionType instructionData1[] = { INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP,
                                           INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP, INSTR_NOP };

    if (fpr < FP_FPSCR_ACCESS) {
        if (read) {
            instructionData1[0] = INSTR_STFD(fpr, 0, 3); // stfd fpr, 0(r3)
        } else {
            instructionData1[0] = INSTR_LFD(fpr, 0, 3); // lfd fpr, 0(r3)
        }

        error = TRKPPCAccessSpecialReg(srcDestPtr, instructionData1, read);
    } else if (fpr == FP_FPSCR_ACCESS) {
        *(u64*) srcDestPtr &= 0xFFFFFFFF;
    } else if (fpr == FP_FPECR_ACCESS) {
        if (!read) {
            *(u32*) srcDestPtr = *(u32*) ((u32) srcDestPtr + 4);
        }

        error = TRKPPCAccessSPR(srcDestPtr, SPR_FPECR, read);

        if (read) {
            DSFetch_u64(srcDestPtr) = DSFetch_u32(srcDestPtr) & 0xFFFFFFFFLL;
        }
    }

    return error;
}
#pragma dont_inline reset

static inline DSError TRKPPCAccessSpecialReg(void* srcDestPtr, u32* instructionData,
                               bool read)
{
    instructionData[9] = INSTR_BLR; // Set the last entry as blr
    TRK_flush_cache((u32) instructionData, 0x28);
    // Call the instruction data array as code
    ((RegAccessFunc) instructionData)(srcDestPtr, TRKvalue128_temp);
    return kNoError;
}

void TRKTargetSetInputPendingPtr(u8* ptr)
{
    gTRKState.inputPendingPtr = ptr;
}
