#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateWildSnailFlee.
NativeRuntimeBaseList<2> lbl_802BB248 = {
    {
        { &lbl_80374FC8, 0 }, // CState
        { &lbl_80374FD0, 0 }, // CStateWildSnailBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8009CECCFv();
void __dt__15Object_8009CF58Fv();
void fn_8009C694();
void fn_8009C708();
void fn_8009C754();
void fn_8009C7B0();
void fn_8009C834();
void fn_8009CB04();
}

extern "C" __declspec(section ".data") const void* const lbl_802BB25C[6] __attribute__((aligned(4))) = {
    &lbl_80374FE0,
    0,
    (const void*)__dt__15Object_8009CECCFv,
    (const void*)fn_8009C7B0,
    (const void*)fn_8009C834,
    (const void*)fn_8009CB04,
};

extern "C" NativeRuntimeBaseList<2> lbl_802BB274 = {
    {
        {&lbl_80374FC8, 0},
        {&lbl_80374FD0, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802BB288[6] __attribute__((aligned(4))) = {
    &lbl_80374FE8,
    0,
    (const void*)__dt__15Object_8009CF58Fv,
    (const void*)fn_8009C694,
    (const void*)fn_8009C708,
    (const void*)fn_8009C754,
};

