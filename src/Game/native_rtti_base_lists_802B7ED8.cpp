#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateCollectableBase.
NativeRuntimeBaseList<1> lbl_802B7ED8 = {
    {
        { &lbl_803748C0, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateCollectableSpinBob.
NativeRuntimeBaseList<2> lbl_802B7EE4 = {
    {
        { &lbl_803748C0, 0 }, // CState
        { &lbl_803748C8, 0 }, // CStateCollectableBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800749F8Fv();
void __dt__15Object_80074A8CFv();
void __dt__15Object_80074B20Fv();
void fn_80074434();
void fn_800744D4();
void fn_80074550();
void fn_80074560();
void fn_800746AC();
void fn_80074708();
void fn_8007484C();
void fn_800748B4();
void fn_80074A84();
void fn_80074A88();
void fn_80074B18();
void fn_80074B1C();
void fn_80074BAC();
void fn_80074BB0();
void fn_80074BB4();
void fn_80074BB8();
void fn_80074BBC();
}

extern "C" __declspec(section ".data") const void* const lbl_802B7EF8[7] __attribute__((aligned(4))) = {
    &lbl_803748D0,
    0,
    (const void*)__dt__15Object_800749F8Fv,
    (const void*)fn_8007484C,
    (const void*)fn_80074A84,
    (const void*)fn_80074A88,
    (const void*)fn_800748B4,
};

extern "C" NativeRuntimeBaseList<2> lbl_802B7F14 = {
    {
        {&lbl_803748C0, 0},
        {&lbl_803748C8, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802B7F28[7] __attribute__((aligned(4))) = {
    &lbl_803748D8,
    0,
    (const void*)__dt__15Object_80074A8CFv,
    (const void*)fn_800746AC,
    (const void*)fn_80074B18,
    (const void*)fn_80074B1C,
    (const void*)fn_80074708,
};

extern "C" NativeRuntimeBaseList<2> lbl_802B7F44 = {
    {
        {&lbl_803748C0, 0},
        {&lbl_803748C8, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802B7F58[7] __attribute__((aligned(4))) = {
    &lbl_803748E0,
    0,
    (const void*)__dt__15Object_80074B20Fv,
    (const void*)fn_80074550,
    (const void*)fn_80074BAC,
    (const void*)fn_80074BB0,
    (const void*)fn_80074560,
};

extern "C" __declspec(section ".data") const void* const lbl_802B7F74[7] __attribute__((aligned(4))) = {
    &lbl_803748C8,
    0,
    (const void*)fn_800744D4,
    (const void*)fn_80074BB4,
    (const void*)fn_80074BB8,
    (const void*)fn_80074BBC,
    (const void*)fn_80074434,
};

