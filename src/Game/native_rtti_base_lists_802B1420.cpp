#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802B1420 = {
    {
        { &lbl_80374068, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B142C = {
    {
        { &lbl_80374068, 0 }, // BaseObject_Z
        { &lbl_80374070, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B1440 = {
    {
        { &lbl_80374068, 0 }, // BaseObject_Z
        { &lbl_80374070, 0 }, // ABC_Agent
        { &lbl_80374078, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B145C = {
    {
        { &lbl_80374068, 0 }, // BaseObject_Z
        { &lbl_80374070, 0 }, // ABC_Agent
        { &lbl_80374078, 0 }, // Agent_Z
        { &lbl_80374080, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B1480 = {
    {
        { &lbl_80374068, 0 }, // BaseObject_Z
        { &lbl_80374070, 0 }, // ABC_Agent
        { &lbl_80374078, 0 }, // Agent_Z
        { &lbl_80374080, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374088, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for CCollectableAgent.
NativeRuntimeBaseList<6> lbl_802B14AC = {
    {
        { &lbl_80374068, 0 }, // BaseObject_Z
        { &lbl_80374070, 0 }, // ABC_Agent
        { &lbl_80374078, 0 }, // Agent_Z
        { &lbl_80374080, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374088, 0 }, // AnimatedAgent_Z
        { &lbl_80374090, 0 }, // MovingAgent_Z
    }, 0
};

}

// Adjacent collectable-agent method records.
extern "C" {
void fn_80022A84();
void slot74__15AnimatedAgent_ZFv();
void slot48__7Agent_ZFv();
void slot4C__7Agent_ZFv();
void slot50__7Agent_ZFv();
void slot70__7Agent_ZFv();
void slot54__7Agent_ZFv();
void slot58__7Agent_ZFv();
void slot5C__7Agent_ZFv();
void slot60__7Agent_ZFv();
void fn_8002AE0C();
void fn_8002AE88();
void fn_8002AF38();
void fn_8002AF3C();
void fn_8002B0A8();
void fn_8002B450();
void fn_8002B458();
void fn_8002B460();
void fn_8002B4D4();
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

extern "C" __declspec(section ".data") const void* const lbl_802B14E0[34] __attribute__((aligned(4))) = {
    &lbl_80374098,
    0,
    (const void*)fn_8002AE0C,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8002AE88,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_8002B450,
    (const void*)fn_8002B458,
    (const void*)fn_8002B460,
    (const void*)fn_8002B4D4,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_8002AF38,
    (const void*)fn_8025A324,
    (const void*)fn_8002AF3C,
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
    (const void*)fn_8002B0A8,
    (const void*)fn_80022A84,
    0,
};

extern "C" __declspec(section ".data") const unsigned int lbl_802B1568[18] __attribute__((aligned(4))) = {
    0x00000000,
    0x000000AC,
    0x00000008,
    0x00000000,
    0x000000AC,
    0x00000008,
    0x00000000,
    0x000000AC,
    0x00000008,
    0x00000000,
    0x000000AC,
    0x00000008,
    0x00000000,
    0x000000AC,
    0x00000008,
    0x00000000,
    0x000000AC,
    0x00000008,
};
