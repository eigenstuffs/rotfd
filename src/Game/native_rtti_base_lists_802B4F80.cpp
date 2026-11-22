#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802B4F80 = {
    {
        { &lbl_80374390, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B4F8C = {
    {
        { &lbl_80374390, 0 }, // BaseObject_Z
        { &lbl_80374398, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B4FA0 = {
    {
        { &lbl_80374390, 0 }, // BaseObject_Z
        { &lbl_80374398, 0 }, // ABC_Agent
        { &lbl_803743A0, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B4FBC = {
    {
        { &lbl_80374390, 0 }, // BaseObject_Z
        { &lbl_80374398, 0 }, // ABC_Agent
        { &lbl_803743A0, 0 }, // Agent_Z
        { &lbl_803743A8, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B4FE0 = {
    {
        { &lbl_80374390, 0 }, // BaseObject_Z
        { &lbl_80374398, 0 }, // ABC_Agent
        { &lbl_803743A0, 0 }, // Agent_Z
        { &lbl_803743A8, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803743B0, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802B500C = {
    {
        { &lbl_80374390, 0 }, // BaseObject_Z
        { &lbl_80374398, 0 }, // ABC_Agent
        { &lbl_803743A0, 0 }, // Agent_Z
        { &lbl_803743A8, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803743B0, 0 }, // AnimatedAgent_Z
        { &lbl_803743B8, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for LodAgent_Z.
NativeRuntimeBaseList<7> lbl_802B5040 = {
    {
        { &lbl_80374390, 0 }, // BaseObject_Z
        { &lbl_80374398, 0 }, // ABC_Agent
        { &lbl_803743A0, 0 }, // Agent_Z
        { &lbl_803743A8, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803743B0, 0 }, // AnimatedAgent_Z
        { &lbl_803743B8, 0 }, // MovingAgent_Z
        { &lbl_803743C0, 0 }, // Throwable_Z
    }, 0
};

// Base hierarchy for CActorAgent.
NativeRuntimeBaseList<8> lbl_802B507C = {
    {
        { &lbl_80374390, 0 }, // BaseObject_Z
        { &lbl_80374398, 0 }, // ABC_Agent
        { &lbl_803743A0, 0 }, // Agent_Z
        { &lbl_803743A8, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803743B0, 0 }, // AnimatedAgent_Z
        { &lbl_803743B8, 0 }, // MovingAgent_Z
        { &lbl_803743C0, 0 }, // Throwable_Z
        { &lbl_803743C8, 0 }, // LodAgent_Z
    }, 0
};

// Base hierarchy for Jellyfish.
NativeRuntimeBaseList<9> lbl_802B50C0 = {
    {
        { &lbl_80374390, 0 }, // BaseObject_Z
        { &lbl_80374398, 0 }, // ABC_Agent
        { &lbl_803743A0, 0 }, // Agent_Z
        { &lbl_803743A8, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803743B0, 0 }, // AnimatedAgent_Z
        { &lbl_803743B8, 0 }, // MovingAgent_Z
        { &lbl_803743C0, 0 }, // Throwable_Z
        { &lbl_803743C8, 0 }, // LodAgent_Z
        { &lbl_803743D0, 0 }, // CActorAgent
    }, 0
};

// Base hierarchy for YellowJfish.
NativeRuntimeBaseList<10> lbl_802B510C = {
    {
        { &lbl_80374390, 0 }, // BaseObject_Z
        { &lbl_80374398, 0 }, // ABC_Agent
        { &lbl_803743A0, 0 }, // Agent_Z
        { &lbl_803743A8, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803743B0, 0 }, // AnimatedAgent_Z
        { &lbl_803743B8, 0 }, // MovingAgent_Z
        { &lbl_803743C0, 0 }, // Throwable_Z
        { &lbl_803743C8, 0 }, // LodAgent_Z
        { &lbl_803743D0, 0 }, // CActorAgent
        { &lbl_803743D8, 0 }, // Jellyfish
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void slot5C__11Throwable_ZFv();
void slot60__11Throwable_ZFv();
void slot84__11Throwable_ZFv();
void slot88__11Throwable_ZFv();
void slot8C__11Throwable_ZFv();
void slot74__15AnimatedAgent_ZFv();
void slot48__7Agent_ZFv();
void slot70__7Agent_ZFv();
void slot94__10LodAgent_ZFv();
void slot98__10LodAgent_ZFv();
void slot9C__10LodAgent_ZFv();
void slotA0__10LodAgent_ZFv();
void slotA4__10LodAgent_ZFv();
void slotA8__10LodAgent_ZFv();
void slotAC__11CActorAgentFv();
void slot4C__11CActorAgentFv();
void slot50__11CActorAgentFv();
void fn_8005CD68();
void fn_8005CDE4();
void fn_8005CE48();
void fn_8005CE4C();
void fn_8005D0BC();
void fn_8005D0DC();
void fn_8005D3C4();
void fn_8005D3CC();
void fn_8005D3D4();
void fn_8005D414();
void slot6C__7Agent_ZFv();
void slot68__15AnimatedAgent_ZFv();
void slot64__15AnimatedAgent_ZFv();
void slot1C__13MovingAgent_ZFv();
void fn_8025A190();
void fn_8025A244();
void fn_8025A324();
void slot78__13MovingAgent_ZFv();
void slot7C__11Throwable_ZFv();
void slot90__11Throwable_ZFv();
void slot58__11Throwable_ZFv();
void slot54__11Throwable_ZFv();
void slot80__11Throwable_ZFv();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802B5160[46] __attribute__((aligned(4))) = {
    &lbl_803743E0,
    0,
    (const void*)fn_8005CD68,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8005CDE4,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_8005D3C4,
    (const void*)fn_8005D3CC,
    (const void*)fn_8005D3D4,
    (const void*)fn_8005D414,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_8005CE48,
    (const void*)fn_8025A324,
    (const void*)fn_8005CE4C,
    (const void*)fn_8005D0BC,
    (const void*)slot48__7Agent_ZFv,
    (const void*)slot4C__11CActorAgentFv,
    (const void*)slot50__11CActorAgentFv,
    (const void*)slot54__11Throwable_ZFv,
    (const void*)slot58__11Throwable_ZFv,
    (const void*)slot5C__11Throwable_ZFv,
    (const void*)slot60__11Throwable_ZFv,
    (const void*)slot64__15AnimatedAgent_ZFv,
    (const void*)slot68__15AnimatedAgent_ZFv,
    (const void*)slot6C__7Agent_ZFv,
    (const void*)slot70__7Agent_ZFv,
    (const void*)slot74__15AnimatedAgent_ZFv,
    (const void*)slot78__13MovingAgent_ZFv,
    (const void*)slot7C__11Throwable_ZFv,
    (const void*)slot80__11Throwable_ZFv,
    (const void*)slot84__11Throwable_ZFv,
    (const void*)slot88__11Throwable_ZFv,
    (const void*)slot8C__11Throwable_ZFv,
    (const void*)slot90__11Throwable_ZFv,
    (const void*)slot94__10LodAgent_ZFv,
    (const void*)slot98__10LodAgent_ZFv,
    (const void*)slot9C__10LodAgent_ZFv,
    (const void*)slotA0__10LodAgent_ZFv,
    (const void*)slotA4__10LodAgent_ZFv,
    (const void*)slotA8__10LodAgent_ZFv,
    (const void*)slotAC__11CActorAgentFv,
    (const void*)fn_8005D0DC,
    0,
};

