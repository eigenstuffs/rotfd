#include "Game/engine_card_sector_prepare.h"
#include "Game/memory_card_owner_internal.h"
extern "C" {
extern const char lbl_802AF158[];
extern signed char lbl_80377FC9[1], lbl_80377FC0[1];
extern struct { char unknown00[0x110]; void* log; } lbl_801E9D24;
int OSGetResetSwitchState();
int CARDGetSectorSize(int, unsigned long*);
int CARDCheck(int);
int CARDFreeBlocks(int, unsigned long*, int*);
void fn_801FA014(void*, const char*, ...);
}
extern "C" int fn_802776D0(MemoryCardOwnerView* self) {
    const char* messages = (const char*)&lbl_802AF158;
    int attempts = 0;
    lbl_80377FC9[0] = OSGetResetSwitchState();
    int result;
    do {
        result = CARDGetSectorSize(self->channel, &self->sectorSize);
        ++attempts;
        if (!OSGetResetSwitchState() && lbl_80377FC9[0]) {
            fn_801FA014(lbl_801E9D24.log, messages + 0xF4);
            lbl_80377FC0[0] = 1;
        }
        lbl_80377FC9[0] = OSGetResetSwitchState();
        if (lbl_80377FC9[0])
            fn_801FA014(lbl_801E9D24.log, messages + 0x114);
    } while (result == -1 && attempts < 1000);
    if (attempts >= 1000)
        fn_801FA014(lbl_801E9D24.log, messages + 0x134);
    if (result)
        return 0;
    if (self->sectorSize != 0x2000)
        return 0;
    attempts = 0;
    lbl_80377FC9[0] = OSGetResetSwitchState();
    do {
        result = CARDCheck(self->channel);
        ++attempts;
        if (!OSGetResetSwitchState() && lbl_80377FC9[0]) {
            fn_801FA014(lbl_801E9D24.log, messages + 0xF4);
            lbl_80377FC0[0] = 1;
        }
        lbl_80377FC9[0] = OSGetResetSwitchState();
        if (lbl_80377FC9[0])
            fn_801FA014(lbl_801E9D24.log, messages + 0x114);
    } while (result == -1 && attempts < 1000);
    if (attempts >= 1000)
        fn_801FA014(lbl_801E9D24.log, messages + 0x134);
    if (result)
        return 0;
    attempts = 0;
    lbl_80377FC9[0] = OSGetResetSwitchState();
    do {
        result = CARDFreeBlocks(self->channel, &self->freeBytes, &self->freeFiles);
        ++attempts;
        if (!OSGetResetSwitchState() && lbl_80377FC9[0]) {
            fn_801FA014(lbl_801E9D24.log, messages + 0xF4);
            lbl_80377FC0[0] = 1;
        }
        lbl_80377FC9[0] = OSGetResetSwitchState();
        if (lbl_80377FC9[0])
            fn_801FA014(lbl_801E9D24.log, messages + 0x114);
    } while (result == -1 && attempts < 1000);
    if (attempts >= 1000)
        fn_801FA014(lbl_801E9D24.log, messages + 0x134);
    return result ? 0 : 1;
}
