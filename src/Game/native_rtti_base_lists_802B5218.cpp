#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802B5218 = {
    {
        { &lbl_803743E8, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B5224 = {
    {
        { &lbl_803743E8, 0 }, // BaseObject_Z
        { &lbl_803743F0, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B5238 = {
    {
        { &lbl_803743E8, 0 }, // BaseObject_Z
        { &lbl_803743F0, 0 }, // ABC_Agent
        { &lbl_803743F8, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B5254 = {
    {
        { &lbl_803743E8, 0 }, // BaseObject_Z
        { &lbl_803743F0, 0 }, // ABC_Agent
        { &lbl_803743F8, 0 }, // Agent_Z
        { &lbl_80374400, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B5278 = {
    {
        { &lbl_803743E8, 0 }, // BaseObject_Z
        { &lbl_803743F0, 0 }, // ABC_Agent
        { &lbl_803743F8, 0 }, // Agent_Z
        { &lbl_80374400, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374408, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802B52A4 = {
    {
        { &lbl_803743E8, 0 }, // BaseObject_Z
        { &lbl_803743F0, 0 }, // ABC_Agent
        { &lbl_803743F8, 0 }, // Agent_Z
        { &lbl_80374400, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374408, 0 }, // AnimatedAgent_Z
        { &lbl_80374410, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for LodAgent_Z.
NativeRuntimeBaseList<7> lbl_802B52D8 = {
    {
        { &lbl_803743E8, 0 }, // BaseObject_Z
        { &lbl_803743F0, 0 }, // ABC_Agent
        { &lbl_803743F8, 0 }, // Agent_Z
        { &lbl_80374400, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374408, 0 }, // AnimatedAgent_Z
        { &lbl_80374410, 0 }, // MovingAgent_Z
        { &lbl_80374418, 0 }, // Throwable_Z
    }, 0
};

// Base hierarchy for CActorAgent.
NativeRuntimeBaseList<8> lbl_802B5314 = {
    {
        { &lbl_803743E8, 0 }, // BaseObject_Z
        { &lbl_803743F0, 0 }, // ABC_Agent
        { &lbl_803743F8, 0 }, // Agent_Z
        { &lbl_80374400, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374408, 0 }, // AnimatedAgent_Z
        { &lbl_80374410, 0 }, // MovingAgent_Z
        { &lbl_80374418, 0 }, // Throwable_Z
        { &lbl_80374420, 0 }, // LodAgent_Z
    }, 0
};

// Base hierarchy for Jellyfish.
NativeRuntimeBaseList<9> lbl_802B5358 = {
    {
        { &lbl_803743E8, 0 }, // BaseObject_Z
        { &lbl_803743F0, 0 }, // ABC_Agent
        { &lbl_803743F8, 0 }, // Agent_Z
        { &lbl_80374400, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374408, 0 }, // AnimatedAgent_Z
        { &lbl_80374410, 0 }, // MovingAgent_Z
        { &lbl_80374418, 0 }, // Throwable_Z
        { &lbl_80374420, 0 }, // LodAgent_Z
        { &lbl_80374428, 0 }, // CActorAgent
    }, 0
};

// Base hierarchy for GreenJfish.
NativeRuntimeBaseList<10> lbl_802B53A4 = {
    {
        { &lbl_803743E8, 0 }, // BaseObject_Z
        { &lbl_803743F0, 0 }, // ABC_Agent
        { &lbl_803743F8, 0 }, // Agent_Z
        { &lbl_80374400, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374408, 0 }, // AnimatedAgent_Z
        { &lbl_80374410, 0 }, // MovingAgent_Z
        { &lbl_80374418, 0 }, // Throwable_Z
        { &lbl_80374420, 0 }, // LodAgent_Z
        { &lbl_80374428, 0 }, // CActorAgent
        { &lbl_80374430, 0 }, // Jellyfish
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
void fn_8005D4E0();
void fn_8005D55C();
void fn_8005D5C0();
void fn_8005D5C4();
void fn_8005D834();
void fn_8005D854();
void fn_8005D990();
void fn_8005D998();
void fn_8005D9A0();
void fn_8005D9E0();
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

extern "C" __declspec(section ".data") const void* const lbl_802B53F8[46] __attribute__((aligned(4))) = {
    &lbl_80374438,
    0,
    (const void*)fn_8005D4E0,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8005D55C,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_8005D990,
    (const void*)fn_8005D998,
    (const void*)fn_8005D9A0,
    (const void*)fn_8005D9E0,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_8005D5C0,
    (const void*)fn_8025A324,
    (const void*)fn_8005D5C4,
    (const void*)fn_8005D834,
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
    (const void*)fn_8005D854,
    0,
};

