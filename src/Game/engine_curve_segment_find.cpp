/* Original accumulated-length segment lookup.
 * See docs/notes/game-engine-owner-small-loops.md. */
#include "Game/engine_owner_small_loops.h"

extern "C" int fn_8024D9FC(CurveSegmentFindOwner* self, float value) {
    float target = self->scale * value;
    float sum = lbl_8037B44C;
    int i;
    for (i = 0; i < self->count; ++i) {
        if (sum > target) break;
        sum += self->entries[i].length;
    }
    return i - 1;
}
