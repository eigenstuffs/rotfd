#include "Game/early_camera_query_views.h"

extern "C" void fn_80078550(QueryCamera* self, QueryVector* out) {
    QueryVector current = self->current;
    QueryVector position;
    fn_80076D98(self, &position);
    *out = current - position;
}
