#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B2AE0 = {
    {
        { &lbl_803741D8, 0 }, // BaseObject_Z
        { &lbl_803741E0, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B2AF4 = {
    {
        { &lbl_803741D8, 0 }, // BaseObject_Z
        { &lbl_803741E0, 0 }, // ABC_Agent
        { &lbl_803741E8, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for RtcAgent_Z.
NativeRuntimeBaseList<4> lbl_802B2B10 = {
    {
        { &lbl_803741D8, 0 }, // BaseObject_Z
        { &lbl_803741E0, 0 }, // ABC_Agent
        { &lbl_803741E8, 0 }, // Agent_Z
        { &lbl_803741F0, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for RtcInGameAgent_Z.
NativeRuntimeBaseList<5> lbl_802B2B34 = {
    {
        { &lbl_803741D8, 0 }, // BaseObject_Z
        { &lbl_803741E0, 0 }, // ABC_Agent
        { &lbl_803741E8, 0 }, // Agent_Z
        { &lbl_803741F0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803741F8, 0 }, // RtcAgent_Z
    }, 0
};

}
