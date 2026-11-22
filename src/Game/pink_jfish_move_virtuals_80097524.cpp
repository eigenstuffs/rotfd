/* Part of the original CPinkJfishMove source: slot40, with the vtable, RTTI
 * records and adjustor thunks that the compiler emits for the class (key
 * function: slot40).  See include/Game/move_classes.h. */
#include "Game/move_classes.h"
#include "Game/early_action_control_views.h"

void CPinkJfishMove::slot40(const Vec3*, const Vec3* value, const Vec3*, int, float) { ActionActor* self = reinterpret_cast<ActionActor*>(this); self->slot45((void*)value, 0); }

/* Objects of this unit ahead of the compiler RTTI data. */
extern "C" const char lbl_8029E008[] = "PinkJfishMove.cpp";
