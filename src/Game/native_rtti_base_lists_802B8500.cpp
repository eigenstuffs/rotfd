#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateProjIdle.
NativeRuntimeBaseList<2> lbl_802B8500 = {
    {
        { &lbl_803749A8, 0 }, // CState
        { &lbl_803749B0, 0 }, // CStateProjBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_80080250Fv();
void fn_80080174();
void fn_800802DC();
void fn_800804EC();
void fn_8008084C();
void fn_8008135C();
void fn_80081360();
void fn_80081364();
}

extern "C" __declspec(section ".data") const void* const lbl_802B8514[6] __attribute__((aligned(4))) = {
    &lbl_803749D0,
    0,
    (const void*)__dt__15Object_80080250Fv,
    (const void*)fn_800802DC,
    (const void*)fn_800804EC,
    (const void*)fn_8008084C,
};

extern "C" __declspec(section ".data") const void* const lbl_802B852C[6] __attribute__((aligned(4))) = {
    &lbl_803749B0,
    0,
    (const void*)fn_80080174,
    (const void*)fn_8008135C,
    (const void*)fn_80081360,
    (const void*)fn_80081364,
};

extern "C" NativeRuntimeBaseList<1> lbl_802B8544 = {
    {
        {&lbl_803749E0, 0},
    }, 0
};

