#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateGlide.
NativeRuntimeBaseList<2> lbl_802B8D70 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8008F280Fv();
void fn_80081414();
void fn_8008761C();
void fn_800876DC();
void fn_800877B8();
}

extern "C" __declspec(section ".data") const void* const lbl_802B8D84[7] __attribute__((aligned(4))) = {
    &lbl_80374B1C,
    0,
    (const void*)__dt__15Object_8008F280Fv,
    (const void*)fn_8008761C,
    (const void*)fn_800876DC,
    (const void*)fn_800877B8,
    (const void*)fn_80081414,
};

