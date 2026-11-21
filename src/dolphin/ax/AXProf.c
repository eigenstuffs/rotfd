/* AX profile ring accessor. Copyright (c) 2019-2025 NWPlayer123.
 * MIT license: reference/ttyd-sdk/LICENSE. See docs/notes/AXProf.md. */
#include "ax_abi.h"

static AXPROFILE* __AXProfile;
static u32 __AXMaxProfiles;
static u32 __AXCurrentProfile;
static u32 __AXProfileInitialized;

AXPROFILE* __AXGetCurrentProfile(void) {
    AXPROFILE* profile;

    if (__AXProfileInitialized != 0) {
        profile = &__AXProfile[__AXCurrentProfile];
        __AXCurrentProfile += 1;
        __AXCurrentProfile %= __AXMaxProfiles;
        return profile;
    }

    return 0;
}

