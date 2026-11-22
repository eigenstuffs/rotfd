#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Fetch_Stick.
NativeRuntimeBaseList<8> lbl_802B1F48 = {
    {
        { &lbl_80374130, 0 }, // BaseObject_Z
        { &lbl_80374138, 0 }, // ABC_Agent
        { &lbl_80374140, 0 }, // Agent_Z
        { &lbl_80374148, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374150, 0 }, // AnimatedAgent_Z
        { &lbl_80374158, 0 }, // MovingAgent_Z
        { &lbl_80374160, 0 }, // Throwable_Z
        { &lbl_80374168, 0 }, // CProjectileAgent
    }, 0
};

}

// Original root-derived method table at 0x802B1F8C.
extern "C" {
void slot5C__11Throwable_ZFv();
void slot60__11Throwable_ZFv();
void slot84__11Throwable_ZFv();
void slot88__11Throwable_ZFv();
void slot8C__11Throwable_ZFv();
void slot74__15AnimatedAgent_ZFv();
void slot70__7Agent_ZFv();
void fn_800356BC();
void fn_80035850();
void fn_80035858();
void fn_8003585C();
void fn_8003AB38();
void fn_8003ABB4();
void fn_8003AE14();
void fn_8003AE34();
void fn_8003B570();
void fn_8003B578();
void fn_8003B580();
void fn_8003B614();
void fn_8003B704();
void fn_8003B714();
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
extern "C" __declspec(section ".data") const void* const lbl_802B1F8C[39] __attribute__((aligned(4))) = {
    &lbl_80374178,
    0,
    (const void*)fn_8003AB38,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8003ABB4,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_8003B570,
    (const void*)fn_8003B578,
    (const void*)fn_8003B580,
    (const void*)fn_8003B614,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_8003AE14,
    (const void*)fn_8025A324,
    (const void*)fn_8003AE34,
    (const void*)fn_800356BC,
    (const void*)fn_80035850,
    (const void*)fn_8003B704,
    (const void*)fn_8003B714,
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
    (const void*)fn_8003585C,
    (const void*)fn_80035858,
};
