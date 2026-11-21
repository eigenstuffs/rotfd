#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802BFC00 = {
    {
        { &lbl_803757A0, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802BFC0C = {
    {
        { &lbl_803757A0, 0 }, // BaseObject_Z
        { &lbl_803757A8, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802BFC20 = {
    {
        { &lbl_803757A0, 0 }, // BaseObject_Z
        { &lbl_803757A8, 0 }, // ABC_Agent
        { &lbl_803757B0, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802BFC3C = {
    {
        { &lbl_803757A0, 0 }, // BaseObject_Z
        { &lbl_803757A8, 0 }, // ABC_Agent
        { &lbl_803757B0, 0 }, // Agent_Z
        { &lbl_803757B8, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802BFC60 = {
    {
        { &lbl_803757A0, 0 }, // BaseObject_Z
        { &lbl_803757A8, 0 }, // ABC_Agent
        { &lbl_803757B0, 0 }, // Agent_Z
        { &lbl_803757B8, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803757C0, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for CCollectableAgent.
NativeRuntimeBaseList<6> lbl_802BFC8C = {
    {
        { &lbl_803757A0, 0 }, // BaseObject_Z
        { &lbl_803757A8, 0 }, // ABC_Agent
        { &lbl_803757B0, 0 }, // Agent_Z
        { &lbl_803757B8, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803757C0, 0 }, // AnimatedAgent_Z
        { &lbl_803757C8, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for CBusTicketBase.
NativeRuntimeBaseList<7> lbl_802BFCC0 = {
    {
        { &lbl_803757A0, 0 }, // BaseObject_Z
        { &lbl_803757A8, 0 }, // ABC_Agent
        { &lbl_803757B0, 0 }, // Agent_Z
        { &lbl_803757B8, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803757C0, 0 }, // AnimatedAgent_Z
        { &lbl_803757C8, 0 }, // MovingAgent_Z
        { &lbl_803757D0, 0 }, // CCollectableAgent
    }, 0
};

}

// Adjacent native method and runtime-base records.
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
void fn_8002AE88();
void fn_8002AF38();
void fn_800BEED4();
void fn_800C5390();
void fn_800C540C();
void fn_800C5560();
void fn_800C5790();
void fn_800C5798();
void fn_800C57A0();
void fn_800C5824();
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

extern "C" __declspec(section ".data") const void* const lbl_802BFCFC[33] __attribute__((aligned(4))) = {
    &lbl_803757D8,
    0,
    (const void*)fn_800C5390,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8002AE88,
    (const void*)fn_80259F0C,
    (const void*)fn_800C5790,
    (const void*)fn_800C5798,
    (const void*)fn_800C57A0,
    (const void*)fn_800C5824,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_8002AF38,
    (const void*)fn_8025A324,
    (const void*)fn_800C540C,
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
    (const void*)fn_800C5560,
    (const void*)fn_800BEED4,
};

