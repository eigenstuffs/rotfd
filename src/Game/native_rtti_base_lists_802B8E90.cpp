#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateCannonFire.
NativeRuntimeBaseList<2> lbl_802B8E90 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8008F424Fv();
void fn_80081414();
void fn_80085590();
void fn_800857A8();
void fn_8008585C();
}

extern "C" __declspec(section ".data") const void* const lbl_802B8EA4[7] __attribute__((aligned(4))) = {
    &lbl_80374B4C,
    0,
    (const void*)__dt__15Object_8008F424Fv,
    (const void*)fn_80085590,
    (const void*)fn_800857A8,
    (const void*)fn_8008585C,
    (const void*)fn_80081414,
};

