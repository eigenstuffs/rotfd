/* MetroTRK host file support. See docs/notes/MetroTRK-support.md. */
#include "msghndlr_abi.h"
enum { kParameterError=2, kWaitACKError=0x800 };
/* Both protocol replies contain ACK, error, I/O result and a 16-bit count. */
enum { kReadFileReplyLength=5, kWriteFileReplyLength=5 };
typedef enum DSIOResult { kDSIONoError=0, kDSIOError=1, kDSIOEOF=2 } DSIOResult;
extern DSError TRKGetFreeBuffer(int*, MessageBuffer**);
extern DSError TRKAppendBuffer_ui8(MessageBuffer*, const u8*, int);
extern DSError TRKReadBuffer_ui8(MessageBuffer*, u8*, int);
extern int TRKTestForPacket(void);
extern void TRKProcessInput(int);
extern size_t strlen(const char*);
DSError TRKRequestSend(MessageBuffer*, int*, u32, u32, int);

DSError TRKSuppAccessFile(u32 file_handle, u8* data, size_t* count,
                          u8* io_result, bool need_reply, bool read)
{
    MessageBuffer* replyBuffer;
    int replyBufferId;
    u32 length;
    int bufferId;
    MessageBuffer* buffer;
    DSError error;
    u32 i;
    u16 replyLength;
    u8 replyIOResult;
    bool exit;

    if (data == NULL || *count == 0) {
        return kParameterError;
    }

    exit = false;
    *io_result = kDSIONoError;
    i = 0;
    error = kNoError;
    while (!exit && i < *count && error == kNoError && *io_result == 0) {
        if (*count - i > 0x800) {
            length = 0x800;
        } else {
            length = *count - i;
        }

        error = TRKGetFreeBuffer(&bufferId, &buffer);

        if (error == kNoError) {
            error = TRKAppendBuffer1_ui8(buffer,
                                         read ? kDSReadFile : kDSWriteFile);
        }

        if (error == kNoError) {
            error = TRKAppendBuffer1_ui32(buffer, file_handle);
        }

        if (error == kNoError) {
            error = TRKAppendBuffer1_ui16(buffer, length);
        }

        if (!read && error == kNoError) {
            error = TRKAppendBuffer_ui8(buffer, data + i, length);
        }

        if (error == kNoError) {
            if (need_reply) {
                bool interactiveRead;
                replyLength = 0;
                replyIOResult = 0;
                interactiveRead = read && file_handle == 0;

                error =
                    TRKRequestSend(buffer, &replyBufferId, read ? kReadFileReplyLength : kWriteFileReplyLength, 3,
                                       !interactiveRead);

                if (error == kNoError) {
                    replyBuffer = TRKGetBuffer(replyBufferId);
                    TRKSetBufferPosition(replyBuffer, 2);
                }

                if (error == kNoError) {
                    error = TRKReadBuffer1_ui8(replyBuffer, &replyIOResult);
                }

                if (error == kNoError) {
                    error = TRKReadBuffer1_ui16(replyBuffer, &replyLength);
                }

                if (read && error == kNoError) {
                    if (replyBuffer->fLength != replyLength + 5) {
                        replyLength = replyBuffer->fLength - 5;
                        if (replyIOResult == 0) {
                            replyIOResult = 1;
                        }
                    }

                    if (replyLength <= length) {
                        error = TRKReadBuffer_ui8(replyBuffer, data + i,
                                                  replyLength);
                    }
                }

                if (replyLength != length) {
                    if ((!read || replyLength >= length) && replyIOResult == 0)
                    {
                        replyIOResult = 1;
                    }
                    length = replyLength;
                    exit = true;
                }

                *io_result = (DSIOResult) replyIOResult;
                TRKReleaseBuffer(replyBufferId);
            } else {
                error = TRKMessageSend(buffer);
            }
        }

        TRKReleaseBuffer(bufferId);
        i += length;
    }

    *count = i;
    return error;
}

