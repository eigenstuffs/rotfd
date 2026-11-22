#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802B7250 = {
    {
        { &lbl_80374798, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B725C = {
    {
        { &lbl_80374798, 0 }, // BaseObject_Z
        { &lbl_803747A0, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B7270 = {
    {
        { &lbl_80374798, 0 }, // BaseObject_Z
        { &lbl_803747A0, 0 }, // ABC_Agent
        { &lbl_803747A8, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B728C = {
    {
        { &lbl_80374798, 0 }, // BaseObject_Z
        { &lbl_803747A0, 0 }, // ABC_Agent
        { &lbl_803747A8, 0 }, // Agent_Z
        { &lbl_803747B0, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B72B0 = {
    {
        { &lbl_80374798, 0 }, // BaseObject_Z
        { &lbl_803747A0, 0 }, // ABC_Agent
        { &lbl_803747A8, 0 }, // Agent_Z
        { &lbl_803747B0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803747B8, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802B72DC = {
    {
        { &lbl_80374798, 0 }, // BaseObject_Z
        { &lbl_803747A0, 0 }, // ABC_Agent
        { &lbl_803747A8, 0 }, // Agent_Z
        { &lbl_803747B0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803747B8, 0 }, // AnimatedAgent_Z
        { &lbl_803747C0, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for LodAgent_Z.
NativeRuntimeBaseList<7> lbl_802B7310 = {
    {
        { &lbl_80374798, 0 }, // BaseObject_Z
        { &lbl_803747A0, 0 }, // ABC_Agent
        { &lbl_803747A8, 0 }, // Agent_Z
        { &lbl_803747B0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803747B8, 0 }, // AnimatedAgent_Z
        { &lbl_803747C0, 0 }, // MovingAgent_Z
        { &lbl_803747C8, 0 }, // Throwable_Z
    }, 0
};

// Base hierarchy for CActorAgent.
NativeRuntimeBaseList<8> lbl_802B734C = {
    {
        { &lbl_80374798, 0 }, // BaseObject_Z
        { &lbl_803747A0, 0 }, // ABC_Agent
        { &lbl_803747A8, 0 }, // Agent_Z
        { &lbl_803747B0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803747B8, 0 }, // AnimatedAgent_Z
        { &lbl_803747C0, 0 }, // MovingAgent_Z
        { &lbl_803747C8, 0 }, // Throwable_Z
        { &lbl_803747D0, 0 }, // LodAgent_Z
    }, 0
};

// Base hierarchy for CRBObjBaseAgent.
NativeRuntimeBaseList<9> lbl_802B7390 = {
    {
        { &lbl_80374798, 0 }, // BaseObject_Z
        { &lbl_803747A0, 0 }, // ABC_Agent
        { &lbl_803747A8, 0 }, // Agent_Z
        { &lbl_803747B0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803747B8, 0 }, // AnimatedAgent_Z
        { &lbl_803747C0, 0 }, // MovingAgent_Z
        { &lbl_803747C8, 0 }, // Throwable_Z
        { &lbl_803747D0, 0 }, // LodAgent_Z
        { &lbl_803747D8, 0 }, // CActorAgent
    }, 0
};

// Base hierarchy for TrashBall.
NativeRuntimeBaseList<10> lbl_802B73DC = {
    {
        { &lbl_80374798, 0 }, // BaseObject_Z
        { &lbl_803747A0, 0 }, // ABC_Agent
        { &lbl_803747A8, 0 }, // Agent_Z
        { &lbl_803747B0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803747B8, 0 }, // AnimatedAgent_Z
        { &lbl_803747C0, 0 }, // MovingAgent_Z
        { &lbl_803747C8, 0 }, // Throwable_Z
        { &lbl_803747D0, 0 }, // LodAgent_Z
        { &lbl_803747D8, 0 }, // CActorAgent
        { &lbl_803747E0, 0 }, // CRBObjBaseAgent
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
void fn_8006F598();
void fn_8006F6CC();
void fn_80070474();
void fn_80070500();
void fn_80070798();
void fn_8007079C();
void fn_80070BCC();
void fn_80070E04();
void fn_80070E0C();
void fn_80070E14();
void fn_80070EF8();
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

extern "C" __declspec(section ".data") const void* const lbl_802B7430[46] __attribute__((aligned(4))) = {
    &lbl_803747E8,
    0,
    (const void*)fn_80070474,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_80070500,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_80070E04,
    (const void*)fn_80070E0C,
    (const void*)fn_80070E14,
    (const void*)fn_80070EF8,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_80070798,
    (const void*)fn_8025A324,
    (const void*)fn_8007079C,
    (const void*)fn_8006F598,
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
    (const void*)fn_8006F6CC,
    (const void*)fn_80070BCC,
};

