#include "Game/native_runtime_type_records_remaining.h"
#include "Game/state_native_operation_records_selected.h"

extern "C" {
Object_8008F82C * __dt__15Object_8008F82CFv(Object_8008F82C *, short);
void fn_80083E50(Owner *);
void fn_80083EB0(Owner *, double);
void fn_80083ED4(Owner *);
void fn_80081414(void);
Object_8008F8B8 * __dt__15Object_8008F8B8Fv(Object_8008F8B8 *, short);
void fn_80083CC0(Owner *);
void fn_80083D1C(Owner *);
void fn_80083D94(Owner *);
Object_8008F944 * __dt__15Object_8008F944Fv(Object_8008F944 *, short);
void fn_80083B18(Owner *);
void fn_80083B78(MiscControlOwner *, double);
void fn_80083BDC(ReflectionControlOwner *);

NativeRuntimeBaseList<2> lbl_802B8FE0 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateKarateDoubleChopNativeOperations lbl_802B8FF4 = {&lbl_80374B84,0,__dt__15Object_8008F82CFv,fn_80083E50,fn_80083EB0,fn_80083ED4,fn_80081414};
NativeRuntimeBaseList<2> lbl_802B9010 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateKaratePowerChopNativeOperations lbl_802B9024 = {&lbl_80374B8C,0,__dt__15Object_8008F8B8Fv,fn_80083CC0,fn_80083D1C,fn_80083D94,fn_80081414};
NativeRuntimeBaseList<2> lbl_802B9040 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateKarateChopNativeOperations lbl_802B9054 = {&lbl_80374B94,0,__dt__15Object_8008F944Fv,fn_80083B18,fn_80083B78,fn_80083BDC,fn_80081414};
}

typedef char CheckCStateKarateDoubleChopNativeOperationsSize[sizeof(CStateKarateDoubleChopNativeOperations)==28?1:-1];
typedef char CheckCStateKaratePowerChopNativeOperationsSize[sizeof(CStateKaratePowerChopNativeOperations)==28?1:-1];
typedef char CheckCStateKarateChopNativeOperationsSize[sizeof(CStateKarateChopNativeOperations)==28?1:-1];
typedef char CheckNativeBaseListSize[sizeof(NativeRuntimeBaseList<2>)==20?1:-1];
