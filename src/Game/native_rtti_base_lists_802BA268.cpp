#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateJFBase.
NativeRuntimeBaseList<1> lbl_802BA268 = {
    {
        { &lbl_80374E00, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateBlueJFReturn.
NativeRuntimeBaseList<2> lbl_802BA274 = {
    {
        { &lbl_80374E00, 0 }, // CState
        { &lbl_80374E08, 0 }, // CStateJFBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void fn_80095410();
void fn_800975A4();
void fn_800975BC();
void fn_8009769C();
void fn_8009770C();
void fn_80097724();
void fn_800977B4();
void fn_800977E0();
void fn_8009785C();
}

extern "C" __declspec(section ".data") const void* const lbl_802BA288[7] __attribute__((aligned(4))) = {
    &lbl_80374E10,
    0,
    (const void*)fn_800977E0,
    (const void*)fn_8009770C,
    (const void*)fn_80097724,
    (const void*)fn_800977B4,
    (const void*)fn_80095410,
};

extern "C" NativeRuntimeBaseList<2> lbl_802BA2A4 = {
    {
        {&lbl_80374E00, 0},
        {&lbl_80374E08, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802BA2B8[8] __attribute__((aligned(4))) = {
    &lbl_80374E18,
    0,
    (const void*)fn_8009785C,
    (const void*)fn_800975A4,
    (const void*)fn_800975BC,
    (const void*)fn_8009769C,
    (const void*)fn_80095410,
    0,
};

