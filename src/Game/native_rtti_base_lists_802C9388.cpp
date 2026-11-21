#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateCardSelectNoFormat.
NativeRuntimeBaseList<2> lbl_802C9388 = {
    {
        { &lbl_80375BD0, 0 }, // CState
        { &lbl_80375BD8, 0 }, // CStateGCCardBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800EFC08Fv();
void __dt__15Object_800EFC94Fv();
void fn_800ECE3C();
void fn_800ED044();
void fn_800ED0F4();
void fn_800ED318();
void fn_800ED520();
void fn_800ED59C();
}

extern "C" __declspec(section ".data") const void* const lbl_802C939C[6] __attribute__((aligned(4))) = {
    &lbl_80375C18,
    0,
    (const void*)__dt__15Object_800EFC08Fv,
    (const void*)fn_800ED318,
    (const void*)fn_800ED520,
    (const void*)fn_800ED59C,
};

extern "C" NativeRuntimeBaseList<2> lbl_802C93B4 = {
    {
        {&lbl_80375BD0, 0},
        {&lbl_80375BD8, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802C93C8[6] __attribute__((aligned(4))) = {
    &lbl_80375C20,
    0,
    (const void*)__dt__15Object_800EFC94Fv,
    (const void*)fn_800ECE3C,
    (const void*)fn_800ED044,
    (const void*)fn_800ED0F4,
};

