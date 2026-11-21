#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateNotAMemCard.
NativeRuntimeBaseList<2> lbl_802C9540 = {
    {
        { &lbl_80375BD0, 0 }, // CState
        { &lbl_80375BD8, 0 }, // CStateGCCardBase
    }, 0
};

}

// Adjacent native method and runtime-base records.

extern "C" {
void __dt__15Object_800F0180Fv();
void fn_800EAE50();
void fn_800EB058();
void fn_800EB0D4();
}

extern "C" __declspec(section ".data") const void* const lbl_802C9554[6] __attribute__((aligned(4))) = {
    &lbl_80375C68,
    0,
    (const void*)__dt__15Object_800F0180Fv,
    (const void*)fn_800EAE50,
    (const void*)fn_800EB058,
    (const void*)fn_800EB0D4,
};

extern "C" NativeRuntimeBaseList<2> lbl_802C956C = {
    {
        { &lbl_80375BD0, 0 },
        { &lbl_80375BD8, 0 },
    }, 0
};

