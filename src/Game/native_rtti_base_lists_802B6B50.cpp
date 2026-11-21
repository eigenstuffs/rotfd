#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802B6B50 = {
    {
        { &lbl_803746E0, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B6B5C = {
    {
        { &lbl_803746E0, 0 }, // BaseObject_Z
        { &lbl_803746E8, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B6B70 = {
    {
        { &lbl_803746E0, 0 }, // BaseObject_Z
        { &lbl_803746E8, 0 }, // ABC_Agent
        { &lbl_803746F0, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B6B8C = {
    {
        { &lbl_803746E0, 0 }, // BaseObject_Z
        { &lbl_803746E8, 0 }, // ABC_Agent
        { &lbl_803746F0, 0 }, // Agent_Z
        { &lbl_803746F8, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B6BB0 = {
    {
        { &lbl_803746E0, 0 }, // BaseObject_Z
        { &lbl_803746E8, 0 }, // ABC_Agent
        { &lbl_803746F0, 0 }, // Agent_Z
        { &lbl_803746F8, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374700, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802B6BDC = {
    {
        { &lbl_803746E0, 0 }, // BaseObject_Z
        { &lbl_803746E8, 0 }, // ABC_Agent
        { &lbl_803746F0, 0 }, // Agent_Z
        { &lbl_803746F8, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374700, 0 }, // AnimatedAgent_Z
        { &lbl_80374708, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for LodAgent_Z.
NativeRuntimeBaseList<7> lbl_802B6C10 = {
    {
        { &lbl_803746E0, 0 }, // BaseObject_Z
        { &lbl_803746E8, 0 }, // ABC_Agent
        { &lbl_803746F0, 0 }, // Agent_Z
        { &lbl_803746F8, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374700, 0 }, // AnimatedAgent_Z
        { &lbl_80374708, 0 }, // MovingAgent_Z
        { &lbl_80374710, 0 }, // Throwable_Z
    }, 0
};

// Base hierarchy for CActorAgent.
NativeRuntimeBaseList<8> lbl_802B6C4C = {
    {
        { &lbl_803746E0, 0 }, // BaseObject_Z
        { &lbl_803746E8, 0 }, // ABC_Agent
        { &lbl_803746F0, 0 }, // Agent_Z
        { &lbl_803746F8, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374700, 0 }, // AnimatedAgent_Z
        { &lbl_80374708, 0 }, // MovingAgent_Z
        { &lbl_80374710, 0 }, // Throwable_Z
        { &lbl_80374718, 0 }, // LodAgent_Z
    }, 0
};

// Base hierarchy for CActorScriptAgent.
NativeRuntimeBaseList<10> lbl_802B6C90 = {
    {
        { &lbl_803746D8, 144 }, // CScriptAgent
        { &lbl_803746E0, 0 }, // BaseObject_Z
        { &lbl_803746E8, 0 }, // ABC_Agent
        { &lbl_803746F0, 0 }, // Agent_Z
        { &lbl_803746F8, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374700, 0 }, // AnimatedAgent_Z
        { &lbl_80374708, 0 }, // MovingAgent_Z
        { &lbl_80374710, 0 }, // Throwable_Z
        { &lbl_80374718, 0 }, // LodAgent_Z
        { &lbl_80374720, 0 }, // CActorAgent
    }, 0
};

// Base hierarchy for CSimpleAgent.
NativeRuntimeBaseList<11> lbl_802B6CE4 = {
    {
        { &lbl_803746D8, 144 }, // CScriptAgent
        { &lbl_803746E0, 0 }, // BaseObject_Z
        { &lbl_803746E8, 0 }, // ABC_Agent
        { &lbl_803746F0, 0 }, // Agent_Z
        { &lbl_803746F8, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374700, 0 }, // AnimatedAgent_Z
        { &lbl_80374708, 0 }, // MovingAgent_Z
        { &lbl_80374710, 0 }, // Throwable_Z
        { &lbl_80374718, 0 }, // LodAgent_Z
        { &lbl_80374720, 0 }, // CActorAgent
        { &lbl_80374728, 0 }, // CActorScriptAgent
    }, 0
};

}
