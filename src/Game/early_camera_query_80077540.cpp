#include "Game/early_camera_query_views.h"

extern "C" signed char fn_80077540(QueryCamera* self) {
    if (fn_8007D604(&resolveQuery(self->target)->stateData, 0) ||
        fn_8007D604(&resolveQuery(self->target)->stateData, 6) ||
        fn_8007D604(&resolveQuery(self->target)->stateData, 24))
        return 1;
    return 0;
}
