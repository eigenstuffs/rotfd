#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateSimpleAttackRnd.
NativeRuntimeBaseList<3> lbl_802BBC98 = {
    {
        { &lbl_80375088, 0 }, // CState
        { &lbl_80375090, 0 }, // CStateScriptBase
        { &lbl_80375098, 0 }, // CStateSimpleBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A2C94Fv();
void fn_800A0028();
void fn_800A4DF0();
void fn_800A4E10();
void fn_800A4E50();
}

extern "C" __declspec(section ".data") const void* const lbl_802BBCB4[7] __attribute__((aligned(4))) = {
    &lbl_80375138,
    0,
    (const void*)__dt__15Object_800A2C94Fv,
    (const void*)fn_800A0028,
    (const void*)fn_800A4DF0,
    (const void*)fn_800A4E50,
    (const void*)fn_800A4E10,
};

