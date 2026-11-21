/* MetroTRK framed message sender (TRKMessageSend, 0x80117FE4).
 *
 * Frame layout: 0x7E, payload bytes, one-byte FCS, 0x7E.  The FCS is the
 * complement of the 8-bit sum of the payload.  Payload and FCS bytes equal
 * to 0x7E or 0x7D are escaped as 0x7D followed by the byte XOR 0x20.  The
 * first writer error stops the frame; the flush runs only on success.
 */
typedef unsigned char u8;
typedef unsigned long u32;
typedef int bool;
typedef int DSError;
enum { kNoError = 0 };

typedef unsigned char FCSType;

typedef struct MessageBuffer {
    u32 fMutex;
    bool fInUse;
    u32 fLength;
    u32 fPosition;
    u8 fData[0x880];
} MessageBuffer;

#define PPP_FLAG   0x7E
#define PPP_ESCAPE 0x7D
#define PPP_TRANS  0x20

extern DSError TRKWriteUART1(signed char);
extern DSError TRKFlushUART(void);

DSError TRKMessageSend(MessageBuffer *b)
{
    FCSType fcs;
    int i;
    DSError err;
    u8 c;

    /* Compute the FCS. */
    fcs = 0;
    for (i = 0; i < b->fLength; i++)
        fcs = (FCSType)(fcs + b->fData[i]);
    fcs = fcs ^ 0xFF;

    /* Opening flag, then the escaped payload. */
    err = TRKWriteUART1(PPP_FLAG);
    if (err == kNoError) {
        for (i = 0; i < b->fLength; i++) {
            c = b->fData[i];
            if (c == PPP_FLAG || c == PPP_ESCAPE) {
                err = TRKWriteUART1(PPP_ESCAPE);
                c ^= PPP_TRANS;
                if (err != kNoError)
                    break;
            }
            err = TRKWriteUART1(c);
            if (err != kNoError)
                break;
        }
    }

    /* The escaped FCS bytes. */
    if (err == kNoError) {
        for (i = 0; i < sizeof(FCSType); i++) {
            u8 fcsByte = (u8)fcs;
            if (fcsByte == PPP_FLAG || fcsByte == PPP_ESCAPE) {
                err = TRKWriteUART1(PPP_ESCAPE);
                fcsByte ^= PPP_TRANS;
                if (err != kNoError)
                    break;
            }
            err = TRKWriteUART1(fcsByte);
            if (err != kNoError)
                break;
        }
    }

    /* Closing flag and flush. */
    if (err == kNoError)
        err = TRKWriteUART1(PPP_FLAG);
    if (err == kNoError)
        err = TRKFlushUART();
    return err;
}
