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
void fn_8002390C();
void fn_80023914();
void fn_8002391C();
void fn_80023920();
void fn_80023924();
void fn_80023928();
void fn_80023934();
void fn_8002393C();
void fn_80023944();
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
void fn_80256028();
void fn_80257C50();
void fn_80257C58();
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
    (const void*)fn_80074058,
    (const void*)fn_80073E00,
    0,
};

