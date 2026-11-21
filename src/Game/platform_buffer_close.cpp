#include "Game/platform_followup_controls.h"

struct PlatformBufferOwner {
    char unknown00[0xC];
    char file[0x40];
    int word4C;
    char unknown50[0xC];
    signed char opened;
};
extern "C" {
void fn_801C9AA0(PlatformBufferOwner*);
int DVDClose(void*);
}

extern "C" void fn_8028C494(PlatformBufferOwner* self) {
    if (self->opened) {
        fn_801C9AA0(self);
        self->opened = 0;
        DVDClose(self->file);
        self->word4C = 0;
    }
}
