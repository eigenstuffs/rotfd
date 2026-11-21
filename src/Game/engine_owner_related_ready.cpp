#include "Game/engine_owner_related_ready.h"

extern "C" signed char fn_80240FC4(RelatedReadyOwner* self) {
    if (!self->BaseObject_Z::slot1C())
        return 0;
    if (fn_801F7EB8(&self->primary))
        relatedReadyResolve(self->primary)->slot1C();
    if (fn_801F7EB8(&self->secondary))
        relatedReadyResolve(self->secondary)->slot1C();
    if (fn_801F7EB8(&self->first))
        relatedReadyResolve(self->first)->slot1C();
    if (fn_801F7EB8(&self->next))
        relatedReadyResolve(self->next)->slot1C();
    if (fn_801F7EB8(&self->related24))
        relatedReadyResolve(self->related24)->slot1C();
    if (fn_801F7EB8(&self->related28))
        relatedReadyResolve(self->related28)->slot1C();
    if (fn_801F7EB8(&self->related130))
        relatedReadyResolve(self->related130)->slot1C();
    if (fn_801F7EB8(&self->related2C))
        relatedReadyResolve(self->related2C)->slot1C();
    return 1;
}
