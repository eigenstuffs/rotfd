#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateBellySlam.
NativeRuntimeBaseList<2> lbl_802B8DA0 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8008F30CFv();
void fn_80081414();
void fn_80086F00();
void fn_80087174();
void fn_80087394();
}

extern "C" __declspec(section ".data") const void* const lbl_802B8DB4[7] __attribute__((aligned(4))) = {
    &lbl_80374B24,
    0,
    (const void*)__dt__15Object_8008F30CFv,
    (const void*)fn_80086F00,
    (const void*)fn_80087174,
    (const void*)fn_80087394,
    (const void*)fn_80081414,
};

