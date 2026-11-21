#include "Game/native_runtime_type_records_remaining.h"
#include "Game/state_native_operation_records_selected.h"

extern "C" {
Object_80089FB4 * __dt__15Object_80089FB4Fv(Object_80089FB4 *, short);
void fn_8008A040(Control *);
void fn_8008A064(Control *);
void fn_8008A0A0(Control *);
void fn_80081414(void);
Object_8008929C * __dt__15Object_8008929CFv(Object_8008929C *, short);
void fn_80089328(SelectionOwner *);
void fn_80089904(EffectOwner *);
void fn_80089B1C(SceneControlOwner *);

NativeRuntimeBaseList<2> lbl_802B8B30 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateInUnderwearNativeOperations lbl_802B8B44 = {&lbl_80374ABC,0,__dt__15Object_80089FB4Fv,fn_8008A040,fn_8008A064,fn_8008A0A0,fn_80081414};
NativeRuntimeBaseList<2> lbl_802B8B60 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateInWaterNativeOperations lbl_802B8B74 = {&lbl_80374AC4,0,__dt__15Object_8008929CFv,fn_80089328,fn_80089904,fn_80089B1C,fn_80081414};
}

typedef char CheckCStateInUnderwearNativeOperationsSize[sizeof(CStateInUnderwearNativeOperations)==28?1:-1];
typedef char CheckCStateInWaterNativeOperationsSize[sizeof(CStateInWaterNativeOperations)==28?1:-1];
typedef char CheckNativeBaseListSize[sizeof(NativeRuntimeBaseList<2>)==20?1:-1];
