#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Snowball.
NativeRuntimeBaseList<8> lbl_802B28F0 = {
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

// Snowball and projectile native method tables plus callback member pointers.
extern "C" {
void __dt__14Agent_80035294Fv();
void slot5C__11Throwable_ZFv();
void slot60__11Throwable_ZFv();
void slot84__11Throwable_ZFv();
void slot88__11Throwable_ZFv();
void slot8C__11Throwable_ZFv();
void slot74__15AnimatedAgent_ZFv();
void slot70__7Agent_ZFv();
void fn_80035390();
void fn_8003543C();
void fn_800356BC();
void fn_800356DC();
void fn_80035850();
void fn_80035858();
void fn_8003585C();
void fn_80035BB8();
void fn_80035C34();
void fn_80035E94();
void fn_80035EB4();
void fn_8003BF88();
void fn_8003BF98();
void fn_8003C7B8();
void fn_8003C7C0();
void fn_8003C7C8();
void fn_8003C85C();
void fn_8003C94C();
void fn_8003C954();
void fn_8003C95C();
void fn_8003C9E0();
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

extern "C" __declspec(section ".data") const void* const lbl_802B2934[39] __attribute__((aligned(4))) = {
    &lbl_803741D0,
    0,
    (const void*)fn_80035BB8,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_80035C34,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_8003C7B8,
    (const void*)fn_8003C7C0,
    (const void*)fn_8003C7C8,
    (const void*)fn_8003C85C,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_80035E94,
    (const void*)fn_8025A324,
    (const void*)fn_80035EB4,
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

extern "C" __declspec(section ".data") const void* const lbl_802B29D0[40] __attribute__((aligned(4))) = {
    &lbl_80374168,
    0,
    (const void*)__dt__14Agent_80035294Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_80035390,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_8003C94C,
    (const void*)fn_8003C954,
    (const void*)fn_8003C95C,
    (const void*)fn_8003C9E0,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_800356DC,
    (const void*)fn_8025A324,
    (const void*)fn_8003543C,
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
    0,
};

extern "C" __declspec(section ".data") const unsigned long lbl_802B2A70[18] __attribute__((aligned(4))) = {
    0x00000000,
    0x0000008C,
    0x00000008,
    0x00000000,
    0x0000008C,
    0x00000008,
    0x00000000,
    0x0000008C,
    0x00000008,
    0x00000000,
    0x0000008C,
    0x00000008,
    0x00000000,
    0x0000008C,
    0x00000008,
    0x00000000,
    0x0000008C,
    0x00000008,
};
