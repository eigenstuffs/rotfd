#include "Game/engine_card_owner_controls.h"

extern "C" {
char* strncpy(char*, const char*, unsigned int);
void* memset(void*, int, unsigned int);
}

extern "C" void fn_80276F58(CardOwnerControlsView* self, const char* name)
{
    if (name)
        strncpy(self->label4A8, name, 32);
    else
        memset(self->label4A8, 0, 32);
}
