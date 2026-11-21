/* MetroTRK v0.9 framed message sender, reconstructed from target control flow. */
#include "trk_abi.h"

extern DSError TRKWriteUART1(signed char);
extern DSError TRKFlushUART(void);

static inline u8 TRKMessageChecksum(u8 *data, unsigned int length)
{
    u32 checksum = 0;
    unsigned int i;
    for (i = 0; i < length; i++) {
        checksum = (u8)(checksum + data[i]);
    }
    return checksum ^ 0xFF;
}

DSError TRKMessageSend(MessageBuffer *msg)
{
    DSError error;
    u32 checksum = TRKMessageChecksum(msg->fData, msg->fLength);
    u32 i;
    u8 byte;
    error = TRKWriteUART1(0x7E);
    if (error == kNoError) {
        for (i = 0; i < msg->fLength; i++) {
            byte = msg->fData[i];
            if (byte == 0x7E || byte == 0x7D) {
                error = TRKWriteUART1(0x7D);
                byte ^= 0x20;
                if (error != kNoError) break;
            }
            error = TRKWriteUART1(byte);
            if (error != kNoError) break;
        }
    }
    do {
        if (error != kNoError) break;
        byte = checksum;
        if (byte == 0x7E || byte == 0x7D) {
            error = TRKWriteUART1(0x7D);
            byte ^= 0x20;
            if (error != kNoError) break;
        }
        error = TRKWriteUART1(byte);
        if (error != kNoError) break;
    } while (0);
    if (error == kNoError) {
        error = TRKWriteUART1(0x7E);
    }
    if (error == kNoError) {
        error = TRKFlushUART();
    }
    return error;
}
