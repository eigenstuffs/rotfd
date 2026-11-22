#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B7D48 = {
    {
        { &lbl_80374880, 0 }, // BaseObject_Z
        { &lbl_80374888, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B7D5C = {
    {
        { &lbl_80374880, 0 }, // BaseObject_Z
        { &lbl_80374888, 0 }, // ABC_Agent
        { &lbl_80374890, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B7D78 = {
    {
        { &lbl_80374880, 0 }, // BaseObject_Z
        { &lbl_80374888, 0 }, // ABC_Agent
        { &lbl_80374890, 0 }, // Agent_Z
        { &lbl_80374898, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B7D9C = {
    {
        { &lbl_80374880, 0 }, // BaseObject_Z
        { &lbl_80374888, 0 }, // ABC_Agent
        { &lbl_80374890, 0 }, // Agent_Z
        { &lbl_80374898, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803748A0, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802B7DC8 = {
    {
        { &lbl_80374880, 0 }, // BaseObject_Z
        { &lbl_80374888, 0 }, // ABC_Agent
        { &lbl_80374890, 0 }, // Agent_Z
        { &lbl_80374898, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803748A0, 0 }, // AnimatedAgent_Z
        { &lbl_803748A8, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for WaterBall.
NativeRuntimeBaseList<7> lbl_802B7DFC = {
    {
        { &lbl_80374880, 0 }, // BaseObject_Z
        { &lbl_80374888, 0 }, // ABC_Agent
        { &lbl_80374890, 0 }, // Agent_Z
        { &lbl_80374898, 0 }, // AnimatedMsgAgent_Z
        { &lbl_803748A0, 0 }, // AnimatedAgent_Z
        { &lbl_803748A8, 0 }, // MovingAgent_Z
        { &lbl_803748B0, 0 }, // Throwable_Z
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__14Agent_800737D8Fv();
void slot5C__11Throwable_ZFv();
void slot60__11Throwable_ZFv();
void slot84__11Throwable_ZFv();
void slot88__11Throwable_ZFv();
void slot8C__11Throwable_ZFv();
void slot74__15AnimatedAgent_ZFv();
void slot4C__7Agent_ZFv();
void slot50__7Agent_ZFv();
void slot70__7Agent_ZFv();
void fn_800738D0();
void fn_80073AF8();
void fn_80073B38();
void fn_80073BE0();
void fn_80073DD8();
void fn_80073DF8();
void fn_80073E00();
void fn_80074058();
void fn_800742CC();
void fn_800742D4();
void fn_800742DC();
void fn_80074360();
void slot6C__7Agent_ZFv();
void slot68__15AnimatedAgent_ZFv();
void slot64__15AnimatedAgent_ZFv();
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

extern "C" __declspec(section ".data") const void* const lbl_802B7E38[40] __attribute__((aligned(4))) = {
    &lbl_803748B8,
    0,
    (const void*)__dt__14Agent_800737D8Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800738D0,
    (const void*)fn_80073B38,
    (const void*)fn_800742CC,
    (const void*)fn_800742D4,
    (const void*)fn_800742DC,
    (const void*)fn_80074360,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_80073AF8,
    (const void*)fn_8025A324,
    (const void*)fn_80073BE0,
    (const void*)fn_80073DD8,
    (const void*)fn_80073DF8,
    (const void*)slot4C__7Agent_ZFv,
    (const void*)slot50__7Agent_ZFv,
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
    (const void*)fn_80074058,
    (const void*)fn_80073E00,
    0,
};

