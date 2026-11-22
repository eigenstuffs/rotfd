#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802C1C38 = {
    {
        { &lbl_80375988, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802C1C44 = {
    {
        { &lbl_80375988, 0 }, // BaseObject_Z
        { &lbl_80375990, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802C1C58 = {
    {
        { &lbl_80375988, 0 }, // BaseObject_Z
        { &lbl_80375990, 0 }, // ABC_Agent
        { &lbl_80375998, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802C1C74 = {
    {
        { &lbl_80375988, 0 }, // BaseObject_Z
        { &lbl_80375990, 0 }, // ABC_Agent
        { &lbl_80375998, 0 }, // Agent_Z
        { &lbl_803759A0, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802C1C98 = {
    {
        { &lbl_80375988, 0 }, // BaseObject_Z
        { &lbl_80375990, 0 }, // ABC_Agent
        { &lbl_80375998, 0 }, // Agent_Z
        { &lbl_803759A0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803759A8, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802C1CC4 = {
    {
        { &lbl_80375988, 0 }, // BaseObject_Z
        { &lbl_80375990, 0 }, // ABC_Agent
        { &lbl_80375998, 0 }, // Agent_Z
        { &lbl_803759A0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803759A8, 0 }, // AnimatedAgent_Z
        { &lbl_803759B0, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for LodAgent_Z.
NativeRuntimeBaseList<7> lbl_802C1CF8 = {
    {
        { &lbl_80375988, 0 }, // BaseObject_Z
        { &lbl_80375990, 0 }, // ABC_Agent
        { &lbl_80375998, 0 }, // Agent_Z
        { &lbl_803759A0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803759A8, 0 }, // AnimatedAgent_Z
        { &lbl_803759B0, 0 }, // MovingAgent_Z
        { &lbl_803759B8, 0 }, // Throwable_Z
    }, 0
};

// Base hierarchy for CActorAgent.
NativeRuntimeBaseList<8> lbl_802C1D34 = {
    {
        { &lbl_80375988, 0 }, // BaseObject_Z
        { &lbl_80375990, 0 }, // ABC_Agent
        { &lbl_80375998, 0 }, // Agent_Z
        { &lbl_803759A0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803759A8, 0 }, // AnimatedAgent_Z
        { &lbl_803759B0, 0 }, // MovingAgent_Z
        { &lbl_803759B8, 0 }, // Throwable_Z
        { &lbl_803759C0, 0 }, // LodAgent_Z
    }, 0
};

// Base hierarchy for DamageAgent.
NativeRuntimeBaseList<9> lbl_802C1D78 = {
    {
        { &lbl_80375988, 0 }, // BaseObject_Z
        { &lbl_80375990, 0 }, // ABC_Agent
        { &lbl_80375998, 0 }, // Agent_Z
        { &lbl_803759A0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803759A8, 0 }, // AnimatedAgent_Z
        { &lbl_803759B0, 0 }, // MovingAgent_Z
        { &lbl_803759B8, 0 }, // Throwable_Z
        { &lbl_803759C0, 0 }, // LodAgent_Z
        { &lbl_803759C8, 0 }, // CActorAgent
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
void fn_8002B820();
void fn_8002BA94();
void fn_8002BAB4();
void slotAC__11CActorAgentFv();
void slot4C__11CActorAgentFv();
void slot50__11CActorAgentFv();
void fn_800CCF38();
void fn_800CCFA4();
void fn_800CD478();
void fn_800CD480();
void fn_800CD488();
void fn_800CD52C();
void fn_800CD638();
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

extern "C" __declspec(section ".data") const void* const lbl_802C1DC4[45] __attribute__((aligned(4))) = {
    &lbl_803759D0,
    0,
    (const void*)fn_800CD638,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800CCF38,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_800CD478,
    (const void*)fn_800CD480,
    (const void*)fn_800CD488,
    (const void*)fn_800CD52C,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_8002B820,
    (const void*)fn_8025A324,
    (const void*)fn_800CCFA4,
    (const void*)fn_8002BA94,
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
    (const void*)fn_8002BAB4,
};

