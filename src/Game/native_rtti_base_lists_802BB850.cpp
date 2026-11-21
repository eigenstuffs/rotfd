#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateScriptBase.
NativeRuntimeBaseList<1> lbl_802BB850 = {
    {
        { &lbl_80375088, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateSimpleBase.
NativeRuntimeBaseList<2> lbl_802BB85C = {
    {
        { &lbl_80375088, 0 }, // CState
        { &lbl_80375090, 0 }, // CStateScriptBase
    }, 0
};

// Base hierarchy for CStateSimpleSlide.
NativeRuntimeBaseList<3> lbl_802BB870 = {
    {
        { &lbl_80375088, 0 }, // CState
        { &lbl_80375090, 0 }, // CStateScriptBase
        { &lbl_80375098, 0 }, // CStateSimpleBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A2100Fv();
void fn_800A2074();
void fn_800A4DF0();
void fn_800A4E10();
void fn_800A4E50();
}

extern "C" __declspec(section ".data") const void* const lbl_802BB88C[7] __attribute__((aligned(4))) = {
    &lbl_803750A0,
    0,
    (const void*)__dt__15Object_800A2100Fv,
    (const void*)fn_800A2074,
    (const void*)fn_800A4DF0,
    (const void*)fn_800A4E50,
    (const void*)fn_800A4E10,
};

