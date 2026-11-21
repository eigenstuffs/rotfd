#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateQSBase.
NativeRuntimeBaseList<1> lbl_802C1850 = {
    {
        { &lbl_80375908, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateQSWander.
NativeRuntimeBaseList<2> lbl_802C185C = {
    {
        { &lbl_80375908, 0 }, // CState
        { &lbl_80375910, 0 }, // CStateQSBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800CBC80Fv();
void __dt__15Object_800CBD74Fv();
void __dt__15Object_800CBF50Fv();
void __dt__15Object_800CC08CFv();
void __dt__15Object_800CC4C0Fv();
void fn_800CBE0C();
void fn_800CBEDC();
void fn_800CBEE0();
void fn_800CBFE8();
void fn_800CC018();
void fn_800CC01C();
void fn_800CC124();
void fn_800CC150();
void fn_800CC154();
void fn_800CC450();
void fn_800CC558();
void fn_800CC584();
void fn_800CC630();
void fn_800CC634();
void fn_800CC638();
void fn_800CC63C();
void fn_800CC640();
}

extern "C" __declspec(section ".data") const void* const lbl_802C1870[7] __attribute__((aligned(4))) = {
    &lbl_80375918,
    0,
    (const void*)__dt__15Object_800CC4C0Fv,
    (const void*)fn_800CC558,
    (const void*)fn_800CC584,
    (const void*)fn_800CC630,
    (const void*)fn_800CC634,
};

extern "C" NativeRuntimeBaseList<2> lbl_802C188C = {
    {
        {&lbl_80375908, 0},
        {&lbl_80375910, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802C18A0[7] __attribute__((aligned(4))) = {
    &lbl_80375920,
    0,
    (const void*)__dt__15Object_800CC08CFv,
    (const void*)fn_800CC124,
    (const void*)fn_800CC150,
    (const void*)fn_800CC450,
    (const void*)fn_800CC154,
};

extern "C" NativeRuntimeBaseList<2> lbl_802C18BC = {
    {
        {&lbl_80375908, 0},
        {&lbl_80375910, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802C18D0[7] __attribute__((aligned(4))) = {
    &lbl_80375928,
    0,
    (const void*)__dt__15Object_800CBF50Fv,
    (const void*)fn_800CBFE8,
    (const void*)fn_800CC018,
    (const void*)fn_800CC01C,
    (const void*)fn_800CC634,
};

extern "C" NativeRuntimeBaseList<2> lbl_802C18EC = {
    {
        {&lbl_80375908, 0},
        {&lbl_80375910, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802C1900[7] __attribute__((aligned(4))) = {
    &lbl_80375930,
    0,
    (const void*)__dt__15Object_800CBD74Fv,
    (const void*)fn_800CBE0C,
    (const void*)fn_800CBEDC,
    (const void*)fn_800CBEE0,
    (const void*)fn_800CC634,
};

extern "C" __declspec(section ".data") const void* const lbl_802C191C[7] __attribute__((aligned(4))) = {
    &lbl_80375910,
    0,
    (const void*)__dt__15Object_800CBC80Fv,
    (const void*)fn_800CC638,
    (const void*)fn_800CC63C,
    (const void*)fn_800CC640,
    (const void*)fn_800CC634,
};

