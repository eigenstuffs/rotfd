#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateGCNoCardFoundLoading.
NativeRuntimeBaseList<3> lbl_802C9580 = {
    {
        { &lbl_80375BD0, 0 }, // CState
        { &lbl_80375BD8, 0 }, // CStateGCCardBase
        { &lbl_80375C70, 0 }, // CStateGCNoCardFound
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800EAB3CFv();
void __dt__15Object_800F02A8Fv();
void fn_800E9F9C();
void fn_800EA1D8();
void fn_800EA424();
void fn_800EA640();
void fn_800EA848();
void fn_800EA910();
void fn_800EABC8();
void fn_800F020C();
}

extern "C" __declspec(section ".data") const void* const lbl_802C959C[6] __attribute__((aligned(4))) = {
    &lbl_80375C78,
    0,
    (const void*)fn_800F020C,
    (const void*)fn_800EABC8,
    (const void*)fn_800EA848,
    (const void*)fn_800EA910,
};

extern "C" __declspec(section ".data") const void* const lbl_802C95B4[6] __attribute__((aligned(4))) = {
    &lbl_80375C70,
    0,
    (const void*)__dt__15Object_800EAB3CFv,
    (const void*)fn_800EA640,
    (const void*)fn_800EA848,
    (const void*)fn_800EA910,
};

extern "C" NativeRuntimeBaseList<2> lbl_802C95CC = {
    {
        {&lbl_80375BD0, 0},
        {&lbl_80375BD8, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802C95E0[6] __attribute__((aligned(4))) = {
    &lbl_80375C80,
    0,
    (const void*)__dt__15Object_800F02A8Fv,
    (const void*)fn_800E9F9C,
    (const void*)fn_800EA1D8,
    (const void*)fn_800EA424,
};

