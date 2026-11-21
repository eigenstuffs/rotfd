#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateBounce.
NativeRuntimeBaseList<2> lbl_802B8E60 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8008F398Fv();
void fn_80081414();
void fn_80085958();
void fn_80085A04();
void fn_80085AAC();
}

extern "C" __declspec(section ".data") const void* const lbl_802B8E74[7] __attribute__((aligned(4))) = {
    &lbl_80374B44,
    0,
    (const void*)__dt__15Object_8008F398Fv,
    (const void*)fn_80085958,
    (const void*)fn_80085A04,
    (const void*)fn_80085AAC,
    (const void*)fn_80081414,
};

