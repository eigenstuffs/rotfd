#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for BootyBag.
NativeRuntimeBaseList<8> lbl_802B2108 = {
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

// Original root-derived method table at 0x802B214C.
extern "C" {
void fn_8002390C();
void fn_80023914();
void fn_8002391C();
void fn_80023920();
void fn_80023924();
void fn_80023928();
void fn_80023944();
void fn_800356BC();
void fn_80035850();
void fn_80035858();
void fn_8003585C();
void fn_8003A2C0();
void fn_8003A33C();
void fn_8003A59C();
void fn_8003A5BC();
void fn_8003B8D8();
void fn_8003B8E0();
void fn_8003B8E8();
void fn_8003B97C();
void fn_8003BA6C();
void fn_8003BA7C();
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
extern "C" __declspec(section ".data") const void* const lbl_802B214C[39] __attribute__((aligned(4))) = {
    &lbl_80374188,
    0,
    (const void*)fn_8003A2C0,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8003A33C,
    (const void*)fn_80259F0C,
    (const void*)fn_8003B8D8,
    (const void*)fn_8003B8E0,
    (const void*)fn_8003B8E8,
    (const void*)fn_8003B97C,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_8003A59C,
    (const void*)fn_8025A324,
    (const void*)fn_8003A5BC,
    (const void*)fn_800356BC,
    (const void*)fn_80035850,
    (const void*)fn_8003BA6C,
    (const void*)fn_8003BA7C,
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
    (const void*)fn_8003585C,
    (const void*)fn_80035858,
};
