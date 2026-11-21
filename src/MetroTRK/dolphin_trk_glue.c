/* MetroTRK transport glue. Buffered serial adaptation follows original accesses. */
#include "trk_abi.h"

typedef struct OSContext OSContext;
typedef void (*TRKInterruptHandler)(short, OSContext*);
typedef int (*DBCommFunc)(void);
typedef void (*DBCommInitFunc)(u8**, TRKInterruptHandler);
typedef int (*DBCommReadFunc)(void*, u32);
typedef int (*DBCommWriteFunc)(const void*, u32);
typedef struct DBCommTable {
    DBCommInitFunc initialize_func;
    DBCommFunc initinterrupts_func;
    DBCommFunc peek_func;
    DBCommReadFunc read_func;
    DBCommWriteFunc write_func;
    DBCommFunc open_func;
    DBCommFunc close_func;
} DBCommTable;
static DBCommTable gDBCommTable = { NULL, NULL, NULL, NULL, NULL, NULL, NULL };

/* The unused word retains its observed offset; original two-byte tail alignment
 * after the write buffer remains separately owned. */
typedef struct TRKUARTState {
    int writeCount;
    int readPosition;
    int readCount;
    u32 unknown_0C;
    u8 readBuffer[0x110A];
} TRKUARTState;
u8 gTRKUARTWriteBuffer[0x110A];
TRKUARTState gTRKUARTState;
extern void TRKLoadContext(OSContext*, u32);
extern int OSEnableScheduler(void);
extern int Hu_IsStub(void), AMC_IsStub(void);
extern void DBInitComm(u8**, TRKInterruptHandler), EXI2_Init(u8**, TRKInterruptHandler);
extern int DBInitInterrupts(void), DBQueryData(void), DBOpen(void), DBClose(void);
extern int EXI2_EnableInterrupts(void), EXI2_Poll(void), EXI2_Reserve(void), EXI2_Unreserve(void);
extern int DBRead(void*, u32), EXI2_ReadN(void*, u32);
extern int DBWrite(const void*, u32), EXI2_WriteN(const void*, u32);
extern void OSReport(const char*, ...);

static void TRKEXICallBack(short interrupt, OSContext* ctx)
{
    OSEnableScheduler();
    TRKLoadContext(ctx, 0x500);
}

int InitMetroTRKCommTable(int hwId)
{
    bool isStub;
    if (hwId == 1) {
        isStub = Hu_IsStub();
        gDBCommTable.initialize_func = DBInitComm;
        gDBCommTable.initinterrupts_func = DBInitInterrupts;
        gDBCommTable.peek_func = DBQueryData;
        gDBCommTable.read_func = DBRead;
        gDBCommTable.write_func = DBWrite;
        gDBCommTable.open_func = DBOpen;
        gDBCommTable.close_func = DBClose;
        return isStub;
    } else {
        isStub = AMC_IsStub();
        gDBCommTable.initialize_func = EXI2_Init;
        gDBCommTable.initinterrupts_func = EXI2_EnableInterrupts;
        gDBCommTable.peek_func = EXI2_Poll;
        gDBCommTable.read_func = EXI2_ReadN;
        gDBCommTable.write_func = EXI2_WriteN;
        gDBCommTable.open_func = EXI2_Reserve;
        gDBCommTable.close_func = EXI2_Unreserve;
        return isStub;
    }
}

DSError TRKInitializeIntDrivenUART(u32 r3, u32 r4, u32 r5, u8** inputPending)
{
    gDBCommTable.initialize_func(inputPending, TRKEXICallBack);
    return kNoError;
}

void EnableEXI2Interrupts(void)
{
    gDBCommTable.initinterrupts_func();
}

DSError TRKWriteUART1(signed char);
DSError TRKFlushUART(void)
{
    DSError error = kNoError;
    for (; gTRKUARTState.writeCount < 0x800; gTRKUARTState.writeCount++)
        gTRKUARTWriteBuffer[gTRKUARTState.writeCount] = 0;
    if (gTRKUARTState.writeCount) {
        error = -(gDBCommTable.write_func(gTRKUARTWriteBuffer, gTRKUARTState.writeCount) != 0);
        gTRKUARTState.writeCount = 0;
    }
    return error;
}

DSError TRKWriteUART1(signed char byte)
{
    gTRKUARTWriteBuffer[gTRKUARTState.writeCount++] = byte;
    return kNoError;
}

DSError TRKReadUART1(signed char* byte)
{
    TRKUARTState* state = &gTRKUARTState;
    DSError error = 4;
    if (state->readPosition >= state->readCount) {
        state->readPosition = 0;
        state->readCount = gDBCommTable.peek_func();
        if (state->readCount > 0) {
            if (state->readCount > 0x110A) state->readCount = 0x110A;
            error = gDBCommTable.read_func(state->readBuffer, state->readCount) ? -1 : 0;
            if (error) state->readCount = 0;
        }
    }
    if (state->readPosition < state->readCount) {
        *byte = state->readBuffer[state->readPosition++];
        error = kNoError;
    }
    return error;
}

void ReserveEXI2Port(void)
{
    gDBCommTable.open_func();
}

void UnreserveEXI2Port(void)
{
    gDBCommTable.close_func();
}

#pragma push
#pragma peephole off
void TRK_board_display(const char* str)
{
    OSReport(str);
}
#pragma pop

void TRKUARTInterruptHandler(void) {}
