#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802B5CE0 = {
    {
        { &lbl_80374560, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B5CEC = {
    {
        { &lbl_80374560, 0 }, // BaseObject_Z
        { &lbl_80374568, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B5D00 = {
    {
        { &lbl_80374560, 0 }, // BaseObject_Z
        { &lbl_80374568, 0 }, // ABC_Agent
        { &lbl_80374570, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B5D1C = {
    {
        { &lbl_80374560, 0 }, // BaseObject_Z
        { &lbl_80374568, 0 }, // ABC_Agent
        { &lbl_80374570, 0 }, // Agent_Z
        { &lbl_80374578, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B5D40 = {
    {
        { &lbl_80374560, 0 }, // BaseObject_Z
        { &lbl_80374568, 0 }, // ABC_Agent
        { &lbl_80374570, 0 }, // Agent_Z
        { &lbl_80374578, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374580, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802B5D6C = {
    {
        { &lbl_80374560, 0 }, // BaseObject_Z
        { &lbl_80374568, 0 }, // ABC_Agent
        { &lbl_80374570, 0 }, // Agent_Z
        { &lbl_80374578, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374580, 0 }, // AnimatedAgent_Z
        { &lbl_80374588, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for LodAgent_Z.
NativeRuntimeBaseList<7> lbl_802B5DA0 = {
    {
        { &lbl_80374560, 0 }, // BaseObject_Z
        { &lbl_80374568, 0 }, // ABC_Agent
        { &lbl_80374570, 0 }, // Agent_Z
        { &lbl_80374578, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374580, 0 }, // AnimatedAgent_Z
        { &lbl_80374588, 0 }, // MovingAgent_Z
        { &lbl_80374590, 0 }, // Throwable_Z
    }, 0
};

// Base hierarchy for CActorAgent.
NativeRuntimeBaseList<8> lbl_802B5DDC = {
    {
        { &lbl_80374560, 0 }, // BaseObject_Z
        { &lbl_80374568, 0 }, // ABC_Agent
        { &lbl_80374570, 0 }, // Agent_Z
        { &lbl_80374578, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374580, 0 }, // AnimatedAgent_Z
        { &lbl_80374588, 0 }, // MovingAgent_Z
        { &lbl_80374590, 0 }, // Throwable_Z
        { &lbl_80374598, 0 }, // LodAgent_Z
    }, 0
};

// Base hierarchy for CWildSnailBaseAgent.
NativeRuntimeBaseList<9> lbl_802B5E20 = {
    {
        { &lbl_80374560, 0 }, // BaseObject_Z
        { &lbl_80374568, 0 }, // ABC_Agent
        { &lbl_80374570, 0 }, // Agent_Z
        { &lbl_80374578, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374580, 0 }, // AnimatedAgent_Z
        { &lbl_80374588, 0 }, // MovingAgent_Z
        { &lbl_80374590, 0 }, // Throwable_Z
        { &lbl_80374598, 0 }, // LodAgent_Z
        { &lbl_803745A0, 0 }, // CActorAgent
    }, 0
};

// Base hierarchy for SnailA.
NativeRuntimeBaseList<10> lbl_802B5E6C = {
    {
        { &lbl_80374560, 0 }, // BaseObject_Z
        { &lbl_80374568, 0 }, // ABC_Agent
        { &lbl_80374570, 0 }, // Agent_Z
        { &lbl_80374578, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374580, 0 }, // AnimatedAgent_Z
        { &lbl_80374588, 0 }, // MovingAgent_Z
        { &lbl_80374590, 0 }, // Throwable_Z
        { &lbl_80374598, 0 }, // LodAgent_Z
        { &lbl_803745A0, 0 }, // CActorAgent
        { &lbl_803745A8, 0 }, // CWildSnailBaseAgent
    }, 0
};

}
