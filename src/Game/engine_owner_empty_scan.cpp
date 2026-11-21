/* Original empty count iteration and zero result.
 * See docs/notes/game-engine-owner-small-loops.md. */
#include "Game/engine_owner_small_loops.h"

extern "C" signed char fn_8024A040(OwnerEmptyScanOwner* self) {
    for (int i = 0; i < self->count; ++i) {}
    return 0;
}
