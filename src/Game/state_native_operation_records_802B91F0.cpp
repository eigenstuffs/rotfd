#include "Game/native_runtime_type_records_remaining.h"
#include "Game/state_native_operation_records_selected.h"

extern "C" {
Object_8008FE30 * __dt__15Object_8008FE30Fv(Object_8008FE30 *, short);
void fn_80081B04(PhaseOwner *);
void fn_80081B74(Owner *, float);
void fn_80081C14(Owner *);
void fn_80081414(void);
Object_8008FEBC * __dt__15Object_8008FEBCFv(Object_8008FEBC *, short);
void fn_80081970(PhaseOwner *);
void fn_800819E0(PhaseOwner *, double);
void fn_80081A4C(Owner *);

NativeRuntimeBaseList<2> lbl_802B91F0 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateRunNativeOperations lbl_802B9204 = {&lbl_80374BDC,0,__dt__15Object_8008FE30Fv,fn_80081B04,fn_80081B74,fn_80081C14,fn_80081414};
NativeRuntimeBaseList<2> lbl_802B9220 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateJogNativeOperations lbl_802B9234 = {&lbl_80374BE4,0,__dt__15Object_8008FEBCFv,fn_80081970,fn_800819E0,fn_80081A4C,fn_80081414};
}

typedef char CheckCStateRunNativeOperationsSize[sizeof(CStateRunNativeOperations)==28?1:-1];
typedef char CheckCStateJogNativeOperationsSize[sizeof(CStateJogNativeOperations)==28?1:-1];
typedef char CheckNativeBaseListSize[sizeof(NativeRuntimeBaseList<2>)==20?1:-1];
