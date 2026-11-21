#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateSimpleAlerted.
NativeRuntimeBaseList<3> lbl_802BBBB8 = {
    {
        { &lbl_80375088, 0 }, // CState
        { &lbl_80375090, 0 }, // CStateScriptBase
        { &lbl_80375098, 0 }, // CStateSimpleBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A2A24Fv();
void fn_800A0CC4();
void fn_800A4DF0();
void fn_800A4E10();
void fn_800A4E50();
}

extern "C" __declspec(section ".data") const void* const lbl_802BBBD4[7] __attribute__((aligned(4))) = {
    &lbl_80375118,
    0,
    (const void*)__dt__15Object_800A2A24Fv,
    (const void*)fn_800A0CC4,
    (const void*)fn_800A4DF0,
    (const void*)fn_800A4E50,
    (const void*)fn_800A4E10,
};

