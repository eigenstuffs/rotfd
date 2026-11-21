#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateTreasureChestClosed.
NativeRuntimeBaseList<2> lbl_802B8170 = {
    {
        { &lbl_80374918, 0 }, // CState
        { &lbl_80374920, 0 }, // CTreasureChestBaseState
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_80075430Fv();
void fn_8007509C();
void fn_80075118();
void fn_8007511C();
void fn_80075120();
void fn_800754BC();
void fn_800754C0();
void fn_800754C4();
}

extern "C" __declspec(section ".data") const void* const lbl_802B8184[6] __attribute__((aligned(4))) = {
    &lbl_80374930,
    0,
    (const void*)__dt__15Object_80075430Fv,
    (const void*)fn_80075118,
    (const void*)fn_8007511C,
    (const void*)fn_80075120,
};

extern "C" __declspec(section ".data") const void* const lbl_802B819C[7] __attribute__((aligned(4))) = {
    &lbl_80374920,
    0,
    (const void*)fn_8007509C,
    (const void*)fn_800754BC,
    (const void*)fn_800754C0,
    (const void*)fn_800754C4,
    0,
};

