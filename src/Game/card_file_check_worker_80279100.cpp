// Memory-card worker thread: waits for a request, probes/mounts the card and
// checks whether the named save file can be opened.
// Owner view (same layout as include/Game/memory_card_owner_internal.h).
struct MemoryCardOwnerView {
    char unknown00[0x350];
    char queue[8];
    char mutex[24];
    unsigned long status;
    int unknown374;
    char name[64];
    unsigned long sectorSize;
    int memorySize;
    int channel;
    char unknown3C4[0x44];
    void* workArea;
};

extern "C" {
extern const char lbl_802AF158[];
extern signed char lbl_80377FC9[1], lbl_80377FC0[1];
extern struct { char unknown00[0x110]; void* log; } lbl_801E9D24;
int OSGetResetSwitchState();
void fn_801FA014(void*, const char*, ...);
int CARDOpen(int, const char*, void*);
int CARDClose(void*);
extern char lbl_801EF5C8[];
void OSSleepThread(void*);
int OSEnableInterrupts();
void OSRestoreInterrupts(int);
void OSLockMutex(void*);
void OSUnlockMutex(void*);
int CARDProbeEx(int, int*, unsigned long*);
int CARDUnmount(int);
int fn_80277918(MemoryCardOwnerView*, int);
void fn_801EF610(void*, void*);
}

extern "C" void* fn_80279100(void* arg) {
    MemoryCardOwnerView* self = (MemoryCardOwnerView*)arg;
    const char* messages = lbl_802AF158;
    do {
        OSSleepThread(self->queue);
        int previous = OSEnableInterrupts();
        OSLockMutex(self->mutex);
        if (self->name[0]) {
            int result = fn_80277918(self, 0);
            if (result == 0 || result == 1) {
                int probe = -1;
                while (probe == -1)
                    probe = CARDProbeEx(self->channel, &self->memorySize, &self->sectorSize);
                result = probe ? 0 : 1;
            }
            CARDUnmount(self->channel);
            if (self->workArea) {
                fn_801EF610(lbl_801EF5C8, self->workArea);
                self->workArea = 0;
            }
            if (result == 0) {
                OSUnlockMutex(self->mutex);
                self->status = 1;
                break;
            }
            unsigned long final = fn_80277918(self, 1);
            if (final == 0) {
                int attempts = 0;
                lbl_80377FC9[0] = OSGetResetSwitchState();
                unsigned long open;
                char info[20];
                do {
                    open = CARDOpen(self->channel, self->name, info);
                    if (!OSGetResetSwitchState() && lbl_80377FC9[0]) {
                        fn_801FA014(lbl_801E9D24.log, messages + 0xF4);
                        lbl_80377FC0[0] = 1;
                    }
                    lbl_80377FC9[0] = OSGetResetSwitchState();
                    if (lbl_80377FC9[0])
                        fn_801FA014(lbl_801E9D24.log, messages + 0x114);
                    ++attempts;
                } while (open == -1 && attempts < 5);
                if (attempts >= 5)
                    fn_801FA014(lbl_801E9D24.log, messages + 0x134);
                if (open == 0) {
                    CARDClose(info);
                    final = 0;
                } else {
                    final = 5;
                }
            }
            self->status = final;
            CARDUnmount(self->channel);
            if (self->workArea) {
                fn_801EF610(lbl_801EF5C8, self->workArea);
                self->workArea = 0;
            }
        }
        OSUnlockMutex(self->mutex);
        OSRestoreInterrupts(previous);
    } while(1);
    return 0;
}
