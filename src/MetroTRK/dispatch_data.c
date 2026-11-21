/* MetroTRK dispatcher callback table and size. The dispatch loop remains
 * in original code; see docs/notes/MetroTRK-dispatch.md. */
#include "trk_abi.h"
extern DSError TRKDoUnsupported(MessageBuffer*);
extern DSError TRKDoConnect(MessageBuffer*);
extern DSError TRKDoDisconnect(MessageBuffer*);
extern DSError TRKDoReset(MessageBuffer*);
extern DSError TRKDoVersions(MessageBuffer*);
extern DSError TRKDoSupportMask(MessageBuffer*);
extern DSError TRKDoCPUType(MessageBuffer*);
extern DSError fn_8011A8B4(MessageBuffer*);
extern DSError TRKDoWriteMemory(MessageBuffer*);
extern DSError TRKDoReadRegisters(MessageBuffer*);
extern DSError TRKDoWriteRegisters(MessageBuffer*);
extern DSError TRKDoFlushCache(MessageBuffer*);
extern DSError TRKDoContinue(MessageBuffer*);
extern DSError TRKDoStep(MessageBuffer*);
extern DSError TRKDoStop(MessageBuffer*);
extern DSError TRKDoSetOption(MessageBuffer*);

u32 lbl_8033AA70;

typedef DSError (*DispatchCallback)(MessageBuffer* buf);

DispatchCallback lbl_802CFD60[] = {
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
    fn_8011A8B4,
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

