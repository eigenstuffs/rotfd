#include "Game/native_runtime_type_records_remaining.h"
#include "Game/state_native_operation_records_selected.h"

extern "C" {
Object_8008F5FC * __dt__15Object_8008F5FCFv(Object_8008F5FC *, short);
void fn_8008478C(InputOwner *);
void fn_80084830(ScopedOwner *, double);
void fn_8008494C(Owner *);
void fn_80081414(void);

NativeRuntimeBaseList<2> lbl_802B8F20 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateNetSwipeNativeOperations lbl_802B8F34 = {&lbl_80374B64,0,__dt__15Object_8008F5FCFv,fn_8008478C,fn_80084830,fn_8008494C,fn_80081414};
}

typedef char CheckCStateNetSwipeNativeOperationsSize[sizeof(CStateNetSwipeNativeOperations)==28?1:-1];
typedef char CheckNativeBaseListSize[sizeof(NativeRuntimeBaseList<2>)==20?1:-1];
