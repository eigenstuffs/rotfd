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
void fn_8002390C();
void fn_80023914();
void fn_8002391C();
void fn_80023920();
void fn_80023924();
void fn_80023928();
void fn_8002392C();
void fn_80023944();
void fn_80025E04();
void fn_80025E08();
void fn_80025E0C();
void fn_80025E10();
void fn_80025E18();
void fn_80025E1C();
void fn_8002BE80();
void fn_8002CEE8();
void fn_8002CEF8();
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
void fn_800600B4();
void fn_800600E4();
void fn_80060114();
void fn_80256028();
void fn_80257C50();
void fn_80257C58();
void fn_80259F0C();
void fn_8025A190();
void fn_8025A244();
void fn_8025A324();
void fn_8025A5F8();
void fn_8025B448();
void fn_8025B928();
void fn_8025BAD4();
void fn_8025BAF4();
void fn_8025BB14();
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
    (const void*)fn_80259F0C,
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
    (const void*)fn_8002392C,
    (const void*)fn_8002CEE8,
    (const void*)fn_8002CEF8,
    (const void*)fn_8025BAF4,
    (const void*)fn_8025BAD4,
    (const void*)fn_8002390C,
    (const void*)fn_80023914,
    (const void*)fn_80257C58,
    (const void*)fn_80257C50,
    (const void*)fn_80256028,
    (const void*)fn_80023944,
    (const void*)fn_80023928,
    (const void*)fn_8025A5F8,
    (const void*)fn_8025B448,
    (const void*)fn_8025BB14,
    (const void*)fn_8002391C,
    (const void*)fn_80023920,
    (const void*)fn_80023924,
    (const void*)fn_8025B928,
    (const void*)fn_80025E04,
    (const void*)fn_80025E08,
    (const void*)fn_80025E0C,
    (const void*)fn_80025E10,
    (const void*)fn_80025E18,
    (const void*)fn_80025E1C,
    (const void*)fn_8002BE80,
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
    (const void*)fn_800600B4,
    (const void*)fn_800600E4,
    (const void*)fn_80060114,
    0,
};

