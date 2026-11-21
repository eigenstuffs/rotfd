#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateTreasureDetectorActive.
NativeRuntimeBaseList<2> lbl_802B8E30 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_80085B88Fv();
void fn_80081414();
void fn_80085C14();
void fn_80085E88();
void fn_800861A0();
}

extern "C" __declspec(section ".data") const void* const lbl_802B8E44[7] __attribute__((aligned(4))) = {
    &lbl_80374B3C,
    0,
    (const void*)__dt__15Object_80085B88Fv,
    (const void*)fn_80085C14,
    (const void*)fn_80085E88,
    (const void*)fn_800861A0,
    (const void*)fn_80081414,
};

