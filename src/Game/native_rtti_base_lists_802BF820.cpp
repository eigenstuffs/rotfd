#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802BF820 = {
    {
        { &lbl_803756F8, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802BF82C = {
    {
        { &lbl_803756F8, 0 }, // BaseObject_Z
        { &lbl_80375700, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802BF840 = {
    {
        { &lbl_803756F8, 0 }, // BaseObject_Z
        { &lbl_80375700, 0 }, // ABC_Agent
        { &lbl_80375708, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802BF85C = {
    {
        { &lbl_803756F8, 0 }, // BaseObject_Z
        { &lbl_80375700, 0 }, // ABC_Agent
        { &lbl_80375708, 0 }, // Agent_Z
        { &lbl_80375710, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802BF880 = {
    {
        { &lbl_803756F8, 0 }, // BaseObject_Z
        { &lbl_80375700, 0 }, // ABC_Agent
        { &lbl_80375708, 0 }, // Agent_Z
        { &lbl_80375710, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375718, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for CCollectableAgent.
NativeRuntimeBaseList<6> lbl_802BF8AC = {
    {
        { &lbl_803756F8, 0 }, // BaseObject_Z
        { &lbl_80375700, 0 }, // ABC_Agent
        { &lbl_80375708, 0 }, // Agent_Z
        { &lbl_80375710, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375718, 0 }, // AnimatedAgent_Z
        { &lbl_80375720, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for SandDollar.
NativeRuntimeBaseList<7> lbl_802BF8E0 = {
    {
        { &lbl_803756F8, 0 }, // BaseObject_Z
        { &lbl_80375700, 0 }, // ABC_Agent
        { &lbl_80375708, 0 }, // Agent_Z
        { &lbl_80375710, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375718, 0 }, // AnimatedAgent_Z
        { &lbl_80375720, 0 }, // MovingAgent_Z
        { &lbl_80375728, 0 }, // CCollectableAgent
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void slot74__15AnimatedAgent_ZFv();
void slot48__7Agent_ZFv();
void slot4C__7Agent_ZFv();
void slot50__7Agent_ZFv();
void slot70__7Agent_ZFv();
void slot54__7Agent_ZFv();
void slot58__7Agent_ZFv();
void slot5C__7Agent_ZFv();
void slot60__7Agent_ZFv();
void fn_800C474C();
void fn_800C47C8();
void fn_800C47E8();
void fn_800C47EC();
void fn_800C4984();
void fn_800C4A74();
void fn_800C4A7C();
void fn_800C4A84();
void fn_800C4B08();
void fn_800C4BDC();
void slot6C__7Agent_ZFv();
void slot68__15AnimatedAgent_ZFv();
void slot64__15AnimatedAgent_ZFv();
void slot1C__13MovingAgent_ZFv();
void fn_80259FB4();
void fn_8025A190();
void fn_8025A244();
void fn_8025A324();
void slot78__13MovingAgent_ZFv();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802BF91C[33] __attribute__((aligned(4))) = {
    &lbl_80375730,
    0,
    (const void*)fn_800C474C,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800C47C8,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_800C4A74,
    (const void*)fn_800C4A7C,
    (const void*)fn_800C4A84,
    (const void*)fn_800C4B08,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_800C47E8,
    (const void*)fn_8025A324,
    (const void*)fn_800C47EC,
    (const void*)fn_80259FB4,
    (const void*)slot48__7Agent_ZFv,
    (const void*)slot4C__7Agent_ZFv,
    (const void*)slot50__7Agent_ZFv,
    (const void*)slot54__7Agent_ZFv,
    (const void*)slot58__7Agent_ZFv,
    (const void*)slot5C__7Agent_ZFv,
    (const void*)slot60__7Agent_ZFv,
    (const void*)slot64__15AnimatedAgent_ZFv,
    (const void*)slot68__15AnimatedAgent_ZFv,
    (const void*)slot6C__7Agent_ZFv,
    (const void*)slot70__7Agent_ZFv,
    (const void*)slot74__15AnimatedAgent_ZFv,
    (const void*)slot78__13MovingAgent_ZFv,
    (const void*)fn_800C4984,
    (const void*)fn_800C4BDC,
};

