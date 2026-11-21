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
void fn_8002BA94();
void fn_8002BAB4();
void fn_8002BE80();
void fn_8002CEE8();
void fn_8002CEF8();
void fn_80072D74();
void fn_80072E0C();
void fn_80072E2C();
void fn_80073534();
void fn_8007353C();
void fn_80073544();
void fn_800735E8();
void fn_800736F4();
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

extern "C" __declspec(section ".data") const void* const lbl_802B7C24[45] __attribute__((aligned(4))) = {
    &lbl_80374878,
    0,
    (const void*)fn_800736F4,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_80072D74,
    (const void*)fn_80259F0C,
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

