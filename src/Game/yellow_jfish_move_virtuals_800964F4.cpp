/* Part of the original CYellowJfishMove source: slot40, the CActorMove and
 * CJellyfishMove members first emitted here, and the vtable, RTTI records and
 * adjustor thunks that the compiler emits for the class (key function:
 * slot40).  The class hierarchy comes from the original RTTI base lists; see
 * include/Game/move_classes.h. */
#include "Game/move_classes.h"

void CYellowJfishMove::slot40(const Vec3* a, const Vec3* b, const Vec3* c, int d, float e) { CJellyfishMove::slot40(a, b, c, d, e); }

void CActorMove::slot168() {}

void CJellyfishMove::configureCallbacks() {}

/* Objects of this unit ahead of the compiler RTTI data. */
extern "C" const char lbl_8029DE30[] = "YellowJfishMove.cpp";
extern "C" const float lbl_80378C60 = 2.5f;
