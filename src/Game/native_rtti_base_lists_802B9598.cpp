#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateJFBase.
NativeRuntimeBaseList<1> lbl_802B9598 = {
    {
        { &lbl_80374C50, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateJFDefeated.
NativeRuntimeBaseList<2> lbl_802B95A4 = {
    {
        { &lbl_80374C50, 0 }, // CState
        { &lbl_80374C58, 0 }, // CStateJFBase
    }, 0
};

}
