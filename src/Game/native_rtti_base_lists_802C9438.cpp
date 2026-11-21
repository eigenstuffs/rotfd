#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateMemCardSaving.
NativeRuntimeBaseList<2> lbl_802C9438 = {
    {
        { &lbl_80375BD0, 0 }, // CState
        { &lbl_80375BD8, 0 }, // CStateGCCardBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800EFE38Fv();
void __dt__15Object_800EFEC4Fv();
void fn_800EC0B8();
void fn_800EC1B4();
void fn_800EC20C();
void fn_800EC334();
void fn_800EC468();
void fn_800EC580();
}

extern "C" __declspec(section ".data") const void* const lbl_802C944C[6] __attribute__((aligned(4))) = {
    &lbl_80375C38,
    0,
    (const void*)__dt__15Object_800EFE38Fv,
    (const void*)fn_800EC334,
    (const void*)fn_800EC468,
    (const void*)fn_800EC580,
};

extern "C" NativeRuntimeBaseList<2> lbl_802C9464 = {
    {
        {&lbl_80375BD0, 0},
        {&lbl_80375BD8, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802C9478[6] __attribute__((aligned(4))) = {
    &lbl_80375C40,
    0,
    (const void*)__dt__15Object_800EFEC4Fv,
    (const void*)fn_800EC0B8,
    (const void*)fn_800EC1B4,
    (const void*)fn_800EC20C,
};

