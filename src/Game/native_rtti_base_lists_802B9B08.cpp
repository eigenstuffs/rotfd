#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateJFBase.
NativeRuntimeBaseList<1> lbl_802B9B08 = {
    {
        { &lbl_80374D18, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateYellowJFReturn.
NativeRuntimeBaseList<2> lbl_802B9B14 = {
    {
        { &lbl_80374D18, 0 }, // CState
        { &lbl_80374D20, 0 }, // CStateJFBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void fn_80095410();
void fn_80096570();
void fn_800965BC();
void fn_80096668();
void fn_800966D8();
void fn_800967A0();
void fn_80096830();
void fn_8009685C();
void fn_800968D8();
}

extern "C" __declspec(section ".data") const void* const lbl_802B9B28[7] __attribute__((aligned(4))) = {
    &lbl_80374D28,
    0,
    (const void*)fn_8009685C,
    (const void*)fn_800966D8,
    (const void*)fn_800967A0,
    (const void*)fn_80096830,
    (const void*)fn_80095410,
};

extern "C" NativeRuntimeBaseList<2> lbl_802B9B44 = {
    {
        {&lbl_80374D18, 0},
        {&lbl_80374D20, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802B9B58[8] __attribute__((aligned(4))) = {
    &lbl_80374D30,
    0,
    (const void*)fn_800968D8,
    (const void*)fn_80096570,
    (const void*)fn_800965BC,
    (const void*)fn_80096668,
    (const void*)fn_80095410,
    0,
};

