#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateSimpleAttack.
NativeRuntimeBaseList<3> lbl_802BBCD0 = {
    {
        { &lbl_80375088, 0 }, // CState
        { &lbl_80375090, 0 }, // CStateScriptBase
        { &lbl_80375098, 0 }, // CStateSimpleBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A2D30Fv();
void fn_8009FFB0();
void fn_800A4DF0();
void fn_800A4E10();
void fn_800A4E50();
}

extern "C" __declspec(section ".data") const void* const lbl_802BBCEC[7] __attribute__((aligned(4))) = {
    &lbl_80375140,
    0,
    (const void*)__dt__15Object_800A2D30Fv,
    (const void*)fn_8009FFB0,
    (const void*)fn_800A4DF0,
    (const void*)fn_800A4E50,
    (const void*)fn_800A4E10,
};

