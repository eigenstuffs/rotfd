#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B4C70 = {
    {
        { &lbl_80374318, 0 }, // BaseObject_Z
        { &lbl_80374320, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B4C84 = {
    {
        { &lbl_80374318, 0 }, // BaseObject_Z
        { &lbl_80374320, 0 }, // ABC_Agent
        { &lbl_80374328, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for CGlobalAgent.
NativeRuntimeBaseList<4> lbl_802B4CA0 = {
    {
        { &lbl_80374318, 0 }, // BaseObject_Z
        { &lbl_80374320, 0 }, // ABC_Agent
        { &lbl_80374328, 0 }, // Agent_Z
        { &lbl_80374330, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__14Agent_80052520Fv();
void slot48__7Agent_ZFv();
void slot4C__7Agent_ZFv();
void slot50__7Agent_ZFv();
void slot54__7Agent_ZFv();
void slot58__7Agent_ZFv();
void slot5C__7Agent_ZFv();
void slot60__7Agent_ZFv();
void fn_8002DAD8();
void slot64__7Agent_ZFv();
void slot68__7Agent_ZFv();
void fn_80035220();
void fn_80035224();
void fn_80035228();
void fn_80052F90();
void fn_80052FEC();
void fn_80056B44();
void fn_8005BC1C();
void fn_8005BE84();
void fn_8005BE8C();
void fn_8005BE94();
void fn_8005BEE8();
void fn_8005BF68();
void slot6C__7Agent_ZFv();
void slot3C__7Agent_ZFv();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802B4CC4[31] __attribute__((aligned(4))) = {
    &lbl_80374338,
    0,
    (const void*)__dt__14Agent_80052520Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_80052F90,
    (const void*)fn_80052FEC,
    (const void*)fn_8005BE84,
    (const void*)fn_8005BE8C,
    (const void*)fn_8005BE94,
    (const void*)fn_8005BEE8,
    (const void*)fn_80035224,
    (const void*)fn_80035228,
    (const void*)fn_8005BF68,
    (const void*)slot3C__7Agent_ZFv,
    (const void*)fn_80035220,
    (const void*)fn_8002DAD8,
    (const void*)slot48__7Agent_ZFv,
    (const void*)slot4C__7Agent_ZFv,
    (const void*)slot50__7Agent_ZFv,
    (const void*)slot54__7Agent_ZFv,
    (const void*)slot58__7Agent_ZFv,
    (const void*)slot5C__7Agent_ZFv,
    (const void*)slot60__7Agent_ZFv,
    (const void*)slot64__7Agent_ZFv,
    (const void*)slot68__7Agent_ZFv,
    (const void*)slot6C__7Agent_ZFv,
    (const void*)fn_80056B44,
    (const void*)fn_8005BC1C,
    0,
};

