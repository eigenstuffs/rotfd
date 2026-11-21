#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateSlide.
NativeRuntimeBaseList<2> lbl_802B9160 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8008FC8CFv();
void fn_8008250C();
void fn_80082570();
void fn_800826B4();
void fn_80082860();
}

extern "C" __declspec(section ".data") const void* const lbl_802B9174[7] __attribute__((aligned(4))) = {
    &lbl_80374BC4,
    0,
    (const void*)__dt__15Object_8008FC8CFv,
    (const void*)fn_8008250C,
    (const void*)fn_80082570,
    (const void*)fn_80082860,
    (const void*)fn_800826B4,
};

