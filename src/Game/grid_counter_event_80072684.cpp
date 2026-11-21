#include "Game/grid_event_update_views.h"

extern "C" void fn_80072684(GridEventOwner* self)
{
    ++self->counter;
    if (self->counter == 8)
        fn_802073E8(self, 0xAA, lbl_803776B8->getResource(), lbl_80378910);
}
