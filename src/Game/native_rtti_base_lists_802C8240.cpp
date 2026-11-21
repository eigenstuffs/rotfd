#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateWaterHelmetBase.
NativeRuntimeBaseList<1> lbl_802C8240 = {
    {
        { &lbl_803759D8, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateHelmetMoving.
NativeRuntimeBaseList<2> lbl_802C824C = {
    {
        { &lbl_803759D8, 0 }, // CState
        { &lbl_803759E0, 0 }, // CStateWaterHelmetBase
    }, 0
};

}

// Adjacent native method and runtime-base records.

extern "C" {
void __dt__15Object_800E04CCFv();
void __dt__15Object_800E0DA4Fv();
void __dt__15Object_800E0E40Fv();
void fn_800E05B4();
void fn_800E079C();
void fn_800E0AEC();
void fn_800E0D94();
void fn_800E0E3C();
void fn_800E0ED8();
void fn_800E0EDC();
void fn_800E0EE0();
}

extern "C" __declspec(section ".data") const void* const lbl_802C8260[7] __attribute__((aligned(4))) = {
    &lbl_803759E8,
    0,
    (const void*)__dt__15Object_800E0DA4Fv,
    (const void*)fn_800E079C,
    (const void*)fn_800E0E3C,
    (const void*)fn_800E0D94,
    (const void*)fn_800E0AEC,
};

extern "C" NativeRuntimeBaseList<2> lbl_802C827C = {
    {
        { &lbl_803759D8, 0 },
        { &lbl_803759E0, 0 },
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802C8290[7] __attribute__((aligned(4))) = {
    &lbl_803759F0,
    0,
    (const void*)__dt__15Object_800E0E40Fv,
    (const void*)fn_800E0ED8,
    (const void*)fn_800E05B4,
    (const void*)fn_800E0EE0,
    (const void*)fn_800E0EDC,
};

extern "C" __declspec(section ".data") const void* const lbl_802C82AC[7] __attribute__((aligned(4))) = {
    &lbl_803759E0,
    0,
    (const void*)__dt__15Object_800E04CCFv,
    (const void*)fn_800E0ED8,
    (const void*)fn_800E0E3C,
    (const void*)fn_800E0EE0,
    (const void*)fn_800E0EDC,
};

