#include "Game/grid_event_update_views.h"

extern "C" void fn_800729C8(GridEventOwner* self)
{
    char text[128];
    const GridEventFormats& formats =
        *reinterpret_cast<const GridEventFormats*>(lbl_8029C8E0);

    sprintf(text, formats.row0, self->cells[0].node->value,
            self->cells[1].node->value, self->cells[2].node->value);
    fn_801FA014(lbl_801E9D24.logger, text);
    fn_801FA014(lbl_801E9D24.logger, lbl_80378914);

    sprintf(text, formats.row1, self->cells[3].node->value,
            self->cells[4].node->value, self->cells[5].node->value);
    fn_801FA014(lbl_801E9D24.logger, text);
    fn_801FA014(lbl_801E9D24.logger, lbl_80378914);

    sprintf(text, formats.row2, self->cells[6].node->value,
            self->cells[7].node->value, self->cells[8].node->value);
    fn_801FA014(lbl_801E9D24.logger, text);
    fn_801FA014(lbl_801E9D24.logger, lbl_80378914);
    fn_801FA014(lbl_801E9D24.logger, lbl_80378914);
    fn_801FA014(lbl_801E9D24.logger, lbl_80378914);
}
