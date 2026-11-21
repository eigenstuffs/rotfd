#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BB598 = {
    {
        { &lbl_80375048, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BB5A4 = {
    {
        { &lbl_80375048, 0 }, // BaseObject_Z
        { &lbl_80375050, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802BB5B8 = {
    {
        { &lbl_80375048, 0 }, // BaseObject_Z
        { &lbl_80375050, 0 }, // Activable_Z
        { &lbl_80375058, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802BB5D4 = {
    {
        { &lbl_80375048, 0 }, // BaseObject_Z
        { &lbl_80375050, 0 }, // Activable_Z
        { &lbl_80375058, 0 }, // Manipulator_Z
        { &lbl_80375060, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802BB5F8 = {
    {
        { &lbl_80375048, 0 }, // BaseObject_Z
        { &lbl_80375050, 0 }, // Activable_Z
        { &lbl_80375058, 0 }, // Manipulator_Z
        { &lbl_80375060, 0 }, // ObjectMove_Z
        { &lbl_80375068, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CActorMove.
NativeRuntimeBaseList<7> lbl_802BB624 = {
    {
        { &lbl_80375040, 792 }, // CFSM
        { &lbl_80375048, 0 }, // BaseObject_Z
        { &lbl_80375050, 0 }, // Activable_Z
        { &lbl_80375058, 0 }, // Manipulator_Z
        { &lbl_80375060, 0 }, // ObjectMove_Z
        { &lbl_80375068, 0 }, // ObjectThrow_Z
        { &lbl_80375070, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CScriptMove.
NativeRuntimeBaseList<8> lbl_802BB660 = {
    {
        { &lbl_80375040, 792 }, // CFSM
        { &lbl_80375048, 0 }, // BaseObject_Z
        { &lbl_80375050, 0 }, // Activable_Z
        { &lbl_80375058, 0 }, // Manipulator_Z
        { &lbl_80375060, 0 }, // ObjectMove_Z
        { &lbl_80375068, 0 }, // ObjectThrow_Z
        { &lbl_80375070, 0 }, // LodMove_Z
        { &lbl_80375078, 0 }, // CActorMove
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8009DAB0Fv();
void fn_800261B4();
void fn_80027CE4();
void fn_80027D64();
void fn_80027D6C();
void fn_80027DCC();
void fn_80027DD0();
void fn_80027DFC();
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
void fn_80089208();
void fn_800948D8();
void fn_800948DC();
void fn_800948E0();
void fn_80094900();
void fn_80094920();
void fn_800949BC();
void fn_800949C4();
void fn_80096514();
void fn_8009AEA8();
void fn_8009B50C();
void fn_8009B63C();
void fn_8009B674();
void fn_8009B7D0();
void fn_8009BE88();
void fn_8009DB34();
void fn_8009DBEC();
void fn_8009DC5C();
void fn_8009DC60();
void fn_8009DF78();
void fn_8009E640();
void fn_8009F058();
void fn_8009F834();
void fn_8009F9A4();
void fn_8009FDD0();
void fn_8009FE08();
void fn_8009FE40();
void fn_8009FE48();
void fn_801BC99C();
void fn_801BCAA0();
void fn_801BCD74();
void fn_801BD02C();
void fn_801BD950();
void fn_801BDCAC();
void fn_801BDEF8();
void fn_801BEB0C();
void fn_801BF5A4();
void fn_801C0BC4();
void fn_801C0CC8();
void fn_801C1A04();
void fn_8021F208();
void fn_8021F340();
void fn_8021F728();
void fn_8021F7CC();
void fn_8021F858();
void fn_8021FA1C();
void fn_8021FAB4();
void fn_80220124();
void fn_80220260();
void fn_802203A8();
void fn_80220D78();
void fn_80221A0C();
void fn_80221EEC();
void fn_80222138();
void fn_802223EC();
void fn_80222E64();
void fn_8022312C();
void fn_80223448();
void fn_80224294();
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

extern "C" __declspec(section ".data") const void* const lbl_802BB6A4[107] __attribute__((aligned(4))) = {
    &lbl_80375080,
    0,
    (const void*)__dt__15Object_8009DAB0Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8009DB34,
    (const void*)slot1C__12BaseObject_ZFv,
    (const void*)slot20__11Activable_ZFv,
    (const void*)slot24__11Activable_ZFv,
    (const void*)slot28__11Activable_ZFv,
    (const void*)slot2C__13Manipulator_ZFf,
    (const void*)slot30__13Manipulator_ZFv,
    (const void*)fn_8009DBEC,
    (const void*)fn_8009DF78,
    (const void*)slot3C__13Manipulator_ZFv,
    (const void*)fn_8009E640,
    (const void*)fn_8009DC60,
    (const void*)fn_801C0CC8,
    (const void*)fn_801BF5A4,
    (const void*)fn_801C0BC4,
    (const void*)fn_80027DD0,
    (const void*)fn_80221EEC,
    (const void*)fn_8009FDD0,
    (const void*)fn_8009FE08,
    (const void*)fn_80228408,
    (const void*)fn_801BDCAC,
    (const void*)fn_80027DFC,
    (const void*)fn_800949BC,
    (const void*)fn_80089208,
    (const void*)fn_800949C4,
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
    (const void*)fn_8009AEA8,
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
    (const void*)fn_80094920,
    (const void*)fn_8009BE88,
    (const void*)fn_800948D8,
    (const void*)fn_800948DC,
    (const void*)fn_800948E0,
    (const void*)fn_80094900,
    (const void*)fn_80027D64,
    (const void*)fn_80027D6C,
    (const void*)fn_801BEB0C,
    (const void*)fn_80096514,
    (const void*)fn_80220D78,
    &lbl_80375080,
    (const void*)0xFFFFFCE8,
    (const void*)fn_8009FE48,
    (const void*)fn_8009FE40,
    (const void*)configure__4CFSMFi,
    (const void*)reset__4CFSMFv,
    (const void*)fn_8009B50C,
    (const void*)fn_8009B63C,
    (const void*)fn_8009B674,
    (const void*)fn_8009B7D0,
    (const void*)fn_8009F058,
    (const void*)fn_8009DC5C,
    (const void*)fn_8009F834,
    (const void*)fn_8009F9A4,
    0,
};

