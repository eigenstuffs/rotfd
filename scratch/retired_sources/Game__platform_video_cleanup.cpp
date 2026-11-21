#include "Game/platform_video_cleanup_internal.h"
extern "C" void fn_8028D6FC(VideoTransitionCleanup* state)
{
    if (state->allocation) {
        fn_801EF610(lbl_801EF5C8, state->allocation);
        state->allocation = 0;
    }
    fn_801C9ABC(state);
    if (state->enabled)
        state->slot18();
}
