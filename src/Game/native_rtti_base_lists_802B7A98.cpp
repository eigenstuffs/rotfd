#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802B7A98 = {
    {
        { &lbl_80374830, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B7AA4 = {
    {
        { &lbl_80374830, 0 }, // BaseObject_Z
        { &lbl_80374838, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B7AB8 = {
    {
        { &lbl_80374830, 0 }, // BaseObject_Z
        { &lbl_80374838, 0 }, // ABC_Agent
        { &lbl_80374840, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B7AD4 = {
    {
        { &lbl_80374830, 0 }, // BaseObject_Z
        { &lbl_80374838, 0 }, // ABC_Agent
        { &lbl_80374840, 0 }, // Agent_Z
        { &lbl_80374848, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B7AF8 = {
    {
        { &lbl_80374830, 0 }, // BaseObject_Z
        { &lbl_80374838, 0 }, // ABC_Agent
        { &lbl_80374840, 0 }, // Agent_Z
        { &lbl_80374848, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374850, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802B7B24 = {
    {
        { &lbl_80374830, 0 }, // BaseObject_Z
        { &lbl_80374838, 0 }, // ABC_Agent
        { &lbl_80374840, 0 }, // Agent_Z
        { &lbl_80374848, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374850, 0 }, // AnimatedAgent_Z
        { &lbl_80374858, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for LodAgent_Z.
NativeRuntimeBaseList<7> lbl_802B7B58 = {
    {
        { &lbl_80374830, 0 }, // BaseObject_Z
        { &lbl_80374838, 0 }, // ABC_Agent
        { &lbl_80374840, 0 }, // Agent_Z
        { &lbl_80374848, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374850, 0 }, // AnimatedAgent_Z
        { &lbl_80374858, 0 }, // MovingAgent_Z
        { &lbl_80374860, 0 }, // Throwable_Z
    }, 0
};

// Base hierarchy for CActorAgent.
NativeRuntimeBaseList<8> lbl_802B7B94 = {
    {
        { &lbl_80374830, 0 }, // BaseObject_Z
        { &lbl_80374838, 0 }, // ABC_Agent
        { &lbl_80374840, 0 }, // Agent_Z
        { &lbl_80374848, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374850, 0 }, // AnimatedAgent_Z
        { &lbl_80374858, 0 }, // MovingAgent_Z
        { &lbl_80374860, 0 }, // Throwable_Z
        { &lbl_80374868, 0 }, // LodAgent_Z
    }, 0
};

// Base hierarchy for Puzzletile.
NativeRuntimeBaseList<9> lbl_802B7BD8 = {
    {
        { &lbl_80374830, 0 }, // BaseObject_Z
        { &lbl_80374838, 0 }, // ABC_Agent
        { &lbl_80374840, 0 }, // Agent_Z
        { &lbl_80374848, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374850, 0 }, // AnimatedAgent_Z
        { &lbl_80374858, 0 }, // MovingAgent_Z
        { &lbl_80374860, 0 }, // Throwable_Z
        { &lbl_80374868, 0 }, // LodAgent_Z
        { &lbl_80374870, 0 }, // CActorAgent
    }, 0
};

}

// Adjacent native method and member-pointer records.

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
void fn_8002BA94();
void fn_8002BAB4();
void slotAC__11CActorAgentFv();
void slot4C__11CActorAgentFv();
void slot50__11CActorAgentFv();
void fn_80072D74();
void fn_80072E0C();
void fn_80072E2C();
void fn_80073534();
void fn_8007353C();
void fn_80073544();
void fn_800735E8();
void fn_800736F4();
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

extern "C" __declspec(section ".data") const void* const lbl_802B7C24[45] __attribute__((aligned(4))) = {
    &lbl_80374878,
    0,
    (const void*)fn_800736F4,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_80072D74,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_80073534,
    (const void*)fn_8007353C,
    (const void*)fn_80073544,
    (const void*)fn_800735E8,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_80072E0C,
    (const void*)fn_8025A324,
    (const void*)fn_80072E2C,
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

extern "C" __declspec(section ".data") const void* const lbl_802B7CD8[18] __attribute__((aligned(4))) = {
    0,
    (const void*)0x00000094,
    (const void*)0x00000008,
    0,
    (const void*)0x00000094,
    (const void*)0x00000008,
    0,
    (const void*)0x00000094,
    (const void*)0x00000008,
    0,
    (const void*)0x00000094,
    (const void*)0x00000008,
    0,
    (const void*)0x00000094,
    (const void*)0x00000008,
    0,
    (const void*)0x00000094,
    (const void*)0x00000008,
};

