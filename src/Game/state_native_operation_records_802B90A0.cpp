#include "Game/native_runtime_type_records_remaining.h"
#include "Game/state_native_operation_records_selected.h"

extern "C" {
Object_8008FA5C * __dt__15Object_8008FA5CFv(Object_8008FA5C *, short);
void fn_800833C8(Owner *);
void fn_80083424(MotionOwner *, double);
void fn_800834C0(Owner *);
void fn_80081414(void);
Object_8008FAE8 * __dt__15Object_8008FAE8Fv(Object_8008FAE8 *, short);
void fn_800830D0(MotionOwner *);
void fn_80083234(MotionOwner *, double);
void fn_800832E4(IndexStateOwner *);
Object_8008FB74 * __dt__15Object_8008FB74Fv(Object_8008FB74 *, short);
void fn_80082C18(Self *);
void fn_80082F20(EventOwner *, float);
void fn_80082FF4(CompletionOwner *);
Object_8008FC00 * __dt__15Object_8008FC00Fv(Object_8008FC00 *, short);
void fn_80082910(MotionOwner *);
void fn_80082A7C(MotionOwner *, float);
void fn_80082B3C(CompletionOwner *);

NativeRuntimeBaseList<2> lbl_802B90A0 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateFallNativeOperations lbl_802B90B4 = {&lbl_80374BA4,0,__dt__15Object_8008FA5CFv,fn_800833C8,fn_80083424,fn_800834C0,fn_80081414};
NativeRuntimeBaseList<2> lbl_802B90D0 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateSpringboardJumpNativeOperations lbl_802B90E4 = {&lbl_80374BAC,0,__dt__15Object_8008FAE8Fv,fn_800830D0,fn_80083234,fn_800832E4,fn_80081414};
NativeRuntimeBaseList<2> lbl_802B9100 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStatePowerJumpNativeOperations lbl_802B9114 = {&lbl_80374BB4,0,__dt__15Object_8008FB74Fv,fn_80082C18,fn_80082F20,fn_80082FF4,fn_80081414};
NativeRuntimeBaseList<2> lbl_802B9130 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateJumpNativeOperations lbl_802B9144 = {&lbl_80374BBC,0,__dt__15Object_8008FC00Fv,fn_80082910,fn_80082A7C,fn_80082B3C,fn_80081414};
}

typedef char CheckCStateFallNativeOperationsSize[sizeof(CStateFallNativeOperations)==28?1:-1];
typedef char CheckCStateSpringboardJumpNativeOperationsSize[sizeof(CStateSpringboardJumpNativeOperations)==28?1:-1];
typedef char CheckCStatePowerJumpNativeOperationsSize[sizeof(CStatePowerJumpNativeOperations)==28?1:-1];
typedef char CheckCStateJumpNativeOperationsSize[sizeof(CStateJumpNativeOperations)==28?1:-1];
typedef char CheckNativeBaseListSize[sizeof(NativeRuntimeBaseList<2>)==20?1:-1];
