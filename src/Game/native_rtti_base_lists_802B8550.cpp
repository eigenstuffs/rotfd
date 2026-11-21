#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802B8550 = {
    {
        { &lbl_803749E0, 0 }, // BaseObject_Z
        { &lbl_803749E8, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802B8564 = {
    {
        { &lbl_803749E0, 0 }, // BaseObject_Z
        { &lbl_803749E8, 0 }, // Activable_Z
        { &lbl_803749F0, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802B8580 = {
    {
        { &lbl_803749E0, 0 }, // BaseObject_Z
        { &lbl_803749E8, 0 }, // Activable_Z
        { &lbl_803749F0, 0 }, // Manipulator_Z
        { &lbl_803749F8, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802B85A4 = {
    {
        { &lbl_803749E0, 0 }, // BaseObject_Z
        { &lbl_803749E8, 0 }, // Activable_Z
        { &lbl_803749F0, 0 }, // Manipulator_Z
        { &lbl_803749F8, 0 }, // ObjectMove_Z
        { &lbl_80374A00, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CProjectileMove.
NativeRuntimeBaseList<7> lbl_802B85D0 = {
    {
        { &lbl_803749D8, 792 }, // CFSM
        { &lbl_803749E0, 0 }, // BaseObject_Z
        { &lbl_803749E8, 0 }, // Activable_Z
        { &lbl_803749F0, 0 }, // Manipulator_Z
        { &lbl_803749F8, 0 }, // ObjectMove_Z
        { &lbl_80374A00, 0 }, // ObjectThrow_Z
        { &lbl_80374A08, 0 }, // LodMove_Z
    }, 0
};

}

// Adjacent native method and runtime-base records.

extern "C" {
void __dt__15Object_8007F578Fv();
void fn_800261B4();
void fn_80027CE4();
void fn_80027CEC();
void fn_80027CF0();
void fn_80027D1C();
void fn_80027D20();
void fn_80027D24();
void fn_80027D44();
void fn_80027D64();
void fn_80027D6C();
void fn_80027DC8();
void fn_80027DCC();
void fn_80027DD0();
void fn_80027DFC();
void fn_80027E04();
void fn_80027E0C();
void fn_80027E10();
void fn_80027E14();
void fn_80027E18();
void fn_80027E20();
void fn_80027E28();
void fn_80027E30();
void fn_80027E38();
void fn_80027ECC();
void fn_80027F54();
void fn_80027FE4();
void fn_80028074();
void fn_80028090();
void fn_800280B4();
void fn_800280E8();
void fn_800280F8();
void fn_80028100();
void configure__4CFSMFi();
void reset__4CFSMFv();
void fn_8007F6A8();
void fn_8007F704();
void fn_8007F860();
void fn_8007F8A8();
void fn_8007F990();
void fn_8007FC68();
void fn_80081368();
void fn_80081370();
void fn_801BC99C();
void fn_801BCAA0();
void fn_801BCD74();
void fn_801BD02C();
void fn_801BD950();
void fn_801BDCAC();
void fn_801BDEF8();
void fn_801BF5A4();
void fn_801C0BC4();
void fn_801C0CC8();
void fn_801C1A04();
void fn_8021E8B8();
void fn_8021F208();
void fn_8021F340();
void fn_8021F5BC();
void fn_8021F728();
void fn_8021F7CC();
void fn_8021F858();
void fn_8021FA1C();
void fn_8021FAB4();
void fn_80220124();
void fn_80220260();
void fn_802203A8();
void fn_80220D78();
void fn_802217BC();
void fn_80221A0C();
void fn_80221EEC();
void fn_80222138();
void fn_802223EC();
void fn_80222B48();
void fn_80222E64();
void fn_8022312C();
void fn_80223448();
void fn_80224294();
void fn_80224888();
void fn_80227F4C();
void fn_80227F98();
void fn_80227F9C();
void fn_80228408();
void fn_80228E0C();
void fn_80228ECC();
void fn_80229B4C();
void fn_80229CA4();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot1C__12BaseObject_ZFv();
void slot20__11Activable_ZFv();
void slot24__11Activable_ZFv();
void slot28__11Activable_ZFv();
void slot2C__13Manipulator_ZFf();
void slot30__13Manipulator_ZFv();
void slot3C__13Manipulator_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802B860C[101] __attribute__((aligned(4))) = {
    &lbl_80374A10,
    0,
    (const void*)__dt__15Object_8007F578Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8007F6A8,
    (const void*)slot1C__12BaseObject_ZFv,
    (const void*)slot20__11Activable_ZFv,
    (const void*)slot24__11Activable_ZFv,
    (const void*)slot28__11Activable_ZFv,
    (const void*)slot2C__13Manipulator_ZFf,
    (const void*)slot30__13Manipulator_ZFv,
    (const void*)fn_80224888,
    (const void*)fn_8007F860,
    (const void*)slot3C__13Manipulator_ZFv,
    (const void*)fn_8007F8A8,
    (const void*)fn_8021F5BC,
    (const void*)fn_801C0CC8,
    (const void*)fn_801BF5A4,
    (const void*)fn_801C0BC4,
    (const void*)fn_80027DD0,
    (const void*)fn_80221EEC,
    (const void*)fn_80222B48,
    (const void*)fn_8021E8B8,
    (const void*)fn_80228408,
    (const void*)fn_801BDCAC,
    (const void*)fn_80027DFC,
    (const void*)fn_80027E04,
    (const void*)fn_80027E0C,
    (const void*)fn_80027E10,
    (const void*)fn_80027E14,
    (const void*)fn_8021F340,
    (const void*)fn_80229CA4,
    (const void*)fn_801BD950,
    (const void*)fn_80027E18,
    (const void*)fn_80027E20,
    (const void*)fn_80027E28,
    (const void*)fn_80027E30,
    (const void*)fn_800261B4,
    (const void*)fn_80027E38,
    (const void*)fn_80027ECC,
    (const void*)fn_80027F54,
    (const void*)fn_80027FE4,
    (const void*)fn_80223448,
    (const void*)fn_8021FAB4,
    (const void*)fn_8021FA1C,
    (const void*)fn_8022312C,
    (const void*)fn_80222E64,
    (const void*)fn_8021F858,
    (const void*)fn_8021F728,
    (const void*)fn_8021F7CC,
    (const void*)fn_802203A8,
    (const void*)fn_80220260,
    (const void*)fn_80220124,
    (const void*)fn_80028074,
    (const void*)fn_80028090,
    (const void*)fn_800280B4,
    (const void*)fn_800280E8,
    (const void*)fn_800280F8,
    (const void*)fn_80028100,
    (const void*)fn_80227F4C,
    (const void*)fn_8021F208,
    (const void*)fn_80228E0C,
    (const void*)fn_801C1A04,
    (const void*)fn_801BDEF8,
    (const void*)fn_802217BC,
    (const void*)fn_801BD02C,
    (const void*)fn_801BCD74,
    (const void*)fn_801BCAA0,
    (const void*)fn_80221A0C,
    (const void*)fn_801BC99C,
    (const void*)fn_80228ECC,
    (const void*)fn_80227F98,
    (const void*)fn_80227F9C,
    (const void*)fn_80229B4C,
    (const void*)fn_802223EC,
    (const void*)fn_80222138,
    (const void*)fn_80027DCC,
    (const void*)fn_80224294,
    (const void*)fn_80027CE4,
    (const void*)fn_80027CEC,
    (const void*)fn_80027CF0,
    (const void*)fn_80027D1C,
    (const void*)fn_80027D20,
    (const void*)fn_80027D24,
    (const void*)fn_80027D44,
    (const void*)fn_80027D64,
    (const void*)fn_80027D6C,
    (const void*)fn_8007FC68,
    (const void*)fn_80027DC8,
    (const void*)fn_80220D78,
    &lbl_80374A10,
    (const void*)0xFFFFFCE8,
    (const void*)fn_80081370,
    (const void*)fn_80081368,
    (const void*)configure__4CFSMFi,
    (const void*)reset__4CFSMFv,
    (const void*)fn_8007F704,
    (const void*)fn_8007F990,
    0,
};

