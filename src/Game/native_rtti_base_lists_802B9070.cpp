#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateDuck.
NativeRuntimeBaseList<2> lbl_802B9070 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8008F9D0Fv();
void fn_80081414();
void fn_80083574();
void fn_80083634();
void fn_800839B8();
}

extern "C" __declspec(section ".data") const void* const lbl_802B9084[7] __attribute__((aligned(4))) = {
    &lbl_80374B9C,
    0,
    (const void*)__dt__15Object_8008F9D0Fv,
    (const void*)fn_80083574,
    (const void*)fn_80083634,
    (const void*)fn_800839B8,
    (const void*)fn_80081414,
};

