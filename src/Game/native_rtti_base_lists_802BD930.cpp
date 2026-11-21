#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802BD930 = {
    {
        { &lbl_803754BC, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802BD93C = {
    {
        { &lbl_803754BC, 0 }, // BaseObject_Z
        { &lbl_803754C4, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802BD950 = {
    {
        { &lbl_803754BC, 0 }, // BaseObject_Z
        { &lbl_803754C4, 0 }, // ABC_Agent
        { &lbl_803754CC, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802BD96C = {
    {
        { &lbl_803754BC, 0 }, // BaseObject_Z
        { &lbl_803754C4, 0 }, // ABC_Agent
        { &lbl_803754CC, 0 }, // Agent_Z
        { &lbl_803754D4, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802BD990 = {
    {
        { &lbl_803754BC, 0 }, // BaseObject_Z
        { &lbl_803754C4, 0 }, // ABC_Agent
        { &lbl_803754CC, 0 }, // Agent_Z
        { &lbl_803754D4, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803754DC, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802BD9BC = {
    {
        { &lbl_803754BC, 0 }, // BaseObject_Z
        { &lbl_803754C4, 0 }, // ABC_Agent
        { &lbl_803754CC, 0 }, // Agent_Z
        { &lbl_803754D4, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803754DC, 0 }, // AnimatedAgent_Z
        { &lbl_803754E4, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for LodAgent_Z.
NativeRuntimeBaseList<7> lbl_802BD9F0 = {
    {
        { &lbl_803754BC, 0 }, // BaseObject_Z
        { &lbl_803754C4, 0 }, // ABC_Agent
        { &lbl_803754CC, 0 }, // Agent_Z
        { &lbl_803754D4, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803754DC, 0 }, // AnimatedAgent_Z
        { &lbl_803754E4, 0 }, // MovingAgent_Z
        { &lbl_803754EC, 0 }, // Throwable_Z
    }, 0
};

// Base hierarchy for CActorAgent.
NativeRuntimeBaseList<8> lbl_802BDA2C = {
    {
        { &lbl_803754BC, 0 }, // BaseObject_Z
        { &lbl_803754C4, 0 }, // ABC_Agent
        { &lbl_803754CC, 0 }, // Agent_Z
        { &lbl_803754D4, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803754DC, 0 }, // AnimatedAgent_Z
        { &lbl_803754E4, 0 }, // MovingAgent_Z
        { &lbl_803754EC, 0 }, // Throwable_Z
        { &lbl_803754F4, 0 }, // LodAgent_Z
    }, 0
};

// Base hierarchy for CCollectableAgent.
NativeRuntimeBaseList<6> lbl_802BDA70 = {
    {
        { &lbl_803754BC, 0 }, // BaseObject_Z
        { &lbl_803754C4, 0 }, // ABC_Agent
        { &lbl_803754CC, 0 }, // Agent_Z
        { &lbl_803754D4, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803754DC, 0 }, // AnimatedAgent_Z
        { &lbl_803754E4, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for CBusTicketBase.
NativeRuntimeBaseList<7> lbl_802BDAA4 = {
    {
        { &lbl_803754BC, 0 }, // BaseObject_Z
        { &lbl_803754C4, 0 }, // ABC_Agent
        { &lbl_803754CC, 0 }, // Agent_Z
        { &lbl_803754D4, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803754DC, 0 }, // AnimatedAgent_Z
        { &lbl_803754E4, 0 }, // MovingAgent_Z
        { &lbl_80375504, 0 }, // CCollectableAgent
    }, 0
};

// Base hierarchy for BusTicket_CA.
NativeRuntimeBaseList<8> lbl_802BDAE0 = {
    {
        { &lbl_803754BC, 0 }, // BaseObject_Z
        { &lbl_803754C4, 0 }, // ABC_Agent
        { &lbl_803754CC, 0 }, // Agent_Z
        { &lbl_803754D4, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803754DC, 0 }, // AnimatedAgent_Z
        { &lbl_803754E4, 0 }, // MovingAgent_Z
        { &lbl_80375504, 0 }, // CCollectableAgent
        { &lbl_8037550C, 0 }, // CBusTicketBase
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
void fn_800BECC4();
void fn_800BED40();
void fn_800BED48();
void fn_800BED50();
void fn_800BEDE4();
void fn_800BEED4();
void fn_800C540C();
void fn_800C5560();
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

extern "C" __declspec(section ".data") const void* const lbl_802BDB24[33] __attribute__((aligned(4))) = {
    &lbl_80375514,
    0,
    (const void*)fn_800BECC4,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8002AE88,
    (const void*)fn_80259F0C,
    (const void*)fn_800BED40,
    (const void*)fn_800BED48,
    (const void*)fn_800BED50,
    (const void*)fn_800BEDE4,
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

