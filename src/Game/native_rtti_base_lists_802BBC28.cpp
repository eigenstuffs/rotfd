#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateSimpleWander.
NativeRuntimeBaseList<3> lbl_802BBC28 = {
    {
        { &lbl_80375088, 0 }, // CState
        { &lbl_80375090, 0 }, // CStateScriptBase
        { &lbl_80375098, 0 }, // CStateSimpleBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800A2B5CFv();
void fn_800A0878();
void fn_800A08D0();
void fn_800A09C4();
void fn_800A4E10();
}

extern "C" __declspec(section ".data") const void* const lbl_802BBC44[7] __attribute__((aligned(4))) = {
    &lbl_80375128,
    0,
    (const void*)__dt__15Object_800A2B5CFv,
    (const void*)fn_800A0878,
    (const void*)fn_800A08D0,
    (const void*)fn_800A09C4,
    (const void*)fn_800A4E10,
};

