#include "Game/engine_owner_small.h"

void fn_8021F518(struct EngineOwnerSmallRecordOwner* self,
                 const struct EngineOwnerSmallRecord* in, int index)
{
    struct EngineOwnerSmallRecord* out =
        (struct EngineOwnerSmallRecord*)(self->records + index * 0x28);
    out->x = in->x;
    out->y = in->y;
    out->z = in->z;
    out->flags = in->flags;
    out->a = in->a;
    out->b = in->b;
    out->c = in->c;
}
