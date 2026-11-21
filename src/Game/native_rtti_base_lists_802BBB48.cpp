#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateSimpleChase.
NativeRuntimeBaseList<3> lbl_802BBB48 = {
    {
        { &lbl_80375088, 0 }, // CState
        { &lbl_80375090, 0 }, // CStateScriptBase
        { &lbl_80375098, 0 }, // CStateSimpleBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A28ECFv();
void fn_800A0F18();
void fn_800A0F54();
void fn_800A4E10();
void fn_800A4E50();
}

extern "C" __declspec(section ".data") const void* const lbl_802BBB64[7] __attribute__((aligned(4))) = {
    &lbl_80375108,
    0,
    (const void*)__dt__15Object_800A28ECFv,
    (const void*)fn_800A0F18,
    (const void*)fn_800A0F54,
    (const void*)fn_800A4E50,
    (const void*)fn_800A4E10,
};

