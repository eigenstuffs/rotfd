#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802BFA80 = {
    {
        { &lbl_80375760, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802BFA8C = {
    {
        { &lbl_80375760, 0 }, // BaseObject_Z
        { &lbl_80375768, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802BFAA0 = {
    {
        { &lbl_80375760, 0 }, // BaseObject_Z
        { &lbl_80375768, 0 }, // ABC_Agent
        { &lbl_80375770, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802BFABC = {
    {
        { &lbl_80375760, 0 }, // BaseObject_Z
        { &lbl_80375768, 0 }, // ABC_Agent
        { &lbl_80375770, 0 }, // Agent_Z
        { &lbl_80375778, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802BFAE0 = {
    {
        { &lbl_80375760, 0 }, // BaseObject_Z
        { &lbl_80375768, 0 }, // ABC_Agent
        { &lbl_80375770, 0 }, // Agent_Z
        { &lbl_80375778, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375780, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for CCollectableAgent.
NativeRuntimeBaseList<6> lbl_802BFB0C = {
    {
        { &lbl_80375760, 0 }, // BaseObject_Z
        { &lbl_80375768, 0 }, // ABC_Agent
        { &lbl_80375770, 0 }, // Agent_Z
        { &lbl_80375778, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375780, 0 }, // AnimatedAgent_Z
        { &lbl_80375788, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for EvilSpellBook.
NativeRuntimeBaseList<7> lbl_802BFB40 = {
    {
        { &lbl_80375760, 0 }, // BaseObject_Z
        { &lbl_80375768, 0 }, // ABC_Agent
        { &lbl_80375770, 0 }, // Agent_Z
        { &lbl_80375778, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80375780, 0 }, // AnimatedAgent_Z
        { &lbl_80375788, 0 }, // MovingAgent_Z
        { &lbl_80375790, 0 }, // CCollectableAgent
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
void fn_800C4FB8();
void fn_800C5034();
void fn_800C5188();
void fn_800C51A8();
void fn_800C51B0();
void fn_800C51B8();
void fn_800C523C();
void fn_800C5310();
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

extern "C" __declspec(section ".data") const void* const lbl_802BFB7C[33] __attribute__((aligned(4))) = {
    &lbl_80375798,
    0,
    (const void*)fn_800C4FB8,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8002AE88,
    (const void*)fn_80259F0C,
    (const void*)fn_800C51A8,
    (const void*)fn_800C51B0,
    (const void*)fn_800C51B8,
    (const void*)fn_800C523C,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_8002AF38,
    (const void*)fn_8025A324,
    (const void*)fn_800C5034,
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
    (const void*)fn_800C5188,
    (const void*)fn_800C5310,
};

