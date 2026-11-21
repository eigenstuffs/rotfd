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
void fn_8002390C();
void fn_80023914();
void fn_8002391C();
void fn_80023920();
void fn_80023924();
void fn_80023928();
void fn_8002392C();
void fn_80023934();
void fn_8002393C();
void fn_80023944();
void fn_80024ECC();
void fn_80024F50();
void fn_80024FD4();
void fn_80024FF4();
void fn_80025C70();
void fn_80025C78();
void fn_80025C80();
void fn_80025D14();
void fn_80025E04();
void fn_80025E08();
void fn_80025E0C();
void fn_80025E10();
void fn_80025E18();
void fn_80025E1C();
void fn_80256028();
void fn_80257C50();
void fn_80257C58();
void fn_80259F0C();
void fn_80259FB4();
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

extern "C" __declspec(section ".data") const void* const lbl_802B0510[44] __attribute__((aligned(4))) = {
    &lbl_80373EF8,
    0,
    (const void*)fn_80024ECC,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_80024F50,
    (const void*)fn_80259F0C,
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
    (const void*)fn_8002392C,
    (const void*)fn_80023934,
    (const void*)fn_8002393C,
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
    0,
};
