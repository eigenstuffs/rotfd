#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802B03D0 = {
    {
        { &lbl_80373EB8, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B03DC = {
    {
        { &lbl_80373EB8, 0 }, // BaseObject_Z
        { &lbl_80373EC0, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B03F0 = {
    {
        { &lbl_80373EB8, 0 }, // BaseObject_Z
        { &lbl_80373EC0, 0 }, // ABC_Agent
        { &lbl_80373EC8, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B040C = {
    {
        { &lbl_80373EB8, 0 }, // BaseObject_Z
        { &lbl_80373EC0, 0 }, // ABC_Agent
        { &lbl_80373EC8, 0 }, // Agent_Z
        { &lbl_80373ED0, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B0430 = {
    {
        { &lbl_80373EB8, 0 }, // BaseObject_Z
        { &lbl_80373EC0, 0 }, // ABC_Agent
        { &lbl_80373EC8, 0 }, // Agent_Z
        { &lbl_80373ED0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80373ED8, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802B045C = {
    {
        { &lbl_80373EB8, 0 }, // BaseObject_Z
        { &lbl_80373EC0, 0 }, // ABC_Agent
        { &lbl_80373EC8, 0 }, // Agent_Z
        { &lbl_80373ED0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80373ED8, 0 }, // AnimatedAgent_Z
        { &lbl_80373EE0, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for LodAgent_Z.
NativeRuntimeBaseList<7> lbl_802B0490 = {
    {
        { &lbl_80373EB8, 0 }, // BaseObject_Z
        { &lbl_80373EC0, 0 }, // ABC_Agent
        { &lbl_80373EC8, 0 }, // Agent_Z
        { &lbl_80373ED0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80373ED8, 0 }, // AnimatedAgent_Z
        { &lbl_80373EE0, 0 }, // MovingAgent_Z
        { &lbl_80373EE8, 0 }, // Throwable_Z
    }, 0
};

// Base hierarchy for hook.
NativeRuntimeBaseList<8> lbl_802B04CC = {
    {
        { &lbl_80373EB8, 0 }, // BaseObject_Z
        { &lbl_80373EC0, 0 }, // ABC_Agent
        { &lbl_80373EC8, 0 }, // Agent_Z
        { &lbl_80373ED0, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80373ED8, 0 }, // AnimatedAgent_Z
        { &lbl_80373EE0, 0 }, // MovingAgent_Z
        { &lbl_80373EE8, 0 }, // Throwable_Z
        { &lbl_80373EF0, 0 }, // LodAgent_Z
    }, 0
};

}

// Adjacent native hook method and base-list records.
extern "C" {
void slot5C__11Throwable_ZFv();
void slot60__11Throwable_ZFv();
void slot84__11Throwable_ZFv();
void slot88__11Throwable_ZFv();
void slot8C__11Throwable_ZFv();
void slot74__15AnimatedAgent_ZFv();
void slot48__7Agent_ZFv();
void slot4C__7Agent_ZFv();
void slot50__7Agent_ZFv();
void slot70__7Agent_ZFv();
void fn_80024ECC();
void fn_80024F50();
void fn_80024FD4();
void fn_80024FF4();
void fn_80025C70();
void fn_80025C78();
void fn_80025C80();
void fn_80025D14();
void slot94__10LodAgent_ZFv();
void slot98__10LodAgent_ZFv();
void slot9C__10LodAgent_ZFv();
void slotA0__10LodAgent_ZFv();
void slotA4__10LodAgent_ZFv();
void slotA8__10LodAgent_ZFv();
void slot6C__7Agent_ZFv();
void slot68__15AnimatedAgent_ZFv();
void slot64__15AnimatedAgent_ZFv();
void slot1C__13MovingAgent_ZFv();
void fn_80259FB4();
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

extern "C" __declspec(section ".data") const void* const lbl_802B0510[44] __attribute__((aligned(4))) = {
    &lbl_80373EF8,
    0,
    (const void*)fn_80024ECC,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_80024F50,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_80025C70,
    (const void*)fn_80025C78,
    (const void*)fn_80025C80,
    (const void*)fn_80025D14,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_80024FD4,
    (const void*)fn_8025A324,
    (const void*)fn_80024FF4,
    (const void*)fn_80259FB4,
    (const void*)slot48__7Agent_ZFv,
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
    (const void*)slot94__10LodAgent_ZFv,
    (const void*)slot98__10LodAgent_ZFv,
    (const void*)slot9C__10LodAgent_ZFv,
    (const void*)slotA0__10LodAgent_ZFv,
    (const void*)slotA4__10LodAgent_ZFv,
    (const void*)slotA8__10LodAgent_ZFv,
    0,
};
