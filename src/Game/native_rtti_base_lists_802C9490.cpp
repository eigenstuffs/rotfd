#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateCheckMemCardSave.
NativeRuntimeBaseList<2> lbl_802C9490 = {
    {
        { &lbl_80375BD0, 0 }, // CState
        { &lbl_80375BD8, 0 }, // CStateGCCardBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800EFF50Fv();
void __dt__15Object_800EFFDCFv();
void fn_800EBA6C();
void fn_800EBBF8();
void fn_800EBCC0();
void fn_800EBDE0();
void fn_800EBF1C();
void fn_800EBFA8();
}

extern "C" __declspec(section ".data") const void* const lbl_802C94A4[6] __attribute__((aligned(4))) = {
    &lbl_80375C48,
    0,
    (const void*)__dt__15Object_800EFF50Fv,
    (const void*)fn_800EBDE0,
    (const void*)fn_800EBF1C,
    (const void*)fn_800EBFA8,
};

extern "C" NativeRuntimeBaseList<2> lbl_802C94BC = {
    {
        {&lbl_80375BD0, 0},
        {&lbl_80375BD8, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802C94D0[6] __attribute__((aligned(4))) = {
    &lbl_80375C50,
    0,
    (const void*)__dt__15Object_800EFFDCFv,
    (const void*)fn_800EBA6C,
    (const void*)fn_800EBBF8,
    (const void*)fn_800EBCC0,
};

