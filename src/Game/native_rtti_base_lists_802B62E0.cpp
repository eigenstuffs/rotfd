#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B62E0 = {
    {
        { &lbl_803745F0, 0 }, // BaseObject_Z
        { &lbl_803745F8, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B62F4 = {
    {
        { &lbl_803745F0, 0 }, // BaseObject_Z
        { &lbl_803745F8, 0 }, // ABC_Agent
        { &lbl_80374600, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B6310 = {
    {
        { &lbl_803745F0, 0 }, // BaseObject_Z
        { &lbl_803745F8, 0 }, // ABC_Agent
        { &lbl_80374600, 0 }, // Agent_Z
        { &lbl_80374608, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B6334 = {
    {
        { &lbl_803745F0, 0 }, // BaseObject_Z
        { &lbl_803745F8, 0 }, // ABC_Agent
        { &lbl_80374600, 0 }, // Agent_Z
        { &lbl_80374608, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374610, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802B6360 = {
    {
        { &lbl_803745F0, 0 }, // BaseObject_Z
        { &lbl_803745F8, 0 }, // ABC_Agent
        { &lbl_80374600, 0 }, // Agent_Z
        { &lbl_80374608, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374610, 0 }, // AnimatedAgent_Z
        { &lbl_80374618, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for LodAgent_Z.
NativeRuntimeBaseList<7> lbl_802B6394 = {
    {
        { &lbl_803745F0, 0 }, // BaseObject_Z
        { &lbl_803745F8, 0 }, // ABC_Agent
        { &lbl_80374600, 0 }, // Agent_Z
        { &lbl_80374608, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374610, 0 }, // AnimatedAgent_Z
        { &lbl_80374618, 0 }, // MovingAgent_Z
        { &lbl_80374620, 0 }, // Throwable_Z
    }, 0
};

// Base hierarchy for CActorAgent.
NativeRuntimeBaseList<8> lbl_802B63D0 = {
    {
        { &lbl_803745F0, 0 }, // BaseObject_Z
        { &lbl_803745F8, 0 }, // ABC_Agent
        { &lbl_80374600, 0 }, // Agent_Z
        { &lbl_80374608, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374610, 0 }, // AnimatedAgent_Z
        { &lbl_80374618, 0 }, // MovingAgent_Z
        { &lbl_80374620, 0 }, // Throwable_Z
        { &lbl_80374628, 0 }, // LodAgent_Z
    }, 0
};

// Base hierarchy for CActorScriptAgent.
NativeRuntimeBaseList<10> lbl_802B6414 = {
    {
        { &lbl_803745E8, 144 }, // CScriptAgent
        { &lbl_803745F0, 0 }, // BaseObject_Z
        { &lbl_803745F8, 0 }, // ABC_Agent
        { &lbl_80374600, 0 }, // Agent_Z
        { &lbl_80374608, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374610, 0 }, // AnimatedAgent_Z
        { &lbl_80374618, 0 }, // MovingAgent_Z
        { &lbl_80374620, 0 }, // Throwable_Z
        { &lbl_80374628, 0 }, // LodAgent_Z
        { &lbl_80374630, 0 }, // CActorAgent
    }, 0
};

}
