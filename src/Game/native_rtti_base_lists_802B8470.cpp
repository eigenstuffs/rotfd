#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateProjBase.
NativeRuntimeBaseList<1> lbl_802B8470 = {
    {
        { &lbl_803749A8, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateProjFalling.
NativeRuntimeBaseList<2> lbl_802B847C = {
    {
        { &lbl_803749A8, 0 }, // CState
        { &lbl_803749B0, 0 }, // CStateProjBase
    }, 0
};

}

// Native virtual dispatch for the falling projectile state.
extern "C" {
void __dt__15Object_80081184Fv();
void fn_80081210();
void fn_80081270();
void fn_800812E8();
}
extern "C" __declspec(section ".data") const void* const lbl_802B8490[6] __attribute__((aligned(4))) = {
    &lbl_803749B8, 0,
    (const void*)__dt__15Object_80081184Fv,
    (const void*)fn_80081210,
    (const void*)fn_80081270,
    (const void*)fn_800812E8,
};
