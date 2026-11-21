#include "Game/engine_game_factory.h"

extern "C" {
extern char lbl_801EF5C8[];
extern const char lbl_802AE024[], lbl_802AE0FC[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
}

inline void *operator new(unsigned long, void *address) { return address; }

extern "C" ObjectsGame_802EB900 *fn_80209814()
{
    return new (fn_801EFA1C(lbl_801EF5C8, sizeof(ObjectsGame_802EB900),
                           lbl_802AE024, lbl_802AE0FC, 96, 4)) ObjectsGame_802EB900;
}
