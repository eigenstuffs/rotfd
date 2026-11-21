#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateSBBase.
NativeRuntimeBaseList<1> lbl_802B87A0 = {
    {
        { &lbl_80374A1C, 0 }, // CState
    }, 0
};

// Base hierarchy for CStateCelebrate.
NativeRuntimeBaseList<2> lbl_802B87AC = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}
