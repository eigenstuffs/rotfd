#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802B54B0 = {
    {
        { &lbl_80374440, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B54BC = {
    {
        { &lbl_80374440, 0 }, // BaseObject_Z
        { &lbl_80374448, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B54D0 = {
    {
        { &lbl_80374440, 0 }, // BaseObject_Z
        { &lbl_80374448, 0 }, // ABC_Agent
        { &lbl_80374450, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B54EC = {
    {
        { &lbl_80374440, 0 }, // BaseObject_Z
        { &lbl_80374448, 0 }, // ABC_Agent
        { &lbl_80374450, 0 }, // Agent_Z
        { &lbl_80374458, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B5510 = {
    {
        { &lbl_80374440, 0 }, // BaseObject_Z
        { &lbl_80374448, 0 }, // ABC_Agent
        { &lbl_80374450, 0 }, // Agent_Z
        { &lbl_80374458, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374460, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802B553C = {
    {
        { &lbl_80374440, 0 }, // BaseObject_Z
        { &lbl_80374448, 0 }, // ABC_Agent
        { &lbl_80374450, 0 }, // Agent_Z
        { &lbl_80374458, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374460, 0 }, // AnimatedAgent_Z
        { &lbl_80374468, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for LodAgent_Z.
NativeRuntimeBaseList<7> lbl_802B5570 = {
    {
        { &lbl_80374440, 0 }, // BaseObject_Z
        { &lbl_80374448, 0 }, // ABC_Agent
        { &lbl_80374450, 0 }, // Agent_Z
        { &lbl_80374458, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374460, 0 }, // AnimatedAgent_Z
        { &lbl_80374468, 0 }, // MovingAgent_Z
        { &lbl_80374470, 0 }, // Throwable_Z
    }, 0
};

// Base hierarchy for CActorAgent.
NativeRuntimeBaseList<8> lbl_802B55AC = {
    {
        { &lbl_80374440, 0 }, // BaseObject_Z
        { &lbl_80374448, 0 }, // ABC_Agent
        { &lbl_80374450, 0 }, // Agent_Z
        { &lbl_80374458, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374460, 0 }, // AnimatedAgent_Z
        { &lbl_80374468, 0 }, // MovingAgent_Z
        { &lbl_80374470, 0 }, // Throwable_Z
        { &lbl_80374478, 0 }, // LodAgent_Z
    }, 0
};

// Base hierarchy for Jellyfish.
NativeRuntimeBaseList<9> lbl_802B55F0 = {
    {
        { &lbl_80374440, 0 }, // BaseObject_Z
        { &lbl_80374448, 0 }, // ABC_Agent
        { &lbl_80374450, 0 }, // Agent_Z
        { &lbl_80374458, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374460, 0 }, // AnimatedAgent_Z
        { &lbl_80374468, 0 }, // MovingAgent_Z
        { &lbl_80374470, 0 }, // Throwable_Z
        { &lbl_80374478, 0 }, // LodAgent_Z
        { &lbl_80374480, 0 }, // CActorAgent
    }, 0
};

// Base hierarchy for PinkJfish.
NativeRuntimeBaseList<10> lbl_802B563C = {
    {
        { &lbl_80374440, 0 }, // BaseObject_Z
        { &lbl_80374448, 0 }, // ABC_Agent
        { &lbl_80374450, 0 }, // Agent_Z
        { &lbl_80374458, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374460, 0 }, // AnimatedAgent_Z
        { &lbl_80374468, 0 }, // MovingAgent_Z
        { &lbl_80374470, 0 }, // Throwable_Z
        { &lbl_80374478, 0 }, // LodAgent_Z
        { &lbl_80374480, 0 }, // CActorAgent
        { &lbl_80374488, 0 }, // Jellyfish
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8005E258Fv();
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
void fn_8005DAAC();
void fn_8005DB28();
void fn_8005DB8C();
void fn_8005DB90();
void fn_8005DD14();
void fn_8005DD34();
void fn_8005E038();
void fn_8005E040();
void fn_8005E048();
void fn_8005E088();
void fn_8005E66C();
void fn_8005E670();
void script58__12CScriptAgentFv();
void script5C__12CScriptAgentFv();
void script60__12CScriptAgentFv();
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
extern char lbl_803744A4;
}

extern "C" __declspec(section ".data") const void* const lbl_802B5690[46] __attribute__((aligned(4))) = {
    &lbl_80374490,
    0,
    (const void*)fn_8005DAAC,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8005DB28,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_8005E038,
    (const void*)fn_8005E040,
    (const void*)fn_8005E048,
    (const void*)fn_8005E088,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_8005DB8C,
    (const void*)fn_8025A324,
    (const void*)fn_8005DB90,
    (const void*)fn_8005DD14,
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
    (const void*)fn_8005DD34,
    0,
};

extern "C" __declspec(section ".data") const void* const lbl_802B5748[26] __attribute__((aligned(4))) = {
    &lbl_803744A4,
    0,
    (const void*)__dt__15Object_8005E258Fv,
    (const void*)fn_8005E66C,
    (const void*)fn_8005E670,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    (const void*)script58__12CScriptAgentFv,
    (const void*)script5C__12CScriptAgentFv,
    (const void*)script60__12CScriptAgentFv,
    0,
};

