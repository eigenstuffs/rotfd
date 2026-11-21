#include "Game/memory_card_init_internal.h"
#include "Game/platform_native_interface_tables.h"

extern "C" {
extern const char lbl_802AF32C[];
void* memset(void*, int, unsigned long);
char* strcpy(char*, const char*);
}

extern "C" MemoryCardInitView* fn_80279044(MemoryCardInitView* self)
{
    self->table = &lbl_802EDC48;
    self->unknown00 = 2;
    self->unknown04 = 0;
    self->table = &lbl_802EDB80;
    self->workArea = 0;
    self->channel = 0;
    self->freeFiles = 0;
    self->freeBytes = 0;
    self->sectorSize = 0;
    self->unknown4C8 = 0;
    self->unknown420 = 0;
    self->unknown418 = 0;
    self->unknown414 = 0;
    self->unknown424 = 0;
    self->unknown41C = 0;
    memset(self->bytes, 0, 96);
    strcpy(self->shortLabel, lbl_802AF32C);
    self->label[0] = 0;
    self->other[0] = 0;
    self->state = 0;
    self->connected = 0;
    self->formatted = 0;
    self->name[0] = 0;
    return self;
}
