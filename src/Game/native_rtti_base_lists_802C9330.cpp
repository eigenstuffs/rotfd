#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateCardFormatting.
NativeRuntimeBaseList<2> lbl_802C9330 = {
    {
        { &lbl_80375BD0, 0 }, // CState
        { &lbl_80375BD8, 0 }, // CStateGCCardBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800EFAF0Fv();
void __dt__15Object_800EFB7CFv();
void fn_800ED7C0();
void fn_800ED9C8();
void fn_800EDA78();
void fn_800EDCAC();
void fn_800EDED0();
void fn_800EDFE4();
}

extern "C" __declspec(section ".data") const void* const lbl_802C9344[6] __attribute__((aligned(4))) = {
    &lbl_80375C08,
    0,
    (const void*)__dt__15Object_800EFAF0Fv,
    (const void*)fn_800EDCAC,
    (const void*)fn_800EDED0,
    (const void*)fn_800EDFE4,
};

extern "C" NativeRuntimeBaseList<2> lbl_802C935C = {
    {
        {&lbl_80375BD0, 0},
        {&lbl_80375BD8, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802C9370[6] __attribute__((aligned(4))) = {
    &lbl_80375C10,
    0,
    (const void*)__dt__15Object_800EFB7CFv,
    (const void*)fn_800ED7C0,
    (const void*)fn_800ED9C8,
    (const void*)fn_800EDA78,
};

