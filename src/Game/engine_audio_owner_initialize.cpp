#include "Game/engine_audio_owner_initialize.h"

struct AudioOwnerInitializeView {
    char unknown00[0x7C];
    void* table7C;
    char unknown80[0x390];
    void* buffer410;
    char unknown414[0xC];
    char queue420[0x10];
};

typedef char AudioOwnerInitializeViewSize[(sizeof(AudioOwnerInitializeView) == 0x430) ? 1 : -1];

extern "C" {
extern char lbl_802F1550[];
extern char lbl_801EF5C8[];
extern char lbl_802AF4F0[];
extern char lbl_802AF500[];
void __ct__27PlatformAudioOwner_8023BB18Fv(AudioOwnerInitializeView*);
void fn_8028AFF0(void*);
void* fn_801EFA1C(void*, unsigned long, const char*, const char*, int, int);
int OSEnableInterrupts();
void OSRestoreInterrupts(int);
void MIXUpdateSettings();
}

extern "C" AudioOwnerInitializeView* fn_80287AE0(AudioOwnerInitializeView* self) {
    __ct__27PlatformAudioOwner_8023BB18Fv(self);
    self->table7C = lbl_802F1550;
    fn_8028AFF0(self->queue420);
    self->buffer410 = fn_801EFA1C(lbl_801EF5C8, 0x500, lbl_802AF4F0, lbl_802AF500, 0x27, 4);
    return self;
}

extern "C" void fn_80287B50() {
    int interrupts = OSEnableInterrupts();
    MIXUpdateSettings();
    OSRestoreInterrupts(interrupts);
}
