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
void __dt__14CWaterBallMoveFv();
void slot9C__12ObjectMove_ZFv();
void slot138__13ObjectThrow_ZFv();
void slot54__12ObjectMove_ZFv();
void slot6C__12ObjectMove_ZFv();
void slot70__12ObjectMove_ZFv();
void slot74__12ObjectMove_ZFv();
void slot78__12ObjectMove_ZFf();
void slot7C__12ObjectMove_ZFv();
void slot8C__12ObjectMove_ZFv();
void slot90__12ObjectMove_ZFv();
void slot94__12ObjectMove_ZFv();
void slot98__12ObjectMove_ZFv();
void slotA0__12ObjectMove_ZFv();
void slotA4__12ObjectMove_ZFv();
void slotA8__12ObjectMove_ZFv();
void slotAC__12ObjectMove_ZFv();
void slotDC__12ObjectMove_ZFv();
void slotE0__12ObjectMove_ZFv();
void slotE4__12ObjectMove_ZFv();
void slotE8__12ObjectMove_ZFv();
void slotEC__12ObjectMove_ZFv();
void slotF0__12ObjectMove_ZFv();
void configure__4CFSMFi();
void reset__4CFSMFv();
void slot18__14CWaterBallMoveFv();
void slot1C__14CWaterBallMoveFv();
void configureCallbacks__14CWaterBallMoveFv();
void slot38__14CWaterBallMoveFf();
void slot40__14CWaterBallMoveFPC4Vec3PC4Vec3PC4Vec3if();
void slot158__14CWaterBallMoveFv();
void slot130__13ObjectThrow_ZFv();
void slot134__13ObjectThrow_ZFv();
void fn_800AFCB0();
void fn_800AFCB8();
void slot118__12ObjectMove_ZFv();
void slot11C__12ObjectMove_ZFv();
void slot114__12ObjectMove_ZFv();
void slot110__12ObjectMove_ZFv();
void slot10C__12ObjectMove_ZFv();
void slot88__12ObjectMove_ZFv();
void slot68__12ObjectMove_ZFv();
void slot104__12ObjectMove_ZFv();
void slot100__13ObjectThrow_ZFv();
void slot4C__13ObjectThrow_ZFv();
void slot50__13ObjectThrow_ZFv();
void slot48__13ObjectThrow_ZFv();
void slot108__12ObjectMove_ZFv();
void slot60__12ObjectMove_ZFv();
void slotF8__12ObjectMove_ZFv();
void slot80__12ObjectMove_ZFv();
void slot44__12ObjectMove_ZFv();
void slotC8__12ObjectMove_ZFv();
void slotCC__12ObjectMove_ZFv();
void slotC4__12ObjectMove_ZFv();
void slotC0__12ObjectMove_ZFv();
void slotBC__12ObjectMove_ZFv();
void slotB8__12ObjectMove_ZFv();
void slotB4__12ObjectMove_ZFv();
void slotB0__12ObjectMove_ZFv();
void slotD8__12ObjectMove_ZFv();
void slotD4__12ObjectMove_ZFv();
void slotD0__12ObjectMove_ZFv();
void slot5C__13ObjectThrow_ZFv();
void slotF4__13ObjectThrow_ZFv();
void slot124__13ObjectThrow_ZFv();
void slot128__13ObjectThrow_ZFv();
void slot64__13ObjectThrow_ZFv();
void slotFC__13ObjectThrow_ZFv();
void slot120__13ObjectThrow_ZFv();
void slot12C__13ObjectThrow_ZFv();
void slot84__13ObjectThrow_ZFv();
void slot34__13ObjectThrow_ZFv();
void slot58__12ObjectMove_ZFv();
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
    (const void*)__dt__14CWaterBallMoveFv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)slot18__14CWaterBallMoveFv,
    (const void*)slot1C__14CWaterBallMoveFv,
    (const void*)slot20__11Activable_ZFv,
    (const void*)slot24__11Activable_ZFv,
    (const void*)slot28__11Activable_ZFv,
    (const void*)slot2C__13Manipulator_ZFf,
    (const void*)slot30__13Manipulator_ZFv,
    (const void*)slot34__13ObjectThrow_ZFv,
    (const void*)slot38__14CWaterBallMoveFf,
    (const void*)slot3C__13Manipulator_ZFv,
    (const void*)slot40__14CWaterBallMoveFPC4Vec3PC4Vec3PC4Vec3if,
    (const void*)slot44__12ObjectMove_ZFv,
    (const void*)slot48__13ObjectThrow_ZFv,
    (const void*)slot4C__13ObjectThrow_ZFv,
    (const void*)slot50__13ObjectThrow_ZFv,
    (const void*)slot54__12ObjectMove_ZFv,
    (const void*)slot58__12ObjectMove_ZFv,
    (const void*)slot5C__13ObjectThrow_ZFv,
    (const void*)slot60__12ObjectMove_ZFv,
    (const void*)slot64__13ObjectThrow_ZFv,
    (const void*)slot68__12ObjectMove_ZFv,
    (const void*)slot6C__12ObjectMove_ZFv,
    (const void*)slot70__12ObjectMove_ZFv,
    (const void*)slot74__12ObjectMove_ZFv,
    (const void*)slot78__12ObjectMove_ZFf,
    (const void*)slot7C__12ObjectMove_ZFv,
    (const void*)slot80__12ObjectMove_ZFv,
    (const void*)slot84__13ObjectThrow_ZFv,
    (const void*)slot88__12ObjectMove_ZFv,
    (const void*)slot8C__12ObjectMove_ZFv,
    (const void*)slot90__12ObjectMove_ZFv,
    (const void*)slot94__12ObjectMove_ZFv,
    (const void*)slot98__12ObjectMove_ZFv,
    (const void*)slot9C__12ObjectMove_ZFv,
    (const void*)slotA0__12ObjectMove_ZFv,
    (const void*)slotA4__12ObjectMove_ZFv,
    (const void*)slotA8__12ObjectMove_ZFv,
    (const void*)slotAC__12ObjectMove_ZFv,
    (const void*)slotB0__12ObjectMove_ZFv,
    (const void*)slotB4__12ObjectMove_ZFv,
    (const void*)slotB8__12ObjectMove_ZFv,
    (const void*)slotBC__12ObjectMove_ZFv,
    (const void*)slotC0__12ObjectMove_ZFv,
    (const void*)slotC4__12ObjectMove_ZFv,
    (const void*)slotC8__12ObjectMove_ZFv,
    (const void*)slotCC__12ObjectMove_ZFv,
    (const void*)slotD0__12ObjectMove_ZFv,
    (const void*)slotD4__12ObjectMove_ZFv,
    (const void*)slotD8__12ObjectMove_ZFv,
    (const void*)slotDC__12ObjectMove_ZFv,
    (const void*)slotE0__12ObjectMove_ZFv,
    (const void*)slotE4__12ObjectMove_ZFv,
    (const void*)slotE8__12ObjectMove_ZFv,
    (const void*)slotEC__12ObjectMove_ZFv,
    (const void*)slotF0__12ObjectMove_ZFv,
    (const void*)slotF4__13ObjectThrow_ZFv,
    (const void*)slotF8__12ObjectMove_ZFv,
    (const void*)slotFC__13ObjectThrow_ZFv,
    (const void*)slot100__13ObjectThrow_ZFv,
    (const void*)slot104__12ObjectMove_ZFv,
    (const void*)slot108__12ObjectMove_ZFv,
    (const void*)slot10C__12ObjectMove_ZFv,
    (const void*)slot110__12ObjectMove_ZFv,
    (const void*)slot114__12ObjectMove_ZFv,
    (const void*)slot118__12ObjectMove_ZFv,
    (const void*)slot11C__12ObjectMove_ZFv,
    (const void*)slot120__13ObjectThrow_ZFv,
    (const void*)slot124__13ObjectThrow_ZFv,
    (const void*)slot128__13ObjectThrow_ZFv,
    (const void*)slot12C__13ObjectThrow_ZFv,
    (const void*)slot130__13ObjectThrow_ZFv,
    (const void*)slot134__13ObjectThrow_ZFv,
    (const void*)slot138__13ObjectThrow_ZFv,
    &lbl_80375458,
    (const void*)0xFFFFFE08,
    (const void*)fn_800AFCB8,
    (const void*)fn_800AFCB0,
    (const void*)configure__4CFSMFi,
    (const void*)reset__4CFSMFv,
    (const void*)configureCallbacks__14CWaterBallMoveFv,
    (const void*)slot158__14CWaterBallMoveFv,
};

