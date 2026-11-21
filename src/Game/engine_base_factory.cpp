#include "Game/engine_base_factory.h"

extern "C" {
extern char lbl_801EF5C8[];
extern const char lbl_802AE024[], lbl_802AE174[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
}

inline void *operator new(unsigned long, void *address) { return address; }

extern "C" ObjectsBase_802EB3F8 *fn_8020A1E4()
{
    return new (fn_801EFA1C(lbl_801EF5C8, sizeof(ObjectsBase_802EB3F8),
                           lbl_802AE024, lbl_802AE174, 221, 4)) ObjectsBase_802EB3F8;
}
