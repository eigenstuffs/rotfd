#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateScriptBase.
NativeRuntimeBaseList<1> lbl_802BC040 = {
    {
        { &lbl_803751A0, 0 }, // CState
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void fn_800A3798();
void fn_800A379C();
void fn_800A37D0();
void fn_800A386C();
void fn_800A38FC();
}

extern "C" __declspec(section ".data") const void* const lbl_802BC04C[7] __attribute__((aligned(4))) = {
    &lbl_803751A8,
    0,
    (const void*)fn_800A38FC,
    (const void*)fn_800A37D0,
    (const void*)fn_800A3798,
    (const void*)fn_800A386C,
    (const void*)fn_800A379C,
};

