#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateHookBase.
NativeRuntimeBaseList<1> lbl_802B05C0 = {
    {
        { &lbl_80373F00, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateHookKeyframing.
NativeRuntimeBaseList<2> lbl_802B05CC = {
    {
        { &lbl_80373F00, 0 }, // CState
        { &lbl_80373F08, 0 }, // CStateHookBase
    }, 0
};

}

// Adjacent native hook method and base-list records.
extern "C" {
void __dt__15Object_80025E24Fv();
void __dt__15Object_80026A78Fv();
void __dt__15Object_80026B10Fv();
void fn_80025F18();
void fn_80025F40();
void fn_8002607C();
void fn_800261BC();
void fn_80026258();
void fn_800264C4();
void fn_80026938();
void fn_80026A74();
void fn_80026BA8();
void fn_80026BAC();
void fn_80026BB0();
void fn_80026BB4();
}

extern "C" __declspec(section ".data") const void* const lbl_802B05E0[7] __attribute__((aligned(4))) = {
    &lbl_80373F10,
    0,
    (const void*)__dt__15Object_80026A78Fv,
    (const void*)fn_80026258,
    (const void*)fn_800264C4,
    (const void*)fn_80026A74,
    (const void*)fn_80026938,
};

extern "C" NativeRuntimeBaseList<2> lbl_802B05FC = {
    {
        {&lbl_80373F00, 0},
        {&lbl_80373F08, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802B0610[7] __attribute__((aligned(4))) = {
    &lbl_80373F18,
    0,
    (const void*)__dt__15Object_80026B10Fv,
    (const void*)fn_80025F18,
    (const void*)fn_80025F40,
    (const void*)fn_800261BC,
    (const void*)fn_8002607C,
};

extern "C" __declspec(section ".data") const void* const lbl_802B062C[7] __attribute__((aligned(4))) = {
    &lbl_80373F08,
    0,
    (const void*)__dt__15Object_80025E24Fv,
    (const void*)fn_80026BA8,
    (const void*)fn_80026BB0,
    (const void*)fn_80026BB4,
    (const void*)fn_80026BAC,
};
