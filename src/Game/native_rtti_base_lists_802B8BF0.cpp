#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateThrow.
NativeRuntimeBaseList<2> lbl_802B8BF0 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8008EE20Fv();
void fn_80081414();
void fn_80088758();
void fn_800887B8();
void fn_80088B08();
}

extern "C" __declspec(section ".data") const void* const lbl_802B8C04[7] __attribute__((aligned(4))) = {
    &lbl_80374ADC,
    0,
    (const void*)__dt__15Object_8008EE20Fv,
    (const void*)fn_80088758,
    (const void*)fn_800887B8,
    (const void*)fn_80088B08,
    (const void*)fn_80081414,
};

