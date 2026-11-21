/* MetroTRK command dispatch; table storage is owned by dispatch_data.c. */
#include "trk_abi.h"

typedef DSError (*DispatchCallback)(MessageBuffer*);

extern DSError TRKSetBufferPosition(MessageBuffer*, u32);
extern u32 lbl_8033AA70;
extern DispatchCallback lbl_802CFD60[34];

static inline u32 ReadCommand(MessageBuffer* buffer)
{
    char command;
    TRKReadBuffer1_ui8(buffer, (u8*)&command);
    return (u8)command;
}

DSError TRKDispatchMessage(MessageBuffer* buffer)
{
    DSError result = 0x500;
    u32 command;

    TRKSetBufferPosition(buffer, 0);
    command = ReadCommand(buffer);

    if ((command & 0xFF) < lbl_8033AA70) {
        result = lbl_802CFD60[(u8)command](buffer);
    }

    return result;
}
