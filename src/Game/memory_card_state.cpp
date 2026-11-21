#include "Game/memory_card_owner_internal.h"

extern "C" {
extern char lbl_801E9D24[];
extern char lbl_801EF5C8[];
extern const char lbl_802AF158[];
extern const char lbl_802AF178[];
void fn_801FA014(void*, const char*, ...);
void fn_801EF610(void*, void*);
int fn_80277918(MemoryCardOwnerView*, int);
int CARDProbeEx(int, int*, unsigned long*);
int CARDUnmount(int);
}

extern "C" void fn_80276A6C(MemoryCardOwnerView* self)
{
    if (self->connected) {
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
            self->state = 1;
            self->connected = 0;
            self->formatted = 0;
            fn_801FA014(*(void**)(lbl_801E9D24 + 0x110), lbl_802AF158);
        }
    }
}

extern "C" void fn_80276B48(MemoryCardOwnerView* self)
{
    fn_801FA014(*(void**)(lbl_801E9D24 + 0x110), lbl_802AF178);
    if (fn_80277918(self, 1) != 1) {
        self->connected = 1;
        self->state = 0;
        self->formatted = 0;
    } else {
        self->connected = 0;
        self->state = 0;
        self->formatted = 0;
    }
    CARDUnmount(self->channel);
    if (self->workArea) {
        fn_801EF610(lbl_801EF5C8, self->workArea);
        self->workArea = 0;
    }
}
