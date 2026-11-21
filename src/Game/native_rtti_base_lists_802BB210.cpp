#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateWildSnailBase.
NativeRuntimeBaseList<1> lbl_802BB210 = {
    {
        { &lbl_80374FC8, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateWildSnailReturn.
NativeRuntimeBaseList<2> lbl_802BB21C = {
    {
        { &lbl_80374FC8, 0 }, // CState
        { &lbl_80374FD0, 0 }, // CStateWildSnailBase
    }, 0
};

}

// Adjacent native method and runtime-base records.

extern "C" {
void __dt__15Object_8009CE40Fv();
void fn_8009CBD0();
void fn_8009CC54();
void fn_8009CDCC();
}

extern "C" __declspec(section ".data") const void* const lbl_802BB230[6] __attribute__((aligned(4))) = {
    &lbl_80374FD8,
    0,
    (const void*)__dt__15Object_8009CE40Fv,
    (const void*)fn_8009CBD0,
    (const void*)fn_8009CC54,
    (const void*)fn_8009CDCC,
};

