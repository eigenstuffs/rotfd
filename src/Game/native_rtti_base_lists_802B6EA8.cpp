#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802B6EA8 = {
    {
        { &lbl_80374740, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B6EB4 = {
    {
        { &lbl_80374740, 0 }, // BaseObject_Z
        { &lbl_80374748, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B6EC8 = {
    {
        { &lbl_80374740, 0 }, // BaseObject_Z
        { &lbl_80374748, 0 }, // ABC_Agent
        { &lbl_80374750, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B6EE4 = {
    {
        { &lbl_80374740, 0 }, // BaseObject_Z
        { &lbl_80374748, 0 }, // ABC_Agent
        { &lbl_80374750, 0 }, // Agent_Z
        { &lbl_80374758, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B6F08 = {
    {
        { &lbl_80374740, 0 }, // BaseObject_Z
        { &lbl_80374748, 0 }, // ABC_Agent
        { &lbl_80374750, 0 }, // Agent_Z
        { &lbl_80374758, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374760, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802B6F34 = {
    {
        { &lbl_80374740, 0 }, // BaseObject_Z
        { &lbl_80374748, 0 }, // ABC_Agent
        { &lbl_80374750, 0 }, // Agent_Z
        { &lbl_80374758, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374760, 0 }, // AnimatedAgent_Z
        { &lbl_80374768, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for LodAgent_Z.
NativeRuntimeBaseList<7> lbl_802B6F68 = {
    {
        { &lbl_80374740, 0 }, // BaseObject_Z
        { &lbl_80374748, 0 }, // ABC_Agent
        { &lbl_80374750, 0 }, // Agent_Z
        { &lbl_80374758, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374760, 0 }, // AnimatedAgent_Z
        { &lbl_80374768, 0 }, // MovingAgent_Z
        { &lbl_80374770, 0 }, // Throwable_Z
    }, 0
};

// Base hierarchy for CActorAgent.
NativeRuntimeBaseList<8> lbl_802B6FA4 = {
    {
        { &lbl_80374740, 0 }, // BaseObject_Z
        { &lbl_80374748, 0 }, // ABC_Agent
        { &lbl_80374750, 0 }, // Agent_Z
        { &lbl_80374758, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374760, 0 }, // AnimatedAgent_Z
        { &lbl_80374768, 0 }, // MovingAgent_Z
        { &lbl_80374770, 0 }, // Throwable_Z
        { &lbl_80374778, 0 }, // LodAgent_Z
    }, 0
};

// Base hierarchy for CActorScriptAgent.
NativeRuntimeBaseList<10> lbl_802B6FE8 = {
    {
        { &lbl_80374738, 144 }, // CScriptAgent
        { &lbl_80374740, 0 }, // BaseObject_Z
        { &lbl_80374748, 0 }, // ABC_Agent
        { &lbl_80374750, 0 }, // Agent_Z
        { &lbl_80374758, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374760, 0 }, // AnimatedAgent_Z
        { &lbl_80374768, 0 }, // MovingAgent_Z
        { &lbl_80374770, 0 }, // Throwable_Z
        { &lbl_80374778, 0 }, // LodAgent_Z
        { &lbl_80374780, 0 }, // CActorAgent
    }, 0
};

// Base hierarchy for CComplexAgent.
NativeRuntimeBaseList<11> lbl_802B703C = {
    {
        { &lbl_80374738, 144 }, // CScriptAgent
        { &lbl_80374740, 0 }, // BaseObject_Z
        { &lbl_80374748, 0 }, // ABC_Agent
        { &lbl_80374750, 0 }, // Agent_Z
        { &lbl_80374758, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374760, 0 }, // AnimatedAgent_Z
        { &lbl_80374768, 0 }, // MovingAgent_Z
        { &lbl_80374770, 0 }, // Throwable_Z
        { &lbl_80374778, 0 }, // LodAgent_Z
        { &lbl_80374780, 0 }, // CActorAgent
        { &lbl_80374788, 0 }, // CActorScriptAgent
    }, 0
};

}
