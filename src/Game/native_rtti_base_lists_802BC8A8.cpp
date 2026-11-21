#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateScriptBase.
NativeRuntimeBaseList<1> lbl_802BC8A8 = {
    {
        { &lbl_803752D8, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateSimpleBase.
NativeRuntimeBaseList<2> lbl_802BC8B4 = {
    {
        { &lbl_803752D8, 0 }, // CState
        { &lbl_803752E0, 0 }, // CStateScriptBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8009FE8CFv();
void fn_800A4DF0();
void fn_800A4E10();
void fn_800A4E30();
void fn_800A4E50();
}

extern "C" __declspec(section ".data") const void* const lbl_802BC8C8[8] __attribute__((aligned(4))) = {
    &lbl_803752E8,
    0,
    (const void*)__dt__15Object_8009FE8CFv,
    (const void*)fn_800A4E30,
    (const void*)fn_800A4DF0,
    (const void*)fn_800A4E50,
    (const void*)fn_800A4E10,
    0,
};

