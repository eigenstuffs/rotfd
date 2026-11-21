/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-fn-reset-layers.md. */
#include "Game/scene_vector_owner_800E2288.h"

Object_800E2288::~Object_800E2288() {
    prefix.root.vtable = lbl_802C85D0;
}
