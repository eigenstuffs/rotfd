#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateMemCardInsufficientMemory.
NativeRuntimeBaseList<2> lbl_802C93E0 = {
    {
        { &lbl_80375BD0, 0 }, // CState
        { &lbl_80375BD8, 0 }, // CStateGCCardBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800EFD20Fv();
void __dt__15Object_800EFDACFv();
void fn_800EC6D8();
void fn_800EC7D4();
void fn_800EC82C();
void fn_800EC93C();
void fn_800ECB44();
void fn_800ECC18();
}

extern "C" __declspec(section ".data") const void* const lbl_802C93F4[6] __attribute__((aligned(4))) = {
    &lbl_80375C28,
    0,
    (const void*)__dt__15Object_800EFD20Fv,
    (const void*)fn_800EC93C,
    (const void*)fn_800ECB44,
    (const void*)fn_800ECC18,
};

extern "C" NativeRuntimeBaseList<2> lbl_802C940C = {
    {
        {&lbl_80375BD0, 0},
        {&lbl_80375BD8, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802C9420[6] __attribute__((aligned(4))) = {
    &lbl_80375C30,
    0,
    (const void*)__dt__15Object_800EFDACFv,
    (const void*)fn_800EC6D8,
    (const void*)fn_800EC7D4,
    (const void*)fn_800EC82C,
};

