#include "Game/native_runtime_type_records_remaining.h"
#include "Game/state_native_operation_records_selected.h"

extern "C" {
Object_8008EEAC * __dt__15Object_8008EEACFv(Object_8008EEAC *, short);
void fn_800885B0(Owner *);
void fn_8008860C(CompletionOwner *, double);
void fn_800886A8(Owner *);
void fn_80081414(void);
Object_8008EF38 * __dt__15Object_8008EF38Fv(Object_8008EF38 *, short);
void fn_800882A8(MotionOwner *);
void fn_80088414(CompletionOwner *, float);
void fn_800884D4(CompletionOwner *);
Object_8008EFC4 * __dt__15Object_8008EFC4Fv(Object_8008EFC4 *, short);
void fn_8008809C(CompletionOwner *);
void fn_8008814C(CompletionOwner *, double);
void fn_800881F8(Owner *);
Object_8008F050 * __dt__15Object_8008F050Fv(Object_8008F050 *, short);
void fn_80087F28(Owner *);
void fn_80087F84(Owner *, double);
void fn_80087FE4(Owner *);
Object_8008F0DC * __dt__15Object_8008F0DCFv(Object_8008F0DC *, short);
void fn_80087CA4(Owner *);
void fn_80087D04(Owner *);
void fn_80087E6C(Owner *);
Object_8008F168 * __dt__15Object_8008F168Fv(Object_8008F168 *, short);
void fn_80087AB4(CompletionOwner *);
void fn_80087BDC(Owner *, double);
void fn_80087B44(CompletionOwner *);
void fn_80087C00(Owner *, int, int);
Object_8008F1F4 * __dt__15Object_8008F1F4Fv(Object_8008F1F4 *, short);
void fn_800878A0(StateOwner *);
void fn_8008795C(StateOwner *, double);
void fn_800879D4(StateOwner *);

NativeRuntimeBaseList<2> lbl_802B8C20 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateCarryFallNativeOperations lbl_802B8C34 = {&lbl_80374AE4,0,__dt__15Object_8008EEACFv,fn_800885B0,fn_8008860C,fn_800886A8,fn_80081414};
NativeRuntimeBaseList<2> lbl_802B8C50 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateCarryJumpNativeOperations lbl_802B8C64 = {&lbl_80374AEC,0,__dt__15Object_8008EF38Fv,fn_800882A8,fn_80088414,fn_800884D4,fn_80081414};
NativeRuntimeBaseList<2> lbl_802B8C80 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateCarryWalkNativeOperations lbl_802B8C94 = {&lbl_80374AF4,0,__dt__15Object_8008EFC4Fv,fn_8008809C,fn_8008814C,fn_800881F8,fn_80081414};
NativeRuntimeBaseList<2> lbl_802B8CB0 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateCarryIdleNativeOperations lbl_802B8CC4 = {&lbl_80374AFC,0,__dt__15Object_8008F050Fv,fn_80087F28,fn_80087F84,fn_80087FE4,fn_80081414};
NativeRuntimeBaseList<2> lbl_802B8CE0 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStatePickupNativeOperations lbl_802B8CF4 = {&lbl_80374B04,0,__dt__15Object_8008F0DCFv,fn_80087CA4,fn_80087D04,fn_80087E6C,fn_80081414};
NativeRuntimeBaseList<2> lbl_802B8D10 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateNoMoveNativeOperations lbl_802B8D24 = {&lbl_80374B0C,0,__dt__15Object_8008F168Fv,fn_80087AB4,fn_80087BDC,fn_80087B44,fn_80087C00};
NativeRuntimeBaseList<2> lbl_802B8D40 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};
CStateGetUpNativeOperations lbl_802B8D54 = {&lbl_80374B14,0,__dt__15Object_8008F1F4Fv,fn_800878A0,fn_8008795C,fn_800879D4,fn_80081414};
}

typedef char CheckCStateCarryFallNativeOperationsSize[sizeof(CStateCarryFallNativeOperations)==28?1:-1];
typedef char CheckCStateCarryJumpNativeOperationsSize[sizeof(CStateCarryJumpNativeOperations)==28?1:-1];
typedef char CheckCStateCarryWalkNativeOperationsSize[sizeof(CStateCarryWalkNativeOperations)==28?1:-1];
typedef char CheckCStateCarryIdleNativeOperationsSize[sizeof(CStateCarryIdleNativeOperations)==28?1:-1];
typedef char CheckCStatePickupNativeOperationsSize[sizeof(CStatePickupNativeOperations)==28?1:-1];
typedef char CheckCStateNoMoveNativeOperationsSize[sizeof(CStateNoMoveNativeOperations)==28?1:-1];
typedef char CheckCStateGetUpNativeOperationsSize[sizeof(CStateGetUpNativeOperations)==28?1:-1];
typedef char CheckNativeBaseListSize[sizeof(NativeRuntimeBaseList<2>)==20?1:-1];
