#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateKarateJumpAttack.
NativeRuntimeBaseList<2> lbl_802B8F80 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8008F714Fv();
void fn_80081414();
void fn_800841F8();
void fn_80084264();
void fn_800842B0();
}

extern "C" __declspec(section ".data") const void* const lbl_802B8F94[7] __attribute__((aligned(4))) = {
    &lbl_80374B74,
    0,
    (const void*)__dt__15Object_8008F714Fv,
    (const void*)fn_800841F8,
    (const void*)fn_80084264,
    (const void*)fn_800842B0,
    (const void*)fn_80081414,
};

