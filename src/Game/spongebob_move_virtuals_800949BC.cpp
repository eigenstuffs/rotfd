/* Part of the original CSpongeBobMove source: two CActorMove accessors
 * first emitted here and CSpongeBobMove::configureCallbacks, with the vtable,
 * RTTI records and adjustor thunks that the compiler emits for the class
 * (key function: configureCallbacks).  See include/Game/move_classes.h. */
#include "Game/move_classes.h"

/* Leading objects of this unit, ahead of the compiler's RTTI data. */
extern "C" const float lbl_80378C20 = -1612.0f;

float CActorMove::slot70() { return *(const float*)((const char*)this + 892); }

void CActorMove::slot78(float value) { *(float*)((char*)this + 892) = value; }

void CSpongeBobMove::configureCallbacks() {}
