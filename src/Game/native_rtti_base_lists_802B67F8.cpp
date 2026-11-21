#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802B67F8 = {
    {
        { &lbl_80374680, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B6804 = {
    {
        { &lbl_80374680, 0 }, // BaseObject_Z
        { &lbl_80374688, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B6818 = {
    {
        { &lbl_80374680, 0 }, // BaseObject_Z
        { &lbl_80374688, 0 }, // ABC_Agent
        { &lbl_80374690, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B6834 = {
    {
        { &lbl_80374680, 0 }, // BaseObject_Z
        { &lbl_80374688, 0 }, // ABC_Agent
        { &lbl_80374690, 0 }, // Agent_Z
        { &lbl_80374698, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B6858 = {
    {
        { &lbl_80374680, 0 }, // BaseObject_Z
        { &lbl_80374688, 0 }, // ABC_Agent
        { &lbl_80374690, 0 }, // Agent_Z
        { &lbl_80374698, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803746A0, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802B6884 = {
    {
        { &lbl_80374680, 0 }, // BaseObject_Z
        { &lbl_80374688, 0 }, // ABC_Agent
        { &lbl_80374690, 0 }, // Agent_Z
        { &lbl_80374698, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803746A0, 0 }, // AnimatedAgent_Z
        { &lbl_803746A8, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for LodAgent_Z.
NativeRuntimeBaseList<7> lbl_802B68B8 = {
    {
        { &lbl_80374680, 0 }, // BaseObject_Z
        { &lbl_80374688, 0 }, // ABC_Agent
        { &lbl_80374690, 0 }, // Agent_Z
        { &lbl_80374698, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803746A0, 0 }, // AnimatedAgent_Z
        { &lbl_803746A8, 0 }, // MovingAgent_Z
        { &lbl_803746B0, 0 }, // Throwable_Z
    }, 0
};

// Base hierarchy for CActorAgent.
NativeRuntimeBaseList<8> lbl_802B68F4 = {
    {
        { &lbl_80374680, 0 }, // BaseObject_Z
        { &lbl_80374688, 0 }, // ABC_Agent
        { &lbl_80374690, 0 }, // Agent_Z
        { &lbl_80374698, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803746A0, 0 }, // AnimatedAgent_Z
        { &lbl_803746A8, 0 }, // MovingAgent_Z
        { &lbl_803746B0, 0 }, // Throwable_Z
        { &lbl_803746B8, 0 }, // LodAgent_Z
    }, 0
};

// Base hierarchy for CActorScriptAgent.
NativeRuntimeBaseList<10> lbl_802B6938 = {
    {
        { &lbl_80374678, 144 }, // CScriptAgent
        { &lbl_80374680, 0 }, // BaseObject_Z
        { &lbl_80374688, 0 }, // ABC_Agent
        { &lbl_80374690, 0 }, // Agent_Z
        { &lbl_80374698, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803746A0, 0 }, // AnimatedAgent_Z
        { &lbl_803746A8, 0 }, // MovingAgent_Z
        { &lbl_803746B0, 0 }, // Throwable_Z
        { &lbl_803746B8, 0 }, // LodAgent_Z
        { &lbl_803746C0, 0 }, // CActorAgent
    }, 0
};

// Base hierarchy for CMediumAgent.
NativeRuntimeBaseList<11> lbl_802B698C = {
    {
        { &lbl_80374678, 144 }, // CScriptAgent
        { &lbl_80374680, 0 }, // BaseObject_Z
        { &lbl_80374688, 0 }, // ABC_Agent
        { &lbl_80374690, 0 }, // Agent_Z
        { &lbl_80374698, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803746A0, 0 }, // AnimatedAgent_Z
        { &lbl_803746A8, 0 }, // MovingAgent_Z
        { &lbl_803746B0, 0 }, // Throwable_Z
        { &lbl_803746B8, 0 }, // LodAgent_Z
        { &lbl_803746C0, 0 }, // CActorAgent
        { &lbl_803746C8, 0 }, // CActorScriptAgent
    }, 0
};

}
