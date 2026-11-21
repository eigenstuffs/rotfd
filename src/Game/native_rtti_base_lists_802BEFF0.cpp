#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802BEFF0 = {
    {
        { &lbl_803755E8, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802BEFFC = {
    {
        { &lbl_803755E8, 0 }, // BaseObject_Z
        { &lbl_803755F0, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802BF010 = {
    {
        { &lbl_803755E8, 0 }, // BaseObject_Z
        { &lbl_803755F0, 0 }, // ABC_Agent
        { &lbl_803755F8, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802BF02C = {
    {
        { &lbl_803755E8, 0 }, // BaseObject_Z
        { &lbl_803755F0, 0 }, // ABC_Agent
        { &lbl_803755F8, 0 }, // Agent_Z
        { &lbl_80375600, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802BF050 = {
    {
        { &lbl_803755E8, 0 }, // BaseObject_Z
        { &lbl_803755F0, 0 }, // ABC_Agent
        { &lbl_803755F8, 0 }, // Agent_Z
        { &lbl_80375600, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375608, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for CCollectableAgent.
NativeRuntimeBaseList<6> lbl_802BF07C = {
    {
        { &lbl_803755E8, 0 }, // BaseObject_Z
        { &lbl_803755F0, 0 }, // ABC_Agent
        { &lbl_803755F8, 0 }, // Agent_Z
        { &lbl_80375600, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375608, 0 }, // AnimatedAgent_Z
        { &lbl_80375610, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for ExtraHealth.
NativeRuntimeBaseList<7> lbl_802BF0B0 = {
    {
        { &lbl_803755E8, 0 }, // BaseObject_Z
        { &lbl_803755F0, 0 }, // ABC_Agent
        { &lbl_803755F8, 0 }, // Agent_Z
        { &lbl_80375600, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375608, 0 }, // AnimatedAgent_Z
        { &lbl_80375610, 0 }, // MovingAgent_Z
        { &lbl_80375618, 0 }, // CCollectableAgent
    }, 0
};

}

// Adjacent native method and member-pointer records.

extern "C" {
void fn_80023928();
void fn_8002392C();
void fn_80023934();
void fn_8002393C();
void fn_80023944();
void fn_80028D58();
void fn_80028D60();
void fn_80028D68();
void fn_80028D6C();
void fn_800C0F58();
void fn_800C0FD4();
void fn_800C0FF4();
void fn_800C0FF8();
void fn_800C10BC();
void fn_800C12E0();
void fn_800C12E8();
void fn_800C12F0();
void fn_800C1374();
void fn_800C1448();
void fn_80256028();
void fn_80257C50();
void fn_80257C58();
void fn_80259F0C();
void fn_80259FB4();
void fn_8025A190();
void fn_8025A244();
void fn_8025A324();
void fn_8025A5F8();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802BF0EC[33] __attribute__((aligned(4))) = {
    &lbl_80375620,
    0,
    (const void*)fn_800C0F58,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800C0FD4,
    (const void*)fn_80259F0C,
    (const void*)fn_800C12E0,
    (const void*)fn_800C12E8,
    (const void*)fn_800C12F0,
    (const void*)fn_800C1374,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_800C0FF4,
    (const void*)fn_8025A324,
    (const void*)fn_800C0FF8,
    (const void*)fn_80259FB4,
    (const void*)fn_8002392C,
    (const void*)fn_80023934,
    (const void*)fn_8002393C,
    (const void*)fn_80028D58,
    (const void*)fn_80028D60,
    (const void*)fn_80028D68,
    (const void*)fn_80028D6C,
    (const void*)fn_80257C58,
    (const void*)fn_80257C50,
    (const void*)fn_80256028,
    (const void*)fn_80023944,
    (const void*)fn_80023928,
    (const void*)fn_8025A5F8,
    (const void*)fn_800C10BC,
    (const void*)fn_800C1448,
};

