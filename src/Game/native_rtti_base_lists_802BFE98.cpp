#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802BFE98 = {
    {
        { &lbl_80375800, 0 }, // BaseObject_Z
        { &lbl_80375808, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802BFEAC = {
    {
        { &lbl_80375800, 0 }, // BaseObject_Z
        { &lbl_80375808, 0 }, // ABC_Agent
        { &lbl_80375810, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802BFEC8 = {
    {
        { &lbl_80375800, 0 }, // BaseObject_Z
        { &lbl_80375808, 0 }, // ABC_Agent
        { &lbl_80375810, 0 }, // Agent_Z
        { &lbl_80375818, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802BFEEC = {
    {
        { &lbl_80375800, 0 }, // BaseObject_Z
        { &lbl_80375808, 0 }, // ABC_Agent
        { &lbl_80375810, 0 }, // Agent_Z
        { &lbl_80375818, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375820, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802BFF18 = {
    {
        { &lbl_80375800, 0 }, // BaseObject_Z
        { &lbl_80375808, 0 }, // ABC_Agent
        { &lbl_80375810, 0 }, // Agent_Z
        { &lbl_80375818, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375820, 0 }, // AnimatedAgent_Z
        { &lbl_80375828, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for LodAgent_Z.
NativeRuntimeBaseList<7> lbl_802BFF4C = {
    {
        { &lbl_80375800, 0 }, // BaseObject_Z
        { &lbl_80375808, 0 }, // ABC_Agent
        { &lbl_80375810, 0 }, // Agent_Z
        { &lbl_80375818, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375820, 0 }, // AnimatedAgent_Z
        { &lbl_80375828, 0 }, // MovingAgent_Z
        { &lbl_80375830, 0 }, // Throwable_Z
    }, 0
};

// Base hierarchy for CActorAgent.
NativeRuntimeBaseList<8> lbl_802BFF88 = {
    {
        { &lbl_80375800, 0 }, // BaseObject_Z
        { &lbl_80375808, 0 }, // ABC_Agent
        { &lbl_80375810, 0 }, // Agent_Z
        { &lbl_80375818, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375820, 0 }, // AnimatedAgent_Z
        { &lbl_80375828, 0 }, // MovingAgent_Z
        { &lbl_80375830, 0 }, // Throwable_Z
        { &lbl_80375838, 0 }, // LodAgent_Z
    }, 0
};

// Base hierarchy for CRBObjBaseAgent.
NativeRuntimeBaseList<9> lbl_802BFFCC = {
    {
        { &lbl_80375800, 0 }, // BaseObject_Z
        { &lbl_80375808, 0 }, // ABC_Agent
        { &lbl_80375810, 0 }, // Agent_Z
        { &lbl_80375818, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375820, 0 }, // AnimatedAgent_Z
        { &lbl_80375828, 0 }, // MovingAgent_Z
        { &lbl_80375830, 0 }, // Throwable_Z
        { &lbl_80375838, 0 }, // LodAgent_Z
        { &lbl_80375840, 0 }, // CActorAgent
    }, 0
};

}
