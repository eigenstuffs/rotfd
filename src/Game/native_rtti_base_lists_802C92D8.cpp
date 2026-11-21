#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateCardCorruptUserData.
NativeRuntimeBaseList<2> lbl_802C92D8 = {
    {
        { &lbl_80375BD0, 0 }, // CState
        { &lbl_80375BD8, 0 }, // CStateGCCardBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800EF9D8Fv();
void __dt__15Object_800EFA64Fv();
void fn_800EE210();
void fn_800EE420();
void fn_800EE468();
void fn_800EE684();
void fn_800EE88C();
void fn_800EE944();
}

extern "C" __declspec(section ".data") const void* const lbl_802C92EC[6] __attribute__((aligned(4))) = {
    &lbl_80375BF8,
    0,
    (const void*)__dt__15Object_800EF9D8Fv,
    (const void*)fn_800EE684,
    (const void*)fn_800EE88C,
    (const void*)fn_800EE944,
};

extern "C" NativeRuntimeBaseList<2> lbl_802C9304 = {
    {
        {&lbl_80375BD0, 0},
        {&lbl_80375BD8, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802C9318[6] __attribute__((aligned(4))) = {
    &lbl_80375C00,
    0,
    (const void*)__dt__15Object_800EFA64Fv,
    (const void*)fn_800EE210,
    (const void*)fn_800EE420,
    (const void*)fn_800EE468,
};

