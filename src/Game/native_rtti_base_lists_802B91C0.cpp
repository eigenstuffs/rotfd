#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateHoopRoll.
NativeRuntimeBaseList<2> lbl_802B91C0 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8008FDA4Fv();
void fn_80081414();
void fn_80081CCC();
void fn_80081D88();
void fn_800820E8();
}

extern "C" __declspec(section ".data") const void* const lbl_802B91D4[7] __attribute__((aligned(4))) = {
    &lbl_80374BD4,
    0,
    (const void*)__dt__15Object_8008FDA4Fv,
    (const void*)fn_80081CCC,
    (const void*)fn_80081D88,
    (const void*)fn_800820E8,
    (const void*)fn_80081414,
};

