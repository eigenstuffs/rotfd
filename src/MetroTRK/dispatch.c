#include "trk_abi.h"
#define kDispatchError 0x500
extern DSError TRKSetBufferPosition(MessageBuffer*, u32);
extern DSError TRKDoUnsupported(MessageBuffer*);
extern DSError TRKDoConnect(MessageBuffer*);
extern DSError TRKDoDisconnect(MessageBuffer*);
extern DSError TRKDoReset(MessageBuffer*);
extern DSError TRKDoVersions(MessageBuffer*);
extern DSError TRKDoSupportMask(MessageBuffer*);
extern DSError TRKDoCPUType(MessageBuffer*);
extern DSError TRKDoReadMemory(MessageBuffer*);
extern DSError TRKDoWriteMemory(MessageBuffer*);
extern DSError TRKDoReadRegisters(MessageBuffer*);
extern DSError TRKDoWriteRegisters(MessageBuffer*);
extern DSError TRKDoFlushCache(MessageBuffer*);
extern DSError TRKDoContinue(MessageBuffer*);
extern DSError TRKDoStep(MessageBuffer*);
extern DSError TRKDoStop(MessageBuffer*);
extern DSError TRKDoSetOption(MessageBuffer*);

u32 gTRKDispatchTableSize;

typedef DSError (*DispatchCallback)(MessageBuffer* buf);

DispatchCallback gTRKDispatchTable[] = {
    TRKDoUnsupported,
    TRKDoConnect,
    TRKDoDisconnect,
    TRKDoReset,
    TRKDoVersions,
    TRKDoSupportMask,
    TRKDoCPUType,
    TRKDoUnsupported,
    TRKDoUnsupported,
    TRKDoUnsupported,
    TRKDoUnsupported,
    TRKDoUnsupported,
    TRKDoUnsupported,
    TRKDoUnsupported,
    TRKDoUnsupported,
    TRKDoUnsupported,
    TRKDoReadMemory,
    TRKDoWriteMemory,
    TRKDoReadRegisters,
    TRKDoWriteRegisters,
    TRKDoUnsupported,
    TRKDoUnsupported,
    TRKDoFlushCache,
    TRKDoSetOption,
    TRKDoContinue,
    TRKDoStep,
    TRKDoStop,
    TRKDoUnsupported,
    TRKDoUnsupported,
    TRKDoUnsupported,
    TRKDoUnsupported,
    TRKDoUnsupported,
    NULL,
    NULL,
};

DSError TRKInitializeDispatcher(void)
{
    gTRKDispatchTableSize = 32; // ARRAY_COUNT(gTRKDispatchTable) - 2;
    return kNoError;
}

DSError TRKDispatchMessage(MessageBuffer* buffer)
{
    DSError result = kDispatchError;
    char command;

    TRKSetBufferPosition(buffer, 0);
    TRKReadBuffer1_ui8(buffer, (u8*)&command);

    if ((command & 0xFF) < gTRKDispatchTableSize) {
        result = gTRKDispatchTable[(u8)command](buffer);
    }

    return result;
}
