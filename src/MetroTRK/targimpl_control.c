#include "targimpl_helpers.h"

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

#pragma dont_inline on
DSError TRKPPCAccessFPRegister(void* srcDestPtr, u32 fpr, bool read)
{
    DSError error = kNoError;
    // all nop by default
    TRKInstructionTemplate instructionData1 = gTRKFPTemplate;

    if (fpr < FP_FPSCR_ACCESS) {
        if (read) {
            instructionData1.words[0] = INSTR_STFD(fpr, 0, 3); // stfd fpr, 0(r3)
        } else {
            instructionData1.words[0] = INSTR_LFD(fpr, 0, 3); // lfd fpr, 0(r3)
        }

        error = TRKPPCAccessSpecialReg(srcDestPtr, instructionData1.words, read);
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

void TRKTargetSetInputPendingPtr(u8* ptr)
{
    gTRKState.inputPendingPtr = ptr;
}
