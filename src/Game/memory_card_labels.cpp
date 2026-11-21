#include "Game/memory_card_init_internal.h"

extern "C" {
extern char lbl_801E9D24[];
extern const char lbl_802AF308[];
void fn_801FA014(void*, const char*, ...);
char* strcpy(char*, const char*);
char* strncpy(char*, const char*, unsigned long);
}

extern "C" void fn_80278E50(MemoryCardInitView* self, const char* name)
{
    if (name) {
        fn_801FA014(*(void**)(lbl_801E9D24 + 0x110), lbl_802AF308, name);
        strcpy(self->label, name);
        strncpy(self->shortLabel, self->label, 32);
    }
}
