#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BD530 = {
    {
        { &lbl_80375430, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BD53C = {
    {
        { &lbl_80375430, 0 }, // BaseObject_Z
        { &lbl_80375438, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802BD550 = {
    {
        { &lbl_80375430, 0 }, // BaseObject_Z
        { &lbl_80375438, 0 }, // Activable_Z
        { &lbl_80375440, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802BD56C = {
    {
        { &lbl_80375430, 0 }, // BaseObject_Z
        { &lbl_80375438, 0 }, // Activable_Z
        { &lbl_80375440, 0 }, // Manipulator_Z
        { &lbl_80375448, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for CWaterBallMove.
NativeRuntimeBaseList<6> lbl_802BD590 = {
    {
        { &lbl_80375428, 504 }, // CFSM
        { &lbl_80375430, 0 }, // BaseObject_Z
        { &lbl_80375438, 0 }, // Activable_Z
        { &lbl_80375440, 0 }, // Manipulator_Z
        { &lbl_80375448, 0 }, // ObjectMove_Z
        { &lbl_80375450, 0 }, // ObjectThrow_Z
    }, 0
};

}

// Adjacent native method and runtime-base records.

extern "C" {
void __dt__15Object_800AF348Fv();
void fn_800261B4();
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
void fn_800AF478();
void fn_800AF4B8();
void fn_800AF58C();
void fn_800AF6A4();
void fn_800AF6E8();
void fn_800AFA84();
void fn_800AFCA8();
void fn_800AFCAC();
void fn_800AFCB0();
void fn_800AFCB8();
void fn_801BC98C();
void fn_801BC99C();
void fn_801BCAA0();
void fn_801BCD74();
void fn_801BD02C();
void fn_801BD950();
void fn_801BDCAC();
void fn_801BDEF8();
void fn_801C1A04();
void fn_801C1CB4();
void fn_801C234C();
void fn_801C2520();
void fn_8021DA20();
void fn_8021E8B8();
void fn_8021F208();
void fn_8021F340();
void fn_8021F5BC();
void fn_8021F728();
void fn_8021F7CC();
void fn_8021F858();
void fn_8021F8F4();
void fn_8021F990();
void fn_8021FA1C();
void fn_8021FAB4();
void fn_8021FB5C();
void fn_80220124();
void fn_80220260();
void fn_802203A8();
void fn_80227C30();
void fn_80227F4C();
void fn_80227F98();
void fn_80227F9C();
void fn_80228408();
void fn_80228E0C();
void fn_80228ECC();
void fn_80229B4C();
void fn_80229CA4();
void fn_80229EE0();
void fn_8028E4F8();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot20__11Activable_ZFv();
void slot24__11Activable_ZFv();
void slot28__11Activable_ZFv();
void slot2C__13Manipulator_ZFf();
void slot30__13Manipulator_ZFv();
void slot3C__13Manipulator_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802BD5C4[87] __attribute__((aligned(4))) = {
    &lbl_80375458,
    0,
    (const void*)__dt__15Object_800AF348Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800AF478,
    (const void*)fn_800AF4B8,
    (const void*)slot20__11Activable_ZFv,
    (const void*)slot24__11Activable_ZFv,
    (const void*)slot28__11Activable_ZFv,
    (const void*)slot2C__13Manipulator_ZFf,
    (const void*)slot30__13Manipulator_ZFv,
    (const void*)fn_80229EE0,
    (const void*)fn_800AF6A4,
    (const void*)slot3C__13Manipulator_ZFv,
    (const void*)fn_800AF6E8,
    (const void*)fn_8021F5BC,
    (const void*)fn_801C2520,
    (const void*)fn_801C1CB4,
    (const void*)fn_801C234C,
    (const void*)fn_80027DD0,
    (const void*)fn_8028E4F8,
    (const void*)fn_80227C30,
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
    (const void*)fn_8021FB5C,
    (const void*)fn_8021FAB4,
    (const void*)fn_8021FA1C,
    (const void*)fn_8021F990,
    (const void*)fn_8021F8F4,
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
    (const void*)fn_8021DA20,
    (const void*)fn_801BD02C,
    (const void*)fn_801BCD74,
    (const void*)fn_801BCAA0,
    (const void*)fn_801BC98C,
    (const void*)fn_801BC99C,
    (const void*)fn_80228ECC,
    (const void*)fn_80227F98,
    (const void*)fn_80227F9C,
    (const void*)fn_80229B4C,
    (const void*)fn_800AFCA8,
    (const void*)fn_800AFCAC,
    (const void*)fn_80027DCC,
    &lbl_80375458,
    (const void*)0xFFFFFE08,
    (const void*)fn_800AFCB8,
    (const void*)fn_800AFCB0,
    (const void*)configure__4CFSMFi,
    (const void*)reset__4CFSMFv,
    (const void*)fn_800AF58C,
    (const void*)fn_800AFA84,
};

