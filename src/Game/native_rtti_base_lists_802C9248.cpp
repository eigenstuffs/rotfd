#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateGCCardBase.
NativeRuntimeBaseList<1> lbl_802C9248 = {
    {
        { &lbl_80375BD0, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateCardWarnManage.
NativeRuntimeBaseList<2> lbl_802C9254 = {
    {
        { &lbl_80375BD0, 0 }, // CState
        { &lbl_80375BD8, 0 }, // CStateGCCardBase
    }, 0
};

}

// Adjacent native method and runtime-base records.

extern "C" {
void __dt__15Object_800EF834Fv();
void fn_800EF514();
void fn_800EF71C();
void fn_800EF788();
}

extern "C" __declspec(section ".data") const void* const lbl_802C9268[6] __attribute__((aligned(4))) = {
    &lbl_80375BE0,
    0,
    (const void*)__dt__15Object_800EF834Fv,
    (const void*)fn_800EF514,
    (const void*)fn_800EF71C,
    (const void*)fn_800EF788,
};

