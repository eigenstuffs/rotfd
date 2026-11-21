#include "Game/native_runtime_type_records_remaining.h"
#include "Game/state_native_operation_records_selected.h"

extern "C" {
Object_80088C34 * __dt__15Object_80088C34Fv(Object_80088C34 *, short);
void fn_80088CC0(Self *);
void fn_80088E94(Owner *, double);
void fn_80088EE0(CompletionOwner *);
void fn_80081414(void);

NativeRuntimeBaseList<2> lbl_802B8BC0 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateGetHitNativeOperations lbl_802B8BD4 = {&lbl_80374AD4,0,__dt__15Object_80088C34Fv,fn_80088CC0,fn_80088E94,fn_80088EE0,fn_80081414};
}

typedef char CheckCStateGetHitNativeOperationsSize[sizeof(CStateGetHitNativeOperations)==28?1:-1];
typedef char CheckNativeBaseListSize[sizeof(NativeRuntimeBaseList<2>)==20?1:-1];
