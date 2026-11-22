#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802C8470 = {
    {
        { &lbl_80375A28, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802C847C = {
    {
        { &lbl_80375A28, 0 }, // BaseObject_Z
        { &lbl_80375A30, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802C8490 = {
    {
        { &lbl_80375A28, 0 }, // BaseObject_Z
        { &lbl_80375A30, 0 }, // ABC_Agent
        { &lbl_80375A38, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802C84AC = {
    {
        { &lbl_80375A28, 0 }, // BaseObject_Z
        { &lbl_80375A30, 0 }, // ABC_Agent
        { &lbl_80375A38, 0 }, // Agent_Z
        { &lbl_80375A40, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802C84D0 = {
    {
        { &lbl_80375A28, 0 }, // BaseObject_Z
        { &lbl_80375A30, 0 }, // ABC_Agent
        { &lbl_80375A38, 0 }, // Agent_Z
        { &lbl_80375A40, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375A48, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for WaterHelmet.
NativeRuntimeBaseList<6> lbl_802C84FC = {
    {
        { &lbl_80375A28, 0 }, // BaseObject_Z
        { &lbl_80375A30, 0 }, // ABC_Agent
        { &lbl_80375A38, 0 }, // Agent_Z
        { &lbl_80375A40, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375A48, 0 }, // AnimatedAgent_Z
        { &lbl_80375A50, 0 }, // MovingAgent_Z
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
void fn_800E1378();
void fn_800E13F4();
void fn_800E1478();
void fn_800E1498();
void fn_800E15F0();
void fn_800E15F8();
void fn_800E1600();
void fn_800E1674();
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

extern "C" __declspec(section ".data") const void* const lbl_802C8530[32] __attribute__((aligned(4))) = {
    &lbl_80375A58,
    0,
    (const void*)fn_800E1378,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800E13F4,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_800E15F0,
    (const void*)fn_800E15F8,
    (const void*)fn_800E1600,
    (const void*)fn_800E1674,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_800E1478,
    (const void*)fn_8025A324,
    (const void*)fn_800E1498,
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
    0,
};

