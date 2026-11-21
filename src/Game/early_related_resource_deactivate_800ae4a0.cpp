/* Related resource deactivation; see docs/notes/game-early-related-resource-deactivate.md. */
#include "Game/early_related_resource_deactivate_views.h"
extern "C" void fn_800AE4A0(DeactivateOwner*self){DeactivateObject*owner=resolveDeactivate(self->actor->handle);resolveDeactivate(resolveDeactivate(owner->related58)->related20)->destroy(-1);if(self->actor->active){DeactivateObject*effect=resolveDeactivate(fn_80058778(lbl_801E9D24.scene->mode,DeactivateName(lbl_802A0178),0));deactivateEffect(effect);deactivateEffect(owner->effect);}self->actor->active=0;}
