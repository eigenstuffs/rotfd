#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateJFBase.
NativeRuntimeBaseList<1> lbl_802BA630 = {
    {
        { &lbl_80374E78, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateRedJFReturn.
NativeRuntimeBaseList<2> lbl_802BA63C = {
    {
        { &lbl_80374E78, 0 }, // CState
        { &lbl_80374E80, 0 }, // CStateJFBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void fn_80095410();
void fn_8009808C();
void fn_800980D8();
void fn_80098184();
void fn_800981F4();
void fn_800982BC();
void fn_8009834C();
void fn_80098378();
void fn_800983F4();
}

extern "C" __declspec(section ".data") const void* const lbl_802BA650[7] __attribute__((aligned(4))) = {
    &lbl_80374E88,
    0,
    (const void*)fn_80098378,
    (const void*)fn_800981F4,
    (const void*)fn_800982BC,
    (const void*)fn_8009834C,
    (const void*)fn_80095410,
};

extern "C" NativeRuntimeBaseList<2> lbl_802BA66C = {
    {
        {&lbl_80374E78, 0},
        {&lbl_80374E80, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802BA680[8] __attribute__((aligned(4))) = {
    &lbl_80374E90,
    0,
    (const void*)fn_800983F4,
    (const void*)fn_8009808C,
    (const void*)fn_800980D8,
    (const void*)fn_80098184,
    (const void*)fn_80095410,
    0,
};

