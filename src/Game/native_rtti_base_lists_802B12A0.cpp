#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802B12A0 = {
    {
        { &lbl_80374028, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B12AC = {
    {
        { &lbl_80374028, 0 }, // BaseObject_Z
        { &lbl_80374030, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B12C0 = {
    {
        { &lbl_80374028, 0 }, // BaseObject_Z
        { &lbl_80374030, 0 }, // ABC_Agent
        { &lbl_80374038, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B12DC = {
    {
        { &lbl_80374028, 0 }, // BaseObject_Z
        { &lbl_80374030, 0 }, // ABC_Agent
        { &lbl_80374038, 0 }, // Agent_Z
        { &lbl_80374040, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B1300 = {
    {
        { &lbl_80374028, 0 }, // BaseObject_Z
        { &lbl_80374030, 0 }, // ABC_Agent
        { &lbl_80374038, 0 }, // Agent_Z
        { &lbl_80374040, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374048, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for CCollectableAgent.
NativeRuntimeBaseList<6> lbl_802B132C = {
    {
        { &lbl_80374028, 0 }, // BaseObject_Z
        { &lbl_80374030, 0 }, // ABC_Agent
        { &lbl_80374038, 0 }, // Agent_Z
        { &lbl_80374040, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374048, 0 }, // AnimatedAgent_Z
        { &lbl_80374050, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for KPatty.
NativeRuntimeBaseList<7> lbl_802B1360 = {
    {
        { &lbl_80374028, 0 }, // BaseObject_Z
        { &lbl_80374030, 0 }, // ABC_Agent
        { &lbl_80374038, 0 }, // Agent_Z
        { &lbl_80374040, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374048, 0 }, // AnimatedAgent_Z
        { &lbl_80374050, 0 }, // MovingAgent_Z
        { &lbl_80374058, 0 }, // CCollectableAgent
    }, 0
};

}

// Adjacent collectable-agent method records.
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
void fn_8002A848();
void fn_8002A8C4();
void fn_8002A8FC();
void fn_8002A900();
void fn_8002AB04();
void fn_8002ABAC();
void fn_8002ABF4();
void fn_8002ABFC();
void fn_8002AC04();
void fn_8002AC88();
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

extern "C" __declspec(section ".data") const void* const lbl_802B139C[33] __attribute__((aligned(4))) = {
    &lbl_80374060,
    0,
    (const void*)fn_8002A848,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8002A8C4,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_8002ABF4,
    (const void*)fn_8002ABFC,
    (const void*)fn_8002AC04,
    (const void*)fn_8002AC88,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_8002A8FC,
    (const void*)fn_8025A324,
    (const void*)fn_8002A900,
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
    (const void*)fn_8002AB04,
    (const void*)fn_8002ABAC,
};
