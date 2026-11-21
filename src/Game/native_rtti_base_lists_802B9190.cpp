#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateSkid.
NativeRuntimeBaseList<2> lbl_802B9190 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8008FD18Fv();
void fn_80081414();
void fn_80082274();
void fn_800822D0();
void fn_80082444();
}

extern "C" __declspec(section ".data") const void* const lbl_802B91A4[7] __attribute__((aligned(4))) = {
    &lbl_80374BCC,
    0,
    (const void*)__dt__15Object_8008FD18Fv,
    (const void*)fn_80082274,
    (const void*)fn_800822D0,
    (const void*)fn_80082444,
    (const void*)fn_80081414,
};

