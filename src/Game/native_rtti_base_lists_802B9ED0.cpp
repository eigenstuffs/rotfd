#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateJFBase.
NativeRuntimeBaseList<1> lbl_802B9ED0 = {
    {
        { &lbl_80374D90, 0 }, // CState
    }, 0
};

// Base hierarchy for CStatePinkJFKeyframed.
NativeRuntimeBaseList<2> lbl_802B9EDC = {
    {
        { &lbl_80374D90, 0 }, // CState
        { &lbl_80374D98, 0 }, // CStateJFBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void fn_80095410();
void fn_80097188();
void fn_80097228();
void fn_8009722C();
void fn_80097230();
}

extern "C" __declspec(section ".data") const void* const lbl_802B9EF0[8] __attribute__((aligned(4))) = {
    &lbl_80374DA0,
    0,
    (const void*)fn_80097230,
    (const void*)fn_80097188,
    (const void*)fn_80097228,
    (const void*)fn_8009722C,
    (const void*)fn_80095410,
    0,
};

