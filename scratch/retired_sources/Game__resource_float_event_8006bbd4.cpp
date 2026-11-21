#include "Game/resource_action_query_views.h"

extern "C" signed char fn_8006BBD4(ActionQuery* self, float x, float y)
{
    fn_8007622C(fn_8007D074(self), x, y);
    lbl_801E9D24.speaker->update(0, 0,
                              (int)(lbl_803787FC * (x / lbl_80378800)));
    if (y >= lbl_803787D4)
        fn_802073BC(self->getResource(), 0xCF, self->getResource(), y,
                    lbl_80378804);
    return 1;
}
