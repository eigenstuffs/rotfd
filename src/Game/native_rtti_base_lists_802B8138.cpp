#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CTreasureChestBaseState.
NativeRuntimeBaseList<1> lbl_802B8138 = {
    {
        { &lbl_80374918, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateTreasureChestOpen.
NativeRuntimeBaseList<2> lbl_802B8144 = {
    {
        { &lbl_80374918, 0 }, // CState
        { &lbl_80374920, 0 }, // CTreasureChestBaseState
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800753A4Fv();
void fn_8007517C();
void fn_800751F4();
void fn_800753A0();
}

extern "C" __declspec(section ".data") const void* const lbl_802B8158[6] __attribute__((aligned(4))) = {
    &lbl_80374928,
    0,
    (const void*)__dt__15Object_800753A4Fv,
    (const void*)fn_8007517C,
    (const void*)fn_800751F4,
    (const void*)fn_800753A0,
};

