/* MetroTRK protocol ABI. Reference provenance is recorded in the unit note. */
#ifndef ROTFD_TRK_MSGHNDLR_ABI_H
#define ROTFD_TRK_MSGHNDLR_ABI_H
#include "trk_abi.h"
typedef signed long s32;
#define ATTRIBUTE_ALIGN(n) __attribute__((aligned(n)))
typedef enum MessageCommandID {
    kDSPing = 0x00,
    kDSConnect = 0x01,
    kDSDisconnect = 0x02,
    kDSReset = 0x03,
    kDSVersions = 0x04,
    kDSSupportMask = 0x05,
    kDSOverride = 0x07,
    kDSReadMemory = 0x10,
    kDSWriteMemory = 0x11,
    kDSReadRegisters = 0x12,
    kDSWriteRegisters = 0x13,
    kDSSetOption = 0x17,
    kDSContinue = 0x18,
    kDSStep = 0x19,
    kDSStop = 0x1A,
    kDSReplyACK = 0x80,
    kDSReplyNAK = 0xFF,
    kDSNotifyStopped = 0x90,
    kDSNotifyException = 0x91,
    kDSWriteFile = 0xD0,
    kDSReadFile = 0xD1,
    kDSOpenFile = 0xD2,
    kDSCloseFile = 0xD3,
    kDSPositionFile = 0xD4
} MessageCommandID;
typedef enum {
    kDSStepIntoCount = 0x00, /* Exec count instructions & stop */
    kDSStepIntoRange = 0x01, /* Exec until PC is out of specified range */
    kDSStepOverCount = 0x10, /* Step over 1*count instructions & stop */
    kDSStepOverRange = 0x11  /* Step over until PC is out of specified range */
} DSMessageStepOptions;
typedef enum DSReplyError {
    kDSReplyNoError = 0x00,
    kDSReplyError = 0x01,
    kDSReplyPacketSizeError = 0x02,
    kDSReplyCWDSError = 0x03,
    kDSReplyEscapeError = 0x04,
    kDSReplyBadFCS = 0x05,
    kDSReplyOverflow = 0x06,
    kDSReplySequenceMissing = 0x07,
    kDSReplyUnsupportedCommandError = 0x10,
    kDSReplyParameterError = 0x11,
    kDSReplyUnsupportedOptionError = 0x12,
    kDSReplyInvalidMemoryRange = 0x13,
    kDSReplyInvalidRegisterRange = 0x14,
    kDSReplyCWDSException = 0x15,
    kDSReplyNotStopped = 0x16,
    kDSReplyBreakpointsFull = 0x17,
    kDSReplyBreakpointConflict = 0x18,
    kDSReplyOsError = 0x20,
    kDSReplyInvalidProcessId = 0x21,
    kDSReplyInvalidThreadId = 0x22,
    kDSDebugSecurityError = 0x23
} DSReplyError;
typedef u8 DSSupportMask[32];
enum { kInvalidMemory=0x700, kInvalidRegister=0x701, kCWDSException=0x702, kUnsupportedError=0x703, kInvalidProcessId=0x704, kInvalidThreadId=0x705, kOsError=0x706 };
typedef enum MemoryAccessOptions {
    kUserMemory = 0,
    kDebuggerMemory = 1
} MemoryAccessOptions;
typedef struct DSVersions {
    /* 0x00 */ u8 kernelMajor;
    /* 0x01 */ u8 kernelMinor;
    /* 0x02 */ u8 protocolMajor;
    /* 0x03 */ u8 protocolMinor;
} DSVersions;
typedef struct DSCPUType {
    /* 0x00 */ u8 cpuMajor;
    /* 0x01 */ u8 cpuMinor;
    /* 0x02 */ u8 bigEndian;
    /* 0x03 */ u8 defaultTypeSize;
    /* 0x04 */ u8 fpTypeSize;
    /* 0x05 */ u8 extended1TypeSize;
    /* 0x06 */ u8 extended2TypeSize;
} DSCPUType;
DSError TRKTargetAccessMemory(void*, u32, size_t*, MemoryAccessOptions, bool);
DSError TRKTargetAccessDefault(u32, u32, MessageBuffer*, size_t*, bool);
DSError TRKTargetAccessFP(u32 firstRegister, u32 lastRegister,
                          MessageBuffer* b, size_t* registerStorageSize,
                          s32 read);
DSError TRKTargetAccessExtended1(u32 firstRegister, u32 lastRegister,
                                 MessageBuffer* b, size_t* registerStorageSize,
                                 s32 read);
DSError TRKTargetAccessExtended2(u32, u32, MessageBuffer*, size_t*, bool);
DSError TRKTargetVersions(DSVersions*);
DSError TRKTargetSupportMask(DSSupportMask*);
DSError TRKTargetSingleStep(u32, bool);
DSError TRKTargetStepOutOfRange(u32, u32, bool);
u32 TRKTargetGetPC(void);
DSError TRKTargetFlushCache(u8, u32, u32);
DSError TRKTargetStop(void);
DSError TRKTargetCPUType(DSCPUType* cpuType);
extern DSError TRKMessageSend(MessageBuffer*);
extern DSError TRKSetBufferPosition(MessageBuffer*, u32);
extern DSError TRKReadBuffer1_ui16(MessageBuffer*, u16*);
extern DSError TRKAppendBuffer1_ui16(MessageBuffer*, u16);
extern void TRKConstructEvent(NubEvent*, NubEventType);
extern DSError TRKPostEvent(NubEvent*);
extern void SetUseSerialIO(u8);
static inline DSError TRKAppendBuffer1_ui8(MessageBuffer* buffer, const u8 data)
{
    if (buffer->fPosition >= kMessageBufferSize) return kMessageBufferOverflow;
    buffer->fData[buffer->fPosition++] = data;
    buffer->fLength++;
    return kNoError;
}
#endif
