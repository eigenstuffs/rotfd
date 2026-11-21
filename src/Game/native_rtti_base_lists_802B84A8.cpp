#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateProjMoving.
NativeRuntimeBaseList<2> lbl_802B84A8 = {
    {
        { &lbl_803749A8, 0 }, // CState
        { &lbl_803749B0, 0 }, // CStateProjBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800808B0Fv();
void __dt__15Object_80080B34Fv();
void fn_8008093C();
void fn_80080A48();
void fn_80080AD0();
void fn_80080BC0();
void fn_80080CCC();
void fn_800810B0();
}

extern "C" __declspec(section ".data") const void* const lbl_802B84BC[6] __attribute__((aligned(4))) = {
    &lbl_803749C0,
    0,
    (const void*)__dt__15Object_80080B34Fv,
    (const void*)fn_80080BC0,
    (const void*)fn_80080CCC,
    (const void*)fn_800810B0,
};

extern "C" NativeRuntimeBaseList<2> lbl_802B84D4 = {
    {
        {&lbl_803749A8, 0},
        {&lbl_803749B0, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802B84E8[6] __attribute__((aligned(4))) = {
    &lbl_803749C8,
    0,
    (const void*)__dt__15Object_800808B0Fv,
    (const void*)fn_8008093C,
    (const void*)fn_80080A48,
    (const void*)fn_80080AD0,
};

