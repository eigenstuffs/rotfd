#include "Game/platform_movie_init_internal.h"
extern "C" signed char fn_8028D76C(MoviePlatformInit* state)
{
    if (!fn_801C9AC0(state))
        return 0;
    VIGetTvFormat();
    MovieVideoModePrefix* mode = &GXNtsc480Int;
    lbl_80378120 = mode;
    lbl_80378104 = (unsigned short)((((MovieVideoModePrefix*)lbl_80378120)->width + 15) & ~15) * ((MovieVideoModePrefix*)lbl_80378120)->height * 2;
    state->enabled = 0;
    state->black = 0;
    state->word48 = 0;
    state->allocation = fn_801EFA1C(lbl_801EF5C8, 0x60, lbl_802AF7A0,
                                   lbl_802AF7B0, 426, 32);
    return 1;
}
