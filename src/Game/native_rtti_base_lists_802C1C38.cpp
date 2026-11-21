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
void fn_8002B820();
void fn_8002BA94();
void fn_8002BAB4();
void fn_8002BE80();
void fn_8002CEE8();
void fn_8002CEF8();
void fn_800CCF38();
void fn_800CCFA4();
void fn_800CD478();
void fn_800CD480();
void fn_800CD488();
void fn_800CD52C();
void fn_800CD638();
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
}

extern "C" __declspec(section ".data") const void* const lbl_802C1DC4[45] __attribute__((aligned(4))) = {
    &lbl_803759D0,
    0,
    (const void*)fn_800CD638,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800CCF38,
    (const void*)fn_80259F0C,
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
    (const void*)fn_8002BAB4,
};

