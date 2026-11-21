#include "Game/grid_event_update_views.h"

extern "C" void fn_800726EC(GridEventOwner* self)
{
    if (fn_8025E9FC(self, 0x9B))
        fn_802073E8(self, 0x9C, self, lbl_80378900);
    if (fn_8025E9FC(self, 0x8F))
        fn_800729C8(self);
}
