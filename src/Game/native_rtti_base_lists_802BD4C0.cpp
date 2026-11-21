#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateWBLinked.
NativeRuntimeBaseList<2> lbl_802BD4C0 = {
    {
        { &lbl_80375400, 0 }, // CState
        { &lbl_80375408, 0 }, // CStateWBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800AE414Fv();
void __dt__15Object_800AE758Fv();
void fn_800AE338();
void fn_800AE4A0();
void fn_800AE6F0();
void fn_800AE6F4();
void fn_800AE7E4();
void fn_800AEBE4();
void fn_800AEE00();
void fn_800AF29C();
void fn_800AF2A0();
void fn_800AF2A4();
}

extern "C" __declspec(section ".data") const void* const lbl_802BD4D4[6] __attribute__((aligned(4))) = {
    &lbl_80375418,
    0,
    (const void*)__dt__15Object_800AE758Fv,
    (const void*)fn_800AE7E4,
    (const void*)fn_800AEBE4,
    (const void*)fn_800AEE00,
};

extern "C" NativeRuntimeBaseList<2> lbl_802BD4EC = {
    {
        {&lbl_80375400, 0},
        {&lbl_80375408, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802BD500[6] __attribute__((aligned(4))) = {
    &lbl_80375420,
    0,
    (const void*)__dt__15Object_800AE414Fv,
    (const void*)fn_800AE4A0,
    (const void*)fn_800AE6F0,
    (const void*)fn_800AE6F4,
};

extern "C" __declspec(section ".data") const void* const lbl_802BD518[6] __attribute__((aligned(4))) = {
    &lbl_80375408,
    0,
    (const void*)fn_800AE338,
    (const void*)fn_800AF29C,
    (const void*)fn_800AF2A0,
    (const void*)fn_800AF2A4,
};

