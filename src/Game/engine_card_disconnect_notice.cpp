#include "Game/engine_card_owner_controls.h"

extern "C" {
extern struct { char unknown00[0x110]; void* log; } lbl_801E9D24;
extern const char lbl_802AF18C[];
void fn_801FA014(void*, const char*, ...);
}

extern "C" void fn_80276BF0(CardOwnerControlsView* self)
{
    fn_801FA014(lbl_801E9D24.log, lbl_802AF18C);
    self->connected4D0 = 0;
    self->state4CC = 0;
}
