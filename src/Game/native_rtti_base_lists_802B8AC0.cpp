#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateCostumeBase.
NativeRuntimeBaseList<2> lbl_802B8AC0 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

// Base hierarchy for CStateCostumeDefault.
NativeRuntimeBaseList<3> lbl_802B8AD4 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
        { &lbl_80374AAC, 0 }, // CStateCostumeBase
    }, 0
};

}