DSError TRKRequestSend(MessageBuffer* msgBuf, int* bufferId, u32 p1, u32 p2,
                       int p3)
{
    int error = kNoError;
    MessageBuffer* buffer;
    u32 timer;
    int tries;
    u8 msg_command;
    u8 msg_error;
    bool badReply = true;

    *bufferId = -1;

    for (tries = p2 + 1; tries != 0 && *bufferId == -1 && error == kNoError;
         tries--)
    {
        error = TRKMessageSend(msgBuf);
        if (error == kNoError) {
            if (p3) {
                timer = 0;
            }

            while (true) {
                do {
                    *bufferId = TRKTestForPacket();
                    if (*bufferId != -1) {
                        break;
                    }
                } while (!p3 || ++timer < 79999980);

                if (*bufferId == -1) {
                    break;
                }

                badReply = false;

                buffer = TRKGetBuffer(*bufferId);
                TRKSetBufferPosition(buffer, 0);

                if ((error = TRKReadBuffer1_ui8(buffer, &msg_command)) !=
                    kNoError)
                {
                    break;
                }

                if (msg_command >= kDSReplyACK) {
                    break;
                }

                TRKProcessInput(*bufferId);
                *bufferId = -1;
            }

            if (*bufferId != -1) {
                if (buffer->fLength < p1) {
                    badReply = true;
                }
                if (error == kNoError && !badReply) {
                    error = TRKReadBuffer1_ui8(buffer, &msg_error);
                }
                if (error == kNoError && !badReply) {
                    if (msg_command != kDSReplyACK ||
                        msg_error != kDSReplyNoError)
                    {
                        badReply = true;
                    }
                }
                if (error != kNoError || badReply) {
                    TRKReleaseBuffer(*bufferId);
                    *bufferId = -1;
                }
            }
        }
    }

    if (*bufferId == -1) {
        error = kWaitACKError;
    }

    return error;
}

DSError HandleOpenFileSupportRequest(const char* path, u8 mode, u32* handle, u8* ioResult)
{
    DSError error;
    int replyBufferId;
    int bufferId;
    MessageBuffer* replyBuffer;
    MessageBuffer* buffer;

    *handle = 0;
    error = TRKGetFreeBuffer(&bufferId, &buffer);
    if (error == kNoError) error = TRKAppendBuffer1_ui8(buffer, kDSOpenFile);
    if (error == kNoError) error = TRKAppendBuffer1_ui8(buffer, mode);
    if (error == kNoError) error = TRKAppendBuffer1_ui16(buffer, strlen(path) + 1);
    if (error == kNoError) error = TRKAppendBuffer_ui8(buffer, (const u8*)path, strlen(path) + 1);
    if (error == kNoError) {
        *ioResult = kDSIONoError;
        error = TRKRequestSend(buffer, &replyBufferId, 7, 3, 0);
        if (error == kNoError) {
            replyBuffer = TRKGetBuffer(replyBufferId);
            TRKSetBufferPosition(replyBuffer, 2);
        }
        if (error == kNoError) error = TRKReadBuffer1_ui8(replyBuffer, ioResult);
        if (error == kNoError) error = TRKReadBuffer1_ui32(replyBuffer, handle);
        TRKReleaseBuffer(replyBufferId);
    }
    TRKReleaseBuffer(bufferId);
    return error;
}

DSError HandleCloseFileSupportRequest(u32 handle, u8* ioResult)
{
    DSError error;
    int replyBufferId;
    int bufferId;
    MessageBuffer* replyBuffer;
    MessageBuffer* buffer;

    error = TRKGetFreeBuffer(&bufferId, &buffer);
    if (error == kNoError) error = TRKAppendBuffer1_ui8(buffer, kDSCloseFile);
    if (error == kNoError) error = TRKAppendBuffer1_ui32(buffer, handle);
    if (error == kNoError) {
        *ioResult = kDSIONoError;
        error = TRKRequestSend(buffer, &replyBufferId, 3, 3, 0);
        if (error == kNoError) {
            replyBuffer = TRKGetBuffer(replyBufferId);
            TRKSetBufferPosition(replyBuffer, 2);
        }
        if (error == kNoError) error = TRKReadBuffer1_ui8(replyBuffer, ioResult);
        TRKReleaseBuffer(replyBufferId);
    }
    TRKReleaseBuffer(bufferId);
    return error;
}

DSError HandlePositionFileSupportRequest(u32 handle, u32 position, u8 origin, u8* ioResult)
{
    DSError error;
    int replyBufferId;
    int bufferId;
    MessageBuffer* replyBuffer;
    MessageBuffer* buffer;

    error = TRKGetFreeBuffer(&bufferId, &buffer);
    if (error == kNoError) error = TRKAppendBuffer1_ui8(buffer, kDSPositionFile);
    if (error == kNoError) error = TRKAppendBuffer1_ui32(buffer, handle);
    if (error == kNoError) error = TRKAppendBuffer1_ui32(buffer, position);
    if (error == kNoError) error = TRKAppendBuffer1_ui8(buffer, origin);
    if (error == kNoError) {
        *ioResult = kDSIONoError;
        error = TRKRequestSend(buffer, &replyBufferId, 3, 3, 0);
        if (error == kNoError) {
            replyBuffer = TRKGetBuffer(replyBufferId);
            TRKSetBufferPosition(replyBuffer, 2);
        }
        if (error == kNoError) error = TRKReadBuffer1_ui8(replyBuffer, ioResult);
        TRKReleaseBuffer(replyBufferId);
    }
    TRKReleaseBuffer(bufferId);
    return error;
}
