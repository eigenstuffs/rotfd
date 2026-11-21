#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateScriptBase.
NativeRuntimeBaseList<1> lbl_802BC468 = {
    {
        { &lbl_80375238, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateMediumBase.
NativeRuntimeBaseList<2> lbl_802BC474 = {
    {
        { &lbl_80375238, 0 }, // CState
        { &lbl_80375240, 0 }, // CStateScriptBase
    }, 0
};

// Base hierarchy for CStateMediumFlee.
NativeRuntimeBaseList<3> lbl_802BC488 = {
    {
        { &lbl_80375238, 0 }, // CState
        { &lbl_80375240, 0 }, // CStateScriptBase
        { &lbl_80375248, 0 }, // CStateMediumBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A4700Fv();
void fn_800A4674();
void fn_800A4D2C();
void fn_800A4D4C();
void fn_800A4D8C();
}

extern "C" __declspec(section ".data") const void* const lbl_802BC4A4[7] __attribute__((aligned(4))) = {
    &lbl_80375250,
    0,
    (const void*)__dt__15Object_800A4700Fv,
    (const void*)fn_800A4674,
    (const void*)fn_800A4D2C,
    (const void*)fn_800A4D8C,
    (const void*)fn_800A4D4C,
};

