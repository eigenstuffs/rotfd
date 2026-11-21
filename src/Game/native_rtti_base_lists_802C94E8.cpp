#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateMemCardCheckLoading.
NativeRuntimeBaseList<2> lbl_802C94E8 = {
    {
        { &lbl_80375BD0, 0 }, // CState
        { &lbl_80375BD8, 0 }, // CStateGCCardBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800F0068Fv();
void __dt__15Object_800F00F4Fv();
void fn_800EB2F8();
void fn_800EB520();
void fn_800EB59C();
void fn_800EB7C0();
void fn_800EB8C4();
void fn_800EB95C();
}

extern "C" __declspec(section ".data") const void* const lbl_802C94FC[6] __attribute__((aligned(4))) = {
    &lbl_80375C58,
    0,
    (const void*)__dt__15Object_800F0068Fv,
    (const void*)fn_800EB7C0,
    (const void*)fn_800EB8C4,
    (const void*)fn_800EB95C,
};

extern "C" NativeRuntimeBaseList<2> lbl_802C9514 = {
    {
        {&lbl_80375BD0, 0},
        {&lbl_80375BD8, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802C9528[6] __attribute__((aligned(4))) = {
    &lbl_80375C60,
    0,
    (const void*)__dt__15Object_800F00F4Fv,
    (const void*)fn_800EB2F8,
    (const void*)fn_800EB520,
    (const void*)fn_800EB59C,
};

