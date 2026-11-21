#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802B08D8 = {
    {
        { &lbl_80373F68, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B08E4 = {
    {
        { &lbl_80373F68, 0 }, // BaseObject_Z
        { &lbl_80373F70, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B08F8 = {
    {
        { &lbl_80373F68, 0 }, // BaseObject_Z
        { &lbl_80373F70, 0 }, // ABC_Agent
        { &lbl_80373F78, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B0914 = {
    {
        { &lbl_80373F68, 0 }, // BaseObject_Z
        { &lbl_80373F70, 0 }, // ABC_Agent
        { &lbl_80373F78, 0 }, // Agent_Z
        { &lbl_80373F80, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B0938 = {
    {
        { &lbl_80373F68, 0 }, // BaseObject_Z
        { &lbl_80373F70, 0 }, // ABC_Agent
        { &lbl_80373F78, 0 }, // Agent_Z
        { &lbl_80373F80, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80373F88, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for CCollectableAgent.
NativeRuntimeBaseList<6> lbl_802B0964 = {
    {
        { &lbl_80373F68, 0 }, // BaseObject_Z
        { &lbl_80373F70, 0 }, // ABC_Agent
        { &lbl_80373F78, 0 }, // Agent_Z
        { &lbl_80373F80, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80373F88, 0 }, // AnimatedAgent_Z
        { &lbl_80373F90, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for CLetterTileBaseAgent.
NativeRuntimeBaseList<7> lbl_802B0998 = {
    {
        { &lbl_80373F68, 0 }, // BaseObject_Z
        { &lbl_80373F70, 0 }, // ABC_Agent
        { &lbl_80373F78, 0 }, // Agent_Z
        { &lbl_80373F80, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80373F88, 0 }, // AnimatedAgent_Z
        { &lbl_80373F90, 0 }, // MovingAgent_Z
        { &lbl_80373F98, 0 }, // CCollectableAgent
    }, 0
};

// Base hierarchy for LTileB2.
NativeRuntimeBaseList<8> lbl_802B09D4 = {
    {
        { &lbl_80373F68, 0 }, // BaseObject_Z
        { &lbl_80373F70, 0 }, // ABC_Agent
        { &lbl_80373F78, 0 }, // Agent_Z
        { &lbl_80373F80, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80373F88, 0 }, // AnimatedAgent_Z
        { &lbl_80373F90, 0 }, // MovingAgent_Z
        { &lbl_80373F98, 0 }, // CCollectableAgent
        { &lbl_80373FA0, 0 }, // CLetterTileBaseAgent
    }, 0
};

}
