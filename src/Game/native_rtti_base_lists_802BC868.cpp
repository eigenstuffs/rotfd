#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateScriptBase.
NativeRuntimeBaseList<1> lbl_802BC868 = {
    {
        { &lbl_803752C0, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateMediumBase.
NativeRuntimeBaseList<2> lbl_802BC874 = {
    {
        { &lbl_803752C0, 0 }, // CState
        { &lbl_803752C8, 0 }, // CStateScriptBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A4378Fv();
void fn_800A4D2C();
void fn_800A4D4C();
void fn_800A4D6C();
void fn_800A4D8C();
}

extern "C" __declspec(section ".data") const void* const lbl_802BC888[8] __attribute__((aligned(4))) = {
    &lbl_803752D0,
    0,
    (const void*)__dt__15Object_800A4378Fv,
    (const void*)fn_800A4D6C,
    (const void*)fn_800A4D2C,
    (const void*)fn_800A4D8C,
    (const void*)fn_800A4D4C,
    0,
};

