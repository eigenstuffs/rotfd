#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802B9B78 = {
    {
        { &lbl_80374D40, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802B9B84 = {
    {
        { &lbl_80374D40, 0 }, // BaseObject_Z
        { &lbl_80374D48, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802B9B98 = {
    {
        { &lbl_80374D40, 0 }, // BaseObject_Z
        { &lbl_80374D48, 0 }, // Activable_Z
        { &lbl_80374D50, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802B9BB4 = {
    {
        { &lbl_80374D40, 0 }, // BaseObject_Z
        { &lbl_80374D48, 0 }, // Activable_Z
        { &lbl_80374D50, 0 }, // Manipulator_Z
        { &lbl_80374D58, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802B9BD8 = {
    {
        { &lbl_80374D40, 0 }, // BaseObject_Z
        { &lbl_80374D48, 0 }, // Activable_Z
        { &lbl_80374D50, 0 }, // Manipulator_Z
        { &lbl_80374D58, 0 }, // ObjectMove_Z
        { &lbl_80374D60, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CActorMove.
NativeRuntimeBaseList<7> lbl_802B9C04 = {
    {
        { &lbl_80374D38, 792 }, // CFSM
        { &lbl_80374D40, 0 }, // BaseObject_Z
        { &lbl_80374D48, 0 }, // Activable_Z
        { &lbl_80374D50, 0 }, // Manipulator_Z
        { &lbl_80374D58, 0 }, // ObjectMove_Z
        { &lbl_80374D60, 0 }, // ObjectThrow_Z
        { &lbl_80374D68, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CNPCMove.
NativeRuntimeBaseList<8> lbl_802B9C40 = {
    {
        { &lbl_80374D38, 792 }, // CFSM
        { &lbl_80374D40, 0 }, // BaseObject_Z
        { &lbl_80374D48, 0 }, // Activable_Z
        { &lbl_80374D50, 0 }, // Manipulator_Z
        { &lbl_80374D58, 0 }, // ObjectMove_Z
        { &lbl_80374D60, 0 }, // ObjectThrow_Z
        { &lbl_80374D68, 0 }, // LodMove_Z
        { &lbl_80374D70, 0 }, // CActorMove
    }, 0
};

// Base hierarchy for CJellyfishMove.
NativeRuntimeBaseList<9> lbl_802B9C84 = {
    {
        { &lbl_80374D38, 792 }, // CFSM
        { &lbl_80374D40, 0 }, // BaseObject_Z
        { &lbl_80374D48, 0 }, // Activable_Z
        { &lbl_80374D50, 0 }, // Manipulator_Z
        { &lbl_80374D58, 0 }, // ObjectMove_Z
        { &lbl_80374D60, 0 }, // ObjectThrow_Z
        { &lbl_80374D68, 0 }, // LodMove_Z
        { &lbl_80374D70, 0 }, // CActorMove
        { &lbl_80374D78, 0 }, // CNPCMove
    }, 0
};

// Base hierarchy for CGreenJfishMove.
NativeRuntimeBaseList<10> lbl_802B9CD0 = {
    {
        { &lbl_80374D38, 792 }, // CFSM
        { &lbl_80374D40, 0 }, // BaseObject_Z
        { &lbl_80374D48, 0 }, // Activable_Z
        { &lbl_80374D50, 0 }, // Manipulator_Z
        { &lbl_80374D58, 0 }, // ObjectMove_Z
        { &lbl_80374D60, 0 }, // ObjectThrow_Z
        { &lbl_80374D68, 0 }, // LodMove_Z
        { &lbl_80374D70, 0 }, // CActorMove
        { &lbl_80374D78, 0 }, // CNPCMove
        { &lbl_80374D80, 0 }, // CJellyfishMove
    }, 0
};

}

/* Native vtable at 0x802B9D24 (original .data, 4 mod 8). Its RTTI record's base list is the last object above, so the vtable belongs to this unit; adjustor thunks (@N@name) are referenced through the thunkN_name linker aliases in config/GSQE78/ldscript.tpl. */
#pragma explicit_zero_data on
#pragma force_active on
extern "C" char __dt__15Object_800969F0Fv[];
extern "C" char slot0C__12BaseObject_ZFUl[];
extern "C" char slot10__12BaseObject_ZFv[];
extern "C" char slot14__12BaseObject_ZFv[];
extern "C" char fn_80096AD4[];
extern "C" char slot1C__12BaseObject_ZFv[];
extern "C" char slot20__11Activable_ZFv[];
extern "C" char slot24__11Activable_ZFv[];
extern "C" char slot28__11Activable_ZFv[];
extern "C" char slot2C__13Manipulator_ZFf[];
extern "C" char slot30__13Manipulator_ZFv[];
extern "C" char fn_80096B08[];
extern "C" char fn_80096C98[];
extern "C" char slot3C__13Manipulator_ZFv[];
extern "C" char fn_80096F3C[];
extern "C" char fn_8009BD18[];
extern "C" char fn_801C0CC8[];
extern "C" char fn_80098EDC[];
extern "C" char fn_801C0BC4[];
extern "C" char fn_80027DD0[];
extern "C" char fn_80221EEC[];
extern "C" char fn_8009B868[];
extern "C" char fn_8021E8B8[];
extern "C" char fn_80228408[];
extern "C" char fn_801BDCAC[];
extern "C" char fn_80027DFC[];
extern "C" char fn_800949BC[];
extern "C" char fn_80089208[];
extern "C" char fn_800949C4[];
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
extern "C" char fn_8009AEA8[];
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
extern "C" char fn_80094920[];
extern "C" char fn_8009BE88[];
extern "C" char fn_800948D8[];
extern "C" char fn_800948DC[];
extern "C" char fn_800948E0[];
extern "C" char fn_80094900[];
extern "C" char fn_80027D64[];
extern "C" char fn_80027D6C[];
extern "C" char fn_801BEB0C[];
extern "C" char fn_80096514[];
extern "C" char fn_80220D78[];
extern "C" char thunk792___dt__15Object_800969F0Fv[];
extern "C" char thunk792_hook_80096518__32OwnerCleanupVirtualView_80095F4CFv[];
extern "C" char configure__4CFSMFi[];
extern "C" char reset__4CFSMFv[];
extern "C" char fn_8009B50C[];
extern "C" char fn_8009B63C[];
extern "C" char fn_8009B674[];
extern "C" char fn_8009B7D0[];
extern "C" char fn_80096FC8[];
extern "C" char hook_80096518__32OwnerCleanupVirtualView_80095F4CFv[];
extern "C" char accumulate_800970F8__15Object_800969F0FPCf[];
extern "C" char fn_80096B30[];
extern "C" __declspec(section ".data") void* lbl_802B9D24[107] = {
    (void*)&lbl_80374D88,
    0,
    (void*)&__dt__15Object_800969F0Fv,
    (void*)&slot0C__12BaseObject_ZFUl,
    (void*)&slot10__12BaseObject_ZFv,
    (void*)&slot14__12BaseObject_ZFv,
    (void*)&fn_80096AD4,
    (void*)&slot1C__12BaseObject_ZFv,
    (void*)&slot20__11Activable_ZFv,
    (void*)&slot24__11Activable_ZFv,
    (void*)&slot28__11Activable_ZFv,
    (void*)&slot2C__13Manipulator_ZFf,
    (void*)&slot30__13Manipulator_ZFv,
    (void*)&fn_80096B08,
    (void*)&fn_80096C98,
    (void*)&slot3C__13Manipulator_ZFv,
    (void*)&fn_80096F3C,
    (void*)&fn_8009BD18,
    (void*)&fn_801C0CC8,
    (void*)&fn_80098EDC,
    (void*)&fn_801C0BC4,
    (void*)&fn_80027DD0,
    (void*)&fn_80221EEC,
    (void*)&fn_8009B868,
    (void*)&fn_8021E8B8,
    (void*)&fn_80228408,
    (void*)&fn_801BDCAC,
    (void*)&fn_80027DFC,
    (void*)&fn_800949BC,
    (void*)&fn_80089208,
    (void*)&fn_800949C4,
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
    (void*)&fn_8009AEA8,
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
    (void*)&fn_80094920,
    (void*)&fn_8009BE88,
    (void*)&fn_800948D8,
    (void*)&fn_800948DC,
    (void*)&fn_800948E0,
    (void*)&fn_80094900,
    (void*)&fn_80027D64,
    (void*)&fn_80027D6C,
    (void*)&fn_801BEB0C,
    (void*)&fn_80096514,
    (void*)&fn_80220D78,
    (void*)&lbl_80374D88,
    (void*)0xFFFFFCE8,
    (void*)&thunk792___dt__15Object_800969F0Fv,
    (void*)&thunk792_hook_80096518__32OwnerCleanupVirtualView_80095F4CFv,
    (void*)&configure__4CFSMFi,
    (void*)&reset__4CFSMFv,
    (void*)&fn_8009B50C,
    (void*)&fn_8009B63C,
    (void*)&fn_8009B674,
    (void*)&fn_8009B7D0,
    (void*)&fn_80096FC8,
    (void*)&hook_80096518__32OwnerCleanupVirtualView_80095F4CFv,
    (void*)&accumulate_800970F8__15Object_800969F0FPCf,
    (void*)&fn_80096B30,
    0,
};

#pragma force_active reset
