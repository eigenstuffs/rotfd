/* Part of the original CSBPantsMove source: the configureCallbacks members of
 * CSBPants_BRKMove and CSBPantsMove, with the vtables, RTTI records and
 * adjustor thunks that the compiler emits for both classes (key functions:
 * configureCallbacks).  Built with deferred inlining, which emits the two
 * members in reverse source order and the CSBPants_BRKMove tables first, as
 * in the original.  See include/Game/move_classes.h. */
#include "Game/move_classes.h"

/* Leading .rodata objects of this unit, ahead of the compiler's RTTI data. */
extern "C" const char lbl_802AAFA8[] = "Anonymous New";
extern "C" const char lbl_802AAFB8[] = "SBPantsMove.cpp";

void CSBPantsMove::configureCallbacks() {}

void CSBPants_BRKMove::configureCallbacks() {}
