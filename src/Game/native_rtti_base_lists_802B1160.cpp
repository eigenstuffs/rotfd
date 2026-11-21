#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802B1160 = {
    {
        { &lbl_80373FF0, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B116C = {
    {
        { &lbl_80373FF0, 0 }, // BaseObject_Z
        { &lbl_80373FF8, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B1180 = {
    {
        { &lbl_80373FF0, 0 }, // BaseObject_Z
        { &lbl_80373FF8, 0 }, // ABC_Agent
        { &lbl_80374000, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B119C = {
    {
        { &lbl_80373FF0, 0 }, // BaseObject_Z
        { &lbl_80373FF8, 0 }, // ABC_Agent
        { &lbl_80374000, 0 }, // Agent_Z
        { &lbl_80374008, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B11C0 = {
    {
        { &lbl_80373FF0, 0 }, // BaseObject_Z
        { &lbl_80373FF8, 0 }, // ABC_Agent
        { &lbl_80374000, 0 }, // Agent_Z
        { &lbl_80374008, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374010, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Tchest.
NativeRuntimeBaseList<6> lbl_802B11EC = {
    {
        { &lbl_80373FF0, 0 }, // BaseObject_Z
        { &lbl_80373FF8, 0 }, // ABC_Agent
        { &lbl_80374000, 0 }, // Agent_Z
        { &lbl_80374008, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374010, 0 }, // AnimatedAgent_Z
        { &lbl_80374018, 0 }, // MovingAgent_Z
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
void fn_8002A050();
void fn_8002A0CC();
void fn_8002A160();
void fn_8002A164();
void fn_8002A54C();
void fn_8002A694();
void fn_8002A69C();
void fn_8002A6A4();
void fn_8002A718();
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

extern "C" __declspec(section ".data") const void* const lbl_802B1220[32] __attribute__((aligned(4))) = {
    &lbl_80374020,
    0,
    (const void*)fn_8002A050,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8002A0CC,
    (const void*)fn_80259F0C,
    (const void*)fn_8002A694,
    (const void*)fn_8002A69C,
    (const void*)fn_8002A6A4,
    (const void*)fn_8002A718,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_8002A160,
    (const void*)fn_8025A324,
    (const void*)fn_8002A164,
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
    (const void*)fn_8002A54C,
};
