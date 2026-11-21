#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateDefeated.
NativeRuntimeBaseList<2> lbl_802B8B90 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.

extern "C" {
void __dt__15Object_8008ED94Fv();
void fn_80081414();
void fn_80088FF4();
void fn_800890E0();
void fn_80089150();
}

extern "C" __declspec(section ".data") const void* const lbl_802B8BA4[7] __attribute__((aligned(4))) = {
    &lbl_80374ACC,
    0,
    (const void*)__dt__15Object_8008ED94Fv,
    (const void*)fn_80088FF4,
    (const void*)fn_800890E0,
    (const void*)fn_80089150,
    (const void*)fn_80081414,
};

