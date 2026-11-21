#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateSimpleGetHit.
NativeRuntimeBaseList<3> lbl_802BBA68 = {
    {
        { &lbl_80375088, 0 }, // CState
        { &lbl_80375090, 0 }, // CStateScriptBase
        { &lbl_80375098, 0 }, // CStateSimpleBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A267CFv();
void fn_800A150C();
void fn_800A1554();
void fn_800A4E10();
void fn_800A4E50();
}

extern "C" __declspec(section ".data") const void* const lbl_802BBA84[7] __attribute__((aligned(4))) = {
    &lbl_803750E8,
    0,
    (const void*)__dt__15Object_800A267CFv,
    (const void*)fn_800A150C,
    (const void*)fn_800A1554,
    (const void*)fn_800A4E50,
    (const void*)fn_800A4E10,
};

