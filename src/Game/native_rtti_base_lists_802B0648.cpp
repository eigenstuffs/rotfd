#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802B0648 = {
    {
        { &lbl_80373F28, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802B0654 = {
    {
        { &lbl_80373F28, 0 }, // BaseObject_Z
        { &lbl_80373F30, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802B0668 = {
    {
        { &lbl_80373F28, 0 }, // BaseObject_Z
        { &lbl_80373F30, 0 }, // Activable_Z
        { &lbl_80373F38, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802B0684 = {
    {
        { &lbl_80373F28, 0 }, // BaseObject_Z
        { &lbl_80373F30, 0 }, // Activable_Z
        { &lbl_80373F38, 0 }, // Manipulator_Z
        { &lbl_80373F40, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802B06A8 = {
    {
        { &lbl_80373F28, 0 }, // BaseObject_Z
        { &lbl_80373F30, 0 }, // Activable_Z
        { &lbl_80373F38, 0 }, // Manipulator_Z
        { &lbl_80373F40, 0 }, // ObjectMove_Z
        { &lbl_80373F48, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for VehiculeMove_Z.
NativeRuntimeBaseList<6> lbl_802B06D4 = {
    {
        { &lbl_80373F28, 0 }, // BaseObject_Z
        { &lbl_80373F30, 0 }, // Activable_Z
        { &lbl_80373F38, 0 }, // Manipulator_Z
        { &lbl_80373F40, 0 }, // ObjectMove_Z
        { &lbl_80373F48, 0 }, // ObjectThrow_Z
        { &lbl_80373F50, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CHookMove.
NativeRuntimeBaseList<8> lbl_802B0708 = {
    {
        { &lbl_80373F20, 792 }, // CFSM
        { &lbl_80373F28, 0 }, // BaseObject_Z
        { &lbl_80373F30, 0 }, // Activable_Z
        { &lbl_80373F38, 0 }, // Manipulator_Z
        { &lbl_80373F40, 0 }, // ObjectMove_Z
        { &lbl_80373F48, 0 }, // ObjectThrow_Z
        { &lbl_80373F50, 0 }, // LodMove_Z
        { &lbl_80373F58, 0 }, // VehiculeMove_Z
    }, 0
};

}

/* Native vtable at 0x802B074C (original .data, 4 mod 8). Its RTTI record's base list is the last object above, so the vtable belongs to this unit; adjustor thunks (@N@name) are referenced through the thunkN_name linker aliases in config/GSQE78/ldscript.tpl. */
#pragma explicit_zero_data on
#pragma force_active on
extern "C" char cleanup__32OwnerCleanupVirtualView_80027A08Fi[];
extern "C" char slot0C__12BaseObject_ZFUl[];
extern "C" char slot10__12BaseObject_ZFv[];
extern "C" char slot14__12BaseObject_ZFv[];
extern "C" char fn_80027AFC[];
extern "C" char slot1C__12BaseObject_ZFv[];
extern "C" char slot20__11Activable_ZFv[];
extern "C" char slot24__11Activable_ZFv[];
extern "C" char slot28__11Activable_ZFv[];
extern "C" char slot2C__13Manipulator_ZFf[];
extern "C" char slot30__13Manipulator_ZFv[];
extern "C" char fn_80027B1C[];
extern "C" char fn_80027C14[];
extern "C" char slot3C__13Manipulator_ZFv[];
extern "C" char fn_80027C58[];
extern "C" char fn_8021F5BC[];
extern "C" char fn_801C0CC8[];
extern "C" char fn_801BF5A4[];
extern "C" char fn_801C0BC4[];
extern "C" char fn_80027DD0[];
extern "C" char fn_80221EEC[];
extern "C" char fn_80222B48[];
extern "C" char fn_8021E8B8[];
extern "C" char fn_80228408[];
extern "C" char fn_801BDCAC[];
extern "C" char fn_80027DFC[];
extern "C" char fn_80027E04[];
extern "C" char fn_80027E0C[];
extern "C" char fn_80027E10[];
extern "C" char fn_80027E14[];
extern "C" char fn_8021F340[];
extern "C" char fn_80229CA4[];
extern "C" char fn_801BD950[];
extern "C" char fn_80027E18[];
extern "C" char fn_80027E20[];
extern "C" char fn_80027E28[];
extern "C" char fn_80027E30[];
extern "C" char fn_800261B4[];
extern "C" char fn_80027E38[];
extern "C" char fn_80027ECC[];
extern "C" char fn_80027F54[];
extern "C" char fn_80027FE4[];
extern "C" char fn_80223448[];
extern "C" char fn_8021FAB4[];
extern "C" char fn_8021FA1C[];
extern "C" char fn_8022312C[];
extern "C" char fn_80222E64[];
extern "C" char fn_8021F858[];
extern "C" char fn_8021F728[];
extern "C" char fn_8021F7CC[];
extern "C" char fn_802203A8[];
extern "C" char fn_80220260[];
extern "C" char fn_80220124[];
extern "C" char fn_80028074[];
extern "C" char fn_80028090[];
extern "C" char fn_800280B4[];
extern "C" char fn_800280E8[];
extern "C" char fn_800280F8[];
extern "C" char fn_80028100[];
extern "C" char fn_80227F4C[];
extern "C" char fn_8021F208[];
extern "C" char fn_80228E0C[];
extern "C" char fn_801C1A04[];
extern "C" char fn_801BDEF8[];
extern "C" char fn_802217BC[];
extern "C" char fn_801BD02C[];
extern "C" char fn_801BCD74[];
extern "C" char fn_801BCAA0[];
extern "C" char fn_80221A0C[];
extern "C" char fn_801BC99C[];
extern "C" char fn_80228ECC[];
extern "C" char fn_80227F98[];
extern "C" char fn_80227F9C[];
extern "C" char fn_80229B4C[];
extern "C" char fn_802223EC[];
extern "C" char fn_80222138[];
extern "C" char fn_80027DCC[];
extern "C" char fn_80224294[];
extern "C" char fn_80027CE4[];
extern "C" char fn_80027CEC[];
extern "C" char fn_80027CF0[];
extern "C" char fn_80027D1C[];
extern "C" char fn_80027D20[];
extern "C" char fn_80027D24[];
extern "C" char fn_80027D44[];
extern "C" char fn_80027D64[];
extern "C" char fn_80027D6C[];
extern "C" char fn_801BEB0C[];
extern "C" char fn_80027DC8[];
extern "C" char fn_80220D78[];
extern "C" char thunk792_cleanup__32OwnerCleanupVirtualView_80027A08Fi[];
extern "C" char thunk792_configureCallbacks__32OwnerCleanupVirtualView_80027A08Fv[];
extern "C" char configure__4CFSMFi[];
extern "C" char reset__4CFSMFv[];
extern "C" char configureCallbacks__32OwnerCleanupVirtualView_80027A08Fv[];
extern "C" __declspec(section ".data") void* lbl_802B074C[99] = {
    (void*)&lbl_80373F60,
    0,
    (void*)&cleanup__32OwnerCleanupVirtualView_80027A08Fi,
    (void*)&slot0C__12BaseObject_ZFUl,
    (void*)&slot10__12BaseObject_ZFv,
    (void*)&slot14__12BaseObject_ZFv,
    (void*)&fn_80027AFC,
    (void*)&slot1C__12BaseObject_ZFv,
    (void*)&slot20__11Activable_ZFv,
    (void*)&slot24__11Activable_ZFv,
    (void*)&slot28__11Activable_ZFv,
    (void*)&slot2C__13Manipulator_ZFf,
    (void*)&slot30__13Manipulator_ZFv,
    (void*)&fn_80027B1C,
    (void*)&fn_80027C14,
    (void*)&slot3C__13Manipulator_ZFv,
    (void*)&fn_80027C58,
    (void*)&fn_8021F5BC,
    (void*)&fn_801C0CC8,
    (void*)&fn_801BF5A4,
    (void*)&fn_801C0BC4,
    (void*)&fn_80027DD0,
    (void*)&fn_80221EEC,
    (void*)&fn_80222B48,
    (void*)&fn_8021E8B8,
    (void*)&fn_80228408,
    (void*)&fn_801BDCAC,
    (void*)&fn_80027DFC,
    (void*)&fn_80027E04,
    (void*)&fn_80027E0C,
    (void*)&fn_80027E10,
    (void*)&fn_80027E14,
    (void*)&fn_8021F340,
    (void*)&fn_80229CA4,
    (void*)&fn_801BD950,
    (void*)&fn_80027E18,
    (void*)&fn_80027E20,
    (void*)&fn_80027E28,
    (void*)&fn_80027E30,
    (void*)&fn_800261B4,
    (void*)&fn_80027E38,
    (void*)&fn_80027ECC,
    (void*)&fn_80027F54,
    (void*)&fn_80027FE4,
    (void*)&fn_80223448,
    (void*)&fn_8021FAB4,
    (void*)&fn_8021FA1C,
    (void*)&fn_8022312C,
    (void*)&fn_80222E64,
    (void*)&fn_8021F858,
    (void*)&fn_8021F728,
    (void*)&fn_8021F7CC,
    (void*)&fn_802203A8,
    (void*)&fn_80220260,
    (void*)&fn_80220124,
    (void*)&fn_80028074,
    (void*)&fn_80028090,
    (void*)&fn_800280B4,
    (void*)&fn_800280E8,
    (void*)&fn_800280F8,
    (void*)&fn_80028100,
    (void*)&fn_80227F4C,
    (void*)&fn_8021F208,
    (void*)&fn_80228E0C,
    (void*)&fn_801C1A04,
    (void*)&fn_801BDEF8,
    (void*)&fn_802217BC,
    (void*)&fn_801BD02C,
    (void*)&fn_801BCD74,
    (void*)&fn_801BCAA0,
    (void*)&fn_80221A0C,
    (void*)&fn_801BC99C,
    (void*)&fn_80228ECC,
    (void*)&fn_80227F98,
    (void*)&fn_80227F9C,
    (void*)&fn_80229B4C,
    (void*)&fn_802223EC,
    (void*)&fn_80222138,
    (void*)&fn_80027DCC,
    (void*)&fn_80224294,
    (void*)&fn_80027CE4,
    (void*)&fn_80027CEC,
    (void*)&fn_80027CF0,
    (void*)&fn_80027D1C,
    (void*)&fn_80027D20,
    (void*)&fn_80027D24,
    (void*)&fn_80027D44,
    (void*)&fn_80027D64,
    (void*)&fn_80027D6C,
    (void*)&fn_801BEB0C,
    (void*)&fn_80027DC8,
    (void*)&fn_80220D78,
    (void*)&lbl_80373F60,
    (void*)0xFFFFFCE8,
    (void*)&thunk792_cleanup__32OwnerCleanupVirtualView_80027A08Fi,
    (void*)&thunk792_configureCallbacks__32OwnerCleanupVirtualView_80027A08Fv,
    (void*)&configure__4CFSMFi,
    (void*)&reset__4CFSMFv,
    (void*)&configureCallbacks__32OwnerCleanupVirtualView_80027A08Fv,
};

#pragma force_active reset
