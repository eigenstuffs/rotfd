#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateReefBlowerActiveRunning.
NativeRuntimeBaseList<2> lbl_802B8DD0 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800868CCFv();
void fn_80081414();
void fn_80086958();
void fn_80086BB0();
void fn_80086C7C();
}

extern "C" __declspec(section ".data") const void* const lbl_802B8DE4[7] __attribute__((aligned(4))) = {
    &lbl_80374B2C,
    0,
    (const void*)__dt__15Object_800868CCFv,
    (const void*)fn_80086958,
    (const void*)fn_80086BB0,
    (const void*)fn_80086C7C,
    (const void*)fn_80081414,
};

