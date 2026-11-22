#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for RockThrow.
NativeRuntimeBaseList<8> lbl_802B23A8 = {
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
// Native root-derived method table at 0x802B23EC.
// The 39 slots reproduce the original interface pointer order.
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
void fn_800390A4();
void fn_80039120();
void fn_80039380();
void fn_800393A0();
void fn_8003BDF4();
void fn_8003BDFC();
void fn_8003BE04();
void fn_8003BE98();
void fn_8003BF88();
void fn_8003BF98();
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

extern "C" __declspec(section ".data") const void* const lbl_802B23EC[39] __attribute__((aligned(4))) = {
    &lbl_803741A0,
    0,
    (const void*)fn_800390A4,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_80039120,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_8003BDF4,
    (const void*)fn_8003BDFC,
    (const void*)fn_8003BE04,
    (const void*)fn_8003BE98,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_80039380,
    (const void*)fn_8025A324,
    (const void*)fn_800393A0,
    (const void*)fn_800356BC,
    (const void*)fn_80035850,
    (const void*)fn_8003BF88,
    (const void*)fn_8003BF98,
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
