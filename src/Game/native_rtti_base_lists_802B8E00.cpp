#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateReefBlowerActive.
NativeRuntimeBaseList<2> lbl_802B8E00 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800862C0Fv();
void fn_80081414();
void fn_8008634C();
void fn_800865A4();
void fn_80086654();
}

extern "C" __declspec(section ".data") const void* const lbl_802B8E14[7] __attribute__((aligned(4))) = {
    &lbl_80374B34,
    0,
    (const void*)__dt__15Object_800862C0Fv,
    (const void*)fn_8008634C,
    (const void*)fn_800865A4,
    (const void*)fn_80086654,
    (const void*)fn_80081414,
};

