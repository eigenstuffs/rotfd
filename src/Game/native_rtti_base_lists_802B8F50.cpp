#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateKarateDuckAttack.
NativeRuntimeBaseList<2> lbl_802B8F50 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8008F688Fv();
void fn_80081414();
void fn_800844CC();
void fn_8008452C();
void fn_80084578();
}

extern "C" __declspec(section ".data") const void* const lbl_802B8F64[7] __attribute__((aligned(4))) = {
    &lbl_80374B6C,
    0,
    (const void*)__dt__15Object_8008F688Fv,
    (const void*)fn_800844CC,
    (const void*)fn_8008452C,
    (const void*)fn_80084578,
    (const void*)fn_80081414,
};

