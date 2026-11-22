#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B2EB8 = {
    {
        { &lbl_80374208, 0 }, // BaseObject_Z
        { &lbl_80374210, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B2ECC = {
    {
        { &lbl_80374208, 0 }, // BaseObject_Z
        { &lbl_80374210, 0 }, // ABC_Agent
        { &lbl_80374218, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B2EE8 = {
    {
        { &lbl_80374208, 0 }, // BaseObject_Z
        { &lbl_80374210, 0 }, // ABC_Agent
        { &lbl_80374218, 0 }, // Agent_Z
        { &lbl_80374220, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for MovingAgent_Z.
NativeRuntimeBaseList<5> lbl_802B2F0C = {
    {
        { &lbl_80374208, 0 }, // BaseObject_Z
        { &lbl_80374210, 0 }, // ABC_Agent
        { &lbl_80374218, 0 }, // Agent_Z
        { &lbl_80374220, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374228, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for Throwable_Z.
NativeRuntimeBaseList<6> lbl_802B2F38 = {
    {
        { &lbl_80374208, 0 }, // BaseObject_Z
        { &lbl_80374210, 0 }, // ABC_Agent
        { &lbl_80374218, 0 }, // Agent_Z
        { &lbl_80374220, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374228, 0 }, // AnimatedAgent_Z
        { &lbl_80374230, 0 }, // MovingAgent_Z
    }, 0
};

// Base hierarchy for LodAgent_Z.
NativeRuntimeBaseList<7> lbl_802B2F6C = {
    {
        { &lbl_80374208, 0 }, // BaseObject_Z
        { &lbl_80374210, 0 }, // ABC_Agent
        { &lbl_80374218, 0 }, // Agent_Z
        { &lbl_80374220, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374228, 0 }, // AnimatedAgent_Z
        { &lbl_80374230, 0 }, // MovingAgent_Z
        { &lbl_80374238, 0 }, // Throwable_Z
    }, 0
};

// Base hierarchy for CActorAgent.
NativeRuntimeBaseList<8> lbl_802B2FA8 = {
    {
        { &lbl_80374208, 0 }, // BaseObject_Z
        { &lbl_80374210, 0 }, // ABC_Agent
        { &lbl_80374218, 0 }, // Agent_Z
        { &lbl_80374220, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374228, 0 }, // AnimatedAgent_Z
        { &lbl_80374230, 0 }, // MovingAgent_Z
        { &lbl_80374238, 0 }, // Throwable_Z
        { &lbl_80374240, 0 }, // LodAgent_Z
    }, 0
};

// Base hierarchy for SpongeBob.
NativeRuntimeBaseList<9> lbl_802B2FEC = {
    {
        { &lbl_80374208, 0 }, // BaseObject_Z
        { &lbl_80374210, 0 }, // ABC_Agent
        { &lbl_80374218, 0 }, // Agent_Z
        { &lbl_80374220, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374228, 0 }, // AnimatedAgent_Z
        { &lbl_80374230, 0 }, // MovingAgent_Z
        { &lbl_80374238, 0 }, // Throwable_Z
        { &lbl_80374240, 0 }, // LodAgent_Z
        { &lbl_80374248, 0 }, // CActorAgent
    }, 0
};

// Base hierarchy for SpongeBobKR.
NativeRuntimeBaseList<10> lbl_802B3038 = {
    {
        { &lbl_80374208, 0 }, // BaseObject_Z
        { &lbl_80374210, 0 }, // ABC_Agent
        { &lbl_80374218, 0 }, // Agent_Z
        { &lbl_80374220, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374228, 0 }, // AnimatedAgent_Z
        { &lbl_80374230, 0 }, // MovingAgent_Z
        { &lbl_80374238, 0 }, // Throwable_Z
        { &lbl_80374240, 0 }, // LodAgent_Z
        { &lbl_80374248, 0 }, // CActorAgent
        { &lbl_80374250, 0 }, // SpongeBob
    }, 0
};

}

// Related native method tables and runtime base lists.
// The 55-word tables share many slots but retain the distinct RTTI
// pointers, destructors, overrides, and native base-list records.
extern "C" {
void __dt__15Object_8003FD34Fv();
void slot5C__11Throwable_ZFv();
void slot60__11Throwable_ZFv();
void slot84__11Throwable_ZFv();
void slot88__11Throwable_ZFv();
void slot8C__11Throwable_ZFv();
void slot74__15AnimatedAgent_ZFv();
void slot70__7Agent_ZFv();
void fn_800400BC();
void fn_800401FC();
void fn_8004024C();
void fn_80040654();
void fn_80040758();
void fn_8004084C();
void fn_8004086C();
void fn_80040B90();
void fn_80040BFC();
void fn_800410E4();
void fn_80041B74();
void fn_80041F30();
void fn_800420C8();
void fn_80042260();
void fn_80042340();
void fn_800425CC();
void fn_800428F4();
void fn_80042C14();
void fn_80043018();
void fn_800433AC();
void fn_80043648();
void fn_800438E4();
void fn_800438EC();
void fn_800438F4();
void fn_80043934();
void fn_800439D8();
void fn_80043A24();
void fn_80043B30();
void fn_80043BBC();
void fn_80043BC4();
void fn_80043BCC();
void fn_80043BD0();
void fn_80043BD8();
void fn_80043BE0();
void fn_80043BF0();
void fn_80043C00();
void fn_80043C08();
void fn_80043C10();
void fn_80043C18();
void fn_80043C20();
void fn_80043C60();
void fn_80043CAC();
void fn_80043D38();
void fn_80043D40();
void fn_80043D48();
void fn_80043D88();
void fn_80043DD4();
void fn_80043E60();
void fn_80043E68();
void fn_80043E70();
void fn_80043EB0();
void fn_80043EFC();
void fn_80043F88();
void fn_80043F90();
void fn_80043F98();
void fn_80043FD8();
void fn_80044024();
void slot6C__7Agent_ZFv();
void slot68__15AnimatedAgent_ZFv();
void slot64__15AnimatedAgent_ZFv();
void slot1C__13MovingAgent_ZFv();
void fn_8025A190();
void fn_8025A244();
void slot78__13MovingAgent_ZFv();
void slot7C__11Throwable_ZFv();
void slot90__11Throwable_ZFv();
void slot58__11Throwable_ZFv();
void slot54__11Throwable_ZFv();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802B308C[55] __attribute__((aligned(4))) = {
    &lbl_80374258,
    0,
    (const void*)fn_80043B30,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800400BC,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_800438E4,
    (const void*)fn_800438EC,
    (const void*)fn_800438F4,
    (const void*)fn_800439D8,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_800401FC,
    (const void*)fn_8004084C,
    (const void*)fn_8004024C,
    (const void*)fn_80040758,
    (const void*)fn_80040BFC,
    (const void*)fn_80043BE0,
    (const void*)fn_80043BF0,
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
    (const void*)fn_80040B90,
    (const void*)slot84__11Throwable_ZFv,
    (const void*)slot88__11Throwable_ZFv,
    (const void*)slot8C__11Throwable_ZFv,
    (const void*)slot90__11Throwable_ZFv,
    (const void*)fn_80043BC4,
    (const void*)fn_80043BCC,
    (const void*)fn_80043BD0,
    (const void*)fn_80043BBC,
    (const void*)fn_80043BD8,
    (const void*)fn_80041B74,
    (const void*)fn_80042340,
    (const void*)fn_800410E4,
    (const void*)fn_8004086C,
    (const void*)fn_80040654,
    (const void*)fn_800420C8,
    (const void*)fn_80042260,
    (const void*)fn_800425CC,
    (const void*)fn_800428F4,
    (const void*)fn_80042C14,
    (const void*)fn_80043018,
    (const void*)fn_800433AC,
    (const void*)fn_80043648,
};

extern "C" __declspec(section ".data") const void* const lbl_802B3168[55] __attribute__((aligned(4))) = {
    &lbl_80374250,
    0,
    (const void*)__dt__15Object_8003FD34Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800400BC,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_80043C00,
    (const void*)fn_80043C08,
    (const void*)fn_80043934,
    (const void*)fn_80043A24,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_800401FC,
    (const void*)fn_8004084C,
    (const void*)fn_8004024C,
    (const void*)fn_80040758,
    (const void*)fn_80040BFC,
    (const void*)fn_80043BE0,
    (const void*)fn_80043BF0,
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
    (const void*)fn_80040B90,
    (const void*)slot84__11Throwable_ZFv,
    (const void*)slot88__11Throwable_ZFv,
    (const void*)slot8C__11Throwable_ZFv,
    (const void*)slot90__11Throwable_ZFv,
    (const void*)fn_80043BC4,
    (const void*)fn_80043BCC,
    (const void*)fn_80043BD0,
    (const void*)fn_80043BBC,
    (const void*)fn_80043BD8,
    (const void*)fn_80041B74,
    (const void*)fn_80042340,
    (const void*)fn_800410E4,
    (const void*)fn_8004086C,
    (const void*)fn_80040654,
    (const void*)fn_80041F30,
    (const void*)fn_80042260,
    (const void*)fn_800425CC,
    (const void*)fn_800428F4,
    (const void*)fn_80042C14,
    (const void*)fn_80043018,
    (const void*)fn_800433AC,
    (const void*)fn_80043648,
};

extern "C" __declspec(section ".data") NativeRuntimeBaseList<10> lbl_802B3244 __attribute__((aligned(4))) = { { { &lbl_80374208, 0 }, { &lbl_80374210, 0 }, { &lbl_80374218, 0 }, { &lbl_80374220, 0 }, { &lbl_80374228, 0 }, { &lbl_80374230, 0 }, { &lbl_80374238, 0 }, { &lbl_80374240, 0 }, { &lbl_80374248, 0 }, { &lbl_80374250, 0 } }, 0 };

extern "C" __declspec(section ".data") const void* const lbl_802B3298[55] __attribute__((aligned(4))) = {
    &lbl_80374260,
    0,
    (const void*)fn_80043CAC,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800400BC,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_80043C10,
    (const void*)fn_80043C18,
    (const void*)fn_80043C20,
    (const void*)fn_80043C60,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_800401FC,
    (const void*)fn_8004084C,
    (const void*)fn_8004024C,
    (const void*)fn_80040758,
    (const void*)fn_80040BFC,
    (const void*)fn_80043BE0,
    (const void*)fn_80043BF0,
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
    (const void*)fn_80040B90,
    (const void*)slot84__11Throwable_ZFv,
    (const void*)slot88__11Throwable_ZFv,
    (const void*)slot8C__11Throwable_ZFv,
    (const void*)slot90__11Throwable_ZFv,
    (const void*)fn_80043BC4,
    (const void*)fn_80043BCC,
    (const void*)fn_80043BD0,
    (const void*)fn_80043BBC,
    (const void*)fn_80043BD8,
    (const void*)fn_80041B74,
    (const void*)fn_80042340,
    (const void*)fn_800410E4,
    (const void*)fn_8004086C,
    (const void*)fn_80040654,
    (const void*)fn_80041F30,
    (const void*)fn_80042260,
    (const void*)fn_800425CC,
    (const void*)fn_800428F4,
    (const void*)fn_80042C14,
    (const void*)fn_80043018,
    (const void*)fn_800433AC,
    (const void*)fn_80043648,
};

extern "C" __declspec(section ".data") NativeRuntimeBaseList<10> lbl_802B3374 __attribute__((aligned(4))) = { { { &lbl_80374208, 0 }, { &lbl_80374210, 0 }, { &lbl_80374218, 0 }, { &lbl_80374220, 0 }, { &lbl_80374228, 0 }, { &lbl_80374230, 0 }, { &lbl_80374238, 0 }, { &lbl_80374240, 0 }, { &lbl_80374248, 0 }, { &lbl_80374250, 0 } }, 0 };

extern "C" __declspec(section ".data") const void* const lbl_802B33C8[55] __attribute__((aligned(4))) = {
    &lbl_80374268,
    0,
    (const void*)fn_80043DD4,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800400BC,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_80043D38,
    (const void*)fn_80043D40,
    (const void*)fn_80043D48,
    (const void*)fn_80043D88,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_800401FC,
    (const void*)fn_8004084C,
    (const void*)fn_8004024C,
    (const void*)fn_80040758,
    (const void*)fn_80040BFC,
    (const void*)fn_80043BE0,
    (const void*)fn_80043BF0,
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
    (const void*)fn_80040B90,
    (const void*)slot84__11Throwable_ZFv,
    (const void*)slot88__11Throwable_ZFv,
    (const void*)slot8C__11Throwable_ZFv,
    (const void*)slot90__11Throwable_ZFv,
    (const void*)fn_80043BC4,
    (const void*)fn_80043BCC,
    (const void*)fn_80043BD0,
    (const void*)fn_80043BBC,
    (const void*)fn_80043BD8,
    (const void*)fn_80041B74,
    (const void*)fn_80042340,
    (const void*)fn_800410E4,
    (const void*)fn_8004086C,
    (const void*)fn_80040654,
    (const void*)fn_80041F30,
    (const void*)fn_80042260,
    (const void*)fn_800425CC,
    (const void*)fn_800428F4,
    (const void*)fn_80042C14,
    (const void*)fn_80043018,
    (const void*)fn_800433AC,
    (const void*)fn_80043648,
};

extern "C" __declspec(section ".data") NativeRuntimeBaseList<10> lbl_802B34A4 __attribute__((aligned(4))) = { { { &lbl_80374208, 0 }, { &lbl_80374210, 0 }, { &lbl_80374218, 0 }, { &lbl_80374220, 0 }, { &lbl_80374228, 0 }, { &lbl_80374230, 0 }, { &lbl_80374238, 0 }, { &lbl_80374240, 0 }, { &lbl_80374248, 0 }, { &lbl_80374250, 0 } }, 0 };

extern "C" __declspec(section ".data") const void* const lbl_802B34F8[55] __attribute__((aligned(4))) = {
    &lbl_80374270,
    0,
    (const void*)fn_80043EFC,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800400BC,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_80043E60,
    (const void*)fn_80043E68,
    (const void*)fn_80043E70,
    (const void*)fn_80043EB0,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_800401FC,
    (const void*)fn_8004084C,
    (const void*)fn_8004024C,
    (const void*)fn_80040758,
    (const void*)fn_80040BFC,
    (const void*)fn_80043BE0,
    (const void*)fn_80043BF0,
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
    (const void*)fn_80040B90,
    (const void*)slot84__11Throwable_ZFv,
    (const void*)slot88__11Throwable_ZFv,
    (const void*)slot8C__11Throwable_ZFv,
    (const void*)slot90__11Throwable_ZFv,
    (const void*)fn_80043BC4,
    (const void*)fn_80043BCC,
    (const void*)fn_80043BD0,
    (const void*)fn_80043BBC,
    (const void*)fn_80043BD8,
    (const void*)fn_80041B74,
    (const void*)fn_80042340,
    (const void*)fn_800410E4,
    (const void*)fn_8004086C,
    (const void*)fn_80040654,
    (const void*)fn_80041F30,
    (const void*)fn_80042260,
    (const void*)fn_800425CC,
    (const void*)fn_800428F4,
    (const void*)fn_80042C14,
    (const void*)fn_80043018,
    (const void*)fn_800433AC,
    (const void*)fn_80043648,
};

extern "C" __declspec(section ".data") NativeRuntimeBaseList<10> lbl_802B35D4 __attribute__((aligned(4))) = { { { &lbl_80374208, 0 }, { &lbl_80374210, 0 }, { &lbl_80374218, 0 }, { &lbl_80374220, 0 }, { &lbl_80374228, 0 }, { &lbl_80374230, 0 }, { &lbl_80374238, 0 }, { &lbl_80374240, 0 }, { &lbl_80374248, 0 }, { &lbl_80374250, 0 } }, 0 };

extern "C" __declspec(section ".data") const void* const lbl_802B3628[56] __attribute__((aligned(4))) = {
    &lbl_80374278,
    0,
    (const void*)fn_80044024,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800400BC,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_80043F88,
    (const void*)fn_80043F90,
    (const void*)fn_80043F98,
    (const void*)fn_80043FD8,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_800401FC,
    (const void*)fn_8004084C,
    (const void*)fn_8004024C,
    (const void*)fn_80040758,
    (const void*)fn_80040BFC,
    (const void*)fn_80043BE0,
    (const void*)fn_80043BF0,
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
    (const void*)fn_80040B90,
    (const void*)slot84__11Throwable_ZFv,
    (const void*)slot88__11Throwable_ZFv,
    (const void*)slot8C__11Throwable_ZFv,
    (const void*)slot90__11Throwable_ZFv,
    (const void*)fn_80043BC4,
    (const void*)fn_80043BCC,
    (const void*)fn_80043BD0,
    (const void*)fn_80043BBC,
    (const void*)fn_80043BD8,
    (const void*)fn_80041B74,
    (const void*)fn_80042340,
    (const void*)fn_800410E4,
    (const void*)fn_8004086C,
    (const void*)fn_80040654,
    (const void*)fn_80041F30,
    (const void*)fn_80042260,
    (const void*)fn_800425CC,
    (const void*)fn_800428F4,
    (const void*)fn_80042C14,
    (const void*)fn_80043018,
    (const void*)fn_800433AC,
    (const void*)fn_80043648,
    0,
};

extern "C" __declspec(section ".data") const void* const lbl_802B3708[18] __attribute__((aligned(4))) = {
    0,
    (const void*)0x0000008C,
    (const void*)0x00000008,
    0,
    (const void*)0x0000008C,
    (const void*)0x00000008,
    0,
    (const void*)0x0000008C,
    (const void*)0x00000008,
    0,
    (const void*)0x0000008C,
    (const void*)0x00000008,
    0,
    (const void*)0x0000008C,
    (const void*)0x00000008,
    0,
    (const void*)0x0000008C,
    (const void*)0x00000008,
};
