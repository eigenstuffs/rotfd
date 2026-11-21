#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateWildSnailIdle.
NativeRuntimeBaseList<2> lbl_802BB2A0 = {
    {
        { &lbl_80374FC8, 0 }, // CState
        { &lbl_80374FD0, 0 }, // CStateWildSnailBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8009CFE4Fv();
void fn_8009C288();
void fn_8009C304();
void fn_8009C400();
void fn_8009C638();
void fn_8009D070();
void fn_8009D074();
void fn_8009D078();
}

extern "C" __declspec(section ".data") const void* const lbl_802BB2B4[6] __attribute__((aligned(4))) = {
    &lbl_80374FF0,
    0,
    (const void*)__dt__15Object_8009CFE4Fv,
    (const void*)fn_8009C304,
    (const void*)fn_8009C400,
    (const void*)fn_8009C638,
};

extern "C" __declspec(section ".data") const void* const lbl_802BB2CC[7] __attribute__((aligned(4))) = {
    &lbl_80374FD0,
    0,
    (const void*)fn_8009C288,
    (const void*)fn_8009D070,
    (const void*)fn_8009D074,
    (const void*)fn_8009D078,
    0,
};

