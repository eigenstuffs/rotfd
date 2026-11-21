#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802C8B40 = {
    {
        { &lbl_80375AD8, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802C8B4C = {
    {
        { &lbl_80375AD8, 0 }, // BaseObject_Z
        { &lbl_80375AE0, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802C8B60 = {
    {
        { &lbl_80375AD8, 0 }, // BaseObject_Z
        { &lbl_80375AE0, 0 }, // ABC_Agent
        { &lbl_80375AE8, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802C8B7C = {
    {
        { &lbl_80375AD8, 0 }, // BaseObject_Z
        { &lbl_80375AE0, 0 }, // ABC_Agent
        { &lbl_80375AE8, 0 }, // Agent_Z
        { &lbl_80375AF0, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802C8BA0 = {
    {
        { &lbl_80375AD8, 0 }, // BaseObject_Z
        { &lbl_80375AE0, 0 }, // ABC_Agent
        { &lbl_80375AE8, 0 }, // Agent_Z
        { &lbl_80375AF0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375AF8, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802C8BCC = {
    {
        { &lbl_80375AD8, 0 }, // BaseObject_Z
        { &lbl_80375AE0, 0 }, // ABC_Agent
        { &lbl_80375AE8, 0 }, // Agent_Z
        { &lbl_80375AF0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375AF8, 0 }, // AnimatedAgent_Z
        { &lbl_80375B00, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for Breakable_Z.
NativeRuntimeBaseList<7> lbl_802C8C00 = {
    {
        { &lbl_80375AD8, 0 }, // BaseObject_Z
        { &lbl_80375AE0, 0 }, // ABC_Agent
        { &lbl_80375AE8, 0 }, // Agent_Z
        { &lbl_80375AF0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375AF8, 0 }, // AnimatedAgent_Z
        { &lbl_80375B00, 0 }, // MovingAgent_Z
        { &lbl_80375B08, 0 }, // Throwable_Z
    }, 0
};

// Base hierarchy for SBPants_BRK.
NativeRuntimeBaseList<8> lbl_802C8C3C = {
    {
        { &lbl_80375AD8, 0 }, // BaseObject_Z
        { &lbl_80375AE0, 0 }, // ABC_Agent
        { &lbl_80375AE8, 0 }, // Agent_Z
        { &lbl_80375AF0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375AF8, 0 }, // AnimatedAgent_Z
        { &lbl_80375B00, 0 }, // MovingAgent_Z
        { &lbl_80375B08, 0 }, // Throwable_Z
        { &lbl_80375B10, 0 }, // Breakable_Z
    }, 0
};

}
