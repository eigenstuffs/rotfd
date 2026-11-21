#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateDeleteComplete.
NativeRuntimeBaseList<2> lbl_802C9280 = {
    {
        { &lbl_80375BD0, 0 }, // CState
        { &lbl_80375BD8, 0 }, // CStateGCCardBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800EF8C0Fv();
void __dt__15Object_800EF94CFv();
void fn_800EEB6C();
void fn_800EED7C();
void fn_800EEE38();
void fn_800EF060();
void fn_800EF268();
void fn_800EF2F8();
}

extern "C" __declspec(section ".data") const void* const lbl_802C9294[6] __attribute__((aligned(4))) = {
    &lbl_80375BE8,
    0,
    (const void*)__dt__15Object_800EF8C0Fv,
    (const void*)fn_800EF060,
    (const void*)fn_800EF268,
    (const void*)fn_800EF2F8,
};

extern "C" NativeRuntimeBaseList<2> lbl_802C92AC = {
    {
        {&lbl_80375BD0, 0},
        {&lbl_80375BD8, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802C92C0[6] __attribute__((aligned(4))) = {
    &lbl_80375BF0,
    0,
    (const void*)__dt__15Object_800EF94CFv,
    (const void*)fn_800EEB6C,
    (const void*)fn_800EED7C,
    (const void*)fn_800EEE38,
};

