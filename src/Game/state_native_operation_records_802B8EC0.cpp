#include "Game/native_runtime_type_records_remaining.h"
#include "Game/state_native_operation_records_selected.h"

extern "C" {
void* fn_8008F4B0(View *, int);
void fn_800850D0(InputOwner *);
void fn_800851A4(InputOwner *);
void fn_800853EC(InputOwner *);
void fn_800853B4(Owner *, int, int);

NativeRuntimeBaseList<2> lbl_802B8EC0 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateInCannonNativeOperations lbl_802B8ED4 = {&lbl_80374B54,0,fn_8008F4B0,fn_800850D0,fn_800851A4,fn_800853EC,fn_800853B4};
}

typedef char CheckCStateInCannonNativeOperationsSize[sizeof(CStateInCannonNativeOperations)==28?1:-1];
typedef char CheckNativeBaseListSize[sizeof(NativeRuntimeBaseList<2>)==20?1:-1];
