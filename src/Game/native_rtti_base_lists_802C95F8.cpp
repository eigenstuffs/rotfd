#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateMemCardWaitForUpdateText.
NativeRuntimeBaseList<2> lbl_802C95F8 = {
    {
        { &lbl_80375BD0, 0 }, // CState
        { &lbl_80375BD8, 0 }, // CStateGCCardBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800F0334Fv();
void __dt__15Object_800F03C0Fv();
void fn_800E96A4();
void fn_800E9738();
void fn_800E9ADC();
void fn_800E9B70();
void fn_800E9BAC();
void fn_800E9F00();
}

extern "C" __declspec(section ".data") const void* const lbl_802C960C[6] __attribute__((aligned(4))) = {
    &lbl_80375C88,
    0,
    (const void*)__dt__15Object_800F0334Fv,
    (const void*)fn_800E9B70,
    (const void*)fn_800E9BAC,
    (const void*)fn_800E9F00,
};

extern "C" NativeRuntimeBaseList<2> lbl_802C9624 = {
    {
        {&lbl_80375BD0, 0},
        {&lbl_80375BD8, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802C9638[6] __attribute__((aligned(4))) = {
    &lbl_80375C90,
    0,
    (const void*)__dt__15Object_800F03C0Fv,
    (const void*)fn_800E96A4,
    (const void*)fn_800E9738,
    (const void*)fn_800E9ADC,
};

