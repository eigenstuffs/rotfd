#ifndef GAME_PLATFORM_ITEM_INTERNAL_H
#define GAME_PLATFORM_ITEM_INTERNAL_H
#include "objects_owner_internal.h"
// Only the field-free deletion interface is established here; instances are external.
struct PlatformItem_802859A8 {
 ~PlatformItem_802859A8();
 static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
#endif
