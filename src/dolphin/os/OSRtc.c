/* Dolphin SDK SRAM C services, GSQE78.
 * Adapted from the public doldecomp/melee SDK reconstruction;
 * see reference/melee-sdk/PROVENANCE.md and docs/notes/OSRtc.md.
 */
#include "OSContext_abi.h"
typedef signed long s32;
#define ATTRIBUTE_ALIGN(n) __attribute__((aligned(n)))
#define ASSERTLINE(line,cond) ((void)0)
struct SramControl {
    unsigned char sram[64];
    unsigned long offset;
    int enabled;
    int locked;
    int sync;
    void (* callback)();
};

typedef struct OSSram {
    unsigned short checkSum;
    unsigned short checkSumInv;
    unsigned long ead0;
    unsigned long ead1;
    unsigned long counterBias;
    signed char displayOffsetH;
    unsigned char ntd;
    unsigned char language;
    unsigned char flags;
} OSSram;

typedef struct OSSramEx {
    unsigned char flashID[2][12];
    unsigned long wirelessKeyboardID;
    unsigned short wirelessPadID[4];
    unsigned char dvdErrorCode;
    unsigned char _padding0;
    unsigned char flashIDCheckSum[2];
    unsigned char _padding1[4];
} OSSramEx;


typedef void (*EXICallback)();
extern BOOL EXILock(s32, u32, EXICallback), EXIUnlock(s32), EXISelect(s32, u32, u32), EXIDeselect(s32), EXISync(s32);
extern BOOL EXIImm(s32, void *, s32, u32, EXICallback), EXIImmEx(s32, void *, s32, u32), EXIDma(s32, void *, s32, u32, EXICallback);
extern void DCInvalidateRange(void *, u32);
static struct SramControl Scb ATTRIBUTE_ALIGN(32);
static int WriteSram(void *, unsigned long, unsigned long);
static inline int ReadSram(void* buffer)
{
    int err;
    unsigned long cmd;

    DCInvalidateRange(buffer, 0x40);
    if (!EXILock(0, 1, NULL)) {
        return 0;
    }
    if (!EXISelect(0, 1, 3)) {
        EXIUnlock(0);
        return 0;
    }
    cmd = 0x20000100;
    err = 0;
    err |= !EXIImm(0, &cmd, 4, 1, 0);
    err |= !EXISync(0);
    err |= !EXIDma(0, buffer, 0x40, 0, NULL);
    err |= !EXISync(0);
    err |= !EXIDeselect(0);
    EXIUnlock(0);
    return !err;
}

static void WriteSramCallback()
{
    int unused;
    ASSERTLINE(0xF0, !Scb.locked);
    Scb.sync = WriteSram(&Scb.sram[Scb.offset], Scb.offset, 0x40 - Scb.offset);
    if (Scb.sync != 0) {
        Scb.offset = 0x40;
    }
    ASSERTLINE(0xF6, Scb.sync);
}

static int WriteSram(void* buffer, unsigned long offset, unsigned long size)
{
    int err;
    unsigned long cmd;

    if (!EXILock(0, 1, WriteSramCallback)) {
        return 0;
    }
    if (!EXISelect(0, 1, 3)) {
        EXIUnlock(0);
        return 0;
    }
    offset <<= 6;
    cmd = ((offset + 0x100) | 0xA0000000);
    err = 0;
    err |= !EXIImm(0, &cmd, 4, 1, 0);
    err |= !EXISync(0);
    err |= !EXIImmEx(0, buffer, size, 1);
    err |= !EXIDeselect(0);
    EXIUnlock(0);
    return !err;
}

void __OSInitSram()
{
    Scb.locked = Scb.enabled = 0;
    Scb.sync = ReadSram(&Scb);
    ASSERTLINE(0x12C, Scb.sync);
    Scb.offset = 0x40;
}

static inline void* LockSram(unsigned long offset)
{
    int enabled;

    enabled = OSDisableInterrupts();
    ASSERTLINE(0x140, !Scb.locked);
    if (Scb.locked) {
        OSRestoreInterrupts(enabled);
        return NULL;
    }
    Scb.enabled = enabled;
    Scb.locked = 1;
    return &Scb.sram[offset];
}

struct OSSram* __OSLockSram()
{
    return (struct OSSram*) LockSram(0);
}

struct OSSramEx* __OSLockSramEx(void)
{
    return (struct OSSramEx*) LockSram(0x14);
}

static int UnlockSram(int commit, unsigned long offset)
{
    unsigned short* p;

    ASSERTLINE(0x162, Scb.locked);
    if (commit != 0) {
        if (offset == 0) {
            u8* sram = Scb.sram;

            if ((sram[0x13] & 3) > 2U) {
                sram[0x13] &= 0xFFFFFFFC;
            }

            {
                struct OSSram* sram = (struct OSSram*) &Scb.sram[0];
                sram->checkSum = sram->checkSumInv = 0;
                for (p = (unsigned short*) &sram->counterBias;
                     p < ((u16*) &Scb.sram[sizeof(struct OSSram)]); p++)
                {
                    sram->checkSum += *p;
                    sram->checkSumInv += ~(*p);
                }
            }
        }
        if (offset < Scb.offset) {
            Scb.offset = offset;
        }
        Scb.sync =
            WriteSram(&Scb.sram[Scb.offset], Scb.offset, 0x40 - Scb.offset);
        if (Scb.sync != 0) {
            Scb.offset = 0x40;
        }
    }
    Scb.locked = 0;
    OSRestoreInterrupts(Scb.enabled);
    return Scb.sync;
}

int __OSUnlockSram(int commit)
{
    return UnlockSram(commit, 0);
}

int __OSUnlockSramEx(int commit)
{
    return UnlockSram(commit, 0x14);
}

int __OSSyncSram()
{
    return Scb.sync;
}

unsigned long OSGetSoundMode()
{
    struct OSSram* sram = __OSLockSram();
    unsigned long mode = (sram->flags & 4) ? 1 : 0;

    __OSUnlockSram(0);
    return mode;
}

void OSSetSoundMode(unsigned long mode)
{
    struct OSSram* sram;
    int unused;

    ASSERTLINE(0x22A,
               mode == OS_SOUND_MODE_MONO || mode == OS_SOUND_MODE_STEREO);
    mode *= 4;
    mode &= 4;
    sram = __OSLockSram();
    if (mode == (sram->flags & 4)) {
        __OSUnlockSram(0);
        return;
    }
    sram->flags &= 0xFFFFFFFB;
    sram->flags |= mode;
    __OSUnlockSram(1);
}

u16 OSGetWirelessID(s32 arg0)
{
    u16* var_r3;
    u16 id;
    u8 _[4];

    var_r3 = LockSram(0x14);
    id = var_r3[arg0 + 0xE];
    UnlockSram(0, 0x14);
    return id;
}

void OSSetWirelessID(long chan, u16 id)
{
    struct OSSramEx* sram = __OSLockSramEx();

    if (sram->wirelessPadID[chan] != id) {
        sram->wirelessPadID[chan] = id;
        __OSUnlockSramEx(1);
        return;
    }
    __OSUnlockSramEx(0);
}

