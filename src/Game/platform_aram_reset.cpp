#include "Game/platform_aram_internal.h"
extern "C" unsigned long ARGetBaseAddress();
extern "C" unsigned long fn_80285730(PlatformAramOwner* self) {
    self->unknown08=0;
    self->cursor04=ARGetBaseAddress()+0x8000;
    self->cursor00=ARGetBaseAddress()+0xBB8000;
    return self->cursor00;
}
