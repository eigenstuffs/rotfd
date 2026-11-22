#include "../os/OSContext_abi.h"
typedef signed long s32;
typedef void (*HIOCallback)(void);
typedef void (*EXICallback)(s32, OSContext *);
#define ASSERTLINE(line, condition) ((void)0)
extern u32 __OSGetDIConfig(void);
extern BOOL EXIDeselect(s32), EXIUnlock(s32), EXISync(s32);
extern BOOL EXILock(s32, u32, EXICallback), EXISelect(s32, u32, u32);
extern BOOL EXIImm(s32, void *, s32, u32, EXICallback);
extern BOOL EXIDma(s32, void *, s32, u32, EXICallback);
static s32 Chan = -1;
static u32 Dev;
static HIOCallback TxCallback;
static HIOCallback RxCallback;

static inline BOOL CheckDevType(void)
{
    if (__OSGetDIConfig() == 0xFF) {
        switch (*(u16 *)0x800030E6) {
        case 0x8200:
            return 1;
        default:
            return 0;
        }
    }
    return 1;
}

static void TxHandler(s32 chan, OSContext* context)
{
    EXIDeselect(Chan);
    EXIUnlock(Chan);
    if (TxCallback) {
        TxCallback();
    }
}

static void RxHandler(s32 chan, OSContext* context)
{
    EXIDeselect(Chan);
    EXIUnlock(Chan);
    if (RxCallback) {
        RxCallback();
    }
}

BOOL HIOWriteMailbox(u32 word)
{
    int err;
    u32 cmd;

    if (Chan == -1 || !CheckDevType()) {
        return 0;
    }
    if (EXILock(Chan, Dev, 0) == 0) {
        return 0;
    }
    if (EXISelect(Chan, Dev, 4) == 0) {
        EXIUnlock(Chan);
        return 0;
    }
    cmd = (word & 0x1FFFFFFF) | 0xC0000000;
    err = 0;
    err |= !EXIImm(Chan, &cmd, 4, 1, 0);
    err |= !EXISync(Chan);
    err |= !EXIDeselect(Chan);
    EXIUnlock(Chan);
    return !err;
}

BOOL HIORead(u32 addr, void* buffer, s32 size)
{
    int err;
    u32 cmd;

    if (Chan == -1 || !CheckDevType()) {
        return 0;
    }
    ASSERTLINE(0x145, (addr % 4) == 0);
    if (EXILock(Chan, Dev, 0) == 0) {
        return 0;
    }
    if (EXISelect(Chan, Dev, 4) == 0) {
        EXIUnlock(Chan);
        return 0;
    }
    cmd = ((addr << 8) & 0x01FFFC00) | 0x20000000;
    err = 0;
    err |= !EXIImm(Chan, &cmd, 4, 1, 0);
    err |= !EXISync(Chan);
    err |= !EXIDma(Chan, buffer, size, 0, NULL);
    err |= !EXISync(Chan);
    err |= !EXIDeselect(Chan);
    EXIUnlock(Chan);
    return !err;
}

BOOL HIOWrite(u32 addr, void* buffer, s32 size)
{
    int err;
    u32 cmd;

    if (Chan == -1 || !CheckDevType()) {
        return 0;
    }
    ASSERTLINE(0x167, (addr % 4) == 0);
    if (EXILock(Chan, Dev, 0) == 0) {
        return 0;
    }
    if (EXISelect(Chan, Dev, 4) == 0) {
        EXIUnlock(Chan);
        return 0;
    }
    cmd = ((addr << 8) & 0x01FFFC00) | 0xA0000000;
    err = 0;
    err |= !EXIImm(Chan, &cmd, 4, 1, 0);
    err |= !EXISync(Chan);
    err |= !EXIDma(Chan, buffer, size, 1, NULL);
    err |= !EXISync(Chan);
    err |= !EXIDeselect(Chan);
    EXIUnlock(Chan);
    return !err;
}

BOOL HIOReadAsync(u32 addr, void* buffer, s32 size, HIOCallback callback)
{
    int err;
    u32 cmd;

    if (Chan == -1 || !CheckDevType()) {
        return 0;
    }
    ASSERTLINE(0x189, (addr % 4) == 0);
    RxCallback = callback;
    if (EXILock(Chan, Dev, 0) == 0) {
        return 0;
    }
    if (EXISelect(Chan, Dev, 4) == 0) {
        EXIUnlock(Chan);
        return 0;
    }
    cmd = ((addr << 8) & 0x01FFFC00) | 0x20000000;
    err = 0;
    err |= !EXIImm(Chan, &cmd, 4, 1, 0);
    err |= !EXISync(Chan);
    err |= !EXIDma(Chan, buffer, size, 0, RxHandler);
    return !err;
}

BOOL HIOWriteAsync(u32 addr, void* buffer, s32 size, HIOCallback callback)
{
    int err;
    u32 cmd;

    if (Chan == -1 || !CheckDevType()) {
        return 0;
    }
    ASSERTLINE(0x1AA, (addr % 4) == 0);
    TxCallback = callback;
    if (EXILock(Chan, Dev, 0) == 0) {
        return 0;
    }
    if (EXISelect(Chan, Dev, 4) == 0) {
        EXIUnlock(Chan);
        return 0;
    }
    cmd = ((addr << 8) & 0x01FFFC00) | 0xA0000000;
    err = 0;
    err |= !EXIImm(Chan, &cmd, 4, 1, 0);
    err |= !EXISync(Chan);
    err |= !EXIDma(Chan, buffer, size, 1, TxHandler);
    return !err;
}

BOOL HIOReadStatus(u32* status)
{
    int err;
    u32 cmd;

    if (Chan == -1 || !CheckDevType()) {
        return 0;
    }
    if (EXILock(Chan, Dev, 0) == 0) {
        return 0;
    }
    if (EXISelect(Chan, Dev, 4) == 0) {
        EXIUnlock(Chan);
        return 0;
    }
    cmd = 0x40000000;
    err = 0;
    err |= !EXIImm(Chan, &cmd, 2, 1, 0);
    err |= !EXISync(Chan);
    err |= !EXIImm(Chan, status, 4, 0, 0);
    err |= !EXISync(Chan);
    err |= !EXIDeselect(Chan);
    EXIUnlock(Chan);
    return !err;
}
