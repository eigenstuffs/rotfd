#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateGCDoNothing.
NativeRuntimeBaseList<2> lbl_802C9650 = {
    {
        { &lbl_80375BD0, 0 }, // CState
        { &lbl_80375BD8, 0 }, // CStateGCCardBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800F044CFv();
void fn_800E95C4();
void fn_800E9640();
void fn_800E9644();
void fn_800F04D8();
void fn_800F04DC();
void fn_800F04E0();
void fn_800F04E4();
}

extern "C" __declspec(section ".data") const void* const lbl_802C9664[6] __attribute__((aligned(4))) = {
    &lbl_80375C98,
    0,
    (const void*)__dt__15Object_800F044CFv,
    (const void*)fn_800E9640,
    (const void*)fn_800F04D8,
    (const void*)fn_800E9644,
};

extern "C" __declspec(section ".data") const void* const lbl_802C967C[7] __attribute__((aligned(4))) = {
    &lbl_80375BD8,
    0,
    (const void*)fn_800E95C4,
    (const void*)fn_800F04DC,
    (const void*)fn_800F04E0,
    (const void*)fn_800F04E4,
    0,
};

