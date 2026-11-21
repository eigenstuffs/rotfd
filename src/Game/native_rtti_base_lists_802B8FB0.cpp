#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateKaratePsychoCrusher.
NativeRuntimeBaseList<2> lbl_802B8FB0 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8008F7A0Fv();
void fn_80081414();
void fn_80083F90();
void fn_80083FF0();
void fn_8008413C();
}

extern "C" __declspec(section ".data") const void* const lbl_802B8FC4[7] __attribute__((aligned(4))) = {
    &lbl_80374B7C,
    0,
    (const void*)__dt__15Object_8008F7A0Fv,
    (const void*)fn_80083F90,
    (const void*)fn_80083FF0,
    (const void*)fn_8008413C,
    (const void*)fn_80081414,
};

