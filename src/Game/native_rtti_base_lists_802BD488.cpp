#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateWBBase.
NativeRuntimeBaseList<1> lbl_802BD488 = {
    {
        { &lbl_80375400, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateWBMoving.
NativeRuntimeBaseList<2> lbl_802BD494 = {
    {
        { &lbl_80375400, 0 }, // CState
        { &lbl_80375408, 0 }, // CStateWBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800AEF5CFv();
void fn_800AEFE8();
void fn_800AF084();
void fn_800AF150();
}

extern "C" __declspec(section ".data") const void* const lbl_802BD4A8[6] __attribute__((aligned(4))) = {
    &lbl_80375410,
    0,
    (const void*)__dt__15Object_800AEF5CFv,
    (const void*)fn_800AEFE8,
    (const void*)fn_800AF084,
    (const void*)fn_800AF150,
};

