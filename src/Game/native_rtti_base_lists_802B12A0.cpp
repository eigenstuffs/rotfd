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
void fn_80023928();
void fn_8002392C();
void fn_80023934();
void fn_8002393C();
void fn_80023944();
void fn_80028D58();
void fn_80028D60();
void fn_80028D68();
void fn_80028D6C();
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

extern "C" __declspec(section ".data") const void* const lbl_802B139C[33] __attribute__((aligned(4))) = {
    &lbl_80374060,
    0,
    (const void*)fn_8002A848,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8002A8C4,
    (const void*)fn_80259F0C,
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
    (const void*)fn_8002AB04,
    (const void*)fn_8002ABAC,
};
