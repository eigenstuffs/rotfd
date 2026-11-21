/* Shared C helpers for the split MetroTRK target implementation. */
#ifndef ROTFD_TRK_TARGIMPL_HELPERS_H
#define ROTFD_TRK_TARGIMPL_HELPERS_H
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
typedef struct TRKInstructionTemplate { InstructionType words[10]; } TRKInstructionTemplate;
extern const TRKInstructionTemplate gTRKSPRTemplate;
extern const TRKInstructionTemplate gTRKFPTemplate;
static inline void TRKSetStoppedInternal(bool val) { gTRKState.stopped = val; }

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

    TRKSetStoppedInternal(false);

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

static inline DSError TRKPPCAccessSPR(void* srcDestPtr, u32 spr, bool read)
{
    // all nop by default
    TRKInstructionTemplate instructionData = gTRKSPRTemplate;

    if (read) {
        instructionData.words[0] = INSTR_MFSPR(4, spr); // mfspr r4, spr
        instructionData.words[1] = INSTR_STW(4, 0, 3);  // stw r4, 0(r3)
    } else {
        instructionData.words[0] = INSTR_LWZ(4, 0, 3);  // lwz r4, 0(r3)
        instructionData.words[1] = INSTR_MTSPR(spr, 4); // mtspr spr, r4
    }

    return TRKPPCAccessSpecialReg(srcDestPtr, instructionData.words, read);
}



static inline DSError TRKPPCAccessSpecialReg(void* srcDestPtr, u32* instructionData,
                               bool read)
{
    instructionData[9] = INSTR_BLR; // Set the last entry as blr
    TRK_flush_cache((u32) instructionData, 0x28);
    // Call the instruction data array as code
    ((RegAccessFunc) instructionData)(srcDestPtr, TRKvalue128_temp);
    return kNoError;
}

#endif
