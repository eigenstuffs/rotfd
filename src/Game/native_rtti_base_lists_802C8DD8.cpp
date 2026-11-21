#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateSBBase.
NativeRuntimeBaseList<1> lbl_802C8DD8 = {
    {
        { &lbl_80375B28, 0 }, // CState
    }, 0
};

// Base hierarchy for CStatePlayGroundEffects.
NativeRuntimeBaseList<2> lbl_802C8DE4 = {
    {
        { &lbl_80375B28, 0 }, // CState
        { &lbl_80375B30, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.

extern "C" {
void __dt__15Object_800E588CFv();
void __dt__15Object_800E6E68Fv();
void fn_80081414();
void fn_800E5918();
void fn_800E5CAC();
void fn_800E5F38();
}

extern "C" __declspec(section ".data") const void* const lbl_802C8DF8[8] __attribute__((aligned(4))) = {
    &lbl_80375B38,
    0,
    (const void*)__dt__15Object_800E588CFv,
    (const void*)fn_800E5918,
    (const void*)fn_800E5CAC,
    (const void*)fn_800E5F38,
    (const void*)fn_80081414,
    0,
};

extern "C" __declspec(section ".data") const void* const lbl_802C8E18[4] __attribute__((aligned(4))) = {
    &lbl_80375B40,
    0,
    (const void*)__dt__15Object_800E6E68Fv,
    0,
};

