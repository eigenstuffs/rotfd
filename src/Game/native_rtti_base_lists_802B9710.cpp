#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateJFBase.
NativeRuntimeBaseList<1> lbl_802B9710 = {
    {
        { &lbl_80374C98, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateGreenJFDrop.
NativeRuntimeBaseList<2> lbl_802B971C = {
    {
        { &lbl_80374C98, 0 }, // CState
        { &lbl_80374CA0, 0 }, // CStateJFBase
    }, 0
};

}

// Adjacent native method and member-pointer records.

extern "C" {
void fn_80095410();
void fn_800957A8();
void fn_800957AC();
void fn_800957F4();
void fn_800958C0();
void fn_80095A60();
void fn_80095BB0();
void fn_80095BF8();
void fn_80095C40();
void fn_80095CF0();
void fn_80095D1C();
void fn_80095D98();
void fn_80095E14();
}

extern "C" __declspec(section ".data") const void* const lbl_802B9730[7] __attribute__((aligned(4))) = {
    &lbl_80374CA8,
    0,
    (const void*)fn_80095D1C,
    (const void*)fn_80095BF8,
    (const void*)fn_80095C40,
    (const void*)fn_80095CF0,
    (const void*)fn_80095410,
};

extern "C" NativeRuntimeBaseList<2> lbl_802B974C = {
    {
        {&lbl_80374C98, 0},
        {&lbl_80374CA0, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802B9760[7] __attribute__((aligned(4))) = {
    &lbl_80374CB0,
    0,
    (const void*)fn_80095D98,
    (const void*)fn_800958C0,
    (const void*)fn_80095A60,
    (const void*)fn_80095BB0,
    (const void*)fn_80095410,
};

extern "C" NativeRuntimeBaseList<2> lbl_802B977C = {
    {
        {&lbl_80374C98, 0},
        {&lbl_80374CA0, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802B9790[8] __attribute__((aligned(4))) = {
    &lbl_80374CB8,
    0,
    (const void*)fn_80095E14,
    (const void*)fn_800957F4,
    (const void*)fn_800957A8,
    (const void*)fn_800957AC,
    (const void*)fn_80095410,
    0,
};

